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
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Your implementation should support following operations:

    MyCircularQueue(k): Constructor, set the size of the queue to be k.
    Front: Get the front item from the queue. If the queue is empty, return -1.
    Rear: Get the last item from the queue. If the queue is empty, return -1.
    enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
    deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
    isEmpty(): Checks whether the circular queue is empty or not.
    isFull(): Checks whether the circular queue is full or not.

 

Example:

MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
circularQueue.enQueue(1);  // return true
circularQueue.enQueue(2);  // return true
circularQueue.enQueue(3);  // return true
circularQueue.enQueue(4);  // return false, the queue is full
circularQueue.Rear();  // return 3
circularQueue.isFull();  // return true
circularQueue.deQueue();  // return true
circularQueue.enQueue(4);  // return true
circularQueue.Rear();  // return 4

 

Note:

    All values will be in the range of [0, 1000].
    The number of operations will be in the range of [1, 1000].
    Please do not use the built-in Queue library.


 */
class MyCircularQueue {
  vi buf;
  int f, b, cnt, k;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k): k(k), f(0), b(0), cnt(0), buf(k) {
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
      if( cnt == k ) return false;
      cnt ++ ;
      buf[b++] = value;
      b %= k;
      return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
      if( cnt == 0 ) return false;
      cnt --;
      f += 1;
      f %= k;
      return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
      return cnt ? buf[f] : -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
      return cnt ? buf[(b-1+k)%k] : -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
      return cnt == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
      return cnt == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
