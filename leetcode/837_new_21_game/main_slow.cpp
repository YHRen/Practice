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
  int n,k,w;
  vector<double> prob;
public:
    double new21Game(int N, int K, int W) {
      n = N, k = K, w = W;
      prob.resize(n+1,0);
      prob[0] = 1;
      double scale =  (double)1.0 / (double)w;
      forall(i,0,K){
        forall(j,1,W+1){
          if( i+j < N+1 ){
            prob[i+j] += prob[i] * scale;
          }
        }
        print_(prob);
      }
      double ans = 0;
      forall(i,K,N+1){
        ans += prob[i];
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,k,w; cin >> n >> k >> w;
  Solution sol;
  cout << sol.new21Game( n,k,w)<<'\n';

  return 0;
}
