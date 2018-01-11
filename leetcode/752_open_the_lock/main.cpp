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
    set<int> dead;
    vi get_neighbors( int x ){
      vi v;
      debug(x);
      forall(i,0,4){
        v.pb(x%10);
        x /= 10;
      }
      print_(v);
      vi ans;
      forall(i,0,4){
        int a,b; a = b = v[i];
        a += 1; a %= 10;
        b -= 1; b += 10; b %= 10;
        int y = 0, z = 0;
        for( int j = 3; j >= 0; --j){
          if( j != i ){
            y += v[j];
            z += v[j];
          }else{
            y += a;
            z += b;
          }
          y *= 10;
          z *= 10;
        }
        y /= 10;
        z /= 10;
        ans.pb(y);
        ans.pb(z);
      }
      return ans;
    }
  
  public:
    int openLock(vector<string>& deadends, string target) {
      const int T = stoi( target );
      if( T == 0 ) return 0;
      vi dist(10000, -1);
      for( const auto & d : deadends ){
        dist[stoi(d)] = INF;
      }
      if( dist[0] == INF ) return -1;
      dist[0] = 0;
      queue<int> Q;
      Q.push(0);
      while(!Q.empty()){
        auto x = Q.front(); Q.pop();
        auto nei = get_neighbors(x);
        for( auto u : nei ){
          if( u == T ) return dist[x] + 1;
          if( dist[u] == -1 ){
            dist[u] = dist[x] + 1;
            Q.push(u);
          }
        }
      }
      return -1;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
