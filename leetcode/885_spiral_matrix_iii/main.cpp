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
  vi X = {0, 1, 0, -1 };
  vi Y = {1, 0, -1, 0 };
  public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int x, int y) {
      int tot = R*C;
      set<ii> visited;
      visited.insert( mp(x, y) );
      int cnt = 1;
      int dir = 3;
      vvi ans;
      ans.pb(vi{x, y});
      while( ans.size() != tot ){
        int old_dir = dir;
        dir += 1;
        dir %= 4;
        if( !in( mp( x+X[dir], y + Y[dir] ), visited ) ){
          x += X[dir];
          y += Y[dir];
          visited.insert(mp(x,y));
          if( x >=0 and y >= 0 and x < R and y < C ){
            cnt ++;
            ans.pb(vi{x,y});
          }
        }else{
          dir = old_dir;
          x += X[dir];
          y += Y[dir];
          visited.insert(mp(x,y));
          if( x >=0 and y >= 0 and x < R and y < C ){
            ans.pb(vi{x,y});
            cnt ++;
          }
        }
        debug("x,y",x,y);
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  Solution sol;
  int r,c,x,y; cin >> r >> c >> x >> y;
  auto ans = sol.spiralMatrixIII(r, c, x, y );
  for(auto v : ans ){
    print_(v);
  }

  return 0;
}
