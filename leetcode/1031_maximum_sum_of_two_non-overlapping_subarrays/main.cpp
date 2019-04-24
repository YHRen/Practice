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
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
      int n = sz(A);
      vi B(n+1, 0);
      forall(i,0,n) B[i+1] = B[i] + A[i];
      int res = 0;
      print_(A);
      print_(B);

      forall(i,0,n+1-L){
        int l = B[i+L] - B[i];
        debug(i, l );
        for(int j = i; j - M >= 0; --j ){
          int r = B[j] - B[j-M];
          res = max(res, l+r);
        }
        for(int j = i+L; j < n+1-M; ++j ){
          int r= B[j+M] - B[j];
          res = max(res, l+r);
        }
      }
      return res;
    }
};
int main( int argc, char * argv[] ){
  int n, L, M; cin >> n >> L >> M; 
  vi v(n); input(v);
  Solution sol;
  cout << sol.maxSumTwoNoOverlap(v, L, M) << '\n';

  return 0;
}
