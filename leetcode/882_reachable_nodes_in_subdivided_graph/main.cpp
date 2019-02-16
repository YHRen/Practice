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
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
      vector< vvi > g(N);
      vi dist(N, -1);
      for(auto & e : edges){
        int x = e[0], y = e[1], w = e[2];
        g[x].pb( vi{y,0,w} );
        g[y].pb( vi{x,0,w} );
      }
      priority_queue<ii> pq;
      pq.push( mp( M, 0 ) );
      dist[0] = M;
      while(!pq.empty()){
        auto tmp = pq.top(); pq.pop();
        int idx = tmp.second, d = tmp.first; 
        if( d < dist[idx] ) continue;
        debug("at ", idx, "with d=", d);
        for(auto & u : g[idx]){
          int y = u[0], w = u[2];
          if( d > w ){
            u[1] = w;
            if( d-w-1 > dist[y] ){
              pq.push( mp( d-w-1, y ) );
              dist[y] = d-w-1;
            }
            debug("adding ", y, "with d=", d-w-1);
          }else if( d <= w ){
            u[1] = max(u[1], d);
          }
        }
      }

      print_(dist);

      int tot = 0;
      map<ii, ii> cover;
      for( auto x : dist ) if( x >= 0 ) tot ++;
      forall(i,0,N){
        for( auto & u : g[i] ){
          int y = u[0], d=u[1], w=u[2];
          if( i < y ){
            cover[mp(i,y)].first += d;
            cover[mp(i,y)].second = w;
          }else{
            cover[mp(y,i)].first += d;
          }
        }
      }
      for(auto p : cover ){
        tot += min( p.second.first, p.second.second );
      }
      return tot;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  vvi edges(n, vi(3));
  for(auto & v: edges ) input(v);
  Solution sol;
  cout << sol.reachableNodes( edges, m, n ) << '\n';

  return 0;
}
