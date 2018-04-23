// #include <bits/stdc++.h>
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
/******* Actual Code Starts Here *********/
class Solution {
  vector<string> ans;
  string         str;
  bool validate_int( const string & s ){
    if( s.empty() || (s.length()>1 && s[0] == '0') ) return false;
    return true;
  }
  bool validate_float( const string & s ){
    int n = s.length();
    if( s.empty() || (s[0] == '.') ||
        (n>2 && s[n-1] == '0' && s[n-2] == '0') || s[n-1] == '.' ) return false;
    if( s == "0.0" ) return false;
    int idx = s.find('.');
    string tmp = s.substr(0,idx);
    debug(s,"tmp=",tmp, validate_int(tmp));
    string tmp2 = s.substr(idx+1);
    debug(s,"tmp2=",tmp2, validate_decimal(tmp2));
    return validate_int(tmp) && validate_decimal(tmp2);
  }
  bool validate_decimal( const string & s ){
    int n = s.length();
    if( s.empty() || stoi(s) == 0 || (n>1 && s.back()=='0') ) return false;
    return true;
  }
  bool validate( const string & s, int mode ){
    if( mode == 0 ) return validate_int(s);
    else return validate_float(s);
  }

public:
    vector<string> ambiguousCoordinates(string S) {
      str = S.substr(1, S.length()-2);
      debug(str);
      int n = str.size();
      for( int l = 1; l < n; ++l ){
        string s1 = str.substr(0,l), s2 = str.substr(l);
        debug("s1 =",s1,"s2 =",s2);
        int n1 = s1.size(), n2 = s2.size();

        string tmp1, tmp2;
        for(int i = 0; i < n1; ++i ){
          if( i == 0 ) tmp1 = s1;
          else         tmp1 = s1.substr(0,i) + "." + s1.substr(i);
          if( validate( tmp1, i ) ){
            for(int j = 0; j < n2; ++j ){
            if( j == 0 ) tmp2 = s2;
            else         tmp2 = s2.substr(0,j) + "." + s2.substr(j);
            if( validate( tmp2, j ) ){
              ans.pb("("+tmp1+", "+tmp2+")");
            }
            }
          }
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  string S = "(00011)";
  cin >> S;
  Solution sol;
  auto ans = sol.ambiguousCoordinates(S);
  print_(ans);

  return 0;
}
