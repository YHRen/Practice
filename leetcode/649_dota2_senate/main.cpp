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
    string predictPartyVictory(string senate) {
      int n = senate.size();
      queue<int> R,D;
      forall(i,0,n){
        if( senate[i] == 'R' ){
          R.push(i);
        }else{
          D.push(i);
        }
      }
      while( !R.empty() && !D.empty() ){
        if( R.front() < D.front() ){
          R.push( R.front()+n );
        }else{
          D.push( D.front()+n );
        }
        R.pop(); D.pop();
      }
      return R.empty() ? "Dire" : "Radiant";
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  cout << sol.predictPartyVictory(str) << '\n';


  return 0;
}
