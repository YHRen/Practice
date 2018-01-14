// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
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

#define bg     begin()
#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi>  vvi;
typedef vector<ii>  vii;

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
/******* Actual Code Starts Here *********/
/*
 *  https://leetcode.com/contest/weekly-contest-67/problems/couples-holding-hands/
 *  N couples sit in 2N seats arranged in a row and want to hold hands. We want
 *  to know the minimum number of swaps so that every couple is sitting side by
 *  side. A swap consists of choosing any two people, then they stand up and
 *  switch seats.

The people and seats are represented by an integer from 0 to 2N-1, the couples
are numbered in order, the first couple being (0, 1), the second couple being
(2, 3), and so on with the last couple being (2N-2, 2N-1).

The couples' initial seating is given by row[i] being the value of the person
who is initially sitting in the i-th seat.

Example 1:

Input: row = [0, 2, 1, 3] Output: 1 Explanation: We only need to swap the
second (row[1]) and third (row[2]) person.

Example 2:

Input: row = [3, 2, 0, 1] Output: 0 Explanation: All couples are already seated
side by side.
*/
class Solution {
  vi v,u;
  public:
  int minSwapsCouples(vector<int>& row) {
    int n = row.size();
    v.resize(n/2);
    u.resize(n/2);
    forall(i, 0, n) {
      if (row[i] % 2 == 0) {
        v[row[i] / 2] = i / 2;
      } else {
        u[row[i] / 2] = i / 2;
      }
    }
    int ans = 0;
    print_(v);
    print_(u);
    forall(i,0,n/2){
      if( v[i] == u[i] ) continue;
      bool found = false;
      forall(j,i+1,n/2){
        if( v[j] == v[i] ){
          swap( u[i], v[j] );
          ans ++;
          found = true;
        }
      }
      if( !found ){
        forall(j,i+1,n/2){
          if( u[j] == v[i] ){
            swap( u[i], u[j] );
            ans ++;
            found = true;
          }
        }
      }
    }
    print_(v);
    print_(u);
    return ans;
  }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n); input(v);
  Solution sol;
  cout << sol.minSwapsCouples(v) << '\n';

  return 0;
}
