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
    int longestOnes(vector<int>& A, int K) {
      int n = sz(A);
      if( K == 0 ){
        int ans = 0, tmp = 0;
        forall(i,0,n){
          if(A[i]){
            tmp+=1;
            ans = max(ans, tmp);
          } else{
            tmp = 0;
          }
        }
        return ans;
      }
      int max_len = 1;
      int tmp_len = 1;
      int left    = 0;
      if(A[0] == 0) K -= 1;
      forall(i,1,n){
        if( A[i] ){
          tmp_len ++;
          max_len = max(max_len, tmp_len);
        }else if( A[i] == 0 and K > 0 ){
          tmp_len ++;
          max_len = max(max_len, tmp_len);
          K --;
          if( left == -1 ) left = i;
        }else if( A[i] == 0 and K == 0){
          while(A[left]!=0){
            tmp_len --;
            left ++;
          }
          left ++;
        }
      }
      return max_len;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
