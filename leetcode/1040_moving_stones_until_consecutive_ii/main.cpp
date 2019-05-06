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
    vector<int> numMovesStonesII(vector<int>& v) {
      int n = sz(v); if( n<=2 ) return {0,0};
      sort(all(v));
      ll gap=0;
      forall(i,1,n){ gap+=v[i]-v[i-1]-1; }
      if( gap == 0 ) return {0,0};
      int max_mv;
      if( v[1]-v[0] > 1 and v[n-1] - v[n-2] > 1 ){
        max_mv = gap - min( v[1]-v[0], v[n-1]-v[n-2] ) + 1 ;
      }else{
        max_mv = gap;
      }
      int min_mv = n;
      for(int i=0,j=0; j < n; ++j ){
        while( v[j] - v[i] >= n ) ++i;
        if( j-i+1 == n-1 and v[j]-v[i] == n-2 ){
          min_mv = min(min_mv, 2);
        }else{
          min_mv = min(min_mv, n-(j-i+1));
        }
      }
      return {min_mv,max_mv};
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  Solution sol;
  auto res = sol.numMovesStonesII(v);
  print_(res);
  return 0;
}
