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
    vector<int> maxSumOfThreeSubarrays(vector<int>& v, int k) {
      int n = v.size();
      int K = 3;
      vvi dp(K,vi(n,0));
      vvi pre(K,vi(n,0));
      vi  cums(n,0); cums[0] = v[0];
      forall(i,1,n) cums[i] = cums[i-1]+v[i];
      forall(t,0,K){
        dp[t][(t+1)*k-1] = cums[(t+1)*k-1];
        pre[t][(t+1)*k-1] = t*k;
        forall(i, (t+1)*k, n){
          int tmp = cums[i] - cums[i-k];
          int r   = t ? dp[t-1][i-k] : 0;
          if( tmp + r > dp[t][i-1] ){
            dp[t][i] = tmp + r;
            pre[t][i] = i-k+1;
          }else{
            dp[t][i] = dp[t][i-1];
            pre[t][i] = pre[t][i-1];
          }
        }
        print_(dp[t]);
        print_(pre[t]);
      }
      vi ans;
      int a = n-1;
      while(K-->0){
        a = pre[K][a];
        ans.pb(a--);
      }
      reverse(all(ans));
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,k; cin >> n >> k;
  vi v(n);
  input(v);
  Solution sol;
  auto ans = sol.maxSumOfThreeSubarrays(v,k);
  print_(ans);

  return 0;
}
