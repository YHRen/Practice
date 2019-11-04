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
#define trace(...)       __f(#__VA_ARGS__, __VA_ARGS__)
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define trace(...)       
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
    cerr.write(names, comma - names) << ": " << arg1 << " | ";
    __f(comma + 1, args...);
}

auto mini = [](auto &x, const auto & y){ x = min(x,y); };
auto maxi = [](auto &x, const auto & y){ x = max(x,y); };

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
public:
    int minimumMoves(vector<int>& v) {
      int n = sz(v);
      vvi dp(n, vi(n,n));
      for (int L = n - 1; L >= 0; --L) {
        for (int R = L; R < n; ++R) {
          trace(L,R);
          print_(dp[L]);
          if( L==R ){
            dp[L][R] = 1;
            continue;
          }
          if( L+1==R ){
            dp[L][R] = (v[L] == v[R] ? 1 : 2);
            continue;
          }
          mini(dp[L][R], dp[L+1][R-1] + (v[L]==v[R] ? 0 : 2));
          mini(dp[L][R], dp[L+1][R] + 1);
          mini(dp[L][R], dp[L][R-1] + 1);
          forall(i,L+1,R){
            mini(dp[L][R], dp[L][i-1] + dp[i][R]);
          }
          print_(dp[L]);
        }
      }
      return dp[0][n-1];
    }
};

int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  Solution sol;
  cout << sol.minimumMoves(v) << endl;
  return 0;
}
