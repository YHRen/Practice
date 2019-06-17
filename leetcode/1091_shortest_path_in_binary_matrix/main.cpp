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
  int n;
  bool C( int x, int y ){
    return x >=0 and y >=0 and x < n and y < n;
  }
  public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      n = sz(grid);
      if( grid[0][0] == 1 or grid[n-1][n-1]==1 ) return -1;
      if( n == 1 ) return 1;
      vi dx = {1,0,-1,0,1,1,-1,-1};
      vi dy = {0,1,0,-1,-1,1,1,-1};
      vvi dist(n,vi(n,-1));
      dist[0][0] = 1;
      queue<ii> Q;
      Q.push(mp(0,0));
      while(!Q.empty()){
        auto [x,y] = Q.front(); Q.pop();
        debug("x,y",x,y,dist[x][y]);
        forall(i,0,8){
          int xx = x + dx[i], yy = y+dy[i];
          if( C(xx,yy) and grid[xx][yy] == 0 and dist[xx][yy] == -1 ){
            if( xx == n-1 and yy == n-1 ) return dist[x][y]+1;
            dist[xx][yy] = dist[x][y] + 1;
            Q.push(mp(xx,yy));
          }
        }
      }
      return -1;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vvi mtx(n, vi(n)); for(auto & v : mtx ) input(v);
  Solution sol;
  cout << sol.shortestPathBinaryMatrix(mtx) << endl;
  return 0;
}
