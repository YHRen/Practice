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
// https://leetcode.com/problems/create-maximum-number/
auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
  vi get_sub(const vvi & V, int k, const int n){
    vi ans;
    vi idx(10,0);
    int id = 0;
    while( sz(ans) < k ){
      for(int i = 9; i>=0; --i){
        while( idx[i] < sz(V[i]) and V[i][idx[i]] < id ) idx[i]++;
        if( idx[i] >= sz(V[i]) ) continue;
        if( n-V[i][idx[i]]+sz(ans) >= k and sz(ans) < k ){
          ans.pb(i);
          id = V[i][idx[i]];
          idx[i]++;
          break;
        }
      }
    }
    return ans;
  }

  bool greater(  vi::const_iterator itr1,  vi::const_iterator itr1e,
       vi::const_iterator itr2,  vi::const_iterator itr2e){
    while( itr1!=itr1e and itr2!=itr2e and *itr1==*itr2 ){
        ++itr1;
        ++itr2;
    }
    return itr2==itr2e || (itr1!=itr1e and *itr1 > *itr2);
  }

  vi mrg( const vi & v, const vi & u ){
    auto itrv = v.begin(), itru = u.begin();
    vi res;
    while( itrv!=v.end() and itru!=u.end()){
      if( greater( itrv, v.end(), itru, u.end()) ){
        res.pb(*itrv);
        ++itrv;
      }else{
        res.pb(*itru);
        ++itru;
      }
    }
    while(itrv!=v.end()) {res.pb(*itrv); ++itrv;}
    while(itru!=u.end()) {res.pb(*itru); ++itru;}
    return res;
  }
  
  public:
    vector<int> maxNumber(vector<int>& v, vector<int>& u, int K) {
      debug("u,v");
      print_(v);
      print_(u);
      debug("---");
      int n = sz(v), m = sz(u);
      if( n+m < K ) return {};
      vvi V(10), U(10);
      forall(i,0,n) V[v[i]].pb(i);
      forall(i,0,m) U[u[i]].pb(i);
      vi ans(K,0);
      forall(i,0,K+1){
        int x = i, y = K-i;
        if( x > n or y > m ) continue;
        auto vv = get_sub(V,x,n);
        auto uu = get_sub(U,y,m);
        debug("i=",i, x,y, vv.size(), uu.size());
        print_(vv);
        print_(uu);
        vi ww = mrg(vv,uu);
        // merge(all(vv), all(uu), back_inserter(ww));
        print_(ww);
        if( ww > ans ) swap(ans, ww);
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m,k; cin >> n >> m >> k; 
  vi v(n); input(v);
  vi u(m); input(u);
  Solution sol;
  auto ans = sol.maxNumber(v,u,k);
  print_(ans);
  return 0;
}
