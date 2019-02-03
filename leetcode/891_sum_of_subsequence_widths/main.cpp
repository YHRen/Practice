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
typedef long long ll;

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
  public:
    int sumSubseqWidths(vector<int>& A) {
      int n = A.size();
      int M = 20001;
      vector<ll> p2(M, 1);
      forall(i,1,n){ p2[i] = (p2[i-1] * 2) % INF; }
      sort(all(A));
      ll ans = 0;
      forall(i,0,n){
        ll x = (p2[i] * A[i])%INF ;
        ll y =  (p2[n-i-1] * A[i])%INF;
        x = (x + INF - y )%INF;
        ans += x;
        ans %= INF;
      }
      return ans;

    };
    int sumSubseqWidths_N2_slow(vector<int>& A) {
      int n = A.size();
      int M = 20001;
      vi v(M, 0);
      vector<ll> p2(M, 1);
      forall(i,1,n){ p2[i] = (p2[i-1] * 2) % INF; }
      forall(i,0,n){ v[A[i]] += 1; }
      ll ans = 0;
      forall(i,1,M){
        if( v[i] == 0 ) continue;
        ll tmp = (p2[v[i]] +INF -1)%INF;
        ll r   = 0;
        ll term = 0;
        forall(j,i+1,M){
          if( v[j] == 0 ) continue;
          term = (p2[v[j]] +INF - 1)%INF;
          ll x = ((((tmp * term)%INF)*p2[r])%INF* (j-i) )%INF;
          ans += x;
          ans %= INF;
          r += v[j];
          r %= INF;
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
