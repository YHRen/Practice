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
  public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
      int n = v.size();
      vi  ans;
      if( n == 0 ) return ans;
      if( n == 1 ) return v;
      sort(all(v));
      vii dp(n, mp(1,-1));
      dp[0] = mp( 1, -1 );
      forall(i,1,n){
        int tmp = 0;
        for( int j = i-1; j >= 0; --j ){
          if( v[i] % v[j] == 0 && dp[j].first > tmp ){
            tmp = dp[j].first;
            dp[i].first = 1 + tmp;
            dp[i].second = j;
          }
        }
      }
      auto idx = max_element( all( dp ) ) - dp.bg;
      while( idx!=-1 ){
        ans.pb( v[idx] );
        idx = dp[idx].second;
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n); input(v);
  Solution sol;
  auto ans = sol.largestDivisibleSubset(v);
  print_(ans);
  return 0;
}
