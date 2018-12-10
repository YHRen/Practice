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
  vi v;
  int n;
  int find_next(int i){
    if( i+1 == n ) i = 0;
    else i = i +1;
    forall(j,i,n){
      if( v[j] == 0 ) return j;
    }
    forall(j,0,i){
      if( v[j] == 0 ) return j;
    }
    return -1;
  }


public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
      n = deck.size();
      sort(all(deck));
      v.resize(n,0);
      int j = 0;
      forall(i,0,n){
        v[j] = deck[i];
        j = find_next(j);
        j = find_next(j);
      }
      return v;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n);

  return 0;
}
