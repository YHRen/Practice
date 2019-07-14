#include <vector>
#include <random>
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
#include <complex>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF              (int)1000000007
#define EPS              1e-9
#define pb               push_back
#define mp               make_pair
#define all(c)           c.begin(), c.end()
#define forall(i,a,b)    for(int i=a;i<(b);++i)
#define trav(a,x)        for(auto & a: x)
#define in(a,b)          ((b).find(a) != (b).end())
#define sz(c)            (int)(c).size()
#define input(a)         for(auto & x : a) cin >> x;

using namespace std;

typedef vector<int>      vi;
typedef pair<int,int>    ii;
typedef vector<vi>       vvi;
typedef vector<ii>       vii;
typedef long long        ll;

#ifdef DEBUG
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
      unordered_map<string, int> dic;
      for(auto & s : req_skills) dic[s] = sz(dic);
      int n = sz(people), m = sz(req_skills);
      debug("n=",n,"m=",m);
      vi sk(n,0);
      forall(i,0,n){
        for(auto & x : people[i]){
          if( dic.count(x) )
            sk[i] |= (1<<dic[x]);
        }
      }
      unordered_map<int, vi> req;
      req[0] = {};
      forall(i,0,n){
        unordered_map<int, vi> to_add;
        debug("i=",i);
        for(auto & p : req){
          if( auto itr = req.find(p.first | sk[i]); itr == req.end() 
              or sz(itr->second) > sz(p.second)+1 ){
            vi tmp = p.second;
            tmp.pb(i);
            int nxt = p.first|sk[i];
            if( auto itrnxt = to_add.find(nxt); itrnxt == to_add.end() or 
                itrnxt->second.size() > tmp.size() ){
              to_add[nxt] = tmp;
            }
          }
        }
        debug("adding");
        for(auto & p : to_add){
          debug("add ", p.first );
          print_(p.second);
          req[p.first]=p.second;
        }
      }
      return req[(1<<m)-1];
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vector<string> req(n); input(req);
  int m; cin >> m;
  print_(req);
  debug("n,m",n,m);
  vector<vector<string>> people(m);
  for(auto & v : people){
    int w; cin >> w;
    v.resize(w);
    input(v);
    print_(v);
  }
  Solution sol;
  auto res = sol.smallestSufficientTeam(req, people);
  print_(res);
  return 0;
}
