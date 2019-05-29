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
typedef vector<ll>      vll;

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

/*
Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an integer point in the space covered by the rectangles.

Note:

    An integer point is a point that has integer coordinates. 
    A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
    ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
    length and width of each rectangle does not exceed 2000.
    1 <= rects.length <= 100
    pick return a point as an array of integer coordinates [p_x, p_y]
    pick is called at most 10000 times.

Example 1:

Input: 
["Solution","pick","pick","pick"]
[[[[1,1,5,5]]],[],[],[]]
Output: 
[null,[4,1],[4,1],[3,3]]

Example 2:

Input: 
["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
Output: 
[null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]

Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array of rectangles rects. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.

 */
random_device rd;

class Solution {
  mt19937 rng;
  uniform_int_distribution<ll> dist;
  vvi rect;
  vll bars;
public:
    Solution(vector<vector<int>>& rects) : rng(rd()) {
      this->rect = rects;
      for(auto & rec : rects ){
        print_(rec);
        bars.pb( ll( rec[2]+1-rec[0] ) * (rec[3]+1-rec[1]) );
      }
      int m = sz(bars);
      forall(i,1,m){
        bars[i] += bars[i-1];
      }
      print_(bars);
      dist = uniform_int_distribution<ll>(1,bars[m-1]);
    }
    
    vector<int> pick() {
      auto p = dist(rng);
      auto itr = lower_bound(all(bars),p);
      int idx = itr-bars.begin();
      int xx = p - (itr==bars.begin()?0:*(itr-1))- 1;
      int yy = rect[idx][3]+1-rect[idx][1];
      return { rect[idx][0] + xx/yy, rect[idx][1] + xx%yy };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vvi pnts(n, vi(4));
  for(auto & v : pnts ) input(v);
  Solution sol(pnts);
  forall(i,0,40){
    auto res = sol.pick();
    print_(res);
  }
  return 0;
}
