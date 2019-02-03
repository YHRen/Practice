#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
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
  vector<string> split(const string & str){
    vector<string> ans;
    istringstream iss(str);
    string tmp;
    while( getline(iss, tmp, ' ') ) ans.pb(tmp);
    return ans;
  }
  public:
    vector<string> uncommonFromSentences(string A, string B) {
      auto vA = split(A);
      auto vB = split(B);
      unordered_map<string, int> cntA, cntB;
      unordered_set<string> setA, setB;
      for(auto s : vA){ setA.insert(s); cntA[s]+=1;}
      for(auto s : vB){ setB.insert(s); cntB[s]+=1;}
      unordered_set<string> onceA, onceB;
      for(auto p: cntA){ if(p.second == 1) onceA.insert(p.first); }
      for(auto p: cntB){ if(p.second == 1) onceB.insert(p.first); }
      unordered_set<string> ans;
      for(auto x : onceA ) if( ! in(x, setB) ) ans.insert(x);
      for(auto x : onceB ) if( ! in(x, setA) ) ans.insert(x);
      vector<string> v;
      copy(all(ans), back_inserter(v));
      return v;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
