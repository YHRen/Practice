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
    int maxSatisfied(vector<int>& v, vector<int>& grumpy, int X) {
      int tot = 0, n = sz(v);
      forall(i,0,n) if( grumpy[i] ==  0 ) tot += v[i];
      int left = n;
      forall(i,0,n){
        if( grumpy[i] ) {
          left = i;
          break;
        }
      }
      debug("tot", tot);
      if( left == n ) return tot;
      int tmp = v[left];
      int tot2= tmp;
      for(int r = left+1;r < n; ++r ){
        if( grumpy[r] == 0 ) continue;
        debug("r,left,",r,left,tmp);
        if(r - left >= X ){
          while( grumpy[left] == 0 or r - left >= X ){
            if( grumpy[left] == 1 ){ 
              tmp -= v[left] ;
            }
            left ++;
          }
        }
        tmp += v[r];
        debug("r=",r,"tmp=",tmp);
        tot2 = max(tot2, tmp);
      }
      return tot2+tot; 
    }
};
int main( int argc, char * argv[] ){
  int n, m; cin >> n >> m; 
  vi v(n); input(v);
  vi u(n); input(u);
  Solution sol;
  cout << sol.maxSatisfied(v,u,m) << endl;

  return 0;
}
