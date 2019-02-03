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
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
      vvi g(N);
      for(auto & e : dislikes ){
        int x = e[0]-1, y = e[1]-1;
        g[x].pb(y);
        g[y].pb(x);
      }

      vi color(N, -1);
      forall(i,0,N){
        if( color[i] == -1 ){
          queue<int> Q;
          color[i] = 1;
          Q.push(i);
          while(!Q.empty()){
            int x = Q.front(); Q.pop();
            for(auto y : g[x]){
              if( color[y] == -1 ){
                color[y] = !color[x];
                Q.push(y);
              }else if( color[y] == color[x] ){
                return false;
              }
            }
          }
        }
      }
      return true;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
