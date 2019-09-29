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
  string str;
  int n;
  vi matching;
  void init_matching(){
    matching.resize(n,-1);
    stack<int> S;
    forall(i,0,n){
      if( str[i] == '(' ){
        S.push(i);
      }else if( str[i] == ')' ){
        matching[S.top()] = i;
        S.pop();
      }
    }
  }

  string solve(int i, int j){
    string ans = "";
    debug("at ",i,j,str.substr(i,j-i));
    for(; i < j; ){
      if( str[i] == '(' ){
        string tmp = solve( i+1, matching[i] );
        reverse(all(tmp));
        ans += tmp;
        i = matching[i]+1;
      }else{
        ans += str[i++];
      }
    }
    debug("return ", ans);
    return ans;
  }
  
  public:
    string reverseParentheses(string s) {
      stack<int> S;
      forall(i,0,sz(s)){
        if( s[i] == '(' ){
          S.push(i);
        }else if( s[i] == ')' ){
          reverse(s.begin()+S.top(), s.begin()+i);
          S.pop();
        }
      }
      string ans = "";
      for(auto c : s){
        if( c != ')' and c != '(' ){
          ans += c;
        }

      }
      return ans;
      //str = move(s);
      //n = sz(str);
      //init_matching();
      //return solve(0,n);
    }
};
int main( int argc, char * argv[] ){
  string str;
  cin >> str;
  Solution sol;
  cout << sol.reverseParentheses( str ) << '\n';
  return 0;
}
