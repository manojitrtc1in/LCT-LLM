#pragma "SINITSIN_PITUH"
#include <bits/stdc++.h>










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






#define CASE(n) printf("Case %d: ",++n)
#define CASE_COUT cout<<"Case "<<++cas<<": "
#define Harmonic(n) (0.577215664901532+log(n)+(1/(2*n)))   

#define vec vector

using namespace std;

#define int long long

const int inf = 1e9+47, mod = 1e9+9, MAXN = 27;



#define paiii pair<int, pair<int, int> >
#define al first
#define bl second.first
#define cl second.second

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
int dlina_huia = mask, x = 0, y = 0, z = 0;
loop(i, middle) {
  int op = dlina_huia % 3;
  dlina_huia /= 3;
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
int dlina_huia = mask, x = 0, y = 0, z = 0;
loop(i, n-middle) {
  int op = dlina_huia % 3;
  dlina_huia /= 3;
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