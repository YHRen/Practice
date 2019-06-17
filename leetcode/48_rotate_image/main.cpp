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
  int n;
  void do_swap(vvi & mtx, int x, int y){
    swap( mtx[x][y], mtx[y][n-x-1] );
    swap( mtx[x][y], mtx[n-x-1][n-y-1] );
    swap( mtx[x][y], mtx[n-y-1][x] );
  }
  public:
    void rotate(vector<vector<int>>& matrix) {
      n = sz(matrix);
      if( n <= 1 ) return;
      reverse(all(matrix));
      forall(i,0,n){
        forall(j,0,i){
          swap(matrix[i][j], matrix[j][i]);
        }
      }
    }
    void rotate_slow(vector<vector<int>>& matrix) {
      n = sz(matrix);
      if( n<= 1) return;
      forall(i,0,n/2){
        forall(j,i,n-i-1){
          debug("swap",i,j);
          do_swap(matrix,i,j);
          for(auto & v : matrix){ print_(v); }
        }
      }
      return;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vvi mtx(n,vi(n)); for(auto & v : mtx ){ input(v); }
  Solution sol;
  sol.rotate(mtx);
  for(auto & v : mtx){ print_(v); }
  return 0;
}
