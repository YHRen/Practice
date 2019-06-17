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
  bool try_run(int x, int n, const vi & v, const vi & u ){
    debug("x=",x);
    int W = 0;
    forall(i,0,n){
      int idx = (x+i)%n;
      debug("i=",idx,"W=",W,v[idx],u[idx]);
      if( W+v[idx] < u[idx] ) return false;
      W += v[idx]-u[idx];
    }
    return true;
  }
  public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int n = sz(gas);
      if( accumulate(all(gas),0) < accumulate(all(cost),0) ) return -1;

      vi idx(n); iota(all(idx),0);
      sort(all(idx),[&gas, &cost]( int lhs, int rhs ){
          if( gas[lhs]-cost[lhs] > gas[rhs]-cost[rhs] ) return true;
          else return false;
          });
      print_(idx);
      for(auto x : idx){
        if( try_run(x, n, gas, cost) ) return x;
      }
      return -1;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n), u(n); input(v); input(u);
  Solution sol;
  cout << sol.canCompleteCircuit(v,u) << endl;
  return 0;
}
