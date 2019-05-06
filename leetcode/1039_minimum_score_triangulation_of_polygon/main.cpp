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
  vi v;
  vvi dp;
  int n;
  inline int prev( int x ){
    return (x-1+n)%n;
  }
  inline int next( int x ){
    return (x+1)%n;
  }

  int aux( int l, int r ){
    if( next(l) == r or l == r or prev(l) == r ) return 0;
    debug("aux", l, r);
    if( dp[l][r] != -1 ) return dp[l][r];
    int res = INF;
    for(int k = next(l); k != r; k = next(k)){
      res = min( res, v[k]*v[l]*v[r] + aux(l,k) + aux(k,r));
    }
    debug("dp", l, r, l%n, r%n, res );
    return dp[l][r] = res;
  }

public:
    int minScoreTriangulation(vector<int>& A) {
      n = sz(A);
      v = A;
      dp.resize(n, vi(n,-1));
      int ans = INF;
      forall(i,0,n){
        forall(j,i+1,n){
          forall(k,j+1,n){
            int tmp = aux(i,j) + aux(j,k) + aux(k,i) + v[i]*v[j]*v[k];
            debug("ijk",i,j,k,tmp);
            ans = min(ans, tmp);
          }
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  Solution sol;
  cout << sol.minScoreTriangulation(v) << endl;
  return 0;
}
