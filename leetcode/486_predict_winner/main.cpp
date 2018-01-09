#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <cmath>
#include <cassert>

#define input(v)                  for(int i = 0; i < v.size(); ++i){ cin >> v[i]; }

// numeric_limits
#define INF                         (int)1e9
#define EPS                         1e-9

#define bitcount                    __builtin_popcount
#define gcd                         __gcd

#define forall(i,a,b)               for(int i=a;i<b;i++)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define mp                          make_pair

#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
typedef unsigned long long int ull_t;
typedef long long int           ll_t;

using namespace std;

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

/******* Actual Code Starts Here *********/
// contest 16B
class Solution {
  private:
    bool can_win( bool player, int l, int r, 
        const vector<int> & score,
        const vector<int> & v ){
      if( l == r ){
        if( player && score[player] + v[l] >= score[!player] ){
          return true;
        }else if( !player && score[player] + v[l] <= score[!player] ){
          return true;
        }else{
          return false;
        }
      }
      auto score1 = score;
      auto score2 = score;
      score1[player] += v[l];
      score2[player] += v[r];
      if( can_win( !player, l+1, r, score1, v ) == player ||
          can_win( !player, l, r-1, score2, v ) == player ){
        return player;
      }else{
        return !player;
      }
    }
  public:
    bool PredictTheWinner(vector<int>& nums) {
      if( nums.empty() || nums.size() <= 2 ) return true;
      int n = nums.size()-1;
      vector<int> score = {0,0};
      return can_win( true, 0, n, score, nums);
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> v(n);
  input(v);
  Solution s;
  cout << s.PredictTheWinner( v ) << '\n';

  return 0;
}
