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
    int subarraysWithKDistinct(vector<int>& A, int K) {
      int n = sz(A);
      vi v(n+1,0);
      vi u(n+1,0);
      int ans = 0;
      int run = 0, l = 0, r = 0;
      forall(i,0,n){
        debug("i=",i, "A[i]=", A[i], "ans=", ans, "lr",l,r);
        if( v[A[i]] == 0 ) run++;
        v[A[i]] += 1;
        u[A[i]] += 1;
        if( run == K ){
          while( u[A[r]] > 1 ){
            u[A[r]]--;
            r ++;
          }
          debug("run==K","adding", r-l+1, "l,r", l, r);
          ans += r-l+1;
        }else if(run>K){
          run = K;
          while(v[A[l]] > 1 ){
            v[A[l]] --;
            l ++;
          }
          v[A[l++]] --;
          u[A[r++]] --;
          while(u[A[r]] > 1 ){
            u[A[r]]--;
            r++;
          }
          debug("run>K","adding", r-l+1, "l,r", l, r);
          ans += r-l+1;
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,k; cin >> n >> k;
  vi v(n); input(v);
  Solution sol;
  debug("K=",k);
  print_(v);
  cout << sol.subarraysWithKDistinct(v,k) << '\n';


  return 0;
}
