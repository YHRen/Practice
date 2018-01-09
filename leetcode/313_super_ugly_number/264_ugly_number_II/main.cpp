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
// https://leetcode.com/problems/ugly-number-ii/
//  Write a program to find the n-th ugly number.
//
//  Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
//  For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
//  ugly numbers.
//
//  Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
//
//    The naive approach is to call isUgly for every number until you reach the
//    nth one. Most numbers are not ugly. Try to focus your effort on
//    generating only the ugly ones.  An ugly number must be multiplied by
//    either 2, 3, or 5 from a smaller ugly number.  The key is how to maintain
//    the order of the ugly numbers. Try a similar approach of merging from
//    three sorted lists: L1, L2, and L3.  Assume you have Uk, the kth ugly
//    number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
//
class Solution {
  public:
    int nthUglyNumber(int n) {
      if( n == 1 ) return 1;
      vector<int> v(n,0);
      vector<int> idx(3,0);
      v[0] = 1;
      for( int i = 1; i < v.size(); ++i ){
        v[i] = min( 2*v[idx[0]], min( 3*v[idx[1]], 5*v[idx[2]] ) );
        if( v[i] == 2*v[idx[0]] ) ++idx[0];
        if( v[i] == 3*v[idx[1]] ) ++idx[1];
        if( v[i] == 5*v[idx[2]] ) ++idx[2];
      }
      return v.back();
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);




  return 0;
}
