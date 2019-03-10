#include <vector>
#include <regex>
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
#define forall(i,a,b)               for(int i=a;i<(b);++i)
#define trav(a,x)                   for(auto & a: x)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define sz(c)                       (int)(c).size()
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

auto ____ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  deque<unordered_map<string, int>> registers;
  unordered_map<string,int>::iterator search_reg(string var){
    for(auto itr = registers.rbegin(); itr != registers.rend(); ++itr){
      auto ans_itr = itr->find(var);
      if( ans_itr != itr->end() ){
        return ans_itr;
      }
    }
    return registers.rbegin()->end();
  }

  pair<string,int> eval( istringstream & iss ){
    string token;
    iss>>token;
    if( token == ")" ) return mp(")",-1);
    if( token != "(" ){
      if( isalpha(token[0]) ){
        auto ans_itr = search_reg(token);
        return mp(token, ans_itr==registers.rbegin()->end() ? -1 : ans_itr->second);
      }else 
        return mp(token, stoi(token));
    }
    assert(token == "(" );
    int ans = 0;
    unordered_map<string,int> cur_reg;
    registers.push_back(cur_reg);
    while( iss>>token ){
      debug("token = ", token);
      if( token == "let" ){
        string var;
        do{
          debug("begin l r");
          auto l = eval(iss);
          debug("l=",l.first, l.second);
          auto r = eval(iss);
          debug("r=",r.first, r.second);
          debug("l","r");
          auto tmptmp = vector<pair<string,int>>({l,r});
          printPair_(tmptmp);
          if( r.first == ")" ){
            registers.pop_back();
            return mp("let",l.second);
          }else{
            var = l.first;
            (*registers.rbegin())[var] = r.second;
            debug("assign ", var, r.second);
          }
        }while( true );
      }else if( token == ")" ){
        registers.pop_back();
        return mp("op",ans);
      }else if( token == "mult"){
        int val1 = eval(iss).second;
        int val2 = eval(iss).second;
        debug("mult", "val1 =",val1, "val2 =", val2);
        ans += val1 * val2;
      }else if( token == "add"){
        debug("add");
        int val1 = eval(iss).second;
        int val2 = eval(iss).second;
        debug(val1, val2);
        ans += val1+val2;
      }
    }
    return mp("error",ans);
  }

        

public:
    int evaluate(string expression) {
      regex left_bracket("\\("),  right_bracket("\\)");
      expression = regex_replace(expression, left_bracket, "( ");
      expression = regex_replace(expression, right_bracket, " )");
      debug(expression);
      istringstream iss(expression);

      return eval(iss).second;
    }
};

int main( int argc, char * argv[] ){
//  string str1 = "(add 1 2)";
//  string str1 = "(mult 3 (add 2 3))";
//  string str1 = "(let x 2 (mult x 5))";
//  string str1 = "(let x 3 x 2 x)";
//  string str1 = "(let x 2 (add (let x 3 (let x 4 x)) x))";
  string str1 = "(let a1 3 b2 (add a1 1) b2)";
  Solution sol;
  cout << sol.evaluate(str1) << '\n';

  return 0;
}
