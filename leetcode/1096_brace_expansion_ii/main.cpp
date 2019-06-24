#include <vector>
#include <regex>
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
  string normalize( const string & expr ){
    if( expr[0]  != '{' ) return "{"+expr+"}";
    int cnt = 0, n = sz(expr);
    forall(i,0,n){
      if( expr[i] == '{' ) cnt ++;
      else if( expr[i] == '}') cnt --;
      else continue;
      if( cnt == 0 and i !=n-1 ) return "{"+expr+"}";
    }
    return expr;
  }
  void add_group( vector<vector<vector<string>>> & cache ){
    cache.pb( vector<vector<string>> () );
    cache.back().pb( vector<string>() );
    cache.back().back().pb("");
  }
  void add_break( vector<vector<vector<string>>> & cache ){
    cache.back().pb( vector<string>() );
    cache.back().back().pb("");
  }

  public:
    vector<string> braceExpansionII(string expr) {
      debug("string = ",expr);
      expr = normalize(expr);
      debug("new string = ", expr);
      vector<vector<vector<string>>> ans;
      int level = 0,  i = 1, n = sz(expr)-1, l;
      add_group( ans );
      for(; i < n; ++i ){
        switch( expr[i] ){
          case '{':
            if( level == 0 ){ l = i; add_break(ans); }
            level ++;
            break;
          case '}':
            level --;
            if( level == 0 ){
              ans.back().back() = braceExpansionII( expr.substr(l, i-l+1) );
              add_break(ans);
            }
            break;
          case ',':
            if( level == 0 ){ add_group( ans ); }
            break;
          default:
            if( level == 0 ){ ans.back().back().back() += expr[i]; }
            break;
        }
      }
      vector<string> res;
      for(auto & g : ans){
        if( sz(g) > 1 ){
          forall(i,1,sz(g)){
            vector<string> tmp;
            for(auto & s : g[0]){
              for(auto & t : g[i]){
                tmp.pb(s+t);
              }
            }
            sort(all(tmp));
            tmp.erase( unique(all(tmp)), tmp.end() );
            swap(tmp, g[0]);
          }
        }
        copy( all(g[0]), back_inserter(res) );
      }
      sort(all(res));
      res.erase( unique(all(res)), res.end() );
      debug("returnning ");
      print_(res);
      return res;
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  auto res = sol.braceExpansionII(str);
  return 0;
}
