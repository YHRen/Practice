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
    string strWithout3a3b(int A, int B) {
      string ans = "";
      vector<string> v;
      bool flag = A > B;
      if( A < B ) swap(A,B);
      while( A > 0 and B>0 ){
        v.pb("ab");
        A--;
        B--;
      }
      debug("v.size()");
      forall(i,0,v.size()){
        if( A == 0 ) break;
        v[i] = "aab";
        A--;
      }
      if( A > 0 ){
        if( A == 1 ){
          v.pb("a");
        }else if( A == 2 ){
          v.pb("aa");
        }
      }
      for(auto x : v ) ans += x;
      if( !flag ){
        for(char & c : ans){
          if ( c == 'a' ) c ='b';
          else (c ='a');
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int a,b; cin >> a >> b;
  Solution sol;
  cout << sol.strWithout3a3b(a,b) << '\n';

  return 0;
}
