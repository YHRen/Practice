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
#include <string_view>
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
  int find_matching(int x, string_view & expression){
    int cnt = 1;
    for( int y = x+1; y < sz(expression); ++y ){
      if( expression[y] == '(' ) cnt ++;
      else if( expression[y] == ')' ){
        cnt --;
        if( cnt == 0 ) return y;
      }
    }
    return -1;
  }
  public:
    bool parseBoolExpr(string_view expression) {
      debug("expr=",expression);
      if( expression == "f" or expression == "(f)" or expression == "!(t)" ) return false;
      if( expression == "t" or expression == "(t)" or expression == "!(f)" ) return true;
      int n = sz(expression);
      if( expression[0] == '|' ){
        bool base = false;
        int i = 1;
        while( i < n ){
          if( expression[i] == '&' or expression[i] == '|' or expression[i] == '!' ){
            int upto = find_matching(i+1, expression);
            if( parseBoolExpr( expression.substr(i, upto-i+1) ) ) return true;
            else  i = upto;
          }else if( expression[i] == 't' ) return true;
          ++i;
        }
        return false;
      }else if( expression[0] == '&' ){
        debug("and");
        int i = 1;
        while(i<n){
          debug("i", i, expression[i]);
          if( expression[i] == '&' or expression[i] == '|' or expression[i] == '!' ){
            int upto = find_matching(i+1, expression);
            if( !parseBoolExpr( expression.substr(i, upto-i+1) ) ) return false;
            else i = upto;
          }else if( expression[i] == 'f' ) return false;
          i++;
        }
        return true;
      }else{ // !
        int i = 1;
        while( i < n ){
          if( expression[i] == '&' or expression[i] == '|' or expression[i] == '!' ){
            int upto = find_matching(i+1, expression);
            return !parseBoolExpr( expression.substr(i, upto-i+1) );
          }
          ++i;
        }
      }

      return true;
    }
};
int main( int argc, char * argv[] ){
  string str;
  cin >> str;
  Solution sol;
  cout << sol.parseBoolExpr(str) << endl;
  return 0;
}
