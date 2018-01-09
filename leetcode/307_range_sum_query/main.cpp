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
class NumArray {
  private:
    vector<int> v;
    int org_sz; // input size
    int sz; // padding size = 2^ ceil( log2(orgsz) )
    static const int nill = numeric_limits<int>::min(); // empty node

  public:
    NumArray(vector<int> &nums) {
      if( nums.empty() ){ org_sz = 0, sz = 0; return; }
      this->org_sz = nums.size();
      this->sz = (1u << int(ceil(log2(org_sz))));
      v.assign(2 * sz, numeric_limits<int>::min());
      for( int i = 0; i < nums.size(); ++i ){
        v[i+sz] = nums[i];
      }
      for( int i = sz - 1; i > 0; --i ){
        if( v[i*2] == nill && v[i*2+1] == nill ) continue;
        if( v[i*2+1] == nill ){
          v[i] = v[i*2];
        }else{
          v[i] = v[i*2] + v[i*2+1];
        }
      }
    }

    void update(int i, int val) {
      if( i >= org_sz || i < 0 ) return;
      int idx = i+sz;
      int diff = val - v[idx];
      while( idx != 0 ){
        v[idx] += diff;
        idx /= 2;
      }
    }

    int sumRange(int i, int j) {
      if( i >= org_sz || j >= org_sz || i < 0 || j < 0 ) return 0;
      if( i == j ) return v[i+sz];
      if( i > j  ) swap(i,j); // i must < j
      int lo = i + sz;
      int hi = j + sz;
      //int lv = v.at(lo);
      //int rv = v.at(hi);
      int tot = 0;
      while( lo < hi ){
        if( lo%2 ){
          tot += v[lo++];
          lo /= 2;
        }else{
          lo /= 2;
        }
        if( hi%2 ){
          hi /= 2;
        }else{
          tot += v[hi];
          hi /= 2;
          hi --;
        }
      }
      if( lo == hi ) tot += v[lo];
      debug( tot + v[lo] );
      return tot;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> v(n);
  input(v);
  NumArray ary(v);
  /*
  cout << ary.sumRange(0, 1) << '\n';
  cout << ary.sumRange(0, v.size()-1)  << '\n';
  ary.update( v.size()/2, -8 );
  cout << ary.sumRange( 0, v.size()/2 )<< '\n';
  */

  ary.sumRange(5,6);  
  ary.update(9,27);
  ary.sumRange(2,3);
  ary.sumRange(6,7);
  ary.update(1,-82);
  ary.update(3,-72);
  ary.sumRange(3,7);
  ary.sumRange(1,8);
  ary.update(5,13);
  ary.update(4,-67);
  return 0;
}
