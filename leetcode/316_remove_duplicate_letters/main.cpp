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
class Solution {
  public:
    string removeDuplicateLetters(string s) {
      if( s.empty() ) return s;
      vi cnt(128,0), is_used(128,0);
      for(auto c : s) cnt[c]++;
      deque<char> dq;
      for(auto c : s){
        debug("c=",c);
        --cnt[c];
        if( !is_used[c] ){
          is_used[c] = 1;
          while( !dq.empty() and cnt[dq.back()] and dq.back()>c ){
            debug("pop back",dq.back());
            is_used[dq.back()]=false;
            dq.pop_back();
          }
          dq.push_back(c);
        }
      }
      return string(all(dq));
    }
//    string removeDuplicateLetters(string s) {
//      if( s.empty() ) return s;
//      vi cnt(26,0);
//      for(auto c : s) cnt[c-'a']++;
//      int id = 0;
//      forall(i,0,sz(s)){
//        if( s[i] < s[id] ) id = i;
//        if( --cnt[s[i]-'a'] == 0 ) break;
//      }
//      char selected_char = s[id];
//      debug("s",s,"id=",id,"char=",selected_char);
//      string str;
//      forall(i,id,sz(s)){
//        if( s[i]!=selected_char ) str.pb(s[i]);
//      }
//      return string(1,selected_char) + removeDuplicateLetters(str);
//    }
};
int main( int argc, char * argv[] ){
  string str;
  cin >> str;
  Solution sol;
  cout << sol.removeDuplicateLetters(str) << endl;
  return 0;
}
