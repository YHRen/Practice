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
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
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

// std::ios::sync_with_stdio(false);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/

class Solution {
  public:
    int minKBitFlips(vector<int>& A, int K) {
      if( K == 1 ) return count_if(all(A),[](int x){ return x == 0; });
      int n = A.size();
      int ans = 0;
      deque<int> flips;
      forall(i,0,n){
        if( !flips.empty() and flips.front() == i ) flips.pop_front();
        int x = A[i];
        debug("i,",i,"ans=",ans,"deque size = ", flips.size());
        if( !flips.empty() ){
          int num = flips.size();
          print_(flips);
          debug("num=",num);
          if( num%2 ) x ^= 1;
        }
        debug("i,x",i,x);
        if( x == 0 ){
          debug("x = 0");
          if( i > n-K ) return -1;
          flips.pb(i+K);
          ans ++;
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n, k; cin >> n >> k;
  vi v(n);input(v);
  Solution sol;
  cout << sol.minKBitFlips(v,k) << '\n';

  return 0;
}
