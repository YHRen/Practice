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
/******* Actual Code Starts Here *********/
class Solution {
  private:
    int ans, dif, t;
    void maybe_update(int x ){
      if( abs(x-t) < dif ){
        ans = x;
        dif = abs(x-t);
      }
    }
  public:
    int threeSumClosest(vector<int>& v, int target) {
      dif=INF;
      int n = v.size();
      sort(all(v));
      forall(i,0,n-2){
        int j = i+1, k = n-1;
        t = target;
        while( j != k ){
          debug("i,j,k",i,j,k,dif,ans);
          int x = v[i]+v[j]+v[k];
          if( x == t ){
            return t;
          }else if( x < t ){
            maybe_update(x);
            ++j;
          }else if( x > t ){
            maybe_update(x);
            --k;
          }
          debug("i,j,k",i,j,k,dif,ans);
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,t; cin >> n >> t;
  vi v(n);
  for( auto & x : v ) cin  >> x;
  Solution sol;
  cout << sol.threeSumClosest(v,t) << '\n';

  return 0;
}
