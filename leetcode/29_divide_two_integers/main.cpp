#include <vector>
#include <cstdio>
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
public:
    int divide(int dividend_, int divisor_) {
      // y / x
      if( dividend_ == divisor_ ) return 1;
      if( divisor_ == -1 ) return dividend_;
      if( dividend_ == 0 ) return 0;
      if(dividend_ == numeric_limits<int>::min() && abs(divisor_) == 1) return numeric_limits<int>::max();
      bool flag = (dividend_ > 0 and divisor_ > 0) or (dividend_ < 0 and divisor_ < 0);
      ll dividend = labs(dividend_);
      ll divisor  = labs( divisor_);
      debug("flag", flag);
      ll pw = 32;
      ll x = ((ll)divisor)<< 32;
      ll ans = 0;
      ll y = dividend;
      debug("x,y",x,y);
      while( y >= divisor ){
        while( y < x ){
          x >>= 1;
          pw --;
        }
        y -= x;
        ans += (1LL<<pw);
        debug("ans",ans);
      }
      if( flag ) return ans;
      else return -1*ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  Solution sol;
  cout << sol.divide(n,m) << '\n';
  return 0;
}
