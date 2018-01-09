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
    vector<int> countBits(int n) {
      if( n == 0 ) return vi({0});
      if( n == 1 ) return vi({0,1});
      if( n == 2 ) return vi({0,1,1});
      vi v(n+1);
      v[0] = 0; v[1] = 1; v[2] = 1;
      int b = 2;
      forall(i,3,n+1){
        if( (i & (i-1)) == 0 ){
          v[i] = 1;
          b <<= 1;
        }else{
          v[i] = v[b] + v[i-b];
        }
      }
      return v;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  Solution sol;
  auto ans = sol.countBits(n);
  print_(ans);

  return 0;
}
