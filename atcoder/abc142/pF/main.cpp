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
#define trace(...)       __f(#__VA_ARGS__, __VA_ARGS__)
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define trace(...)       
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << ": " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " | ";
    __f(comma + 1, args...);
}

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();

vi prv, dst;
vi bfs(int src, const vvi & G){
  dst.assign(sz(dst), INF);
  prv.assign(sz(prv), INF);
  prv[src] = -1;
  dst[src] = 0;
  queue<int> Q;
  Q.push(src);
  vi ans;
  while( !Q.empty() ){
    auto x = Q.front(); Q.pop();
    for(auto y : G[x]){
      if( dst[y] == INF ){
        dst[y] = dst[x] + 1;
        prv[y] = x;
        Q.push(y);
        debug("  y=",y, "pushing");
      }
    }
  }
  int min_dist = INF;
  forall(i,0,sz(prv)){
    if( i == src ) continue;
    for(auto j : G[i]){
      if( j != src or dst[j] == INF ) continue;
      if( dst[i] < min_dist ){
        min_dist = dst[i];
        vi tmp;
        int x = i;
        while(x != src){
          tmp.pb(x);
          x = prv[x];
        }
        tmp.pb(src);
        ans = tmp;
      }
    }
  }
  return ans;
}

int main(int argc, char * argv[]){
  int n,m; cin >> n >> m; 
  debug(n,m);
  vvi G(n);
  for(int i=0, x, y; i < m; ++i){
    cin >> x >> y;
    --x, --y;
    G[x].pb(y);
  }
  for(auto v : G){
    print_(v);
  }

  prv.resize(n, INF);
  dst.resize(n, INF);

  vi ans;
  int min_len = INF;
  forall(i,0,n){
    debug("i=",i);
    print_(prv);
    auto tmp = bfs(i, G);
    if( tmp.empty() ) continue;
    if( sz(tmp) < min_len ){
      min_len = sz(tmp);
      ans = tmp;
    }
  }
  if( ans.empty() ){
    cout << -1 << '\n';
  }else{
    cout << sz(ans) << '\n';
    reverse(all(ans));
    for(auto x : ans){
      cout << x+1 << '\n';
    }
  }

  return 0;
}
