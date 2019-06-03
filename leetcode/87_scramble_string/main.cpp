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
    bool isScramble(const string & s1, const string & s2) {
      debug("s1,s2",s1,s2);
      if( s1 == s2 ) return true;
      int n = sz(s1);
      vi cnt(26,0);
      for(auto c : s1 ) cnt[c-'a']++;
      for(auto c : s2 ) cnt[c-'a']--;
      if( any_of(all(cnt),[](int x){ return x != 0 ; }) ) return false;
      debug("n-1=",n-1);
      forall(i,1,n){
        string x1 = s1.substr(0,i), y1 = s1.substr(i);
        string x2 = s2.substr(0,i), y2 = s2.substr(i);
        string x3 = s2.substr(0,n-i), y3 = s2.substr(n-i);
        debug("i=",i,x1,y1,x2,y2,x3,y3);
        if( isScramble(x1,x2) and isScramble(y1,y2) ) return true;
        if( isScramble(x1,y3) and isScramble(y1,x3) ) return true;
      }
      return false;
    }
};
int main( int argc, char * argv[] ){
  string s1,s2;
  cin >> s1 >> s2;
  Solution sol;
  cout << sol.isScramble(s1,s2) << endl;
  return 0;
}
