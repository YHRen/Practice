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
      map<char,int> pat;
      map<char,int> run;
      map<char,int> dif;
  bool set_minus(){
    dif.clear();
    if( pat.size() > run.size() ) return false;
    auto itr2 = run.begin();
    auto itr1 = pat.begin();
    for(/**/; itr1!=pat.end() and itr2!=run.end(); /* */){
      if( itr1->first > itr2->first ){
        dif.insert(*itr2);
        itr2++;
      }else if( itr1->first == itr2->first ){
        if( itr1->second == itr2->second ){
          itr1++;
          itr2++;
        }else if(itr1->second < itr2->second){
          dif.insert(mp(itr2->first, itr2->second-itr1->second));
          itr1++;
          itr2++;
        }else{
          return false;
        }
      }else{
        return false;
      }
    }
    if( itr1 != pat.end() ) return false;
    while( itr2!=run.end() ){
      dif.insert(*itr2);
      itr2++;
    }
    
    return true;
  }
    
public:
    string minWindow(string s, string t) {
      vi cnt(128,0);
      for( auto c : t ) cnt[c]+=1;
      int missing=sz(t), l = 0, r = 0, res = INF;
      int start = 0;
      forall(i,0,sz(s)){
        if( cnt[s[i]] > 0 ){ missing--; }
        cnt[s[i]] --;
        while( missing == 0 ){
          if( i-l+1 < res ){ 
            res = i-l+1;
            start = l;
          }
          cnt[s[l]]++;
          if( cnt[s[l]] > 0 ) missing ++;
          l ++;
        }
      }
      if( res == INF ) return "";
      else return s.substr(start,res);
    }
    string minWindow_slow(string s, string t) {
      int n = sz(s); int m = sz(t);
      if( n < m or m == 0) return "";
      for(auto c : t ) pat[c] += 1;
      forall(i,0,m-1){
        run[s[i]]+=1;
      }
      int l = 0;
      int res = INF;
      int min_pos, max_pos;
      for(int r = m-1; r < n; ++ r ){
        run[s[r]]+=1;
        if( set_minus() ){ // true
          debug("true", "r=",r);
          auto itr = dif.find(s[l]);
          printPair_(dif);
          while( itr!=dif.end() and itr->second > 0 ){
            run[s[l]]--;
            itr->second --;
            l ++;
            itr = dif.find(s[l]);
          }
          debug("lr", l, r);
          if( r-l+1 < res ){
            res = r-l+1;
            min_pos = l;
            max_pos = r;
          }
        }
      }
      if( res == INF ) return "";
      else return s.substr(min_pos,max_pos-min_pos+1);
    }
};
int main( int argc, char * argv[] ){
  string s, t; 
  cin >> s >> t;
  Solution sol;
  cout << sol.minWindow(s,t) << endl;
  return 0;
}
