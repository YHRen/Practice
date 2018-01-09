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
  public:
    int findCircleNum(vector<vector<int>>& M) {
      int n = M.size();
      if( !n ) return 0;
      int ans = 0;
      vi is_visited(n,false);

      forall(i,0,n) if( !is_visited[i] ){
          ++ans;
          is_visited[i] = ans;
          queue<int> Q;
          Q.push(i);
          while( !Q.empty() ){
            int u = Q.front(); Q.pop();
            for( int i = 0; i < n; ++i ){
              if( M[u][i] && !is_visited[i] ){
                is_visited[i] = ans;
                Q.push(i);
              }
            }
          }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vvi M(n, vi(n) );
  for( auto & v : M ) input(v);
  Solution sol;
  cout << sol.findCircleNum(M) << '\n';


  return 0;
}
