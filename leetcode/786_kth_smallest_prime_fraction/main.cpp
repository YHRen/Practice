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
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
      int n = A.size(); 
      if( K == 1 ) return {A[0], A.back()};

      auto cmp = [&A]( const ii & lhs, const ii & rhs ){
        if( A[lhs.first] * A[rhs.second] > A[rhs.first] * A[lhs.second] ) return true;
        else return false;
      };
      
      priority_queue<ii, vii, decltype(cmp)> Q(cmp);

      forall(i,0,n-1){
        Q.push( mp(i,n-1) );
      }
      while( K-->1 ){
        auto p = Q.top(); Q.pop();
        int idx = p.first, nxt=p.second;
        if( nxt - idx > 1 ){
          Q.push( mp( idx, nxt-1 ) );
        }
      }
      return {A[Q.top().first],  A[Q.top().second]};
    }
};
int main( int argc, char * argv[] ){
  int n ; cin >> n;
  vi v(n);
  input(v);
  int k ; cin >> k;
  Solution sol;
  auto ans = sol.kthSmallestPrimeFraction(v,k);
  print_(ans);

  return 0;
}
