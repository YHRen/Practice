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
/******* Actual Code Starts Here *********/
class Solution {
  private:
    string get_roman( char one, char five, char ten, int digit){
      string ans = "";
      if( digit == 9 ){
        ans += one;
        ans += ten;
        digit = 0;
      }else if( digit == 4 ){
        ans += one;
        ans += five;
        digit = 0;
      }else if( digit >= 5 ){ 
        ans += five;
        digit -= 5;
      }
      forall(i,0,digit){
        ans += one;
      }
      debug("ans=",ans);
      return ans;
    }

  public:
    string intToRoman(int num) {
      string ans = "";
      int d[4];
      forall(i,0,4){
        d[i] = num % 10;
        num -= d[i] ;
        num /= 10;
        debug(d[i]);
      }
      ans += get_roman( 'M', '.', '.' , d[3] );
      ans += get_roman( 'C', 'D', 'M' , d[2] );
      ans += get_roman( 'X', 'L', 'C' , d[1] );
      ans += get_roman( 'I', 'V', 'X' , d[0] );
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int x; cin >> x;
  Solution sol;
  cout << sol.intToRoman(x) << '\n';

  return 0;
}
