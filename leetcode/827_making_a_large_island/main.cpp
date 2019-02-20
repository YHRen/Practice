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
  int n;
  vvi mtx;
  bool try_color(int x, int y, vvi & clr, int c){
    if( x >= 0 and y >=0 and x < n and y < n and mtx[x][y] == 1 and clr[x][y] == -1 ){
      clr[x][y] = c;
      return true;
    }else{
      return false;
    }
  }
  public:
    int largestIsland(vector<vector<int>>& grid) {
      mtx = grid;
      n = grid.size();
      vvi color(n, vi(n,-1));
      int cid = 0;
      int max_sz = 0;
      unordered_map<int,int> island_sz;
      forall(i,0,n) forall(j,0,n) if( grid[i][j] == 1 and color[i][j] == -1 ) {
        color[i][j] = cid;
        queue<ii> Q;
        Q.push(mp(i,j));
        int cnt = 0;
        while(!Q.empty()){
          auto xy = Q.front(); Q.pop();
          cnt ++;
          int x = xy.first, y = xy.second, c = color[x][y];
          if( try_color( x+1, y, color, c) ) Q.push(mp(x+1,y));
          if( try_color( x-1, y, color, c) ) Q.push(mp(x-1,y));
          if( try_color( x, y+1, color, c) ) Q.push(mp(x,y+1));
          if( try_color( x, y-1, color, c) ) Q.push(mp(x,y-1));
        }
        island_sz[cid++] = cnt;
        max_sz = max(max_sz, cnt);
      }

      debug("max_sz = ",max_sz);

      forall(i,0,n) forall(j,0,n) if( grid[i][j] == 0 ){
        debug("at ", i, j);
        int tmp = 1;
        set<int> visited;
        if( i > 0 and grid[i-1][j] == 1 and visited.count(color[i-1][j]) == 0 ){   int c = color[i-1][j]; tmp += island_sz[c]; visited.insert(c); }
        if( i < n-1 and grid[i+1][j] == 1 and visited.count(color[i+1][j]) == 0 ){ int c = color[i+1][j]; tmp += island_sz[c]; visited.insert(c); }
        if( j > 0 and grid[i][j-1] == 1 and visited.count(color[i][j-1]) == 0 ){   int c = color[i][j-1]; tmp += island_sz[c]; visited.insert(c); }
        if( j < n-1 and grid[i][j+1] == 1 and visited.count(color[i][j+1]) == 0 ){ int c = color[i][j+1]; tmp += island_sz[c]; visited.insert(c); }
        debug("tmp = ", tmp);
        max_sz = max(max_sz, tmp);
      }
      return max_sz;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vvi mtx(n,vi(n));
  for(auto & v : mtx) input(v);
  Solution sol;
  cout << sol.largestIsland(mtx) << '\n';

  return 0;
}
