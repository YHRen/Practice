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

int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vector<ll> v(n); input(v);
  vector<vector<ll>> dp(n,vector<ll>(n, numeric_limits<ll>::max()));
  vector<ll> cumsum(n+1);
  cumsum[0] = 0;
  forall(i,0,n) cumsum[i+1] = cumsum[i] + v[i];

  // inclusive [l, r]
  auto get_part = [&](int l, int r){ return cumsum[r+1] - cumsum[l]; };
  for(int L = n-1; L >= 0; --L){
    for(int R = L; R < n; ++R ){
      if( L == R ){ dp[L][R] = 0; continue; }
      if( R - L == 1 ){ dp[L][R] = v[L] + v[R]; continue; }
      forall(k, L, R) {
        dp[L][R] = min(dp[L][R], dp[L][k] + dp[k + 1][R] + get_part(L, R));
      }
      trace(L, R, dp[L][R], res);
    }
    print_(dp[L]);
  }
  cout << dp[0][n-1] << endl;

  
  return 0;
}
