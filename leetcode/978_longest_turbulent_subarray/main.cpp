#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
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

#define bg     begin()
#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi>  vvi;
typedef vector<ii>  vii;

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

// std::ios::sync_with_stdio(false);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
      int n = A.size();
      if( n == 1 ) return 1;
      vi v(n-1);
      forall(i,1,n){
        if( A[i] > A[i-1] ) v[i-1] = -1;
        else if( A[i] < A[i-1]) v[i-1] = 1;
        else v[i-1] = 0;
      }

      int x = 0, l=0;
      int max_len = 0;
      print_(v);
      forall(i,0,n-1){
        if( v[i] == 0 ){
          x =  0;
          l = 0;
          continue;
        }
        if( i > 0 and v[i] == v[i-1]){
          x = v[i];
          l = 1;
          continue;
        }
        x += v[i];
        l += 1;
        debug(x,l,v[i]);
        if( x > 1 ){
          x = 1;
          l = 1;
        }else if( x < -1 ){
          x = -1;
          l = 1;
        }else{
          max_len = max(l, max_len);
        }
      }
      return max_len + 1;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n); input(v);
  Solution sol;
  cout << sol.maxTurbulenceSize(v) << '\n';

  return 0;
}
