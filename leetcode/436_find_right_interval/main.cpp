#include <vector>
#include <set>
#include <map>
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
// 436. Find Right Interval 
// https://leetcode.com/problems/find-right-interval/
// Given a set of intervals, for each of the interval i, check if there exists
// an interval j whose start point is bigger than or equal to the end point of
// the interval i, which can be called that j is on the "right" of i.
//
// For any interval i, you need to store the minimum interval j's index, which
// means that the interval j has the minimum start point to build the "right"
// relationship for interval i. If the interval j doesn't exist, store -1 for
// the interval i. Finally, you need output the stored value of each interval
// as an array.
//
// Note:
//
// You may assume the interval's end point is always bigger than its start
// point.  You may assume none of these intervals have the same start
// point.
//
// Example 1:
//
// Input: [ [1,2] ]
//
// Output: [-1]
//
// Explanation: There is only one interval in the collection, so it
// outputs -1.
//
// Example 2:
//
// Input: [ [3,4], [2,3], [1,2] ]
//
// Output: [-1, 0, 1]
//
// Explanation: There is no satisfied "right" interval for [3,4].  For
// [2,3], the interval [3,4] has minimum-"right" start point; For
// [1,2], the interval [2,3] has minimum-"right" start point.
//
// Example 3:
//
// Input: [ [1,4], [2,3], [3,4] ]
//
// Output: [-1, 2, -1]
//
// Explanation: There is no satisfied "right" interval for [1,4] and
// [3,4].  For [2,3], the interval [3,4] has minimum-"right" start
// point.
//
/**
 * Definition for an interval.
 */
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
  private:
    struct cmp{
      bool operator()( const pair<Interval*,int> & lhs, 
        const pair<Interval*,int> & rhs ){
        return lhs.first->start < rhs.first->start;
      }
    };
  public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
      vector<int> rst;
      set<pair<Interval*,int>, cmp > bag;
      for( int i = 0; i < intervals.size(); ++i ){
        bag.insert( make_pair( &intervals[i], i ) );
      }
      for( int i = 0; i < intervals.size(); ++i ){
        auto tmp = Interval(intervals[i].end, 0 );
        const auto target = make_pair(&tmp,0) ;
        auto itr = bag.lower_bound(target);
        debug("found: ",itr->second,"(,",itr->first->start,",",itr->first->end,")");
        if( itr == bag.end() ){
          rst.push_back(-1);
        }else{
          rst.push_back(itr->second);
        }
      }
      return rst;
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<Interval> v;
  for( int i = 0; i < n; ++i ){
    int x,y;
    cin >> x >> y;
    v.emplace_back( Interval(x,y) );
  }
  Solution s;
  auto rst = s.findRightInterval( v );
  print_(rst);
   




  return 0;
}
