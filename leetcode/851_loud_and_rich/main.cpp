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
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
      int n = quiet.size();
      vvi g(n);
      vi ind(n,0);
      for(auto p : richer){
        g[p[0]].pb(p[1]);
        ind[p[1]]+=1;
      }
      vi ans(n);
      iota(all(ans),0);
      queue<int> leaf;
      forall(i,0,n) if( ind[i] == 0 ) leaf.push(i);
      while(!leaf.empty()){
        int i = leaf.front(); leaf.pop();
        for(auto y : g[i] ){
          if( quiet[ans[i]] < quiet[ans[y]] ){
            ans[y] = ans[i];
          }
          ind[y] -= 1;
          if( ind[y] == 0 ) leaf.push(y);
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n, m; cin >> n >> m;
  vi q(n); input(q);
  vvi e(m, vi(2)); for(auto & x : e ) input(x);
  Solution sol;
  auto ans = sol.loudAndRich(e, q);
  print_(ans);

  return 0;
}
