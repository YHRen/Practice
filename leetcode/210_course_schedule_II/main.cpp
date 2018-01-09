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
  private:
    int n;
    vvi in_edge, out_edge;
  public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
      this->n = numCourses;
      this->in_edge.resize(n);
      this->out_edge.resize(n);
      for( const auto & e : prerequisites ){
        in_edge[e.first].pb( e.second );
        out_edge[e.second].pb(e.first);
      }
      vi ans;
      vi indeg(n);
      queue<int> Q;
      forall(i,0,n){
        indeg[i] = in_edge[i].size();
        if( in_edge[i].empty() ){ Q.push(i); }
      }
      if( Q.empty() ) return ans;
      vi is_visited(n,false);
      while( !Q.empty() ){
        auto v = Q.front();
        Q.pop();
        if( is_visited[v] ) return vector<int>{};
        is_visited[v] = true;
        ans.pb(v);
        for( auto u : out_edge[v] ){
          indeg[u] -= 1;
          if( indeg[u] == 0 ) Q.push(u);
        }
      }
      if( ans.size() <  n ) return vector<int>{};
      else return ans;
    }
};

int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  vii edges(m);
  forall(i,0,m) cin >> edges[i].first >> edges[i].second;
  Solution sol;
  auto ans = sol.findOrder(n, edges);
  print_(ans);
  return 0;
}
