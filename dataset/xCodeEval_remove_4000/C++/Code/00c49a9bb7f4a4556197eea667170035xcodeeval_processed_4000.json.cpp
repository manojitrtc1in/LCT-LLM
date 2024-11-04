

 

 



 

































 
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