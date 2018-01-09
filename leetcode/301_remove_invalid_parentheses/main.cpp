#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
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

#define bg     begin()
#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi>  vvi;
typedef vector<ii>  vii;

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

// std::ios::sync_with_stdio(false);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  int n;
  vector<string> ans;
  vector<char>   p = {'(',')'};
  void solve(string & s, int si, int sj, int rev){
    int left = 0;
    forall(i, si, s.size()){
      if( s[i] == p[rev] ) left ++;
      else if( s[i] == p[rev^1] ) left --;
      if( left < 0 ){
        debug("left<0",si,sj,i);
        forall(j,sj,i+1){
          if( s[j] == p[rev^1] && (j==sj || s[j-1] != p[rev^1] ) ){
            string t = s.substr(0,j) + s.substr(j+1);
            debug("solve t,i,j,rev",t,i,j,rev);
            solve(t,i,j,rev);
          }
        }
        return ;
      }
    }
    string rs = s;
    reverse( all(rs) );
    if( p[rev] == '(' ){
      solve( rs, 0, 0, rev^1 );
    }else{
      ans.pb(rs);
    }
  }

  public:
    vector<string> removeInvalidParentheses(string s) {
      int n = s.size();
      debug("n=",n);
      solve(s,0,0,0);
      return ans;
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  debug("str=",str);
  auto ans = sol.removeInvalidParentheses(str);
  print_(ans);

  return 0;
}
