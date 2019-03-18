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
  int n ;
  int goal;
  int rec(ll x, int d, int mask ){
    if( d > 10 ) return 0;
    if( x > n ) return 0;
    if( mask == goal ) return 0; //used up
    int res = 1;
    forall(i,0,10){
      if( ( mask & (1<<i) ) ) continue;
      else{
        res += rec( x*10 + i, d+1, (mask | (1<<i)) );
      }
    }
    return res;
  }

public:

    int numDupDigitsAtMostN(int N) {
      n = N;
      goal = (1<<10)-1;
      int ans = 0;
      forall(i,1,10){
        ans += rec(i, 1, 0|(1<<i));
      }
      return N-ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  Solution sol;
  cout << sol.numDupDigitsAtMostN(n) << '\n';

  return 0;
}
