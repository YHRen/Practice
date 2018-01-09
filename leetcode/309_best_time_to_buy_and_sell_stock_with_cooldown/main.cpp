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
//309. Best Time to Buy and Sell Stock with Cooldown
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete as many
//transactions as you like (ie, buy one and sell one share of the stock
//multiple times) with the following restrictions:
//
//You may not engage in multiple transactions at the same time (ie, you must
//sell the stock before you buy again).  After you sell your stock, you cannot
//buy stock on next day. (ie, cooldown 1 day)
//
// Example:
//
// prices = [1, 2, 3, 0, 2]
// maxProfit = 3
// transactions = [buy, sell, cooldown, buy, sell]
//
class Solution {
  private:
    int profit( int idx,
        vector<int> & dp,
        const vector<int> & v 
        ){
      if( idx >= v.size() ) return 0;
      if( dp[idx] != -1 ) return dp[idx];
      int buy = numeric_limits<int>::max();
      int rst = 0;
      for( int i = idx; i < v.size(); ++i ){
        if( buy > v[i] ){
          buy = v[i];
        }else if( buy < v[i] ){
          rst = max( rst, v[i]-buy + profit( i+2, dp, v ) );
        }
      }
      dp[idx] = rst;
      return rst;
    }
          
  public:
    int maxProfit(vector<int>& v) {
      if( v.empty() || v.size() == 1 ) return 0;
      if( v.size() == 2 ) return max( 0, v[1]-v[0] );
      int n = v.size()-1;
      vector<int> dp( n+1, -1 );
      dp[n] = 0;
      dp[n-1] = max( 0, v[n] - v[n-1] );
      return profit( 0, dp, v );
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> v(n);
  input(v);
  Solution s;
  cout << s.maxProfit(v) << '\n';




  return 0;
}
