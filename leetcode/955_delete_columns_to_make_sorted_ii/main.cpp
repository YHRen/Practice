#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
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

#define bg     begin()
#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi>  vvi;
typedef vector<ii>  vii;

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
public:
    int minDeletionSize(vector<string>& A) {
      int n = A.size();
      int m = A[0].size();
      vector<string> B(m);
      forall(i,0,m){
        B[i] = "";
        forall(j,0,n){
          B[i].pb(A[j][i]);
        }
      }

      int ans = 0;
      queue<ii> Q;
      forall(i,0,m){
        debug("i",i, B[i]);
        if( Q.empty() && is_sorted(all(B[i])) ){
          debug("Q empty()", "sorted");
          int l = 0, r=0;
          forall(j,1,n){
            if( B[i][j] == B[i][j-1] ){
              continue;
            }else{
              r = j;
              if( r - l > 1 ){
                Q.push(mp(l,r));
                debug("Q push", l,r);
              }
              l = j;
            }
          }
          if( l!= n-1 ){
            Q.push(mp(l,n));
            debug("Q push", l,n);
          }
          if( Q.empty() ) return ans;
        }else if( !Q.empty() ){
          queue<ii> P;
          queue<ii> Q1 = Q;
          bool flag = false;
          while(!Q.empty()){
            auto p = Q.front();Q.pop();
            int l = p.first, r=p.second;
            debug("Q pop()", l, r);
            if( is_sorted(B[i].begin()+l, B[i].begin()+r) ){
              debug("is sorted")
              int lstar = l, rstar=l;
              for(int k = l+1; k < r; ++k){
                if( B[i][k] == B[i][k-1] ) continue;
                else{
                  rstar = k;
                  if( rstar - lstar > 1 ){
                    debug("P push", lstar,  rstar);
                    P.push(mp(lstar,rstar));
                  }
                  lstar = k;
                }
              }
              if( lstar != r-1 ){
                P.push(mp(lstar, r));
                debug("P push", lstar,  r);
              }
            }else{
              Q = Q1;
              ans += 1;
              flag = true;
              break;
            }
          }
          debug("P.empty()", P.empty() );
          if( flag ) continue;
          else if( P.empty() ) return ans;
          else Q=P;
        }else{
          ans += 1;
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n ; cin >> n;
  vector<string> v(n); input(v);
  Solution sol;
  cout << sol.minDeletionSize(v) << '\n';

  return 0;
}
