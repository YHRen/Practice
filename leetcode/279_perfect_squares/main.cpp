#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <functional>
#include <numeric>
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
// https://leetcode.com/problems/perfect-squares/
// 279. Perfect Squares 
// Given a positive integer n, find the least number of perfect square numbers
// (for example, 1, 4, 9, 16, ...) which sum to n.
//
// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13,
// return 2 because 13 = 4 + 9.
//
class Solution {
  public:
    int numSquares(int n) {
      if( n < 1 ) return 0;
      vector<int> dp = {0};
      dp.reserve(n+1);
      while( dp.size() < n+1 ){
        int m = dp.size();
        int val = numeric_limits<int>::max();
        for( int i = 1; i*i <= m; ++i ){
          val = min( val, 1 + dp[ m - i*i ] );
        }
        dp.push_back(val);
      }
      return dp.back();
    }

};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  Solution s;
  cout << s.numSquares(n) << '\n';





  return 0;
}
