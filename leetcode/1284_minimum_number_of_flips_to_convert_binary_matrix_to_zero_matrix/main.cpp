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
  int n,m,N;
  vi dp;
  int flip(const int cur, const int loc){
    int res = cur;
    res ^= (1<<loc);
    if( loc-m >= 0 ) res ^= (1<<(loc-m)); // up
    if( loc+m < N ) res ^= (1<<(loc+m)); // down
    if( loc%m!=0 ) res ^= (1<<(loc-1)); //left
    if( (loc+1)%m!=0 and (loc+1<N) ) res ^= ( 1<<(loc+1)); // right
    return res;
  }

  public:
    int minFlips(vector<vector<int>>& mat) {
      n = sz(mat), m = sz(mat[0]);
      N = n*m;
      if( n==1 and m == 1) return mat[0][0]==1 ? 1 : 0;
      dp.resize(1<<N,INF);
      int init_state = 0;
      forall(i,0,N){
        if( mat[i/m][i%m] == 1 ){
          init_state |= (1<<i);
        }
      }
      dp[init_state] = 0;
      queue<int> Q;
      Q.push(init_state);
      while( !Q.empty() ){
        int k = sz(Q);
        trace(k, bitset<9>(k));
        while(k--){
          int x = Q.front(); Q.pop();
          trace(x);
          forall(i,0,N){
            int nxt = flip(x,i);
            trace(bitset<9>(nxt));
            if( nxt == 0 ) return dp[x]+1;
            if( dp[nxt] == INF) {
              dp[nxt] = dp[x] + 1;
              Q.push(nxt);
            }
          }
        }
      }
      return -1;
    }
};

int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m; 
  vvi mtx(n, vi(m));
  for(auto & v : mtx) input(v);
  Solution sol;
  cout << sol.minFlips(mtx) << endl;
  return 0;
}
