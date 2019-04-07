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
  int B, W;
  public:
  Solution():B(2), W(to_string(B).size()){}
  Solution(int base):B(base), W(to_string(B).size()){}
  string to_fw_str(int val){ // to fixed width string
    ostringstream oss;
    oss << setw(W) << setfill('0') << val;
    return oss.str();
  }
  string base(int N) {
    if( N < B ) return to_fw_str(N);
    else return base( N/B ) + to_fw_str(N%B);
  }
  string negbase(int N){
    if( N>=0 and N < B ) return to_fw_str(N);
    else return negbase(-(N/B) +( N<0?1:0) ) + to_fw_str( (N%B+B)%B );
  }
  string baseNeg2(int N){
    debug(N);
    if( N == 0 || N == 1) return to_string(N);
    else return baseNeg2(-(N>>1)) + to_string( N&1 );
  }

  string baseNeg2_binary_search(int N) {
    if( N == 0 ) return "0";
    vector<ll> pos, neg, cumpos, cumneg;
    pos.pb(1);
    forall(i,0,16){
      pos.pb(4L<<(2*i));
      neg.pb(2L<<(2*i));
    }

    cumpos = pos, cumneg = neg;
    forall(i,1,16){ cumpos[i]+=cumpos[i-1]; }
    forall(i,1,16){ cumneg[i]+=cumneg[i-1]; }
    vi ans(32,0);
    while(N!=0){
      if( N > 0 ){
        auto idx = lower_bound(all(cumpos),N) - cumpos.begin();
        ans[idx*2] = 1;
        N -= pos[idx];
      }else{
        auto idx = lower_bound(all(cumneg), -N) - cumneg.begin();
        ans[idx*2+1] = 1;
        N += neg[idx];
      }
    }
    reverse(all(ans));
    string res;
    for(auto x : ans ){
      if( res.empty() and x == 0 ) continue;
      else res += to_string(x);
    }
    return res;
  }
};
int main( int argc, char * argv[] ){
  int n ; cin >> n;
  Solution sol(11);
  cout << sol.base(n) << endl;
  cout << sol.negbase(n) << endl;
  cout << sol.baseNeg2(n) << endl;
//  cout << sol.baseNeg2(n) << endl;
  return 0;
}
