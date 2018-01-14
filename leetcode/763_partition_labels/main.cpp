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
 *  A string S of lowercase letters is given. We want to partition this string
 *  into as many parts as possible so that each letter appears in at most one
 *  part, and return a list of integers representing the size of these parts.
Example 1:

Input: S = "ababcbacadefegdehijhklij" Output: [9,7,8] Explanation: The
partition is "ababcbaca", "defegde", "hijhklij".  This is a partition so that
each letter appears in at most one part.  A partition like "ababcbacadefegde",
"hijhklij" is incorrect, because it splits S into less parts.
*/
class Solution {
  public:
    vector<int> partitionLabels(string S) {
      if( S.empty() ) return vi{};
      vii v(26,{-1,-1});
      int n = S.size();
      forall(i,0,n){
        int idx = S[i] - 'a';
        if( v[idx].first == -1 ){ 
          v[idx].first = i;
          v[idx].second = i;
        }else{
          v[idx].second = i;
        }
      }
      sort(all(v));
      vi ans;
      int l = 0, r=-1;
      for( auto p : v ){
        if( p.first == -1 ) continue;
        if( p.first > r ){
          ans.pb(r-l+1);
          l = p.first;
          r = p.second;
        }else{ // p.first < r
          r = max( p.second, r );
        }
      }
      ans.pb(r-l+1);
      return vi(ans.begin()+1, ans.end());
    }
};
int main( int argc, char * argv[] ){
  string S; cin >> S;
  Solution sol;
  auto ans = sol.partitionLabels(S);
  print_(ans);

  return 0;
}
