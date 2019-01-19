#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
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
struct debugger
{
  template<typename T> debugger& operator , (const T& x)
  {    
    clog << x << " ";    
    return *this;    
  }
} dbg;

/******* Actual Code Starts Here *********/
class Solution {
public:
    int subarraysDivByK_slow(vector<int>& A, int K) {
      int n = A.size();
      int ans = 0;
      vi v(n,0); v[0] = A[0];
      forall(i,1,n){ v[i] = v[i-1]+A[i]; }
      forall(i,0,n){
        print_(v);
        ans += count_if( v.begin()+i, v.end(), [K](int x){ 
            if(x >= 0 ) return x%K == 0;
            else return (-x)%K==0;
            });
        debug(ans);
        forall(j,i,n){
          v[j] -= A[i];
        }
      }
      return ans;
    }
    int subarraysDivByK(vector<int>& A, int K) {
      int n = A.size();
      vector<long long> v(n+1,0);  v[0] = 0;
      forall(i,1,n+1){ v[i] = v[i-1]+A[i-1]; }
      vi u(K,0);
      forall(i,0,n+1){ u[ (v[i]%K+K)%K ] += 1; }
      int ans = 0;
      for(auto x : u ) if( x ) ans += (x-1)*x/2;
      return ans;
    }
};
int main( int argc, char * argv[] ){
//  std::ios::sync_with_stdio(false);
//  std::cin.tie(NULL);
  int n, k; cin >> n >> k;
  vi v(n); input(v);
  Solution sol;
  cout << sol.subarraysDivByK(v,k) << '\n';

  return 0;
}
