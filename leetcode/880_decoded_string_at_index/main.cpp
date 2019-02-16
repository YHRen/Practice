#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
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
typedef long long ll;

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
    string decodeAtIndex(string S, int K) {
      stack<string>         words;
      stack<pair<ll,ll>>    opera;
      S.pb('1');
      int l = 0;
      int found = S.find_first_of("123456789");
      ll run = 0;
      while( found != string::npos ){
        string tmp = S.substr(l, found-l);
        if( tmp.size() ==0 and isdigit(S[l])){ // another digit
          auto & x = opera.top(); 
          int factor = S[l] - '0';
          debug("factor = ",factor);
          x.second *= factor;
          run *= factor;
        }else{
          ll prev_size   = 0;
          ll prev_factor = 1;
          if( !opera.empty() ){
            prev_size = opera.top().first;
            prev_factor = opera.top().second;
          }
          ll m = tmp.size();
          ll factor = S[found] - '0';
          debug(" word = ", tmp, "factor = ", factor );
          words.push(tmp);
          opera.push(mp(prev_size*prev_factor+m, factor));
          run += m;
          run *= factor;
        }
        if( found + 1 == S.size() ) break;
        if( run >= K ) break;
        l = found + 1;
        found = S.find_first_of("123456789",found+1);
      }

      while( K>0 ){
        ll prev_size = opera.top().first;
        ll prev_factor = opera.top().second;
        string wrd = words.top();
        words.pop();
        opera.pop();
        debug("K=",K, "prev_size=", prev_size, wrd);
        ll m = wrd.size();
        while ( K > prev_size ) K -= prev_size;
        debug("K now = ", K, prev_size-m, wrd);
        if( K > (prev_size-m) ) return string(1, wrd[K+m-prev_size-1]);
      }
      return "";
    }
};
int main( int argc, char * argv[] ){
  int K; cin >> K;
  string str; cin >> str;
  Solution sol;
  cout << sol.decodeAtIndex(str, K ) << '\n';
  return 0;
}
