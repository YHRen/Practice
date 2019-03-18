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
  pair<string,bool> compress_blocks( const string & s, bool is_in_block ){
    int n = sz(s);
    int idx = 0;
    string ans;
    do{
      if( !is_in_block ){
        auto nxt1 = s.find("//", idx); /**/ //
        auto nxt2 = s.find("/*", idx);
        if( nxt1 == string::npos and nxt2 == string::npos ){
          ans += s.substr(idx);
          return mp(ans,false);
        }else if( nxt1 < nxt2 ){
          string tmp = s.substr(idx, nxt1-idx);
          if( !tmp.empty() ) ans += tmp;
          return mp(ans,false); // not enter comment
        }else{
          string tmp = s.substr(idx,nxt2-idx);
          if( !tmp.empty() ) ans += tmp;
          idx = nxt2+2;
          is_in_block = true;
        }
      }else{ // is in block
        auto nxt = s.find("*/", idx); // */
        if( nxt != string::npos ){
          //string tmp = s.substr(idx, nxt-idx);
          //if( !tmp.empty() ) ans += tmp;
          idx = nxt+2;
          is_in_block = false;
        }else{
          //enter block
          return mp(ans,true);
        }
      }
    }while(idx!=n);
    return mp(ans,is_in_block);
  }
  
  public:
    vector<string> removeComments(vector<string>& source) {
      vector<string> ans;
      int n = sz(source);
      bool is_block = false;
      forall(i,0,n){
        auto tmp = compress_blocks(source[i], is_block);
        if( !tmp.first.empty() ){
          if( is_block ) *ans.rbegin()+=tmp.first;
          else ans.pb(tmp.first);
        }
        is_block = tmp.second;
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
