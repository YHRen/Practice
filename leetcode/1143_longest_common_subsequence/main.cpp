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
#include <complex>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF              (int)1000000007
#define EPS              1e-9
#define pb               push_back
#define mp               make_pair
#define all(c)           c.begin(), c.end()
#define forall(i,a,b)    for(int i=a;i<(b);++i)
#define trav(a,x)        for(auto & a: x)
#define in(a,b)          ((b).find(a) != (b).end())
#define sz(c)            (int)(c).size()
#define input(a)         for(auto & x : a) cin >> x;

using namespace std;

typedef vector<int>      vi;
typedef pair<int,int>    ii;
typedef vector<vi>       vvi;
typedef vector<ii>       vii;
typedef long long        ll;

#ifdef DEBUG
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();

class SolutionDP {
  public:
    int longestCommonSubsequence(string text1, string text2) {
      int n = sz(text1), m = sz(text2);
      vvi dp(2, vi(m+1,0));
      forall(i,1,n+1){
        forall(j,1,m+1){
          if( text1[i-1] == text2[j-1] ){
            dp[1][j] = dp[0][j-1]+1;
          }else{
            dp[1][j] = max( dp[0][j] ,  dp[1][j-1]  );
          }
        }
        swap(dp[0], dp[1]);
      }
      for(auto & v : dp ){
        print_(v);
      }
      return dp[0][m];
    }
};
class Solution {
    int GetLengthOfLIS(const vector<int>& arr) {
        vector<int> lis;
        for (auto& num : arr) {
            auto it = lower_bound(lis.begin(), lis.end(), num);
            if (it == lis.end()) {
                lis.emplace_back(num);
            } else {
                *it = num;
            }
            debug("num = ", num);
            print_(lis);
        }
        return lis.size();
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        array<vector<int>, 26> positions;
        for (int i = 0; i < text2.size(); ++i) {
            positions[text2[i] - 'a'].emplace_back(i);
        }
        
        vector<int> arr;
        for (auto& ch : text1) {
            auto& ps = positions[ch - 'a'];
            for (auto it = ps.rbegin(); it != ps.rend(); ++it) {
                arr.emplace_back(*it);
            }
        }
        print_(arr);
        
        return GetLengthOfLIS(arr);
    }
};
int main( int argc, char * argv[] ){
  string str1, str2;
  cin >> str1 >> str2;
  Solution sol;
  cout << sol.longestCommonSubsequence(str1, str2) << endl;
  return 0;
}
