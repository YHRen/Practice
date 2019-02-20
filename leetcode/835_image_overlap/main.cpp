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
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF                         (int)1000000007
#define EPS                         1e-9

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

#ifdef DEBUG
#define debug(args...)            {dbg,args; clog<<endl;}
#define print_( a )               for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )           for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)             // Just strip off all debug tokens
#define print_( a )               // skip
#define printPair_( a )           // skip
#endif
struct debugger
{
  template<typename T> debugger& operator , (const T& x)
  {    
    clog << x << " ";    
    return *this;    
  }
} dbg;

// std::ios::sync_with_stdio(false);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  int n;
  vi encode( const vvi & A ){
    vi v(n,0);
    forall(i,0,n){
      forall(j,0,n){
        v[i] |= A[i][j];
        v[i] <<= 1;
      }
      v[i] >>= 1;
    }
    return v;
  }

  int calc(const vi & va, const vi & vb){
    int ans = 0;
    forall(i,0,n) 
      ans += __builtin_popcount( va[i] & vb[i] );
    return ans;
  }

  public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
      n = A.size();
      auto va = encode(A);
      auto vb = encode(B);
      debug("VA");
      for(auto x : va ){
        debug( bitset<32>(x) );
      }

      debug("VB");

      for(auto x : vb ){
        debug( bitset<32>(x) );
      }
      int ans = calc(va,vb);
      debug("ans=",ans);

      {//shift right and up and down
        auto tmp = va;
        forall(i,0,n){
          if( i!= 0 ) for(auto & x : tmp) x >>= 1;
          debug("right shift ", i, "ans = ", calc(tmp, vb));
          for(auto x : tmp ){
            debug( bitset<32>(x) );
          }
          ans = max(ans, calc(tmp, vb) );
          forall(k,1,n){ // up
            int tmp_cnt = 0;
            int ii = k;
            forall(j,0,n){
              if( ii == n ) break;
              tmp_cnt += __builtin_popcount(tmp[ii] & vb[j]);
              ii += 1;
            }
            debug("upshift", k, "ans = ", tmp_cnt);
            ans = max(tmp_cnt, ans);
          }
          forall(k,1,n){// down
            int tmp_cnt = 0;
            int ii = 0;
            forall(j,k,n){
              tmp_cnt += __builtin_popcount(tmp[ii] & vb[j]);
              ii += 1;
            }
            debug("down shift", k, "ans = ", tmp_cnt);
            ans = max(tmp_cnt, ans);
          }
        }
      }
      debug("ans =", ans);
      {//shift left and up and down
        auto tmp = va;
        forall(i,0,n){
          if( i != 0 ) for(auto & x : tmp) { 
            x <<= 1;
            x &= ((1<<30)-1);
          }
          ans = max(ans, calc(tmp, vb) );
          forall(k,1,n){
            int tmp_cnt = 0;
            int ii = k;
            forall(j,0,n){
              if( ii == n ) break;
              tmp_cnt += __builtin_popcount(tmp[ii] & vb[j]);
              ii += 1;
            }
            ans = max(tmp_cnt, ans);
          }
          //down 
          forall(k,1,n){
            int tmp_cnt = 0;
            int ii = 0;
            forall(j,k,n){
              tmp_cnt += __builtin_popcount(tmp[ii] & vb[j]);
              ii += 1;
            }
            ans = max(tmp_cnt, ans);
          }
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vvi A(n, vi(n,0)); for(auto & v : A) input(v); 
  vvi B(n, vi(n,0)); for(auto & v : B) input(v);
  Solution sol;
  cout << sol.largestOverlap( A, B ) << '\n';

  return 0;
}
