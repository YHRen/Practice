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
    int minFlipsMonoIncr(string S) {
        int n0 = count_if(all(S), [](char c){ return c == '0'; });
        int res = S.size()+1;
        int m0 = 0, m1= 0;
        for( auto c: S){
            if( c == '0' ) m0 ++; 
            else m1 ++; 
            res = min( res, n0-m0+m1 );
        }
        return min(res, n0);
    }
};
int main( int argc, char * argv[] ){
    Solution sol;
    cout << sol.minFlipsMonoIncr("00011000") << '\n';
    cout << sol.minFlipsMonoIncr("00110") << '\n';
    cout << sol.minFlipsMonoIncr("010110") << '\n';
    cout << sol.minFlipsMonoIncr("00011000") << '\n';
    cout << sol.minFlipsMonoIncr("01111010011111110100000101110100011000000010011010") << '\n';


  return 0;
}
