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
typedef long long ll;

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
  int T, n;
  public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      int n = stations.size();
      vector<ll> dp(n+1, 0);
      dp[0] = startFuel;
      forall(i,0,n){
        int y = stations[i][0], gas = stations[i][1];
        for(int j = i+1; j > 0; --j ){
          if( y <= dp[j-1] ) dp[j] = max( dp[j], dp[j-1] + gas );
        }
      }
      int ans = 0;
      for(; ans < n+1; ++ans){
        if( dp[ans] >= target ) break;
      }
      if( ans == n+1 ) return -1;
      else return ans;
    }

    int minRefuelStops_pq(int target, int startFuel, vector<vector<int>>& stations) {
      int ans = 0;
      ll fuel = startFuel;
      ll x = 0;
      int t = 0, n = stations.size();
      priority_queue<int> pq;
      for(int i = 0; i < n; ++i ){
        int y = stations[i][0], gas = stations[i][1];
        debug("x =", x, "y = ", y, "fuel =", fuel);
        while( fuel < y-x and !pq.empty() ){
          fuel += pq.top();
          pq.pop();
          t ++;
        }
        debug("x =", x, "y = ", y, "fuel =", fuel);
        if( fuel < y-x ) return -1;
        pq.push(gas);
        fuel -= (y-x);
        x = y;
      }
      debug("fuel = ", fuel, "x =", x);
      while( fuel < target - x and !pq.empty() ){
        fuel += pq.top();
        pq.pop();
        t++;
      }
      if( fuel < target -x ) return -1;
      else return t;
    }
};
int main( int argc, char * argv[] ){
  int T,s,n; cin  >> n >> T >> s;
  vvi v(n); for(auto & p : v) { p.resize(2); input(p);}
  Solution sol;
  cout << sol.minRefuelStops(T, s, v) << '\n';

  return 0;
}
