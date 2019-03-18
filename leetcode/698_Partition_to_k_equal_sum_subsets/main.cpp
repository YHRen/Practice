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
#define forall(i,a,b)               for(int i=a;i<(b);++i)
#define trav(a,x)                   for(auto & a: x)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define sz(c)                       (int)(c).size()
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<vvi>   vvvi;
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

auto ____ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  //vector<vector<vector<char>>> dp;
  vector<vector<set<int>>> dp;
  int n,k,g;
  vi v;
  bool rec( int x, int y, int mask ){
    if( x == k-1 ) return 1;
    if( x >= k or y >= g ) return 0; // safty net, should never happen
    if( dp[x][y].count(mask) ) return 0;
    forall(i,0,n){
      if( mask & (1<<i) ) continue; // visited
      else if( y + v[i] > g ) continue;
      else if( y + v[i] == g ){
        if( rec(x+1, 0, mask | (1<<i) ) ) return  true;
      }else if( y + v[i] < g ){
        if( rec(x, y+v[i], mask|(1<<i))) return  true;
      }
    }
    dp[x][y].insert(mask);
    return false;
  }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
      if( k == 1 ) return true;
      this->n = sz(nums);
      this->k = k;
      this->v = nums;
      int tot = accumulate(all(nums),0);
      if( tot%k != 0 ) return false;
      this-> g = tot/k;
      if( any_of(all(nums), [g=this->g](int x){ return x>g; }) ) return false;
      dp.resize(k);
      for(auto & mtx : dp ){
        mtx.resize(g);
        // for(auto & u : mtx ){
        //   u.resize( 1<<n, -1 );
        // }
      }
      return rec( 0, 0, 0 );
    }
};
int main( int argc, char * argv[] ){
  int n,k; cin >> n >> k;
  vi v(n); input(v);
  Solution sol;
  cout << sol.canPartitionKSubsets(v, k) << '\n';

  return 0;
}
