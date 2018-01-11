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
  int n,m;
  vvi dir = { {1,0}, {-1,0}, {0, 1}, {0,-1} };
  private:
    void flood(queue<ii> & Q, vvi & is_flooded, const vvi & mtx){
      while(!Q.empty()){
        auto v = Q.front(); Q.pop();
        forall(i,0,4){
          int x = v.first + dir[i][0];
          int y = v.second + dir[i][1];
          if( x < n && x >= 0 && y < m && y >= 0 &&
              is_flooded[x][y] == false &&
              mtx[x][y] >= mtx[v.first][v.second] ){
            is_flooded[x][y] = true;
            Q.push(mp(x,y));
          }
        }
      }
    }

  public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& mtx) {
      this-> n = mtx.size();    if( n == 0 ) return vii{};
      this-> m = mtx[0].size(); if( m == 0 ) return vii{};
      if( n == 1 || m == 1 ) {
        vii ans; forall(i,0,n) forall(j,0,m) ans.pb(mp(i,j));
        return ans;
      }

      vvi visit_pacific(n, vi(m,0)), visit_atlantic(n, vi(m, 0));
      queue<ii> pacific_Q, atlantic_Q;
      forall(i,0,n){
        visit_pacific[i][0] = true;
        pacific_Q.push( mp(i,0) );
        visit_atlantic[i][m-1] = true;
        atlantic_Q.push( mp(i,m-1) );
      }

      forall(j,0,m){ 
        visit_pacific[0][j] = true;
        pacific_Q.push( mp(0,j) ); 
        visit_atlantic[n-1][j] = true;
        atlantic_Q.push( mp(n-1,j) );
      }
      
      flood( pacific_Q, visit_pacific, mtx );
      flood( atlantic_Q, visit_atlantic, mtx );
      vii ans;
      forall(i,0,n){
        forall(j,0,m){
          if( visit_pacific[i][j] && visit_atlantic[i][j] ){
            ans.pb(mp(i,j));
          }
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
