#pragma "SINITSIN_PITUH"
#include <bits/stdc++.h>
 

 
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target (sse, sse2, sse3, ssse3, sse4,popcnt,tune=native)
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
 
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define CIN   ios_base::sync_with_stdio(0); cin.tie(0)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long int
#define ull unsigned long long int
#define dd long double
#define SZ(a) (int)(a.size())


#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define Unique(x)  x.erase(unique(all(x)), x.end())


#define pf printf
#define sf scanf
#define vec vector
#define mp make_pair
#define paii pair<int, int>
#define padd pair<dd, dd>
#define pall pair<ll, ll>
#define fr first
#define sc second
#define endl "\n"
#define CASE(n) printf("Case %d: ",++n)
#define CASE_COUT cout<<"Case "<<++cas<<": "
#define Harmonic(n) (0.577215664901532+log(n)+(1/(2*n)))   

#define vec vector
 
using namespace std;
 


 
const int MAXN = 15e5+47;
 
struct node{
  int l, r, sum, nw;
  node() {
    l = r = nw =-1;
    sum = 0;
  }
};
 
struct hui{
  int op, l, r;
};
 
node T[4*MAXN];
vec<paii> lol;
 
void build(int l, int r, int i){
  if(l>r) return;
  

  if(l == r) {
    T[i].l = lol[l].fr, T[i].r = lol[l].sc;
    T[i].sum = T[i].r - T[i].l +1;
    return; 
  }  
  int mid=(l+r)/2;
  build(l, mid, i*2);
  build(mid+1, r, i*2+1);
  T[i].l = T[i*2].l, T[i].r = T[i*2+1].r;
  T[i].sum = T[i*2].sum + T[i*2+1].sum;
}
 
void push(int i){
  if(T[i].nw == -1) return;
  T[i].sum = T[i].nw * (T[i].r - T[i].l +1);
  if(T[i].l != T[i].r && i*2+1 < 4*MAXN) {
  T[i*2].nw = T[i].nw;
  T[i*2+1].nw = T[i].nw;
  }
  T[i].nw = -1;
}
 
void update(int l, int r, int op, int i = 1) {
  push(i);
  if(r < T[i].l || T[i].r < l) return;
  if(l <= T[i].l && T[i].r <= r) {
    T[i].nw = op;
    push(i);
    return;
  }
  update(l, r, op, i*2);
  update(l, r, op, i*2+1);
  T[i].sum = T[i*2].sum + T[i*2+1].sum;
}
    
int get(int ind, int i =1){
  push(i);
  if(ind < T[i].l || T[i].r < ind) return 0;
  if(ind == T[i].l && T[i].r == ind) return T[i].sum;
  return get(ind, i*2) + get(ind, i*2+1);
}
 
signed main(){
  CIN;
  int n, m;
  cin >> n >> m;
  vec<hui> q(m);
  vec<int> blu;
  loop(i, m) {
    cin >> q[i].l >> q[i].r >> q[i].op;
    q[i].l--, q[i].r--;
    blu.pb(q[i].l), blu.pb( q[i].r);
  }
  blu.pb(0), blu.pb(n-1);
  sort(all(blu));
  Unique(blu);
  lol.pb(mp(blu[0], blu[0]));
  FOR(i, 1, SZ(blu)) {
   if(blu[i-1] + 1 <= blu[i]-1)lol.pb(mp(blu[i-1]+1, blu[i]-1));
    lol.pb(mp(blu[i], blu[i]));
  }
  build(0, SZ(lol)-1, 1);
  

    
  loop(i, m){
  update(q[i].l, q[i].r, q[i].op-1);
  int ans = T[1].sum;
 
  cout << ans << endl;
  }
}