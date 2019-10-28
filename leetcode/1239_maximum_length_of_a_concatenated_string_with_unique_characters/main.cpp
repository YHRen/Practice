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
  int encode( string & str){
    int code = 0;
    for(auto c : str ){
      if( code & (1<<(c-'a')) ) return 0;
      code |= (1<<(c-'a'));
    }
    return code;
  }
public:
    int maxLength(vector<string>& arr) {
      int n = sz(arr);
      int max_len = 0;
      vi code;
      for(auto & s : arr) code.pb( encode(s) );
      forall(i,0,1<<n){
        int cur = 0;
        bool succ = true;
        forall(j,0,n){
          if( ( i & ( 1<<j ) ) ){
            if( (cur & code[j]) == 0 ){
            cur |= code[j];
            }else{
              succ = false;
              break;
            }
          }
        }
        if( succ ) max_len = max( max_len, __builtin_popcount(cur));
        }
       return max_len; 
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
