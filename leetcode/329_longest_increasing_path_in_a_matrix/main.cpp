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
/******* Actual Code Starts Here *********/
class Solution {
  private:
    int n,m,N;
    inline int get_idx(int x, int y) { return x * m + y; }
    vvi in_edge, out_edge;
    inline void try_connect( int x, int y, bool is_vertical, const vvi & mtx ){
      int ida = get_idx(x,y);
      int idb = is_vertical ? get_idx(x+1,y) : get_idx(x,y+1);
      int vala = mtx[x][y];
      int valb = is_vertical ? mtx[x+1][y] : mtx[x][y+1];
      if( vala == valb ) return;
      else if( vala < valb ){
        in_edge[idb].pb(ida);
        out_edge[ida].pb(idb);
      }else{
        in_edge[ida].pb(idb);
        out_edge[idb].pb(ida);
      }
    }
   public:
    int longestIncreasingPath(vector<vector<int>>& mtx) {
      n = mtx.size(); if( !n ) return 0;
      m = mtx[0].size(); if( !m ) return 0;
      N = n*m;
      in_edge.resize(N);
      out_edge.resize(N);
      forall(i,0,n-1){
        forall(j,0,m-1){
          try_connect( i, j, 1, mtx );
          try_connect( i, j, 0, mtx );
        }
      }
      forall(j,0,m-1){ try_connect( n-1, j, 0, mtx ); }
      forall(i,0,n-1){ try_connect( i, m-1, 1, mtx);}

      vi indeg(N);
      vi dist(N,-1);
      vi pre(N,-1);
      queue<int> Q;
      forall(i,0,N){
        indeg[i] = in_edge[i].size();
        dist[i]  = 1;
        if( !indeg[i] && !out_edge[i].empty() ){ Q.push(i); }
      }

      while( !Q.empty() ){
        int v = Q.front(); Q.pop();
        for( auto u : out_edge[v] ){
          indeg[u] -= 1;
          if( dist[u] < dist[v]+1 ){
            dist[u] = dist[v]+1;
            pre[u] = v;
          }
          if( indeg[u] == 0 ) Q.push(u);
        }
      }
      
      // print the path
      int end_node = max_element(all(dist)) - dist.begin();

      /*
      vi ans;
      do{
        ans.pb(end_node);
        end_node = pre[end_node];
      }while(end_node != -1);
      print_(ans);
      */
      return dist[end_node];
    }
};

int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  vvi mtx(n, vi(m));
  for( auto & row : mtx ) input(row);
  Solution sol;
  auto ans = sol.longestIncreasingPath(mtx);
  cout << ans << '\n';


  return 0;
}
