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
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
      vi is_prime(21, 0);
      is_prime[2] = 1;
      is_prime[3] = 1;
      is_prime[5] = 1;
      is_prime[7] = 1;
      is_prime[11] = 1;
      is_prime[13] = 1;
      is_prime[17] = 1;
      is_prime[19] = 1;
      int ans = 0;
      forall(i,L,R+1){
        int x = __builtin_popcount(i);
        if( is_prime[x] ) ++ans;
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int L,R;
  cin >> L >> R;
  Solution sol;
  cout << sol.countPrimeSetBits(L,R) << '\n';

  return 0;
}
