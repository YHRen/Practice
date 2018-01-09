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
  public:
    int wiggleMaxLength(vector<int>& v) {
      if( v.size() < 2 ) return v.size();
      int n = v.size();
      vector<char> diff;
      int k = 0;
      forall(i,1,n){
        int d = v[i] - v[i-1];
        if( d == 0 ){
          k++;
        }else if( d > 0 ){
          diff.pb(1);
        }else{
          diff.pb(0);
        }
      }
      if( diff.size() <= 1 ) return n-k;
      forall(i,1,diff.size()){
        if( !(diff[i-1] ^ diff[i]) ){
          ++k;
        }
      }
      return n-k;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n);
  for( auto & x : v ) cin >> x;
  Solution sol;
  cout << sol.wiggleMaxLength(v) << '\n';

  return 0;
}
