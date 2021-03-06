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
  void balance_SL( multiset<int> & S, multiset<int> & L ){
    if( sz(S) - sz(L) > 1 ){
      L.insert(*S.rbegin());
      S.erase(--S.end());
    }else if( sz(L)-sz(S) > 1 ){
      S.insert( *L.begin() );
      L.erase(L.begin());
    }
  }
  void insert_SL( multiset<int> & S, multiset<int> &L, int val){
    if( S.empty() or val <= *S.rbegin() ) S.insert(val);
    else L.insert(val);
  }
public:
    vector<double> medianSlidingWindow(vector<int>& v, int k) {
      vector<double> res;
      int n = sz(v);
      if( n == 0 ) return res;
      if( k == 1 ){ copy(all(v),back_inserter(res)); return res; }
      multiset<int> S, L; 
      // S for small values, large elements at top. 
      // L for large values, small elements at top.
      debug("before init");
      forall(i,0,k-1){// init S and L
        insert_SL(S,L,v[i]);
        balance_SL(S,L);
      }
      debug("after init", sz(S), sz(L));
      print_(S);
      print_(L);

      forall(j,k-1,n){
        insert_SL(S,L,v[j]);
        balance_SL(S,L);
        double mid;
        if( k%2 ){ // k is odd
          mid = sz(S) > sz(L) ? *S.rbegin() : *L.begin();
        }else{
          mid = (double)( (ll)*S.rbegin() + (ll)*L.begin() ) / 2;
        }
        res.pb(mid);
        debug("j=",j, "mid=",mid);
        print_(S);
        print_(L);

        if(auto itr = S.find(v[j-k+1]); itr != S.end() ){
          S.erase(itr);
        }else{
          itr = L.find(v[j-k+1]);
          if(itr == L.end()) debug("finding ",v[j-k+1]);
          L.erase(itr);
        }
        balance_SL(S,L);
      } 
      return res;
    }
};
int main( int argc, char * argv[] ){
  int n,k; cin >> n >> k; 
  vi v(n); input(v);
  Solution sol;
  auto res = sol.medianSlidingWindow(v,k);
  print_(res);
  return 0;
}
