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
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
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

// std::ios::sync_with_stdio(false);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
public:
    string toGoatLatin(string S) {
      vector<string> tokens;
      {
        istringstream iss(S);
        string tmp;
        while( iss>>tmp ){ tokens.pb(tmp); }
      }
      int n = tokens.size();
      string ans;
      forall(i,0,n){ 
        auto x = tokens[i].find_first_of("aeiouAEIOU");
        if( x == 0 ){
          tokens[i] += "ma";
          tokens[i] += string(i+1, 'a');
        }else{
          string suffix = string(1, tokens[i][0]) + "ma" + string(i+1,'a');
          tokens[i] = tokens[i].substr(1);
          tokens[i] += suffix;
        }
        ans += tokens[i];
        if( i != n-1 ) ans += " ";
      }

      return ans;
        
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
