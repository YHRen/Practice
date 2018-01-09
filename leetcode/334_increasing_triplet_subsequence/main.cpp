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
// 334. Increasing Triplet Subsequence 
// https://leetcode.com/problems/increasing-triplet-subsequence/
// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//
// Formally the function should:
//
//     Return true if there exists i, j, k
//         such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false. 
//
//         Your algorithm should run in O(n) time complexity and O(1) space complexity.
//
//         Examples:
//         Given [1, 2, 3, 4, 5],
//         return true.
//
//         Given [5, 4, 3, 2, 1],
//         return false. 

class Solution {
  public:
    bool increasingTriplet(vector<int>& v) {
      if( v.size() <= 2 ) return false;
      int frst = numeric_limits<int>::max();
      int medm = numeric_limits<int>::max();
      for( auto x : v ){
        debug("x=",x);
        if( x <= frst ){
          frst = x;
          debug("update first",x);
          continue;
        }
        if( x <= medm ){
          medm = x;
          debug("update medium",x);
          continue;
        }
        if( x > medm ){
          return true;
        }
      }
      return false;
    }
};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> v(n);
  input(v);
  Solution s;
  cout << s.increasingTriplet(v) << endl;
  
  return 0;
}
