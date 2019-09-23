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
  int n,m;
  vvi G;
  vvi grpitems;
  vi  group;
  int iso2grp(int x){ return x+n; }
  int grp2iso(int x){ return x-n; }
  vi Kahn( int group_id  ){
    const vi & items = grpitems[group_id];
    if( items.empty() ) return {};
    unordered_map<int, int> deg;
    for(auto x : items) deg[x] = 0;
    for(auto x : items){
      debug("x=",x);
      for(auto y : G[x]){
        debug("y=",y, group[y]);
        if( group[y] == group_id ){
          deg[y] ++;
        }
      }
    }
    queue<int> Q;
    for(auto & p : deg){
      debug(p.first, p.second);
      if( p.second == 0 ){
        Q.push(p.first);
      }
    }
    debug("Q",Q.empty(), Q.front());
    vi ans ;
    while( !Q.empty() ){
      int x = Q.front(); Q.pop();
      ans.pb(x);
      for(auto y : G[x]){
        if( group[y] == group_id ){
          deg[y]--;
          if( deg[y] == 0 ) Q.push(y);
        }
      }
    }
    if( ans.size() == items.size() ) return ans;
    else return {-1};
  }

  public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
      this->n = n;
      this->m = m;
      this->grpitems.resize(m+1);
      this->group = group;
      forall(i,0,n)
      if(auto g = group[i]; g == -1 ) grpitems[m].pb(i); 
      else  grpitems[g].pb(i);
      
      G.resize(n);
      forall(i,0,n){
        for(auto x : beforeItems[i] ){
          G[x].pb(i);
        }
      }

      forall(i,0,n){ sort(all(G[i])); }

      debug("print graph");
      forall(i,0,n){
        debug("i=",i);
        print_(G[i]);
      }

      forall(g,0,m){
        if( grpitems[g].empty() ) continue;
        debug("group ", g);
        print_(grpitems[g]);
        auto tmp = Kahn(g);
        debug("sorted ");
        print_(tmp);
        if( tmp[0] == -1 ) return {};
        grpitems[g] = tmp;
      }

      // sorted groups

      unordered_map<int, vi> H; // group DAG
      forall(i,0,m) H[i]={};
      for(auto x : grpitems[m]) H[iso2grp(x)]={};
      forall(i,0,m){ // for each group;
        debug("gourp", i);
        for(auto x : grpitems[i]){ // for each elm in grp [i]
          if( beforeItems[x].empty() ) continue;
          debug("item x",x);
          for(auto y : beforeItems[x]){
            debug("y=",y);
            if(auto grp=group[y]; grp != -1 and grp != i ){
              debug("outside my group", y, grp);
              H[grp].pb(i); // may have duplicates
            }else if( grp == -1 ){
              debug("ouside isolated ", y, grp);
              H[iso2grp(y)].pb(i);
            }
          }
        }
      }
      for(auto x : grpitems[m]){// for each isolated elm
        debug("isolated x",x);
        for(auto y : beforeItems[x]){
          debug("y=",y);
          if( auto grp = group[y]; grp == -1 ){
            debug("grp=",grp, "isolated",y);
            H[iso2grp(x)].pb(iso2grp(x));
          }else{
            debug("grp=",grp);
            H[grp].pb(iso2grp(x));
          }
        }
      }
      // remove duplicated nodes
      for(auto & v : H ){
        sort(all(v.second));
        v.second.erase( unique(all(v.second)), v.second.end());
      }

      debug("print H");
      for(auto & p : H ){
        debug(p.first, ":");
        print_(p.second);
      }

      unordered_map<int,int> deg;
      for(auto & p : H ) deg[p.first]=0;
      queue<int> Q;
      for(auto & p : H ){
        for(auto y : p.second){
          deg[y] ++;
        }
      }
      for(auto & p : deg){
        if( p.second == 0 ){
          Q.push(p.first);
        }
      }
      vi grp_ord;
      while( !Q.empty() ){
        int x = Q.front(); Q.pop();
        grp_ord.pb(x);
        for(auto y : H[x]){
          deg[y] --;
          if( deg[y] == 0 ) Q.push(y);
        }
      }
      if( grp_ord.size() != H.size() ) return {};
      debug("group order=");
      print_(grp_ord);

      vi ans;
      for(auto gid : grp_ord){
        if( gid >= n ){ // isolated nodes
          ans.pb(grp2iso(gid));
        }else{
          for(auto x : grpitems[gid]){
            ans.pb(x);
          }
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m; 
  vi v(n); input(v);
  cin.ignore(256,'\n');
  vvi before(n);
  forall(i,0,n){
    string tmp;
    getline(cin, tmp, '\n');
    istringstream iss(tmp);
    int token;
    while(iss>>token){
      before[i].pb(token);
    }
  }

  Solution sol;
  auto ans = sol.sortItems(n, m, v, before) ;
  print_(ans);

  return 0;
}
