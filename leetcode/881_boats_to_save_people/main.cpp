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
    int numRescueBoats(vector<int>& people, int limit) {
      int ans = 0;
      map<int,int> cnt;
      for(auto x : people ) cnt[x] ++;
      sort(all(people));

      while( !cnt.empty() ){
        int w = cnt.rbegin() -> first, m = cnt.rbegin()->second; 
        cnt.erase(w);
        if( w + w <= limit ){
          while ( m >= 2 ){
            ans ++;
            m -= 2;
          }
        }
        if( m == 0 ) continue;
        while( m!= 0 and !cnt.empty() ){
          auto itr = cnt.upper_bound( limit-w );
          if( itr == cnt.begin() ){
            m -= 1;
            ans += 1;
          }else{
            -- itr;
            itr->second -= 1;
            m -= 1;
            ans += 1;
            if( itr->second == 0 ) cnt.erase(itr);
          }
        }
        if( cnt.empty() and m != 0 ){
          ans +=  m;
        }
      }
      return ans;

    }
};
int main( int argc, char * argv[] ){

  return 0;
}
