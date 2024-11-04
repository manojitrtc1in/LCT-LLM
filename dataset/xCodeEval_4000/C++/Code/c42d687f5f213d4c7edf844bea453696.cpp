#include <iostream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <functional>
#include <numeric>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <unordered_map>
#include <random>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

const int INFL = (int)1e9;
const ll INFLL = (ll)1e18;
const double INFD = numeric_limits<double>::infinity();
const double PI = 3.14159265358979323846;
#define Loop(i, n) for(int i = 0; i < (int)n; i++)
#define Loopll(i, n) for(ll i = 0; i < (ll)n; i++)
#define Loop1(i, n) for(int i = 1; i <= (int)n; i++)
#define Loopll1(i, n) for(ll i = 1; i <= (ll)n; i++)
#define Loopr(i, n) for(int i = (int)n - 1; i >= 0; i--)
#define Looprll(i, n) for(ll i = (ll)n - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = (int)n; i >= 1; i--)
#define Looprll1(i, n) for(ll i = (ll)n; i >= 1; i--)
#define Loopitr(itr, container) for(auto itr = container.begin(); itr != container.end(); itr++)
#define printv(vector) Loop(i, vector.size()) { cout << vector[i] << " "; } cout << endl;
#define rnd(d) (ll)((double)d + (d >= 0 ? 0.5 : -0.5))
#define floorsqrt(x) ((ll)sqrt((double)x) + ((ll)sqrt((double)x) * (ll)sqrt((double)x) <= (ll)x ? 0 : -1))
#define ceilsqrt(x) ((ll)sqrt((double)x) + ((ll)x <= (ll)sqrt((double)x) * (ll)sqrt((double)x) ? 0 : 1))
#define ceildiv(a, b) ((ll)a / (ll)b + ((ll)a % (ll)b == 0 ? 0 : 1))
#define bitmanip(m,val) static_cast<bitset<(int)m>>(val)



const ll MOD = (ll)1e9 + 7;

class Extended_Euclid {
private:
  ll m, n;
  vvll mx_multiply(vvll mx1, vvll mx2) {
    vvll ret(mx1.size(), vll(mx2[0].size(), 0));
    Loop(i, mx1.size()) {
      Loop(j, mx1[0].size()) {
        Loop(k, mx2[0].size()) {
          ret[i][j] += mx1[i][k] * mx2[k][j];
        }
      }
    }
    return ret;
  }
  bool adjust_into_range(ll m, ll n, ll *x, ll *y, Pll x_range = { LLONG_MIN, LLONG_MAX }, Pll y_range = { LLONG_MIN, LLONG_MAX }) {
    if ((*x) < x_range.first && (*y) < y_range.first) return false;
    if ((*x) > x_range.second && (*y) > y_range.second) return false;
    ll d;
    if ((*y) > y_range.second) {
      d = ceildiv((*y) - y_range.second, m);
      (*x) += n * d;
      (*y) -= m * d;
      if ((*x) > x_range.second || (*y) < y_range.first) return false;
    }
    if ((*y) < y_range.first) {
      d = ceildiv(y_range.first - (*y), m);
      (*x) -= n * d;
      (*y) += m * d;
      if ((*x) < x_range.first || (*y) > y_range.second) return false;
    }
    if ((*x) < x_range.first) {
      d = ceildiv(x_range.first - (*x), n);
      (*x) += n * d;
      (*y) -= m * d;
      if ((*x) > x_range.second || (*y) < y_range.first) return false;
    }
    if ((*x) > x_range.second) {
      d = ceildiv((*x) - x_range.second, n);
      (*x) -= n * d;
      (*y) += m * d;
      if ((*x) < x_range.first || (*y) > y_range.second) return false;
    }
    return true;
  }
public:
  

  ll x, y, gcd;
  Extended_Euclid(ll M, ll N) {
    m = M;
    n = N;
    vll r(100), k(100);
    bool swapflag = false, m_negflag = false, n_negflag = false;
    if (m < n) { swap(m, n); swapflag = true; }
    if (m < 0) { m *= -1; m_negflag = true; }
    if (n < 0) { n *= -1; n_negflag = true; }
    r[0] = m;
    r[1] = n;
    int h = 1;
    while (1) {
      k[h - 1] = r[h - 1] / r[h];
      r[h + 1] = r[h - 1] % r[h];
      if (r[h + 1] == 0) break;
      h++;
    }
    gcd = r[h];
    vvll mx1 = { { 0, 1 },{ 1, (-1) * k[h - 1] } };
    Loopr(i, h - 1) {
      vvll mx2 = { { 0, 1 },{ 1, (-1) * k[i] } };
      mx1 = mx_multiply(mx1, mx2);
    }
    x = mx1[0][0];
    y = mx1[0][1];
    if (n_negflag) { n *= -1; y *= -1; }
    if (m_negflag) { m *= -1; x *= -1; }
    if (swapflag) { swap(m, n); swap(x, y); }
  }
  

  bool solve_equation(ll r, ll *x, ll *y, Pll x_range = { LLONG_MIN, LLONG_MAX }, Pll y_range = { LLONG_MIN, LLONG_MAX }) {
    if (r % gcd != 0) return false;
    else {
      bool m_negflag = false, n_negflag = false;
      if (m < 0) { m *= -1; this->x *= -1; x_range = { -x_range.second, -x_range.first }; m_negflag = true; }
      if (n < 0) { n *= -1; this->y *= -1; y_range = { -y_range.second, -y_range.first }; n_negflag = true; }
      ll ret_x = this->x * (r / gcd);
      ll ret_y = this->y * (r / gcd);
      bool valid = adjust_into_range(m / gcd, n / gcd, &ret_x, &ret_y, x_range, y_range);
      if (n_negflag) { n *= -1; this->y *= -1; ret_y *= -1; }
      if (m_negflag) { m *= -1; this->x *= -1; ret_x *= -1; }
      if (!valid) return false;
      else {
        *x = ret_x;
        *y = ret_y;
        return true;
      }
    }
  }
};

namespace mod_op {

  

  ll modify(ll n) {
    ll ret;
    if (n > 0) ret = n - n / MOD * MOD;
    else ret = n - (n - MOD + 1) / MOD * MOD;
    return ret;
  }

  ll mul(ll x, ll y) {
    return x * y % MOD;
  }

  ll add(ll x, ll y) {
    return (x + y) % MOD;
  }

  ll sub(ll x, ll y) {
    return modify(x - y);
  }

  

  vll factlist(ll n) {
    if (n < 0) return{};
    else {
      vll ret((int)n + 1);
      ret[0] = 1;
      Loop1(i, (int)n) ret[i] = mul(ret[i - 1], i);
      return ret;
    }
  }

  

  ll powm(ll n, ll p) {
    if (p == 0) return 1;
    else if (p == 1) return n;
    else {
      ll ans = powm(n, p / 2);
      ans = mul(ans, ans);
      if (p % 2 == 1) ans = mul(ans, n);
      return ans;
    }
  }

  

  ll inv(ll n) {
    Extended_Euclid ee(n, MOD*(-1));
    return modify(ee.x);
  }

  

  ll mod_combination(ll n, ll r) {
    vll facts = factlist(n);
    return mul(facts[(unsigned)n], inv(mul(facts[(unsigned)r], facts[(unsigned)(n - r)])));
  }

  ll divm(ll x, ll y) {
    return mul(x, inv(y));
  }

  

  ll disc_log(ll a, ll b) {
    ll m = rnd(sqrt(MOD)) + 1;
    unordered_map<ll, ll> mp;
    ll y = 1;
    Loop(i, m) {
      mp[y] = i;
      y = mul(y, a);
    }
    y = inv(powm(a, m));
    ll k = b;
    Loop(i, m) {
      if (mp.find(k) == mp.end()) k = mul(k, y);
      else return i * m + mp[k];
    }
    return -1;
  }
}

using namespace mod_op;

typedef ll nodeval_t;
typedef ll edgeval_t;

struct tree_t {
  int n;           

  vector<P> edges; 

  vector<nodeval_t> vals; 

  vector<edgeval_t> costs; 

};

class Tree {
private:
  struct node {
    int id; vi childs; int parent;
    int deg; 

    int eid; 

    int subtree_n; 

    nodeval_t val; 

    edgeval_t cost; 

  };
  struct edgeinfo {
    int eid; int to; edgeval_t cost;
  };
  int n;
  static const nodeval_t init_val = 0;
  static const edgeval_t init_cost = 1;
public:
  vector<node> nodes;
  vi deg_order; 

  vi leaves;
  int root;
  

  Tree(tree_t T, int root = -1) {
    n = T.n;
    nodes.resize(n);
    Loop(i, n) nodes[i] = { i, {}, -1, -1, -1, 1, T.vals.size() > i ? T.vals[i] : 0, init_cost };
    vector<vector<edgeinfo>> edges(n);
    Loop(i, n - 1) {
      edges[T.edges[i].first].push_back({ i, T.edges[i].second, (T.costs.size() > i ? T.costs[i] : init_cost) });
      edges[T.edges[i].second].push_back({ i, T.edges[i].first, (T.costs.size() > i ? T.costs[i] : init_cost) });
    }
    

    if (root < 0) {
      int max_d = -1;
      Loop(i, n) {
        if (edges[i].size() > max_d) {
          Tree::root = i;
          max_d = edges[i].size();
        }
      }
    }
    else {
      Tree::root = min(root, n - 1);
    }
    

    leaves = {};
    queue<int> que;
    que.push(Tree::root);
    while (que.size()) {
      int a = que.front(); que.pop();
      deg_order.push_back(a);
      if (a == Tree::root) nodes[a].deg = 0;
      int leaf_flag = true;
      Loop(i, edges[a].size()) {
        int b = edges[a][i].to;
        if (nodes[b].deg != -1) {
          nodes[a].parent = b;
          nodes[a].eid = edges[a][i].eid;
          nodes[a].cost = edges[a][i].cost;
          nodes[a].deg = nodes[b].deg + 1;
        }
        else {
          leaf_flag = false;
          nodes[a].childs.push_back(b);
          que.push(b);
        }
      }
      if (leaf_flag) leaves.push_back(a);
    }
    Loopr(i, n) {
      int a = deg_order[i];
      Loop(j, nodes[a].childs.size()) {
        int b = nodes[a].childs[j];
        nodes[a].subtree_n += nodes[b].subtree_n;
      }
    }
    return;
  }
  vi solve_node_inclusion_cnt_in_all_path(bool enable_single_node_path) {
    vi ret(n, 0);
    Loop(i, n) {
      int a = i;
      

      Loop(j, nodes[a].childs.size()) {
        int b = nodes[a].childs[j];
        ret[i] += nodes[b].subtree_n * (nodes[a].subtree_n - nodes[b].subtree_n - 1);
      }
      ret[i] /= 2; 

      ret[i] += (nodes[a].subtree_n - 1) * (n - nodes[a].subtree_n); 

      ret[i] += n - 1; 

      if (enable_single_node_path) ret[i]++; 

    }
    return ret;
  }
  vi solve_edge_inclusion_cnt_in_all_path() {
    vi ret(n - 1, 0);
    Loop(i, n) {
      int eid = nodes[i].eid;
      if (eid < 0) continue;
      ret[eid] = nodes[i].subtree_n * (n - nodes[i].subtree_n); 

    }
    return ret;
  }
  ll solve() {
    vll subtree_evencnt(n, 0);
    vll pathcnt(n, 0);
    int all_even_cnt = 0;
    Loop(i, n) {
      if (nodes[i].deg % 2 == 0) all_even_cnt++;
    }
    Loopr(i, n) {
      int a = deg_order[i];
      Loop(j, nodes[a].childs.size()) {
        int b = nodes[a].childs[j];
        subtree_evencnt[a] += subtree_evencnt[b];
      }
      if (nodes[a].deg % 2 == 0) subtree_evencnt[a]++;
    }
    Loop(i, n) {
      int a = i;
      

      Loop(j, nodes[a].childs.size()) {
        int b = nodes[a].childs[j];
        pathcnt[a] += subtree_evencnt[b] * (subtree_evencnt[a] - subtree_evencnt[b] - (nodes[a].deg % 2 == 0 ? 1 : 0));
      }
      pathcnt[a] += (subtree_evencnt[a] - (nodes[a].deg % 2 == 0 ? 1 : 0)) * (all_even_cnt - subtree_evencnt[a]) * 2; 

      if (nodes[a].deg % 2 == 0) pathcnt[a] += (all_even_cnt - 1) * 2; 

      if (nodes[a].deg % 2 == 0) pathcnt[a]++; 

    }
    ll ret = 0;
    Loop(i, n) {
      if (nodes[i].deg % 2 == 0) {
        ret = add(ret, mul(nodes[i].val, modify(pathcnt[i])));
      }
      else {
        ret = sub(ret, mul(nodes[i].val, modify(pathcnt[i])));
      }
    }
    return ret;
  }
};

int main() {
  tree_t T;
  cin >> T.n;
  Loop(i, T.n) {
    ll x; cin >> x;
    T.vals.push_back(modify(x));
  }
  Loop(i, T.n - 1) {
    int s, t; cin >> s >> t;
    s--;
    t--;
    T.edges.push_back({ s, t });
  }
  Tree tree(T, 0);
  int r0 = tree.leaves[0];
  int r1 = tree.nodes[r0].parent;
  Tree tree0(T, r0), tree1(T, r1);
  ll ans = add(tree0.solve(), tree1.solve());
  cout << ans << endl;
}