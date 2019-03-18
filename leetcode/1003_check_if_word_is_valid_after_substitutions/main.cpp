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
public:
    bool isValid(string S) {
      const string t ="abc";
      int n = sz(S);
      vi skip(n,false);
      if( S[0] != 'a' or S[n-1] != 'c' ) return false;
      vi ida, idb;
      forall(i,0,n){
        if( S[i] == 'a' ) ida.pb(i);
        if( S[i] == 'b' ) idb.pb(i);
        if( S[i] == 'c' ){
          if( ida.empty() or idb.empty() ) return false;
          int a = ida.back(), b = idb.back();
          ida.pop_back(); idb.pop_back();
          if( b < a ) return false;
          skip[i] = 1;
          for(int j = i-1; j > b; --j) if( skip[j] == false ) return false;
          skip[b] = 1;
          for(int j = b-1; j > a; --j) if( skip[j] == false ) return false;
          skip[a] = 1;
        }
      }
      return true;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
