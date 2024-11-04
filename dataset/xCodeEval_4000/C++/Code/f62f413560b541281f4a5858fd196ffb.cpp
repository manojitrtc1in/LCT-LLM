#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb emplace_back
#define x first
#define y second
#define sz(a) ((int)(a).size())
#define rep(i,a,b) for(auto i=(a); i<(b); i++)
#define dec(i,n,a) for(auto i=(n); i>=(a); i--)
#define clr(a,v) memset(a, v, sizeof(a))
#define all(a) (a).begin(),(a).end()
#define EPS 2e-9
#define fcin ios_base::sync_with_stdio(false)
#define db(x) cerr << #x << " == " << x << endl
#define _ << " " <<
#define MAXN 202020
#define LOGN 20
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;



const unsigned int mod = 1000000007;
struct mod_int{
	ll val;
	mod_int():val(0){}
	mod_int(ll X):val((X%mod + mod)%mod){}
	mod_int operator+(mod_int a){ return (val+a.val)%mod; }
	mod_int operator-(mod_int a){ return (val-a.val+mod)%mod; }
	mod_int operator*(mod_int a){ return (val*a.val)%mod; }
};

struct frac{
	mod_int a, b;
	frac():a(0),b(1){}
	frac(mod_int x):a(x),b(1){}
	frac(mod_int A, mod_int B):a(A),b(B){}
	frac operator+(frac A){ return frac(a*A.b + b*A.a, b*A.b); }
	frac operator-(frac A){ return frac(a*A.b - b*A.a, b*A.b); }
	frac operator*(frac A){ return frac(a*A.a, b*A.b); }
};

mod_int mod_pow(mod_int b, ll e){
	mod_int ret(1);
	while(e>0){
		if(e&1) ret = ret*b;
		b = b*b;
		e >>= 1;
	}
	return ret;
}

mod_int inv(mod_int x){ return mod_pow(x, mod-2); }

int n, m, sa[MAXN], sb[MAXN];
frac pd[MAXN];

int main(){
	scanf("%d%d", &n, &m);
	rep(i,0,n) scanf("%d", sa+i);
	rep(i,0,n) scanf("%d", sb+i);
	dec(i,n-1,0){
		if(sa[i] && sb[i]){
			if(sa[i] > sb[i])
				pd[i] = frac(1);
			else if(sa[i] == sb[i])
				pd[i] = pd[i+1];
			else pd[i] = frac(0);
		}else if(sa[i])
			pd[i] = frac(sa[i]-1,m) + frac(1,m)*pd[i+1];
		else if(sb[i])
			pd[i] = frac(m-sb[i], m) + frac(1,m)*pd[i+1];
		else
			pd[i] = frac(((ll)m*m - m)/2, (ll)m*m) + frac(m, (ll)m*m)*pd[i+1];
	}
	cout << (pd[0].a*inv(pd[0].b)).val << endl;
}
