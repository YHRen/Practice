#include <vector>
#include <random>
#include <list>
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

class Skiplist {
  struct Node{
    int val;
    int cnt;
    Node * nxt;
    Node * dwn;
    Node() : val(-1), nxt(nullptr), dwn(nullptr) {}
    Node(int x) : val(x), nxt(nullptr), dwn(nullptr), cnt(1) {}
  };

  mt19937 rng;
  const int LEVEL;
  vector<Node*> data;
  vector<Node*> ans;
  uniform_int_distribution<int> flip;
  public:
    Skiplist(int rndseed=0) : LEVEL(16) , rng( rndseed ) {
      data.resize(LEVEL);
      forall(i,0,LEVEL) data[i] = new Node();
      forall(i,0,LEVEL-1){ data[i]->dwn = data[i+1];}
      flip = uniform_int_distribution<int>{0,1};
      ans.resize(16);
    }
    void _del( Node * node ){
      if( node->nxt ) _del(node->nxt);
      delete node;
    }
    ~Skiplist(){
      auto cur = data[0];
      while(cur){
        auto tmp = cur->dwn;
        _del(cur);
        cur = tmp;
      }
    }

    void query( int target ){
      auto cur = data[0];
      for(int lev = 0; lev != LEVEL; ++lev ){
        while( cur->nxt != nullptr and cur->nxt->val < target ){
          cur = cur->nxt;
        }
        ans[lev] = cur;
        cur = cur->dwn;
      }
    }

    bool search(int target) {
      query( target );
      //return (*ans.back())->nxt != nullptr and (*ans.back())->nxt->val == target;
      return (ans.back())->nxt != nullptr and (ans.back())->nxt->val == target;
    }

    Node * add_node( Node * & node, int num ){
      debug("add node ", node, num);
      if( node->nxt == nullptr ){
        node->nxt = new Node(num);
      }else if( node->nxt->val == num ){
        node->nxt->cnt ++;
      }else{
        auto tmp = node->nxt;
        node->nxt = new Node(num);
        node->nxt->nxt = tmp;
      }
      return node->nxt;
    }

    void add(int num) {
      query(num);
      auto cur = add_node( ans.back(), num ); // add at the last layer
      for(auto itr = ans.rbegin()+1; itr != ans.rend(); ++itr ){
        if( flip(rng) ){
          auto tmp = add_node( *itr, num );
          tmp->dwn = cur;
          cur = tmp;
        }else{
          return;
        }
      }
    }

    Node * del_node( Node * & node ){
      auto tmp = node->nxt->nxt;
      if( node->nxt->cnt == 1 ){
        delete node->nxt;
        node->nxt = tmp;
      }else{
        node->nxt->cnt --;
      }
      return tmp;
    }

    
    bool erase(int num) {
      query(num);
      if ((ans.back())->nxt == nullptr or (ans.back())->nxt->val != num)
        return false;  // not here
      for(auto itr = ans.rbegin(); itr != ans.rend(); ++itr ){
        auto cur = *itr;
        if( (cur)->nxt == nullptr or (cur)->nxt->val < num ) break;
        del_node(cur);
      }
      return true;
    }

    void print(){
      forall(lev,0,LEVEL){
        auto cur = data[lev];
        clog << "L " << lev << ": ";
        while( cur != nullptr ){
          clog << '[' << cur->val << ',' << cur->cnt << ']' << ' ';
          cur = cur->nxt;
        }
        clog << '\n';
      }
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

int main( int argc, char * argv[] ){
  Skiplist slst = Skiplist();
  debug("add 1");
  slst.add(1);
  slst.print();

  debug("add 2");
  slst.add(2);
  slst.print();

  debug("add 3");
  slst.add(3);
  slst.print();

  cout << "search 0: " << slst.search(0) << '\n';
  debug("add 5");
  slst.add(5);
  slst.print();

  debug("add 3");
  slst.add(3);
  slst.print();

  debug("==============================");
  cout << "search 3: " << slst.search(3) << '\n';
  debug("search 3 : ", slst.search(3));
  cout << "search 1: " << slst.search(1) << '\n';
  debug("search 1 : ", slst.search(1));
  cout << "erase 0: " << slst.erase(0) << '\n';
  debug("erase 0 : ", slst.erase(0));
  slst.print();

  cout << "erase 4: " << slst.erase(4) << '\n';
  debug("erase 4 : ", slst.erase(4));
  slst.print();

  cout << "erase 2: " << slst.erase(2) << '\n';
  debug("erase 2 : ", slst.erase(2));
  slst.print();
  
  slst.print();

  cout << "search 2: " << slst.search(2) << '\n';

  cout << "SUCESS\n";


  return 0;
}
