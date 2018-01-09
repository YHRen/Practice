#include <vector>
#include <unordered_map>
#include <set>
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
// https://leetcode.com/problems/can-i-win/
// For example, two player-s might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.
//
// Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both player-s play optimally.
//
// You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300. 
//
// Input:
// maxChoosableInteger = 10
// desiredTotal = 11
//
// Output:
// false
//
// Explanation:
// No matter which integer the first player choose, the first player will lose.
// The first player can choose an integer from 1 up to 10.
// If the first player choose 1, the second player can only choose integers from 2 up to 10.
// The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
// Same with other integers chosen by the first player, the second player will always win.
class Solution {
  private:
    vector<unordered_map<uint32_t, bool>> mem;
    inline uint32_t msb32( uint32_t x ){
      x |= ( x >> 1 );
      x |= ( x >> 2 );
      x |= ( x >> 4 );
      x |= ( x >> 8 );
      x |= ( x >> 16 );
      return ( x & ~( x>>1 ) );
    }
    inline uint32_t log2_32(uint32_t x){
      int y = (x & (x - 1));
      y |= -y;
      y >>= 31;
      x |= (x >> 1);
      x |= (x >> 2);
      x |= (x >> 4);
      x |= (x >> 8);
      x |= (x >> 16);
      return(__builtin_popcount(x >> 1) - y);
    }
    bool can_win( bool player, int n, uint32_t action, int k, 
        vector<unordered_map<uint32_t, bool>> & mem){
      // first player is true
      // no more action
      if( ! action ) return !player;
      // n can be consumed by one move
      if( n <= 1+log2( msb32( action ) ) ) return player; 
      if( mem[n].find( action ) != mem[n].end() ) return mem[n][action];

      // for each available move
      for( int i = 0; i < k; ++i ){
        if( action & (1u<<i ) ){
          bool rst = can_win( !player, n-i-1, (action & ~(1u<<i)), k, mem );
          if( rst == player ){
            mem[n][action] = player;
            return player;
          }
        }
      }
      mem[n][action] = !player;
      return !player;
    }
  
  public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
      const int & n = desiredTotal;
      const int & k = maxChoosableInteger;
      if( n <= k ) return true;
      if( k*(k+1)/2 < n ) return false;
      this->mem.resize(n+1);
      return can_win( true, n, (1u<<k)-1, k, mem);
    }
};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n,k; cin >> n >> k;
  Solution s;
  cout << s.canIWin(k,n) << '\n';

  return 0;
}
