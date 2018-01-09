#include <vector>
#include <sstream>
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
/******* Actual Code Starts Here *********/

class Solution {
  string str;
  int    n;
  pair<string,int> decode( int idx ){
    if( idx == n ) return mp("",n);
    int r = idx + 1;
    while( r < n && str[r] !='[' ){
      ++r;
    }
    int  t = stoi( str.substr(idx, r-idx) );
    debug("idx=",idx,"t=",t);
    string tmp = "";
    char c = str[++r]; 
    while( c != ']' ){
      debug("c=",c);
      if( isdigit(c) ){ // c is digit
        auto rtn = decode( r );
        tmp += rtn.first;
        r = rtn.second;
      }else{
        tmp += c;
      }
      c = str[++r];
    }

    string ans = "";
    forall(_,0,t){
      ans += tmp;
    }
    return mp(ans, r);
  }


  public:
    string decodeString(string s) {
      if( s.empty() ) return s;
      this->str = s;
      this->n   = s.size();
      string ans = "";
      int idx = 0;
      for(;idx<n;++idx) if( isdigit(str[idx]) ){ break; }
      
      if( idx == n ){
        return s;
      }else{
        ans = str.substr(0, idx);
      }

      while( isdigit(str[idx]) && idx < n){
        auto tmp = decode(idx);
        ans += tmp.first;
        idx = tmp.second;
        debug("idx=",idx);
        ++idx;
        int y = idx;
        while( y < n && !isdigit(str[y])  ){
          debug("y",y,str[y]);
          ++y; }
        debug("y=",y);
        ans += str.substr(idx, y-idx);
        idx = y;
        debug("idx====",idx);
      }
      if( idx !=n ){
        ans += s.substr(idx, n-idx);
      }
      return ans;

    }
};
int main( int argc, char * argv[] ){
  int T; cin >> T;
  string str;
  Solution sol;
  while( T-- ){
    cin >> str;
    cout << sol.decodeString(str) << '\n';
  }

  return 0;
}
