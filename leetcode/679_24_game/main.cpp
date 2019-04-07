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

// auto ____ =[]()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     return nullptr;
// }();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  vector<function<ii(ii, ii)> > ops;
public:
  Solution() {
    ops.pb([](ii a, ii b) {  // +
      ii ans;
      int c = __gcd(a.second, b.second);
      int ma = b.second / c, mb = a.second / c;
      ans.first = a.first * ma + b.first * mb;
      ans.second = a.second * ma;
      c = __gcd(ans.first, ans.second);
      return mp(ans.first / c, ans.second / c);
    });
    ops.pb([](ii a, ii b) {  // -
      int c = __gcd(a.second, b.second);
      int ma = b.second / c, mb = a.second / c;
      ii ans;
      ans.first = a.first * ma - b.first * mb;
      ans.second = a.second * ma;
      c = __gcd(ans.first, ans.second);
      return mp(ans.first / c, ans.second / c);
    });
    ops.pb([](ii a, ii b) {  // *
      int c;
      ii ans;
      ans.first = a.first * b.first;
      ans.second = a.second * b.second;
      c = __gcd(ans.first, ans.second);
      return mp(ans.first / c, ans.second / c);
    });
    ops.pb([](ii a, ii b) {  // /
      ii ans;
      int c;
      ans.first = a.first * b.second;
      ans.second = a.second * b.first;
      c = __gcd(ans.first, ans.second);
      if (c == 0) return mp(0, 0);
      return mp(ans.first / c, ans.second / c);
    });
  }

  bool C(ii num) {
    if (num.second == 1 and num.first == 24) return true;
    return false;
  }

  bool rec(const vi& v) {
    ii a = mp(v[0], 1), b = mp(v[1], 1), c = mp(v[2], 1), d = mp(v[3], 1);
    ii ans;
    forall(i, 0, 4) forall(j, 0, 4) forall(k, 0, 4) {
      if (C(ops[k](ops[j](ops[i](a, b), c), d))) return true;
      if (C(ops[k](ops[i](a, b), ops[j](c, d)))) return true;
      if (C(ops[k](a, ops[j](b, ops[i](c, d))))) return true;
    }
    return false;
  }
 public:
  bool judgePoint24(vector<int>& nums) {
    sort(all(nums));
    do {
      if (rec(nums)) return true;
    } while (next_permutation(all(nums)));
    return false;
  }
};
int main( int argc, char * argv[] ){
  vi v(4);
  input(v);
  Solution sol;
  cout << sol.judgePoint24(v) << '\n';
  return 0;
}
