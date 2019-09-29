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
  /* find bridge algorithm */
  vi D,L,V; // depth, Low
  vvi G,ans;
  int timer = 0;
  void dfs(int x, int p){
    D[x] = L[x] = timer++;
    for(auto y : G[x]){
      if( y == p ) continue;
      if( D[y] != -1 ){ // visited
        L[x] = min(L[x], D[y]);
      }else{
        dfs(y, x);
        L[x] = min(L[x], L[y]);
        if( L[y] > D[x] ){
          ans.pb({x,y});
        }
      }
    }
  }

  public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
      G.resize(n);
      for(const auto & e : connections){
        G[e[0]].pb(e[1]);
        G[e[1]].pb(e[0]);
      }
      D.resize(n,-1);
      L.resize(n,-1);
      V.resize(n,0);
      V[0] = 1;
      dfs(0, -1);
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
