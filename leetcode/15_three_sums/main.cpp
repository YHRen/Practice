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
// https://leetcode.com/problems/3sum/
// find a+b+c = 0 for a,b,c \in vector
// solve: a+b = -c, sort array, for each a + b, b-search -c.
// if (a,b) unique a<b, (a,b,c) is unique.
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> rst;
      if( nums.empty() || nums.size() < 3 ) return rst;
      sort( nums.begin(), nums.end() );
      int jpre = nums.size()-1;
      for( int i = 0; i < nums.size(); ++i ){
        if( i !=0 && nums[i] == nums[i-1] ) continue; // duplicate
        if( -(nums[i]+nums.back()) > nums.back() ) continue;// target always smaller than nums[i]
        for( int j = jpre; j > i+1; --j ){
          if( j != nums.size()-1 && nums[j] == nums[j+1] ) continue; // duplicate
          int c = - ( nums[i]+nums[j] );  // c is increasing
          if( c >= nums[i] && c <= nums[j] ){
            if( !found ){
              jpre = j;
              found = true;
            }
            auto itr = lower_bound( nums.begin()+i+1, nums.begin()+j, c );
            int idx = itr-nums.begin();
            if( idx > i && idx < j && *itr == c ){
              rst.push_back( {nums[i], c, nums[j]} );
            }
          }else if( c > nums[j] ){
            found = false;
            break;
          }
        }
      }
      return rst;
    }
};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);




  return 0;
}
