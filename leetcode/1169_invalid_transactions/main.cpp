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

struct Record{
  int time, amount;
  string name, city;
  string to_str() const{
    return this->name + ','+ to_string(this->time) + 
      ',' + to_string(this->amount) + ',' + this->city;
  }

};

class Solution {
  Record parse_record( const string & transaction ){
    istringstream iss(transaction);
    Record rec;
    string tmp;
    getline(iss, tmp,','); rec.name   = tmp;
    getline(iss, tmp,','); rec.time   = stoi(tmp);
    getline(iss, tmp,','); rec.amount = stoi(tmp);
    getline(iss, tmp,','); rec.city   = tmp;
    return rec;
  }

  bool is_invalid( const Record & lhs, const Record & rhs ){
    if( abs(lhs.time-rhs.time) <= 60 and lhs.city != rhs.city) return true;
    else return false;
  }

public:
    vector<string> invalidTransactions(vector<string>& transactions) {
      vector<Record> recs;
      for(auto & tran : transactions) recs.pb(parse_record(tran));
      vector<string> ans;
      unordered_map<string, vector<Record>> dic;
      for(auto & rec : recs ) dic[rec.name].pb(rec);
      for(auto & ptr : dic){
        sort(all(ptr.second), [](const Record & lhs, const Record & rhs){
            if( lhs.time < rhs.time ) return true;
            else return false;});
        auto & v = ptr.second;
        int  n = sz(v);
        vi msk(n,0);
        forall(i,0,n){
          //if( msk[i] ) continue;
          if( v[i].amount > 1000 ) msk[i] = 1;
          forall(j,i+1,n){
            if( is_invalid(v[i], v[j]) ){
              msk[i] = msk[j] = 1;
              //continue;
            }
          }
        }
        forall(i,0,n) if( msk[i] ) ans.pb(v[i].to_str());
      }
      return ans;
    }
        
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
