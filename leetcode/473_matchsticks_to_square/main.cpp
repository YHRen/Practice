#include <vector>
#include <set>
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
//473. Matchsticks to Square 
//https://leetcode.com/problems/matchsticks-to-square/
//Remember the story of Little Match Girl? By now, you know exactly what
//matchsticks the little match girl has, please find out a way you can make one
//square by using up all those matchsticks. You should not break any stick, but
//you can link them up, and each matchstick must be used exactly one time.
//
//Your input will be several matchsticks the girl has, represented with their
//stick length. Your output will either be true or false, to represent whether
//you could make one square using all the matchsticks the little match girl
//has.
//
//Example 1:
//
//Input: [1,1,2,2,2]
//Output: true
//
//Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
//
//Example 2:
//
//Input: [3,3,3,3,4]
//Output: false
//
//Explanation: You cannot find a way to form a square with all the matchsticks.
//
class Solution {
  private:
    bool can_square(
        int a, int b, int c, int d,
        int k, const int l, const vector<int> & v ){
      debug(a,b,c,d,l);
      if( a == l && b == l && c == l ) return true;
      if( a > l || b > l || c > l ){
        return false;
      }
      if(  d > c ) return false;
      if( k == v.size() ) return false;
      int x = v[k];
      if( can_square( a+x, b, c, d, k+1, l, v ) || 
          can_square( a, b+x, c, d, k+1, l, v ) ||
          can_square( a, b, c+x, d, k+1, l, v ) ||
          can_square( a, b, c, d+x, k+1, l, v ) ){
        return true;
      }else{
        return false;
      }
    }

  public:
    bool makesquare(vector<int>& nums) {
      if( nums.empty() )    return false;
      if( nums.size() < 4 ) return false;
      int tot = 0;
      for( int x : nums ){
        tot += x;
      }
      debug( tot );
      if( tot % 4 ) return false;
      int a = 0, b = 0, c = 0, d = 0;
      int len = tot/4;
      return can_square( a, b, c, d, 0, len, nums);
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> v(n);
  input(v);
  Solution s;
  cout << s.makesquare( v ) << '\n';




  return 0;
}
