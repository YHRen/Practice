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
    int rangeBitwiseAnd(int m, int n) {
      return  m < n ? ( rangeBitwiseAnd( m/2, n/2 ) << 1 ) :m;
    }
    int rangeBitwiseAnd2(int m, int n ){
      int sft = 0;
      while( m<n ){
        m /= 2;
        n /= 2;
        sft ++;
      }
      return m << sft;
    }
};
int main( int argc, char * argv[] ){
  int m,n; cin >> m >> n;
  Solution sol;
  cout << sol.rangeBitwiseAnd(m,n) << '\n';
  cout << sol.rangeBitwiseAnd2(m,n) << '\n';
  int x;
  for( int i = x = m; i < n+1; ++i ){
    x &= i;
  }
  cout << x << '\n';




  return 0;
}
