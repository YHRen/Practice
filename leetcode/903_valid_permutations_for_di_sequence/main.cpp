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
  vvi dp;
  string S;
  vector<vector<long long>> mk;
  int rec( int l, int r ){
    if( l == r ) return 1;
    if( dp[l][r] != -1 ) return dp[l][r];
    else{
      long long ans = 0;
      int m = r-l;
      debug("l,r,m", l,r,m);
      if( S[l] == 'I' ){ ans += rec( l+1, r); ans %= INF; }
      if( S[r-1] == 'D' ){ ans += rec( l, r-1); ans %= INF;}
      for(int i = l; i < r-1; ++ i ){
        if( S[i] == 'D' and S[i+1] == 'I' ){
          debug("m",m,"l,i,r",l,i,r, "ans=",ans);
          long long tmp = C(m, i+1-l);
          tmp = tmp* rec(l,i); tmp %= INF;
          tmp = tmp* rec(i+2,r); tmp %= INF;
          ans += tmp;
          ans %= INF;
          debug("m",m,"l,i,r",l,i,r, "ans=",ans);
        }
      }
      dp[l][r] = ans;
      debug("dp[l][r]",l,r,ans);
      return ans;
    }
  }
  long long C( int n, int p ){
    if( n < p ) return 0;
    if( p == 0 or n == p) return mk[n][p] = 1;
    else if (mk[n][p] != 0) return mk[n][p];
    else 
      return mk[n][p] = (C(n-1,p-1)%INF + C(n-1,p)%INF) %INF;
  }

public:
    int numPermsDISequence(string S) {
      this->S = S;
      int n = S.size()+1;
      dp.resize(n); for(auto & v : dp) v.resize(n,-1);
      mk.resize(n); for(auto & v : mk) v.resize(n,0);
      forall(i,0,n-1){ dp[i][i+1] = 1; }
      return rec(0,n-1);
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  cout << sol.numPermsDISequence(str) << '\n';

  return 0;
}
