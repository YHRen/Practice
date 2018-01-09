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
typedef vector<vector<char>> vvc;
class Solution {
  int n,m;
  vector<vector<char>> is_visited;
  public:

  void bfs( int i, int j, const vvc & grid ){
    is_visited[i][j] = true;
    queue<ii> Q;
    Q.push(mp(i,j));
    while(!Q.empty()){
      auto x = Q.front(); Q.pop();
      i = x.first;
      j = x.second;
      if( i+1 < n && grid[i+1][j] == '1' && !is_visited[i+1][j] ){
        is_visited[i+1][j] = true;
        Q.push(mp(i+1,j));
      }
      if( i > 0 && grid[i-1][j] == '1' && !is_visited[i-1][j] ){
        is_visited[i-1][j] = true;
        Q.push(mp(i-1,j));
      }
      if( j+1 < m && grid[i][j+1] == '1' && !is_visited[i][j+1] ){
        is_visited[i][j+1] = true;
        Q.push(mp(i,j+1));
      }
      if( j > 0 && grid[i][j-1] == '1' && !is_visited[i][j-1] ){
        is_visited[i][j-1] = true;
        Q.push(mp(i, j-1));
      }
    }
  }

  int numIslands(vector<vector<char>>& grid) {
    this->n = grid.size(); if(!n) return 0;
    this->m = grid[0].size(); if(!m) return 0;
    is_visited.resize(n);
    for(auto & row : is_visited ) row.resize(m, false);
    int ans = 0;
    forall(i,0,n){
      forall(j,0,m){
        if( grid[i][j] == '1' && !is_visited[i][j] ){
          ++ans;
          bfs(i, j, grid);
        }
      }
    }
    return ans;
  }

};
int main( int argc, char * argv[] ){
  int n, m; cin >> n >> m;
  vvc grid(n, vector<char>(m));
  for( auto & row : grid ){
    input(row);
  }
  Solution sol;
  cout << sol.numIslands( grid ) << '\n';

  return 0;
}
