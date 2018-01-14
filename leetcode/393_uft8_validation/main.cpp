#include <vector>
#include <bitset>
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
public:
    bool validUtf8(vector<int>& data) {
      int cnt = 0;
      const int is_data = (1<<7);
      for( const auto & x : data ){
        if( cnt == 0 ){
          if( x < is_data ) continue;
          if( ( x >> 5 ) == 0b110 ){
            cnt = 1;
          }else if( ( x >> 4 ) == 0b1110 ){
            cnt = 2;
          }else if( ( x >> 3 ) == 0b11110 ){
            cnt = 3;
          }else{
            return false;
          }
        }else{
          cnt --;
          if( ( x >> 6 ) != 0b10 ) return false;
        }
      }
      return cnt == 0;
    } 
};

int main( int argc, char * argv[] ){
  bitset<8> x (255);
  cout << x << '\n';
  cout << (255 < (1<<7))<<'\n';
  cout << 0b1110 << '\n';
  int n; cin >> n;
  vi v(n); input(v);
  Solution sol;
  cout << sol.validUtf8(v) << '\n';
  return 0;
}