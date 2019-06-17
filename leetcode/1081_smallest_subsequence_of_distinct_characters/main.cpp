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
  public:
    string smallestSubsequence(string text) {
      vi cnt(128,0);
      vi  is_visited(128,0);
      for(auto c : text) cnt[c]++;
      deque<char> Q;
      for(auto c : text){
        if( Q.empty() or Q.back() < c ){
          if( !is_visited[c] ){
            is_visited[c] = 1;
            Q.push_back(c);
          }
        }else if(Q.back() > c and !is_visited[c] ){
          while( !Q.empty() and cnt[Q.back()] > 0 and Q.back() > c ){
            is_visited[Q.back()] = 0;
            Q.pop_back();
          }
          is_visited[c] = 1;
          Q.push_back(c);
        }
        cnt[c]--;
      }
      return string(all(Q));
    }
    string smallestSubsequence_slow(string text) {
      vvi cnt(26);
      unordered_set<char> unq;
      int n = sz(text);
      forall(i,0,n){
        cnt[text[i]-'a'].pb(i);
        unq.insert(text[i]);
      }
      int K = sz(unq);
      string ans;
      int idx = 0;
      while( K-- ){
        debug("idx",idx);
        int selected_char = -1;
        for(int i = 0; i < 26; ++i ){
          if( cnt[i].empty() ) continue;
          debug("test",i);
          bool flag=  true;
          auto itr = lower_bound(all(cnt[i]), idx);
          debug("(itr=",*itr);
          for(int j = i+1; j < 26; ++j ){
            if( cnt[j].empty()) continue;
            if( cnt[j].back() < *itr ) {
              flag = false;
              break;
            }
          }
          if( flag ){ 
            debug("select i",i);
            selected_char = i;
            idx = *itr;
            break;
          }
        }

        debug("selected_char = ", selected_char, char('a'+selected_char),"idx=",idx);
        ans.pb(char('a'+selected_char));
        cnt[selected_char].clear();
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  string str;
  cin >> str;
  Solution sol;
  cout << sol.smallestSubsequence(str)<< endl;
  return 0;
}
