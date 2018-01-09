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
  typedef vector<vector<char>> vvc;
  private:
    string str;
    int n,m,K;
    vvc C;
    bool dfs(int i, int j, int k, const vvc& b) {
      if (k == K) return true;
      if (i < 0 || i == n || j < 0 || j == m) return false;
      if (b[i][j] == str[k] && !C[i][j]) {
        C[i][j] = 1;
        if (dfs(i + 1, j, k + 1, b) || dfs(i, j + 1, k + 1, b) ||
            dfs(i - 1, j, k + 1, b) || dfs(i, j - 1, k + 1, b)){
          debug(i,j,k);
          return true;
        }
        C[i][j] = 0;
      }
      return false;
    }

   public:
    bool exist(vector<vector<char>>& board, string word) {
      n = board.size(); if(!n) return false;
      m = board.front().size(); if(!m) return false;
      str = word; K = word.size();
      C.resize(n); for(auto & v : C ) v.resize(m,false);
      if( word.size() > n*m ) return false;
      if( word.empty() ) return true;
      char s = word[0];
      vii cand;
      forall(i,0,n) forall(j,0,m) if( board[i][j] == s ) 
        cand.pb( mp( i,j ) );
      if( cand.empty() ) return false;
      for (auto p : cand) {
        int i = p.first, j = p.second;
        if (dfs(i, j, 0, board)) return true;
      }
      return false;
    }
};
int main( int argc, char * argv[] ){
  vector<vector<char>> board= { {'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
  string target = "ABCB";
  Solution sol;
  cout << sol.exist(board, target ) << '\n';

  return 0;
}
