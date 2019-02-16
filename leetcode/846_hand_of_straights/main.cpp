#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
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

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

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
    bool isNStraightHand(vector<int>& hand, int W) {
      int n = hand.size();
      if( n%W != 0 ) return false;
      map<int, int> cnt;
      for(auto x : hand) cnt[x]+=1;
      vii sorted_hand;
      copy(all(cnt), back_inserter(sorted_hand));
      int m = sorted_hand.size();
      if( m < W ) return false;
      forall(i,0,m-W+1){
        int h = sorted_hand[i].second;
        if( h == 0 ) continue;
        forall(j,1,W){
          if( sorted_hand[i+j].first - sorted_hand[i+j-1].first != 1 ) return false;
          if( sorted_hand[i+j].second < h ) return false;
          sorted_hand[i+j].second -= h;
        }
        sorted_hand[i].second = 0;
      }
      for(auto p : sorted_hand) if( p.second > 0 ) return false;
      return true;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}

/*
Alice has a hand of cards, given as an array of integers.

Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.

Return true if and only if she can.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].

Example 2:

Input: hand = [1,2,3,4,5], W = 4
Output: false
Explanation: Alice's hand can't be rearranged into groups of 4.

 

Note:

    1 <= hand.length <= 10000
    0 <= hand[i] <= 10^9
    1 <= W <= hand.length

*/
