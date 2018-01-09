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
#define input_( a )               for( auto & x : a ) cin >> x;
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
  public:
    string getHint(string v, string u) {
      int n = v.size();
      vi cnt1(10,0), cnt2(10,0),cnt3(10,0);
      forall(i,0,n){
        ++cnt1[v[i]-'0'];
        ++cnt2[u[i]-'0'];
        if( v[i] == u[i] ) ++cnt3[v[i]-'0'];
      }
      int cntA = 0, cntB = 0;
      for( auto & x : cnt3 ) cntA += x;
      forall(i,0,10){
        int x = min(cnt1[i],cnt2[i]);
        x -= cnt3[i];
        cntB +=x;
      }
      return to_string(cntA) + "A" + to_string(cntB) + "B";
    }
};
int main( int argc, char * argv[] ){
  string v,u;
  cin >> v >> u;
  Solution sol;
  cout << sol.getHint(v,u) << '\n';

  return 0;
}
