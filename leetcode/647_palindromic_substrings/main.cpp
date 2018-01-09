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
/******* Actual Code Starts Here *********/
class Solution {
  vvi dp;
  string s;
  public:
    bool solve(int i, int j){
      if( i > j ) return true;
      if( dp[i][j] != -1 ) return dp[i][j];
      solve(i+1,j);
      solve(i,j-1);
      if( s[i] == s[j] ){
        dp[i][j] = solve(i+1,j-1);
      }else{
        dp[i][j] = 0;
      }
      return dp[i][j];
    }
    int countSubstrings(string s) {
      this->s = s;
      int n = s.size();
      if( n == 0 ) return 0;
      if( n == 1 ) return 1;
      dp.resize(n);
      for( auto & v : dp ) v.resize(n,-1);
      forall(i,0,n) dp[i][i] = 1;
      solve(0,n-1);
      int64_t ans = 0;
      forall(i,0,n){
        forall(j,i,n){
          ans += dp[i][j];
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  cout << sol.countSubstrings(str) << '\n';

  return 0;
}
