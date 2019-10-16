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
typedef vector<vvi>      vvvi;
typedef long long        ll;

#ifdef DEBUG
#define trace(...)       __f(#__VA_ARGS__, __VA_ARGS__)
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

template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << ": " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " |";
    __f(comma + 1, args...);
}

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
  vi M;
  vvvi dp;
  int n;
  int solve(int r, int prv, int cnt){
    if( r == n ) return 1;
    if( dp[r][prv][cnt] != -1 ) return dp[r][prv][cnt];
    
    ll ans = 0;
    forall(i,0,6){
      if( i == prv and M[i] == cnt ) continue;
      else if( i == prv ){
        ans += solve(r+1, i, cnt+1);
      }else{
        ans += solve(r+1, i, 1);
      }
      ans %= INF;
    }
    return dp[r][prv][cnt]=ans;
  }


  public:
    int dieSimulator(int n, vector<int>& rollMax) {
      M = rollMax;
      this->n = n;
      dp.resize(n);
      for(auto & mtx : dp ){
        mtx.resize(6);
        for(auto & v : mtx ) v.resize(16, -1);
      }

      ll ans = 0;
      forall(i,0,6){
        ans += solve(1,i,1);
        ans %= INF;
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n, m; cin >> n >> m; 
  vi v(n); input(v);
  Solution sol;
  cout << sol.dieSimulator(m, v) << endl;
  return 0;
}
