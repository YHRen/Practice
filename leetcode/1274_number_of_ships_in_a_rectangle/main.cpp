#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define INF (int)1000000007
#define EPS 1e-9
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define forall(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define in(a, b) ((b).find(a) != (b).end())
#define sz(c) (int)(c).size()
#define input(a) \
  for (auto& x : a) cin >> x;

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;

#ifdef DEBUG
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define debug(args...) \
  {                    \
    dbg, args;         \
    clog << endl;      \
  }
#define print_(a)                     \
  for (auto& x : a) clog << x << ' '; \
  clog << '\n';
#define printPair_(a)                                                        \
  for (auto& x : a) clog << '(' << x.first << ',' << x.second << ')' << ' '; \
  clog << '\n';
#else
#define trace(...)
#define debug(args...)
#define print_(a)
#define printPair_(a)
#endif

struct debugger {
  template <typename T>
  debugger& operator,(const T& x) {
    clog << x << " ";
    return *this;
  }
} dbg;

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << ": " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " | ";
  __f(comma + 1, args...);
}

auto ____ = []() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  return nullptr;
}();
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 */
class Sea {
 public:
  vi x, y;
  int n;
  bool hasShips(vector<int> topRight, vector<int> bottomLeft) {
    forall(i, 0, n) {
      if (x[i] >= bottomLeft[0] and x[i] <= topRight[0] and
          y[i] >= bottomLeft[1] and y[i] <= topRight[1])
        return true;
    }
    return false;
  }
};

class Solution {
 public:
  int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
    debug(bottomLeft[0], bottomLeft[1], topRight[0], topRight[1]);
    int ans = 0;
    if (topRight[0] == bottomLeft[0] and topRight[1] == bottomLeft[1]) {
      ans = sea.hasShips(topRight, bottomLeft);
    } else if (topRight[0] == bottomLeft[0]) {
      int a = topRight[1], b = bottomLeft[1];
      int c = (a + b) / 2, d = c + 1;
      if (c == b) {
        ans += sea.hasShips({bottomLeft[0], b}, {bottomLeft[0], c});
      } else if (c > b and
                 sea.hasShips({bottomLeft[0], c}, {bottomLeft[0], b})) {
        ans += countShips(sea, {bottomLeft[0], c}, {bottomLeft[0], b});
      }
      if (a == d) {
        ans += sea.hasShips({bottomLeft[0], a}, {bottomLeft[0], d});
      } else if (a > d and
                 sea.hasShips({bottomLeft[0], a}, {bottomLeft[0], d})) {
        ans += countShips(sea, {bottomLeft[0], a}, {bottomLeft[0], d});
      }
    } else if (topRight[1] == bottomLeft[1]) {
      debug("topRight[1] == bottomLeft[1]", topRight[1]);
      int a = topRight[0], b = bottomLeft[0];
      int c = (a + b) / 2, d = c + 1;
      trace(c,d, b, a);
      if (c == b) {
        //ans += sea.hasShips({bottomLeft[1], b}, {bottomLeft[1], c});
        trace(b, bottomLeft[1], c, bottomLeft[1]);
        ans += sea.hasShips({b, bottomLeft[1]}, {c, bottomLeft[1]});
      } else if (c > b and
                 sea.hasShips({c, bottomLeft[1]}, {b, bottomLeft[1]})) {
        ans += countShips(sea, {c, bottomLeft[1]}, {b, bottomLeft[1]});
      }
      if (a == d) {
        ans += sea.hasShips({a, bottomLeft[1]}, {d, bottomLeft[1]});
      } else if (a > d and
                 sea.hasShips({a, bottomLeft[1]}, {d, bottomLeft[1]})) {
        ans += countShips(sea, {a, bottomLeft[1]}, {d, bottomLeft[1]});
      }
    } else {  //
      int a = (topRight[0] + bottomLeft[0]) / 2;
      int b = (topRight[1] + bottomLeft[1]) / 2;
      debug(" empty ", a, b, bottomLeft[0], bottomLeft[1]);
      // bot left
      if (a == bottomLeft[0] and b == bottomLeft[1]) {
        ans += sea.hasShips({a, b}, {a, b});
      } else if (sea.hasShips({a, b}, bottomLeft)) {
        debug("bot left", a, b, bottomLeft[0], bottomLeft[1]);
        ans += countShips(sea, {a, b}, bottomLeft);
      }
      // upper left
      int lx = bottomLeft[0], ly = b + 1;
      if (sea.hasShips({a, topRight[1]}, {bottomLeft[0], ly})) {
        debug("upper left");
        ans += countShips(sea, {a, topRight[1]}, {bottomLeft[0], ly});
      }

      // lower right
      lx = a + 1, ly = b;
      if (sea.hasShips({topRight[0], b}, {a + 1, bottomLeft[1]})) {
        debug("lower right");
        ans += countShips(sea, {topRight[0], b}, {a + 1, bottomLeft[1]});
      }

      // upper right
      lx = a + 1, ly = b + 1;
      if (vi({lx, ly}) == topRight) {
        debug("upper right");
        ans += countShips(sea, {lx, ly}, {lx, ly});
      } else if (sea.hasShips(topRight, {lx, ly})) {
        ans += countShips(sea, topRight, {lx, ly});
      }
    }
    debug(bottomLeft[0], bottomLeft[1], topRight[0], topRight[1],
          "ans = ", ans);
    return ans;
  }
};
int main(int argc, char* argv[]) {
  int n;
  cin >> n;
  vi v(n);
  input(v);
  vi u(n);
  input(u);
  Sea sea;
  sea.n = n;
  sea.x = v;
  sea.y = u;
  Solution sol;
  vi a(2);
  vi b(2);
  input(a);
  input(b);
  cout << sol.countShips(sea, a, b) << endl;

  return 0;
}
