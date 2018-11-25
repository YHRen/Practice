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
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  void update_neighbor( int x, int y, int n, queue<ii> & Q, vvi & dist, const vvi & A ){
    if( x >= 0 && y >= 0 && x < n && y < n && dist[x][y] == INF && A[x][y] == 1 ){
      Q.push( mp(x,y));
      dist[x][y] = 0;
    }
  }
  bool search_neighbor( int x, int y, int n, int d, queue<ii> & Q, vvi & dist, const vvi & A ){
    if( x >= 0 && y >= 0 && x < n && y < n && dist[x][y] == INF ){
      if( A[x][y] == 0 ){
        dist[x][y] =  d+1;
        Q.push(mp(x,y));
      }else{ 
        //found
        return true;
      }
    }
    return false;
  }
        
public:
    int shortestBridge(vector<vector<int>>& A) {
      int n = A.size();
      for( auto v : A ){
        print_(v);
      }
      debug("n",n);
      vvi dist(n, vi(n, INF));
      {
        bool flag = false;
        forall(i,0,n){
          forall(j,0,n){
            if( A[i][j] == 1 ){
              dist[i][j] = 0;
              queue<ii> Q;
              Q.push(mp(i,j));
              while(!Q.empty()){
                auto x = Q.front(); Q.pop();
                auto xx = x.first, yy = x.second;
                update_neighbor( xx-1, yy, n, Q, dist, A);
                update_neighbor( xx+1, yy, n, Q, dist, A);
                update_neighbor( xx, yy-1, n, Q, dist, A);
                update_neighbor( xx, yy+1, n, Q, dist, A);
              }
              flag = true;
              break;
            }
          }
          if( flag ) break;
        }
      }
      for( auto v : dist ){
        print_(v);
      }

      queue<ii> Q;
      forall(i,0,n){
        forall(j,0,n){
          if( dist[i][j] == 0 ){
            Q.push(mp(i,j));
          }
        }
      }
      debug("qsize", Q.size());
      while( !Q.empty() ){
        auto tmp = Q.front(); Q.pop();
        auto x = tmp.first, y = tmp.second;
        int d = dist[x][y];
        if( search_neighbor(x-1, y, n, d, Q, dist, A ) ) return d;
        if( search_neighbor(x+1, y, n, d, Q, dist, A ) ) return d;
        if( search_neighbor(x, y-1, n, d, Q, dist, A ) ) return d;
        if( search_neighbor(x, y+1, n, d, Q, dist, A ) ) return d;
        
      for( auto v : dist ){
        print_(v);
      }
      debug("qsze",Q.size());
      }

      return -1;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vvi g(n, vi(n));
  for( auto & v : g ) input(v);
  Solution sol;
  cout << sol.shortestBridge(g) << '\n';


  return 0;
}
