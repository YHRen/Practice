#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <cmath>
#include <cassert>

#define input(v)                  for(int i = 0; i < v.size(); ++i){ cin >> v[i]; }

// numeric_limits
#define INF                         (int)1e9
#define EPS                         1e-9

#define bitcount                    __builtin_popcount
#define gcd                         __gcd

#define forall(i,a,b)               for(int i=a;i<b;i++)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define mp                          make_pair

#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
typedef unsigned long long int ull_t;
typedef long long int           ll_t;

using namespace std;

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

/******* Actual Code Starts Here *********/
// https://leetcode.com/problems/simplify-path/
//
// Given an absolute path for a file (Unix-style), simplify it.
//
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// Corner Cases:
//
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".

class Solution {
  public:
    string simplifyPath(string path) {
      if( path.empty() || path[0] != '/' || 
          (path.size() == 1 && path[0] == '/') ){
        return "/";
      }
      if( path.back() != '/' ){
        path += '/';
      }

      vector<string> tokens;
      size_t idx = 1;
      while( idx < path.length()-1 ){
        size_t j = path.find( '/', idx );
        debug( j );
        if( j == string::npos ){
          break;
        }
        if( j == idx ){ // the case "//"
          idx ++ ;
          continue;
        }
        size_t len = j-idx;
        auto tmp = path.substr(idx, len);
        tokens.push_back(tmp);
        idx += len+1 ;
      }

      if( tokens.empty() ) return "/";
      deque<string> S;
      for( auto s : tokens ){
        debug(s);
        if( s=="..") {
          debug("equal");
        } else {
          debug("unequal");
        }
        if( s.compare("..") == 0){
          if( S.empty() ){
            continue;
          }else{
            debug("pop");
            S.pop_back();
          }
        }else if( s.compare(".") == 0 ){
          continue;
        }else{
          debug("push", s );
          S.push_back(s);
        }
      }
      string rst = "";
      while( !S.empty() ){
        debug("front=", S.front());
        rst += "/";
        rst += S.front();
        S.pop_front();
      }
      if( rst.empty() ) return "/";
      else return rst;
    }
};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  string str;
  cin >> str;
  Solution s;
  cout << s.simplifyPath(str) << '\n';




  return 0;
}
