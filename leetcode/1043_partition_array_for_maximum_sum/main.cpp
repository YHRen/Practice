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
  int n, k;
  vi  v;
  vi  dp;

  int get_cum( int l, int r ){
    int mx = *max_element(v.begin()+l, v.begin()+r);
    int res = 0;
    for(int i = l; i < r; ++i ){
      res += mx-v[i];
    }
    return res;
  }
  int aux(int x){
    if( x >= n ) return 0;
    if( dp[x] != -1 ) return dp[x];
    int res = 0;
    for( int i = x; i < x+k and i < n; ++i ){
      int p = get_cum(x,i+1) + aux(i+1);
      res = max(res,p);
    }
    return dp[x] = res;
  }

public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
      v = A;
      n = sz(A);
      k = K;
      dp.resize(n,-1);
      {
        dp[n-1] = 0;
        for(int i = n-2; i >= n-k; --i ){
          dp[i] = get_cum(i,n);
        }
      }
      print_(dp);
      return aux(0) + accumulate(all(A),0);
    }
};
int main( int argc, char * argv[] ){
  int n, m; cin >> n >> m; 
  vi v(n); input(v);
  Solution sol;
  cout << sol.maxSumAfterPartitioning( v, m ) << '\n';
  return 0;
}
