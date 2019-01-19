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
  int n;
  vector<vector<double>> dp;
  vector<vector<double>> mtx;
  double rec(int x, int k){
    if( x==n ) return -INF;
    if( k==1 ){
      debug("dp",x,k,*mtx[x].rbegin());
      return *mtx[x].rbegin();
    }
    if( dp[x][k] > -1.0) return dp[x][k];

    double ans = 0.0;
    forall(i,x,n-1){
      debug("for,",i,x);
      ans = max(ans, mtx[x][i] + rec(i+1,k-1));
    }
    debug("dp",x,k,ans);
    dp[x][k] = ans;
    return ans;
  }

public:
    double largestSumOfAverages(vector<int>& A, int K) {
      n = A.size();
      vi v(n+1,0); 
      forall(i,1,n+1) v[i] = v[i-1] + A[i-1];
      mtx.resize(n); for(auto & u : mtx) u.resize(n,0.0);
      dp.resize(n);  for(auto & u : dp ) u.resize(K+1,-1);
      forall(i,0,n){
        forall(j,i,n){
          mtx[i][j] = double(v[j+1] - v[i])/double(j-i+1);
        }
      }

      print_(A);
      print_(v);
      debug("===mtx===");
      for(auto u : mtx){
        print_(u);
      }
      debug("===mtx===");

      double ans = rec(0,K);

      debug("===dp===");
      for(auto u : dp){
        print_(u);
      }

      return ans;
        
    }
};

int main( int argc, char * argv[] ){
  int n, K; cin >> n >> K; 
  vi v(n); input(v);
  Solution sol;
  cout << sol.largestSumOfAverages(v, K) << '\n';

  return 0;
}
