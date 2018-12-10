#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
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
  bool is_valid(const vi & v){
    if( v[0] > 2 ) return false;
    if( v[0] == 2 && v[1] > 3 ) return false;
    if( v[2] > 5 ) return false;
    return true;
  }
  int to_num( const vi & v ){
    return (v[0] * 10+v[1])*60+(v[2]*10+v[3]);
  }
    string largestTimeFromDigits(vector<int>& A) {
      int max_time = -1;
      vi ans;
      sort(all(A));
      do{
        auto p = to_num(A);
        print_(A);
        debug("p=",p, is_valid(A));
        if( is_valid(A) && p > max_time ){ 
          max_time = p;
          ans = A;
        }
      }while( next_permutation(all(A)));
      if(max_time==-1) return "";
      else return to_string( ans[0]) + to_string(ans[1]) +":"+ to_string(ans[2]) + 
        to_string(ans[3]);
    }
};
int main( int argc, char * argv[] ){
  vi v(4); input(v);
  Solution sol;
  cout << sol.largestTimeFromDigits(v) << '\n';

  return 0;
}
