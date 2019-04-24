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

class Solution {
  int dist(vi & loc, int r0, int c0){
    return abs( loc[0]-r0 ) + abs(loc[1]-c0);
  }
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
      vvi mtx;
      forall(i,0,R) forall(j,0,C) mtx.pb({i,j});
      sort(all(mtx), [r0,c0](vi lhs, vi rhs){ 
          return 
          ( abs( lhs[0]-r0 ) + abs(lhs[1]-c0) ) <
          ( abs( rhs[0]-r0 ) + abs(rhs[1]-c0) );
          });
      return mtx;
    }
};
int main( int argc, char * argv[] ){
  int R,C,r,c; cin>> R >> C >> r >> c;
  Solution sol;
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
