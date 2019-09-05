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
class MajorityChecker {
  public:
    MajorityChecker(vector<int>& arr) {
        
    }
    
    int query(int left, int right, int threshold) {
        
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */

template<class T>
class StaticSegmentTree {
  vector<T> s; 
  function< T ( const T & , const T & ) > f;
  T unit;
  int n;
  
  public:
  // identity: i.e. INF as in MIN, 0 as in sum, 1 as in mul, 
  // f : any associative fn
  StaticSegmentTree( const vector<T> & v, T unit, 
      function<T(const T &, const T &)> f ) : s(2*n, unit), n(n), f(f), unit(unit) {}

  void update(int pos, const T & val){
    debug("update", pos, val);
    for( s[pos+=n] = val; pos /= 2; ){
      debug("pos = ", pos);
      s[pos] = f( s[pos*2], s[pos*2+1] );
    }
  }

  T query( int b, int e ){ // query [b, e)
    T ra = unit, rb = unit;
    for (b+=n, e+=n; b < e; b/=2, e/=2){
      if(b%2) ra = f(ra, s[b++]);
      if(e%2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

  
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
