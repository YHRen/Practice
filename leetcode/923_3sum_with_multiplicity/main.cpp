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
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
      int n = A.size();
      int res = 0;
      vvi dict(101);
      for( int i = 0; i < n; ++i ){
        int x = A[i];
        dict[x].pb(i);
      }

      for( int i = 0; i < n; ++i ){
        for( int j = i+1; j < n; ++j ){
          int x = A[i];
          int y = A[j];
          int z = target - x - y;
          if( z>=0 && z <= 100 && !dict[z].empty() ){
            const vi & ids = dict[z];
            int cnt = ids.end() - upper_bound(all(ids), j);
            debug("i,j,", i,j,"A[i],A[j]", A[i], A[j], "z=",z,"cnt=",cnt)
            res += cnt;
            res %= INF;
          }
        }
      }
      return res;
    }
};

int main( int argc, char * argv[] ){
  //vi A = {1,1,2,2,3,3,4,4,5,5};
  // vi A = {1,1,2,2,2,2};
  int n; cin >> n;
  vi v(n); input(v);
  int t; cin >> t;
  Solution sol;
  //int ans = sol.threeSumMulti(A, 8);
  // int ans = sol.threeSumMulti(A, 5);
  int ans = sol.threeSumMulti(v,t);
  cout << ans << '\n';


  return 0;
}
