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
typedef pair<int,ii> iii;
typedef vector<vi>  vvi;
typedef vector<ii>  vii;
typedef vector<iii> viii;

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
  public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
      int N = schedule.size(); // num. of employees
      debug("N =",N);
      priority_queue< iii, viii, greater<iii> > Q;
      forall(i,0,N){
        if( !schedule[i].empty() ){
          Q.push( mp( schedule[i][0].start, mp( i, 0 ) ) );
        }
      }
      debug("Qsize",Q.size());
      vector<Interval> ans;
      int current_end = -1;
      while( !Q.empty() ){
        auto p = Q.top(); Q.pop();
        int s = p.first, idx = p.second.first, jth = p.second.second;
        debug("s = ", s, "idx", idx, "jth =", jth, "current_end", current_end);
        if( current_end == -1 ){
          current_end = schedule[idx][jth].end;
        }else{
          if( s  > current_end){
            ans.pb( Interval(current_end, s) );
            current_end = schedule[idx][jth].end;
          }else{
            current_end = max( current_end, schedule[idx][jth].end );
          }
        }
        if( ++jth < schedule[idx].size() ){
          Q.push( mp( schedule[idx][jth].start, mp( idx, jth) ) );
        }
      }
      return ans;

    }
};
int main( int argc, char * argv[] ){
  vector<vector<Interval>> mtx(3);
  mtx[0].pb(Interval(1,2));
  mtx[0].pb(Interval(5,6));
  mtx[1].pb(Interval(1,3));
  mtx[2].pb(Interval(4,10));
  Solution sol;
  auto ans = sol.employeeFreeTime(mtx);
  for( auto & x : ans ){
    cout << x.start << ' ' << x.end << '\n';
  }cout << '\n';


  return 0;
}
