#include "bits/stdc++.h"
using namespace std;
#define int long long
#ifdef ONLINE_JUDGE
const int MAXN = 2e5 + 10;
#endif
#ifndef ONLINE_JUDGE
const int MAXN = 1029;
#endif
const int MOD = 1e9 + 7;
#define ll __int128
mt19937_64 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  int u = uniform_int_distribution<int>(x, y)(rng); return u;
}
ll read() { int x; cin >> x; return (ll)x; }
long long bm(long long b, long long p) {
  if(p==0) return 1 % MOD;
  long long r = bm(b, p >> 1);
  if(p&1) return (((r*r) % MOD) * b) % MOD;
  return (r*r) % MOD;
}
long long inv(long long b) { 
  return bm(b, MOD-2);
}
long long f[MAXN];
long long nCr(int n, int r) { 
  long long ans = f[n]; ans *= inv(f[r]); ans %= MOD;
  ans *= inv(f[n-r]); ans %= MOD; return ans;
}
void precomp() { for(int i=0; i<MAXN; i++) f[i] = (i == 0 ? 1 % MOD : (f[i-1] * i) % MOD); }
int fastlog(int x) {
  return (x == 0 ? -1 : 32 - __builtin_clz(x) - 1);
}
void gay(int i) { cout << "Case #" << i << ": "; }
int csb(int l, int r, int k) { 

  if(l > r) return 0;
  if(l == 0) {
    int s = r / (1ll << (k+1)); 

    int t = r % (1ll << (k+1));
    int ans = s * (1ll << k);
    ans += (t >= (1ll << k) ? t - (1ll << k) + 1 : 0);
    return ans;
  }
  else return csb(0, r, k) - csb(0, l - 1, k);
}






struct segtree_basic {
  

  

  

  

  

  

  

  

  struct node {
    int upd = 0;
    char type = '?'; 
    int mi = 0, ma = 0, sum = 0;
  };
  int stok;
  vector<node> st;
  void u1(int l, int r, int constl, int constr, int idx, int val) { 

    if(l <= constl && constr <= r) {
      st[idx].upd = val;
      st[idx].type = ':';
      st[idx].mi = val;
      st[idx].ma = val;
      st[idx].sum = val * (constr - constl + 1);
      return;
    }
    int mid = (constl + constr) >> 1;
    if(st[idx].type != '?') {
      if(st[idx].type == ':') {
        st[2*idx+1].upd = st[idx].upd;
        st[2*idx+1].type = ':';
        st[2*idx+1].mi = st[idx].upd;
        st[2*idx+1].ma = st[idx].upd;
        st[2*idx+1].sum = st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd = st[idx].upd;
        st[2*idx+2].type = ':';
        st[2*idx+2].mi = st[idx].upd;
        st[2*idx+2].ma = st[idx].upd;
        st[2*idx+2].sum = st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
      else {
        st[2*idx+1].upd += st[idx].upd;
        if(st[2*idx+1].type == '?') st[2*idx+1].type = '+';
        st[2*idx+1].mi += st[idx].upd;
        st[2*idx+1].ma += st[idx].upd;
        st[2*idx+1].sum += st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd += st[idx].upd;
        if(st[2*idx+2].type == '?') st[2*idx+2].type = '+';
        st[2*idx+2].mi += st[idx].upd;
        st[2*idx+2].ma += st[idx].upd;
        st[2*idx+2].sum += st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
    }
    if(mid<l || r<constl) u1(l, r, mid + 1, constr, 2*idx+2, val);
    else if(constr<l || r<mid+1) u1(l, r, constl, mid, 2*idx+1, val);
    else {
      u1(l, r, constl, mid, 2*idx+1, val); u1(l, r, mid + 1, constr, 2*idx+2, val);
    }
    st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
    st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
    st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
  }
  void u2(int l, int r, int constl, int constr, int idx, int val) { 

    if(l <= constl && constr <= r) {
      st[idx].upd += val;
      if(st[idx].type == '?') st[idx].type = '+';
      st[idx].mi += val;
      st[idx].ma += val;
      st[idx].sum += val * (constr - constl + 1);
      return;
    }
    int mid = (constl + constr) >> 1;
    if(st[idx].type != '?') {
      if(st[idx].type == ':') {
        st[2*idx+1].upd = st[idx].upd;
        st[2*idx+1].type = ':';
        st[2*idx+1].mi = st[idx].upd;
        st[2*idx+1].ma = st[idx].upd;
        st[2*idx+1].sum = st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd = st[idx].upd;
        st[2*idx+2].type = ':';
        st[2*idx+2].mi = st[idx].upd;
        st[2*idx+2].ma = st[idx].upd;
        st[2*idx+2].sum = st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
      else {
        st[2*idx+1].upd += st[idx].upd;
        if(st[2*idx+1].type == '?') st[2*idx+1].type = '+';
        st[2*idx+1].mi += st[idx].upd;
        st[2*idx+1].ma += st[idx].upd;
        st[2*idx+1].sum += st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd += st[idx].upd;
        if(st[2*idx+2].type == '?') st[2*idx+2].type = '+';
        st[2*idx+2].mi += st[idx].upd;
        st[2*idx+2].ma += st[idx].upd;
        st[2*idx+2].sum += st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
    }
    if(mid<l || r<constl) u2(l, r, mid + 1, constr, 2*idx+2, val);
    else if(constr<l || r<mid+1) u2(l, r, constl, mid, 2*idx+1, val);
    else {
      u2(l, r, constl, mid, 2*idx+1, val); u2(l, r, mid + 1, constr, 2*idx+2, val);
    }
    st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
    st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
    st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
  }
  int qu1(int l, int r, int constl, int constr, int idx) { 

    if(l<=constl && constr<=r) return st[idx].mi;
    int mid = (constl + constr) >> 1;
    if(st[idx].type != '?') {
      if(st[idx].type == ':') {
        st[2*idx+1].upd = st[idx].upd;
        st[2*idx+1].type = ':';
        st[2*idx+1].mi = st[idx].upd;
        st[2*idx+1].ma = st[idx].upd;
        st[2*idx+1].sum = st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd = st[idx].upd;
        st[2*idx+2].type = ':';
        st[2*idx+2].mi = st[idx].upd;
        st[2*idx+2].ma = st[idx].upd;
        st[2*idx+2].sum = st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
      else {
        st[2*idx+1].upd += st[idx].upd;
        if(st[2*idx+1].type == '?') st[2*idx+1].type = '+';
        st[2*idx+1].mi += st[idx].upd;
        st[2*idx+1].ma += st[idx].upd;
        st[2*idx+1].sum += st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd += st[idx].upd;
        if(st[2*idx+2].type == '?') st[2*idx+2].type = '+';
        st[2*idx+2].mi += st[idx].upd;
        st[2*idx+2].ma += st[idx].upd;
        st[2*idx+2].sum += st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
    }
    if(mid<l || r<constl) return qu1(l, r, mid+1, constr, 2*idx+2);
    else if(constr<l || r<mid+1) return qu1(l, r, constl, mid, 2*idx+1);
    return min(qu1(l, r, constl, mid, 2*idx+1), qu1(l, r, mid+1, constr, 2*idx+2));
  }
  int qu2(int l, int r, int constl, int constr, int idx) { 

    if(l<=constl && constr<=r) return st[idx].ma;
    int mid = (constl + constr) >> 1;
    if(st[idx].type != '?') {
      if(st[idx].type == ':') {
        st[2*idx+1].upd = st[idx].upd;
        st[2*idx+1].type = ':';
        st[2*idx+1].mi = st[idx].upd;
        st[2*idx+1].ma = st[idx].upd;
        st[2*idx+1].sum = st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd = st[idx].upd;
        st[2*idx+2].type = ':';
        st[2*idx+2].mi = st[idx].upd;
        st[2*idx+2].ma = st[idx].upd;
        st[2*idx+2].sum = st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
      else {
        st[2*idx+1].upd += st[idx].upd;
        if(st[2*idx+1].type == '?') st[2*idx+1].type = '+';
        st[2*idx+1].mi += st[idx].upd;
        st[2*idx+1].ma += st[idx].upd;
        st[2*idx+1].sum += st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd += st[idx].upd;
        if(st[2*idx+2].type == '?') st[2*idx+2].type = '+';
        st[2*idx+2].mi += st[idx].upd;
        st[2*idx+2].ma += st[idx].upd;
        st[2*idx+2].sum += st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
    }
    if(mid<l || r<constl) return qu2(l, r, mid+1, constr, 2*idx+2);
    else if(constr<l || r<mid+1) return qu2(l, r, constl, mid, 2*idx+1);
    return max(qu2(l, r, constl, mid, 2*idx+1), qu2(l, r, mid+1, constr, 2*idx+2));
  }
  int qu3(int l, int r, int constl, int constr, int idx) { 

    if(l<=constl && constr<=r) return st[idx].sum;
    int mid = (constl + constr) >> 1;
    if(st[idx].type != '?') {
      if(st[idx].type == ':') {
        st[2*idx+1].upd = st[idx].upd;
        st[2*idx+1].type = ':';
        st[2*idx+1].mi = st[idx].upd;
        st[2*idx+1].ma = st[idx].upd;
        st[2*idx+1].sum = st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd = st[idx].upd;
        st[2*idx+2].type = ':';
        st[2*idx+2].mi = st[idx].upd;
        st[2*idx+2].ma = st[idx].upd;
        st[2*idx+2].sum = st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
      else {
        st[2*idx+1].upd += st[idx].upd;
        if(st[2*idx+1].type == '?') st[2*idx+1].type = '+';
        st[2*idx+1].mi += st[idx].upd;
        st[2*idx+1].ma += st[idx].upd;
        st[2*idx+1].sum += st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd += st[idx].upd;
        if(st[2*idx+2].type == '?') st[2*idx+2].type = '+';
        st[2*idx+2].mi += st[idx].upd;
        st[2*idx+2].ma += st[idx].upd;
        st[2*idx+2].sum += st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
    }
    if(mid<l || r<constl) return qu3(l, r, mid + 1, constr, 2*idx + 2);
    else if(constr < l || r <mid+ 1) return qu3(l, r, constl, mid, 2*idx + 1);
    else {
      return qu3(l, r, constl, mid, 2*idx + 1) + qu3(l, r, mid + 1, constr, 2*idx + 2);
    }
  }
  int qu4(int l, int r, int constl, int constr, int idx, int val) { 

    if(l<=constl && constr<=r) {
      if(st[idx].ma < val) return -1;
      while(constl < constr) {
        int mid = (constl + constr) >> 1;
        if(st[idx].type != '?') {
          if(st[idx].type == ':') {
            st[2*idx+1].upd = st[idx].upd;
            st[2*idx+1].type = ':';
            st[2*idx+1].mi = st[idx].upd;
            st[2*idx+1].ma = st[idx].upd;
            st[2*idx+1].sum = st[idx].upd * (mid - constl + 1);

            st[2*idx+2].upd = st[idx].upd;
            st[2*idx+2].type = ':';
            st[2*idx+2].mi = st[idx].upd;
            st[2*idx+2].ma = st[idx].upd;
            st[2*idx+2].sum = st[idx].upd * (constr - mid);

            st[idx].upd = 0;
            st[idx].type = '?';
            st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
            st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
            st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
          }
          else {
            st[2*idx+1].upd += st[idx].upd;
            if(st[2*idx+1].type == '?') st[2*idx+1].type = '+';
            st[2*idx+1].mi += st[idx].upd;
            st[2*idx+1].ma += st[idx].upd;
            st[2*idx+1].sum += st[idx].upd * (mid - constl + 1);

            st[2*idx+2].upd += st[idx].upd;
            if(st[2*idx+2].type == '?') st[2*idx+2].type = '+';
            st[2*idx+2].mi += st[idx].upd;
            st[2*idx+2].ma += st[idx].upd;
            st[2*idx+2].sum += st[idx].upd * (constr - mid);

            st[idx].upd = 0;
            st[idx].type = '?';
            st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
            st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
            st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
          }
        }
        if(st[2*idx+1].ma >= val) idx = 2*idx + 1, constr = mid;
        else idx = 2*idx+2, constl = mid + 1;
      }
      return constl;
    }
    int mid = (constl+constr) >> 1;
    if(st[idx].type != '?') {
      if(st[idx].type == ':') {
        st[2*idx+1].upd = st[idx].upd;
        st[2*idx+1].type = ':';
        st[2*idx+1].mi = st[idx].upd;
        st[2*idx+1].ma = st[idx].upd;
        st[2*idx+1].sum = st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd = st[idx].upd;
        st[2*idx+2].type = ':';
        st[2*idx+2].mi = st[idx].upd;
        st[2*idx+2].ma = st[idx].upd;
        st[2*idx+2].sum = st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
      else {
        st[2*idx+1].upd += st[idx].upd;
        if(st[2*idx+1].type == '?') st[2*idx+1].type = '+';
        st[2*idx+1].mi += st[idx].upd;
        st[2*idx+1].ma += st[idx].upd;
        st[2*idx+1].sum += st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd += st[idx].upd;
        if(st[2*idx+2].type == '?') st[2*idx+2].type = '+';
        st[2*idx+2].mi += st[idx].upd;
        st[2*idx+2].ma += st[idx].upd;
        st[2*idx+2].sum += st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
    }
    if(mid<l || r<constl) return qu4(l, r, mid+1, constr, 2*idx+2, val);
    else if(constr<l || r<mid+1) return qu4(l, r, constl, mid, 2*idx+1, val);
    else {
      int oho = qu4(l, r, constl, mid, 2*idx+1, val);
      if(oho != -1) return oho;
      return qu4(l, r, mid+1, constr, 2*idx+2, val);
    }
  }
  int qu5(int l, int r, int constl, int constr, int idx, int val) { 

    if(l<=constl && constr<=r) {
      if(st[idx].mi > val) return -1;
      while(constl < constr) {
        int mid = (constl + constr) >> 1;
        if(st[idx].type != '?') {
          if(st[idx].type == ':') {
            st[2*idx+1].upd = st[idx].upd;
            st[2*idx+1].type = ':';
            st[2*idx+1].mi = st[idx].upd;
            st[2*idx+1].ma = st[idx].upd;
            st[2*idx+1].sum = st[idx].upd * (mid - constl + 1);

            st[2*idx+2].upd = st[idx].upd;
            st[2*idx+2].type = ':';
            st[2*idx+2].mi = st[idx].upd;
            st[2*idx+2].ma = st[idx].upd;
            st[2*idx+2].sum = st[idx].upd * (constr - mid);

            st[idx].upd = 0;
            st[idx].type = '?';
            st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
            st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
            st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
          }
          else {
            st[2*idx+1].upd += st[idx].upd;
            if(st[2*idx+1].type == '?') st[2*idx+1].type = '+';
            st[2*idx+1].mi += st[idx].upd;
            st[2*idx+1].ma += st[idx].upd;
            st[2*idx+1].sum += st[idx].upd * (mid - constl + 1);

            st[2*idx+2].upd += st[idx].upd;
            if(st[2*idx+2].type == '?') st[2*idx+2].type = '+';
            st[2*idx+2].mi += st[idx].upd;
            st[2*idx+2].ma += st[idx].upd;
            st[2*idx+2].sum += st[idx].upd * (constr - mid);

            st[idx].upd = 0;
            st[idx].type = '?';
            st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
            st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
            st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
          }
        }
        if(st[2*idx+1].mi <= val) idx = 2*idx + 1, constr = mid;
        else idx = 2*idx+2, constl = mid + 1;
      }
      return constl;
    }
    int mid = (constl+constr) >> 1;
    if(st[idx].type != '?') {
      if(st[idx].type == ':') {
        st[2*idx+1].upd = st[idx].upd;
        st[2*idx+1].type = ':';
        st[2*idx+1].mi = st[idx].upd;
        st[2*idx+1].ma = st[idx].upd;
        st[2*idx+1].sum = st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd = st[idx].upd;
        st[2*idx+2].type = ':';
        st[2*idx+2].mi = st[idx].upd;
        st[2*idx+2].ma = st[idx].upd;
        st[2*idx+2].sum = st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
      else {
        st[2*idx+1].upd += st[idx].upd;
        if(st[2*idx+1].type == '?') st[2*idx+1].type = '+';
        st[2*idx+1].mi += st[idx].upd;
        st[2*idx+1].ma += st[idx].upd;
        st[2*idx+1].sum += st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd += st[idx].upd;
        if(st[2*idx+2].type == '?') st[2*idx+2].type = '+';
        st[2*idx+2].mi += st[idx].upd;
        st[2*idx+2].ma += st[idx].upd;
        st[2*idx+2].sum += st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
    }
    if(mid<l || r<constl) return qu5(l, r, mid+1, constr, 2*idx+2, val);
    else if(constr<l || r<mid+1) return qu5(l, r, constl, mid, 2*idx+1, val);
    else {
      int oho = qu5(l, r, constl, mid, 2*idx+1, val);
      if(oho != -1) return oho;
      return qu5(l, r, mid+1, constr, 2*idx+2, val);
    }
  }
  int qu6(int l, int r, int constl, int constr, int idx, int val) { 

    if(l<=constl && constr<=r) {
      if(st[idx].ma < val) return -1;
      while(constl < constr) {
        int mid = (constl + constr) >> 1;
        if(st[idx].type != '?') {
          if(st[idx].type == ':') {
            st[2*idx+1].upd = st[idx].upd;
            st[2*idx+1].type = ':';
            st[2*idx+1].mi = st[idx].upd;
            st[2*idx+1].ma = st[idx].upd;
            st[2*idx+1].sum = st[idx].upd * (mid - constl + 1);

            st[2*idx+2].upd = st[idx].upd;
            st[2*idx+2].type = ':';
            st[2*idx+2].mi = st[idx].upd;
            st[2*idx+2].ma = st[idx].upd;
            st[2*idx+2].sum = st[idx].upd * (constr - mid);

            st[idx].upd = 0;
            st[idx].type = '?';
            st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
            st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
            st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
          }
          else {
            st[2*idx+1].upd += st[idx].upd;
            if(st[2*idx+1].type == '?') st[2*idx+1].type = '+';
            st[2*idx+1].mi += st[idx].upd;
            st[2*idx+1].ma += st[idx].upd;
            st[2*idx+1].sum += st[idx].upd * (mid - constl + 1);

            st[2*idx+2].upd += st[idx].upd;
            if(st[2*idx+2].type == '?') st[2*idx+2].type = '+';
            st[2*idx+2].mi += st[idx].upd;
            st[2*idx+2].ma += st[idx].upd;
            st[2*idx+2].sum += st[idx].upd * (constr - mid);

            st[idx].upd = 0;
            st[idx].type = '?';
            st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
            st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
            st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
          }
        }
        if(st[2*idx+2].ma >= val) idx = 2*idx + 2, constl = mid + 1;
        else idx = 2*idx + 1, constr = mid;
      }
      return constl;
    }
    int mid = (constl+constr) >> 1;
    if(st[idx].type != '?') {
      if(st[idx].type == ':') {
        st[2*idx+1].upd = st[idx].upd;
        st[2*idx+1].type = ':';
        st[2*idx+1].mi = st[idx].upd;
        st[2*idx+1].ma = st[idx].upd;
        st[2*idx+1].sum = st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd = st[idx].upd;
        st[2*idx+2].type = ':';
        st[2*idx+2].mi = st[idx].upd;
        st[2*idx+2].ma = st[idx].upd;
        st[2*idx+2].sum = st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
      else {
        st[2*idx+1].upd += st[idx].upd;
        if(st[2*idx+1].type == '?') st[2*idx+1].type = '+';
        st[2*idx+1].mi += st[idx].upd;
        st[2*idx+1].ma += st[idx].upd;
        st[2*idx+1].sum += st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd += st[idx].upd;
        if(st[2*idx+2].type == '?') st[2*idx+2].type = '+';
        st[2*idx+2].mi += st[idx].upd;
        st[2*idx+2].ma += st[idx].upd;
        st[2*idx+2].sum += st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
    }
    if(mid<l || r<constl) return qu6(l, r, mid+1, constr, 2*idx+2, val);
    else if(constr<l || r<mid+1) return qu6(l, r, constl, mid, 2*idx+1, val);
    else {
      int oho = qu6(l, r, mid+1, constr, 2*idx+2, val);
      if(oho != -1) return oho;
      return qu6(l, r, constl, mid, 2*idx+1, val);
    }
  }
  int qu7(int l, int r, int constl, int constr, int idx, int val) { 

    if(l<=constl && constr<=r) {
      if(st[idx].mi > val) return -1;
      while(constl < constr) {
        int mid = (constl + constr) >> 1;
        if(st[idx].type != '?') {
          if(st[idx].type == ':') {
            st[2*idx+1].upd = st[idx].upd;
            st[2*idx+1].type = ':';
            st[2*idx+1].mi = st[idx].upd;
            st[2*idx+1].ma = st[idx].upd;
            st[2*idx+1].sum = st[idx].upd * (mid - constl + 1);

            st[2*idx+2].upd = st[idx].upd;
            st[2*idx+2].type = ':';
            st[2*idx+2].mi = st[idx].upd;
            st[2*idx+2].ma = st[idx].upd;
            st[2*idx+2].sum = st[idx].upd * (constr - mid);

            st[idx].upd = 0;
            st[idx].type = '?';
            st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
            st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
            st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
          }
          else {
            st[2*idx+1].upd += st[idx].upd;
            if(st[2*idx+1].type == '?') st[2*idx+1].type = '+';
            st[2*idx+1].mi += st[idx].upd;
            st[2*idx+1].ma += st[idx].upd;
            st[2*idx+1].sum += st[idx].upd * (mid - constl + 1);

            st[2*idx+2].upd += st[idx].upd;
            if(st[2*idx+2].type == '?') st[2*idx+2].type = '+';
            st[2*idx+2].mi += st[idx].upd;
            st[2*idx+2].ma += st[idx].upd;
            st[2*idx+2].sum += st[idx].upd * (constr - mid);

            st[idx].upd = 0;
            st[idx].type = '?';
            st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
            st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
            st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
          }
        }
        if(st[2*idx+2].mi <= val) idx = 2*idx + 2, constl = mid + 1;
        else idx = 2*idx + 1, constr = mid;
      }
      return constl;
    }
    int mid = (constl+constr) >> 1;
    if(st[idx].type != '?') {
      if(st[idx].type == ':') {
        st[2*idx+1].upd = st[idx].upd;
        st[2*idx+1].type = ':';
        st[2*idx+1].mi = st[idx].upd;
        st[2*idx+1].ma = st[idx].upd;
        st[2*idx+1].sum = st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd = st[idx].upd;
        st[2*idx+2].type = ':';
        st[2*idx+2].mi = st[idx].upd;
        st[2*idx+2].ma = st[idx].upd;
        st[2*idx+2].sum = st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
      else {
        st[2*idx+1].upd += st[idx].upd;
        if(st[2*idx+1].type == '?') st[2*idx+1].type = '+';
        st[2*idx+1].mi += st[idx].upd;
        st[2*idx+1].ma += st[idx].upd;
        st[2*idx+1].sum += st[idx].upd * (mid - constl + 1);

        st[2*idx+2].upd += st[idx].upd;
        if(st[2*idx+2].type == '?') st[2*idx+2].type = '+';
        st[2*idx+2].mi += st[idx].upd;
        st[2*idx+2].ma += st[idx].upd;
        st[2*idx+2].sum += st[idx].upd * (constr - mid);

        st[idx].upd = 0;
        st[idx].type = '?';
        st[idx].mi = min(st[2*idx+1].mi, st[2*idx+2].mi);
        st[idx].ma = max(st[2*idx+1].ma, st[2*idx+2].ma);
        st[idx].sum = st[2*idx+1].sum + st[2*idx+2].sum;
      }
    }
    if(mid<l || r<constl) return qu7(l, r, mid+1, constr, 2*idx+2, val);
    else if(constr<l || r<mid+1) return qu7(l, r, constl, mid, 2*idx+1, val);
    else {
      int oho = qu7(l, r, mid+1, constr, 2*idx+2, val);
      if(oho != -1) return oho;
      return qu7(l, r, constl, mid, 2*idx+1, val);
    }
  }
  public:
  void resize(int k) {
    stok = k;
    st.resize(4 * k + 10);
  }
  void range_assign(int l, int r, int v) {
    u1(l, r, 0, stok, 0, v);
  }
  void range_add(int l, int r, int v) {
    u2(l, r, 0, stok, 0, v);
  }
  int query_min(int l, int r) {
    return qu1(l, r, 0, stok, 0);
  }
  int query_max(int l, int r) {
    return qu2(l, r, 0, stok, 0);
  }
  int query_sum(int l, int r) {
    return qu3(l, r, 0, stok, 0);
  }
  int query_firstAtLeast(int l, int r, int v) {
    return qu4(l, r, 0, stok, 0, v);
  }
  int query_firstAtMost(int l, int r, int v) {
    return qu5(l, r, 0, stok, 0, v);
  }
  int query_lastAtLeast(int l, int r, int v) {
    return qu6(l, r, 0, stok, 0, v);
  }
  int query_lastAtMost(int l, int r, int v) {
    return qu7(l, r, 0, stok, 0, v);
  }
};
void solve(int tc) {
  int n, k;
  cin >> n >> k;
  int a[n+1];
  int s = 0;
  int ct = 0;
  for(int i=1; i<=n; i++) {
    cin >> a[i];
    s += a[i];
    ct += (a[i] == 0);
  }
  if(abs(s) > k * ct) {
    cout << "-1\n"; return;
  }
  if(s >= 0) {
    int lb = 0, rb = 1e13;
    while(lb < rb) { 
      int mid= (lb+rb+1) >> 1;
      int req = (mid+k-1) / k;
      int rem = mid+s;
      int req2 = (rem+k-1) / k;
      if(req + req2 <= ct) lb = mid;
      else rb = mid-1;
    }
    vector<int> v;
    int sto = lb;
    for(int i=0; i<(lb+k-1)/k; i++) {
      int cost = min(sto, k);
      v.push_back(cost);
      sto -= cost;
    }
    int rem = lb+s;
    sto = rem;
    for(int i=0; i<(rem+k-1)/k; i++) {
      int cost = min(sto, k);
      v.push_back(-cost);
      sto -= cost;
    }
    sort(v.begin(), v.end());
    while(v.size() < ct) v.push_back(0);
    int len = v.size();
    int ans =0 ;
    for(int i=1; i<=n; i++) {
      int maptr = len - 1;
      int miptr = 0; 
      int roll =0 ;
      int misum = 0, masum = 0;
      for(int j=i; j<=n; j++) {
        roll += a[j];
        if(a[j] == 0) {
          masum += v[maptr];
          maptr--;
          misum += v[miptr];
          miptr++;
        }
        ans = max(ans, roll + masum);
        ans = max(ans, -(roll + misum));
      }
    }
    cout << ans +1 << "\n";
  }
  else {
    s = abs(s);
    for(int i=1; i<=n; i++) a[i] = -a[i];
    int lb = 0, rb = 1e13;
    while(lb < rb) { 
      int mid= (lb+rb+1) >> 1;
      int req = (mid+k-1) / k;
      int rem = mid+s;
      int req2 = (rem+k-1) / k;
      if(req + req2 <= ct) lb = mid;
      else rb = mid-1;
    }
    vector<int> v;
    int sto = lb;
    for(int i=0; i<(lb+k-1)/k; i++) {
      int cost = min(sto, k);
      v.push_back(cost);
      sto -= cost;
    }
    int rem = lb+s;
    sto = rem;
    for(int i=0; i<(rem+k-1)/k; i++) {
      int cost = min(sto, k);
      v.push_back(-cost);
      sto -= cost;
    }
    sort(v.begin(), v.end());
    while(v.size() < ct) v.push_back(0);
    int len = v.size();
    int ans =0 ;
    for(int i=1; i<=n; i++) {
      int maptr = len - 1;
      int miptr = 0; 
      int roll =0 ;
      int misum = 0, masum = 0;
      for(int j=i; j<=n; j++) {
        roll += a[j];
        if(a[j] == 0) {
          masum += v[maptr];
          maptr--;
          misum += v[miptr];
          miptr++;
        }
        ans = max(ans, roll + masum);
        ans = max(ans, -(roll + misum));
      }
    }
    cout << ans +1 << "\n";
  }
}
int32_t main() {
  precomp();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1; 

  for(int i=1; i<=t; i++) solve(i);
} 

