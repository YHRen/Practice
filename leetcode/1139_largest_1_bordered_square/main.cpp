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
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
      int n = sz(grid), m = sz(grid[0]);
      vvi rowsum(n, vi(m+1,0)), colsum(m, vi(n+1,0));
      forall(i,0,n){ forall(j,0,m){ rowsum[i][j+1] = rowsum[i][j] + grid[i][j]; } }
      forall(j,0,m){ forall(i,0,n){ colsum[j][i+1] = colsum[j][i] + grid[i][j]; } }
      print_(rowsum[0]);
      print_(rowsum[2]);
      int L = min(n,m);
      while( L > 0 ){
        forall(i,0,n-L+1) forall(j,0,m-L+1){ 
          if( rowsum[i][j+L] - rowsum[i][j]         == L and
              rowsum[i+L-1][j+L] - rowsum[i+L-1][j] == L and
              colsum[j][i+L] - colsum[j][i]         == L and
              colsum[j+L-1][i+L] - colsum[j+L-1][i] == L ) return L*L;
        }
        --L;
      }
      return 0;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m; 
  vvi mtx(n,vi(m));
  for(auto & v : mtx ) input(v);
  Solution sol;
  cout << sol.largest1BorderedSquare(mtx) << endl;
  return 0;
}
