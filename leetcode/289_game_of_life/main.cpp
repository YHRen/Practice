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
// 289. Game of Life 
// https://leetcode.com/problems/game-of-life/
// According to the Wikipedia's
// article: "The Game of Life, also known simply as Life, is a cellular
// automaton devised by the British mathematician John Horton Conway in 1970."
//
// Given a board with m by n cells, each cell has an initial state live (1) or
// dead (0). Each cell interacts with its eight neighbors (horizontal,
// vertical, diagonal) using the following four rules (taken from the above
// Wikipedia article):
//
//  Any live cell with fewer than two live neighbors dies, as if caused by
//  under-population.  Any live cell with two or three live neighbors lives
//  on to the next generation.  Any live cell with more than three live
//  neighbors dies, as if by over-population..  Any dead cell with exactly
//  three live neighbors becomes a live cell, as if by reproduction.
//
//  Write a function to compute the next state (after one
//  update) of the board given its current state.
//
//  Follow up:
//
//      Could you solve it in-place? Remember that the board
//      needs to be updated at the same time: You cannot update
//      some cells first and then use their updated values to
//      update other cells.
class Solution {
    int count_alive( const vector<vector<int>> & board, int i, int j ){
      int alive = 0;
      if( i+1 < board.size()    &&  board[i+1][j] ) alive ++; 
      if( j+1 < board[0].size() &&  board[i][j+1] ) alive ++; 
      if( i-1 >= 0              &&  board[i-1][j] ) alive ++; 
      if( j-1 >= 0              &&  board[i][j-1] ) alive ++; 
      if( i+1 < board.size() && j+1 < board[0].size() &&  board[i+1][j+1] ) alive ++; 
      if( i-1 >= 0 && j-1 >= 0                        &&  board[i-1][j-1] ) alive ++; 
      if( i+1 < board.size() && j-1 >= 0              &&  board[i+1][j-1] ) alive ++; 
      if( i-1 >= 0 && j+1 < board[0].size()           &&  board[i-1][j+1] ) alive ++; 
      return alive;
    }
  public:
    void gameOfLife(vector<vector<int>>& board) {
      vector<pair<pair<int,int>,bool>> update_queue;
      for( int i = 0; i < board.size(); ++i ){
        for( int j = 0; j < board[0].size(); ++j ){
          int nbr = count_alive( board, i, j );
          if( board[i][j] && (nbr < 2 || nbr > 3) ){ // live cell
            update_queue.push_back( make_pair( make_pair(i,j), false ) );
            continue;
          }
          if( !board[i][j] && nbr == 3 ){
            update_queue.push_back( make_pair( make_pair(i,j), true  ) );
          }
        }
      }
      for( const auto & x : update_queue ){
        board[x.first.first][x.first.second] = x.second;
      }
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);




  return 0;
}
