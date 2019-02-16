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
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
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

// std::ios::sync_with_stdio(false);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class ExamRoom {
  int n;
  set<int> v;
  ii get_seat( int x, int y ){
    int dist = (y - x) / 2 - 1;
    int pos = x + dist + 1;
    return mp(dist, pos);
  }

   public:
    ExamRoom(int N) {
      n = N;
    }
    int seat(){
      if( v.empty() ){
        v.insert(0);
        return 0;
      }else if( v.size() == 1 ){
        int x = *v.begin();
        if( x < n/2 ){ v.insert(n-1); return n-1; }
        else{ v.insert(0); return 0;}
      }else{
        int dist = *v.begin() - 1;
        int pos  = 0;
        auto itr = v.begin();
        for(int x = *itr++; itr != v.end(); x = *itr++ ){
          auto p = get_seat(x, *itr );
          if( p.first > dist ){
            dist = p.first;
            pos  = p.second;
          }
        }
        if( dist < (n-1-*v.rbegin() - 1 ) ){
          dist = (n-1-*v.rbegin()-1);
          pos  = n-1;
        }
        debug("insert ", pos);
        v.insert(pos);
        return pos;
      }
    }
    
    void leave(int p) {
      v.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */

int main( int argc, char * argv[] ){
  int n; cin >> n;
  ExamRoom er(n);
  int x;
  while( cin  >> x ){
    if(x == -1 ){
      cout << er.seat() << '\n';
    }else{
      cout << "leave " << x << '\n';
      er.leave(x);
    }
  }

  return 0;
}

/*
n an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.

When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.  If there are multiple such seats, they sit in the seat with the lowest number.  (Also, if no one is in the room, then the student sits at seat number 0.)

Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() returning an int representing what seat the student sat in, and ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.

 

Example 1:

Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
Output: [null,0,9,4,2,null,5]
Explanation:
ExamRoom(10) -> null
seat() -> 0, no one is in the room, then the student sits at seat number 0.
seat() -> 9, the student sits at the last seat number 9.
seat() -> 4, the student sits at the last seat number 4.
seat() -> 2, the student sits at the last seat number 2.
leave(4) -> null
seat() -> 5, the student sits at the last seat number 5.

​​​​​​​

Note:

    1 <= N <= 10^9
    ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times across all test cases.
    Calls to ExamRoom.leave(p) are guaranteed to have a student currently sitting in seat number p.
*/
