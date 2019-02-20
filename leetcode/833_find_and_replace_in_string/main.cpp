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
    string findReplaceString(string S, vector<int>& indexes, 
        vector<string>& sources, vector<string>& targets) {
      int n = indexes.size();
      int m = S.size();
      vi is_replaced(m,-1);
      forall(i,0,n){
        if( S.substr( indexes[i], sources[i].size() ) == sources[i] ){
          is_replaced[indexes[i]] = i;
          forall(j,1,sources[i].size()){
            is_replaced[indexes[i]+j] = INF;
          }
        }
      }
      string ans; 
      forall(i,0,m){
        if( is_replaced[i] == -1 ){
          ans += string(1, S[i]);
        }else if( is_replaced[i] == INF ){
          continue;
        }else{
          ans += targets[is_replaced[i]];
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
