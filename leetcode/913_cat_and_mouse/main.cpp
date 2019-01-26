#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <numeric>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF                         (int)1000000007
#define EPS                         1e-9

#define bg     begin()
#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi>  vvi;
typedef vector<ii>  vii;

#ifdef DEBUG
#define debug(args...)            {dbg,args; clog<<endl;}
#define print_( a )               for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )           for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)             // Just strip off all debug tokens
#define print_( a )               // skip
#define printPair_( a )           // skip
#endif
struct debugger
{
  template<typename T> debugger& operator , (const T& x)
  {    
    clog << x << " ";    
    return *this;    
  }
} dbg;

// std::ios::sync_with_stdio(false);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  int n;
  vvi g, dp;
  int aux(int i, int j){ // i mouse, j cat
    if( dp[i][j] != -1 ) return dp[i][j];
    dp[i][j] = 1;
    int mouse = 2;
    for(auto x : g[i]){
      if( x == j ) continue;
      if( x == 0 ) return dp[i][j]=0;
      int cat   = 0;
      for(auto y : g[j]){
        if( y == 0 ) continue;
        if( y == x ) { cat = 2; break;}
        cat = max( cat, aux(x, y) );
        if( cat == 2 ) break;
      }
      mouse = min(mouse, cat);
      if( mouse == 0 ) break;
    }
    return dp[i][j] = mouse;
  }
        
public:
    int catMouseGame(vector<vector<int>>& graph) {
      g.clear(); dp.clear();
      n = graph.size();
      g = graph;
      dp.resize(n); for(auto & v : dp) v.resize(n,-1);
      forall(i,0,n){
        dp[i][i] = 2;
        dp[0][i] = 0;
        dp[i][0] = 0;
      }
      int ans = aux(1,2);
      debug("ans=",ans);
      if( ans == 0 ) return 1;
      else if( ans == 2 ) return 2;
      else return 0;
    }
};

int main( int argc, char * argv[] ){
  vvi g(6);
  g[0] = {2,5};
  g[1] = {3};
  g[2] = {0, 4, 5};
  g[3] = {1, 4, 5};
  g[4] = {2,3};
  g[5] = {0,2,3};
  // 0

  vvi h(10);
  h[0] =   {2,4,7,8};
  h[1] =   {2,3,4,5,7,8,9};
  h[2] =   {0,1,3,4,5,7,8,9};
  h[3] =   {1,2,5};
  h[4] =   {0,1,2,5,6,7,9};
  h[5] =   {1,2,3,4,6,7};
  h[6] =   {4,5,8,9};
  h[7] =   {0,1,2,4,5,9};
  h[8] =   {0,1,2,6,9};
  h[9] =   {1,2,4,6,7,8};
  // 0

  vvi k(5);
  k[0] = {2,3};
  k[1] = {3,4};
  k[2] = {0,4};
  k[3] = {0,1};
  k[4] = {1,2};
  // 1

  vvi l(5);
  l[0] = {2,3,4};
  l[1] = {2,4};
  l[2] = {0,1,4};
  l[3] = {0,4};
  l[4] = {0,1,2,3};
  // 2

  Solution sol;
  debug("g");
  cout << sol.catMouseGame(g) << '\n';
  debug("h");
  cout << sol.catMouseGame(h) << '\n';
  debug("k");
  cout << sol.catMouseGame(k) << '\n';
  debug("l");
  cout << sol.catMouseGame(l) << '\n';

  return 0;
}
