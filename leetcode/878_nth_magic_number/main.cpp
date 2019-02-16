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
  ll nth(ll x, ll a, ll b, ll c){
    return x/a- x/c+x/b;
  }
public:
    int nthMagicalNumber(int N, int A, int B) {
      if( A == B ){ return ll(N)*A%INF; }
      if( A > B ) swap(A,B);
      // A < B 
      ll n = N;
      ll C = ll(A)*ll(B)/__gcd(A,B);
      ll left = A, right = ll(INF)*40000, mid;
      
      while( left < right ){
        mid = (right+left)/2;
        ll m = nth(mid, A, B, C);
        debug("mid = ", mid, "m = ", m );
        if( m > n ){
          right = mid;
        }else if (m < n ){
          left = mid+1;
        }else{
          break;
        }
      }
      while( mid % A != 0 and mid %B != 0 ){ mid --; }
      return mid%INF;
    }
};
int main( int argc, char * argv[] ){
  int n,a,b;
  cin >> n >> a >> b ;
  Solution sol;
  cout << sol.nthMagicalNumber(n,a,b) << '\n';
  return 0;
}
