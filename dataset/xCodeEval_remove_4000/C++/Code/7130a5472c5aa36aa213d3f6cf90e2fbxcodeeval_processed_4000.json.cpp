















































































































































































































































































using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;



struct base {
	ld x, y;
	base() : x(0), y(0) {}
	base(ld a, ld b=0) : x(a), y(b) {}
	base operator/=(ld k) { x/=k; y/=k; return (*this); }
	base operator*(base a) const { return base(x*a.x - y*a.y, x*a.y + y*a.x); }
	base operator*=(base a) {
		ld tx = x*a.x - y*a.y;
		ld ty = x*a.y + y*a.x;
		x = tx; y = ty;
		return (*this);
	}
	base operator+(base a) const { return base(x+a.x, y+a.y); }
	base operator-(base a) const { return base(x-a.x, y-a.y); }
	ld real() { return x; }
	ld imag() { return y; }
};





 
void fft (vector<base> & a, bool invert) {
	int n = (int)a.size();
	for(int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for(; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
 
	for(int len=2; len<=n; len<<=1) {
		ld ang = 2*acosl(-1.0)/len * (invert ? -1 : 1);
		base wlen(cosl(ang), sinl(ang));
		for(int i=0; i<n; i+=len) {
			base w(1);
			for(int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if(invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

void convolution(vector<base> a, vector<base> b, vector<base> & res) {
	int n = 1;
	while(n < max(a.size(), b.size())) n <<= 1;
	n <<= 1;
	a.resize(n), b.resize(n);
	fft(a, false); fft(b, false);
	res.resize(n);
	for(int i=0; i<n; ++i) res[i] = a[i]*b[i];
	fft(res, true);
}





typedef long long ll;

void sqrtConv(vector<ll> a, vector<ll> b, vector<ll> & c) {
	vector<base> ca[2], cb[2], cc[2][2];
	ca[0].resize(a.size());
	ca[1].resize(a.size());
	for(int i=0; i<(int)a.size(); i++) {
		ca[0][i] = base(a[i] % SMOD, 0);
		ca[1][i] = base(a[i] / SMOD, 0);
	}
	cb[0].resize(b.size());
	cb[1].resize(b.size());
	for(int i=0; i<(int)b.size(); i++) {
		cb[0][i] = base(b[i] % SMOD, 0);
		cb[1][i] = base(b[i] / SMOD, 0);
	}
	for(int l=0; l<2; l++) for(int r=0; r<2; r++)
		convolution(ca[l], cb[r], cc[l][r]);
	c.resize(cc[0][0].size());
	for(int i=0; i<(int)c.size(); i++) {
		c[i] =
		ll(cc[1][1][i].real() + 0.5)*SMOD*SMOD +
		ll(cc[0][1][i].real() + 0.5)*SMOD +
		ll(cc[1][0][i].real() + 0.5)*SMOD + 
		ll(cc[0][0][i].real() + 0.5);
	}
}

int a[MAXN];
vector<base> pre, suf, bans;

void solve(vector<ll> & ans, int l, int r) {
	ans.clear();
	if (l == r) {
		ans.assign(2, 0);
		if (a[r] == 1) ans[1] = 1;
		else ans[0] = 1;
		return;
	}
	vector<ll> lh, rh;
	int m = (l + r) / 2;
	solve(lh, l, m);
	solve(rh, m+1, r);
	int cur = 0;
	suf.clear();
	for(int i = m; i >= l; i--) {
		cur += a[i];
		while (cur >= suf.size()) suf.pb(base(0, 0));
		suf[cur].x++;
	}
	cur = 0;
	pre.clear();
	for(int i = m+1; i <= r; i++) {
		cur += a[i];
		while (cur >= pre.size()) pre.pb(base(0, 0));
		pre[cur].x++;
	}
	bans.clear();
	convolution(pre, suf, bans);
	while(ans.size() < bans.size()) ans.pb(0);
	while(ans.size() < lh.size()) ans.pb(0);
	while(ans.size() < rh.size()) ans.pb(0);
	for(int i = 0; i < (int)lh.size(); i++) {
		ans[i] += lh[i];
	}
	for(int i = 0; i < (int)rh.size(); i++) {
		ans[i] += rh[i];
	}
	for(int i = 0; i < (int)bans.size(); i++) {
		ans[i] += ll(bans[i].x + 0.5);
	}
	while(ans.back() == 0) ans.pop_back();
}

int main() {
	

	int n = 200000, x = 1;
	scanf("%d %d", &n, &x);
	FOR(i, n) {
		a[i] = 0;
		scanf("%d", &a[i]);
		a[i] = (a[i] < x ? 1 : 0);
	}
	vector<ll> ans;
	solve(ans, 0, n-1);
	

	

	FOR(i, n+1) {
		if (i < (int)ans.size()) printf("%lld ", ans[i]);
		else printf("0 ");
	}
	return 0;
}