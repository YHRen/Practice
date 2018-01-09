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
    int maxProfit(vector<int>& v) {
      int buy1 = -INF, buy2 = -INF, profit1 = 0, profit2 = 0;
      for(auto x : v ){
        profit2 = max( profit2, buy2+x );
        buy2    = max( buy2, profit1 - x);
        profit1 = max( profit1, buy1+x );
        buy1    = max( buy1, -x );
      }
      return profit2;
    }

    int maxProfit_slow(vector<int>& v) {
      int N = v.size();
      int K = 2;
      if( N < 2 ) return 0;
      vvi dp(K+1, vi(N, 0));
      forall( k, 1, K+1 ){
        forall( i, 1, N ){
          int tmp = 0;
          forall( j, 0, i ){
            tmp = max( tmp, v[i] - v[j] + dp[k-1][j]);
          }
          dp[k][i] = max( dp[k][i-1], tmp );
        }
      }
      for(auto & _ : dp ){
        print_(_);
      }
      return dp[K].back();
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n); input(v);
  Solution sol;
  cout << sol.maxProfit(v) << '\n';

  return 0;
}
