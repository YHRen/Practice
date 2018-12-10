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
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      int n = pushed.size();
      if ( n == 0 ) return true;
      vi is_visited(1000,false);
      stack<int> S;
      int idx = find(all(pushed),popped[0]) - pushed.begin();
      debug("idx = ",idx);
      forall(i,0,idx+1){
        S.push(pushed[i]);
        is_visited[pushed[i]] = true;
      }
      S.pop();
      print_(is_visited);
      forall(i,1,n){
        int x = popped[i];
        debug("i,x",i,x);
        if( is_visited[x] ){
          debug("visited");
          if( S.top() != x ){
            return false;
          }else{
            S.pop();
          }
        }else{
          debug("not visited");
          int idx2 = find(pushed.begin()+idx+1, pushed.end(), x) - pushed.begin();
          debug("idx2=",idx2);
          forall(i, idx+1, idx2+1){
            S.push(pushed[i]);
            is_visited[pushed[i]] = true;
          }
          idx = idx2;
          S.pop();
        }
      }
      return true;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n), u(n);
  input(v); input(u);
  Solution sol;
  cout << sol.validateStackSequences(v,u) << '\n';

  return 0;
}
