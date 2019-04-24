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
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  ListNode * reverse(ListNode * head, int k){
    ListNode * cur = head;
    ListNode * nxt, *prv = nullptr;
    while( k-- ){
      nxt = cur->next;
      cur->next = prv;
      prv = cur;
      cur = nxt;
    }
    return prv;
  }
  int try_advance(ListNode * cur, ListNode *& tail, const int k ){
    if( cur == nullptr ) return 0;
    debug("cur=",cur->val);
    int cnt = 0;
    while( cur and cnt < k ){
      cur = cur->next;
      cnt ++;
    }
    if( cnt == k ) tail = cur;
    debug("cnt=",cnt);
    return cnt;
  }


  public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode * tail;
      if( try_advance(head,tail,k) <k ) return head;
      ListNode * new_head = reverse( head, k );
      head->next = reverseKGroup(tail, k);
      return new_head;
    }
};
int main( int argc, char * argv[] ){
  ListNode * head = new ListNode(1);
  ListNode * cur = head;
  forall(i,2,7){
    cur->next = new ListNode(i);
    cur = cur->next;
  }
  Solution sol;
  auto ans = sol.reverseKGroup(head, 3);
  while(ans!=nullptr){
    cout << ans->val <<endl;
    ans = ans->next;
  }
  return 0;

}
