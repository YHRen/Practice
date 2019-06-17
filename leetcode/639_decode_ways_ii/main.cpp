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
  int n;
  public:
    int numDecodings(string s) {
      if( s.empty() or s[0] == '0' ) return 0;
      n = sz(s);
      vll dp(n+1,0);
      dp[n] = 1;

      if( s[n-1] == '*' ){ dp[n-1] = 9; }
      else dp[n-1] = (s[n-1]=='0' ? 0 : 1);

      for(int i = n-2; i >= 0; --i ){
        if( s[i] == '0' ){
          //dp[i] = dp[i+1];
          dp[i] = 0;
        }else if( s[i] == '1' ){
          if( s[i+1] == '*' ){
            dp[i] = dp[i+1] + dp[i+2]*9;
          }else{
            dp[i] = dp[i+1] + dp[i+2];
          }
        }else if( s[i] == '2' ){
          dp[i] = dp[i+1];
          if( s[i+1] == '*' ){
            dp[i] +=  dp[i+2]*6;
          }else if( (s[i+1]-'0') < 7 ){
            // 2[0-6]
            dp[i] +=  dp[i+2];
          }
        }else if( s[i] == '*' ){
          dp[i] = dp[i+1]*9;
          if( s[i+1] == '*' ){
            dp[i] +=  dp[i+2]*15 ;
          }else if( (s[i+1]-'0') < 7 ){
            dp[i] +=  dp[i+2]*2 ;
          }else{
            dp[i] += dp[i+2] ;
          }
        }else{ // s[i] == '3' '4' ... '9'
          dp[i] = dp[i+1];
        }
        dp[i] %= INF;
      }
      print_(dp);
      return dp[0];
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  cout << sol.numDecodings(str) << endl;
  return 0;
}
