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
  int n,m,ans;
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};
  bool C(int x, int y){
    return x >= 0 and y >= 0 and x < n and y < m;
  }

  int move( int x, int y, vvi & B){
    int ans = 0, q = 0, tmp=0;
    ans += B[x][y];
    tmp = B[x][y];
    B[x][y] = 0;
    forall(t,0,4){
      auto xx = x+dx[t], yy = y+dy[t];
      if( C(xx,yy) and B[xx][yy] ){
        q = max(q, move(xx,yy,B));
      }
    }
    B[x][y] = tmp;
    return ans + q;
  }
    
  int solve(int x, int y, vvi B){
    return move(x,y,B);
  }

  public:
    int getMaximumGold(vector<vector<int>>& grid) {
      n = sz(grid), m = sz(grid[0]);
      ans = 0;
      forall(i,0,n) forall(j,0,m) if( grid[i][j] ){
        auto tmp = solve(i,j, grid);
        ans = max(ans, tmp);
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
