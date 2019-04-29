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
  vvi dp;
  vi  v;
  int n;
  int calc(int x) {
    return v[x] * (x - 1 >= 0 ? v[x - 1] : 1) * (x + 1 < n ? v[x + 1] : 1);
  }
  int calc( int x, int l, int r ){
    return v[x]* (l >= 0 ? v[l]:1) * (r<n?v[r]:1);
  }
  int solve( int l, int r ){
    if( l > r ) return 0;
    if( l == r ) return calc(l);
    if( dp[l][r] != INF ) return dp[l][r];
    int run = 0;
    forall(i,l,r+1){ // try 
      int tmp = calc(i, l-1, r+1) + solve(l, i-1) + solve(i+1,r);
      run = max(run, tmp);
    }
    dp[l][r] = run; 
    return run;
  }
public:
    int maxCoins(vector<int>& nums) {
      v = nums;
      n = sz(v);
      if( n == 0 ) return 0;
      if( n == 1 ) return v[0];
      dp.resize(n, vi(n,INF));
      return solve(0,n-1);
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  Solution sol;
  cout << sol.maxCoins(v) << endl;
  return 0;
}
