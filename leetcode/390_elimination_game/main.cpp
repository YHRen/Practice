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
// 390. Elimination Game
// https://leetcode.com/problems/elimination-game/
// There is a list of sorted integers from 1 to n. Starting from left to right,
// remove the first number and every other number afterward until you reach the
// end of the list.
//
// Repeat the previous step again, but this time from right to left, remove the
// right most number and every other number from the remaining numbers.
//
// We keep repeating the steps again, alternating left to right and right to
// left, until a single number remains.
//
// Find the last number that remains starting with a list of length n.
//
// Example:
//
// Input:
// n = 9,
// 1 2 3 4 5 6 7 8 9
// 2 4 6 8
// 2 6
// 6
//
// Output:
// 6
//
class Solution {
  public:
    int lastRemaining(int n) {
      uint64_t bits  = 0;
      bool     round = 0;
      int      turns = floor( log2( n ) );
      while( n != 1 ){
        if( round && n%2==0 ){
          bits <<= 1;
          bits |=  1;
        }else{
          bits <<= 1;
        }
        n /= 2;
        round ^= 1;
      }
      while( turns -- > 0 ){
        //n = bits & 1 ? (n+1)*2 : 2*n;
        n <<= 1;
        n -= bits & 1;
        bits >>= 1;
      }
      return n;
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  Solution s;
  cout << s.lastRemaining( n ) << endl;




  return 0;
}
