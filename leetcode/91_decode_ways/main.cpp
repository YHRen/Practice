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
// https://leetcode.com/problems/decode-ways/
// A message containing letters from A-Z is being encoded to numbers using the
// following mapping: 
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//  Given an encoded message containing digits, determine the total number of
//  ways to decode it.
//
//  For example,
//  Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
//  The number of ways decoding "12" is 2. 

// solution: a classic DP problem, dp[i] = dp[i+1] + dp[i+2], 
// dp[i+1] == null only if s[i+1] = 0
// dp[i+2] == null only if s[i+1]s[i+2] == 0 || > 26 or i+2 > n
class Solution {
  private:
    inline bool is_valid_one( char c ){
      return c != '0';
    }
    inline bool is_valid_two( char c1, char c2 ){
      return ( c1 == '1' || (c1 == '2' && (c2 - '0') < 7) );
    }
    int64_t count_aux( int idx, 
        const string & s,  
        vector<int64_t> & dp ){
      const int & n = s.length()-1;
      if( idx == s.length() ) return 1;
      if( dp[idx] != -1 ) return dp[idx];
      /*
      if( idx == n ){
        dp[idx] = ( is_valid_one( s[n] ) ? 1 : 0 );
        return dp[idx];
      }
      */
      dp[idx] = 0;
      if( is_valid_one( s[idx] ) ){
        dp[idx] += count_aux( idx + 1, s, dp );
      }
      if( is_valid_two( s[idx], s[idx+1] ) ){
        dp[idx] += count_aux( idx + 2, s, dp );
      }
      // if both invalid, return 0, illegal message, such as 330
      return dp[idx];
    }

  public:
    int numDecodings(string s) {
      // dp[i] = the number of ways to decode of the substring after ith
      // element including i.
      if( s.empty() ) return 0;
      vector<int64_t> dp( s.length(), -1 );
      dp.back() = ( is_valid_one( s.back() ) ? 1 : 0 );
      return count_aux( 0, s, dp );
    }
};


int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  string str; cin >> str;
  Solution s;
  cout << s.numDecodings( str ) << '\n';




  return 0;
}
