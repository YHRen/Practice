#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
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
/******* Actual Code Starts Here *********/
class Solution {
  private:
    int n,m;
    vvi is_visited;
    vvi dir{{1,0}, {-1,0}, {0,1}, {0,-1}};
    int solve( const vvi & mtx ){
      priority_queue< ii, vii, greater<ii> > Q;
      forall(i,0,n){
        is_visited[i][0] = 1;
        is_visited[i][m-1] = 1;
        Q.push(mp(mtx[i][0], i*m+0));
        Q.push(mp(mtx[i][m-1], i*m+m-1));
      }
      forall(j,1,m-1){
        is_visited[0][j] = 1;
        is_visited[n-1][j] = 1;
        Q.push(mp(mtx[0][j],j));
        Q.push(mp(mtx[n-1][j], (n-1)*m+j));
      }
      int Max = -INF;
      int ans = 0;
      while( !Q.empty() ){
        auto v = Q.top(); Q.pop();
        Max = max(Max, v.first);
        int p = v.second/m, q = v.second%m;
        debug("Max = ", Max, "(", p, ",", q, ")", " val =", v.first, " ans =", ans );
        forall(i,0,4){
          int x = p + dir[i][0];
          int y = q + dir[i][1];
          if( x >= 0 && x < n && y >= 0 && y < m &&
              !is_visited[x][y] ){
            is_visited[x][y] = 1;
            ans += max(0, Max-mtx[x][y]);
            debug(" pushing (", x, y, ")" );
            Q.push(mp(mtx[x][y], x*m+y));
          }
        }
      }
      return ans;
    }


public:
    int trapRainWater(vector<vector<int>>& heightMap) {
      n = heightMap.size(); if (!n) return 0;
      m = heightMap[0].size(); if (!m) return 0;
      if( n==1 || m ==1 ) return 0;
      is_visited.resize(n);
      for( auto & row: is_visited ) row.resize(m,false);
      return solve(heightMap);
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  vvi mtx(n, vi(m) );
  for( auto & row : mtx ) input(row);
  Solution sol;
  cout << sol.trapRainWater( mtx ) << '\n';

  return 0;
}
