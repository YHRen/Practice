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
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF                         (int)1000000007
#define EPS                         1e-9

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<(b);++i)
#define trav(a,x)                   for(auto & a: x)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define sz(c)                       (int)(c).size()
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

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

auto ____ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  bool if_win( vector<string> & B, char t){
    trav(row, B){
      int cnt = 0;
      trav(c, row){
        if( c == t ) cnt ++;
      }
      if( cnt == 3 ) return true;
    }
    forall(j,0,3){
      int cnt = 0;
      forall(i,0,3){
        if( B[i][j] == t ) cnt ++;
      }
      if( cnt == 3 ) return true;
    }
    if( ( (int)(B[0][0] == t ) +  (int)(B[1][1] == t) + (int)(B[2][2] == t ) ) == 3 ) return true;
    if( ( (int)(B[0][2] == t ) +  (int)(B[1][1] == t) + (int)(B[2][0] == t ) ) == 3 ) return true;
    return false;
  }

  public:
    bool validTicTacToe(vector<string>& board) {
      int cntX=0, cntO =0;
      trav(v, board){
        trav(c, v){
          if( c == 'X' ) cntX++;
          if( c == 'O' ) cntO++;
        }
      }
      if( cntX < cntO or cntX - cntO > 1 ) return false;
      bool xwin = if_win(board, 'X');
      bool owin = if_win(board, 'O');
      if( owin and xwin ) return false;
      if( cntX == cntO and xwin ) return false;
      if( cntX > cntO  and owin ) return false;
      return true;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
