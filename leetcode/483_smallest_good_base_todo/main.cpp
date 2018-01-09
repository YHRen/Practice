#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <cmath>
#include <cassert>

#define input(v)                  for(int i = 0; i < v.size(); ++i){ cin >> v[i]; }

// numeric_limits
#define INF                         (int)1e9
#define EPS                         1e-9

#define bitcount                    __builtin_popcount
#define gcd                         __gcd

#define forall(i,a,b)               for(int i=a;i<b;i++)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define mp                          make_pair

#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
typedef unsigned long long int ull_t;
typedef long long int           ll_t;

using namespace std;

#ifdef DEBUG
#define debug(args...)            {dbg,args; clog<<endl;}
#define print_( a )               for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )           for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)             // Just strip off all debug tokens
#define print_( a )               // skip
#define printPair_( a )           // skip
#endif
struct debugger
{
  template<typename T> debugger& operator , (const T& x)
  {    
    clog << x << " ";    
    return *this;    
  }
} dbg;

/******* Actual Code Starts Here *********/
// contest 16B

class Solution {
  public:
    string smallestGoodBase_slow(string str) {
      uint64_t n = stoull( str );
      for( uint64_t base = 2; base < n; ++ base ){
        uint64_t digits = ceil(log( static_cast<double>(n) ) / log( static_cast<double>(base) ));
        //debug( base, digits );
        uint64_t p = uint64_t( pow( base, digits ) ); 
        if( (p - 1) % n == 0 && base-1 == (p-1)/n )
          return to_string(base);
      }
      return " " ;
    }
    string smallestGoodBase(string str) {
      uint64_t n = stoull( str );
      n -= 1;
      uint64_t k = 2;
      uint64_t q = floor( pow(n, 1.0/k ) );

      for(; q > 1; ++ k ){
        q = floor( pow( n, 1.0/k ) );
        if( q == 1 ) break;
        debug("q,k", q,k );
        if( uint64_t( pow(q,k) -1 ) % (q-1) == 0 &&
         n == q * ( pow(q, k) - 1 ) / ( q-1 ) ){
          return to_string(q);
        }
        //q = floor( pow( n, 1.0/k ) );
      }
      return to_string(n);
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  string str;
  cin >> str;
  Solution s;
  cout << s.smallestGoodBase( str ) << '\n';
//  cout << s.smallestGoodBase_slow( str ) << '\n';





  return 0;
}
