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

/*
Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]

Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
class SummaryRanges {
  vvi v;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
      if( v.empty() ) v.pb({val,val});
      else{
        auto itr = lower_bound(all(v),vi {val,val});
        if( itr == v.end() ){
          if( (*(itr-1))[1] >= val ) return;
          if( (*(itr-1))[1] == val-1 ){
            (*(itr-1))[1] += 1;
          }else{
            v.pb({val,val});
          }
        }else if( (*itr)[0] == val+1 ){
          (*itr)[0] = val;
          if(itr != v.begin() and (*(itr-1))[1] == val -1 ){
            // mrege
            (*(itr-1))[1] = (*(itr))[1];
            v.erase(itr);
          }
        }else if( itr!=v.begin() and (*(itr-1))[1] == val-1 ){
          (*(itr-1))[1] = val;
        }else if( itr!=v.begin() and (*(itr-1))[0] <= val and (*(itr-1))[1]>= val ){
          // already in
          return;
        }else if( (*itr)[0] == val ){
          return;
        }else{
          v.pb({val,val});
        }
      }
      sort(all(v));
    }

    vector<vector<int>> getIntervals() {
      return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
