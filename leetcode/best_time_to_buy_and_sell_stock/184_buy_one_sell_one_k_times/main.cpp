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
    int maxProfit(int k, vector<int>& v) {
      if( v.size() < 2 ) return 0;
      int n = v.size();
      if( k > n/2 ){
        int res = 0;
        forall(i,1,n) if( v[i] > v[i-1] ) res += v[i]-v[i-1]; 
        return res;
      }
          
      k = min( k, n/2);
      vector<int> buy(k+1, -INF);
      vector<int> profit(k+1, 0);
      for(auto x : v ){
        forall(i,0,k){
          profit[i] = max( profit[i], buy[i] + x );
          buy[i] =  max( buy[i], profit[i+1] - x );
        }
      }
      return profit[0];
    }
};
int main( int argc, char * argv[] ){
  int n, k; cin >> n >> k;
  vi v(n); input(v);
  Solution sol;
  cout << sol.maxProfit(k, v) << '\n';

  return 0;
}
