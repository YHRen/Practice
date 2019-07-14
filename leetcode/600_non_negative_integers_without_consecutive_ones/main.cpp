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
  unordered_map<int,int> dp;
  vi get_bits(int n){
    vi res;
    while(n){
      res.pb(n&1);
      n >>= 1;
    }
    return res;
  }
  public:
    int findIntegers(int n) {
      if( in(n, dp) ) return dp[n];
      if( n < 3 ) return n+1;
      if( n < 6 ) return n;
      if( n < 8 ) return 5;
      auto bits = get_bits(n);
      int m = sz(bits);
      int ans = 0;
      if( bits[m-1] == 1 and bits[m-2] == 1 ){
        ans = 2*findIntegers( (1<<(m-2))-1) + findIntegers((1<<(m-3))-1);
      }else if( bits[m-1] == 1 and bits[m-2] == 0 ){
        ans = findIntegers( (1<<(m-2))-1) + findIntegers((1<<(m-3))-1);
        int nxt = 0;
        for(int i = m-3; i>=0; --i){
          nxt |= bits[i];
          nxt <<= 1;
        }
        nxt >>= 1;
        debug("nxt =", nxt);
        ans += findIntegers( nxt );
      }else if( bits[m-1] == 0 and bits[m-2] == 1 ){
        ans = findIntegers((1<<(m-3))-1);
      }else{
        ans = findIntegers((1<<(m-2))-1);
      }
      return dp[n] = ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
