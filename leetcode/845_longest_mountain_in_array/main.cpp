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
class Solution {
  public:
    int longestMountain(vector<int>& A) {
      int n=A.size();
      if( n < 3 ) return 0;
      int state = 0, ans = 0, left; // 1: climbing, -1 descending, 0, flat
      forall(i,0,n-1){
        if( state == 0 ){
          if( A[i+1] > A[i] ){
            left = i;
            state = 1;
          }
        }else if( state == 1 ){
          if( A[i+1] == A[i] ){
            state = 0;
          }else if( A[i+1] < A[i] ){
            state = -1;
            ans = max(ans, i+1-left+1);
          }
        }else if( state == -1 ){
          if( A[i+1] == A[i] ){
            ans = max(ans, i+1-left);
            state = 0;
          }else if( A[i+1] > A[i] ){
            ans = max(ans, i+1-left);
            state = 1;
            left = i;
          }else if( i+1 == n-1 ){
            ans = max(ans, n-left);
          }
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}

/*
Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:

    B.length >= 3
    There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]

(Note that B could be any subarray of A, including the entire array A.)

Given an array A of integers, return the length of the longest mountain. 

Return 0 if there is no mountain.

Example 1:

Input: [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

Example 2:

Input: [2,2,2]
Output: 0
Explanation: There is no mountain.

Note:

    0 <= A.length <= 10000
    0 <= A[i] <= 10000

Follow up:

    Can you solve it using only one pass?
    Can you solve it in O(1) space?

*/
