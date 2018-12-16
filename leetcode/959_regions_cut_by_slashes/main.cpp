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
  int n;
  vvi mtx;
  void try_visit( int x, int y, queue<ii> & Q, vvi & visited){
    if( x >= 0 && x < n && y >= 0 && y < n ){
      if( visited[x][y] || mtx[x][y] == 1 ) return;
      visited[x][y] = 1;
      Q.push(mp(x,y));
    }
  }

public:
    int regionsBySlashes(vector<string>& grid) {
      int m = grid.size();
      n = 3*m;
      mtx.resize(n);
      for(auto & v : mtx ) v.resize(n,0);
      forall(i,0,m){
        forall(j,0,m){
          if( grid[i][j] == ' ' ) continue;
          else if( grid[i][j] == '/' ){
            mtx[i*3][j*3+2] = 1;
            mtx[i*3+1][j*3+1] = 1;
            mtx[i*3+2][j*3] = 1;
          }else if( grid[i][j] == '\\'){
            mtx[i*3][j*3] = 1;
            mtx[i*3+1][j*3+1] = 1;
            mtx[i*3+2][j*3+2] = 1;
          }
        }
      }

      for(auto v : mtx ){ print_(v); }

      int ans = 0;
      vvi visited(n, vi(n, false));
      forall(i,0,n){
        forall(j,0,n){
          if( visited[i][j] || mtx[i][j] ) continue;
          debug("not visited ", i, j );
          visited[i][j] = 1;
          ans +=1;
          queue<ii> Q;
          Q.push(mp(i,j));
          while(!Q.empty()){
            auto p = Q.front(); Q.pop();
            int x= p.first, y=p.second;
            try_visit( x-1, y, Q, visited );
            try_visit( x+1, y, Q, visited );
            try_visit( x, y-1, Q, visited );
            try_visit( x, y+1, Q, visited );
          }
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int m ; cin >> m;
  vector<string> grid(m); input(grid);
  Solution sol;
  cout << sol.regionsBySlashes(grid) << '\n';

  return 0;
}
