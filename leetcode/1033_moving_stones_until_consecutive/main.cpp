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
    vector<int> numMovesStones(int a, int b, int c) {
      vi v; 
      v.pb(a);
      v.pb(b);
      v.pb(c);
      sort(all(v));
      int gap1 = v[1]-v[0]-1;
      int gap2 = v[2]-v[1]-1;
      int max_mv = gap1 + gap2;
      int min_mv = 0;
      if( gap1 > gap2 ) swap(gap1, gap2); // now gap1 < gap2
      debug("gap", gap1, gap2);
      if( gap1 == 0 ) min_mv = min(1,gap2);
      else if( gap1 == 1 ) min_mv = 1;
      else min_mv = 2;
      return {min_mv, max_mv};
    }
};

int main( int argc, char * argv[] ){
  int a,b,c;
   cin >> a >> b >> c ;
   Solution sol;
   auto res = sol.numMovesStones(a,b,c);
   print_(res);
  return 0;
}
