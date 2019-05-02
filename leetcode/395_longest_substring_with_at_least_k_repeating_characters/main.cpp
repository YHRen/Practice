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
  vvi buf;
  int K,n;
  int eval(int l, int r){
    if( l > r ) return INF;
    for(const auto & v : buf ){
      if( v.empty() ) continue;
      auto itr = lower_bound(all(v),l);
      int cnt = upper_bound(all(v),r) - itr;
      if( cnt == 0 or cnt >= K ) continue;
      return *itr;
    }
    return -1;
  }


public:
    int longestSubstring(string s, int k) {
      int max_len = 0;
      int n = sz(s);
      int i,  w, run;
      vi cnt(26,0);
      forall(h,1,27){
        run = i = w = 0;
        cnt.assign(sz(cnt),0);
        forall(j,0,n){
          char c = s[j];
          if( run <= h ){
            if( cnt[c-'a'] == 0 ){
              run ++;
            }
            cnt[c-'a']+=1;
            if( cnt[c-'a']==k ) ++w;
          }
          while( run > h ){
            if( cnt[s[i]-'a'] == k ) --w;
            cnt[s[i]-'a'] -= 1;
            if( cnt[s[i]-'a'] == 0 ){
              run -= 1;
            }
            ++i;
          }
          if( w == h and run == h ){
            max_len = max(max_len, j-i+1);
          }
        }
      }
      return max_len;
    }
    int longestSubstring_nlogn(string s, int k) {
      if( s.empty() ) return 0;
      buf.resize(26);
      K = k;
      n = sz(s);
      forall(i,0,n){ buf[s[i]-'a'].pb(i); }
      queue<ii> Q;
      Q.push(mp(0,sz(s)-1));
      int max_len = 0;
      while(!Q.empty()){
        auto [l,r] = Q.front(); Q.pop();
        int res = eval(l,r);
        if( res == -1 ){ //success
          max_len = max(max_len, r-l+1);
        }else if(res != INF ){
          Q.push(mp(l,res-1));
          Q.push(mp(res+1,r));
        }
      }
      return max_len;
    }
};

int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
