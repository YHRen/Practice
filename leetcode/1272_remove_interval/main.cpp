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
#define trace(...)       __f(#__VA_ARGS__, __VA_ARGS__)
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define trace(...)       
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << ": " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " | ";
    __f(comma + 1, args...);
}

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& u) {
      vvi ans;
      for(auto & v : intervals){
        print_(v);
        print_(u);
        if( v[1] <  u[0] or u[1] < v[0] ){
          debug("1");
          ans.pb(v);
        }else if( v[0] >= u[0] and v[1] <= u[1] ){
          debug("2");
          continue; 
        }else if( v[0] < u[0] and v[1] > u[1] ){
          debug(" here ");
          int a = u[0];
          int b = u[1];
          trace(a,b,v[0], v[1]);
          if( v[0] < a ) ans.pb({v[0], a});
          if( b < v[1] ) ans.pb({b, v[1]});
        }else if( v[0] < u[0] ){
          int a = u[0];
          if( v[0] < a ) ans.pb({v[0], a});
        }else if( v[1] > u[1] ){
          int b = u[1];
          if( b < v[1] ) ans.pb({b, v[1]});
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vvi mtx(n, vi(2));
  for(auto & v : mtx)input(v);
  vi u(2);
  input(u);
  Solution sol;
  auto ans = sol.removeInterval(mtx, u);
  for(auto v : ans) {
    print_(v);
  }
  return 0;
}
