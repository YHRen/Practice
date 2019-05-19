#include <vector>
#include <random>
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
#define forall(i,a,b)               for(int i=a;i<(b);++i)
#define trav(a,x)                   for(auto & a: x)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define sz(c)                       (int)(c).size()
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

auto ____ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  vi B;
  vi bl;
  int n, m;
  mt19937 rng;
  uniform_int_distribution<int> dist;
  public:
    Solution(int N, vector<int> blacklist) {
      sort(all(blacklist));
      //B = blacklist;
      swap(bl, blacklist);
      forall(i,0,sz(bl)) bl[i] -= i;
      print_(bl);
      this->dist = uniform_int_distribution<int>(0,N-sz(bl)-1);
      random_device rd;
      this->rng.seed( rd() );
    }

    int pick(){
      auto r = dist(rng);
      debug("r=",r);
      return r + (upper_bound(all(bl),r)-bl.begin());
    }
    int pick_slow() {
      int x = dist(rng);
      debug("pick x=", x);
      int lo = x, hi = n+1;
      while(lo < hi){
        int mid = (lo+hi)/2;
        auto itr = lower_bound(all(B), mid);
        int y;
        if( itr == B.end() ){
          if( mid - sz(B) == x ) return mid;
          else if( mid-sz(B) < x ){ 
            lo = mid+1;
          }else{
            hi = mid-1;
          }
        }else if( *itr == mid){
          int cnt = itr-B.begin();
          if( mid-cnt == x ){
            lo = mid+1;
          }else if( mid-cnt < x ){
            lo = mid + 1;
          }else{
            hi = mid-1;
          }
        }else{
          int cnt = itr-B.begin();
          if( mid-cnt == x ){
            return mid;
          }else if( mid-cnt < x ){
            lo = mid+1;
          }else{
            hi = mid-1;
          }
        }
      }
      return lo;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
int main( int argc, char * argv[] ){
  int n, m; cin >> n >> m;
  vi v(m); input(v);
  Solution sol(n, v);
  debug("0->0, 1->1, 2->4, 3->6, 4->8, 5->9");
  forall(i,0,20) 
    cout << sol.pick() << '\n';

  return 0;
}


/*  generate random number from [0, N) but not in B.
 *  idea 1: generate enough number not to hit B. could be slow if B contains many number
 *  idea 2: generate a number from [0, N-sz(B) ), say, x, find the real number y such that
 *    y = x + (|B|<y)
 *
 *
 *  i.e. [0, 10) but B = [2,3,5,7] 
 *   n = 10, m = 10 - 4 = 6
 *   generate a number from [0, 6)
 *   such that 0->0, 1->1, 2->4, 3->6, 4->8, 5->9,
 *   say, x = 4,
 *   find y such that y - |B<y|==x
 *   we can do binary search for y
 *
 *  idea 3: 
 *  for( int i = 0; i < sz(bl); ++i )
 *    bl[i] -= i;
 *
 *  [2, 3, 5, 7] --> [2, 2, 3, 4]
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
