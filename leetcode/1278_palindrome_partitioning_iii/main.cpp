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
class Solution {
  int n, K;
  string str;
  vvi dp, dp2;
  bool is_palindrom(const string& s) {
    forall(i, 0, n / 2) {
      if (s[i] != s[n - i - 1]) return false;
    }
    return true;
  }

  int count_replace(int x, int y) {
    // [x,y) of string
    if (dp2[x][y] != -1) return dp2[x][y];
    if (x == y - 1) return dp2[x][y] = 0;
    int ans = 0, m = y - x;
    forall(i, 0, m / 2) {
      if (str[x + i] != str[x + m - i - 1]) ans++;
    }
    return dp2[x][y] = ans;
  }

  int solve(int x, int k) {
    if (dp[x][k] != -1) return dp[x][k];
    if (k == 1) {
      return dp[x][1] = count_replace(x, n);
    }
    int ans = INF;
    forall(i, x + 1, n) {
      int p = count_replace(x, i);
      int q = p + solve(i, k - 1);
      ans = min(ans, q);
    }
    return dp[x][k] = ans;
  }

  public:
   int palindromePartition(string s, int k) {
     n = sz(s);
     if (n == k) return 0;
     if (k == 1 and is_palindrom(s)) return 0;
     this->K = k;
     this->str = s;
     dp.resize(n);
     for (auto& v : dp) v.resize(k + 1, -1);
     dp2.resize(n);
     for (auto& v : dp2) v.resize(n + 1, -1);
     return solve(0, k);
   }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  string str; cin >> str;
  Solution sol;
  cout << sol.palindromePartition(str, n) << endl;
  return 0;
}
