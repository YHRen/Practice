#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <numeric>
#include <functional>
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
  private:
    unordered_map<char,int> book = { 
      {'A',0},{'C',1},{'T',2},{'G',3}};
    vector<string> key = {"A","C","T","G"};
    int encode(string s){
      int ans = 0;
      for( auto c : s ){
        ans <<= 2;
        ans |= book[c];
      }
      return ans;
    }
    string decode(int x){
      string s = "";
      forall(i,0,10){
        int y = x & 3;
        s += key[y];
        x >>= 2;
      }
      reverse(all(s));
      return s;
    }
    vector<int> cnt;
  public:
    vector<string> findRepeatedDnaSequences(string s) {
      if( s.size() <= 10 ) return vector<string>();
      cnt.resize(1<<20,0);
      int code = encode( s.substr(0,10) );
      cnt[code] ++;
      int mask_high = (1<<20) -1;
      forall(i,10,s.size()){
        code <<= 2;
        code &= mask_high;
        debug("adding",s[i]);
        code |= book[s[i]];
        debug(code, decode(code) );
        cnt[code]++;
      }
      vector<string> ans;
      forall(i,0,cnt.size()){
        if( cnt[i] > 1 ){
          debug("cnt[i]",cnt[i],i);
          ans.pb( decode(i) );
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  string s; cin >> s;
  Solution sol;
  auto ans = sol.findRepeatedDnaSequences(s);
  for(auto x : ans ){
    cout << x << '\n';
  }

  return 0;
}
