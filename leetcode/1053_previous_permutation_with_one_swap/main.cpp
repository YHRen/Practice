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
    vector<int> prevPermOpt1(vector<int>& u) {
      auto v = u;
      print_(v);
      if( is_sorted(all(v)) ) return v;
      int n = sz(v);
      int r = n-1;
      for(int i = r; i >= 1; --i ){
        if( v[i] < v[i-1] ){
          debug("found", i, v[i], v[i-1]);
          int j = i;
          int jj = i, max_j = v[i];
          // find the first largest element that is smaller than v[i]
          while( j < n and v[j] < v[i-1] ){
            if( v[j] > max_j ) { jj = j, max_j = v[j] ; }
            j++;
          }
          --j;
          debug("idx = ", j, jj, max_j);
          swap(v[i-1], v[jj]);
          return v;
        }
      }
      return v;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  Solution sol;
  auto res = sol.prevPermOpt1(v);
  print_(res);
  return 0;
}
