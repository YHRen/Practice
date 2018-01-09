#include <vector>
#include <set>
#include <queue>
#include <functional>
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
#define print_( a )               for( int  x : a ) clog << x << ' '; clog << '\n';
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
// https://leetcode.com/problems/super-ugly-number/
// Write a program to find the nth super ugly number.
//
// Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
//
// Note:
// (1) 1 is a super ugly number for any given primes.
// (2) The given numbers in primes are in ascending order.
// (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
// (4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer. 
class Solution {
  public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
      vector<int> ugly( n, 0);
      vector<int> idx ( primes.size(), 0 );
      vector<int> tmp ( primes.size(), 0 );
      ugly[0] = 1;
      for( int i = 1; i < ugly.size(); ++ i ){
        for( int j = 0; j < primes.size(); ++j ){
          tmp[j] =  ugly[idx[j]]*primes[j] ;
        }
        ugly[i] = *min_element( tmp.begin(), tmp.end() );
        for( int j = 0; j < primes.size(); ++j ){
          if( tmp[j] == ugly[i] )  ++idx[j];
        }
      }
      return ugly.back();
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n,m; cin >> n >> m;
  vector<int> v(n);
  input(v);
  Solution s;
  cout << s.nthSuperUglyNumber( m, v ) << '\n';




  return 0;
}
