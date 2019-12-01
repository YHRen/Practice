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
public:
    int countSquares(vector<vector<int>>& mtx) {
      int n = sz(mtx), m = sz(mtx[0]);
      vvi cumsum(n+1, vi(m+1,0));
      forall(i,0,n){
        forall(j,0,m){
          cumsum[i+1][j+1] = cumsum[i+1][j] + cumsum[i][j+1] + mtx[i][j] - cumsum[i][j];
        }
      }
      for(auto & v : cumsum){ print_(v); }

      int ans = 0;
      forall(i,0,n){
        forall(j,0,m){
          forall(k,1,min(n,m)+1){
            if( i+k <= n and j+k <=m ){
              int tmp = cumsum[i+k][j+k] - cumsum[i][j+k] - cumsum[i+k][j] + cumsum[i][j];
              trace(i,j,k,tmp);
              if( tmp == k*k ) ans ++;
            }
          }
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n, m; cin >> n >> m; 
  vvi mtx(n, vi(m));
  for(auto & v : mtx ) input(v);
  Solution sol;
  cout << sol.countSquares(mtx) << endl;
  return 0;
}
