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
    int search(vector<int>& v, int target) {
      int n = sz(v); if( !n ) return -1;
      if( n == 1 ) return v[0] == target ? 0 : -1;
      if( v[0] < v[n-1] ){ // already sorted
        auto itr = lower_bound(all(v), target);
        if( itr == v.end() or *itr != target ) return -1;
        else return itr-v.begin();
      }
      int lo = 0, hi = n-1;
      if( v[lo] == target ) return lo; 
      if( v[hi] == target ) return hi;
      int mid = (hi+lo)/2;
      while( mid > lo ){
        debug("mid", mid, lo, hi);
        if( v[mid] < v[hi] and v[mid] < v[mid-1] ) break;
        if( v[mid] > v[hi] ){// mv right
          lo = mid;
          mid = (lo+hi)/2;
        }else{ // mv left
          hi = mid;
          mid = (lo+hi)/2;
        }
      }
      debug("found mid = ", mid, v[mid]);
      auto itr = v.end();
      if( v[0] <= target ){ // first half
        itr = lower_bound(v.begin(), v.begin()+mid, target);
      }else{ //second half
        itr = lower_bound(v.begin()+mid, v.end(), target);
      }
      if( itr == v.end() or *itr != target ) return -1;
      else return itr-v.begin();
    }
};
int main( int argc, char * argv[] ){
  int n, t; cin >> n >> t;
  vi v(n); input(v);
  Solution sol;
  cout << sol.search(v, t) << endl;
  return 0;
}
