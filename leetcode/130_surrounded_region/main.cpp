#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <cmath>
#include <cassert>

#define input(v)                  for(int i = 0; i < v.size(); ++i){ cin >> v[i]; }

// numeric_limits
#define INF                         (int)1e9
#define EPS                         1e-9

#define bitcount                    __builtin_popcount
#define gcd                         __gcd

#define forall(i,a,b)               for(int i=a;i<b;i++)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define mp                          make_pair

#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
typedef unsigned long long int ull_t;
typedef long long int           ll_t;

using namespace std;

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

/******* Actual Code Starts Here *********/
// https://leetcode.com/problems/surrounded-regions/
//  Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
//  A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//  For example,
//
//  X X X X
//  X O O X
//  X X O X
//  X O X X
//
//  After running your function, the board should be:
//
//  X X X X
//  X X X X
//  X X X X
//  X O X X
//

class Solution {
  private:

    void solve_region( 
        int i, int j, 
        const int n,
        const int m,
        vector<vector<char>> & board,
        vector<vector<uint8_t>> & is_visited ){
      is_visited[i][j] = true;
      bool is_surrounded = true;
      queue<pair<int,int>> Q;
      stack<pair<int,int>> S;
      Q.push( make_pair(i,j) );
      while( !Q.empty() ){
        i = Q.front().first;
        j = Q.front().second;
        S.push( Q.front() );
        Q.pop();

        vector<pair<int,int>> next_moves = {
          make_pair( i+1, j ),
          make_pair( i-1, j ),
          make_pair( i, j+1 ),
          make_pair( i, j-1 ) };
        for( const auto & mv : next_moves ){
          if( mv.first >= 0 && mv.first < n &&
              mv.second >= 0 && mv.second < m ){
            if( board[mv.first][mv.second] == 'O' && 
                is_visited[mv.first][mv.second] == false){
              is_visited[mv.first][mv.second] = true;
              Q.push( mv );
            }
          }else{ // hit the boundary
            is_surrounded = false;
          }
        }
      }

      if( is_surrounded ){
        while( !S.empty() ){
          board[S.top().first][S.top().second] = 'X';
          S.pop();
        }
      }
    }

  public:
    void solve(vector<vector<char>>& board) {
      if( board.empty() || board[0].empty() ) return;
      int n = board.size();
      int m = board.at(0).size();
      vector<vector<uint8_t>> is_visited( n, vector<uint8_t>(m, false) );

      for( int i = 0; i < n; ++i ){
        for( int j = 0; j < m; ++j ){
          if( board[i][j] == 'O' && !is_visited[i][j] ){
            solve_region( i, j, n, m, board, is_visited );
          }
        }
      }
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n,m; cin >> n >> m;
  vector<vector<char>> board(n, vector<char>(m));
  for( auto & row : board ){
    input( row );
  }
  Solution s;
  s.solve( board );
  for( const auto & row : board ){
    print_( row );
  }

  return 0;
}
