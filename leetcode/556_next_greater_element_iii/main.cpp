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
    int nextGreaterElement(int n) {
      vi v; 
      while(n){
        v.pb(n%10);
        n/=10;
      }
      reverse(all(v));
      if(next_permutation(all(v))){
        bool flag = true;
        do{
        }while( v[0] == 0 and (flag=next_permutation(all(v))) );
        if( flag ){
          ll ans = 0;
          for(auto x : v){
            ans += x;
            ans *= 10;
          }
          ans /= 10;
          if( ans < static_cast<ll>(numeric_limits<int>::max()) )
            return ans;
        }
      }
      return -1;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  Solution sol;
  cout << sol.nextGreaterElement(n) << endl;
  return 0;
}
