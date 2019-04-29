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
#include <complex>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF              (int)1000000007
#define EPS              1e-9
#define pb               push_back
#define mp               make_pair
#define all(c)           c.begin(), c.end()
#define forall(i,a,b)    for(int i=a;i<(b);++i)
#define trav(a,x)        for(auto & a: x)
#define in(a,b)          ((b).find(a) != (b).end())
#define sz(c)            (int)(c).size()
#define input(a)         for(auto & x : a) cin >> x;

using namespace std;

typedef vector<int>      vi;
typedef pair<int,int>    ii;
typedef vector<vi>       vvi;
typedef vector<ii>       vii;
typedef long long        ll;

#ifdef DEBUG
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
      int res = 0;
      int n = sz(v);
      forall(i,0,n){
        if( i+1 < n and v[i] <= v[i+1] ) continue;
        int h = v[i];
        for(int j = i; j >= 0; --j){
          h = min(h, v[j]);
          res = max(res, h*(i-j+1));
        }
      }
      return res;
    }
    int largestRectangleArea_slow(vector<int>& v) {
      int n = sz(v);
      if( n == 0 ) return 0; 
      if( n == 1 ) return v[0];
      int ans = 0;
      vii que;
      forall(i,0,n){
        debug("i=",i,v[i]);
        if( que.empty() ){
          que.push_back(mp(v[i],i));
          ans = max(ans, v[i]);
        }else{
          int x = v[i];
          auto itr = lower_bound(all(que),mp(x,0));
          if( itr == que.end() ){ // new largest
            debug("new largest");
            que.pb(mp(x,i));
            int n = sz(que);
            for(int j = n-1; j >=0 ; --j){
              ans = max(ans, que[j].first * (i-que[j].second+1) );
            }
          }else{ // smaller than previous
            debug("smaller than prev");
            int xxx = itr->second;
            ans = max(ans, x * (i-xxx+1) );
            que.erase(itr,que.end());
            que.pb(mp(x,xxx));
            int n = sz(que);
            for(int j = n-1; j >=0 ; --j){
              ans = max(ans, que[j].first * (i-que[j].second+1) );
            }
          }
            debug("ans=",ans);
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  Solution sol;
  cout << sol.largestRectangleArea(v) << endl;
  return 0;
}
