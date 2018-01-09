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
class Solution {
  private:
    bool search_aux(
        int rlo, int rhi,
        int clo, int chi,
        const vector<vector<int>> & matrix,
        int target){
      if( rlo > rhi || clo > chi ) return false;
      
      int rmid = (rlo+rhi)/2;
      if( matrix[rmid][clo] > target ){
        // search upper matrix
        return search_aux( rlo, rmid-1, clo, chi, matrix, target );
      }else if( matrix[rmid][chi] < target ){
        // search for lower matrix
        return search_aux( rmid+1, rhi, clo, chi, matrix, target );
      }
      // in between : row[0] < target < row[end]
      auto itr = lower_bound( matrix[rmid].begin(),
          matrix[rmid].end(), target );
      if( *itr == target ) return true;
      // matrix[rmid][cmid] < target and  
      // matrix[rmid][cmid+1] > target
      int cmid = itr - matrix[rmid].begin() - 1;

      // search for lower left submatrix and upper right submatrix
      return 
        search_aux( rmid+1, rhi, clo, cmid, matrix, target) 
          | search_aux( rlo, rmid-1, cmid+1, chi, matrix, target );
    }
      
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if( matrix.empty() ) return false;
      for( const auto & row : matrix ) if( row.empty() ) return false;
      if( target < matrix[0][0] || target > matrix.back().back() ) return false;
      return search_aux( 
          0, matrix.size() -1, 
          0, matrix[0].size()-1,
          matrix, target);
    }
};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int T,n,m; cin >> T >> n >> m;
  vector<vector<int>> mtx(n, vector<int>(m, 0) );
  for( auto & row : mtx ) input(row);
  Solution s;
  while(T--){
    int x ;
    cin >> x;
    if( s.searchMatrix( mtx, x ) ){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }
  return 0;
}
