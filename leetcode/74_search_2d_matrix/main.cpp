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
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if( matrix.empty() ) return false;
      for( const auto & row : matrix ) if( row.empty() ) return false;
      if( target < matrix[0][0] || target > matrix.back().back() ) return false;
      vector<int> heads(matrix.size());
      for( size_t i = 0; i < heads.size(); ++i ){
        heads[i] = matrix[i][0];
      }
      auto itr = lower_bound( heads.begin(), heads.end(), target );
      if( *itr == target ) return true;
      int idx = itr - heads.begin() - 1;
      auto itr2 = lower_bound( matrix[idx].begin(), matrix[idx].end(), target );
      if( *itr2 == target ) return true;
      else return false;
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int t,n,m; cin >> t >> n >> m;
  vector<vector<int>> mtx(n, vector<int>(m,0));
  for( auto & v : mtx ){
    input(v);
  }
  Solution s;
  if( s.searchMatrix( mtx, t ) ){
    cout << "YES\n";
  }else{
    cout << "NO\n";
  }


  return 0;
}
