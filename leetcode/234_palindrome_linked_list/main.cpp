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
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
      int n = 0;
      auto cur = head;
      while( cur ){
        n++;
        cur = cur->next;
      }
      if( n <= 1 ) return true;
      auto tail = head;
      if( n%2 == 0 ){ // even, move to n/2
        forall(i,0,n/2){ tail = tail->next; }
      }else{ // odd, move to  n/2 + 1
        forall(i,0,n/2+1){ tail = tail->next; }
      }
      //reverse first half
      cur = head;
      ListNode * prv = nullptr;
      int j = n/2;
      while(cur and j--){
        auto tmp = cur->next;
        cur->next = prv;
        prv = cur;
        cur = tmp;
      }
      // compare two halves
      while( prv and tail ){
        if( prv->val == tail->val ){
          prv = prv->next;
          tail = tail->next;
        }else{
          return false;
        }
      }
      return true;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
