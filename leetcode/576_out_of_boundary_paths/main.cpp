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
  int64_t ans;
  void add(int x){
    ans += x; 
    ans %= INF;
  }
  public:
    int findPaths(int n, int m, int N, int i, int j) {
      vvi b1, b2;
      b1.resize(n, vi(m, 0) );
      b1[i][j] = 1;
      ans = 0;
      while( N-- ){
        b2 = b1;
        forall(i,0,n){
          forall(j,0,m){
            if( b2[i][j] ){
              b1[i][j] = 0;
              int x = b2[i][j];
              if( i == 0 ) add(x);
              else{ b1[i-1][j] += x; b1[i-1][j] %= INF;}
              if( i == n-1 ) add(x);
              else{ b1[i+1][j] += x; b1[i+1][j] %= INF;}
              if( j == 0 ) add(x);
              else{ b1[i][j-1] += x; b1[i][j-1] %= INF;}
              if( j == m-1 ) add(x);
              else{ b1[i][j+1] += x; b1[i][j+1] %= INF;}
            }
          }
        }
      }
      return ans;

    }
};
int main( int argc, char * argv[] ){
  int n,m,N,i,j;
  cin >> n >> m >> N >> i >> j;
  Solution sol;
  cout << sol.findPaths(n, m, N, i, j) << '\n';

  return 0;
}
