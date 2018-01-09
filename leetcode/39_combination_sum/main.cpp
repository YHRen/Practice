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
// https://leetcode.com/problems/combination-sum/
//  Given a set of candidate numbers (C) (without duplicates) and a target
//  number (T), find all unique combinations in C where the candidate numbers
//  sums to T.
//
//  The same repeated number may be chosen from C unlimited number of times.
//
//  Note:
//
//  All numbers (including target) will be positive integers.
//  The solution set must not contain duplicate combinations.
//
//  For example, given candidate set [2, 3, 6, 7] and target 7,
//  A solution set is:
//  [ [7], [2, 2, 3] ]
//

class Solution {
  private:
    void find_combo( vector<vector<int>> & rst,
        vector<int> & tmp,
        int n, int k, 
        const vector<int> & v){
      if( k >= v.size() || n < 0 ){ return; }
      int p = n / v[k];
      int q = n % v[k];
      vector<int> nxt = tmp;
      int t = p;
      while( t-- ){
        nxt.push_back(v[k]);
      }
      if( q == 0 ){
        rst.push_back( nxt );
      }

      for( t = 0; t < p; ++t ){
        nxt.pop_back();
        auto cur = nxt;
        find_combo( rst, cur, n-(p-t-1)*v[k], k+1, v );
      }

    }
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> rst;
      if( candidates.empty() || target < 1 ) return rst;
      sort( candidates.begin(), candidates.end() );
      vector<int> tmp ;
      find_combo( rst, tmp, target, 0,  candidates );
      return rst;
    }

};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n,t; cin >> n >> t;
  vector<int> v(n);
  input( v );
  Solution s;
  auto rst = s.combinationSum( v, t );
  for( auto & u : rst ){
    print_(u);
  }




  return 0;
}
