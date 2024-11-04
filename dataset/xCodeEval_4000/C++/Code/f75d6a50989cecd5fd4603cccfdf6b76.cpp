


#define USETR1
#define CPPELEVEN
#define GPP





#include <math.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

#ifndef CPPELEVEN
#ifdef USETR1
#include <tr1/unordered_map>
#include <tr1/unordered_set>
using namespace tr1;
#endif
#else
#include <unordered_map>
#include <unordered_set>
#endif

#ifdef USEPB_DS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;


typedef __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq_type;


typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    tree_type;
#endif

#define mpr make_pair
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef map<string, int> mpsi;
typedef map<double, int> mpdi;
typedef map<int, int> mpii;

const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = {{-1, 0}, {0, 1}, {1, 0},  {0, -1},
                        {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}

#ifndef CPPELEVEN
template <class T>
inline T max1(T a, T b) {
  return b < a ? a : b;
}
template <class T>
inline T max1(T a, T b, T c) {
  return max1(max1(a, b), c);
}
template <class T>
inline T max1(T a, T b, T c, T d) {
  return max1(max1(a, b, c), d);
}
template <class T>
inline T max1(T a, T b, T c, T d, T e) {
  return max1(max1(a, b, c, d), e);
}
template <class T>
inline T min1(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline T min1(T a, T b, T c) {
  return min1(min1(a, b), c);
}
template <class T>
inline T min1(T a, T b, T c, T d) {
  return min1(min1(a, b, c), d);
}
template <class T>
inline T min1(T a, T b, T c, T d, T e) {
  return min1(min1(a, b, c, d), e);
}
#else
template <typename t, typename t1>
t min1(t a, t1 b) {
  return a < b ? a : b;
}
template <typename t, typename... arg>
t min1(t a, arg... arr) {
  return min1(a, min1(arr...));
}
template <typename t, typename t1>
t max1(t a, t1 b) {
  return a > b ? a : b;
}
template <typename t, typename... arg>
t max1(t a, arg... arr) {
  return max1(a, max1(arr...));
}
#endif

inline int jud(double a, double b) {
  if (abs(a) < eps && abs(b) < eps)
    return 0;
  else if (abs1(a - b) / max(abs1(a), abs1(b)) < eps)
    return 0;
  if (a < b) return -1;
  return 1;
}
template <typename t>
inline int jud(t a, t b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}

template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
  if (na == 0) return 0;
  int be = 0, en = na - 1;
  if (*a <= *(a + na - 1)) {
    if (f_lb == 0)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != 1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != -1)
          en = mid;
        else
          be = mid + 1;
      }
    if (f_small && jud(*(a + be), val) == 1) be--;
    if (!f_small && jud(*(a + be), val) == -1) be++;
  } else {
    if (f_lb)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != -1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != 1)
          en = mid;
        else
          be = mid + 1;
      }
    if (!f_small && jud(*(a + be), val) == -1) be--;
    if (f_small && jud(*(a + be), val) == 1) be++;
  }
  return be;
}

template <class T>
inline T lowb(T num) {
  return num & (-num);
}
#ifdef GPP
inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(ull nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitnum(ll nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitmaxl(ui a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(ull a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
inline int bitmaxl(ll a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
#else
#endif

long long pow(long long n, long long m, long long mod = 0) {
  if (m < 0) return 0;
  long long ans = 1;
  long long k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (mod) ans %= mod;
    }
    k *= k;
    if (mod) k %= mod;
    m >>= 1;
  }
  return ans;
}

#define MOD 1000000007
template <class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
  if (mod == -1) mod = MOD;
  a += b;
  while (a >= mod) a -= mod;
  while (a < 0) a += mod;
}
template <class t>
void output1(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) cerr << arr[i] << ' ';
  cerr << endl;
}
template <class t>
void output2(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) output1(arr[i]);
}




#ifndef N
#define N 201000
#endif
struct segment_node{
  int be, en;
  int add;
  pii minv;
};
struct segment_tree{
  int l;
  segment_node tree[N * 4];
  
  inline int gleft(int no) {return no << 1;}
  inline int gright(int no) {return (no << 1) + 1;}
  inline int gfa(int no) {return no >> 1;}
  inline segment_tree(){ l = 0; }
  
  void build(int no, int l, int r, int orig = 0, int *a = NULL){
    if(l > r) r = l;
    if(l == r){
      tree[no].be = tree[no].en = l;
      tree[no].add = 0;
      if(a == NULL) tree[no].minv = mpr(orig, l);
      else tree[no].minv = mpr(a[l], l);
      tree[no].add = 0;
      return;
    }
    tree[no].be = l; tree[no].en = r;
    int mid = (l + r) / 2;
    build(gleft(no), l, mid, orig, a);
    build(gright(no), mid + 1, r, orig, a);
    tree[no].add = 0;
    tree[no].minv = min(tree[gleft(no)].minv, tree[gright(no)].minv);
  }
  inline void relax(int no) {
    int le = gleft(no), ri = gright(no);
    tree[le].add += tree[no].add;
    tree[le].minv.first += tree[no].add;
    tree[ri].add += tree[no].add;
    tree[ri].minv.first += tree[no].add;
    tree[no].add = 0;
  }
  void down(int l, int r, int no, int ranadd){
    if(l <= tree[no].be && r >= tree[no].en){
      tree[no].add += ranadd;
      tree[no].minv.first += ranadd;
      return;
    }
    if(tree[no].add && tree[no].be != tree[no].en) relax(no);
    int mid = (tree[no].be + tree[no].en) >> 1;
    if(r >= tree[no].be && l <= mid) down(l, r, gleft(no), ranadd);
    if(r >= mid + 1 && l <= tree[no].en) down(l, r, gright(no), ranadd);
    tree[no].minv = min(tree[gleft(no)].minv, tree[gright(no)].minv);
  }
  int get(int loc, int no){
    if(tree[no].be == tree[no].en)
      return tree[no].minv.first;
    if(tree[no].add && tree[no].be != tree[no].en) relax(no);
    int mid = (tree[no].be + tree[no].en) >> 1;
    if (loc <= mid) return get(loc, gleft(no));
    else return get(loc, gright(no));
  }
} sgt;

const int maxn = N;
int n, nq;
int cnt_rev[2];
int loc[maxn];
int orig[maxn];
int sum[maxn];

inline int Sgn(int num) {
  return num == n ? 0 : (num > n ? 1 : -1);
}

int main() {
  ios_base::sync_with_stdio(0);
#ifdef DEBUG  

  freopen("input.txt", "r", stdin);
#endif  


  scanf("%d%d", &n, &nq);
  for (int i = 0; i < n * 2 + 1; i++) {
    scanf("%d", orig + i);
    orig[i]--;
    loc[orig[i]] = i;
  }
  

  bool deb = false;

  for (int i = 0; i < n; i++) {
    if (loc[i + 1] < loc[i]) cnt_rev[0]++;
    if (loc[i + n + 1] < loc[i + n]) cnt_rev[1]++;
  }
  sum[0] = Sgn(orig[0]);
  for (int i = 1; i < n * 2 + 1; i++) {
    sum[i] = sum[i - 1] + Sgn(orig[i]);
  }
  sgt.build(1, 0, n * 2, 0, sum);

  for (int i = 0; i < nq; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    if (deb) {
      int rcnt[2] = {0, 0};
      for (int i = 0; i < n * 2; i++) rcnt[i >= n] += loc[i] > loc[i + 1];
      if (rcnt[0] != cnt_rev[0] || rcnt[1] != cnt_rev[1]) {
        printf("!%d %d %d %d %d\n", i, a, b, orig[a], orig[b]);
        printf("!%d %d %d %d\n", rcnt[0], rcnt[1], cnt_rev[0], cnt_rev[1]);
      }
    }
    auto upd = [&](int no, int to_add) {
      if (no < 0 || no >= 2 * n) return;
      if (loc[no + 1] < loc[no]) cnt_rev[no >= n] += to_add;
    };
    upd(orig[a], -1);
    upd(orig[a] - 1, -1);
    if (orig[b] != orig[a] - 1) upd(orig[b], -1);
    if (orig[b] - 1 != orig[a]) upd(orig[b] - 1, -1);
    sgt.down(a, n * 2, 1, -Sgn(orig[a]));
    sgt.down(b, n * 2, 1, -Sgn(orig[b]));
    swap(orig[a], orig[b]);
    swap(loc[orig[a]], loc[orig[b]]);
    upd(orig[a], 1);
    upd(orig[a] - 1, 1);
    if (orig[b] != orig[a] - 1) upd(orig[b], 1);
    if (orig[b] - 1 != orig[a]) upd(orig[b] - 1, 1);
    sgt.down(a, n * 2, 1, Sgn(orig[a]));
    sgt.down(b, n * 2, 1, Sgn(orig[b]));
    
    if (deb) {
      int rcnt[2] = {0, 0};
      for (int i = 0; i < n * 2; i++) rcnt[i >= n] += loc[i] > loc[i + 1];
      if (rcnt[0] != cnt_rev[0] || rcnt[1] != cnt_rev[1]) {
        printf("%d %d %d %d %d\n", i, a, b, orig[a], orig[b]);
        printf("%d %d %d %d\n", rcnt[0], rcnt[1], cnt_rev[0], cnt_rev[1]);
      }
    }
    
    int rsumn = sgt.get(loc[n], 1);
    if (sgt.tree[1].minv.first < rsumn) {
      if (!deb)  printf("%d\n", (sgt.tree[1].minv.second + 1) % (n * 2 + 1));
      continue;
    }
    {
      bool flag = false;
      if (loc[0] > loc[n] && cnt_rev[0] == 1) {
        flag = true;
      }
      if (loc[0] < loc[n] && cnt_rev[0] == 0) {
        flag = true;
      }
      if (!flag) {
        if (!deb) printf("%d\n", (loc[n] + 1) % (n * 2 + 1));
        continue;
      }
    }
    {
      bool flag = false;
      if (loc[n * 2] < loc[n] && cnt_rev[1] == 1) {
        flag = true;
      }
      if (loc[n * 2] > loc[n] && cnt_rev[1] == 0) {
        flag = true;
      }
      if (!flag) {
        if (!deb) printf("%d\n", loc[n] % (n * 2 + 1));
        continue;
      }
    }
    

    

    

    

    if (!deb)  puts("-1");
  }



  return 0;
}