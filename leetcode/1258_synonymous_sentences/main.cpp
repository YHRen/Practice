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
#define trace(...)       __f(#__VA_ARGS__, __VA_ARGS__)
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define trace(...)       
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << ": " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " | ";
    __f(comma + 1, args...);
}

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
};
class Solution {

  unordered_map<string, int> s2idx;
  unordered_map<int, string> idx2s;
  unordered_map<int, int> idx2meaning;
  unordered_map<int, vi> meaning2idx;
  int n;
  vector<string> token;
  vector<string> ans;
  vector<string> cur;
  void solve(int idx){
    if( idx == n ){
      string tmp = "";
      forall(i,0,n){
        tmp+=cur[i];
        if( i != n-1 ) tmp+=" ";
      }
      ans.pb(tmp);
      return;
    }

    string cur_token = token[idx];
    trace(cur_token, idx, token[idx], sz(token));
    if( s2idx.find(cur_token) == s2idx.end() ){ 
      cur.pb(cur_token);
      solve(idx+1);
      cur.pop_back();
      return;
    }else{
      int meanning = idx2meaning[ s2idx[ cur_token] ];
      for(auto t : meaning2idx[meanning] ){
        cur.pb(idx2s[t]);
        solve(idx+1);
        cur.pop_back();
      }
      return;
    }
  }
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
      forall(i,0,sz(synonyms)){
        if( s2idx.find(synonyms[i][0]) == s2idx.end() ) s2idx[synonyms[i][0]] = sz(s2idx);
        if( s2idx.find(synonyms[i][1]) == s2idx.end() ) s2idx[synonyms[i][1]] = sz(s2idx);
      }
      for(auto & p : s2idx){
        idx2s[p.second] = p.first;
      }

      trace( sz(s2idx) );
      UF uf(sz(s2idx));
      forall(i,0,sz(synonyms)){
        int x = s2idx[synonyms[i][0]], y = s2idx[synonyms[i][1]];
        uf.join(x,y);
      }

      forall(i,0,sz(s2idx)){
        int cid = uf.find(i);
        idx2meaning[i] = cid;
        meaning2idx[cid].pb(i);
      }

      for(auto & v : meaning2idx){
        sort( all(v.second), [&](int x, int y){ return idx2s[x] < idx2s[y]; });
      }

      {
        istringstream iss(text);
        string tmp;
        while( iss>>tmp ){
          this->token.pb(tmp);
        }
      }

      print_(token);
      this->n = sz(token);
      solve(0);
      return ans;
    }
};
int main( int argc, char * argv[] ){
  vector<vector<string>> syn = {{"happy","joy"},{"sad","sorrow"},{"joy","cheerful"}};
  string text = "I am happy today but was sad yesterday";
  Solution sol;
  auto ans = sol.generateSentences(syn, text);
  print_(ans);
  return 0;
}
