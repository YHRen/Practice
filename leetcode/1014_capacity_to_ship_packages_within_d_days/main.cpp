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

// auto ____ =[]()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     return nullptr;
// }();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  vi u;
  int C( int cap ){
    int turns = 0;
    int run = 0;
    auto itr = u.begin();
    debug("cap=",cap);
    do{
      turns ++;
      debug("finding", run+cap, "from", *itr);
      auto nxt = upper_bound(itr, u.end(), run+cap);
      if( nxt == u.end() ) return turns;
      else{
        itr = nxt;
        run = *(nxt-1);
      }
    }while(true); 
    return turns;
  }
public:
    int shipWithinDays(vector<int>& v, int D) {
      int n = sz(v);
      u.resize(n+1,0);
      int tot = accumulate(all(v),0);
      int max_elm= *max_element(all(v));
      forall(i,1,n+1){ u[i] = u[i-1] + v[i-1]; }
      int lo = max_elm, hi = tot+1; 
      int ans = INF;
      while( lo <= hi ){
        int mid = (lo+hi)/2;
        debug("lo,hi,mid",lo,hi,mid);
        int turns = C(mid);
        debug("turns",turns, D);
        if( turns > D ){ //increase cap
          lo = mid+1;
        }else if( turns <= D ){// decrease cap
          ans = mid;
          hi = mid-1;
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n, D; cin >> n >> D;
  vi v(n); input(v);
  Solution sol;
  cout << sol.shipWithinDays(v,D) << '\n';
  return 0;
}
