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

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();

int n;
vector<vector<vector<double>>> dp(
    301, vector<vector<double>>(301, vector<double>(301, -1)));

double solve( int x, int y, int z ){
  // x ones, y twos, z threes
  if( dp[x][y][z] > 0.0 ) return dp[x][y][z];
  int w = n - x - y - z;
  double ans = 1.0;
  trace(x,y,z,w,ans);
  if( z > 0 ){
    ans += (double)z / n * solve(x, y+1, z-1);
  }
  if( y > 0 ){
    ans += (double)y / n * solve(x+1, y-1, z);
  }
  if( x > 0 ){
    trace(x,y,z,n,ans,"before x>0");
    ans += (double)x / n * solve(x-1, y, z);
    trace(x,y,z,n,ans,"after x>0");
  }

  trace(x,y,z, n, "before", ans);
  if( w > 0 ){
    ans = ans * (n) / (n-w);
  }
  trace(x,y,z, '=', ans);
  return dp[x][y][z] = ans;
}

int main( int argc, char * argv[] ){
  cin >> n; 
  vector<double> v(n);
  input(v);

  dp[0][0][0] = 0;
  dp[1][0][0] = n;
  trace(dp[1][0][0]);
  vi cnt(3,0);
  for(auto x : v) cnt[x-1]++;
  print_(cnt);
  cout << setprecision(16) << solve(cnt[0], cnt[1], cnt[2]) << endl;

  return 0;
}
