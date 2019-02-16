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
typedef vector<vector<ii>> vvii;

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
  vector<vvii> dp;
  int n;
  ii solve( bool is_A, int l, int r ){
    debug("at ", is_A, "l,r", l,r);
    if( r-l == 1 ) // always B
      return mp(0, v[l]);
    if( dp[is_A][l][r] != mp(-1,-1) ) return dp[is_A][l][r];

    // pick left end
    auto opt1 = solve( !is_A, l+1, r );
    if( is_A ) opt1.first += v[l];
    else opt1.second += v[l];
    debug(is_A, "at ", "lr,",l,r,"opt1=",opt1.first, opt1.second);

    // pick right end
    auto opt2 = solve( !is_A, l, r-1 );
    if( is_A ) opt2.first += v[r-1];
    else opt2.second += v[r-1];
    debug(is_A, "at ", "lr,",l,r,"opt1=",opt1.first, opt1.second);

    ii ans;
    if( is_A ){
      ans = opt1.first > opt2.first ? opt1 : opt2;
    }else{
      ans = opt1.second > opt2.second ? opt1 : opt2;
    }
    debug(is_A, "at ", "lr,",l,r,"final=",ans.first, ans.second);
    return dp[is_A][l][r] = ans;
  }

  public:
    bool stoneGame(vector<int>& piles) {
      v = piles;
      n = v.size();
      dp.resize(2);
      for( auto & mtx : dp ){
        mtx.resize(n+1);
        for(auto & v : mtx )
          v.resize(n+1, mp(-1,-1));
      }

      auto ans = solve(1,0,n);
      return ans.first > ans.second;


    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n); input(v);
  Solution sol;
  cout << sol.stoneGame(v) << '\n';


  return 0;
}
