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
typedef vector<vii>      vvii;
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
  int N;
  bool dfs(int x, int d, vi & v, vi & used, vvii & g ){
    if( d == N ) return true;
    for(auto & [y, idx] : g[x]){
      if(used[idx]) continue;
      v.pb(y); used[idx]=1;
      if( dfs(y,d+1,v,used,g)) return true;
      v.pop_back();
      used[idx]=0;
      // if( used[y.second] ) continue;
      // v.pb(y.first);
      // used[y.second]=1;
      // if( dfs(y.first, d+1, v, used, g) ) return true;
      // v.pop_back();
      // used[y.second]=0;
    }
    return false;
  }


    
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
      this->N = sz(tickets);
      vector<string> bag;
      for(auto pp : tickets){
        const string & s = pp.first, & t = pp.second;
        bag.pb(s);
        bag.pb(t);
      }
      sort(all(bag));
      bag.erase(unique(all(bag)), bag.end());
      unordered_map<string,int> dic;
      int n = 0;
      for(auto s : bag) dic[s]=n++;
      vvii g(n);
      forall(i,0,N){
        auto pp = tickets[i];
        int s = dic[pp.first], t = dic[pp.second];
        g[s].pb(mp(t,i));
      }
      for(auto & v : g ) sort(all(v));
      vi ans;
      vi used(N,0);
      if( !dfs(dic["JFK"], 0, ans, used, g) ) return vector<string>();
      else{
        vector<string> res;
        res.pb("JFK");
        for(auto x : ans) res.pb(bag[x]);
        return res;
      }
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
