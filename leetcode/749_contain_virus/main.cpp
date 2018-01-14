// #include <bits/stdc++.h>
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
  int n, m;
  vvi dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  set<int> get_next_gen(const vvi& grid, set<int>& seed) {
    set<int> ans;
    for (auto z : seed) {
      int x = z / m, y = z % m;
      forall(k, 0, 4) {
        int xx = x + dir[k][0];
        int yy = y + dir[k][1];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == 0) {
          ans.insert(xx * m + yy);
        }
      }
    }
    return ans;
  }

  void infect(vvi& grid, const set<int>& seed) {
    for (auto z : seed) {
      int x = z / m, y = z % m;
      forall(k, 0, 4) {
        int xx = x + dir[k][0];
        int yy = y + dir[k][1];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == 0) {
          grid[xx][yy] = 1;
        }
      }
    }
  }

  int find_most_infectious_region(vvi& grid) {
    vvi color (n, vi(m, -1));
    vvi is_visited(n, vi(m, 0));
    int current_max = 0;
    int current_max_index = -1;
    set<int> ans;
    vector<set<int>> clusters;
    forall(i, 0, n) {
      forall(j, 0, m) {
        if (grid[i][j] == 1 && is_visited[i][j] == 0) {
          queue<int> Q;
          Q.push(i * m + j);
          is_visited[i][j] = 1;
          set<int> S;
          while (!Q.empty()) {
            int z = Q.front();
            Q.pop();
            S.insert(z);
            int x = z / m, y = z % m;
            color[x][y] = clusters.size();
            forall(k, 0, 4) {
              int xx = x + dir[k][0];
              int yy = y + dir[k][1];
              if (xx >= 0 && xx < n && yy >= 0 && yy < m &&
                  is_visited[xx][yy] == 0 && grid[xx][yy] == 1) {
                is_visited[xx][yy] = 1;
                Q.push(xx * m + yy);
              }
            }
          }
          auto next_gen = get_next_gen(grid, S);
          if (next_gen.size() > current_max) {
            current_max = next_gen.size();
            current_max_index = clusters.size();
            ans = next_gen;
          }
          clusters.emplace_back(S);
        }
      }
    }
    if (current_max_index == -1) return 0;
    for (auto Z : clusters[current_max_index]) {
      grid[Z / m][Z % m] = -1;
    }
    int res = 0;
    debug("current_max=", current_max );
    debug("current_max_index=", current_max_index );
    for(auto r: color ){
      print_(r);
    }
    for( auto z : ans ){
      int x = z / m, y = z % m;
      forall(k, 0, 4) {
        int xx = x + dir[k][0];
        int yy = y + dir[k][1];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && color[xx][yy] == current_max_index) {
          res ++;
        }
      }
    }
   
    forall(i, 0, clusters.size()) {
      if (i != current_max_index) {
        infect(grid, clusters[i]);
      }
    }
    return res;
  }

 public:
  int containVirus(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    int ans = 0, tmp;
    do {
      tmp = find_most_infectious_region(grid);
      ans += tmp;
    } while (tmp > 0);
    return ans;
  }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  vvi mtx(n,vi(m));
  for( auto & r : mtx ) input(r);
  Solution sol;
  cout << sol.containVirus(mtx) << '\n';

  return 0;
}
