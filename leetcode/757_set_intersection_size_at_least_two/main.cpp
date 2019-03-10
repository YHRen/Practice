#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
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

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<(b);++i)
#define trav(a,x)                   for(auto & a: x)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define sz(c)                       (int)(c).size()
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

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

auto ____ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
      int n = sz(intervals);
      sort(all(intervals), [](vi & lhs, vi & rhs){
          if( lhs[0] < rhs[0] ) return true;
          if( lhs[0] == rhs[0] and lhs[1] > rhs[1] ) return true;
          return false;
          });
      deque<int> S;
      for(int i = n-1; i >= 0; --i ){
        int x = intervals[i][0], y = intervals[i][1];
        int elm = upper_bound(all(S),y) - lower_bound(all(S),x);
        if( elm > 1 ) continue;
        if( elm == 1 ){
          S.push_front(x);
        }else{
          S.push_front(x+1);
          S.push_front(x);
        }
      }
      return S.size();
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vvi mtx(n, vi(2));
  for(auto & v : mtx ) input(v);
  Solution sol;
  cout << sol.intersectionSizeTwo(mtx) << '\n';

  return 0;
}

/* problem statement
757. Set Intersection Size At Least Two
Hard

An integer interval [a, b] (for integers a < b) is a set of all consecutive integers from a to b, including a and b.

Find the minimum size of a set S such that for every integer interval A in intervals, the intersection of S with A has size at least 2.

Example 1:

Input: intervals = [[1, 3], [1, 4], [2, 5], [3, 5]]
Output: 3
Explanation:
Consider the set S = {2, 3, 4}.  For each interval, there are at least 2 elements from S in the interval.
Also, there isn't a smaller size set that fulfills the above condition.
Thus, we output the size of this set, which is 3.

Example 2:

Input: intervals = [[1, 2], [2, 3], [2, 4], [4, 5]]
Output: 5
Explanation:
An example of a minimum sized set is {1, 2, 3, 4, 5}.

Note:

    intervals will have length in range [1, 3000].
    intervals[i] will have length 2, representing some integer interval.
    intervals[i][j] will be an integer in [0, 10^8].
*/
