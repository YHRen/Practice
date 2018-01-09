#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
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
  int n,m;
  vvi dp ;
  string s1, s2;
  int solve( int i, int j ){
    if( i == n || j == m ) return 0;
    if( dp[i][j] != -1 ) return dp[i][j];
    int ans = 0;
    if( s1[i] == s2[j] ){
      ans = (int)s1[i] + solve( i+1, j+1 );
    }
    int p   = solve(i+1,j);
    int q   = solve(i,j+1);
    ans = max(ans,max(p,q));
    dp[i][j] = ans;
    return dp[i][j];
  }

  public:
    int minimumDeleteSum(string s1, string s2) {
      n = s1.size(), m = s2.size();
      this->s1 = s1;
      this->s2 = s2;
      int a1 = 0, a2 = 0;
      for( char c : s1 ) a1 += c;
      for( char c : s2 ) a2 += c;
      if( n == 0 || m == 0 ){ return max(a1, a2); }
      dp.resize(n, vi(m,-1));
      int keep = solve(0,0);
      return a1 + a2 - 2*keep;
    }
};
int main( int argc, char * argv[] ){
  string s1,s2;
  cin >> s1 >> s2;
  Solution sol;
  cout << sol.minimumDeleteSum(s1,s2) << '\n';

  return 0;
}
