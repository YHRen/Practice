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

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      if( !head or !head->next ) return head;
      ListNode * h1 = head, * h2 = head->next;
      ListNode * l1 = h1, *l2 = h2;
      int x = 1;
      ListNode * r = h2->next;
      while( r!= nullptr ){
        if( x%2 ){
          l1->next = r;
          l1 = r;
          debug("l1=r");
        }else{
          l2->next = r;
          l2 = r;
          debug("l2=r");
        }
        ++x;
        debug("x=",x);
        r = r->next;
        debug("r null",r==nullptr);
      }
      l2->next = nullptr;
      l1->next = h2;
      return h1;
    }
};
int main( int argc, char * argv[] ){
  vi v = {1,2,3,4,5};
  ListNode * head = new ListNode(1);
  ListNode * cur = head;
  forall(i,1,5){
    cur->next = new ListNode(v[i]);
    cur = cur->next;
  }
  Solution sol;
  auto A = sol.oddEvenList(head);
  while( A ){
    cout << A->val << " -> ";
    A = A->next;
  }
  cout << endl;


  return 0;
}
