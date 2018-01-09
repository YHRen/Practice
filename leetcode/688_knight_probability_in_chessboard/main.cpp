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
  int n, k;
  vector<vector<vector<double>>> dp;
  vi  m1 = {-2, -1, 1, 2, 2, 1, -1, -2 };
  vi  m2 = {-1, -2, -2, -1, 1, 2, 2, 1};
  double solve( int d, int r, int c ){
    if( r >= n || r < 0 || c >= n || c < 0 ) return 0;
    if( d == k ) return 1;
    if( dp[d][r][c] != -1 ) return dp[d][r][c];
    double tot = 0;
    forall(i,0,8){
      tot += solve( d+1, r+m1[i], c +m2[i]);
    }
    return dp[d][r][c] = tot / 8.0;
  }

  public:
    double knightProbability(int N, int K, int r, int c) {
      n = N, k = K;
      dp.resize(k,vector<vector<double>>(n,vector<double>(n,-1.0)));
      return solve(0,r,c);
    }
};
int main( int argc, char * argv[] ){
  int n,k,r,c;
  cin >> n >> k >> r >>  c;
  Solution sol;
  cout << sol.knightProbability(n,k,r,c) << '\n';

  return 0;
}
