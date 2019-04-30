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
    ~ListNode(){
      if( this->next ) delete this->next;
    }
};

void print_list( ListNode * node){
  while(node){
    debug(node->val);
    node = node->next;
  }
}
class Solution {
  ListNode * merge_list( ListNode *& ptr1, ListNode *& ptr2 ){
    ListNode * res;
    if( !ptr1 ) res = ptr2;
    else if( !ptr2 ) res = ptr1;
    else {
      if( ptr1->val < ptr2->val ){
        res = ptr1;
        ptr1 = ptr1->next;
      }else{
        res = ptr2;
        ptr2 = ptr2->next;
      }
    }

    ListNode * cur = res;
    while(ptr1 and ptr2){
      if( ptr1->val < ptr2->val ){
        cur->next = ptr1;
        ptr1 = ptr1->next;
      }else{
        cur->next = ptr2;
        ptr2 = ptr2->next;
      }
      cur = cur->next;
    }
    if( ptr1 ){
      cur->next = ptr1;
    }
    if( ptr2 ){
      cur->next = ptr2;
    }
    return res;
  }

public:
    ListNode* sortList(ListNode* head) {
      if(!head) return head;
      print_list(head);
      queue<ListNode*> Q;
      ListNode * cur = head;
      while( cur ){
        if( cur->next != nullptr ){
          if( cur->val > cur->next->val){
            swap(cur->val, cur->next->val);
          }
          auto tmp = cur;
          cur = cur->next->next;
          tmp->next->next = nullptr;
          debug("pushing");
          print_list(tmp);
          Q.push(tmp);
        }else{
          Q.push(cur);
          cur = nullptr;
        }
      }
      debug("Q.size()",sz(Q));

      while(Q.size() > 1){
        auto ptr1 = Q.front(); Q.pop();
        auto ptr2 = Q.front(); Q.pop();
        debug("printing list while loop", Q.size());
        debug("ptr1:");
        print_list(ptr1);
        debug("ptr2:");
        print_list(ptr2);
        auto ptr3 = merge_list(ptr1, ptr2);
        debug("after merge");
        print_list(ptr3);
        Q.push(ptr3);
      }
      return Q.front();
        
    }
};
int main( int argc, char * argv[] ){
  ListNode * head = new ListNode(4);
  ListNode * cur = head;
  vi v = {2, 1, 3};
  forall(i,0,sz(v)){
    cur->next = new ListNode(v[i]);
    cur = cur->next;
  }
  print_list(head);
  Solution sol;
  auto res = sol.sortList(head);
  while(res){
    cout << res->val << ' ';
    res = res->next;
  }
  delete head;
  return 0;
}
