#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
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

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

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
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {

      if( S==T) return 0;
      int n = 0, m = routes.size();
      for(auto & v : routes){ n = max(n, 1+*max_element(all(v))); }
      vvi g(n+m);
      forall(i,0,m){
        for(auto x : routes[i]){
          g[n+i].pb(x);
          g[x].pb(n+i);
        }
      }
      vi is_visited(n+m, -1);
      queue<int> Q;
      Q.push(S);
      is_visited[S] = 0;
      while(!Q.empty()){
        auto x = Q.front(); Q.pop();
        int d = is_visited[x];
        for(auto y : g[x] ){
          if( is_visited[y] == -1 ){
            if( y == T ) return (d+1)/2;
            is_visited[y] = d + 1;
            Q.push(y);
          }
        }
      }
      return -1;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
