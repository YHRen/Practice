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
    int maximalSquare(vector<vector<char>>& matrix){
      if( matrix.empty() ) return 0;
      int ans = *max_element( all(matrix[0]) ) == '1';
      int n = matrix.size();
      int m = matrix[0].size();
      vi pre(m);
      forall(i,0,m) pre[i] = matrix[0][i] == '1';
      forall( i, 1, n ){
        vi cur(m, 0);
        forall( j, 0, m ){
          if( matrix[i][j] == '1' ){
            if( j == 0 ){ 
              cur[j] = 1 ;
            }else{
              cur[j] = min( cur[j-1], min( pre[j], pre[j-1] ) ) + 1;
            }
          }
        }
        ans = max(ans, *max_element( all(cur) ) );
        swap(pre,cur);
      }
      return ans * ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m ; cin >> n >> m;
  vector<vector<char>> mtx(n, vector<char>(m));
  for( auto & v : mtx ) input(v);
  Solution sol;
  cout << sol.maximalSquare( mtx ) << '\n';

  return 0;
}
