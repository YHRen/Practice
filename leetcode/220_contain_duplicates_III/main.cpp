#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <set>
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
// https://leetcode.com/problems/contains-duplicate-iii/ 
// Given an array of integers, find out whether there are two distinct indices
// i and j in the array such that the absolute difference between nums[i] and
// nums[j] is at most t and the absolute difference between i and j is at most
// k. 
// 
// I think the best solution would be using a kd-tree. O(NlogN)
// A naive solution would take O(Nk)

class Solution {
  private:
    bool insert_new( set<long> & bag, const long value, const long t ){
      debug("inserting ",value);
      auto itr = bag.lower_bound( value-t );
      if( itr != bag.end() ){
        if( *itr - value <= t ){
          return true;
        }
      }else if( !bag.empty() && 
          itr != bag.begin() &&
          value - *(--itr) <= t ){
        return true;
      }
      bag.insert(value);
      return false;
    }

  public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      if( nums.empty() || k<=0 || t < 0 ) return false;
      set<long> bag;
      // initialize the set
      for( int i = 0; i < min(k+1, int(nums.size()) ); ++i ){
        if( insert_new( bag, nums[i], t ) ) return true;
      }
      // num2idx has k+1 elements

      for( int i = k+1; i < nums.size(); ++i ){
        debug(i,nums[i-k-1]);
        auto itr = bag.find( nums[i-k-1] );
        assert( itr != bag.end() );
        bag.erase(itr);
        if( insert_new( bag, nums[i], t ) ) return true;
      }

      return false;
    }
};

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n,k,t; cin >> n >> k >> t;
  vector<int> v(n);
  input(v);
  Solution s;
  cout << s.containsNearbyAlmostDuplicate( v, k, t ) << '\n';;

  return 0;
}
