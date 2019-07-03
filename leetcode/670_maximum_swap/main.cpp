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
  vi to_vec(int num){
    vi res;
    while(num){
      res.pb(num%10);
      num/=10;
    }
    return res;
  }
  int to_num(const vi & v){
    int res = 0;
    for(auto itr = v.rbegin(); itr!=v.rend(); ++itr){
      res *= 10;
      res += *itr;
    }
    return res;
  }
public:
    int maximumSwap(int num) {
      auto v = to_vec(num);
      print_(v);
      if( is_sorted(all(v)) ) return num;
      int n = sz(v);
      for(int r = n-1; r > 0; --r){
        int val = -1, loc = -1, x =v[r];
        debug("x=",x);
        for(int l = 0; l < r; ++l){
          if( v[l] > x and v[l] > val ){
            val = v[l];
            loc = l;
          }
        }
        debug("val=",val, "loc=",loc);
        if( val != -1 ){
          swap(v[loc],v[r]);
          print_(v);
          return to_num(v);
        }
      }
      return -1;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  Solution sol;
  cout << sol.maximumSwap(n) << endl;
  return 0;
}
