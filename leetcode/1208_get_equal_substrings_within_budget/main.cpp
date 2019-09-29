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
    int equalSubstring(string s, string t, int maxCost) {
      int n = sz(s);
      vi v(n,0);
      forall(i,0,n) v[i] = abs(s[i]-t[i]);

      int run = 0, left = 0, ans = 0;
      forall(i,0,n){
        if( v[i]+run <= maxCost ){
          run += v[i];
          ans = max(ans, i-left+1);
        }else{
          while(left < i and v[i] + run > maxCost ){
            run -= v[left];
            left ++;
          }
          if( v[i] + run > maxCost ){ 
            left = i+1;
            run = 0;
          }else{
            run += v[i];
            ans = max(ans, i-left+1);
          }
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  string s,t ;cin >> s >>t;
  int n; cin >> n; 
  Solution sol;
  cout << sol.equalSubstring(s,t,n) << endl;
  return 0;
}
