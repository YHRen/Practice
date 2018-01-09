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
// https://leetcode.com/problems/wiggle-sort-ii/
//  Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//
//  Example:
//  (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
//  (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
//
//  Note:
//  You may assume all input has valid answer.
//
//  Follow Up:
//  Can you do it in O(n) time and/or in-place with O(1) extra space? 
//

class Solution {
  public:
void wiggleSort(vector<int>& nums) {
      if( nums.empty() || nums.size() == 1 ) return;
      for( int i = 0; i < nums.size()-1; ++i ){
        if( i%2 == 0 ){
          if( nums[i] > nums[i+1] ){
            swap( nums[i], nums[i+1] );
          }else if( nums[i] == nums[i+1] ){
            bool is_resolved = false;
            if( !is_resolved ){
              for( int j = i+2; j < nums.size(); ++j ){
                if( nums[i+1] < nums[j] ){
                  swap( nums[i+1], nums[j] );
                  is_resolved = true;
                  break;
                }
              }
            }
            if( !is_resolved ){
              for( int j = 1; j < i; j+=2 ){
                if( nums[i+1] < nums[j] && nums[i+1] > nums[j-1] && nums[i+1] > nums[j+1] ){
                  swap(nums[i+1],nums[j]);
                  is_resolved = true;
                  break;
                }
              }
            }
          }
        }else{
          if( nums[i] < nums[i+1] ){
            swap( nums[i], nums[i+1] );
          }else if( nums[i] == nums[i+1] ){
            bool is_resolved = false;
           for( int j = i+2; j < nums.size(); ++j ){
              if( nums[i+1] > nums[j] ){
                swap( nums[i+1], nums[j] );
                is_resolved = true;
                break;
              }
            }
           if( !is_resolved ){
              for( int j = 0; j < i; j+=2 ){
                if( nums[i+1] > nums[j] && nums[i+1] < nums[j+1] && 
                    ( j==0 || nums[i+1] < nums[j-1] ) ){
                  swap( nums[i+1], nums[j] );
                }
              }
            }
          }
        }
      }
    }
};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> v(n);
  input(v);
  Solution s;
  s.wiggleSort(v);
  for( auto x : v ){
    cout << x << ' ';
  }cout << '\n';

  return 0;
}
