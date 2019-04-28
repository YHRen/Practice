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

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ~ListNode(){
      if(next) delete next;
    }
};

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int tmp = 0 ) {
      tmp += (l1?l1->val:0) + (l2?l2->val:0);
      if( tmp || (l1 or l2) ){
        ListNode * head = new ListNode( tmp%10 );
        head->next = addTwoNumbers( l1?l1->next:nullptr, l2?l2->next:nullptr, tmp/10);
        return head;
      }else return nullptr;
    }
};

ListNode * vec2list( const vi & v ){
  if( v.empty() ) return nullptr;
  ListNode * head = new ListNode(v[0]);
  ListNode * res = head;
  int n = sz(v);
  forall(i,1,n){
    res->next = new ListNode(v[i]);
    res = res->next;
  }
  return head;
}

int main( int argc, char * argv[] ){
  //vi v = {9,9,9}, u = { 1, 2};
  vi v = {0}, u = { 0};
  ListNode *l1 = vec2list(v);
  ListNode *l2 = vec2list(u);
  Solution sol;
  auto res = sol.addTwoNumbers(l1, l2);
  while(res){
    cout << res->val << ' ';
    res = res->next;
  }
  cout << endl;
  return 0;
}
