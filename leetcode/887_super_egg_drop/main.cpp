#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
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

#define bg     begin()
#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi>  vvi;
typedef vector<ii>  vii;

#ifdef DEBUG
#define debug(args...)            {dbg,args; clog<<endl;}
#define print_( a )               for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )           for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)             // Just strip off all debug tokens
#define print_( a )               // skip
#define printPair_( a )           // skip
#endif
struct debugger {
  template <typename T>
  debugger& operator,(const T& x) {
    clog << x << " ";
    return *this;
  }
} dbg;

// std::ios::sync_with_stdio(false);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  public:
    int superEggDrop(int K, int N) {
      vi v(N+1,0);
      forall(i,1,N+1) v[i]=i;
      int x=1, k = 1;
      forall(k,2,K+1){
        vi u;
        u.pb(0);
        int x = 1;
        forall(i,1,N+1){
          while( max( v[x-1], u[i-x] ) > max( v[x], u[i-x-1] ) )
            x ++;
          debug("k=",k,"n",i, 1+max(v[x], u[i-x]), "x=",x);
          u.pb(1+max(v[x-1],u[i-x]));
        }
        v = u;
      }
      return v.back();
    }
};
int main( int argc, char * argv[] ){
  int k,n; cin >> k >> n;
  Solution sol;
  cout << sol.superEggDrop(k,n) << '\n';

  return 0;
}
