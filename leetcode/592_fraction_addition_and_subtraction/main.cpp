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
  void to_number(string && str, int & a, int & b){
    int idx = str.find('/');
    a = stoi(str.substr(0,idx-0));
    b = stoi(str.substr(idx+1));
  }
  public:
    string fractionAddition(string expr) {
      if( expr[0] != '-' ) expr = "+"+expr;
      int N = sz(expr);
      int n = 0, m = 1;
      for(int i = 0; i != -1; i=expr.find_first_of("+-",i+1)){
        debug("i=",i, "n/m",n,m, expr.substr(i,4));
        int a,b,c;
        int next_idx = expr.find_first_of("+-",i+1);
        if( next_idx==-1 ) next_idx = N;
        debug("next_idx=",next_idx,N,"i=",i, expr.substr(i,next_idx-i));
        to_number( expr.substr(i, next_idx-i), a,b );
        debug("ab=",a,b);
        c = __gcd(m,b);
        n*=(b/c), a*=(m/c);
        debug("a,b,c,n,m",a,b,c,n,m);
        n += a;
        //if(expr[i]=='+') n += a;
        //else n-=a;
        m*=(b/c);
        debug("n/m",n,m);
      }
      string ans;
      if(n<0){
        ans+="-";
        n = -n;
      }
      if( n == 0 ) m = 1;
      else{
        int c = __gcd(n,m);
        n /= c, m /= c;
      }
      ans+=to_string(n)+"/"+to_string(m);
      return ans;
    }
};
int main( int argc, char * argv[] ){
  string str;
  cin >> str;
  Solution sol;
  cout << sol.fractionAddition(str) << endl;

  return 0;
}
