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
  int n;
  vvi dp;
  vi v,u;
  int solve(int idx, bool flag){
    if(  idx == n ) return 0;
    if( dp[flag][idx] != -1 ) return dp[flag][idx];
    int a = flag ? u[idx-1] : v[idx-1]; 
    int b = flag ? v[idx-1] : u[idx-1];
    int p = INF, q = INF;
    if( a < v[idx] and b < u[idx] ) p = solve(idx+1, false);
    if( a < u[idx] and b < v[idx] ) q = 1 + solve(idx+1, true);
    return dp[flag][idx] = min(p,q);
  }

public:
    int minSwap(vector<int>& A, vector<int>& B) {
      v = A; 
      u = B;
      n = A.size();
      dp.resize(2); for(auto & v : dp ) v.resize(n,-1);
      return min(solve(1,0), 1+solve(1,1));
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n), u(n);
  input(v); input(u);
  Solution sol;
  cout << sol.minSwap(v,u) << '\n';

  return 0;
}
