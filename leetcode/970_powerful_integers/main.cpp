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
  vi single(int y, int bound){
    int x = 1;
    int by = int(log(double(bound))/log(double(y)))+1;
    vi ans;
    forall(i,0,by){
      if( x + 1 <= bound ) ans.pb(x+1);
      else break;
      x *= y;
    }
    return ans;
  }
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
      if( bound < 2 ) return {};
      if( bound == 2 ) return {2};
      if( x == 1 && y == 1 ) return {2};
      if( x == 1 || y == 1 ) return single( max(x,y), bound) ;
      vi ans;
      int bx = int(log(double(bound))/log(double(x)))+1;
      int by = int(log(double(bound))/log(double(y)))+1;
      int tmp = 1;
      forall(i,0,bx){
        if( tmp > bound ) break;
        int tmpy = 1;
        forall(j,0,by){
          if( tmp + tmpy <= bound ) ans.pb(tmp+tmpy);
          else break;
          tmpy *= y; 
        }
        tmp *= x;
      }
      sort(all(ans));
      ans.erase(unique(all(ans)), ans.end());
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
