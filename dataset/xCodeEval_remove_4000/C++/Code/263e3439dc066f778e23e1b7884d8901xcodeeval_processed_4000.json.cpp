
















































using namespace std;



const int inf = 1e9+47, mod = 1e9+9, MAXN = 27;








int n, middle;
vec<paiii> miss;

void read() {
  cin >> n;
  miss.resize(n);
  loop(i, n) cin >> miss[i].al >> miss[i].bl >> miss[i].cl;
}

map<paiii, paii> hsh;

void solve(){
  middle = n/2;
  int stp = 1;
  loop(i, middle) stp *= 3;
  loop(mask, stp) {
int id0 = mask, x = 0, y = 0, z = 0;
loop(i, middle) {
  int op = id0 % 3;
  id0 /= 3;
  if(op == 0) {
x += miss[i].al;
y += miss[i].bl;
  }
  if(op == 1) {
x += miss[i].al;
z += miss[i].cl;    
  }
  if(op == 2) {
y += miss[i].bl;
z += miss[i].cl;    
  }
}
  
  int mn = min(x, min(y, z));
  x -= mn, y -= mn, z -= mn;
  paiii temp;
  temp.al = x, temp.bl = y, temp.cl = z;
  if(hsh.find(temp) == hsh.end()) hsh[temp] = mp(mn, mask);
  else {
    if(hsh[temp].first <= mn) hsh[temp] = mp(mn, mask);
  }
  }


  int s2 = 1;
  int ans = -inf, print=-1;
  loop(i, n - middle) s2 *= 3;
  loop(mask, s2) {
int id0 = mask, x = 0, y = 0, z = 0;
loop(i, n-middle) {
  int op = id0 % 3;
  id0 /= 3;
  if(op == 0) {
x += miss[i+middle].al;
y += miss[i+middle].bl;
  }
  if(op == 1) {
x += miss[i+middle].al;
z += miss[i+middle].cl;    
  }
  if(op == 2) {
y += miss[i+middle].bl;
z += miss[i+middle].cl;    
  }
}
  
  int mn = min(x, min(y, z));
  x -= mn, y -= mn, z -= mn;
  paiii temp;
  int mx = max(x, max(y, z));
  x = mx - x, y = mx - y, z = mx - z;
  temp.al = x, temp.bl = y, temp.cl = z;
 

  if(hsh.find(temp) == hsh.end()) continue;
  else {
    if(hsh[temp].first + temp.al + mn + mx-x> ans) ans = hsh[temp].first + temp.al + mn + mx - x, print = hsh[temp].second  + mask*stp;
  }
  }
 

  if(print == -1) {
      cout << "Impossible"<<endl;
      return ;  
  }
  loop(i, n) {
int op = print % 3;
print /= 3;
if(op == 0) cout << "LM\n";
if(op == 1) cout << "LW\n";
if(op == 2) cout << "MW\n";
  }
  

}

signed main(){ 
  CIN;
  read();
  solve();
}