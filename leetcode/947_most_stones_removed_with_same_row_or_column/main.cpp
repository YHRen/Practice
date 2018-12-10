#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
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
public:
    int removeStones(vector<vector<int>>& stones) {
      int n = stones.size();
      if( n == 1 ) return 0;
      map<int, vi> xnodes, ynodes;
      vvi g(n, vi(n));
      forall(i,0,n){
        int x = stones[i][0], y = stones[i][1];
        if( xnodes.find(x) != xnodes.end() ){
          for(auto u : xnodes[x]){
            g[u].pb(i);
            g[i].pb(u);
          }
          xnodes[x].pb(i);
        }else{
          xnodes[x].pb(i);
        }
        if( ynodes.find(y) != ynodes.end() ){
          for(auto u : ynodes[y]){
            g[u].pb(i);
            g[i].pb(u);
          }
          ynodes[y].pb(i);
        }else{
          ynodes[y].pb(i);
        }
      }

      int ans = 0;
      vi is_visited(n,0);
      forall(i,0,n){
        if( is_visited[i] ) continue;
        queue<int> Q;
        is_visited[i] = 1;
        Q.push( i );
        int tmp = 0;
        while( !Q.empty() ){
          int x = Q.front(); Q.pop();
          tmp += 1;
          for(auto u : g[x] ){
            if( !is_visited[u] ){
              is_visited[u] = 1;
              Q.push(u);
            }
          }
        }
        ans += (tmp-1);
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
