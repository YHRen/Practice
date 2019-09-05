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
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
      int n = sz(s);
      vvi dp(26);
      forall(i,0,n) dp[s[i]-'a'].pb(i);
      vector<bool> ans;
      for(const auto & q : queries){
        int l = q[0], r = q[1], k = q[2];
        debug("query", l, r, k);
        int odd = 0;
        forall(i,0,26){
          if( dp[i].empty() ) continue;
          int cnt = upper_bound(all(dp[i]),r) - lower_bound(all(dp[i]),l);
          debug("i = ",i, "cnt=",cnt)
          if( cnt % 2 == 1 ) odd ++;
        }
        if( k >=  odd/2 ) ans.pb(true);
        else ans.pb(false);
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  int n; cin >> n; 
  vvi mtx(n, vi(3));
  for(auto & v : mtx) input(v);
  Solution sol;
  auto ans = sol.canMakePaliQueries(str, mtx);
  forall(i,0,n) clog << int(ans[i]) << ' ';
  clog << endl;
  return 0;
}
