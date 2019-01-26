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
  vi digits;
  vi cnt_digits;
  int rec( string num ){
    if( num.empty() ) return 0;
    int ans = 0;
    int n = num.size();
    int x = num[0] - '0';
    if( n == 1 ) return upper_bound(all(digits), x) - digits.begin();
    debug("rec, ", num, "x=",x);
    auto itr = lower_bound(all(digits), x );
    debug("itr",itr-digits.begin(), digits.size());
    if( itr == digits.end() ){
      // all digits smaller than this digit
      ans = cnt_digits[n];
      return ans;
    }else if( *itr > x ){ 
      // at least one digit larger than this digit
      ans = cnt_digits[n-1] * (itr-digits.begin());
      return ans;
    }else if( *itr == x ){
      // one digits equal to this
      debug("found one", itr-digits.begin());
      ans = cnt_digits[n-1] * (itr-digits.begin());
      debug("ans=",ans);
      ans += rec( num.substr(1) );
      debug("ans=",ans);
      return ans;
    }else{
      return -1;
    }
    return ans;
  }
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
      if( D.empty() ) return 0;
      int m = D.size();
      int n = to_string(N).size();
      debug("m,n",m,n);
      cnt_digits.pb(0);
      cnt_digits.pb(m);
      forall(i,1,n) cnt_digits.pb( *cnt_digits.rbegin() * m );
      debug("cnt digits");
      print_(cnt_digits);

      for(auto s : D ){ digits.pb(stoi(s));}
      print_(digits);

      int ans = 0;
      forall(i,1,n){
        debug("i ", i, "digits");
        ans += cnt_digits[i];
      }
      debug("ans = ", ans);
      ans += rec(to_string(N));
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  vi v(n); input(v);
  vector<string> S; for(auto x : v ) S.pb(to_string(x));
  Solution sol;
  cout << sol.atMostNGivenDigitSet(S,m) << '\n';


  return 0;
}
