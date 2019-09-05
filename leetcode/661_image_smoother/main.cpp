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
  int n,m;
//  vi dx, dy;
  constexpr static int dx[8] = {-1,0,1,0, -1, 1, 1, -1};
  constexpr static int dy[8] = {0,-1,0,1, -1, 1, -1, 1};
  bool C( int x, int y ){
    return x < n and x >= 0 and y < m and y >= 0;
  }

  int smth( int x, int y, const vvi & M ){
    int cnt = 1, res = M[x][y];
    forall(i,0,8){
      int xx = x + dx[i], yy = y + dy[i];
      if( C(xx,yy) ){
        cnt ++;
        res += M[xx][yy];
      }
    }
    return res/cnt;
  }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
      n = sz(M), m = sz(M[0]);
      vvi res = M;
 //     dx = {-1,0,1,0, -1, 1, 1, -1};
 //     dy = {0,-1,0,1, -1, 1, -1, 1};
      forall(i,0,n) forall(j,0,m) res[i][j] = smth(i,j,M);
      return res;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}