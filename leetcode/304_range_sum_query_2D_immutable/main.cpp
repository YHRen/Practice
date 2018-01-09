#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <cmath>
#include <cassert>

#define input(v)                  for(int i = 0; i < v.size(); ++i){ cin >> v[i]; }

// numeric_limits
#define INF                         (int)1e9
#define EPS                         1e-9

#define bitcount                    __builtin_popcount
#define gcd                         __gcd

#define forall(i,a,b)               for(int i=a;i<b;i++)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define mp                          make_pair

#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
typedef unsigned long long int ull_t;
typedef long long int           ll_t;

using namespace std;

#ifdef DEBUG
#define debug(args...)            {dbg,args; clog<<endl;}
#define print_( a )               for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )           for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)             // Just strip off all debug tokens
#define print_( a )               // skip
#define printPair_( a )           // skip
#endif
struct debugger
{
  template<typename T> debugger& operator , (const T& x)
  {    
    clog << x << " ";    
    return *this;    
  }
} dbg;

/******* Actual Code Starts Here *********/
// https://leetcode.com/problems/range-sum-query-2d-immutable/
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]
// 
// sumRegion(2, 1, 4, 3) -> 8
// sumRegion(1, 1, 2, 2) -> 11
// sumRegion(1, 2, 2, 4) -> 12
//
// solve: the idea is similar to the 1D case.
// ... build a cumulative matrix A, where A[i][j] is the cumsum upto i and j inclusive.
// ... for query row_i, row_j, col_i, col_j, return the difference between cumsum.
// ... be careful of inclusion-exclusion principle
class NumMatrix {
  private:
    vector<vector<int>> cumsum;
  public:
    NumMatrix(vector<vector<int>> &matrix) {
      if( matrix.empty() || matrix.at(0).empty() ) return ;
      // todo: see if matrix is valid, namely each row has the same size
      cumsum = matrix;
      for( int i = 1; i < cumsum.size(); ++i ) cumsum[i][0] += cumsum[i-1][0];
      for( int j = 1; j < cumsum[0].size(); ++j ) cumsum[0][j] += cumsum[0][j-1];
      for( int i = 1; i < cumsum.size(); ++i ){
        for( int j = 1; j < cumsum[i].size(); ++j ){
          cumsum[i][j] += cumsum[i][j-1] + cumsum[i-1][j] - cumsum[i-1][j-1];
        }
      }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
      // input check
      if( row1 > row2 ) swap(row1, row2);
      if( col1 > col2 ) swap(col1, col2);
      if( row1 != 0 && col1 != 0 ){
        // inclusion-exclusion
        return cumsum[row2][col2] 
          - cumsum[row1-1][col2] 
          - cumsum[row2][col1-1] 
          + cumsum[row1-1][col1-1];
      }else if( row1 == 0 && col1 == 0 ){
        return cumsum[row2][col2];
      }else if( row1 != 0 ){ // col1 == 0
        return cumsum[row2][col2] - cumsum[row1-1][col2];
      }else{ // row1 ==0 && col1 != 0
        return cumsum[row2][col2] - cumsum[row2][col1-1];
      }
    }
};


// Your NumMatrix object will be instantiated and called as such:
// // NumMatrix numMatrix(matrix);
// // numMatrix.sumRegion(0, 1, 2, 3);
// // numMatrix.sumRegion(1, 2, 3, 4);
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);




  return 0;
}
