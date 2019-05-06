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

//auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
static inline int c2i(char c){ return c-'A';};
class Solution {
public:
    int characterReplacement(const string  & s, const int k) {
      int n = sz(s);
      int max_cnt = 0, res = 0, l = 0;
      vi  buf(26,0);
      auto c2i = [](char c){ return c-'A';};
      forall(r,0,n){
        int idx = c2i(s[r]);
        buf[idx] += 1;
        max_cnt = max(max_cnt, buf[idx]);
        while( r-l+1 - max_cnt > k ){
          buf[c2i(s[l++])] -= 1;
        }
        res = max(res, r-l+1);
      }
      return res;
    }

    int characterReplacement_slow(const string  & s, const int k) {
      int n = sz(s);
      if( n <= 1 ) return n;
      if( n-1 <= k ) return n;

      vi buf(26,0);
      buf[c2i(s[0])] = 1;
      int l = 0;
      int res = 0;
      forall(r,1,n){
        // if we still can change 
        int idx = c2i(s[r]);
        if( r-l+1 - (buf[idx]+1) <= k or r-l+1 - *max_element(all(buf)) <= k){ 
          buf[idx] += 1;
        }else{
          buf[idx] += 1;
          do{
            buf[c2i(s[l++])] -= 1;
          }while( l < r and r-l+1 - *max_element(all(buf)) > k );
        }
        res = max(res, r-l+1);
      }
      return res;
    }
};
int main( int argc, char * argv[] ){
  string s; cin >> s;
  int k ; cin >> k;
  Solution sol;
  cout << sol.characterReplacement(s,k) << endl;
  return 0;
}
