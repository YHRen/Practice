#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
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
  string str;
  int n;
  bool C(int x, int y){
    forall(i,0,n){
      if( x + i == n ){ x = -i; }
      if( y + i == n ){ y = -i; }
      if( str[x+i] > str[y+i] ){
        return true;
      }else if( str[x+i] < str[y+i] ){
        return false;
      }
    }
    return false;
  }
  string construct( int x ){
    string ans = "";
    forall(i,0,n){
      if( x + i == n ){ x = -i;}
      ans.pb(str[i+x]);
      //+= to_string(str[i]);
    }
    return ans;
  }


  public:
    string orderlyQueue(string S, int K) {
      n = S.size();
      str = S;
      if( K == 1 ){
        int idx = 0;
        while( idx < n ){
          bool flag = false;
          forall(i,idx+1,n){
            debug("idx, i",idx, i);
            if( C(idx,i) ){
              debug("yes",idx, i);
              idx = i;
              flag = true;
              break;
            }
          }
          if( flag == false ) break;
        }
        debug("idx=",idx);
        return construct(idx);
      }else{
        sort(all(S));
        return S;
      }
    }
};
int main( int argc, char * argv[] ){
  int K; cin >> K;
  string str;  cin >> str;
  Solution sol;
  cout << sol.orderlyQueue(str, K) << '\n';

  return 0;
}
