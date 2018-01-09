#include <vector>
#include <array>
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
class Solution_1 {
  public:
    int minSteps(int n) {
      int m = (n+1)/2;
      vvi dp(n+1, vi( m, INF) );
      dp[1][0] = 0;
      forall(i,1,n){
        if( i < m ) dp[i][i] = *min_element( all(dp[i]) ) + 1;
        for( int j = 1; j < m; ++j ){
          if( dp[i][j] != INF && i+j < n+1  ){
            dp[i+j][j] = min( dp[i+j][j], dp[i][j] + 1 );
          }
        }
      }
      for(auto v : dp ){
        print_(v);
      }
      return *min_element(all(dp[n]));
    }
};

class Solution {
  public:
    int minSteps(int n) {
      if( n == 1 ) return 0;
      queue<array<int,3>> Q;
      int ans = INF;
      Q.push( {1,1,1} );
      while( !Q.empty() ){
        auto x = Q.front(); Q.pop();
        debug(x[0],x[1],x[2]);
        if( x[0] == n ){
          ans = min( ans, x[2] );
        }else if( x[0] < n ){
          // copy
          if( x[0] != x[1] ){
            Q.push( {x[0], x[0], x[2]+1} );
          }
          // paste
          if( x[0] + x[1] <= n ){
            Q.push( {x[0]+x[1], x[1], x[2]+1} );
          }
        }
      }
      return ans;
    }
};

int main( int argc, char * argv[] ){
  int n; cin >> n;
  Solution sol;
  cout << sol.minSteps(n) << '\n';

  return 0;
}
