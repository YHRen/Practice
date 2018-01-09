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
// 330. Patching Array 
// https://leetcode.com/problems/patching-array/
// Given a sorted positive integer array nums and an integer n, add/patch
// elements to the array such that any number in range [1, n] inclusive can be
// formed by the sum of some elements in the array. Return the minimum number
// of patches required.
//
// Example 1:
// nums = [1, 3], n = 6
// Return 1.
//
// Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
// Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
// Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
// So we only need 1 patch.
//
// Example 2:
// nums = [1, 5, 10], n = 20
// Return 2.
// The two patches can be [2, 4].
//
// Example 3:
// nums = [1, 2, 2], n = 5
// Return 0.
//

class Solution {
  public:
    int minPatches(vector<int>& nums, int n) {
      // check
      int64_t head = 1;
      int64_t sz   = static_cast<int64_t>(n);
      int idx  = 0;
      int rst  = 0;
      while( head < sz ){
        if( idx >= nums.size() ){
          rst ++;
          debug("inserting", head);
          head += head;
        }else{
          int x = nums[idx];
          if( x > head ){
            rst ++;
            debug("inserting", head);
            head += head;
          }else{
            head += x;
            idx ++;
          }
        }
      }
      return rst;
    }

};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n,m; cin >> n >> m;
  vector<int> v(n);
  input( v );
  Solution s;
  cout << s.minPatches( v, m );

  return 0;
}
