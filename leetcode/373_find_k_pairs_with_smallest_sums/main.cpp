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
    vector<pair<int, int>> kSmallestPairs(vector<int>& v, vector<int>& u, int k) {
      int i = 0, j = 0;
      int n = v.size(), m = u.size();
      vii ans;
      if( v.empty() || u.empty() || !k ) return ans;
      auto cmp = [&v,&u]( const ii & lhs, const ii & rhs ){
        return v[lhs.first] + u[lhs.second] > v[rhs.first] + u[rhs.second];
      };
      priority_queue< ii, vii, decltype( cmp ) > Q(cmp);
      Q.push(mp(0,0));
      while( !Q.empty() && k-- ){
        auto p = Q.top(); Q.pop();
        debug(p.first, p.second);
        debug( v[p.first]+u[p.second]);
        ans.pb( mp( v[p.first], u[p.second] ) );
        if( p.first + 1 < n  ){
          Q.push( mp( p.first+1, p.second ) );
        }
        if( p.first == 0 && p.second+1 < m ){
          Q.push( mp( p.first, p.second+1 ) );
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m,k; cin >> n >> m >> k;
  vi v(n), u(m);
  for( auto & x : v ) cin >> x;
  for( auto & x : u ) cin >> x;
  Solution sol;
  auto ans = sol.kSmallestPairs(v,u,k);
  printPair_(ans);

  return 0;
}
