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
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
      int n = group.size();
      vector<vector<ll>> dp( G+1, vector<ll>(P+1,0));
      dp[0][0] = 1;
      forall(x, 0, n){
        for(int i = G; i >= 0; --i ){
          for( int j = P; j >= 0; --j ){
            if( dp[i][j] != 0 and i + group[x] <= G ){
              int ii = i+group[x], jj = min(j+profit[x], P);
              dp[ii][jj] += dp[i][j];
              dp[ii][jj] %= INF;
            }
          }
        }
      }
      ll ans = 0;
      forall(i,0,G+1){
        ans += dp[i][P];
        ans %= INF;
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,G,P; cin >> n >> G >> P;
  vi g(n), p(n);
  input(g);
  input(p);
  Solution sol;
  cout << sol.profitableSchemes(G, P, g, p) << '\n';

  return 0;
}
