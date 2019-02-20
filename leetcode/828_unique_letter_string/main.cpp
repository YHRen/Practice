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
    int uniqueLetterString(string S) {
      int n = S.size();
      if( n == 0 ) return 0;
      if( n == 1 ) return 1;
      vvi loc(26);
      forall(i,0,n) loc[S[i]-'A'].pb(i);
      ll ans = 0;
      forall(k,0,26){
        if( loc[k].empty() ) continue;
        int m = loc[k].size();
        forall(i,0,m){
          int l,r;
          if( i == 0 ){ l = loc[k][i] + 1; }
          else {l = loc[k][i] - loc[k][i-1];}
          if( i == m-1 ){ r = n-loc[k][i];}
          else r = loc[k][i+1] - loc[k][i];
          ans += l*r; 
          ans %= INF;
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
