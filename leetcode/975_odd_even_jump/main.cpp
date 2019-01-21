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
    int oddEvenJumps(vector<int>& A) {
      int n = A.size();
      vi even_true(n,0);
      vi odd_true(n,0);
      even_true[n-1]=1;
      odd_true[n-1] =1;
      map<int,int> dict;
      dict.insert(mp(A[n-1],n-1));
      int ans = 1;
      for(int i = n-2; i > -1; --i){
        int x = A[i];
        auto itr = dict.lower_bound(x);
        if( itr != dict.end() and even_true[itr->second] ){
          odd_true[i] = 1;
          ans += 1;
        }
        itr = dict.upper_bound(x);
        if( itr != dict.begin() ){
          --itr;
          if( odd_true[itr->second] ){
            even_true[i] = 1;
          }
        }
        dict[x] = i;
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n); input(v);
  Solution sol;
  cout << sol.oddEvenJumps(v) << '\n';

  return 0;
}
