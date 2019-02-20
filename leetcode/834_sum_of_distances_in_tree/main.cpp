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
  int n;
  vi  parent;
  vii  cum_dist;
  vvi g;
  int find_root(){
      vi is_visited(n,-1);
      queue<int> Q;
      forall(i,0,n) if( g[i].size() == 1 ) { is_visited[i] = 0; Q.push(i); }
      while(!Q.empty()){
        int x = Q.front(); Q.pop();
        int d = is_visited[x];
        for(auto y : g[x]){
          if( is_visited[y] == -1 ){
            is_visited[y] = d + 1;
            Q.push(y);
          }
        }
      }
      return max_element(all(is_visited)) - is_visited.begin();
  }

  ii dfs( int x, int p ){
    int cnt = 1;
    int ans = 0;
    for(auto y : g[x] ){
      if( y != p ){
        parent[y] = x;
        auto rst = dfs(y, x);
        cnt += rst.first;
        ans += rst.first + rst.second;
      }
    }
    return cum_dist[x] = mp(cnt, ans);
  }
  
  public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
      n = N;
      g.resize(N);
      for(auto e : edges){ g[e[0]].pb(e[1]);  g[e[1]].pb(e[0]); }
      int r = find_root();
      debug("found root=",r);
      parent.resize(N,-1);
      cum_dist.resize(N);
      parent[r] = -1;
      vi ans(n,0);
      ans[r] = dfs(r, -1).second;

      debug("parent"); print_(parent);
      debug("cum dist"); printPair_(cum_dist);
      queue<int> Q; 
      Q.push(r);
      while( !Q.empty() ){
        int x = Q.front(); Q.pop();
        for( auto y : g[x] ){ 
          if( y != parent[x] ){
            debug("x =", x, "y =", y, cum_dist[y].first, cum_dist[y].second );
            ans[y] = cum_dist[y].second + ans[x] 
              - cum_dist[y].second - cum_dist[y].first + (n-cum_dist[y].first);
            Q.push(y);
          }
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vvi e(n-1,vi(2)); for(auto & v : e ) input(v);
  Solution sol;
  auto ans = sol.sumOfDistancesInTree(n, e);
  print_(ans);


  return 0;
}
