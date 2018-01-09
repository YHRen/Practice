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
    vector<int> topKFrequent(vector<int>& nums, int k){
      unordered_map<int,int> dict;
      for(const auto & x : nums ) dict[x] ++;
      vector<ii> v;
      for(const auto & p : dict ){
        v.pb(mp(p.second,p.first));
      }
      auto comp = [](const ii & lhs, const ii & rhs ){
          if( lhs.first > rhs.first ) return true;
          if( lhs.first == rhs.first && lhs.second < rhs.second ) return true;
          return false;
          };
      nth_element(v.begin(), v.begin()+k, v.end(), comp);
      sort(v.begin(), v.begin()+k, comp);
      vi ans;
      for(auto itr = v.begin(); itr < v.begin()+k; ++itr){
        ans.pb(itr->second);
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
