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
  map<ii,ll> dp;
  ll solve( int x, int y ){
    if( x < 0 || y < 0 || abs(x-y) > 2 ) return 0;
    auto itr = dp.find(mp(x,y));
    if( itr != dp.end() ) return itr->second;
    ll ans = 0;
    if( x != y ){
      if( x < y ){ 
        ans += solve(x-1, y-2);
        ans %= INF;
        ans += solve(x, y-2);
        ans %= INF;
      }else{ // x > y
        ans += solve(x-2, y-1);
        ans %= INF;
        ans += solve(x-2, y);
        ans %= INF;
      }
    }else{ // x== y
      ans += solve(x-1, y-1);
      ans += solve(x-2, y-1);
      ans += solve(x-1, y-2);
      ans += solve(x-2, y-2);
      ans %= INF;
    }
    return dp[mp(x,y)] = ans;
  }
  public:
    int numTilings(int N) {
      if( N == 1 ) return 1;
      dp[mp(0,0)] = 1;
      dp[mp(1,1)] = 1;
      dp[mp(1,0)] = 0;
      dp[mp(0,1)] = 0;
      dp[mp(2,0)] = 1;
      dp[mp(0,2)] = 1;
      dp[mp(2,1)] = 1;
      dp[mp(1,2)] = 1;
      return solve(N,N);
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  Solution sol;
  cout << sol.numTilings(n) << '\n';

  return 0;
}
