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
/*

Given an array which consists of non-negative integers and an integer m, you
can split the array into m non-empty continuous subarrays. Write an algorithm
to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

    1 ≤ n ≤ 1000
    1 ≤ m ≤ min(50, n)

Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

*/
auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
  int n, M;
  vll u;
  bool C(ll x){
    int cnt = 1;
    auto itr = upper_bound(all(u),x);
    while( itr!=u.end() and cnt < M ){
      cnt ++;
      itr = upper_bound(itr, u.end(), x+*(itr-1));
    }
    if( itr == u.end() ) return true;
    else return false;
  }
public:
    int splitArray(vector<int>& v, int m) {
      n = sz(v);  M = m;
      if( m == n ) return *max_element(all(v));
      u.resize(n); u[0] = v[0];
      forall(i,1,n) u[i] = u[i-1] + v[i];
      ll lo = *max_element(all(v)), hi = u[n-1];
      print_(u);
      int res = -1;
      if( m == 1 ) return hi;
      while( hi>=lo ){
        int mid = (lo+hi)/2;
        debug("mid =",mid, "lo=",lo, "hi=",hi);
        if( C(mid) ){
          debug("success");
          res = mid;
          hi = mid-1;
        }else{
          debug("fail");
          lo = mid+1;
        }
      }
      return res;
      if( C(lo) ) return lo;
      else return res;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m; 
  vi v(n); input(v);
  Solution sol;
  cout << sol.splitArray(v,m) << endl;
  return 0;
}
