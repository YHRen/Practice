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
class Solution {
  public:
    int maxProfit(vector<int>& v, int fee) {
      int n = v.size() ;
      if( n < 2 ) return 0;
      vvi dp(2, vi(n+1, 0 )); // hold, sold
      dp[0][0] = -INF;
      forall(i,1,n+1){
        dp[0][i] = max( dp[0][i-1], dp[1][i-1] - v[i-1] - fee );
        dp[1][i] = max( dp[1][i-1], dp[0][i-1] + v[i-1]);
      }
      return dp[1].back();
    }
};

int main( int argc, char * argv[] ){
  int n, fee; cin >> n >> fee;
  vi v(n); input(v);
  Solution sol;
  cout << sol.maxProfit( v, fee) << '\n';

  return 0;
}
