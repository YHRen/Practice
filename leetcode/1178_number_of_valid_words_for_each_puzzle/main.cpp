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
  unsigned int encode( const string & s ){
    unsigned int code = 0;
    for(auto c : s ){
      code |= (1 << (c-'a'));
    }
    return code;
  }

public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
      int n = sz(words), m = sz(puzzles);
      vvi mtx(26);
      vector<unsigned int> ws(n), pz(m); 
      forall(i,0,n) ws[i] = encode(words[i]);
      forall(i,0,m) pz[i] = encode(puzzles[i]);
      forall(i,0,m) mtx[puzzles[i][0]-'a'].pb(i);
      vi ans(m,0);
      forall(i,0,26){
        unsigned int msk = (1<<i);
        forall(j,0,n){
          if( (ws[j] & msk) == 0 ) continue;
          for(auto idx : mtx[i]) if( ( (ws[j] | pz[idx]) == pz[idx] ) ) ans[idx]++;
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m; 
  vector<string> v(n), u(m);
  input(v);
  input(u);
  Solution sol;
  auto ans = sol.findNumOfValidWords(v,u);
//  print_(ans);
  return 0;
}
