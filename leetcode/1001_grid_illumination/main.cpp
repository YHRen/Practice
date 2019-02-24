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
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
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

// std::ios::sync_with_stdio(false);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
      unordered_map<int,int> row, col, major, minor;
      unordered_map<int, set<int>> L;
      for(auto & p : lamps ){
        int x = p[0], y = p[1];
        L[x].insert(y);
        row[x] += 1;
        col[y] += 1;
        major[x-y] += 1;
        minor[x+y] += 1;
        debug("adding", x, y, x-y, x+y );
      }

      vi ans;
      for(auto & q : queries ){
        int x = q[0], y = q[1];
        if( row.count(x) || col.count(y) || major.count(x-y) || minor.count(x+y) ){
          ans.pb(1);
        }else{ 
          ans.pb(0);
        }
        for(int i = x-1; i <= x + 1; ++i ){
          if( i < 0 || i >= N ) continue;
          auto itr = L.find(i);
          if( itr == L.end() ) continue;
          for( int j = y-1; j <= y+1; ++j ){
            if( j < 0 || j >= N ) continue;
            auto itr_j = itr->second.find(j);
            if( itr_j != itr->second.end() ){
              itr->second.erase( itr_j) ;
              { auto itr_x = row.find(i); itr_x->second --; if( itr_x->second == 0 ) row.erase(itr_x); }
              { auto itr_x = col.find(j); itr_x->second --; if( itr_x->second == 0 ) col.erase(itr_x); }
              { auto itr_x = major.find(i-j); itr_x->second --; if( itr_x->second == 0 ) major.erase(itr_x); }
              { auto itr_x = minor.find(i+j); itr_x->second --; if( itr_x->second == 0 ) minor.erase(itr_x); }
            }
          }
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n, m; cin >> n >> m;
  vvi V(m, vi(2)), W(m, vi(2));
  for(auto & v : V ) input(v);
  for(auto & v : W ) input(v);
  Solution sol;
  auto ans = sol.gridIllumination(n, V, W );
  print_(ans);


  return 0;
}
