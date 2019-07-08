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
#include <complex>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF              (int)1000000007
#define EPS              1e-9
#define pb               push_back
#define mp               make_pair
#define all(c)           c.begin(), c.end()
#define forall(i,a,b)    for(int i=a;i<(b);++i)
#define trav(a,x)        for(auto & a: x)
#define in(a,b)          ((b).find(a) != (b).end())
#define sz(c)            (int)(c).size()
#define input(a)         for(auto & x : a) cin >> x;

using namespace std;

typedef vector<int>      vi;
typedef pair<int,int>    ii;
typedef vector<vi>       vvi;
typedef vector<ii>       vii;
typedef long long        ll;

#ifdef DEBUG
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
  public:
    int maxProfit(vector<int>& prices, int K) {
      int n = sz(prices);
      if( n < 2 ) return 0;
      vvi dp(K+1, vi(n,0));
      forall(k,1,K+1){
        int min_val = prices[0];
        debug("k=",k);
        print_(dp[k-1]);
        forall(i,1,n){
          min_val = min(min_val, prices[i] - dp[k-1][i-1]);
          debug("i=",i,"min_val=",min_val);
          dp[k][i] = max(dp[k][i-1], prices[i] - min_val);
        }
      }
      return dp[K][n-1];
    }
    int maxProfit(vector<int>& prices) {
      int n = sz(prices);
      if( n < 2 ) return 0;
      vvi dp(3, vi(n,0));
      forall(k,1,3){
        int min_val = prices[0];
        forall(i,1,n){
          min_val = min(min_val, prices[i] - dp[k-1][i-1]);
          dp[k][i] = max(dp[k][i-1], prices[i] - min_val);
        }
      }
      return dp[2][n-1];
    }
};
int main( int argc, char * argv[] ){
  int n,k; cin >> n >> k; 
  vi v(n); input(v);
  Solution sol;
  cout << sol.maxProfit(v, k) << endl;
  return 0;
}
