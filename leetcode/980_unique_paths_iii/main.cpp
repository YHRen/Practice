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
  vector<vector<char>> dp;
  int starting_idx;
  int ending_idx;
  int n,m,N;
  int goal;
  vvi mtx;
  bool C( int i, int j, int past){
    if( i < 0 || j < 0 || i == n || j == m ) return 0;
    int idx = i*m+j;
    return !(past & (1<<idx));
  }
  int dfs( int i, int j, int past ){
    int idx = i*m+j;
//    debug("visiting", i,j,"with past",past, dp[idx][past]);
    if( dp[idx][past] != -1 ) return dp[idx][past]; 
    past |= (1<<idx);
    if( idx == ending_idx and past == (1<<N)-1 ) return 1; // found
    int ans = 0;
    if( C(i+1, j, past ) ) ans += dfs(i+1,j, past);
    if( C(i-1, j, past ) ) ans += dfs(i-1,j, past);
    if( C(i, j+1, past ) ) ans += dfs(i,j+1, past);
    if( C(i, j-1, past ) ) ans += dfs(i,j-1, past);
    return dp[idx][past] = ans;
  }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
      n = grid.size();
      m = grid[0].size();
      N = n*m;
      debug("N",N,1<<(N));
      mtx = grid;
      dp.resize(N);
      for(auto & v : dp ) v.resize(1<<(N), -1);
      int goal = 0;
      forall(i,0,n){
        forall(j,0,m){
          if( grid[i][j] == -1 ){
            goal |= ( 1<< (i*m+j) );
          }
          if( grid[i][j] == 1 ){ starting_idx = i*m+j;}
          if( grid[i][j] == 2 ){ ending_idx = i*m +j;}
        }
      }

      goal |= (1<<starting_idx); 
      return dfs( starting_idx/m, starting_idx%m, goal);
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  vvi mtx(n, vi(m));
  for(auto & v : mtx) input(v);
  Solution sol;
  cout << sol.uniquePathsIII(mtx) << '\n';

  return 0;
}
