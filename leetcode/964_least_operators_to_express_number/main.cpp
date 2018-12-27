#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
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
typedef long long ll;

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
  unordered_map<ll,int> dp;
  vector<ll> u;
  int X;
  int rec( ll n ){
    if( n == 0 ) return 0;
    if( dp.find(n) != dp.end() ) return dp[n];

    ll g = 1;
    int cnt = 0;
    while( g*X < n ){
      g *= X;
      cnt ++;
    }
    
    int p = (cnt==0?2:cnt) + rec( n - g ); // pos
    debug("n, p",n ,p);
    if(g<n && g*X-n < n ){
      int q = 1 + cnt + rec( g*X - n ); // neg
      p = min(p,q);
    }
    debug("assing ", n, " as ", p);
    dp[n] = p;
    return p;
  }

public:
    int leastOpsExpressTarget(int x, int target) {
      // x>=2, 1<=t<=2*10^8
      X = x;
      return rec(target) -1;
        
    }
};
int main( int argc, char * argv[] ){
  int x,n;cin >> x >> n;
  Solution sol;
  cout << sol.leastOpsExpressTarget(x,n) << '\n';

  return 0;
}
