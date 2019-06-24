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
typedef vector<ll>       vll;
typedef vector<vll>      vvll;

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
    int kInversePairs(int n, int k) {
      if( n == 1 ) return k==0;
      if( k == 0 or k == n*(n-1)/2 ) return 1;
      if( k > n*(n-1)/2 ) return 0;
      vll prv(k+1, 0);// n = 0
      vll cur(k+1, 0);// n = 1
      prv[0] = 1;
      forall(i,1,n+1){
        debug("i=",i);
        debug("before prv");
        print_(prv);
        forall(j,1,k+1){
          prv[j] += prv[j-1];
          prv[j] %= INF;
        }
        cur[0] = prv[0];
        forall(j,1,k+1){
          cur[j] = prv[j] + INF - (j-i+1 > 0 ? prv[j-i] : 0 );
          cur[j] %= INF;
        }
        debug("after prv");
        print_(prv);
        //debug("cur");
        print_(cur);
        swap(cur,prv);
      }
      return prv[k];
    }
};
int main( int argc, char * argv[] ){
  int n,k; cin >> n >> k;
  Solution sol;
  cout << sol.kInversePairs(n,k) << endl;
  return 0;
}
