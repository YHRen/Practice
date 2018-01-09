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
// https://leetcode.com/problems/maximum-product-subarray/
//
//  Find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
//  For example, given the array [2,3,-2,4],
//  the contiguous subarray [2,3] has the largest product = 6. 
//
class Solution {

  public:
    int maxProduct(vector<int>& nums) {
      if( nums.empty() ) return 0;
      int max_sofar = nums[0];
      int min_sofar = nums[0];
      int pre_max   = nums[0];
      int pre_min   = nums[0];
      int max_tmp, min_tmp;
      for( int i = 1; i < nums.size(); ++i ){
        max_tmp = max( max( pre_max * nums[i], pre_min * nums[i] ), nums[i] );
        min_tmp = min( min( pre_max * nums[i], pre_min * nums[i] ), nums[i] );
        max_sofar = max( max_tmp, max_sofar );
        min_sofar = min( min_tmp, min_sofar );
        pre_max = max_tmp;
        pre_min = min_tmp;
      }
      return max_sofar;
    }
};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> v(n);
  input(v);
  Solution s;
  cout << s.maxProduct(v) << '\n';

  return 0;
}
