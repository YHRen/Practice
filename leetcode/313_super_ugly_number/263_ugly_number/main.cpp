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
// 263. Ugly Number
// https://leetcode.com/problems/ugly-number/
// Write a program to check whether a given number is an ugly number.
//
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
// For example, 6, 8 are ugly while 14 is not ugly since it includes another
// prime factor 7.
//
// Note that 1 is typically treated as an ugly number. 
class Solution {
  public:
    bool isUgly(int x) {
      if( x == 1 ) return true;
      if( x <= 0 ) return false;
      while( x%2 == 0 ) x/=2;
      while( x%3 == 0 ) x/=3;
      while( x%5 == 0 ) x/=5;
      return x==1;
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);




  return 0;
}
