#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
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
    int sumSubarrayMins(vector<int>& A) {
      int n = A.size();
      vii v;
      forall(i,0,n) v.pb(mp(A[i],i));
      sort(all(v));
      int l = v[0].second, r = v[0].second;

      set<int> bars;
      bars.insert(-1);
      bars.insert(n);

      long long ans = 0;
      forall(i,0,n){
        int idx = v[i].second;
        int val = v[i].first;
        auto itr = bars.lower_bound(idx);
        int right = *itr;
        --itr;
        int left = *itr;
        long long tmp = val*(idx-left)*(right-idx);
        ans += tmp;
        ans %= INF;
        bars.insert(idx);
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n ; cin >> n;
  vi v(n); input(v);
  Solution sol;
  cout << sol.sumSubarrayMins(v) << '\n';

  return 0;
}
