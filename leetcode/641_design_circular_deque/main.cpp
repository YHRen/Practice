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
/*
Design your implementation of the circular double-ended queue (deque).

Your implementation should support following operations:

    MyCircularDeque(k): Constructor, set the size of the deque to be k.
    insertFront(): Adds an item at the front of Deque. Return true if the operation is successful.
    insertLast(): Adds an item at the rear of Deque. Return true if the operation is successful.
    deleteFront(): Deletes an item from the front of Deque. Return true if the operation is successful.
    deleteLast(): Deletes an item from the rear of Deque. Return true if the operation is successful.
    getFront(): Gets the front item from the Deque. If the deque is empty, return -1.
    getRear(): Gets the last item from Deque. If the deque is empty, return -1.
    isEmpty(): Checks whether Deque is empty or not. 
    isFull(): Checks whether Deque is full or not.

 

Example:

MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to be 3
circularDeque.insertLast(1);			// return true
circularDeque.insertLast(2);			// return true
circularDeque.insertFront(3);			// return true
circularDeque.insertFront(4);			// return false, the queue is full
circularDeque.getRear();  			// return 2
circularDeque.isFull();				// return true
circularDeque.deleteLast();			// return true
circularDeque.insertFront(4);			// return true
circularDeque.getFront();			// return 4

 

Note:

    All values will be in the range of [0, 1000].
    The number of operations will be in the range of [1, 1000].
    Please do not use the built-in Deque library.

 */
class MyCircularDeque {
  vi buf;
  int f,b,cnt,k;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k): f(0), b(k-1), cnt(0), k(k), buf(k,0) {
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
      if( cnt == k ) return false;
      buf[f] = value;
      f += 1;
      f %= k;
      cnt ++;
      return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
      if( cnt == k ) return false;
      buf[b] = value;
      b -= 1;
      b = (b+k)%k;
      cnt ++;
      return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
      if( cnt == 0 ) return false;
      f -= 1;
      f = (f+k)%k;
      cnt --;
      return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
      if( cnt == 0 ) return false;
      b += 1;
      b %= k;
      cnt --;
      return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
      return cnt ? buf[(f-1+k)%k] : -1;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
      return cnt ? buf[(b+1)%k] : -1;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
      return cnt == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
      return cnt == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
