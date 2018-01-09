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
#define input_( a )               for( auto & x : a ) cin >> x;
#define printPair_( a )           for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)             // Just strip off all debug tokens
#define print_( a )               // skip
#define printPair_( a )           // skip
#define input_( a )               for( auto & x : a ) cin >> x;
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
    int minSubArrayLen(int s, vector<int>& v) {
      int i = 0, j = 0, n = v.size();
      int tot = 0;
      for(;j<n;++j){
        if( tot >= s ) break;
        tot += v[j];
      }
      if( tot < s ) return 0;
      int ans = INF;
      while( 1 ){
        if( tot >= s ) ans = min(ans, j-i );
        while( tot >= s ){
          tot -= v[i++];
        }
        if( tot + v[i-1] >= s ) ans = min( ans, j-i+1 );
        if( j == n ) break;
        while( tot < s && j < n ){
          tot += v[j++];
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,s; cin >> n >> s;
  vi v(n);
  input_(v);
  Solution sol;
  cout << sol.minSubArrayLen(s, v ) << '\n';


  return 0;
}
