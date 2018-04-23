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
    string mostCommonWord(string text, vector<string>& banned) {
      for (int i = 0, len = text.size(); i < len; i++) {
        if (ispunct(text[i])) {
            text.erase(i--, 1);
            len = text.size();
        }else{
          text[i] = tolower(text[i]);
        }
      }

      debug(text);

      set<string> B( all(banned) );
      map<string,int> cnt;
      istringstream iss(text);
      string cur_wrd;
      while( iss >> cur_wrd ){
        cnt[cur_wrd] += 1;
      }
      vector<pair<int,string>> v;
      for(auto p : cnt ){
        if( B.find(p.first) == B.end() ){
          v.pb(mp(p.second,p.first));
        }
      }
      sort(all(v));
      return v.rbegin()->second;
    }
};
int main( int argc, char * argv[] ){
  Solution sol;
  vector<string> ban = {"hit"};
  cout << sol.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.",
      ban) << '\n';

  return 0;
}
