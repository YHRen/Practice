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
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
      int n = sz(barcodes);
      if( n == 1 ) return vi(barcodes);
      unordered_map<int,int> cnt;
      print_(barcodes);
      for(auto x : barcodes) cnt[x] += 1;
      priority_queue<ii> pq;
      for(auto p : cnt){
        debug("push", p.first, p.second);
        pq.push(mp(p.second,p.first));
      }
      vi ans;
      debug("pq.size()",pq.size());
      while(pq.size() > 1 ){
        auto x = pq.top(); pq.pop();
        auto y = pq.top(); pq.pop();
        debug("x,y",x.first,x.second, y.first, y.second);
        vi tmp;
        tmp.pb(x.second);
        tmp.pb(y.second);
        if( x.first > 1 ) pq.push(mp(x.first-1, x.second));
        if( y.first > 1 ) pq.push(mp(y.first-1, y.second));
        if( ans.empty() ){
          ans = tmp;
        }else{
          if( ans.back() == tmp.front() ){ reverse(all(tmp));}
          copy(all(tmp),back_inserter(ans));
        }
        print_(ans);
      }
      if( pq.size() == 1 ) ans.pb(pq.top().second);
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  Solution sol;
  auto res  = sol.rearrangeBarcodes(v);
  print_(res);
  return 0;
}
