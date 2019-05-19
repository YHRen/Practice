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
typedef unsigned long long ull;

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

struct SuffixArray {
  vi sa, lcp;
  SuffixArray(string& s, int lim=256) { // or basic_string<int>
    int n = sz(s) + 1, k = 0, a, b;
    vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
    sa = lcp = y, iota(all(sa), 0);
    for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
      p = j, iota(all(y), n - j);
      forall(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
      fill(all(ws), 0);
      forall(i,0,n) ws[x[i]]++;
      forall(i,1,lim) ws[i] += ws[i - 1];
      for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
      swap(x, y), p = 1, x[sa[0]] = 0;
      forall(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
        (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
    }
    forall(i,1,n) rank[sa[i]] = i;
    for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
      for (k && k--, j = sa[rank[i] - 1];
          s[i + k] == s[j + k]; k++);
  }
};
const ll B = 5600748293801;
class Solution {
  string str;
  int n;
  
  
  int D( int L ){
    // no need for modular
    ull run = 0, lpow=1;
    unordered_set<ull> dic;
    forall(i,0,L-1) {
      lpow = lpow*26;
    }
    forall(i,0,L){
      run = (run*26 + (str[i]-'a'));
    }
    dic.insert(run);
    forall(i,L,n){
      run = (run - lpow*(str[i-L]-'a'))*26+(str[i]-'a');
      if( dic.find(run) != dic.end() ) return i-L+1;
      dic.insert(run);
    }
    return -1;
  }

  int C( int L ){
    ll run = 0;
    unordered_set<ll> dic;
    ll lpow = 1;
    forall(i,0,L-1) {
      lpow = lpow*26%B;
    }
    forall(i,0,L){
      run = (run*26%B + (str[i]-'a'))%B;
    }
    dic.insert(run);
    forall(i,L,n){
      run = (run - lpow*(str[i-L]-'a')%B+B)*26%B+(str[i]-'a');
      run %= B;
      if( dic.find(run) != dic.end() ) return i-L+1;
      dic.insert(run);
    }
    return -1;
  }


public:
    string longestDupSubstring(string S) {
      // suffix array
      SuffixArray sa(S);
      int res = 0, start=-1;
      forall(i,0,sz(sa.lcp)){
        if( res < sa.lcp[i] ){
          res = sa.lcp[i];
          start = sa.sa[i];
        }
      }
      if(res==0) return "";
      else return S.substr(start, res);
    }
    string longestDupSubstring_rabin_karp(string S) {
      n = sz(S);
      if( n==1 ) return "";
      swap(str, S);

      int l = 0, r = n, mid, res=-1, len=0, tmp;
      while( r-l>1 ){
        mid = (l+r)/2;
        debug("testing ", mid);
        if( (tmp=D(mid)) != -1 ){
          debug("success");
          l = mid;
          res = tmp;
          len = mid;
          debug("starting at",res,"has length",len);
        }else{
          debug("failure");
          r = mid;
        }
      }
      if(len==0){
        return "";
      }else{
        return str.substr(res,len);
      }
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  cout << sol.longestDupSubstring(str) << endl;
  return 0;
}
