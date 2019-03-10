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

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  int calc( const vi & v, int th ){
    int ans = 0, l = 0, n = sz(v);
    forall(i, 0, n) {
      if (v[i] < th) {
        continue;
      } else {
        if (i > l) ans += (i - l) * (i - l + 1) / 2;
        l = i + 1;
      }
    }
    ans += (n - l) * (n - l + 1) / 2;
    return ans;
  }

   public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
      int n = sz(A);
      vi v(n);
      forall(i,0,n){ 
        if( A[i] < L ) v[i] = -1;
        else if( A[i] > R ) v[i] = 1;
        else v[i] = 0;
      }

      int ans = calc(v, 1);
      return ans - calc(v,0);
    }
};
int main( int argc, char * argv[] ){
  int n,l,r; cin >> n >> l >> r;
  vi v(n); input(v);
  Solution sol;
  cout << sol.numSubarrayBoundedMax(v,l,r) << '\n';

  return 0;
}
