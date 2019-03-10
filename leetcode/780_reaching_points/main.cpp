#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
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

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<(b);++i)
#define trav(a,x)                   for(auto & a: x)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define sz(c)                       (int)(c).size()
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

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

auto ____ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  int s,t;
  bool reduce( ii  xy ){
    int x = xy.first, y = xy.second;
    debug("x,y",x,y);
    if( s > x or t > y ) return false;
    if( s == x and t == y ) return true;
    if( s == x ) return (y-t)%s==0;
    if( t == y ) return (x-s)%t==0;
    if( x < y ){
      if( y%x == 0 ) return x==s and t%s==0 and t>=y;
      else return reduce( mp(x, y%x) );
    }else if( x > y ){
      if( x%y == 0 ) return y==t and s%t==0 and x>=s;
      else return reduce( mp(x%y, y) );
    }else{
      return false; 
    }
  }
  public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
      s = sx, t = sy;
      return reduce(mp(tx,ty));
    }
};
int main( int argc, char * argv[] ){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  Solution sol;
  cout << sol.reachingPoints(a,b,c,d) << '\n';

  return 0;
}
