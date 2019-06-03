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
  vi cnt(vi & flip, vvi & mtx){
    vi mask(n,0);
    vi v(n); 
    forall(i,0,n){
      if( flip[0] ) v[i] = 1^mtx[i][0];
      else v[i] = mtx[i][0];
    }
    forall(i,0,n){
      if( mask[i] ) continue;
      forall(j,0,m){
        if( (flip[j] and v[i] != mtx[i][j] ) or (!flip[j] and v[i] == mtx[i][j] ) ){
          //good
        }else{
          mask[i] = 1;
          break;
        }
      }
    }
    return mask;
  }
  int solve(vvi & mtx){
    int ans = 0;
    vi is_visited(n,0);
    vi flip(m,0);
    forall(i,0,n){
      if( is_visited[i] ) continue;
      flip.assign(sz(flip),0);
      forall(j,1,m) flip[j] = (mtx[i][0]!=mtx[i][j]);
      debug("i=",i,"mask");
      debug("flip");
      print_(flip);
      auto mask = cnt(flip, mtx);
      print_(mask);
      int tmp  = 0;
      forall(k,0,n){
        if( !mask[k] ){
          tmp ++;
          is_visited[k] = 1;
        }
      }
      ans = max(tmp,ans);
    }
    return ans;
  }
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mtx) {
      n = sz(mtx), m = sz(mtx[0]);
      if( m == 1 ) return n;
      int ans = solve(mtx);
      return ans;
//  public:
//    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
//        int n = matrix.size(), m = matrix[0].size();
//        map<string, int> mp;
//        int ans = 0;
//        for(int i = 0; i < n; i++) {
//            string s1, s2;
//            for(int j = 0; j < m; j++) {
//                if(matrix[i][j] == 0) {
//                    s1 += '0'; s2 += '1';
//                }
//                else {
//                    s1 += '1'; s2 += '0';
//                }
//            }
//            debug("i=",i,"s1=",s1,"s2=",s2);
//            ans = max(ans, mp[s1]+1);
//            mp[s1]++; mp[s2]++;
//        }
//        debug("mpsz",mp.size());
//        return ans;
//    }
};

int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  vvi mtx(n,vi(m));
  for(auto & v : mtx ) input(v);
  Solution sol;
  cout << sol.maxEqualRowsAfterFlips(mtx) << endl;
  return 0;
}
