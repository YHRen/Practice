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
public:
    int minFallingPathSum(vector<vector<int>>& A) {
      int n = A.size();
      vi v(n,0), u(n,0);
      forall(i,0,n) v[i] = A[0][i];
      forall(t,1,n){
        forall(i,0,n){
          if( i == 0 ){
            u[i] = A[t][i] + min( v[i], v[i+1] );
          }else if( i == n-1 ){
            u[i] = A[t][i] + min( v[i], v[i-1] );
          }else{
            u[i] = A[t][i] + min( v[i-1], min( v[i], v[i+1] ));
          }
        }
        swap(u,v);
      }

      return *min_element(all(v));
        
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vvi mtx(n);
  for( auto & v: mtx ){ v.resize(n); input(v);}
  Solution sol;
  cout << sol.minFallingPathSum(mtx) << '\n';

  return 0;
}
