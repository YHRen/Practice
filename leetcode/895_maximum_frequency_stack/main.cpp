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
typedef pair<ii, int> iii;
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
class FreqStack {
  unordered_map<int, int> freq;
  unordered_map<int, stack<int> > group;
  int max_freq;
public:
    FreqStack() {
      freq.clear();
      group.clear();
      max_freq = 0;
    }
    
    void push(int x) {
      auto itr = freq.find(x);
      if( itr == freq.end() ){
        auto p = freq.insert(mp(x,1));
        itr = p.first;
      }else{
        itr ->second += 1;
      }
      if( itr->second > max_freq ){
        max_freq = itr->second;
        group[max_freq].push( x ) ;
      }else{
        group[itr->second].push(x);
      }
    }
    
    int pop() {
      auto & itr = group[max_freq];
      int ans = itr.top();
      itr.pop();
      if( itr.empty() ){
        group.erase(max_freq);
        max_freq --;
      }
      freq[ans] -= 1;
      if( freq[ans] == 0 ) freq.erase(ans);
      return ans;
    }
};

class FreqStack2{
  // oh boy... just implemented a prioirty_queue with increase_key()
  unordered_map<int,int> dict;// val to idx
  vvi idx_trace;
  vector<iii> v;
  int cnt;
  int n;
  public:
  FreqStack2() {
      v.clear();
      dict.clear();
      idx_trace.clear();
      cnt = 0;
      v.pb(mp(mp(-INF,-INF),-INF));
      idx_trace.pb({});
    }

    void perco_up( int idx ){
      if( idx == 1 ) return;
      int p = idx/2;
      if( v[p].first < v[idx].first ){
        dict[v[p].second] = idx;
        dict[v[idx].second] = p;
        swap(v[p], v[idx]);
        swap(idx_trace[p], idx_trace[idx]);
        perco_up( p );
      }
    }

    void perco_down(int idx){
      int n = v.size();
      if( idx > n)  return;
      int l = idx*2, r = idx*2+1;
      if( l < n and (r >= n  or v[l].first > v[r].first) ){
        perco_up( l );
        perco_down(l);
      }else if( r < n and ( l >= n or v[r].first > v[l].first) ){
        perco_up(r);
        perco_down(r);
      }
    }

    void push(int x) {
      auto itr = dict.find(x);
      if( itr != dict.end() ){
        int idx = itr->second;
        v[idx].first.first += 1;
        v[idx].first.second = cnt;
        idx_trace[idx].pb(cnt);
        cnt ++;
        perco_up(idx);
      }else{
        int idx = v.size();
        v.pb( mp( mp(1, cnt), x ) );
        idx_trace.pb( {cnt} );
        cnt ++;
        dict[x] = idx;
        perco_up(idx);
      }
    }

    int pop() {
      int ans = v[1].second;
      v[1].first.first -= 1;
      idx_trace[1].pop_back();
      v[1].first.second = idx_trace[1].empty() ? -1 : *idx_trace[1].rbegin();
      perco_down(1);
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
