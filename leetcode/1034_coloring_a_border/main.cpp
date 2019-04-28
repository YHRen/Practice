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
  int n,m;
  bool C(int x, int y){
    return x >= 0 and x < n and y >=0 and y < m;
  }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
      n = sz(grid);
      m = sz(grid[0]);
      vvi visited(n, vi(m, 0 ));
      int c = grid[r0][c0];
      vi dx = {1,0,-1,0};
      vi dy = {0,1,0,-1};
      vii ans;
      queue<ii> Q;
      Q.push(mp(r0,c0));
      while(!Q.empty()){
        auto [x,y] = Q.front(); Q.pop();
        forall(i,0,4){
          int xx = x+dx[i], yy = y+dy[i];
          if( C(xx,yy) ){
            if( visited[xx][yy] == false ){
              if(grid[xx][yy] == c ){
              visited[xx][yy] = true;
              Q.push(mp(xx,yy));
              }else{
                ans.pb(mp(x,y));
              }
            }
          }else{
            ans.pb(mp(x,y));
          }
        }
      }
      sort(all(ans));
      ans.erase(unique(all(ans)),ans.end());
      vvi res = grid;
      for(auto [x,y] : ans ){
        res[x][y] = color;
      }
      return res;
        
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
