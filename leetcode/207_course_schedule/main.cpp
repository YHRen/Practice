#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <cmath>
#include <cassert>

#define input(v)                  for(int i = 0; i < v.size(); ++i){ cin >> v[i]; }

// numeric_limits
#define INF                         (int)1e9
#define EPS                         1e-9

#define bitcount                    __builtin_popcount
#define gcd                         __gcd

#define forall(i,a,b)               for(int i=a;i<b;i++)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define mp                          make_pair

#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
typedef unsigned long long int ull_t;
typedef long long int           ll_t;

using namespace std;

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

/******* Actual Code Starts Here *********/
// https://leetcode.com/problems/course-schedule/
// 207. Course Schedule 
// There are a total of n courses you have to take, labeled from 0 to n - 1.
//
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
//
// For example:
//
// 2, [[1,0]]
//
// There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
//
// 2, [[1,0],[0,1]]
//
// There are a total of 2 courses to take. To take course 1 you should have
// finished course 0, and to take course 0 you should also have finished course
// 1. So it is impossible.
//
// Note:
//
//     The input prerequisites is a graph represented by a list of edges, not
//     adjacency matrices. Read more about how a graph is represented.  
//     You may assume that there are no duplicate edges in the input prerequisites.
//

class Solution {
  private:
    bool is_dag_kahn( const vector<vector<int>> & g, int ecnt ){
      vector<int> indeg(g.size(),0);
      for( const vector<int> & v : g ){
        for( int u : v ){
          indeg[u] ++;
        }
      }
      queue<int> Q;
      for( int i = 0; i < indeg.size(); ++i ){
        if( indeg[i] == 0 ) Q.push(i);
      }
      while( !Q.empty() ){
        int x = Q.front();
        Q.pop();
        for( int u : g[x] ){
          indeg[u] --;
          ecnt --;
          if( indeg[u] == 0 ) Q.push(u);
        }
      }
      return ecnt == 0;
    }
    
    bool dfs( int idx, 
        vector<int8_t> & is_visited,
        vector<int8_t> & tmp_visited,
        const vector<vector<int>> & g ){
      if( tmp_visited[idx] ) return false;
      tmp_visited[idx] = true;
      for( int u : g[idx] ){
        if( !dfs( u, is_visited, tmp_visited, g ) ) 
          return false;
      }
      is_visited[idx] = true;
      tmp_visited[idx] = false;
      return true;
    }


    bool is_dag_tarjan( const vector<vector<int>> & g, int ecnt ){
      vector<int8_t> is_visited(g.size(), false);
      for( int i = 0; i < g.size(); ++i ){
        if( !is_visited[i] ){
          vector<int8_t> tmp_visited(g.size(),false);
          if( !dfs( i, is_visited, tmp_visited, g ) ) return false;
        }
      }
      return true;
    }
     

  public:
    bool canFinish(int n, vector<pair<int, int>>& e) {
      vector<vector<int>> g(n);
      for( const pair<int,int> & p : e ){
        g[p.second].push_back(p.first);
      }
      return is_dag_tarjan( g, e.size() );
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n,m; cin >> n >> m;
  vector<pair<int,int>> v(m);
  forall(i,0,m){
    cin >> v[i].first >> v[i].second;
  }
  Solution s;
  cout << s.canFinish( n, v ) << '\n';

  return 0;
}
