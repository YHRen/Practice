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
  int n;
  vector<string> v;
  vector<string> parse_formula( const string & F ){
    vi breaks;
    breaks.pb(0);
    forall(i,1,sz(F)){
      if( !isdigit(F[i-1]) and isdigit(F[i]) ) breaks.pb(i); // ..H2.. or ...Mg3...
      else if( isupper(F[i]) ) breaks.pb(i); // MgO or H2O
      else if( F[i] == '(' or F[i] == ')' ) breaks.pb(i);
    }
    breaks.pb(sz(F));
    vector<string> res;
    forall(i,1,sz(breaks)){
      res.pb( F.substr(breaks[i-1], breaks[i]-breaks[i-1]) );
    }
    return res;
  }
  map<string,int> rec( int & idx ){
    map<string,int> res;
    while( idx != n and v[idx]!=")"){
      if( v[idx] == "(" ){
        auto tmp = rec( ++idx );
        int factor = (idx!=n and isdigit(v[idx][0])) ? stoi(v[idx++]) : 1;
        for(auto p : tmp ){ res[p.first] += factor*p.second; }
      }else if( isupper(v[idx][0]) ){
        string name = v[idx++];
        int factor = (idx!=n and isdigit(v[idx][0])) ? stoi(v[idx++]) : 1;
        res[name] += factor;
      }else{
        cerr << "ERROR: " << idx << " " << v[idx] << '\n';
      }
    }
    if( idx == n ) return res;
    if( v[idx] == ")" ) idx ++;
    return res;
  }

  public:
    string countOfAtoms(string formula) {
      this->v = parse_formula( formula );
      n = sz(v);
      int idx = 0;
      auto atoms = rec(idx);
      string ans;
      for(auto p:atoms){ ans += p.first + ( p.second == 1 ? "" : to_string(p.second) ); }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  debug(str);
  cout << sol.countOfAtoms( str ) << '\n';
  return 0;
}
