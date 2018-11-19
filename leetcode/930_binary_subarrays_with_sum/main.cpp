#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
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
    void move_to_next_one( const vi & A, int & idx){
      int n = A.size();
      for(++idx; idx<A.size(); ++idx){
        if(A[idx]) break;
      }
    }

    int numSubarraysWithSum(vector<int>& A, int S) {
      int n = A.size();
      {
        int total = 0;
        for(auto x : A) total+=x;
        if( S > total ) return 0;
        if( S == 0 && total==0 )
          return n*(n+1)/2;
        if( S == 0 && total==n )
          return 0;
      }
      {
        if( S == 0 ){
          auto itr = A.begin();
          int cnt = 0;
          while(itr != A.end()){
            itr = find(itr, A.end(), 0);
            int run = 0;
            for(; itr!=A.end();++itr){
              if( *itr == 0 ) ++run;
              else break;
            }
            cnt += run*(run+1)/2;
          }
          return cnt;
        }
      }

      vi left(n, -1);
      vi right(n, n);
      {
        int pre = -1;
        forall(i,0,n){
          left[i] = pre;
          if( A[i] ){ pre = i; }
        }
      }
      {
        int pre = n;
        for(int i=n-1; i>-1; --i){
          right[i] = pre;
          if(A[i]) pre = i;
        }
      }

      print_(left);
      print_(right);

      int run = 0;
      int cnt = 0;
      int l = -1, r;
      move_to_next_one(A, l);
      for(r=l; r < n; ++r){
        run += A[r];
        if( run == S ){
          break;
        }
      }
      while( r != n ){
        cnt += (l - left[l] ) * (right[r] - r );
        move_to_next_one(A, l);
        move_to_next_one(A, r);
      }
      return cnt;
    }
};
int main( int argc, char * argv[] ){
  int n,m ; cin >> n >> m;
  vi v(n); input(v);
  Solution sol;
  cout << sol.numSubarraysWithSum(v,m) << '\n';

  return 0;
}
