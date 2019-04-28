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

//auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
  vii Q;
  int n;

  bool C( int x, int y ){
    return ! any_of(all(Q),[x,y](ii lhs){ return lhs.second == y or 
        y - x == lhs.second-lhs.first or
        x+y == lhs.second+lhs.first; });
        }
  int aux(int x){
    debug("x,");
    printPair_(Q);
    if( x == n ) return 1;
    int ans = 0;
    forall(j,0,n){
      if( C(x,j) ){
        Q.pb(mp(x,j));
        ans += aux(x+1);
        Q.pop_back();
      }
    }
    return ans;
  }

public:
    int totalNQueens(int n) {
      if( n == 0 ) return 0;
      this->n = n;
      int ans = 0;
      forall(j,0,n){
        Q.pb(mp(0,j));
        ans += aux(1);
        Q.pop_back();
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  Solution sol;
  cout << sol.totalNQueens(n) << endl;
  return 0;
}
