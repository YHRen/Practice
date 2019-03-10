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
    int largestSumAfterKNegations(vector<int>& A, int K) {
      int n = sz(A);
      int min_elem = INF;
      int min_idx = 0;
      sort(all(A));
      forall(i,0,n){
        if(K > 0 and A[i] < 0){
          A[i] = -A[i];
          if( A[i] < min_elem ){
            min_elem = A[i];
            min_idx = i;
          }
          K--;
          if( K == 0 ) break;
        }else if( K>0 and A[i] >= 0 ){
          if( A[i] < min_elem ){
            min_elem = A[i];
            min_idx = i;
          }
          if(K%2 == 0){
            K = 0;
            break;
          }else{
            A[min_idx] = -A[min_idx];
            K = 0;
            break;
          }
        }
      }
      return accumulate(all(A),0);
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
