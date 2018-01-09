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
    int romanToInt(string s) {
      map<char, int> dict;
      dict['I'] = 1;
      dict['V'] = 5;
      dict['X'] = 10;
      dict['L'] = 50;
      dict['C'] = 100;
      dict['D'] = 500;
      dict['M'] = 1000;

      int ans = 0;
      int n = s.size();
      forall(i,0,n){
        if( i < n - 1 && dict[s[i]] < dict[s[i+1]] ){
          ans -= dict[s[i]];
        }else{ 
          ans += dict[s[i]];
        }
      }
      return ans;
    }
};

int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  cout << sol.romanToInt(str) << '\n';

  return 0;
}
