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
#define trace(...)       __f(#__VA_ARGS__, __VA_ARGS__)
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define trace(...)       
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << ": " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " | ";
    __f(comma + 1, args...);
}

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
      int n = sz(words);
      vi cnt(26,0), buf(26), wscore(n,0);
      for(auto c : letters) cnt[c-'a']++;
      vvi wcnt(n, vi(26,0));
      forall(i,0,n) for(auto c : words[i]){
        wcnt[i][c-'a']++;
        wscore[i] += score[c-'a'];
      }
      
      auto C = [&](int msk){
        trace(msk, bitset<15>(msk));
        buf = cnt;
        int res = 0;
        for(int i = 0; i < n and msk; i++){
          if(msk&1){
            trace(words[i]);
            forall(j,0,26) buf[j] -= wcnt[i][j];
            res += wscore[i];
          }
          msk >>= 1;
          if( any_of(all(buf), [](int x){return x < 0;}) ) return -1;
        }
        return res;
      };

      int ans = 0;
      for(int i = 1;  i < (1<<n); ++i){
        ans = max(ans, C(i));
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m; 
  vector<string> v(n);
  vector<char> u(m);
  vector<int> w(26);
  input(v);
  input(u);
  input(w);
  Solution sol;
  cout << sol.maxScoreWords(v,u,w) << endl;
  return 0;
}
