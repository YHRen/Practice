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

//auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class DinnerPlates {
  int cap, ridx ;
  vector<stack<int>> vs;
  set<int> push_set; // left_most_index that has empty space
public:
    DinnerPlates(int capacity) : cap(capacity), ridx(0) {
    }
    
    void push(int val) {
      int idx =  push_set.empty() ? sz(vs) : *push_set.begin(); 
      debug("push val", val, "idx = ", idx);
      if( idx == sz(vs) ){
        push_set.insert(idx);
        vs.pb(stack<int>());
        if( ridx < idx ) ridx = idx;
        vs[idx].push(val);
        if( sz(vs[idx]) == cap ) push_set.erase(idx);
      }else if( sz(vs[idx]) < cap ){
        debug("\tinsert at empty slot",idx);
        vs[idx].push(val);
        if( sz(vs[idx]) == cap ){
            push_set.erase(idx);
            if(ridx <= idx and ridx+1 < sz(vs)) ridx ++;
        }

      }else{
        debug("ERROR: sz(vs[idx]) is full", idx, sz(vs[idx]));
      }
      debug("\tafter push, ridx = ", ridx);
    }
    
    int pop() {
      while( vs[ridx].empty() and ridx > 0 ){ ridx --; }
      if( ridx == 0 and vs[ridx].empty() ) return -1;
      debug("pop at", ridx);
      int ans = vs[ridx].top(); 
      vs[ridx].pop();
      push_set.insert(ridx);
      return ans;
    }
    
    int popAtStack(int idx) {
      debug("pop at ", idx);
      if( idx >= sz(vs) or vs[idx].empty() ) return -1;
      int ans = vs[idx].top();
      vs[idx].pop();
      push_set.insert( idx );
      return ans;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
int main( int argc, char * argv[] ){
  // test 1
  debug("==========TEST1===========");
  int tmp;
  DinnerPlates D(2);
  D.push(1);
  D.push(2);
  D.push(3);
  D.push(4);
  D.push(5);         // The stacks are now:  2  4
                     //                      1  3  5
                     //                      ﹈ ﹈ ﹈
  tmp = D.popAtStack(0);   // Returns 2.  The stacks are now:     4
                     //                                  1  3  5
                     //                                  ﹈ ﹈ ﹈
  clog << tmp  << " vs : " << 2 << endl;
  D.push(20);        // The stacks are now: 20  4
                     //                      1  3  5
                     //                      ﹈ ﹈ ﹈
  D.push(21);        // The stacks are now: 20  4 21
                     //                      1  3  5
                     //                      ﹈ ﹈ ﹈
  tmp = D.popAtStack(0);   // Returns 20.  The stacks are now:     4 21
                     //                                   1  3  5
                     //                                   ﹈ ﹈ ﹈
  clog << tmp  << " vs : " << 20 << endl;
  tmp = D.popAtStack(2);   // Returns 21.  The stacks are now:     4
                     //                                   1  3  5
                     //                                   ﹈ ﹈ ﹈ 
  clog << tmp  << " vs : " << 21 << endl;
  tmp = D.pop();            // Returns 5.  The stacks are now:      4
                     //                                   1  3 
                     //                                   ﹈ ﹈  
  clog << tmp  << " vs : " << 5 << endl;
  tmp = D.pop();            // Returns 4.  The stacks are now:   1  3 
                     //                                   ﹈ ﹈   
  clog << tmp  << " vs : " << 4 << endl;
  tmp = D.pop();            // Returns 3.  The stacks are now:   1 
                     //                                   ﹈   
  clog << tmp  << " vs : " << 3 << endl;
  tmp = D.pop();            // Returns 1.  There are no stacks.
  clog << tmp  << " vs : " << 1 << endl;
  tmp = D.pop();            // Returns -1.  There are still no stacks.
  clog << tmp  << " vs : " << -1 << endl;

  debug("==========TEST2===========");

  DinnerPlates D2(1);
  D2.push(1);
  D2.push(2);
  D2.push(3);
  debug(D2.popAtStack(1), " vs : ", 2);
  debug(D2.pop(), " vs : ", 3);
  debug(D2.pop(), " vs : ", 1);


  debug("==========TEST3===========");

  DinnerPlates D3(1);
  D2.push(1);
  D2.push(2);
  debug(D2.popAtStack(1), " vs : ", 2);
  debug(D2.pop(), " vs : ", 1);
  D2.push(1);
  D2.push(2);
  debug(D2.pop(), " vs : ", 2);
  debug(D2.pop(), " vs : ", 1);
  return 0;
}
