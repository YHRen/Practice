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
#include <complex>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF              (int)1000000007
#define EPS              1e-9
#define pb               push_back
#define mp               make_pair
#define all(c)           c.begin(), c.end()
#define forall(i,a,b)    for(int i=a;i<(b);++i)
#define trav(a,x)        for(auto & a: x)
#define in(a,b)          ((b).find(a) != (b).end())
#define sz(c)            (int)(c).size()
#define input(a)         for(auto & x : a) cin >> x;

using namespace std;

typedef vector<int>      vi;
typedef pair<int,int>    ii;
typedef vector<vi>       vvi;
typedef vector<vvi>      vvvi;
typedef vector<ii>       vii;
typedef long long        ll;

#ifdef DEBUG
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
  vvvi G;
  vvi dist;
  int n;
  vi bfs(void){
    dist[0][0] = 0;
    dist[1][0] = 0;
    queue<ii> Q;
    Q.push(mp(0,0));
    Q.push(mp(0,1));
    vvi is_visited(2, vi(n, 0));
    is_visited[0][0] = 1;
    is_visited[1][0] = 1;
    while( !Q.empty() ){
      auto [x,c] = Q.front(); Q.pop();
      for(auto y : G[c][x]){
        if( !is_visited[c][y] ){
          is_visited[c][y] = 1;
          dist[c][y] = dist[!c][x] + 1;
          Q.push(mp(y,!c));
        }
      }
    }
    vi res(n);
    forall(i,0,n) 
      if( dist[0][i] == INF and dist[1][i] == INF ) res[i] = -1;
      else res[i] = min(dist[0][i], dist[1][i]);
    return res;
  }
  public:
    vector<int> shortestAlternatingPaths(int n, 
        vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
    this->n = n;
      G.resize(2);
      dist.resize(2);
      for(auto & v : dist) v.resize(n,INF);
      for( auto & g : G ) { g.resize(n); }
      for(auto & v : red_edges){ G[0][v[0]].pb(v[1]); }
      for(auto & v : blue_edges){ G[1][v[0]].pb(v[1]); }
      return bfs();
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
