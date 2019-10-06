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
  ll L,H;
  vi ans;
  ll to_num( const vi & digs ){
    if( digs.empty() ) return 0;
    ll ans = 0;
    for(auto x : digs){
      ans += x;
      ans *= 10;
    }
    ans /= 10;
    return ans;
  }
  void aux( vi & v, ll val ){
    if( val <= H and val >= L ) ans.pb(val);
    if( val > H ) return;
    if( v.back() != 9 ){
      int nxt = v.back()+1;
      v.pb(nxt);
      val*=10;
      val += nxt;
      aux(v, val);
      v.pop_back();
      val /= 10;
    }
    if( v.back() != 0 ){
      int nxt = v.back()-1;
      v.pb(nxt);
      val *= 10;
      val += nxt;
      aux(v, val);
      v.pop_back();
      val/=10;
    }
  }

  public:
    vector<int> countSteppingNumbers(int low, int high) {
    L = low, H = high;
      vi v;
      if( low == 0 ) ans.pb(0);
      forall(i,1,10){
        v.clear();
        v.pb(i);
        aux(v, i);
      }
      sort(all(ans));
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n; 
  vi v(n); input(v);
  return 0;
}
