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
#include <complex>
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

//auto ____ =[]()
//{
//    std::ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    return nullptr;
//}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/

class Solution {
  int N, M;
  bool C( int x, int y ){
    return x >= 0 and y >= 0 and x < N and y < M;
  }
  void try_visit( int x, int y, queue<ii> & Q, vector<string> & B, vvi & is_visited ){
    debug(x,y,C(x,y));
    if( C( x, y ) and is_visited[x][y] == false and (B[x][y] == 'X' or B[x][y] =='S') ){ 
      B[x][y] = 'S';
      is_visited[x][y]=true;
      debug("push", x, y);
      Q.push(mp(x,y));
    }
  }
public:
    int numEnclaves(vector<vector<int>>& A) {
      int n = sz(A), m = sz(A[0]);
      vector<string> B(n+2);
      B[0] = string(m+2, 'S');
      B[n+1] = string(m+2, 'S');
      N = n+2, M = m+2;
      forall(i,0,n){
        B[i+1] += "S";
        forall(j,0,m){
          if( A[i][j] == 0 ) B[i+1] += "O";
          else B[i+1] += "X";
        }
        B[i+1] += "S";
      }

      for(auto v : B )
        debug(v);
      vvi is_visited(n+2, vi(m+2, false));
      is_visited[0][0] = true;
      queue<ii> Q;
      Q.push(mp(0,0));
      while(!Q.empty()){
        auto xy = Q.front(); Q.pop();
        int x = xy.first, y = xy.second;
        debug(x,y);
        try_visit( x+1, y, Q, B, is_visited );
        try_visit( x-1, y, Q, B, is_visited );
        try_visit( x, y+1, Q, B, is_visited );
        try_visit( x, y-1, Q, B, is_visited );
      }

      int ans = 0;
      forall(i,1,n+2){
        ans += count_if(all(B[i]), [](char c){ return c == 'X'; });
      }
      for(auto v : B )
        debug(v);

      return ans;
    }
};
int main( int argc, char * argv[] ){
  vvi mtx = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
  Solution sol;
  cout << sol.numEnclaves(mtx) << '\n';

  return 0;
}
