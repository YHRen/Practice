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
typedef unsigned long long        ull;

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

string str;
int n;
vvi dp;

int solve( int l, int r, int k){
  if( l > k or r >= n ) return 0;
  if( dp[l][r] != -1 ) return dp[l][r];
  trace(l,r);
  if(str[l] == str[r]){
    dp[l][r] = 1+solve(l+1,r+1, k);
  }else{
    dp[l][r] = 0;
  }
  return dp[l][r];
}

int main( int argc, char * argv[] ){
  cin >> n; 
  cin >> str;
  int ans = 0;
  dp.resize(n);
  for(auto & v : dp) v.resize(n,-1);
  forall(i,0,n){
    forall(j,i+1,n){
      ans = max(ans, solve(i,j,j-1));
    }
  }
  cout << ans << endl;
  return 0;
}


/**   Poly Hash
ull base = 97;
ull dase = 31;
string str;
int n;
vector<ull> B;
vector<ull> D;
bool solve(int k){
  unordered_map<ull, int> been;
  unordered_map<ull, int> deen;
  ull bun = str[0]-'a'+1;
  ull dun = str[0]-'a'+1;
  forall(i,1,k){
    bun *= base;
    dun *= dase;
    bun += str[i]-'a'+1;
    dun += str[i]-'a'+1;
    dun %= INF;
    bun %= INF;
  }
  been[bun] = k-1;
  deen[dun] = k-1;
  forall(i,k,n){
    bun *= base;
    bun += str[i]-'a'+1;
    bun %= INF;
    bun = bun + INF - (B[k]*(str[i-k]-'a'+1)%INF);
    bun %= INF;

    dun *= dase;
    dun += str[i]-'a'+1;
    dun %= INF;
    dun = dun + INF - (D[k]*(str[i-k]-'a'+1)%INF);
    dun %= INF;

    debug("i=", i, dun, bun);
    if( been.find(bun) != been.end() and deen.find(dun) != deen.end() ){
      if ( been[bun] + k <= i and deen[dun]+k <= i and been[bun] == deen[dun] ){
        trace("been ", been[bun], deen[dun]);
        return true;
      }
    }else {
      been[bun] = i;
      deen[dun] = i;
    }
    debug("i=",i,"code=",bun);
  }
  return false;
}

int main( int argc, char * argv[] ){
  cin >> n; 
  cin >> str;
  B.resize(n/2+1,1);
  forall(i,1,sz(B)) B[i] = B[i-1]*base%INF;
  D.resize(n/2+1,1);
  forall(i,1,sz(D)) D[i] = D[i-1]*dase%INF;

  int lo = 1, hi = n/2;
  int ans = 0;
  while( lo <= hi ){
    int mid = lo + (hi-lo)/2;
    debug("mid=",mid);
    if( solve(mid) ){ 
      debug("yes");
      lo = mid+1;
      ans = max(ans, mid);
    }else{
      debug("no");
      hi = mid-1;
    }
  }
  cout << ans << endl;
  return 0;
}

*/
