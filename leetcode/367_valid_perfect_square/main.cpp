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
// 367. Valid Perfect Square
// https://leetcode.com/problems/valid-perfect-square/
//Given a positive integer num, write a function which returns True if num is a
//perfect square else False.
//
//Note: Do not use any built-in library function such as sqrt.
//
//Example 1:
//
//Input: 16
//Returns: True
//
//Example 2:
//
//Input: 14
//Returns: False
//
class Solution {
  public:
    bool isPerfectSquare(int n) {
      if( n <= 0 ) return false;
      if( n % 2 == 0 ){
        int cnt = 0;
        while( n % 2 == 0 ){
          ++ cnt;
          n /= 2;
        }
        if( cnt % 2 != 0 ) return false;
      }
      if( n == 1 ) return true;
      int p = 2, q = n/2;
      int t = p;
      while( q - p > 1 ){
        p = n / ( ( p + q ) / 2 );
        q = n / p;
        if( p > q ) swap( p, q );
        if( t == p ) break;
        t = p;
        debug(p,q);
      }
      return p == q && p*q == n;
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  Solution s;
  cout << s.isPerfectSquare(n) << '\n';

  return 0;
}
