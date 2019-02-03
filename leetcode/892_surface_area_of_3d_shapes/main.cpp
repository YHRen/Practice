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
  public:
    int surfaceArea(vector<vector<int>>& grid) {
      int n = grid.size();
      int ans = 0;
      forall(i,0,n) forall(j,0,n) if( grid[i][j] ) ans+=2;
      debug(ans);
      forall(i,0,n){
        ans += grid[0][i];
        ans += grid[i][0];
        ans += grid[i][n-1];
        ans += grid[n-1][i];
      }
      debug(ans);
      forall(i,0,n){
        forall(j,0,n){
          if( i != n-1 ){
            ans += abs(grid[i][j] - grid[i+1][j]);
          }
          if( j != n-1 ){
            ans += abs(grid[i][j] - grid[i][j+1]);
          }
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vvi v(n, vi(n)); for(auto & x : v) input(x);
  Solution sol;
  cout << sol.surfaceArea(v) << '\n';

  return 0;
}
