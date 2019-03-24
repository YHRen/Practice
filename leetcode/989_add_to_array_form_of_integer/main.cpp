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
#define forall(i,a,b)               for(int i=a;i<(b);++i)
#define trav(a,x)                   for(auto & a: x)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define sz(c)                       (int)(c).size()
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

auto ____ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
      vi B;
      while(K>0){
        B.pb(K%10);
        K/=10;
      }
      reverse(all(A));
      int inc=0, i = 0;
      int n = sz(A), m = sz(B);
      vi C;
      for(/* */; i < n and i < m; ++i){
        int y = A[i] + B[i] + inc;
        if( y > 9 )  inc=1, y-=10;
        else inc = 0;
        C.pb(y);
      }
      while(i<n){
        int y = A[i] + inc;
        if( y > 9 ) inc=1, y-=10;
        else inc = 0;
        C.pb(y);
        ++i;
      }
      while(i<m){
        int y = B[i] + inc;
        if( y > 9 ) inc=1, y-=10;
        else inc = 0;
        C.pb(y);
        ++i;
      }
      if(inc){
        C.pb(inc);
      }
      reverse(all(C));
      return C;
        
    }
};
int main( int argc, char * argv[] ){
  int n, m; cin >> n >> m;
  vi v(n); input(v);
  Solution sol;
  auto ans = sol.addToArrayForm(v,m);
  print_(ans);
  return 0;
}
