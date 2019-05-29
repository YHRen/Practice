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
  double get_median( const vi & v ){
    int n = sz(v);
    if( n%2 ){
      return v[n/2];
    }else{
      return double(v[n/2-1]+v[n/2])/2;
    }
  }
  public:
    double findMedianSortedArrays(vector<int>& v, vector<int>& u) {
      const int inf = numeric_limits<int>::max();
      int n = sz(v), m = sz(u);
      if( n == 0 ){ return get_median(u); }
      if( m == 0 ){ return get_median(v); }

      int l = min(v[0],u[0]);
      int r = max(v[n-1],u[m-1])+1;
      int t = (m+n)/2;
      int mid, res = -1;
      while( r-l>1 ){
        mid = (r+l)/2;
        auto itr1a = upper_bound(all(v),mid);
        auto itr1  = lower_bound(all(v),mid);
        auto itr2a = upper_bound(all(u),mid);
        auto itr2  = lower_bound(all(u),mid);
        int p = (itr1  - v.begin())+ (itr2  -u.begin()); // num. of elems < mid;
        int q = (itr1a-itr1) + (itr2a-itr2 ); // num. of elms == mid
        debug("mid=",mid,"p=",p, "q=",q, itr1-v.begin(), itr2-u.begin());
        if( p == t ){ // found one 
          debug("left is half");
          if( (n+m)%2 == 1 ){
            debug("odd",*itr1, *itr2);
            return min(itr1==v.end()?inf:*(itr1), itr2==u.end()?inf:*(itr2));
          }else{
            int left,right;
            if( itr1!=v.begin() and itr2!=u.begin()  ) left = max( *(itr1-1), *(itr2-1));
            else if( itr1==v.begin() ) left = *(itr2-1);
            else left = *(itr1-1);
            if( itr1 != v.end() and itr2!=u.end() ) right = min(*itr1, *itr2);
            else if( itr1==v.end() ) right = *itr2;
            else right = *itr1;
            return double(left+right)/2;
          }
        }else if( p < t and p+q >= t ){
          debug("left + dup covers half");
          if( (n+m)%2 == 1 ){
            if( p+q > t ){
              debug("odd",*itr1, *itr2);
              return min(itr1==v.end()?inf:*(itr1), itr2==u.end()?inf:*(itr2));
            }else if( p+q == t){
              return min(itr1a==v.end()?inf:*(itr1a), itr2a==u.end()?inf:*(itr2a));
            }
          }else{
            if( p+q > t ){
              return min(itr1==v.end()?inf:*(itr1), itr2==u.end()?inf:*(itr2));
            }else{
              debug("p+q==t");
            vi candidates;
            if( itr1a!=v.end() ){ 
              candidates.pb(*itr1a);
              if( itr1a > itr1 ) candidates.pb(*(itr1a-1));
            }
            if( itr2a!= u.end() ){ 
              candidates.pb(*itr2a);
              if( itr2a > itr2 ) candidates.pb(*(itr2a-1));
            }
            print_(candidates);
            sort(all(candidates));
            return double(candidates[0] + candidates[1])/2;
            }
          }
        }else if( p < t ){ // increase l
          l = mid;
        }else if( p > t ){
          r = mid;
        }
      }
      return l;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m; 
  vi v(n); input(v);
  vi u(m); input(u);
  Solution sol;
  cout << sol.findMedianSortedArrays(v,u) << endl;
  return 0;
}
