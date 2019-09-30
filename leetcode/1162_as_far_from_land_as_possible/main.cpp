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
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};
  vvi dp;
  bool C(int x, int y, int d, const vvi & grid){ 
    return x < n and y < n and x >= 0 and y >= 0 and grid[x][y] == 0 and dp[x][y] > d;
  }
  public:
    int maxDistance(vector<vector<int>>& grid) {
      n = sz(grid);
      dp.resize(n); for(auto & v : dp ) v.resize(n,INF);
      queue< pair<ii, int> > Q;

      forall(i,0,n) forall(j,0,n) 
        if( grid[i][j] == 1 ) 
          Q.push(mp( mp(i,j), 0) );

      if( Q.empty() or sz(Q)==n*n ) return -1;

      while(!Q.empty()){
        auto tmp = Q.front(); Q.pop();
        int i = tmp.first.first, j = tmp.first.second, d = tmp.second;
        forall(t,0,4){
          int xx = i + dx[t], yy = j + dy[t];
          if( C(xx,yy,d+1,grid) ){
            dp[xx][yy] = d+1;
            Q.push(mp(mp(xx,yy),d+1));
          }
        }
      }

      int ans = 0;
      forall(i,0,n) forall(j,0,n) 
        if( grid[i][j] == 0 and dp[i][j] > ans ) 
          ans = dp[i][j];

      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
