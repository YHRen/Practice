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
  constexpr static int incre[10] = {1, 6, 0,0,0,0, 8, 0, 9,0};
  constexpr static int rotat[10] = {0, 1, 0,0,0,0, 9, 0, 8,6};
  vi nvec;
  int  K;

  void register_nvec(int n){
    string str = to_string(n);
    for(auto c : str ){ nvec.pb(c-'0'); }
    K = sz(nvec);
  }

  bool increment( vi & v ){
    int n = sz(v);
    for(int i = n-1; i >= 0; --i ){
      if( v[i] != 9 ){
        v[i] = incre[v[i]];
        forall(j,i+1,n) v[j] = 0;
        return true;
      }
    }
    return false;
  }
  
  bool C( const vi & v, const vi & u ){
    auto vitr = v.begin();
    auto uitr = u.rbegin();
    for(; vitr != v.end() and uitr != u.rend(); ++vitr, ++uitr){
      if( rotat[*vitr] != *uitr ) return true;
    }
    if( uitr == u.rend() ) return false;
    if( *uitr == 6 or *uitr == 9 ) return true;
    else return false;
  }

  bool D( const vi & v, const vi & u ){
    int m = sz(v);
    forall(i,0,K){
      if( i <  m ){
        if( v[i] < nvec[i] ) return true;
        else if( v[i] > nvec[i] ) return false;
      }else{
        if( u[i-m] < nvec[i] )  return true;
        else if( u[i-m] > nvec[i] ) return false;
      }
    }
    return true;
  }
 
  public:
    int confusingNumberII(int N) {
      if( N < 10 ){ if( N < 6 ) return 0; if( N < 9 ) return 1; else return 2;}
      register_nvec(N);
      int res = 2;
      for(int k = 2; k < 10; ++k){ // num digits
          vi left(k/2,0);
          left[0] = 1;
          vi right(k-k/2,0);
          do{
            right.assign(k-k/2,0);
            do{
              if( C(left, right) ){
                if( k < K ) res ++;
                else if( D(left, right) ) res ++;
                else return res;
              }
            }while(increment(right));
          }while(increment(left));
      }
      if( N ==  1000000000 ) res++;
      return res;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
