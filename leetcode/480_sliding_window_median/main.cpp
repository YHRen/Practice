#include <vector>
#include <queue>
#include <set>
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
//https://leetcode.com/contest/leetcode-weekly-contest-14/problems/sliding-window-median/
class Solution {
  private: 
    double find_median( const vector<int64_t> & nums, int k, multiset<int64_t> & lo, multiset<int64_t> & hi ){
      vector<int64_t> tmp( nums.begin(), nums.begin()+k);
      sort(tmp.begin(), tmp.end());
      print_(tmp);
      lo.insert( tmp.begin(), tmp.begin() + tmp.size()/2 );
      hi.insert( tmp.begin() + tmp.size()/2, tmp.end() ); // hi has extra element
      for(auto x :lo ){
        debug(x);
      }
      if( lo.size() < hi.size() ) return *hi.begin();
      else return ( *hi.begin()  + *lo.rbegin() ) / 2;
    }
    inline double avg( int x, int y ){
      if( x == y ) return x;
      if( x == -y ) return 0;
      return double( int64_t(x) + int64_t(y) )/2;
//      return double(x)/2 + double(y)/2;
    }

  public:
    vector<double> medianSlidingWindow(vector<int64_t>& nums, int k) {
      if( nums.empty() || k > nums.size() ) return vector<double>();
      if( k == 1 ) return vector<double>(nums.begin(), nums.end());
      multiset<int64_t> lo, hi;
      find_median( nums, k, lo, hi );
      debug(nums.size(),k);
      debug(lo.size(), hi.size() );
      int left = 0;
      bool is_even = lo.size() == hi.size();
      vector<double> rst;
      double med = ( is_even ? avg( *lo.rbegin() , *hi.begin() ) : *hi.begin() );
      rst.push_back( med );
      debug("before for");
      for(int left = 0 ; k < nums.size(); ++ left, ++k ){
        if( nums[left] >= *hi.begin() && hi.find(nums[left]) != hi.end() ){
          hi.erase(hi.find(nums[left]));
        }else{
          lo.erase(lo.find(nums[left]));
        }
        if( hi.empty() || nums[k] >= *hi.begin() ){
          hi.insert( nums[k] );
        }else{
          lo.insert( nums[k] );
        }
        if( is_even ){
          if( hi.size() > lo.size() ){
            int x = *hi.begin();
            hi.erase(hi.find(x));
            lo.insert(x);
          }else if( hi.size() < lo.size() ){
            int x = *lo.rbegin();
            hi.insert(x);
            lo.erase(lo.find(x));
          }
        }else{
          if( hi.size() > lo.size() && hi.size() - lo.size() == 3 ){
            int x = *hi.begin();
            hi.erase(hi.find(x));
            lo.insert(x);
          }else if( lo.size() > hi.size() ){
            int x = *lo.rbegin();
            lo.erase(lo.find(x));
            hi.insert(x);
          }
        }
        double med = ( is_even ? avg( *lo.rbegin() , *hi.begin() ) : *hi.begin() );
        rst.push_back( med );
      }
      return rst;
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n,k; cin >> n >> k;
  vector<int64_t> v(n);
  input(v);
  Solution s;
  vector<double> rst = s.medianSlidingWindow( v, k );
  print_(rst);




  return 0;
}
