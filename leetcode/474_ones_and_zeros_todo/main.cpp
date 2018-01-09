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
//  https://leetcode.com/problems/ones-and-zeroes/
//In the computer world, use restricted resource you have to generate maximum
//benefit is what we always want to pursue.
//
//For now, suppose you are a dominator of m 0s and n 1s respectively. On the
//other hand, there is an array with strings consisting of only 0s and 1s.
//
//Now your task is to find the maximum number of strings that you can form with
//given m 0s and n 1s. Each 0 and 1 can be used at most once.
//
//Note:
//
//    The given numbers of 0s and 1s will both not exceed 100 The size of given
//    string array won't exceed 600.
//
//        Example 1:
//
//        Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
//        Output: 4
//
//        Explanation: This are totally 4 strings can be formed by the using of
//        5 0s and 3 1s, which are “10,”0001”,”1”,”0”
//
//        Example 2:
//
//        Input: Array = {"10", "0", "1"}, m = 1, n = 1 Output: 2
//
//        Explanation: You could form "10", but then you'd have nothing left.
//        Better form "0" and "1".
//
class Solution {
  public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      if( strs.empty() || m < 0 || n < 0 ) return 0;
      vector<vector<int16_t>> dp( m+1, vector<int16_t>( n+1, 0 ) );
      for( const auto & s : strs ){
        int cnt0 = count( s.begin(), s.end(), '0' );
        int cnt1 = s.length() - cnt0 ;
        for( int i = m; i >= cnt0; --i ){
          for( int j = n; j >= cnt1; --j ){
            if( dp[i-cnt0][j-cnt1] + 1 > dp[i][j] ){
              dp[i][j] =  dp[i-cnt0][j-cnt1] + 1 ;
            }
          }
        }
      }
      return dp[m][n];
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int m,n,sz; cin >> m >> n >> sz;
  vector<string> v(sz);
  input(v);
  Solution s;
  cout << s.findMaxForm(v,m,n) << '\n';
  return 0;
}
