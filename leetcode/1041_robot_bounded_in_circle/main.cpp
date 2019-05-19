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
  int x,y,d;
  vi dx, dy;
  void exec( char c ){
    if( c == 'L' ) d = (d+4-1)%4;
    else if( c == 'R' ) d = (d+1)%4;
    else if( c == 'G' ) x += dx[d], y += dy[d];
  }
public:
    bool isRobotBounded(string instructions) {
      dx = {0,1,0,-1};
      dy = {1,0,-1,0};
      d = 0;
      x = 0;
      y = 0;
      int x_min = 0, y_min = 0, x_max = 0, y_max = 0;
      forall(i,0,4){
        for( auto c : instructions ){
          exec(c);
          x_min = min(x_min, x);
          x_max = max(x_max, x);
          y_min = min(y_min, y);
          y_max = max(y_max, y);
        }
      }
      for(auto c : instructions ){
        exec(c);
        if( x < x_min  or x > x_max or y < y_min or y > y_max ) return false;
      }
      return true;
    }
};
int main( int argc, char * argv[] ){
  string ins; cin >> ins;
  Solution sol;
  cout << sol.isRobotBounded(ins) << '\n';
  return 0;
}
