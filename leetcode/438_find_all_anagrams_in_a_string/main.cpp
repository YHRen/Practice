#include <vector>
#include <array>
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


#define INF              (int)1000000007
#define EPS              1e-9
#define pb               push_back
#define mp               make_pair
#define all(c)           c.begin(), c.end()
#define forall(i,a,b)    for(int i=a;i<(b);++i)
#define trav(a,x)        for(auto & a: x)
#define in(a,b)          ((b).find(a) != (b).end())
#define sz(c)            (int)(c).size()
#define input(a)         for(auto & x : a) cin >> x;

using namespace std;

typedef vector<int>      vi;
typedef pair<int,int>    ii;
typedef vector<vi>       vvi;
typedef vector<ii>       vii;
typedef long long        ll;

#ifdef DEBUG
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
public:
    vector<int> findAnagrams(string & s, string & p) {
      int m = sz(p), n = sz(s);
      if( n < m ) return {};
      vi target(26,0), run(26,0);
      for(auto c : p) target[c-'a'] +=1;
      forall(i,0,m-1){ 
        run[s[i]-'a'] += 1;
      }
      vi res;
      print_(target);
      print_(run);
      for(int tail = m-1; tail < n; ++tail ){
        run[s[tail]-'a'] += 1;
        print_(run);
        if( target == run ) res.pb(tail-m+1);
        run[s[tail-m+1]-'a'] -= 1;
      }
      return res;
    }
};
int main( int argc, char * argv[] ){
  string s,p;
  cin >> s >> p;
  Solution sol;
  auto res = sol.findAnagrams(s,p);
  print_(res);
  return 0;
}
