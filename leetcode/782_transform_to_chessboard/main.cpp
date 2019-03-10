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
  int n;
  int cal( const vi & v ){
    print_(v);
    int starts_even = 0, starts_odd = 0;
    forall(i,0,n){
      if( v[i] ^ (i&1) ) starts_even ++;
      if( v[i] ^ ((i+1)&1) ) starts_odd ++;
    }
    int zeros = count_if(all(v),[](int x){ return x == 0; });
    debug(starts_even, starts_odd, n, zeros);
    if( n%2 == 0 ){
      if(  zeros != n/2 ) return -INF;
      if( starts_even%2 != 0 || starts_odd%2 != 0 ) return -INF;
      else return min(starts_even, starts_odd)/2;
    }else{
      if( abs( 2*zeros - n ) > 1 ) return -INF;
      if( zeros > n/2 ){
        return starts_even/2;
      }else{
        return starts_odd/2;
      }
    }
  }


  public:
  int movesToChessboard(vector<vector<int>>& b) {
    n = b.size();
    forall(i,0,n-1) forall(j,0,n-1) 
      if( b[i][j] ^ b[i+1][j] ^ b[i][j+1] ^ b[i+1][j+1] )
        return -1;
    vi col;
    forall(i,0,n) col.pb(b[i][0]);
    return max( cal(b[0]) + cal(col), -1);
  }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vvi mtx(n, vi(n)); for(auto & v : mtx ) input(v);
  Solution sol;
  cout << sol.movesToChessboard(mtx) << '\n';

  return 0;
}

/* problem statement
An N x N board contains only 0s and 1s. In each move, you can swap any 2 rows with each other, or any 2 columns with each other.

What is the minimum number of moves to transform the board into a "chessboard" - a board where no 0s and no 1s are 4-directionally adjacent? If the task is impossible, return -1.

Examples:
Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
Output: 2
Explanation:
One potential sequence of moves is shown below, from left to right:

0110     1010     1010
0110 --> 1010 --> 0101
1001     0101     1010
1001     0101     0101

The first move swaps the first and second column.
The second move swaps the second and third row.


Input: board = [[0, 1], [1, 0]]
Output: 0
Explanation:
Also note that the board with 0 in the top left corner,
01
10

is also a valid chessboard.

Input: board = [[1, 0], [1, 0]]
Output: -1
Explanation:
No matter what sequence of moves you make, you cannot end with a valid chessboard.

Note:

    board will have the same number of rows and columns, a number in the range [2, 30].
    board[i][j] will be only 0s or 1s.
*/
