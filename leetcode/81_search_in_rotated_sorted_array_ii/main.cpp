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
public:
    bool search(vi & v, int target) {
      int n = sz(v);
      if( !n ) return false;
      if( n == 1 ) return v[0] == target;
      int lo,hi,mid;
      lo = 0, hi = n-1, mid = (hi+lo)/2;
      if( v[lo] == target or v[hi] == target or v[mid] == target ) return true;
      if( v[lo] < v[hi] ){ // already sorted, no rotation
        auto itr = lower_bound(all(v), target);
        return !(itr==v.end() or *itr!=target);
      }
      if( v[lo] == v[hi] ){
        auto itr = find_if(all(v),[a = v[0]](int x){return x != a;});
        if( itr == v.end() ) return false;
        lo = itr-v.begin();
      }
      if( v[lo] == target ) return true;
      if( v[lo] < v[hi] ){
        auto itr = lower_bound(v.begin()+lo, v.end(), target);
        return !(itr==v.end() or *itr!=target);
      }
      mid = (hi+lo)/2;
      debug("lo, mid, hi", lo, mid, hi);
      while(lo<mid){
        debug("mid=",mid, v[mid]);
        if( v[mid] == target ) return true;
        if( v[mid] <= v[hi] and v[mid] < v[mid-1] ) break;
        if( v[mid] > v[hi] ){ // go right
          lo = mid;
          mid = (lo+hi)/2;
        }else if( v[mid] <= v[hi] ){ // go left
          hi = mid;
          mid = (lo+hi)/2;
        }
      }
      debug("found mid = ", mid);
      auto itr = v.end();
      if( v[0] <= target ) itr = lower_bound(v.begin(), v.begin()+mid,target);
      else itr = lower_bound(v.begin()+mid, v.end(), target );
      return !(itr == v.end() or *itr!=target);
    }
};
int main( int argc, char * argv[] ){
  int n,t; cin >> n >> t;
  vi v(n); input(v);
  Solution sol;
  cout << sol.search(v,t) << endl;
  return 0;
}
