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
  int n,m;
  vvi cum;
  bool C(int k, const int T){
    forall(i,0,n-k+1){
      forall(j,0,m-k+1){
        if( cum[i+k][j+k] - cum[i][j+k] - cum[i+k][j] + cum[i][j] <= T ) return true;
      }
    }
    return false;
  }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
      n = sz(mat), m = sz(mat[0]);
      cum.resize(n+1);
      for(auto & v : cum) v.resize(m+1);
      forall(i,0,n) forall(j,0,m)
          cum[i+1][j+1]= -cum[i][j] + cum[i+1][j] + cum[i][j+1] + mat[i][j];
      for(auto & v : cum){ print_(v);}

      int lo = 1, hi = min(n,m)+1, ans=0;
      while(lo<hi){
        int mid = (lo+hi) /2;
        trace(mid);
        if( C(mid, threshold) ){
          ans = mid;
          lo = mid+1;
        }else{
          hi = mid;
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m,t; cin >> n >> m >> t;
  vvi mtx(n, vi(m));
  for(auto & v : mtx) input(v);
  Solution sol;
  cout << sol.maxSideLength(mtx, t) << endl;
  return 0;
}
