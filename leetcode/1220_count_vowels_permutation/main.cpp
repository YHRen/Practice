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
typedef vector<ll>       vll;
typedef vector<vll>      vvll;


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
  vvll dp;
  public:
    int countVowelPermutation(int n) {
      // a:0 e:1 i:2 o:3 u:4
      vvll dp(5, vll(n,0));
      forall(i,0,5) dp[i][0] = 1;
      forall(i,1,n){
        dp[0][i] += dp[4][i-1];
        dp[0][i] += dp[2][i-1];
        dp[0][i] += dp[1][i-1];
                              ;
        dp[1][i] += dp[0][i-1];
        dp[1][i] += dp[2][i-1];
                              ;
        dp[2][i] += dp[1][i-1];
        dp[2][i] += dp[3][i-1];
                              ;
        dp[3][i] += dp[2][i-1];
                              ;
        dp[4][i] += dp[2][i-1];
        dp[4][i] += dp[3][i-1];

        forall(j,0,5){ dp[j][i] %= INF; }
      }

      ll ans = 0;
      forall(j,0,5){ ans += dp[j][n-1]; }
      return ans %=INF;

    }
};

int main( int argc, char * argv[] ){
  int n; cin >> n; 
  Solution sol;
  cout << sol.countVowelPermutation(n) << endl;
  
  return 0;
}
