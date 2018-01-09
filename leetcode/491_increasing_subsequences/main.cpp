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
// 491. Increasing Subsequences
// https://leetcode.com/problems/increasing-subsequences/
//
// Given an integer array, your task is to find all the different possible
// increasing subsequences of the given array, and the length of an increasing
// subsequence should be at least 2 .
//
// Example:
//
// Input: [4, 6, 7, 7]
// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
//
// Note:
//
//  The length of the given array will not exceed 15.
//  The range of integer in the given array is [-100,100].
//  The given array may contain duplicates, and two equal integers should also
//  ...be considered as a special case of increasing sequence.
//

class Solution {
  private:
    void dfs( int idx, 
        vector<int> & cur,
        set<vector<int>> & rst,
        const vector<int> & v,
        const vector<vector<int8_t>> & g ){
      cur.push_back( v[idx] );
      set<int> is_visited;
      for( auto nxt : g[idx] ){
        if( is_visited.find(v[nxt]) == is_visited.end() ){
          is_visited.insert( v[nxt] );
          dfs( nxt, cur, rst, v, g );
        }
      }
      if( cur.size() > 1 ){
        rst.insert( cur );
      }
      cur.pop_back();
    }
  public:
    vector<vector<int>> findSubsequences(vector<int>& v) {
      vector<vector<int8_t>> g( v.size() ); // v.size() <= 15
      for( int i = 0; i < v.size(); ++i ){
        for( int j = i+1; j < v.size(); ++j ){
          if( v[j] >= v[i] ){
            g[i].push_back( j );
          }
        }
      }
      set<vector<int>> rst;
      for( int i = 0; i < g.size(); ++i ){
        if( i == 0 || v[i] != v[i-1] ){
          vector<int> cur;
          dfs( i, cur, rst, v, g );
        }
      }
      return vector<vector<int>>(rst.begin(), rst.end());
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> v(n);
  input(v);
  Solution s;
  auto rst = s.findSubsequences( v );
  for( auto & u : rst ){
    print_(u);
  }

  return 0;
}
