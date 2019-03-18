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
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF                         (int)1000000007
#define EPS                         1e-9

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<(b);++i)
#define trav(a,x)                   for(auto & a: x)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define sz(c)                       (int)(c).size()
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

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

auto ____ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      if(matrix.empty()) return;
      int n = sz(matrix), m = sz(matrix[0]);
      bool is_1st_col = false;
      forall(i,0,n) if( matrix[i][0] == 0 ) is_1st_col=true;
      bool is_1st_row = any_of(all(matrix[0]), [](int x){ return x == 0; });
      forall(i,1,n) 
        forall(j,1,m)
          if( matrix[i][j] == 0 )
            matrix[i][0] = matrix[0][j] = 0;
      forall(i,1,n)
        if( matrix[i][0] == 0 ) 
          matrix[i].assign(m, 0);
      forall(j,1,m)
        if( matrix[0][j] == 0 ) 
          forall(i,0,n)
            matrix[i][j] = 0;
      if( is_1st_row ){
        matrix[0].assign(m,0);
      }
      if( is_1st_col ){
        forall(i,0,n) 
          matrix[i][0] = 0;
      }
      return;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
