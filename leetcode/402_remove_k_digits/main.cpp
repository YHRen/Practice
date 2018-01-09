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
  private:
    int find_first_zero( const string & s ){
      forall(i,0,s.size()){
        if( s[i] == '0' ){
          return i;
        }
      }
      return s.size();
    }
    void remove_leading_zeros( string & s ){
      int idx=s.size();
      forall(i,0,s.size()){
        if( s[i] == '0' ) continue;
        idx = i;
        break;
      }
      s = s.substr(idx);
    }
  public:
    string removeKdigits(string num, int k) {
      if( num.empty() || k >= num.size() ) return "0";
      vector<char> ans;
      ans.pb( num[0] );
      int rest = num.size();
      for(int i = 1; i < num.size(); ++i ){
        while(!ans.empty() && ans.back() > num[i] && k > 0 ){
          ans.pop_back();
          --k;
        }
        ans.pb( num[i] );
        if( !k ){ 
          rest = i+1;
          break;
        }
      }
      while(k>0 && !ans.empty()){
        ans.pop_back();
        --k;
      }

      string pre = string(all(ans));
      remove_leading_zeros( pre );
      pre += num.substr(rest);
      if( pre.empty() ) return "0";
      return pre;
    }
};
int main( int argc, char * argv[] ){
  string num;
  int k;
  cin >> num >> k;
  Solution sol;
  cout << sol.removeKdigits(num,k) << '\n';

  return 0;
}
