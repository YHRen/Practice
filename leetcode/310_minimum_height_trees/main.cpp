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
  int n;
  vvi g;
  vi  dst;
  vi  pre;
  vi  ans;
  void dfs(int x, int p){
    dst[x] = dst[p] + 1;
    for( auto y : g[x] ){
      if( y!=p ) dfs( y, x );
    }
  }

  void find_path(int a, int b){
    dst.assign(n,0);
    dst[a] = true;
    queue<int> Q;
    Q.push(a);
    while(!Q.empty()){
      int u = Q.front(); Q.pop();
      for( auto y : g[u] ){
        if( !dst[y] ){
          pre[y] = u;
          dst[y] = true;
          Q.push(y);
        }
        if( y == b ){
          break;
        }
      }
    }

    int idx = b;
    while( pre[idx] != -1 ){
      ans.pb(idx);
      idx = pre[idx];
    }
    assert( idx == a );
    ans.pb(idx);
  }
    
  public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
      if( n==0 && edges.empty() ) return vi() ;
      if( n == 1 ) return {0};
      if( n == 2 ) return {0, 1};
      this->n = n;
          
      g.resize(n);
      dst.resize(n,0);
      pre.resize(n,-1);
      for( const ii & e : edges ){
        g[e.first].pb(e.second);
        g[e.second].pb(e.first);
      }
      debug("g.sz",g.size());
      dfs(0, -1);
      int a = max_element(all(dst)) - dst.bg;
      debug("a=",a);
      dst.assign(n, 0);
      dfs(a, -1);
      int b = max_element(all(dst)) - dst.bg;
      debug("b=",b);
      find_path(a,b);
      print_(ans);
      if( ans.size()%2 == 0 ){
        return {ans[ans.size()/2], ans[ans.size()/2-1]};
      }else{
        return {ans[ans.size()/2]};
      }
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  vii v(m);
  for( auto & e : v ){
    cin >> e.first >> e.second;
  }
  Solution sol;
  auto ans = sol.findMinHeightTrees(n, v);
  print_(ans);
  return 0;
}
