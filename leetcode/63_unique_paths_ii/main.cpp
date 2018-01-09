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
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
      int n = obs.size();
      debug(1);
      if( !n ) return 0;
      int m = obs.front().size(); if( !m ) return 0;
      if( obs.front().front() || obs.back().back() ) return 0;
      debug("n,m",n,m);
      vvi mtx(n,vi(m,-1));
      queue<ii> Q;
      mtx[0][0] = 1;
      Q.push(mp(0, 0));
      while( !Q.empty() ){
        auto p = Q.front(); Q.pop();
        int i = p.first, j = p.second;
        if( i + 1 < n && !obs[i+1][j] ){
          if( mtx[i+1][j] == -1 ){
            mtx[i+1][j] = mtx[i][j];
            Q.push( mp( i+1,j ) );
          }else{
            mtx[i+1][j] += mtx[i][j];
          }
        }
        if( j + 1 < m && !obs[i][j+1] ){
          if( mtx[i][j+1] == -1 ){
            mtx[i][j+1] = mtx[i][j];
            Q.push( mp( i,j+1) );
          }else{
            mtx[i][j+1] += mtx[i][j];
          }
        }
      }
      debug(mtx.back().back());
      if( mtx.back().back() == -1 ) return 0;
      else return mtx.back().back();
    }
};
int main( int argc, char * argv[] ){
  vvi obs(1,vi(2,0));
  Solution sol;
  debug(obs.size() );
  cout << sol.uniquePathsWithObstacles(obs) << '\n';

  return 0;
}
