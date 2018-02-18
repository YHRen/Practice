// #include <bits/stdc++.h>
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
    bool isBipartite(vector<vector<int>>& graph) {
      int n = graph.size();
      vi color(n, -1);
      queue<int> Q;
      forall(i,0,n){
        if( color[i] == -1 ){
          color[i] = 0;
          Q.push(i);
          while(!Q.empty()){
            int x = Q.front(); Q.pop();
            for( auto u : graph[x] ){
              if( color[u] == -1 ){
                color[u] = 1^color[x];
                Q.push(u);
              }else{
                if( color[u] == color[x] ) return false;
              }
            }
          }
        }
      }
      return true;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;


  return 0;
}
