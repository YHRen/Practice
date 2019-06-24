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
#include <complex>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF              (int)1000000007
#define EPS              1e-9
#define pb               push_back
#define mp               make_pair
#define all(c)           c.begin(), c.end()
#define forall(i,a,b)    for(int i=a;i<(b);++i)
#define trav(a,x)        for(auto & a: x)
#define in(a,b)          ((b).find(a) != (b).end())
#define sz(c)            (int)(c).size()
#define input(a)         for(auto & x : a) cin >> x;

using namespace std;

typedef vector<int>      vi;
typedef pair<int,int>    ii;
typedef vector<vi>       vvi;
typedef vector<ii>       vii;
typedef long long        ll;

#ifdef DEBUG
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 */
  class MountainArray {
    public:
    vi v;
      int get(int index){
        if( index >= v.size() ) debug("ERROR",index);
        return v[index];
      }
      int length(){
        return v.size();
      }

  };

class Solution {
  int n;
  unordered_map<int,int> cache;
  int get_if_not_cached(int idx, MountainArray & v){
    auto itr = cache.find(idx);
    if( itr == cache.end() ){
      return cache[idx] = v.get(idx);
    }else{
      return itr->second;
    }
  }
  int find_peak(MountainArray & v){
    debug("find peak");
    if( n == 3 ) return 1;
    int l = 0, r = n;
    while( l < r ){
      int mid = (r+l)/2;
      debug("l,r,mid",l,r,mid);
      if( mid == n-1 ){ --r; continue ;}
      int x,y,z;
      x = get_if_not_cached(mid-1, v);
      y = get_if_not_cached(mid,   v);
      z = get_if_not_cached(mid+1, v);
      debug("x,y,z",x,y,z);
      if( x < y and y > z ) return mid;
      if( x > y and y > z ){ r = mid; }
      if( x < y and y < z ){ l = mid+1; }
    }
    return l;
  }

  int binary_search_up(int l, int r, int target, MountainArray & v){
    debug("binary search up");
    while(l<r){
      int mid = (r+l)/2;
      debug("l,r,mid",l,r,mid);
      int val = get_if_not_cached(mid, v);
      if( val == target ) return mid;
      else if( val < target ) l = mid+1;
      else r = mid;
    }
    return -1;
  }

  int binary_search_down(int l, int r, int target, MountainArray & v){
    while(l<r){
      int mid = (r+l)/2;
      int val = get_if_not_cached(mid, v);
      if( val == target ) return mid;
      else if( val > target ) l = mid+1;
      else r = mid;
    }
    return -1;
  }
    
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
      n = mountainArr.length();
      if( target < get_if_not_cached(0, mountainArr) and target < get_if_not_cached(n-1,mountainArr))
        return -1;
      int peak = find_peak(mountainArr);
      if( get_if_not_cached(peak, mountainArr) == target ) return peak;
      debug("found peak");
      if( target > get_if_not_cached(peak,mountainArr) ) return -1;
      int ans =  binary_search_up(0, peak, target, mountainArr);
      if( ans != -1 ) return ans;
      ans = binary_search_down(peak+1, n, target, mountainArr) ;
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,t ; cin >> n>>t; 
  MountainArray ma;
  ma.v.resize(n); input(ma.v);
  Solution sol;
  cout << sol.findInMountainArray(t, ma) << endl;
  return 0;
}
