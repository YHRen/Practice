#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
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

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<(b);++i)
#define trav(a,x)                   for(auto & a: x)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define sz(c)                       (int)(c).size()
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

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

auto ____ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  int n;
  bool C( int x, int y ){ return x >=0 and y >= 0 and x < n and y < n; }
  public:
    int swimInWater(vector<vector<int>>& grid) {
      vi dx = {1,0,-1,0}, dy = {0,1,0,-1};
      n = grid.size();
      int x,y;
      vvi dist(n, vi(n, INF));
      dist[0][0] = grid[0][0];
      forall(i,0,n) forall(j,0,n){ // for each node
        if( dist[i][j] == INF ) continue;
        forall(ii,0,n) forall(jj,0,n){ // for each edge
          forall(d,0,4){
            x = ii+dx[d], y = jj+dy[d];
            if( C(x,y) and dist[x][y] > dist[ii][jj] )
              dist[x][y] = max( dist[ii][jj], grid[x][y] );
          }
        }
      }
      return dist[n-1][n-1];
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
