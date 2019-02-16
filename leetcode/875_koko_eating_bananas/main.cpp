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
typedef long long ll;

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
  ll timer( int k ){
    ll ans = 0 ;
    for(auto x : v ){ ans += x/k + (x%k>0); }
    return ans;
  }
  public:
    int minEatingSpeed(vector<int>& piles, int H) {
      v = piles;
      int l = 1, r = *max_element(all(piles)), mid;
      ll m = H;
      while(l<r){
        mid = (l+r)/2;
        debug("l,r,",l,r,mid);
        ll w = timer(mid);
        debug("try,",mid,"get",w);
        if( w > m ){ // takes too long
          l = mid+1;
        }else if( w <= m ){ // try eat slower
          r = mid;
        }
      }
      
      /*
      debug(" mid = ", mid, timer(mid));
      vi u;
      for(auto & x : v ){ u.pb(x/mid+(x%mid>0)); }
      print_(u);
      */
      return l;

      while( mid > 0 and timer(mid) > H ){
        mid ++;
      }
      int ans = mid;
      while( mid > 0 and timer(mid) <= H ){
        ans = mid;
        mid --;
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  vi v(n); input(v);
  Solution sol;
  cout << sol.minEatingSpeed(v,m) << '\n';

  return 0;
}
