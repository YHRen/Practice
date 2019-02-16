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
    int shortestPathLength(vector<vector<int>>& g) {
      int n = g.size();
      if( n == 0 ) return 0;
      int t = (1<<n)-1;
      vvi dp(n, vi(1<<n,-1));
      queue<ii> Q;
      forall(i,0,n){
        dp[i][1<<i] = 0;
        Q.push(mp(i,1<<i));
      }
      while( !Q.empty() ){
        auto p = Q.front(); Q.pop();
        int x = p.first, state = p.second;
        int d = dp[x][state];
        for(auto y : g[x]){
          int ns = state | (1<<y);
          if( ns == t ) return d+1;
          if( dp[y][ns] == -1 ){
            dp[y][ns] = 1 + d ;
            Q.push(mp(y,ns));
          }
        }
      }
      return 0;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  cin.ignore(256, '\n');
  vvi g(n);
  string str;
  int i = 0;
  while( getline(cin, str) ){
    debug("str=",str);
    istringstream iss(str);
    string tmp;
    while(iss>>tmp){
      g[i].pb(stoi(tmp));
    }
    i++;
  }
  debug("graph=");
  for(auto v : g ){
    print_(v);
  }
  debug("==========");
  Solution sol;
  cout << sol.shortestPathLength(g) << '\n';

  return 0;
}

/*
An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.

graph.length = N, and j != i is in the list graph[i] exactly once, if and only if nodes i and j are connected.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

 

Example 1:

Input: [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]

Example 2:

Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]

 

Note:

    1 <= graph.length <= 12
    0 <= graph[i].length < graph.length
*/
