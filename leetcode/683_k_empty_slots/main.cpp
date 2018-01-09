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
/******* Actual Code Starts Here *********/
class Solution {
  public:
    int kEmptySlots(vector<int>& flowers, int k) {
      int n = flowers.size();
      debug("n=",n);
      if( n < 2 ) return -1;
      int a = flowers[0];
      int b = flowers[1];
      if( a < b ) swap(a,b);
      ++k;
      if( a-b == k ) return 2;
      set<ii> bag;
      debug("a,b",a,b);
      bag.insert(mp(a,b));
      bag.insert(mp(b,0));
      bag.insert(mp(n+1,a));
      for(int i = 2; i < n; ++i ){
        int x = flowers[i];
        debug("find upper_bound)",x);
        auto itr = bag.upper_bound(mp(x,0));
        debug("found upper_bound)",itr->first,itr->second);
        if( itr->first == n+1 ){
            debug("at end ",i+1);
          if( x - itr->second == k ){
            debug("at end return ",i+1);
            return i+1;
          }else{
            ii p1 = mp( x, itr->second );
            ii p2 = mp(n+1,x);
            bag.erase(itr);
            debug("inserting",p1.first,p1.second);
            debug("inserting",p2.first,p2.second);
            bag.insert(p1);
            bag.insert(p2);
          }
        }else if( itr->second == 0 ){
            debug("at front  ",i+1);
          if( itr->first - x == k ){
            debug("at front return ",i+1);
            return i+1;
          }else{
            ii p1 = mp( x, 0);
            ii p2 = mp( itr->first, x);
            bag.erase(itr);
            debug("inserting",p1.first,p1.second);
            debug("inserting",p2.first,p2.second);
            bag.insert(p1);
            bag.insert(p2);
          }
        }else{
          if( itr->first - x == k || x - itr->second == k ){
            debug("itr=",itr->first, itr->second,"x=",x);
            debug("max bag=",bag.rbegin()->first, bag.rbegin()->second);
            debug("in mid return ",i+1);
            return i+1;
          }else{
            ii p1 = mp( x, itr->second );
            ii p2 = mp( itr->first, x);
            bag.erase(itr);
            debug("inserting",p1.first,p1.second);
            debug("inserting",p2.first,p2.second);
            bag.insert(p1);
            bag.insert(p2);
          }
        }
      }
      return -1;
    }
};
int main( int argc, char * argv[] ){
  int n,k; cin >> n >> k;
  vi v(n); input(v);
  Solution sol;
  cout << sol.kEmptySlots(v,k) << '\n';

  return 0;
}
