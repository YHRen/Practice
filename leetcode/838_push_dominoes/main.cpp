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
    string pushDominoes(string v) {
      int n = v.size();
      if( n == 0 ) return v;
      
      queue<int> Q;
      forall(i,0,n)
        if (v[i] == 'L' or v[i] =='R' ) Q.push(i);

      debug(n, Q.size());
      while( !Q.empty() ){
        map<int, int> dict;
        debug("Q.size()", Q.size());
        while( !Q.empty() ){
          int x = Q.front(); Q.pop();
          if( v[x] == 'L' and x > 0 and v[x-1] == '.' ){
            dict[x-1] += 1;
          }
          if( v[x] == 'R' and x+1 < n and v[x+1] == '.' ){
            dict[x+1] += 2;
          }
        }
        for(auto p : dict ){
          if( p.second == 1 ){
            v[p.first] = 'L';
            Q.push(p.first);
          }else if( p.second==2 ){
            v[p.first] = 'R';
            Q.push(p.first);
          }
        }
      }
      return v;
    }
};
int main( int argc, char * argv[] ){
  string v = ".L.R...LR..L..";
  Solution sol;
  cout << sol.pushDominoes(v) << '\n';

  return 0;
}
