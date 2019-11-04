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
    int longestDecomposition(string text) {
      vector<deque<int>> ids(26);
      int n = sz(text);
      forall(i,0,n) ids[text[i]-'a'].pb(i);

      int ans = 0;
      int l = 0;
      for(; l < n/2; /**/){
        char c = text[l];
        trace(l, c, ids[c-'a'].empty());
        bool flag = false;
        int tail = sz(ids[c-'a']) - 1;
        while( tail > 0 ){
          trace(tail);
          int j = ids[c-'a'][tail];
          int len = n-l-j;
          if( l == j ) break;
          if( text.substr(l,len) == text.substr(j,len) ){
            trace(l, j, len, text[l], text[j]);
            forall(k,l,l+len) ids[text[k]-'a'].pop_front();
            forall(k,j,j+len) ids[text[k]-'a'].pop_back();
            ans += 2;
            l += len;
            flag = true;
            break;
          }else{
            tail -= 1;
          }
        }
        trace(flag, l, n/2);
        if(!flag){
          break;
        }
      }
      if( l != n/2 ) ans ++;
      if( l == n/2 and n%2==1 ) ans ++;
      return ans;
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  cout << sol.longestDecomposition(str) << endl;
  return 0;
}
