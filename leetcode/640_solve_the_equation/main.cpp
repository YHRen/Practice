#include <regex>
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
  ii cal( const string & str ){
    int x = 0, c = 0;
    for( int i = 0; i < str.size(); /* */ ){
      int j = str.find('+',i);
      debug(i,j);
      if( j == -1 ) break;
      if( j == i ){
        ++i;
      }else{
        string tmp = str.substr(i,j-i);
        debug("tmp",tmp);
        if( tmp.back() == 'x' ){
          if( tmp.size() == 1 ){
            x ++;
          }else{
            string tmp2 = tmp.substr(0,tmp.size()-1);
            if( tmp2 == "-" ){ tmp2 += '1';}
            x += stoi( tmp2 );
          }
        }else{
          c += stoi( tmp) ;
        }
        i = j + 1;
      }
    }
    return mp(x,c);
  }

  public:
    string solveEquation(string equation) {
      string str="";
      for( char c : equation ){
        if( c != '-' ){
          str += c;
        }else{
          str += "+-";
        }
      }
      string strL, strR;
      int idx = str.find("=");
      strL = str.substr(0,idx); strL += "+";
      strR = str.substr(idx+1, string::npos); strR += "+";
      debug(strL);
      debug(strR);
      auto L = cal(strL);
      debug(strL);
      auto R = cal(strR);
      debug(strR);
      int X = L.first - R.first;
      int C = R.second - L.second;
      debug(L.first, R.first);
      debug(L.second, R.second);
      if( X == 0 && C == 0 ){
        return "Infinite solutions";
      }else if( X == 0 ){
        return "No solution";
      }else{
        return "x=" +to_string(C/X);
      }

    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  cout << sol.solveEquation( str ) << '\n';

  return 0;
}
