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
typedef vector<char>     vc;
typedef pair<int,int>    ii;
typedef vector<vi>       vvi;
typedef vector<vc>       vvc;
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

//auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      n += 1;
      vi cnt(26,0);
      for( auto c : tasks) cnt[c-'A'] += 1;
      priority_queue<ii> pq;
      forall(i,0,26){
        if( cnt[i] > 0 ) pq.push(mp(cnt[i],i));
      }

      int ans = 0;
      int trailing_idle = 0;
      while(!pq.empty()){
        int min_num = INF;
        vii tmp;
        int m = sz(pq);
        forall(i,0,min(n,m)){
          auto p = pq.top();
          pq.pop();
          tmp.pb(p);
          min_num = min(min_num, p.first);
        }
        printPair_(tmp);
        //ans += min_num*(n);
        ans += (n);
        debug("min_num", min_num, "ans=",ans,"delta=",min_num*n);
        trailing_idle = (n-sz(tmp));
        debug("trailing_idle=",trailing_idle);
        for(auto p : tmp ){
          //p.first -= min_num;
          p.first -= 1;
          if( p.first > 0 ) pq.push(p);
        }
      }
      return ans-trailing_idle;
    }
};
int main( int argc, char * argv[] ){
  int n, m; cin >> n >> m; 
  vc v(n); input(v);
  print_(v);
  Solution sol;
  cout << sol.leastInterval(v,m) << endl;
  return 0;
}
