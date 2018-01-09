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
// 46. Permutations
// https://leetcode.com/problems/permutations/
// Given a collection of distinct numbers, return all possible permutations.
//
// For example,
// [1,2,3] have the following permutations:
//
// [ [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ]
//
class Solution {
  private:
    bool gen_next_permutation( 
        vector<int> & v, 
        vector<vector<int>> & rst ){
      int i = v.size() - 1;
      int n = v.size();
      while( i > 0 && v[i-1] > v[i] ){ --i; }
      if( i == 0 ) return false;
      auto itr = lower_bound( v.rbegin(), v.rbegin() + (n-i+1), v[i-1] );
      swap( *itr, v[i-1] );
      reverse( v.begin() + i, v.end() );
      rst.push_back( v );
      return true;
    }



  public:
    vector<vector<int>> permute(vector<int>& v) {
      vector<vector<int>> rst;
      if( v.empty() ) return rst;
      if( v.size() == 1 ){ rst.push_back( v ); return rst; }
      sort(v.begin(),v.end());
      rst.push_back(v);
      while( gen_next_permutation( v, rst ) ){}
      return rst;
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> v(n);
  input(v);
  Solution s;
  auto rst = s.permute( v );
  for( const auto & u : rst ){
    print_(u);
  }

  return 0;
}
