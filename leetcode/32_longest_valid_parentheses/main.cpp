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
    int longestValidParentheses(string s) {
      int n = sz(s), res = 0;
      stack<int> stk;
      forall(i,0,n){
        if( s[i] == '(' ){
          stk.push(i);
        }else if( s[i] == ')' ){
          if( stk.empty() or s[stk.top()] == ')' ){
            stk.push(i);
          }else{
            stk.pop();
          }
        }
      }
      int r = n;
      while(!stk.empty()){
        int l = stk.top()+1;
        res = max(res, r-l);
        r = stk.top();
        stk.pop();
      }
      res = max(res, r-0);
      return res;
    }
};
int main( int argc, char * argv[] ){
  string str;
  cin >> str;
  Solution sol;
  cout << sol.longestValidParentheses(str) << endl;
  return 0;
}
