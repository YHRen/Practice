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
  typedef long long ll;
public:
    int distinctSubseqII(string S) {
      int n = S.size();
      if( n == 1 ) return 1;
      vector<ll> cnt(26,0);
      ll tot = 0;
      forall(i,0,n){
        int idx = S[i]-'a';
        ll dif = (tot+1-cnt[idx]+INF);
        cnt[idx] = (tot+1)%INF;
        tot = (tot + dif)%INF;
      }
      return tot%INF;
    }
    int slower_distinctSubseqII(string S) {
      int n = S.size();
      if( n == 1 ) return 1;
      vector<ll> cnt(26,0);
      ll tot = 0;
      forall(i,0,n){
        int idx = S[i]-'a';
        tot = 0;
        for( auto x : cnt ) tot += x;
        cnt[idx] = (tot+1)%INF;
      }
      tot = 0;
      for( auto x : cnt ) tot += x;
      return tot%INF;
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol; 
  cout << sol.distinctSubseqII(str) << '\n';

  return 0;
}
