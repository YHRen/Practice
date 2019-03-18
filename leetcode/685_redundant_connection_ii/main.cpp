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
#define forall(i,a,b)               for(int i=a;i<(b);++i)
#define trav(a,x)                   for(auto & a: x)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define sz(c)                       (int)(c).size()
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

auto ____ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
};
class Solution {
  vvi g;
  bool dfs( int x, int p, int t){
    if( x == t ) return true;
    for(auto y: g[x]){
      if( y!=p){
        if(dfs(y,x,t)) return true;
      }
    }
    return false;
  }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
      int n = sz(edges);
      g.resize(n+1);
      vi p(n+1,-1);
      UF uf(n+1);
      vi D;
      vi cycle_e;
      for(auto & e : edges){
        int x = e[0], y = e[1];
        g[x].pb(y);
        g[y].pb(x);
        if( p[y] == -1 ) p[y] = x;
        else if( p[x] == y ){
          return e;
        }else{
          D.pb(y);
          D.pb(p[y]);
          D.pb(x);
        }
        if( uf.find(x) == uf.find(y) ){
          cycle_e = e;
        } else uf.join(x,y);
      }
      if( D.empty() ) return cycle_e;
      if( dfs(D[2],D[0], D[0]) ) return {D[2], D[0]};
      else return {D[1],D[0]};
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vvi edges(n, vi(2));
  for(auto & e : edges) input(e);
  Solution sol;
  auto ans = sol.findRedundantDirectedConnection(edges);
  print_(ans);

  return 0;
}
