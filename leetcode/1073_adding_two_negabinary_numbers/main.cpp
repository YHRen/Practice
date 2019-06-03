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
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
      int n = sz(arr1), m = sz(arr2);
      if( n < m ){ swap(arr1,arr2); swap(n,m); }
      int N = max(n,m)+1;
      vi  pos(N+1, 0 ), neg(N+1,0);
      for(int i = n-1, j = m-1, k=0; i >= 0; --i, --j, ++k ){
        if( k%2 == 0 ){ // pos 
          int cnt = arr1[i] + (j >= 0 ? arr2[j] : 0) ;
          debug("k=",k,cnt);
          if( cnt == 1 ){
            pos[k] = 1;
          }else if( cnt == 2 ){
            pos[k+1] = 1;
          }
        }else{// neg
          int cnt = arr1[i] + (j >= 0 ? arr2[j] : 0) ;
          debug("k=",k,cnt);
          if( cnt == 1 ){
            neg[k] = 1;
          }else if( cnt == 2 ){
            neg[k+1] = 1;
          }
        }
      }
      debug("pos");
      print_(pos);
      debug("neg");
      print_(neg);
      vi meg(N+1,0);
      forall(i,0,N+1){
        meg[i] = pos[i] - neg[i];
      }
      debug("meg");
      print_(meg);
      meg.pb(0);
      meg.pb(0);
      meg.pb(0);
      forall(i,0,N+1){
        if( i%2 == 0 ){ // pos
          if( meg[i] == -1 ){ meg[i] = 1; meg[i+1] -= 1; }
          if( meg[i] == 2 ){
            if( meg[i+1] == -1 ){
              meg[i+1] = 0;
              meg[i] = 0;
            }else{ meg[i] = 0; meg[i+1] -= 1; meg[i+2] += 1; }
          }
        }else{ // neg
          if( meg[i] == -1 ) meg[i] = 1;
          else if( meg[i] == 1 ){ meg[i+1] += 1; }
          else if( meg[i] == -2 ){
            if( meg[i+1] >= 1){
              meg[i] = 0;
              meg[i+1] -= 1;
            }else{
               meg[i] = 0; 
               meg[i+1] += 1;
               meg[i+2] -= 1; 
            }
          }
        }
        debug("i=",i);
        print_(meg);
      }
      debug("meg");
      print_(meg);
      while(meg.size() > 1 and meg.back() == 0 ){
        meg.pop_back();
      }
      reverse(all(meg));
      return meg;

    }
};
int main( int argc, char * argv[] ){
  int n, m; cin >> n >> m; 
  vi v(n); input(v);
  vi u(m); input(u);
  Solution sol;
  auto res = sol.addNegabinary(v,u);
  print_(res);
  return 0;
}
