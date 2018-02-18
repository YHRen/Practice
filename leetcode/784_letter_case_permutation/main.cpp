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

  vector<string> ans;
  void aux( string str, int idx ){
    if( idx == str.size() ) return ;
    if( isalpha(str[idx] ) ){
      ans.pb(str);
      aux(str, idx+1);
      if( islower(str[idx]) ){
        str[idx] = toupper( str[idx] );
        ans.pb(str); 
        aux( str, idx+1);
      }else{
        str[idx] = tolower( str[idx] );
        ans.pb(str);
        aux(str, idx+1 );
      }
    }else{
      aux(str,idx+1);
    }
  }
  public:
    vector<string> letterCasePermutation(string S) {
      aux( S, 0 );
      if( ans.empty() ) ans.pb(S);
      sort(all(ans));
      ans.erase( unique(all(ans)), ans.end() );
      return ans;
    }
};
int main( int argc, char * argv[] ){
  string str ;
  cin >> str;
  Solution sol;
  auto ans = sol.letterCasePermutation(str);
  print_(ans);

  return 0;
}
