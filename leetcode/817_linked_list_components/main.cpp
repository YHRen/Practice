// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
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
/******* Actual Code Starts Here *********/
/**
 * Definition for singly-linked list.
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  vvi G;
  int find_n( ListNode * node, int depth ){
    if( node->next == NULL ) return depth;
    else return find_n( node->next, depth+1);
  }

  void connect_graph( ListNode * node ){
    if( node->next != NULL ){
      int u = node->val, v = node->next->val;
      G[u].pb(v);
      G[v].pb(u);
      connect_graph( node->next );
    }
  }

public:
    int numComponents(ListNode* head, vector<int>& query) {
      int n = find_n(head,1);
      if( n == 1 ) return n;
      G.resize(n);
      debug("found n = ", n );
      connect_graph(head);
      for( auto r : G ){
        print_(r);
      }
      int ans = 0;
      vi is_visited(n, false);
      vi is_blocked(n, true );
      for( auto x : query ) is_blocked[x] = false;

      for(auto x : query ){
        if( is_visited[x] ) continue;
        is_visited[x] = true;
        ans += 1;
        queue<int> Q;
        Q.push(x);
        while(!Q.empty()){
          auto u = Q.front(); Q.pop();
          for( auto v : G[u] ){
            if( !is_visited[v] && !is_blocked[v] ){
              is_visited[v] = true;
              Q.push(v);
            }
          }
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  vi list = {0,1,2,3,4};
  vi query={0,3,1,4};
  ListNode *head = new ListNode(0);
  ListNode *tmp = head;
  forall(i,1,list.size()){
    tmp->next = new ListNode(list[i]);
    tmp = tmp->next;
  }
  Solution sol;
  cout << sol.numComponents( head, query ) << '\n';

  return 0;
}
