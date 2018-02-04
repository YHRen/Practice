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
  public:
    string makeLargestSpecial(string S) {
      int n = S.size();
      int i = 0, j = 0;
      int cnt = 0;
      vector<string> res;
      forall( j,0,n ){
        if( S[j] == '1' ) ++cnt;
        else --cnt;
        if( cnt == 0 ){
          res.pb( "1" + makeLargestSpecial( S.substr(i+1, j-i) ) + "0" );
          i = j+1;
        }
      }
      sort( all(res ), greater<string>() );
      string ans = "";
      for( auto & x : res ){
        ans += x;
      }
      return ans;
    }
};

int main( int argc, char * argv[] ){
  string str = "11011000";
  Solution sol;
  cout << sol.makeLargestSpecial(str) << '\n';

  return 0;
}
