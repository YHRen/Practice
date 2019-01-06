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
  bool is_nine_and_not_empty(string & s){
    return s == "9" || s == "99" || s == "999" || s == "9999";
  }
  
  bool is_zero_or_empty(string & s ){
    return all_of(all(s), [](char c){return c=='0';});
  }

  bool is_nine_or_empty( string & s ){ 
    return all_of(all(s), [](char c){return c == '9';});
  }

  string add_one( string s ){
    int n = s.size();
    int x = stoi(s)+1;
    string y = to_string(x);
    while( y.size() < n ){
      y.insert(0, "0");
    }
    return y;
  } 

  string expand( string s){
    string ans;
    forall(i,0,5){
      for( auto c : s ){
        ans.pb(c);
      }
    }
    return ans;
  }

  vector<string> parse(string & s){
    string int_part, non_repeat_part, repeat_part;
    int_part = s.substr(0, s.find('.'));
    {
      int left = s.find('.'), right = s.find('(');
      if( left == string::npos ) non_repeat_part = "";
      else non_repeat_part = s.substr(left+1, right-left-1);
    }
    {
      int left = s.find('('), right = s.find(')');
      if( left == string::npos ) repeat_part = "";
      else repeat_part = s.substr(left+1, right-left-1);
      if( is_zero_or_empty( repeat_part ) ) repeat_part="";
      if( is_nine_and_not_empty(repeat_part) ){
        if( is_nine_or_empty( non_repeat_part ) ){
          int_part = add_one(int_part);
          non_repeat_part = "";
          repeat_part = "";
        }else{
          non_repeat_part = add_one(non_repeat_part);
          repeat_part = "";
        }
      }
    }
    debug("int", int_part.size(), int_part);
    debug("non", non_repeat_part.size(), non_repeat_part);
    debug("rep", repeat_part.size(), repeat_part);
    return {int_part, non_repeat_part, repeat_part};
  }

public:
    bool isRationalEqual(string S, string T) {
      auto sv = parse(S);
      auto tv = parse(T);
      int int_dif = stoi(sv[0]) - stoi(tv[0]) ;
      if(  abs(int_dif) > 0 ) return false;
      else{ // int the same
        if( sv[2].empty() ^ tv[2].empty() ) return false;
        if( sv[2].empty() and tv[2].empty() ) return sv[1] == tv[1];
        string A = sv[1]; // non_repreat
        A += expand(sv[2]);
        string B = tv[1];
        B += expand(tv[2]);
        debug("repeat pattern");
        debug(A, A.size());
        debug(B, B.size());
        int n = min(A.size(), B.size());
        forall(i,0,n){
          if( A[i] != B[i] ) return false;
        }
        return true;
      }
    }
};
int main( int argc, char * argv[] ){
  string a,b;
  cin >> a >> b ;
  debug("a =",a, "b =", b);
  Solution sol;
  cout << sol.isRationalEqual(a,b) << '\n';

  return 0;
}
