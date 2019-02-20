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
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
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

// std::ios::sync_with_stdio(false);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  public:
    int numFactoredBinaryTrees(vector<int>& A) {
      sort(all(A));
      int n = A.size();
      if( n == 1 ) return 1;
      unordered_map<ll, vii> child_pairs;
      unordered_map<ll, ll> dp;
      forall(i,0,n) dp[A[i]] = -1;
      forall(i,0,n){
        forall(j,i,n){
          ll prd = ll(A[i]) * ll(A[j]);
          if(  prd > ll(*A.rbegin()) ) break;
          if( dp.count(prd) ) child_pairs[prd].pb(mp(A[i], A[j]));
        }
      }
      ll ans = 0;
      forall(i,0,n){
        ll x = A[i];
        dp[x] = 1;
        for(auto p : child_pairs[x]){
          ll tmp = dp[p.first] * dp[p.second];
          if ( p.first != p.second ) tmp *= 2;
          dp[x] += tmp;
          dp[x] %= INF;
        }
        ans += dp[x];
        ans %= INF;
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
