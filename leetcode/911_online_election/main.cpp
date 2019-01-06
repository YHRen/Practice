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
class TopVotedCandidate {
  map<int, int> score_board; // time, winner
  unordered_map<int,int> scores;
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
      int n = persons.size();
      int current_max_score = 0;
      int current_max_candidate = -1;
      forall(i,0,n){
        int x = persons[i], y = times[i];
        auto itr = scores.find(x);
        if( itr == scores.end() ){ // new candidate
          itr = scores.insert(mp(x,1)).first;
        }else{
          itr->second += 1;
        }
        if( itr->second >= current_max_score ){
          score_board.insert(mp(y, x));
          current_max_score = itr->second;
        }
      }
    }
    
    int q(int t) {
      auto itr = score_board.lower_bound(t);
      if( itr != score_board.begin() && itr->first != t ) --itr;
      return itr->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
int main( int argc, char * argv[] ){

  return 0;
}
