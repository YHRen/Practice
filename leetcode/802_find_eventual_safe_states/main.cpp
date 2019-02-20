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
  vi color;
  int dfs( int x, const vvi & g, vi & mark){
    if( color[x] != 0 ) return color[x];
    if( mark[x] ){
      return color[x] = -1;
    }

    int flag = 1;
    mark[x] = 1;
    for(auto y : g[x] ){
      if( dfs(y,g, mark) == -1 ){
        flag = -1;
        break;
      }
    }
    mark[x] = 0;
    return color[x] = flag;
  }

  public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n = graph.size();
      color.resize(n,0);
      vi ans;
      vi mark(n,0);
      forall(i,0,n){
        if( color[i] == 0 ){
          dfs(i, graph, mark);
        }
        if( color[i] == 1 ) ans.pb(i);
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
