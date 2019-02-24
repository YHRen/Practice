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
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
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

// std::ios::sync_with_stdio(false);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
      int n = board.size();
      int ii = -1, jj=-1;
      forall(i,0,n) forall(j,0,n) if( board[i][j] == 'R' ) {
        ii = i;
        jj = j;
        break;
      }
      int ans = 0;
      forall(i,ii+1,n){
        if( board[i][jj] == 'B' ) break;
        if( board[i][jj] == '.' ) continue;
        if( board[i][jj] == 'p' ){
          ans ++;
          break;
        }
      }
      forall(j,jj+1,n){
        if( board[ii][j] == 'B' ) break;
        if( board[ii][j] == '.' ) continue;
        if( board[ii][j] == 'p' ){
          ans ++;
          break;
        }
      }
      for(int i = ii-1; i >=0; --i){
        if( board[i][jj] == 'B' ) break;
        if( board[i][jj] == '.' ) continue;
        if( board[i][jj] == 'p' ){
          ans ++;
          break;
        }
      }
      for(int j = jj-1; j >= 0; --j ){
        if( board[ii][j] == 'B' ) break;
        if( board[ii][j] == '.' ) continue;
        if( board[ii][j] == 'p' ){
          ans ++;
          break;
        }
      }
      return ans;
        
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
