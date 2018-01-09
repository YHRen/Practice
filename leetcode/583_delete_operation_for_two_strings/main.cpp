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
  private:
    int n,m;
    string w1,w2;
    int solve( int i, int j, vvi & dp ){
      if( i == n || j == m ) return 0;
      if( dp[i][j] != -1 ) return dp[i][j];
      int q = 0;
      if( w1[i] == w2[j] ){
        q = solve(i+1,j+1,dp) + 1;
      }else{
        q = max( solve(i+1,j,dp), solve(i,j+1,dp) );
      }
      return dp[i][j] = q;
    }
  public:
    int minDistance(string word1, string word2) {
      n = word1.size();
      m = word2.size();
      w1 = word1;
      w2 = word2;
      if( n == 0 ) return m;
      if( m == 0 ) return n;
      vvi dp( n+1, vi(m+1, -1 ) );
      return m+n-2*solve(0,0,dp);
    }
};
int main( int argc, char * argv[] ){
  string s1,s2; cin >> s1 >> s2;
  Solution sol;
  cout << sol.minDistance(s1,s2) << '\n';

  return 0;
}
