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
    vector<int> pancakeSort(vector<int>& A) {
      int n = A.size();
      vi ans;
      print_(A);
      while( n > 0 ){
        auto itr = max_element(A.begin(), A.begin()+n);
        int idx = itr-A.begin();
        if( idx+1  == n ){
          debug("at place", n );
          n --; continue;
        }
        if( idx != 0 ){
          ans.pb( idx + 1 );
          reverse(A.begin(), A.begin()+idx+1);
          debug("at ",idx+1)
          print_(A);
        }
        ans.pb( n );
        reverse(A.begin(), A.begin()+n);
        debug("at ", n);
        debug(idx+1)
        print_(A);
        n --;
      }
      print_(A);
      return ans;
    }
};
int main( int argc, char * argv[] ){
  vi v = {3,2,4,1};
  Solution sol;
  auto ans = sol.pancakeSort(v);


  return 0;
}
