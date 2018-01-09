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
    int numberOfArithmeticSlices(vector<int>& A) {
      int n = A.size(); if( n < 3 ) return 0;
      vi diff( n-1 );
      forall(i,1,n){
        diff[i-1] = A[i] - A[i-1];
      }
      int cnt = 1;
      long long int ans = 0;
      forall(i,0,n-2){
        if( diff[i+1] == diff[i] ){
          ++cnt;
        }else{
          if( cnt > 1 ){
            ans += cnt*(cnt-1)/2;
          }
          cnt = 1;
        }
      }
      if( cnt > 1 ) ans += cnt*(cnt-1)/2;
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin  >> n;
  vi v(n); for(auto& x : v ) cin >> x;
  Solution sol;
  cout << sol.numberOfArithmeticSlices(v) << '\n';

  return 0;
}
