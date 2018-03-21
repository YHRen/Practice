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
  private:
    int n,m;
    vvi grid, prev, dist;
    vector<vector<char>> is_visited;
    const vvi dir = { {1, 0}, {0, -1}, {0, 1}, { -1, 0} };

    template<class T>
    void resize_mtx( vector<vector<T>> & A, int n, int m ){
      A.resize(n);
      for( auto & r : A ) r.resize(m);
    }

    template<class T>
    void init_mtx( vector<vector<T>> & A, T val ){
      for( auto & r : A ) r.assign(r.size(), val);
    }

    template<class T>
    void print_mtx( const vector<vector<T>> & A ){
      for( auto & r : A ){
        print_(r);
      }
    }

    bool C( int x, int y ){
      return x >= 0 && y >= 0 && x < n && y < m ;
    }

    void bfs_init(){
      queue<ii> Q;
      init_mtx( is_visited, static_cast<char>(false) );
      init_mtx( dist, INF);
      init_mtx( prev, -1 );

      forall(j,0,m) if( grid[0][j] == 1 ){
        dist[0][j] = 0;
        prev[0][j] = n*m;
        is_visited[0][j] = 1;
        Q.push(mp(0,j));
      }

      while( !Q.empty() ){
        auto u = Q.front(); Q.pop();
        int x = u.first, y = u.second;
        for( const auto & d : dir ){
          int xx = x + d[0], yy = y + d[1];
          if( C( xx, yy ) && grid[xx][yy] == 1 && is_visited[xx][yy] == 0 ){
            is_visited[xx][yy] = 1;
            dist[xx][yy] = dist[x][y] + 1;
            prev[xx][yy] = x*m + y;
            Q.push( mp( xx, yy ) );
          }
        }
      }
    }

    void update( ii u ){
      queue<ii> Q;
      Q.push( u );
      while( !Q.empty() ){
        u = Q.front(); Q.pop();
        int x = u.first, y = u.second;
        for ( const auto & d : dir ){
          int xx = x + d[0], yy = y + d[1];
          if( C(xx,yy) && is_visited[xx][yy] == 2 && grid[xx][yy] == 1 && dist[xx][yy] > dist[x][y]  ){
            debug("prev ", xx, yy , " now is ", x, y  );
            debug("dist[xxyy] =", dist[xx][yy], "vs", dist[x][y]);
            prev[xx][yy] = x*m+y;
            dist[xx][yy] = dist[x][y] + 1;
            is_visited[xx][yy] = 1;
            Q.push( mp( xx,yy) );
          }
        }
      }
    }

    int knock_out( int a, int b ){
      if( grid[a][b] == 0 ) return 0;
      int potential = dist[a][b];
      int target = a * m + b;
      grid[a][b] = 0;
      int ans = 0;

      init_mtx( is_visited, char(false) );
      is_visited[a][b] = true;
      
      
      queue<ii> Q;
      for( const auto & d : dir ){
        int xx = a + d[0], yy = b + d[1];
        if( C( xx, yy ) && grid[xx][yy] == 1 && prev[xx][yy] == target){
          dist[xx][yy] = INF;
          is_visited[xx][yy] = 2;
          Q.push( mp(xx,yy ) );
        }
      }

        debug("Q.size = ", Q.size());
        bool grounded = false;
        ii   starting = {-1, -1};
        vii  S;
        while( !Q.empty() ){
          // ans += 1;
          auto u = Q.front(); Q.pop();
          int x = u.first, y = u.second;
          debug("at=", x,y );
          if( is_visited[x][y] == 1 ) continue;
          S.pb(mp(x, y));

          for( const auto & d : dir ){
            int xx = x + d[0], yy = y + d[1];
            if( C(xx,yy) && grid[xx][yy] == 1 && is_visited[xx][yy] == 0 ){
              debug("at xx yy", xx, yy, "grid[xx][yy]", grid[xx][yy] );
              if( prev[xx][yy] == x*m+y ){
                debug("      prev yes", xx, yy );
                dist[xx][yy] = INF;
                is_visited[xx][yy] = 2;
                Q.push( mp(xx, yy) );
              }else if( dist[xx][yy] == potential ){
                debug("      changing grounded to true");
                debug(" prev = ", prev[xx][yy] / m, prev[xx][yy]%m );
                is_visited[xx][yy] = 1;
                update( mp(xx, yy ) );
              }else{
                is_visited[xx][yy] = 2;
                Q.push( mp( xx, yy ) );
              }
            }
          }
        }

        debug("S.size()=", S.size());

        for( auto p : S ){
          debug(" p = ", p.first, p.second, (int)is_visited[p.first][p.second] );
          if( is_visited[p.first][p.second] == 2 ){
            grid[p.first][p.second] = 0;
            ans += 1;
          }
        }
        return ans;
    }
              
  public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
      this->n = grid.size();
      this->m = grid[0].size();
      resize_mtx( this->is_visited, n, m );
      resize_mtx( this->prev, n, m );
      resize_mtx( this->dist, n, m );
      swap(this->grid, grid);
      bfs_init();

      print_mtx( dist );
      print_mtx( prev );

      vi ans;
      for( const auto & p : hits ){
        debug("knocking out (", p[0], p[1], ")");
        ans.pb( knock_out( p[0], p[1] ) );
        print_mtx(dist);
      }
      return ans;

    }
};

int main( int argc, char * argv[] ){
  int n,m,t; cin >> n >> m >> t;
  vvi mtx(n,vi(m));
  for( auto & r : mtx ) input(r);
  vvi query(t, vi(2));
  for( auto & r : query) input(r);
  Solution sol;
  auto ans = sol.hitBricks( mtx, query );
  print_(ans);
  for(auto x : ans ) cout << x << ' '; cout << '\n';


  return 0;
}
