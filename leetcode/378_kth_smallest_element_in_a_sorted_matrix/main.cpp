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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int n = matrix.size();
      int m = matrix[0].size();
      auto cmp = [&matrix]( const ii & lhs, const ii & rhs ){
        return matrix[lhs.first][lhs.second] > matrix[rhs.first][rhs.second];
      };
      priority_queue<ii, vii, decltype(cmp)> Q(cmp);
      Q.push( mp(0,0) );
      int ans;
      while( !Q.empty() && k-- ){
        auto p = Q.top(); Q.pop();
        int i = p.first, j = p.second;
        ans = matrix[i][j];
        if( j+1 < m ){
          Q.push( mp( i, j+1 ) );
        }
        if( j==0 && i+1 < n ){
          Q.push( mp( i+1, j ) );
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m,k; cin >> n >> m >> k;
  vvi mtx(n,vi(m));
  for( auto & v : mtx )
    for( auto & x : v )
      cin >> x;
  Solution sol;
  cout << sol.kthSmallest(mtx,k) << '\n';

  return 0;
}
