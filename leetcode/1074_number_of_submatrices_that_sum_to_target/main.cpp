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
  int n,m;
  vvi mtx;
  int cnt_subary(const vi & cum, int target){
    map<int,int> S;
    S[0]=1;
    int cnt  = 0;
    vi v(m); v[0] = cum[0];
    forall(j,1,m) v[j] = v[j-1]+cum[j];
    for(auto x : v ){
      auto itr = S.find(x-target);
      if( itr != S.end() ){
        cnt += itr->second;
      }
      S[x] += 1;
    }
    return cnt;
  }
  vvi transpose(vvi & mtx){
    vvi ans(m, vi(n));
    forall(i,0,n){
      forall(j,0,m){
        ans[j][i] = mtx[i][j];
      }
    }
    swap(n,m);
    return ans;
  }

public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
      n = sz(matrix), m = sz(matrix[0]);
      if( n > m ){ 
        mtx = transpose(matrix);
      }else{
        mtx = matrix;
      }
      vi cum(m);
      int ans = 0;
      forall(i,0,n){
        cum.assign(m,0);
        forall(ii,i,n){
          forall(j,0,m){
            cum[j] += mtx[ii][j];
          }
          debug("i,ii",i,ii);
          print_(cum);
          ans += cnt_subary(cum, target);
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m,t; cin >> n >> m >> t;
  vvi mtx(n, vi(m)); 
  for(auto & v : mtx ) input(v);
  Solution sol;
  cout << sol.numSubmatrixSumTarget(mtx,t) << endl;
  return 0;
}
