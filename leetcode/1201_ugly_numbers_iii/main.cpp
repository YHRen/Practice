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
  vector<ll> v;
  int find_k( ll x ){
    debug("findK",x);
    ll ans = 0;
    ans = x/v[0] + x/v[1] + x/v[2];
    debug("ans",ans);
    ans = ans - x/v[3] - x/v[4] - x/v[5];
    debug("ans",ans);
    ans += x/v[6];
    debug("ans",ans);
    return ans;
  }
  ll lcd( ll a, ll b ){
    return  a/__gcd(a,b)*b;
  }
  public:
    int nthUglyNumber(int n, int a, int b, int c) {
      v = {a,b,c};
      sort(all(v));
      v.pb(lcd(a,b));
      v.pb(lcd(a,c));
      v.pb(lcd(b,c));
      v.pb(lcd(lcd(a,b), lcd(b,c)));

      ll lo = 1, hi = 2*INF;
      while( lo < hi ){
        ll mid = lo + (hi-lo)/2;
        ll k = find_k(mid);
        debug("mid=",mid,"k=",k);
        if( k == n ){
          while( mid%a != 0 and mid%b!=0 and mid%c != 0 ){
            mid --;
          }
          return mid;
        }else if( k < n ){
          lo = mid + 1;
        }else{
          hi = mid;
        }
      }
      return lo;
    }
};
int main( int argc, char * argv[] ){
  int n, b, c, a;
  cin >> n >> a >> b >> c;
  Solution sol;
  cout << sol.nthUglyNumber(n,a,b,c) << endl;
  return 0;
}
