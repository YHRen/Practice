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
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void plist( ListNode * head ){
  while(head){
    clog << head->val << ' ';
    head = head->next;
  }
  clog << '\n';
}

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
      ListNode H(0);
      unordered_map<int, ListNode*> dic;
      dic[0] = &H;
      H.next = head;
      auto cur = head;
      int run = 0;
      while(cur){
        run += cur->val;
        auto nxt = cur->next;
        if( auto itr = dic.find(run); itr!=dic.end() ){
          debug("found", "at ", cur->val);
          auto prv = itr->second;
          auto a = prv->next, b = prv->next;
          int q = run;
          debug("before while")
          while(b != nxt){
            a = b->next;
            q += b->val;
            if(q!=run) dic.erase(q);
            debug("deleting b", b->val, "as val q", q);
            if (b) delete b;
            b = a;
          }
          prv->next = nxt;
        }else{
          debug("add", "at ", cur->val, "as val", run);
          dic[run] = cur;
        }
        cur = nxt;
      }
      return H.next;
    }
};

int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  ListNode * head = new ListNode(v[0]);
  auto cur = head;
  forall(i,1,n){
    cur->next = new ListNode(v[i]);
    cur = cur->next;
  }
  plist( head );
  Solution sol;
  auto ans = sol.removeZeroSumSublists(head);
  plist( ans );
  cur = ans;
  while(cur){
    auto tmp = cur->next;
    delete cur;
    cur = tmp;
  }

  

  return 0;
}
