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
typedef unsigned long long ull;

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
/*
For an integer n, we call k>=2 a good base of n, if all digits of n base k are 1.

Now given a string representing n, you should return the smallest good base of n in string format.

Example 1:

Input: "13"
Output: "3"
Explanation: 13 base 3 is 111.

 

Example 2:

Input: "4681"
Output: "8"
Explanation: 4681 base 8 is 11111.

 

Example 3:

Input: "1000000000000000000"
Output: "999999999999999999"
Explanation: 1000000000000000000 base 999999999999999999 is 11.

 

Note:

    The range of n is [3, 10^18].
    The string representing n is always valid and will not have leading zeros.
 */
auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
  ull N;
  ull base;
  bool C(int k){
    if( (1ULL<<k) > N ) return false;
    ull lo = 1, hi = pow(N,1.0/k)+1, mid;
    debug( (pow(lo, k+1) -1) / (lo-1), N , (pow(hi,k+1)-1)/(hi-1));
    while(lo<=hi){
      mid = lo + (hi-lo)/2;
      debug("mid=",mid, "lohi",lo,hi);
      ull m = 1, cur = 1;
      forall(i,0,k){
        cur*= mid, m+=cur;
      }
      if( m == N ){
        base = mid;
        return true;
      }else if( m < N ){
        lo = mid+1;
      }else{
        hi = mid-1;
      }
    }
    return false;
  }

  public:
    string smallestGoodBase(string n) {
      N = stoull(n);
      for(int k = 63; k > 1; --k){
        debug("k=",k);
        if( C(k) ){
          return to_string(base);
        }
      }
      return to_string(N-1);
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  cout << sol.smallestGoodBase(str) << endl;
  return 0;
}
