#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
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
  unordered_set<string> exact_dict;
  unordered_map<string, vi> capital_map;
  unordered_map<string, vi> fluffy_map;
  string to_lower( const string & s ){
    string ans = s;
    transform(all(s), ans.begin(), ::tolower);
    return ans;
  }
  string to_fluffy( const string & s ){
    // s is lowered
    string ans;
    for(auto c : s ){
      if( c == 'a' || c == 'e' || c == 'i' || c=='o' || c == 'u' ){
        ans.pb('?');
      }else{
        ans.pb(c);
      }
    }
    return ans;
  }
        
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
      int n = wordlist.size();
      for( auto s : wordlist ) exact_dict.insert(s);
      forall(i,0,n){
        const auto & s = wordlist[i];
        auto tmp = to_lower(s);
        auto itr = capital_map.find(tmp);
        if( itr == capital_map.end() ){
          capital_map[tmp].pb(i);
        }else{
          itr->second.pb(i);
        }

        tmp = to_fluffy(tmp);
        itr = fluffy_map.find(tmp);
        if( itr == fluffy_map.end() ){
          fluffy_map[tmp].pb(i);
        }else{
          itr->second.pb(i);
        }
      }

      vector<string> ans;
      for( const auto & q : queries ){
        {
          auto itr = exact_dict.find(q);
          if( itr != exact_dict.end() ){
            ans.pb( *itr );
            continue;
          }
        }
        auto tmp = to_lower(q);
        auto itr = capital_map.find(tmp);
        if( itr != capital_map.end() ){
          ans.pb( wordlist[ itr->second[0] ] );
          continue;
        }

        tmp = to_fluffy(tmp);
        itr = fluffy_map.find(tmp);
        if( itr != fluffy_map.end() ){
          ans.pb( wordlist[ itr->second[0] ] );
          continue;
        }
        ans.pb("");
      }


      return ans;
        
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
