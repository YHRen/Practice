// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <numeric>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF                         (int)1000000007
#define EPS                         1e-9

#define bg     begin()
#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi>  vvi;
typedef vector<ii>  vii;

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

// std::ios::sync_with_stdio(false);
/******* Actual Code Starts Here *********/
/*
 *  Given an array of numbers nums, in which exactly two elements appear only
 *  once and all the other elements appear exactly twice. Find the two elements
 *  that appear only once.
 *  For example:
 *  Given nums = [1, 2, 1, 3, 2, 5], return [3, 5]
 */
class Solution {
  public:
    vector<int> singleNumber(vector<int>& nums) {
      int n = nums.size();
      if( n < 2 ) return vi{};
      if( n == 2 ) return nums;
      int mask = 0;
      forall(i,0,n){ mask ^= nums[i]; }
      mask &= -mask;
      int res1 = 0, res2 = 0;
      for(auto & x : nums ){
        if( (x & mask) == 0 ){ 
          res1 ^= x;
        }else{
          res2 ^= x;
        }
      }
      return vi{res1, res2};
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n); input(v);
  Solution sol;
  auto ans = sol.singleNumber( v );
  print_(ans);

  return 0;
}
