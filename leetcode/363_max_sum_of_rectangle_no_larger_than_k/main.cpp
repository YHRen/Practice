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
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:

Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2 
Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
             and 2 is the max number no larger than k (k = 2).

Note:

    The rectangle inside the matrix must have an area > 0.
    What if the number of rows is much larger than the number of columns?

 */
auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
vvi transpose( vvi & mtx ){
  int n = sz(mtx), m = sz(mtx[0]);
  vvi res(m, vi(n));
  forall(i,0,n) forall(j,0,m) res[j][i] = mtx[i][j];
  return res;
}

class Solution {
      vi cum;
      int n,m,k,res;

      void get_cum(int top, int bot, const vvi & mtx ){
        cum = mtx[top];
        forall(i,top+1,bot){
          forall(j,0,m){
            cum[j] += mtx[i][j];
          }
        }
      }

      void try_update_res(){
        forall(j,1,m) cum[j] += cum[j-1]; 
        set<int> S;
        S.insert(0);
        forall(j,0,m){
          debug("j",j,cum[j]);
          auto itr = S.upper_bound( cum[j]-k );
          if( itr != S.end() ){
            debug("updating, ", cum[j], *itr);
            res = max(res, cum[j] - *itr );
          }
          S.insert(cum[j]);
        }
      }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
      vvi mtx;
      if( sz(matrix) > sz(matrix[0]) * 2 ) mtx = transpose(matrix);
      else mtx = matrix;
      n = sz(mtx), m = sz(mtx[0]), this->k = k+1;
      res = numeric_limits<int>::min();
      cum.resize(m,0);
      forall(i,0,n){
        forall(ii,i+1,n+1){
          debug("top, bot", i, ii );
          get_cum(i,ii,mtx);
          print_(cum);
          try_update_res();
          debug("res=",res);
        }
      }
      return res;
    }
};

/// int best_cumulative_sum(const vi & v ,int K){
///   debug("k=",K);
///   set<int> cumset;
///   cumset.insert(0);
///   int best=0,cum=0;
///   for(auto x : v ){
///     cum+=x;
///     auto sit=cumset.upper_bound(cum-K);
///     if(sit!=cumset.end())best=max(best,cum-*sit);
///     debug("best = ", best);
///     cumset.insert(cum);
///     print_(cumset);
///   }
///   return best;
/// };
/// int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
///     if (matrix.empty()) return 0;
///     int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
///     for (int l = 0; l < col; ++l) {
///         vector<int> sums(row, 0);
///         for (int r = l; r < col; ++r) {
///             for (int i = 0; i < row; ++i) {
///                 sums[i] += matrix[i][r];
///             }
///             
///             // Find the max subarray no more than K 
///             set<int> accuSet;
///             accuSet.insert(0);
///             int curSum = 0, curMax = INT_MIN;
///             for (int sum : sums) {
///                 curSum += sum;
///                 set<int>::iterator it = accuSet.lower_bound(curSum - k);
///                 if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
///                 accuSet.insert(curSum);
///             }
///             res = std::max(res, curMax);
///         }
///     }
///     return res;
/// }
int main( int argc, char * argv[] ){
  int n, m, k; cin >> n >> m >> k; 
  vvi mtx(n, vi(m));
  for( auto & v: mtx ){ input(v); }
  Solution sol;
  cout << sol.maxSumSubmatrix(mtx,k) << endl;
  return 0;
}
