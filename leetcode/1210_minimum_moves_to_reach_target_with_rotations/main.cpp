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
#include <complex>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF              (int)1000000007
#define EPS              1e-9
#define pb               push_back
#define mp               make_pair
#define all(c)           c.begin(), c.end()
#define forall(i,a,b)    for(int i=a;i<(b);++i)
#define trav(a,x)        for(auto & a: x)
#define in(a,b)          ((b).find(a) != (b).end())
#define sz(c)            (int)(c).size()
#define input(a)         for(auto & x : a) cin >> x;

using namespace std;

typedef vector<int>      vi;
typedef pair<int,int>    ii;
typedef vector<vi>       vvi;
typedef vector<vvi>      vvvi;
typedef vector<ii>       vii;
typedef long long        ll;

#ifdef DEBUG
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();

class Solution {
  vvvi dp; // row, col, dir
  int n,m;
  // D = 0 , go right, D = 1, go down, D = 2, rotate clockwise, D = 3, rotate counter-clock
  bool try_move_to( int r, int c, int hori, int d, const vvi & grid ){
    if( hori == 1 ){ 
      switch( d ){
        case 0:
          if( c + 2 >= m or grid[r][c+2] == 1 ) return false;
          break;
        case 1:
          if( r + 1 >= n or grid[r+1][c] == 1 or grid[r+1][c+1] == 1 ) return false;
          break;
        case 2:// clockwise rotate
          if( r + 1 >= n or grid[r+1][c] == 1 or grid[r+1][c+1] == 1 ) return false;
          break;
        default :
          return false;
      }
    }else{ //vertical
      switch( d ){
        case 0:
          if( c + 1 >= m or grid[r][c+1] == 1 or grid[r+1][c+1] ) return false;
          break;
        case 1:
          if( r + 2 >= n or grid[r+2][c] == 1 ) return false;
          break;
        case 2: // counter clock wise
          if( c + 1 >= m  or grid[r][c+1] == 1 or grid[r+1][c+1] == 1 ) return false;
          break;
        default :
          return false;
      }
    }
    return true;
  }
  struct P{
    int x,y,pos;
    P (){}
    P (int x, int y, int pos) : x(x), y(y), pos(pos){}
  };
          
  public:
    int minimumMoves(vector<vector<int>>& grid) {
      n = sz(grid), m = sz(grid[0]);
      P ini_pos(0,0,1);
      vvvi dp(n, vvi(m, vi(2, -1) ) );
      dp[0][0][1] = 0;
      queue<P> Q;
      Q.push(ini_pos);
      if( grid[n-1][m-1] == 1 ) return -1;
      while(!Q.empty()){
        auto [x,y,p] = Q.front(); Q.pop();
        debug("at <",x,y, (p ? "hori" : "vert"), "> with dist=", dp[x][y][p] );
        if( x == n-1 and y == m-2 and p == 1 ) return dp[x][y][p];
        if( try_move_to(x,y,p,0, grid) and dp[x][y+1][p] == -1 ){ // move to right
          debug("\ttry to move right to ", x, y+1, p);
          dp[x][y+1][p] = dp[x][y][p] + 1;
          Q.push(P(x,y+1,p));
        }
        if( try_move_to(x,y,p,1, grid) and dp[x+1][y][p] == -1 ){ // move down
          debug("\ttry to move down to ", x+1, y, p);
          dp[x+1][y][p] = dp[x][y][p] + 1;
          Q.push(P(x+1,y,p));
        }
        if( try_move_to(x,y,p,2, grid) and dp[x][y][!p] == -1 ){
          debug("\ttry to rotate to ", x, y, !p);
          dp[x][y][!p] = dp[x][y][p] + 1;
          Q.push(P(x,y,!p));
        }
      }
      return -1;
    }
};

int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m; 
  vvi mtx (n, vi(m));
  for(auto & v : mtx) input(v);
  Solution sol;
  cout << sol.minimumMoves(mtx) << endl;
  return 0;
}
