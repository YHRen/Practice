#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>
#include <cassert>

#define input(v)                  for(int i = 0; i < v.size(); ++i){ cin >> v[i]; }

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
// 435. Non-overlapping Intervals 
// https://leetcode.com/problems/non-overlapping-intervals/?tab=Description
// Given a collection of intervals, find the minimum number of intervals you
// need to remove to make the rest of the intervals non-overlapping.
//
// Note:
// You may assume the interval's end point is always bigger than its start
// point.
// Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap
// each other.
//
//Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
  private:
    struct comparator{
      bool operator()( const Interval & lhs, const Interval & rhs){
        return lhs.end < rhs.end;
      }
    };
  public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
      if( intervals.empty() || intervals.size() == 1 ) return 0;
      sort( intervals.begin(), intervals.end(), comparator() );
      int cnt = 1;
      int n   = intervals.size();
      debug( intervals[0].start, intervals[0].end );
      int prv = intervals[0].end;
      for( int i = 1; i < n; ++i ){
        debug( intervals[i].start, intervals[i].end );
        if( intervals[i].start >= prv ){
          ++cnt;
          prv = intervals[i].end;
        }
      }
      return n-cnt;
    }
};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<Interval> v;
  v.reserve(n);
  while(n-->0){
    int x,y;
    cin >> x >> y;
    v.pb( Interval(x,y) );
  }
  Solution s;
  cout << s.eraseOverlapIntervals(v) << '\n';




  return 0;
}
