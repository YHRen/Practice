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
    int minAddToMakeValid(string S) {
      int n = S.size();
      if( n == 0 ) return 0;
      int open  = 0;
      int close = 0;
      int res = 0;
      for( char c : S ){
        if( c == '(' ){
          open ++;
        }else if( c == ')' && open > 0 ){
          open --;
        }else{
          res ++;
        }
      }
      return res+open;
    }
};

int main( int argc, char * argv[] ){
  string s1 = "())";
  string s2 = "(((";
  string s3 = "()";
  string s4 = "()))((";
  Solution sol;
  cout << sol.minAddToMakeValid(s1) << '\n';
  cout << sol.minAddToMakeValid(s2) << '\n';
  cout << sol.minAddToMakeValid(s3) << '\n';
  cout << sol.minAddToMakeValid(s4) << '\n';

  return 0;
}
