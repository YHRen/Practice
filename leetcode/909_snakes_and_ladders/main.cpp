#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
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
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
      int n = board.size();
      reverse(all(board));
      forall(i,0,n) if( i%2 ) reverse(all(board[i]));
      vi v(n*n+1,0);
      vi u(n*n+1,0);
      forall(i,0,n){ copy(all(board[i]), v.begin()+i*n+1); }
      queue<ii> Q;
      u[1] = 1;

      vi xxx(n*n+1);
      iota(all(xxx),0);
      print_(xxx);
      print_(v);
      if( v[1] == -1 ) Q.push(mp(1,0));
      else Q.push(mp(v[1], 0));
      while(!Q.empty()){
        auto x = Q.front(); Q.pop();
        int idx = x.first, dist = x.second;
        debug("Q", idx, dist);
        if( idx + 6 >= n*n ) return dist+1;
        forall(i,1,7) if( u[idx+i] == 0){
          u[idx+i] = 1;
          if( v[idx+i] != -1 ){
            if( v[idx+i] == n*n ) return dist+1;
            Q.push(mp(v[idx+i], dist+1));
          }else{
            if( idx+i == n*n ) return dist+1;
            Q.push(mp(idx+i, dist+1));
          }
        }
      }
      return -1;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vvi mtx(n, vi(n)); for(auto & v : mtx ) input(v);
  Solution sol; 
  cout << sol.snakesAndLadders(mtx) << '\n';

  return 0;
}
