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

// Input macros
#define input(v)                  for(int i = 0; i < v.size(); ++i){ cin >> v[i]; }

// numeric_limits
//#define INF                         (int)1e9
#define EPS                         1e-9
// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

#define forall(i,a,b)               for(int i=a;i<b;i++)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define mp                          make_pair
// Some common useful functions
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
//You are given coins of different denominations and a total amount of money
//amount. Write a function to compute the fewest number of coins that you need
//to make up that amount. If that amount of money cannot be made up by any
//combination of the coins, return -1.
//

class Solution{
  public:
    int coinChange( vector<int> & coins, int amount){
      if( amount <= 0 ) return 0;
      if( coins.size() == 0 ) return -1;
      sort( coins.begin(), coins.end() );
      vector<int> dp( amount+1, -1 );
      dp[0] = 0;
      for( int i = 0; i < amount; ++i ){
        if( dp[i] != -1 ){
          for( auto x : coins ){
            if( x <= amount && i+x <= amount ){
              dp[i+x] = ( dp[i+x] == -1 ? 
                  1 + dp[i] : min( dp[i]+1, dp[i+x] ) );
            }
          }
        }
      }
      return dp[amount];
    }
};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  long long int n,m; cin >> n >> m; // n total, m types of coins
  vector<int> v(m);
  input(v);// input coins
  print_(v);
  Solution s;
  cout << s.coinChange( v, n ) << '\n';






  return 0;
}
