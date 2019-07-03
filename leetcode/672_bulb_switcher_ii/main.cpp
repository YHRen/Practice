#include <vector>
#include <functional>
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
/*
There is a room with n lights which are turned on initially and 4 buttons on the wall. After performing exactly m unknown operations towards buttons, you need to return how many different kinds of status of the n lights could be.

Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given below:

    Flip all the lights.
    Flip lights with even numbers.
    Flip lights with odd numbers.
    Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...

 

Example 1:

Input: n = 1, m = 1.
Output: 2
Explanation: Status can be: [on], [off]

 

Example 2:

Input: n = 2, m = 1.
Output: 3
Explanation: Status can be: [on, off], [off, on], [off, off]

 

Example 3:

Input: n = 3, m = 1.
Output: 4
Explanation: Status can be: [off, on, off], [on, off, on], [off, off, off], [off, on, on].

 

Note: n and m both fit in range [0, 1000].
*/
class Solution {
  typedef bitset<3> bulbs;
  vector<function<bulbs(const bulbs &, int)>> ops;
  void prepare_ops(){
      ops.pb( [](const bulbs & x, int n){
          auto res = x;
          forall(i,0,n) res.flip(i);
          return res;
          });
      ops.pb( []( const bulbs & x, int n){
          auto res = x;
          forall(i,0,n) if( i%2 == 0 ) res.flip(i);
          return res;
          });
      ops.pb( []( const bulbs & x, int n){
          auto res = x;
          forall(i,0,n) if( i%2 != 0 ) res.flip(i);
          return res;
          });
      ops.pb( []( const bulbs & x, int n){
          auto res = x;
          forall(i,0,n) if( i%3 == 0 ) res.flip(i);
          return res;
          });
  }
  public:
    int flipLights(int n, int m) {
      if( n > 3 ) n = 3;
      prepare_ops();
      bulbs init("111");
      queue<bulbs> Q, P;
      Q.push(init);
      while( m-->0 ){
        debug("m=",m);
        unordered_set<bulbs> S;
        while( !Q.empty() ){
          auto x = Q.front(); Q.pop();
          debug("x = ", x );
          for(auto op : ops){
            auto y = op(x,n);
            if( S.count(y) == 0 ){
              debug("pushing ", y);
              S.insert(y);
              P.push(y);
            }
          }
        }
        swap(P,Q);
      }
      return Q.size();
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m; 
  Solution sol;
  cout << sol.flipLights(n,m) << endl;
  return 0;
}
