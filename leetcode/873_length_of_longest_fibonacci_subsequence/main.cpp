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
  vvi dp;
  int n;
  int rec( int i, int j ){
    if( dp[i][j] != -1 ) return dp[i][j];
    int ans = 0;
    forall(k, j+1, n){
      if( v[k] == v[i]+v[j] ){
        ans = 1 + rec(j, k);
        break;
      }
    }
    return dp[i][j] = ans;
  }
  
  public:
    int lenLongestFibSubseq(vector<int>& A) {
      v = A;
      n = A.size();
      dp.resize(n); for(auto & v : dp) v.resize(n,-1);
      int ans = 0;
      forall(i,0,n-2){
        forall(j,i+1,n-1){
          ans = max(ans, rec( i,j ));
        }
      }
      if( ans == 0 ) return 0;
      else return ans + 2;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n); input(v);
  Solution sol;
  cout << sol.lenLongestFibSubseq(v) << '\n';

  return 0;
}
