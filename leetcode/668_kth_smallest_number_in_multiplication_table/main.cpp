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

/*

Nearly every one have used the Multiplication Table. But could you find out
the k-th smallest number quickly from the multiplication table?

Given the height m and the length n of a m * n Multiplication Table, and a
positive integer k, you need to return the k-th smallest number in this table.

Example 1:

Input: m = 3, n = 3, k = 5
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6
3	6	9

The 5-th smallest number is 3 (1, 2, 2, 3, 3).

Example 2:

Input: m = 2, n = 3, k = 6
Output: 
Explanation: 
The Multiplication Table:
1	2	3
2	4	6

The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).

Note:

    The m and n will be in the range [1, 30000].
    The k will be in the range [1, m * n]
*/
auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
  int K,N,M;
  ii C(int x){
    int cnt = 0;
    int eq  = 0;
    forall(i,1,N+1){
      cnt += min(x/i,M);
      if( x/i <= M and x%i == 0 ) eq ++;
    }
    return {cnt,eq};
  }
  public:
    int findKthNumber(int m, int n, int k) {
      debug("m,n,k",m,n,k);
      if( k==1 or k == m*n ) return k;
      K = k;
      if( m<n ) swap(n,m);
      N = n, M = m;
      int lo = 1, hi = n*m;
      while( hi>=lo ){
        int mid = (lo+hi)/2;
        auto [tmp, eq] = C(mid);
        debug("mid =", mid, "lo =",lo,"hi =",hi);
        debug("  cnt = ", tmp, " eq = ", eq);
        forall(y,0,eq){ if( tmp-y == k ) return mid; }
        if( tmp < k ){
          debug("small");
          lo = mid+1;
        }else{
          hi = mid-1;
        }     
      }
      return lo;
    }

};

class Solution_Fast {
 public:
     int findKthNumber(int m, int n, int k) {
         int left = 1, right = m * n;
         while (left < right) {
             int mid = left + (right - left) / 2, cnt = 0, i = m, j = 1;
             while (i >= 1 && j <= n) {
                 if (i * j <= mid) {
                     cnt += i;
                     ++j;
                 } else {
                     --i;
                 }
             }
             if (cnt < k) left = mid + 1;
             else right = mid;
         }
         return right;
     }
 };
int main( int argc, char * argv[] ){
  int m,n,k; cin >> m >> n >> k;
  Solution sol;
  cout << sol.findKthNumber(m,n,k) << endl;
  return 0;
}
