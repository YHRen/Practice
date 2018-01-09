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
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Find the kth largest element in an unsorted array. Note that it is the kth
// largest element in the sorted order, not the kth distinct element.
//
// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.
//
// Note:
// You may assume k is always valid, 1 ≤ k ≤ array's length.

class Solution {
  private:
    int quick_select( vector<int> & v, int l, int r, int k ){
      if( l == r ) return v[l];
      int tmp = v[r];
      int i = l;
      for( int j = l; j < r; ++j ){
        if( v[j] >= tmp ){ // descending order
          swap( v[i++], v[j] );
        }
      }
      swap( v[i], v[r] );
      if( k == i ) return v[i];
      if( k < i ){
        return quick_select( v, l, i-1, k );
      }else{
        return quick_select( v, i+1, r, k );
      }
    }
      
  public:
    int findKthLargest(vector<int>& nums, int k) {
      // the c++ introselect: 
      // nth_element( nums.begin(), nums.begin()+k-1, nums.end(), std::greater<int>() );
      // return nums[k-1];
      return quick_select( nums, 0, nums.size()-1, k-1 );
    }
};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n,k; cin >> n >> k;
  vector<int> v(n);
  input(v);
  Solution s;
  debug( n,k );
  cout << s.findKthLargest( v, k ) << '\n';




  return 0;
}
