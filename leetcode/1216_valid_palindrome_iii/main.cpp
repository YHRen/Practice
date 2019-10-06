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
  int n;
  vvi dp;
  string str;
  int aux(int l, int r){
    debug("l,r",l,r);
    if( l == r ) return 1;
    if( l > r  ) return 0;
    if( dp[l][r] != -1 ) return dp[l][r];
    if( str[l] == str[r] ){
      return dp[l][r] = 2 + aux(l+1,r-1);
    }else{
      return dp[l][r]= max(aux(l+1,r), aux(l,r-1));
    }
  }
  public:
    bool isValidPalindrome(string s, int k) {
      n = sz(s);
      str = s;
      dp.resize(n);
      for(auto & v : dp) v.resize(n,-1);
      int ans = aux(0, n-1);
      debug("ans=",ans);
      return n-ans <= k;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  string str; cin >> str;
  Solution sol;
  cout << sol.isValidPalindrome(str,n) << endl;
  return 0;
}
