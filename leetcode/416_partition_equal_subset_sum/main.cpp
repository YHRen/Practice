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
// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/
//Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
//Note:
//
//    Each of the array element will not exceed 100.
//        The array size will not exceed 200.
//
//        Example 1:
//
//        Input: [1, 5, 11, 5]
//
//        Output: true
//
//        Explanation: The array can be partitioned as [1, 5, 5] and [11].
//
//        Example 2:
//
//        Input: [1, 2, 3, 5]
//
//        Output: false
//
//        Explanation: The array cannot be partitioned into equal sum subsets.

class Solution {
  private:
    bool solve_aux( 
        int n, int k, 
        vector<vector<int8_t>> & dp,
        const vector<int> & v 
        ){
      if( k >= v.size() || n < 0 ) return false;
      if( n == 0 ) return true;
      if( dp[n][k] != -1 ) return dp[n][k];
      dp[n][k] = solve_aux( n, k+1, dp, v ) || solve_aux( n-v[k], k+1, dp, v );
      return dp[n][k];
    }
  public:
    bool canPartition(vector<int>& v) {
      int tot = 0;
      for( auto x : v ){
        tot += x;
      }
      debug("tot=",tot);
      if( tot % 2 ) return false;
      int n = tot / 2;
      debug("n=",n);
      int k = v.size();
      vector<vector<int8_t>> dp( n+1, 
          vector<int8_t>( k, -1 ) );
      return solve_aux( n, 0, dp, v );
    }
};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> v(n);
  input(v);
  Solution s;
  cout << s.canPartition(v) << '\n';




  return 0;
}
