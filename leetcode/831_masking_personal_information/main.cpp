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
    string maskPII(string S) {
      string ans;
      int n = S.size();
      if( find(all(S),'@') != S.end() ){// email
        int idx = find(all(S),'@') - S.begin();
        S[0] = tolower(S[0]);
        S[idx-1] = tolower(S[idx-1]);
        ans.pb(S[0]);
        ans+="*****";
        ans.pb(S[idx-1]);
        forall(i,idx,n){
          S[i] = tolower(S[i]);
        }
        ans += S.substr(idx);
      }else{// phone
        vi d;
        forall(i,0,n) if( isdigit(S[i]) ) d.pb(S[i]-'0'); 
        int digit_cnt = count_if( all(S), [](char c){return isdigit(c);});
        if( digit_cnt > 10 ){ // contains global
          ans += "+";
          ans += string(digit_cnt-10, '*');
          ans += "-";
        }
        ans += "***-***-";
        int m = d.size();
        forall(i,m-4,m) ans += to_string(d[i]);
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
