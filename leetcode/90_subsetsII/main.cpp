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

class Solution {
  private:
    void subsets_aux( 
        int idx,
        const vector<int> & uniq,
        const vector<int> & cnt,
        vector<vector<int>> & rst
        ){
      if( idx == uniq.size() ) return;
      // for each existing subsets, push 0 to n current elements
      vector<vector<int>> org = rst;
      for( int i = 0; i < cnt[idx]; ++ i ){
        vector<vector<int>> tmp = org;
        for( auto & v : tmp ){
          for( int j = 0; j <= i; ++ j ){
            v.push_back(uniq[idx]);
          }
        }
//        rst.insert( rst.end(), tmp.begin(), tmp.end()  );
       rst.insert( rst.end(), 
           make_move_iterator(tmp.begin() ), 
           make_move_iterator(tmp.end() ) );
      }
      subsets_aux( idx + 1, uniq, cnt, rst );
    }

  public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<vector<int>> rst;
      if( nums.size() == 0 ) return rst;
      sort(nums.begin(), nums.end());
      vector<int> uniq = nums;
      uniq.erase( unique( uniq.begin(), uniq.end() ), uniq.end() );
      print_(uniq);
      vector<int> cnt( uniq.size(), 0 );
      for( int i = 0, j = 0, x = nums[0]; i < nums.size(); ++i ){
        if( nums[i] == x ) cnt[j]++;
        else{
          j++;
          cnt[j]++;
          x = nums[i];
        }
      }
      print_(cnt);
      rst.push_back( vector<int> () );
      subsets_aux( 0, uniq, cnt, rst); 
      return rst;
    }
    
};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> v(n);
  input(v);
  Solution s;
  vector<vector<int>> rst = s.subsetsWithDup( v );
  for( auto vv : rst ){
    print_(vv);
  }




  return 0;
}
