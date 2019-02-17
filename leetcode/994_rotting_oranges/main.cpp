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
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
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

// std::ios::sync_with_stdio(false);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  int n,m;
  bool C( int x, int y ){
    if( x >= 0 and x < n and y >= 0 and y < m ) return true;
    else return false;
  }
  public:
    int orangesRotting(vector<vector<int>>& grid) {
      n = grid.size(), m =grid[0].size();
      vvi d(n, vi(m, -1));
      queue<ii> Q;
      int cnt = 0;
      forall(i,0,n) forall(j,0,m)
        if (grid[i][j] == 2){ d[i][j] = 0; Q.push(mp(i,j));}
        else if( grid[i][j] == 1 ) cnt++;

      while( !Q.empty() ){
        auto p = Q.front(); Q.pop();
        int x = p.first, y = p.second;
        int dst = d[x][y];
        if( C( x+1, y)  and d[x+1][y] == -1 and grid[x+1][y] == 1 ){ d[x+1][y] = dst+1; grid[x+1][y]=2; Q.push(mp(x+1,y)); }
        if( C( x-1, y)  and d[x-1][y] == -1 and grid[x-1][y] == 1 ){ d[x-1][y] = dst+1; grid[x-1][y]=2; Q.push(mp(x-1,y)); }
        if( C( x, y+1)  and d[x][y+1] == -1 and grid[x][y+1] == 1 ){ d[x][y+1] = dst+1; grid[x][y+1]=2; Q.push(mp(x,y+1)); }
        if( C( x, y-1)  and d[x][y-1] == -1 and grid[x][y-1] == 1 ){ d[x][y-1] = dst+1; grid[x][y-1]=2; Q.push(mp(x,y-1)); }
      }
      int max_dist = 0;
      forall(i,0,n) forall(j,0,m){
        if( grid[i][j] == 1 ) return -1;
        max_dist = max( max_dist, d[i][j] );
      }
      return max_dist;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
