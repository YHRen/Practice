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
  public:
    bool checkValidString(string s) {
      vi slack, left;
      forall(i,0,s.size()){
          char c = s[i];
        if( c == '(' ){
          left.pb(i);
        }else if( c == '*' ){
          slack.pb(i);
        }else{ // ')'
          if( left.size() > 0 ){
            left.pop_back(); 
          }else if( slack.size() > 0 ){
            slack.pop_back();
          }else{
            return false;
          }
        }
      }
      debug("slack = ", slack.size() , "left = ",left.size());
      print_(slack);
      print_(left);

      if( left.empty() ) return true;
      if( slack.size() >= left.size() ){
        int l = slack.size()-1;
        int r = left.size() -1;
        debug("l,r",l,r);
        for(; l >= 0 && r >= 0; /* */){
          debug("l,r,",l,r,slack[l],left[r]);
          if( slack[l] > left[r] ){
            l --;
            r --;
          }else{
            return false;
          }
        }
        return r<0;
      }
      return false;
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  cout << sol.checkValidString(str) << '\n';

  return 0;
}
