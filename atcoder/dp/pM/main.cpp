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

auto modadd = [](ll & x, ll  y){
  if( y < 0 ) y += INF;
  x += y;
  x %= INF;
};

auto modsub = [](ll & x, const ll & y){
  if( y > x ) x += INF;
  x -= y;
  x %= INF;
};

int main( int argc, char * argv[] ){
  int n, m; cin >> n >> m; 
  vi v(n); input(v);
  vector<ll> dp(m+1, 0), u(m+1, 0);
  dp[0] = 1;
  for (auto x : v) {
    trace(x);
    u.assign(sz(u), 0);
    for (int i = m; i >= 0; --i) {
      ll tmp = dp[i]; if( tmp == 0 ) continue;
      modadd( u[i], tmp);
      if( i+x+1 < m+1 ) modsub(u[i+x+1], tmp);
    }
    debug("u");
    print_(u);
    ll run = 0;
    forall(i,0,m+1){
      modadd(run, u[i]);
      dp[i] = run;
    }
    debug("dp");
    print_(dp);
  }
  cout << dp[m] << endl;

  return 0;
}
