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
    int n;
    vi bits;
    void update(int pos ){
      for(; pos < n; pos |= pos + 1 ) bits[pos] ++;
    }
    int query(int pos){
      int ans = 0;
      for(; pos > 0; pos &= pos -1 ) ans += bits[pos-1];
      return ans;
    }

    vector<int> countSmaller(vector<int>& nums) {
      vi ans;
      if( nums.empty() ) return ans;
      n = nums.size();
      ans.resize(n);
      bits.resize(n,0);
      vii v(n);
      forall(i,0,n) v[i] = mp( nums[i], i);
      sort(all(v), [](const ii & lhs, const ii & rhs){
          if( lhs.first < rhs.first ) return true;
          else if( lhs.first == rhs.first && lhs.second > rhs.second ) 
          return true;
          else return false;
          });
      int eq = 0;
      forall(i,0,n){
        if( i && v[i].first == v[i-1].first ) eq++;
        else eq = 0;
        int idx = v[i].second;
        debug("i=",i, v[i].first, v[i].second,i,eq,query(idx+1));
        ans[idx] = i - eq - query(idx+1);
        update(idx);
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n ; cin >> n;
  vi v(n); input(v);
  Solution sol;
  auto ans = sol.countSmaller(v);
  print_(ans);

  return 0;
}
