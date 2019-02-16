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
  int n;
  vi v;
  int get_number(int i, int r){
    if( r-i>1 and v[i] == 0 ) return -1;
    ll ans = 0;
    for(;i<r;++i){
      ans += v[i];
      ans *= 10;
    }
    ans /= 10;
    if( ans > (1LL<<31)-1) return -1;
    return ans;
  }

  int try_number(ll a0, ll a1, int idx){
    ll ans = 0;
    ll t = a0+a1;
    forall(i,idx,n){
      ans+=v[i];
      if(ans==t) return i+1;
      if( ans > t) return -1;
      ans*=10;
    }
    return -1;
  }

  public:
    vector<int> splitIntoFibonacci(string S) {
      n = S.size();
      v.resize(n);
      forall(i,0,n) v[i]=char(S[i])-'0';
      print_(v);
      forall(i,1,n){
        int f0 = get_number(0,i);
        if( f0 == -1 ) break;
        forall(j, i+1, n-1){
          int f1 = get_number(i,j);
          debug("i,j",i,j,"f0,f1",f0,f1, "j=",j);
          if( f1==-1) break;
          int x = f0, y = f1;
          int k=j, w;
          vi tmp;
          tmp.pb(f0);
          tmp.pb(f1);
          while( (w=try_number(x, y, k)) != -1 ){
            tmp.pb(get_number(k,w));
            k = w;
            if(w == n) return tmp;
            ll z = x+y;
            x = y;
            y = z;
          }
        }
      }

      return {};
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  debug("str=",str);
  Solution sol;
  auto ans = sol.splitIntoFibonacci(str);
  print_(ans);

  return 0;
}

/*
Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

    0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
    F.length >= 3;
    and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.

Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

Example 1:

Input: "123456579"
Output: [123,456,579]

Example 2:

Input: "11235813"
Output: [1,1,2,3,5,8,13]

Example 3:

Input: "112358130"
Output: []
Explanation: The task is impossible.

Example 4:

Input: "0123"
Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.

Example 5:

Input: "1101111"
Output: [110, 1, 111]
Explanation: The output [11, 0, 11, 11] would also be accepted.

Note:

    1 <= S.length <= 200
    S contains only digits.
*/
