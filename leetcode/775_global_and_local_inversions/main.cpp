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
  int get_local( vi & v){
    int cnt = 0;
    int n = v.size();
    for(int i = 0; i < n-1; ++i ) if( v[i+1] < v[i] ) ++cnt;
    return cnt;
  }
  int get_global( vi & v){
    int cnt = 0, n = v.size();
    set<int> bag;
    bag.insert(v[0]);
    for( int i = 1; i < n; ++i ){
      auto itr = lower_bound(all(bag), v[i]);
      cnt += distance(itr, bag.end());
      bag.insert(v[i]);
    }
    return cnt;
  }
  bool isIdealPermutation(vector<int>& A) {
    int p = get_local(A);
    int q = get_global(A);
    debug(p,q);
    return p == q;

  }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n);
  input(v);
  Solution sol;
  cout << sol.isIdealPermutation(v) << '\n';


  return 0;
}
