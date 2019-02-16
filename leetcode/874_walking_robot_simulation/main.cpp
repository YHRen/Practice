#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
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
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
      unordered_map<int, unordered_set<int>> x_obs, y_obs;
      for(auto & p : obstacles ){
        int x = p[0], y = p[1];
        x_obs[x].insert(y);
        y_obs[y].insert(x);
      }

      vi dx = {0, 1, 0, -1};
      vi dy = {1, 0, -1, 0};
      int dir = 0;
      int x = 0, y = 0;
      int ans = 0;
      for(auto c : commands ){
        debug("c = ", c, "x,y", x, y, "dir=",dir);
        if ( c < 0 ){ 
          if( c == -1 ){
            dir += 1;
            dir %= 4;
          }else if( c==-2){
            dir -= 1;
            dir += 4;
            dir %= 4;
          }
        }else{
          if( dir == 0 || dir == 2 ){ // x fixed;
            auto itr = x_obs.find(x);
            if( itr == x_obs.end() ){
              y += c * dy[dir];
            }else{
              int yy;
              for(int i = 0; i < c; ++i ){
                yy = y + dy[dir];
                if(  itr->second.find(yy) != itr->second.end()  ){
                  break;
                }else{
                  y = yy;
                }
              }
            }
          }else{ // y fixed dir = 1 and 3
            auto itr = y_obs.find(y);
            if( itr == y_obs.end() ){
              x += c * dx[dir];
            }else{
              int xx;
              for(int i = 0; i < c; ++i ){
                xx = x + dx[dir];
                if( itr->second.find(xx) != itr->second.end() ){
                  break;
                }else{
                  x = xx;
                }
              }
            }
          }
          ans = max(ans, x*x+y*y);
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  vi v(n); input(v);
  vvi u(m); for(auto & x:u ){ x.resize(2); input(x);}
  Solution sol;
  cout << sol.robotSim(v, u) << '\n';

  return 0;
}
