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
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
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
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  vi v;
  int target, n, K;
public:
    bool splitArraySameAverage(vector<int>& A) {
      sort(all(A));
      v = A;
      n = A.size();
      if( n == 1 ) return false;
      if( n == 2 ) return A[0] == A[1];
      int tot = accumulate(all(A),0);
      vector<bitset<3000001>> dp(n/2+1);
      dp[0][0] = 1;
      print_(A);
      forall(i,0,n){
        for(int k = n/2; k > 0; --k ){
          for(int s = tot; s >= 0; --s){
            if( s < A[i] ) break;
            if( dp[k-1][s-A[i]] ){
              debug("i", i, "k",k,"s=",s);
              dp[k].set(s);
            }
          }
        }
      }
      debug("tot",tot);
      forall(k,1,n){
        if(2*k > n ) break;
        if( k*tot%n != 0 ) continue;
        target = k*tot/n;
        debug("k=",k,"target=",target);
        if( dp[k][target] ) return true;
      }
      return false;
        
    }
};
int main( int argc, char * argv[] ){
  int n; cin >>n;
  vi v(n); input(v);
  Solution sol;
  cout << sol.splitArraySameAverage(v) << '\n';

  return 0;
}
