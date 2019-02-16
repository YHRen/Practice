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
    int rectangleArea(vector<vector<int>>& rectangles) {
      set<int> unique_x, unique_y;
      for(auto & r : rectangles ){
        unique_x.insert(r[0]);
        unique_x.insert(r[2]);
        unique_y.insert(r[1]);
        unique_y.insert(r[3]);
      }
      unique_x.insert(0);
      unique_x.insert(INF);
      unique_y.insert(0);
      unique_y.insert(INF);
      int n = unique_x.size(), m = unique_y.size();
      vi x_ticks(all(unique_x));
      vi y_ticks(all(unique_y));
      vvi mtx(n, vi(m,0));
      for(auto & r : rectangles ){
        int i = lower_bound(all(x_ticks), r[0]) - x_ticks.begin();
        int ii = lower_bound(x_ticks.begin() + i, x_ticks.end(), r[2]) - x_ticks.begin();
        int j = lower_bound(all(y_ticks), r[1]) - y_ticks.begin();
        int jj = lower_bound(y_ticks.begin() + j, y_ticks.end(), r[3]) - y_ticks.begin();
        for(; i<ii; ++i ){
          forall(k, j, jj){
            mtx[i][k] = 1;
          }
        }
      }

      ll ans = 0;
      forall(i,0,n-1) forall(j,0,m-1)
        if( mtx[i][j] ){
          ans += ll(x_ticks[i+1] - x_ticks[i]) * ll(y_ticks[j+1] - y_ticks[j]);
          ans %= INF;
        }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vvi mtx(n, vi(4)); for( auto & v : mtx ) input(v);
  Solution sol;
  cout << sol.rectangleArea(mtx) << '\n';

  return 0;
}
