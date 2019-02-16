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
  string B;
  int n;
  int mask;
  ll encode(string str){
    ll ans = 0;
    for(auto c : str ){
      ans <<= 3;
      ans |= c-'a';
    }
    return ans;
  }
  int get_bits(ll code, int idx){
    return mask & (code >> 3*(n-idx-1));
  }
  char code_to_char(int code ){
    return char('a'+code);
  }
  string decode(ll code ){
    string ans;
    forall(i,0,n){
      ans.pb(code_to_char(get_bits(code, n-i-1)));
    }
    reverse(all(ans));
    return ans;
  }

  unordered_map<ll, int> dp;
  ll target;
  int solve(ll code, string & str, int idx ){
    debug("idx=",idx,code, target);
    if( idx == n ) return 0;
    if( code == target ) return 0;
    debug("str = ",str, "idx=",idx);
    auto itr = dp.find(code);
    if( itr!=dp.end() ) return itr->second ;
    int ans = INF;
    int i = idx;
    for(; i < n; ++i ){
      if( str[i] != B[i] ) break;
    }
    for(int j = i+1; j < n; ++j ){
      if( str[j] != B[j] and B[i] == str[j]){
        swap(str[i], str[j]);
        ans = min( ans, 1+ solve( encode(str), str, i+1) );
        swap(str[i], str[j]);
      }
    }
    debug("dp", str, ans);
    return dp[code] = ans;
  }
  public:
	int kSimilarity(string A, string B) {
      if( A == B ) return 0;
      this->B = B;
      n = A.size();
      mask = (1<<3)-1;
      debug(bitset<64>(mask));
      debug(bitset<64>(encode(A)));
      target = encode(B);
      debug("A=", A, decode(encode(A)));
      int start  = encode(A);
      int ans = solve(start, A, 0);
      return ans;
	}
};


int main( int argc, char * argv[] ){
  string a,b; cin >> a >> b;
  debug(a,b);
  Solution sol;
  cout << sol.kSimilarity(a,b) << '\n';

  return 0;
}


/*
Strings A and B are K-similar (for some non-negative integer K) if we can swap the positions of two letters in A exactly K times so that the resulting string equals B.

Given two anagrams A and B, return the smallest K for which A and B are K-similar.

Example 1:

Input: A = "ab", B = "ba"
Output: 1

Example 2:

Input: A = "abc", B = "bca"
Output: 2

Example 3:

Input: A = "abac", B = "baca"
Output: 2

Example 4:

Input: A = "aabc", B = "abca"
Output: 2

Note:

    1 <= A.length == B.length <= 20
    A and B contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}

*/
