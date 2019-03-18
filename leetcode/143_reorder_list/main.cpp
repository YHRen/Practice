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
  ListNode * insert_and_return( ListNode * current, ListNode * head ){
    if( current->next == nullptr ){ // reached the end of list
      if( head->next == current ) return current->next=nullptr;
      else{
        auto tmp = head->next;
        head->next = current;
        return current->next = tmp;
      }
    }else{
      auto pre = insert_and_return(current->next, head);
      if( pre == nullptr ) return nullptr;
      else if( pre->next == current or pre==current ) return current->next = nullptr;
      else{
        auto tmp = pre->next;
        pre->next = current;
        return current->next = tmp;
      }
    }
  }

public:
    void reorderList(ListNode* head) {
      if( head ) insert_and_return(head, head);
    }
};

int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n); input(v);
  ListNode * head = new ListNode(v[0]);
  auto run = head;
  forall(i,1,n){
    run->next = new ListNode(v[i]);
    run = run->next;
  }
  Solution sol;
  for(run = head; run != nullptr; run=run->next){ 
    cout << run->val << ' ';
  }cout << '\n';
  sol.reorderList(head);
//  return 0;
  for(run = head; run != nullptr; run=run->next){ 
    cout << run->val << ' ';
  }cout << '\n';

  return 0;
}
