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
//https://leetcode.com/problems/range-sum-query-immutable/
//nums = [-2, 0, 3, -5, 2, -1]
//sumRange(0, 2) -> 1
//sumRange(2, 5) -> -1
//sumRange(0, 5) -> -3

class NumArray {
  private:
    vector<int> cumsum; // cumsum[i] := cumulative sum up to i-th element inclusive
  public:
    NumArray(vector<int> &nums) {
      if( nums.empty() ) return;
      cumsum.resize( nums.size() );
      cumsum[0] = nums[0];
      for( int i = 1; i < nums.size(); ++i ){
        cumsum[i] = cumsum[i-1] + nums[i];
      }
    }

    int sumRange(int i, int j) {
      if( i > j ) swap(i,j);
      if( j >= cumsum.size() ) j = cumsum.size()-1;
      if( i < 0 ) i = 0;
      if( i == 0 ) return cumsum.at(j);
      else return cumsum.at(j) - cumsum.at(i-1);
    }
};


// Your NumArray object will be instantiated and called as such:
// // NumArray numArray(nums);
// // numArray.sumRange(0, 1);
// // numArray.sumRange(1, 2);
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);




  return 0;
}
