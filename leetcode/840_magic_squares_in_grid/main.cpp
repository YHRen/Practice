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
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF                         (int)1000000007
#define EPS                         1e-9

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

#ifdef DEBUG
#define debug(args...)            {dbg,args; clog<<endl;}
#define print_( a )               for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )           for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)             // Just strip off all debug tokens
#define print_( a )               // skip
#define printPair_( a )           // skip
#endif
struct debugger
{
  template<typename T> debugger& operator , (const T& x)
  {    
    clog << x << " ";    
    return *this;    
  }
} dbg;

// std::ios::sync_with_stdio(false);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  int n,m;
  vvi mtx;
  vi cnt, row, col;
  bool C(const int x, const int y ){
    cnt.assign(cnt.size(),0);
    row.assign(row.size(),0);
    col.assign(col.size(),0);
    int major = 0, minor = 0;
    forall(i,x,x+3){
      forall(j,y,y+3) {
        debug("i,j",i,j,x,y,x+3,y+3);
        if( i == n or j ==m ) debug("ERROR: ", i,j);
        int w = mtx[i][j];
        if(w == 0 || w > 9 || cnt[w] ){
          return false;
        }
        cnt[w] =1;
        row[i-x] += w;
        col[j-y] += w;
        if( i-x == j-y ) major += w;
        if( x+2-i == j-y ) minor += w;
      }
    }
    debug("major = ", major, "minor = ", minor );
    if( major == minor ){
      for(auto w : row) if( w!= major ) return false;
      for(auto w : col) if( w!= major ) return false;
      return true;
    }
    return false;
  }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
      mtx = grid;
      cnt.resize(10);
      row.resize(3);
      col.resize(3);
      n = grid.size(), m = grid[0].size();
      debug("n,m",n,m);
      int ans = 0;
      forall(i,0,n-2){
        forall(j,0,m-2){
          debug(">>>>>> i,j", i, j, mtx[i][j]);
          if( C(i,j) ) ans ++;
          else{ debug("return false  == ");}
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >>m;
  vvi mmm(n, vi(m));
  for(auto & v : mmm ) input(v);
  Solution sol;
  cout << sol.numMagicSquaresInside(mmm) << '\n';

  return 0;
}
