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
typedef vector<ll>       vll;

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
  vll v;
  int aux( int n ) {
    if( n < 10 ) return n;
    auto itr = lower_bound( all(v), n );
    n -= *(itr-1);
    int d = 1+itr-v.begin();
    debug("d=",d, n);
    ll p = n/d, q = n%(d);
    ll ext = int(pow(10,d-1)) + p;
    if( q == 0 ){
      --ext;
      return ext%10;
    }else{
     return to_string(ext)[q-1]-'0';
    }
  }


public:
    int findNthDigit(int n) {
      ll d = 1, b = 9;
      for(; d<=9 ; ++ d){ v.pb( d*pow(10,d-1)*b ); }
      forall(i,1,sz(v)){ v[i] += v[i-1]; }
      print_(v);
      return aux(n);
      return 0;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  Solution sol;
  cout << sol.findNthDigit(n) << endl;
  return 0;
}
