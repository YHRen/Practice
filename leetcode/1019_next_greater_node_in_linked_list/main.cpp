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


#define INF                         (int)1000000007
#define EPS                         1e-9

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<(b);++i)
#define trav(a,x)                   for(auto & a: x)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define sz(c)                       (int)(c).size()
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

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

auto ____ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
      vi res, s;
      for(auto itr = head; itr!=nullptr; itr = itr->next){
        if( s.empty() || res[s.back()] >= itr->val ){
          s.pb(sz(res));
          res.pb(itr->val);
        }else{
          while( !s.empty() and res[s.back()] < itr->val ){
            res[s.back()] = itr->val;
            s.pop_back();
          }
          s.pb( sz(res) );
          res.pb(itr->val);
        }
      }
      while( !s.empty() ){
        res[s.back()] = 0;
        s.pop_back();
      }
      return res;
    }
    vector<int> nextLargerNodes_slow(ListNode* head) {
      vi ans;
      map<int,vi> buf; // val idx
      int idx = 0;
      while(head!=NULL){
        ans.pb(0);
        if( buf.empty() ){
          buf[head->val].pb(idx);
        }else{
          auto itr = buf.lower_bound(head->val);
          for(auto tt = buf.begin(); tt!=itr; ++tt){
            for(auto id : tt->second){
              ans[id] = head->val;
            }
          }
          buf.erase(buf.begin(), itr);
          buf[head->val].pb(idx);
        }
        ++idx;
        head = head->next;
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  return 0;
}
