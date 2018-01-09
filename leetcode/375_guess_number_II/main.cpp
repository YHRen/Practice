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
// https://leetcode.com/problems/guess-number-higher-or-lower-ii/

class Solution {
  private:
    int get_money_aux( int lo, int hi, 
        vector<vector<int>> & dp ){
      if( lo > hi  ) return 0;
      if( dp[lo][hi] != -1 ) return dp[lo][hi];
      if( lo == hi ){ dp[lo][hi] = 0; return 0; } // no need to guess 
      if( hi-lo == 1 ){ dp[lo][hi] = lo; return lo; } // two elements, guess the lower one
      if( hi-lo == 2 ){ dp[lo][hi] = (hi+lo)/2; return dp[lo][hi]; } // three elements, guess the middle one

      int cost = numeric_limits<int>::max();
      for(int mid = lo + 1; mid != hi; mid ++ ){
        cost = min( cost, max(
              mid + get_money_aux( lo, mid-1, dp ), 
              mid + get_money_aux( mid+1, hi, dp ) ) );
      }
      dp[lo][hi] = cost;
      return cost;
    }


  public:
    int getMoneyAmount(int n) {
      if( n <= 1 ) return 0;
      // dp[i][j] := the minimum number of money required for the interval [i,j]
      vector<vector<int>> dp( n+1, vector<int>( n+1, -1 ) );
      int tot = get_money_aux( 1, n, dp );
      //for( auto & v : dp ){
      //  print_(v);
      //}
      return tot;
    }
};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n ; cin >> n;
  Solution s;
  cout << s.getMoneyAmount(n) << '\n';
  return 0;
}
