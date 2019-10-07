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

    int change(int amount, vector<int>& coins) {
      if( coins.empty() ) return amount ? 0 : 1;
      sort(all(coins));
      coins.erase( unique( all( coins ) ), coins.end() );
      int n = sz(coins);
      vi dp(amount+1, 0);
      dp[0] = 1;
      for(auto x : coins){
        forall(i,1,amount+1){
          if( i - x >= 0 ){
            dp[i] += dp[i-x];
          }
        }
      }
      return dp.back();
    }

    int change_using_upper_limit(int amount, vector<int>& coins) {
      if( coins.empty() ) return amount ? 0 : 1;
      sort(all(coins));
      coins.erase( unique( all( coins ) ), coins.end() );
      int n = sz(coins);
      vvi dp(amount+1, vi(n, 0) );
      dp[0][0] = 1;
      forall(i,0,amount+1){
        forall(j,0,n){
          if( i + coins[j] <= amount ) dp[i+coins[j]][j] += dp[i][j];
          if( j + 1 < n ) dp[i][j+1] += dp[i][j];
        }
      }
      return dp[amount][n-1];
    }
};
int main( int argc, char * argv[] ){
  int n, t; cin >> n >> t; 
  vi v(n); input(v);
  Solution sol;
  cout << sol.change(t, v) << endl;
  return 0;
}
