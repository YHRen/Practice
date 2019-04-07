#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF                         (int)1000000007
#define EPS                         1e-9

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<(b);++i)
#define trav(a,x)                   for(auto & a: x)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define sz(c)                       (int)(c).size()
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

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

auto ____ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
public:
    vector<int> dailyTemperatures_mem(vector<int>& T) {
      // knowning T[i] \in [30, 100]
      vi C(71, INF);
      int n = sz(T);
      vi res(n, 0);
      for(int i = n-1; i >= 0; -- i){
        int x = T[i] - 30;
        int ans = INF;
        for(int j = x+1; j < 71; ++j ){
          ans = min( ans, C[j] - i );
        }
        if( ans > n ) res[i] = 0;
        else res[i] = ans;
        C[x] = i;
      }
      return res;
    }

    vector<int> dailyTemperatures(vector<int>& T) {
      int n = sz(T);
      vi res(n, 0);
      stack<int> S;
      forall(i,0,n){
        while( !S.empty() and T[S.top()] < T[i] ){
          res[S.top()] = i - S.top();
          S.pop();
        }
        S.push(i);
      }
      return res;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
