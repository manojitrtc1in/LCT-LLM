#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1.)

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define REP(i,n) for(int i=0; i < (n); ++i)
#define SIZE(c) (int) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define FWD(i,a,b) for (int i=(a); i<(b); ++i)
#define BCK(i,a,b) for (int i=(a); i>(b); --i)
#define pb push_back
#define mp make_pair
#define st first
#define nd second

using namespace std;



















































  










  










  










  












  








  








  



 










































 





















  


























































  














  
























  






































































  
















  


























  






  




































  










  












































typedef long long int LLI;
typedef pair < int , int > PII;
typedef pair < LLI , LLI > PLL;

typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector <double> VD;
typedef vector < PII > VP;
typedef vector < LLI > VL;
typedef vector < PLL > VPL;

typedef vector < VI > VVI;
typedef vector < VL > VVL;
typedef vector < VB > VVB;
typedef vector < VP > VVP;

typedef double K;
typedef complex<K> CK;

const int MAXM = 1024;



vector<K> er, ei;
void FFT(vector<K> &xr, vector<K> &xi, K d = 1) {
int n = SIZE(xr); er.resize(n), ei.resize(n);
FWD(i,0,n) er[i] = cos(2*PI*i/n), ei[i] = -d*sin(2*PI*i/n);
FWD(i,0,n) {
int j=0; for(int k=1; k<n; k<<=1, j<<=1) if(k&i) j++;
j>>=1; if(i<j) { swap(xr[i], xr[j]); swap(xi[i], xi[j]); } 
}
int k=0;
while((1<<k)<n) k++;
for(int s=1; s<n; s<<=1){
--k;
for(int i=0; i<n; i+=2*s) FWD(j,0,s){
K ur = xr[i+j], ui = xi[i + j];
K vr = xr[i+j+s]*er[j<<k] - xi[i+j+s]*ei[j<<k], vi = xr[i+j+s]*ei[j<<k] + xi[i + j + s]*er[j<<k];
xr[i+j] = ur + vr, xi[i + j] = ui + vi;
xr[i+j+s] = ur - vr, xi[i+j+s] = ui - vi;
}
}
}

pair<VD, VD> convolution(VD ar, VD ai, VD br, VD bi) {
int n = 1; while(n < SIZE(ar)) n *= 2;
FFT(ar, ai); FFT(br, bi); 
FWD(i,0,n) {
  K ur = (ar[i] * br[i] - ai[i] * bi[i]) / n;
  K ui = (ar[i] * bi[i] + ai[i] * br[i]) / n;
  ar[i] = ur, ai[i] = ui; 
}
FFT(ar, ai, -1);
return { ar, ai };
}


int main()
{
  ios_base::sync_with_stdio(0);

  cout << fixed << setprecision(40);

  int n, m;
  cin >> n >> m;

  if (m == 1) { cout << "1.0\n"; return 0; }

  VI val(n);
  REP(i, n) cin >> val[i];

  vector<VD> res;

  REP(i, n) {
    VD mult(MAXM);
    FOR(pos,1,m) {
      if (pos == val[i]) {
        mult[pos] = 0;
      } else {
        mult[pos] = 1. / (m - 1);
      }
    }
    res.pb(mult);
  }

  int bound = MAXM;
  while (SIZE(res) > 1) {
    REP(i,SIZE(res) / 2) {
      VD con(2 * bound);
      VD ar(2 * bound), ai(2 * bound), br(2 * bound), bi(2 * bound);
      REP(j,bound) ar[j] = res[2*i][j], br[j] = res[2*i+1][j];
      con = convolution(ar, ai, br, bi).first;
      res[i] = con;
    }
    if (SIZE(res) % 2) {
      res[SIZE(res) / 2] = VD(2 * bound);
      REP(j, bound) res[SIZE(res) / 2][j] = res[SIZE(res) - 1][j];
    }
    res.resize((SIZE(res) + 1) / 2);
    bound *= 2;
  }

  int sum = 0;
  REP(i,n) sum += val[i];

  const auto& vec = res[0];
  double ans = 0;
  REP(i,sum) ans += vec[i];

  ans = 1 + ans * (m - 1);

  cout << ans << endl;

  return 0;
}

