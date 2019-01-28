#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
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
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  vi cost;
  vi dp;
  vi v;
  int n;
  int rec( int idx ){
    if( idx == n ) return 0;
    if( dp[idx] != -1 ) return dp[idx];
    int c1 = cost[0] + rec( idx+1);
    int next_7_days = lower_bound(v.begin()+idx, v.end(), v[idx]+7) - v.begin();
    int c2 = cost[1] + rec( next_7_days );
    int next_30_days = lower_bound( v.begin()+idx, v.end(), v[idx]+30) - v.begin();
    int c3 = cost[2] + rec(next_30_days);
    dp[idx] = min(c1, min(c2,c3));
    return dp[idx];
  }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
      v = days;
      n  = days.size();
      dp.resize(n+1,-1);
      cost = costs;
      return rec(0);
    }
};
int main( int argc, char * argv[] ){
  int n; cin >>n ;
  vi v(n); input(v);
  vi u(3); input(u);
  Solution sol;
  cout << sol.mincostTickets(v, u) << '\n';

  return 0;
}
