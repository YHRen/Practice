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
// https://leetcode.com/problems/subsets/
// Given a set of distinct integers, nums, return all possible subsets.
//
// Note: The solution set must not contain duplicate subsets.
//
// For example,
// If nums = [1,2,3], a solution is:
//
// [ [3], [1], [2], [1,2,3], [1,3], [2,3], [1,2], [] ]
//

class Solution {
  private:
    void subsets_aux(
        int idx, 
        vector<int> & tmp,
        vector<vector<int>> & rst,
        const vector<int> & nums ){
      if( idx == nums.size() ){
        rst.push_back(tmp);
        return;
      }
      // do not inlucde this one
      subsets_aux( idx+1, tmp, rst, nums );
      tmp.push_back( nums[idx] );
      subsets_aux( idx+1, tmp, rst, nums );
      tmp.pop_back();
    }

  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> rst;
      if( nums.empty() ) return rst;
      vector<int> tmp;
      subsets_aux( 0, tmp, rst, nums );
      return rst;
    }
};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> v(n);
  input(v);
  Solution s;
  auto rst = s.subsets( v );
  for( auto & u : rst ){
    print_(u);
  }




  return 0;
}
