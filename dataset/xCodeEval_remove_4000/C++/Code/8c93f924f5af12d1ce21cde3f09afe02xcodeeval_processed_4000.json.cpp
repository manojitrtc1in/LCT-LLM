

using namespace std;



namespace fft {
using ll = long long;
using vi = vector<int>;









using dbl = double;
struct num { 

	dbl x, y;
	num(dbl x_ = 0, dbl y_ = 0) : x(x_), y(y_) { }
};
inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
inline num conj(num a) { return num(a.x, -a.y); }
inline num inv(num a) { dbl n = (a.x*a.x+a.y*a.y); return num(a.x/n,-a.y/n); }





const int mod = 998244353, g = 3;




struct num { 

	int v;
	num(ll v_ = 0) : v(int(v_ % mod)) { if (v<0) v+=mod; }
	explicit operator int() const { return v; }
};
inline num operator+(num a,num b){return num(a.v+b.v);}
inline num operator-(num a,num b){return num(a.v+mod-b.v);}
inline num operator*(num a,num b){return num(1ll*a.v*b.v);}
inline num pow(num a, int b) {
	num r = 1;
	do{if(b&1)r=r*a;a=a*a;}while(b>>=1);
	return r;
}
inline num inv(num a) { return pow(a, mod-2); }




using vn = vector<num>;
vi rev({0, 1});
vn rt(2, num(1)), fa, fb;

inline void init(int n) { 

	if (n <= sz(rt)) return;
	rev.resize(n);
	rep(i,0,n) rev[i] = (rev[i>>1] | ((i&1)*n)) >> 1;
	rt.reserve(n);
	for (int k = sz(rt); k < n; k *= 2) {
		rt.resize(2*k);

		double a=M_PI/k; num z(cos(a),sin(a)); 


		num z = pow(num(g), (mod-1)/(2*k)); 


		rep(i,k/2,k) rt[2*i] = rt[i], rt[2*i+1] = rt[i]*z;
	}
} 


inline void fft(vector<num> &a, int n) { 

	init(n);
	int s = __builtin_ctz(sz(rev)/n);
	rep(i,0,n) if (i < rev[i]>>s) swap(a[i], a[rev[i]>>s]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			num t = rt[j+k] * a[i+j+k];
			a[i+j+k] = a[i+j] - t;
			a[i+j] = a[i+j] + t;
		}
} 




vn multiply(vn a, vn b) { 

	int s = sz(a) + sz(b) - 1;
	if (s <= 0) return {};
	int L = s > 1 ? 32 - __builtin_clz(s-1) : 0, n = 1 << L;
	a.resize(n), b.resize(n);
	fft(a, n);
	fft(b, n);
	num d = inv(num(n));
	rep(i,0,n) a[i] = a[i] * b[i] * d;
	reverse(a.begin()+1, a.end());
	fft(a, n);
	a.resize(s);
	return a;
} 






vn inverse(const vn& a) { 

	if (a.empty()) return {};
	vn b({inv(a[0])});
	b.reserve(2*a.size());
	while (sz(b) < sz(a)) {
		int n = 2*sz(b);
		b.resize(2*n, 0);
		if (sz(fa) < 2*n) fa.resize(2*n);
		fill(fa.begin(), fa.begin()+2*n, 0);
		copy(a.begin(), a.begin()+min(n,sz(a)), fa.begin());
		fft(b, 2*n);
		fft(fa, 2*n);
		num d = inv(num(2*n));
		rep(i, 0, 2*n) b[i] = b[i] * (2 - fa[i] * b[i]) * d;
		reverse(b.begin()+1, b.end());
		fft(b, 2*n);
		b.resize(n);
	}
	b.resize(a.size());
	return b;
} 





using vd = vector<double>;
vd multiply(const vd& a, const vd& b) { 

	int s = sz(a) + sz(b) - 1;
	if (s <= 0) return {};
	int L = s > 1 ? 32 - __builtin_clz(s-1) : 0, n = 1 << L;
	if (sz(fa) < n) fa.resize(n);
	if (sz(fb) < n) fb.resize(n);

	fill(fa.begin(), fa.begin() + n, 0);
	rep(i,0,sz(a)) fa[i].x = a[i];
	rep(i,0,sz(b)) fa[i].y = b[i];
	fft(fa, n);
	trav(x, fa) x = x * x;
	rep(i,0,n) fb[i] = fa[(n-i)&(n-1)] - conj(fa[i]);
	fft(fb, n);
	vd r(s);
	rep(i,0,s) r[i] = fb[i].y / (4*n);
	return r;
} 




vi multiply_mod(const vi& a, const vi& b, int m) {
	int s = sz(a) + sz(b) - 1;
	if (s <= 0) return {};
	int L = s > 1 ? 32 - __builtin_clz(s-1) : 0, n = 1 << L;
	if (sz(fa) < n) fa.resize(n);
	if (sz(fb) < n) fb.resize(n);

	rep(i,0,sz(a)) fa[i] = num(a[i] & ((1<<15)-1), a[i] >> 15);
	fill(fa.begin()+sz(a), fa.begin() + n, 0);
	rep(i,0,sz(b)) fb[i] = num(b[i] & ((1<<15)-1), b[i] >> 15);
	fill(fb.begin()+sz(b), fb.begin() + n, 0);

	fft(fa, n);
	fft(fb, n);
	double r0 = 0.5 / n; 

	rep(i,0,n/2+1) {
		int j = (n-i)&(n-1);
		num g0 = (fb[i] + conj(fb[j])) * r0;
		num g1 = (fb[i] - conj(fb[j])) * r0;
		swap(g1.x, g1.y); g1.y *= -1;
		if (j != i) {
			swap(fa[j], fa[i]);
			fb[j] = fa[j] * g1;
			fa[j] = fa[j] * g0;
		}
		fb[i] = fa[i] * conj(g1);
		fa[i] = fa[i] * conj(g0);
	}
	fft(fa, n);
	fft(fb, n);
	vi r(s);
	rep(i,0,s) r[i] = int((ll(fa[i].x+0.5)
				+ (ll(fa[i].y+0.5) % m << 15)
				+ (ll(fb[i].x+0.5) % m << 15)
				+ (ll(fb[i].y+0.5) % m << 30)) % m);
	return r;
} 



} 




using fft::num;
using poly = fft::vn;
using fft::multiply;
using fft::inverse;


poly& operator+=(poly& a, const poly& b) {
	if (sz(a) < sz(b)) a.resize(b.size());
	rep(i,0,sz(b)) a[i]=a[i]+b[i];
	return a;
}
poly operator+(const poly& a, const poly& b) { poly r=a; r+=b; return r; }
poly& operator-=(poly& a, const poly& b) {
	if (sz(a) < sz(b)) a.resize(b.size());
	rep(i,0,sz(b)) a[i]=a[i]-b[i];
	return a;
}
poly operator-(const poly& a, const poly& b) { poly r=a; r-=b; return r; }
poly operator*(const poly& a, const poly& b) {
	

	return multiply(a, b);
}
poly& operator*=(poly& a, const poly& b) {return a = a*b;}


poly& operator*=(poly& a, const num& b) { 

	trav(x, a) x = x * b;
	return a;
}
poly operator*(const poly& a, const num& b) { poly r=a; r*=b; return r; }



poly operator/(poly a, poly b) { 

	if (sz(a) < sz(b)) return {};
	int s = sz(a)-sz(b)+1;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	a.resize(s);
	b.resize(s);
	a = a * inverse(move(b));
	a.resize(s);
	reverse(a.begin(), a.end());
	return a;
} 

poly& operator/=(poly& a, const poly& b) {return a = a/b;}
poly& operator%=(poly& a, const poly& b) { 

	if (sz(a) >= sz(b)) {
		poly c = (a / b) * b;
		a.resize(sz(b)-1);
		rep(i,0,sz(a)) a[i] = a[i]-c[i];
	}
	return a;
} 

poly operator%(const poly& a, const poly& b) { poly r=a; r%=b; return r; }



poly deriv(const poly& a) { 

	if (a.empty()) return {};
	poly b(sz(a)-1);
	rep(i,1,sz(a)) b[i-1]=a[i]*i;
	return b;
} 

poly integ(const poly& a) { 

	poly b(sz(a)+1);
	b[1]=1; 

	rep(i,2,sz(b)) b[i]=b[fft::mod%i]*(-fft::mod/i); 

	rep(i,1,sz(b)) b[i]=a[i-1]*b[i]; 

	

	return b;
} 

poly log(const poly& a) { 

	poly b = integ(deriv(a)*inverse(a));
	b.resize(a.size());
	return b;
} 

poly exp(const poly& a) { 

	poly b(1,num(1));
	if (a.empty()) return b;
	while (sz(b) < sz(a)) {
		int n = min(sz(b) * 2, sz(a));
		b.resize(n);
		poly v = poly(a.begin(), a.begin() + n) - log(b);
		v[0] = v[0]+num(1);
		b *= v;
		b.resize(n);
	}
	return b;
} 

poly pow(const poly& a, int m) { 

	poly b(a.size());
	if (!m) { b[0] = 1; return b; }
	int p = 0;
	while (p<sz(a) && a[p].v==0) ++p;
	if (1ll*m*p >= sz(a)) return b;
	num mu = pow(a[p], m), di = inv(a[p]);
	poly c(sz(a) - m*p);
	rep(i,0,sz(c)) c[i] = a[i+p] * di;
	c = log(c);
	trav(v,c) v = v * m;
	c = exp(c);
	rep(i,0,sz(c)) b[i+m*p] = c[i] * mu;
	return b;
} 






vector<num> eval(const poly& a, const vector<num>& x) {
	int n=sz(x);
	if (!n) return {};
	vector<poly> up(2*n);
	rep(i,0,n) up[i+n] = poly({0-x[i], 1});
	per(i,1,n) up[i] = up[2*i]*up[2*i+1];
	vector<poly> down(2*n);
	down[1] = a % up[1];
	rep(i,2,2*n) down[i] = down[i/2] % up[i];
	vector<num> y(n);
	rep(i,0,n) y[i] = down[i+n][0];
	return y;
} 



poly interp(const vector<num>& x, const vector<num>& y) {
	int n=sz(x);
	assert(n);
	vector<poly> up(n*2);
	rep(i,0,n) up[i+n] = poly({0-x[i], 1});
	per(i,1,n) up[i] = up[2*i]*up[2*i+1];
	vector<num> a = eval(deriv(up[1]), x);
	vector<poly> down(2*n);
	rep(i,0,n) down[i+n] = poly({y[i]*inv(a[i])});
	per(i,1,n) down[i] = down[i*2] * up[i*2+1] + down[i*2+1] * up[i*2];
	return down[1];
} 


int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, K; num P; cin >> N >> K >> P.v;
	std::vector<num> A(N);
	for (auto& a : A) cin >> a.v;

	std::vector<num> fact(K+1);
	fact[0] = 1;
	for (int i = 1; i <= K; i++) fact[i] = fact[i-1] * num(i);
	std::vector<num> ifact(K+1);
	ifact[K] = inv(fact[K]);
	for (int i = K; i > 0; i--) ifact[i-1] = ifact[i] * num(i);
	std::vector<num> pow_P(K+1);
	pow_P[0] = 1;
	for (int i = 1; i <= K; i++) pow_P[i] = pow_P[i-1] * P;

	std::vector<num> id0(K+1);
	num id1 = inv(P-1);
	id0[0] = 1;
	for (int i = 1; i <= K; i++) {
		id0[i] = ifact[i] * num(P) * id1;
	}
	id0 = inverse(id0);
	for (int i = 0; i <= K; i++) id0[i] = id0[i] * id1;

	std::vector<num> my_poly(K+1);
	for (int i = 0; i <= K; i++) {
		my_poly[i] = id0[K-i] * ifact[i] * fact[K];
	}
	auto xs = A;
	for (auto& v : xs) v = v + 1;
	auto resp = eval(my_poly, xs);
	for (int i = 0; i < N; i++) {
		resp[i] = resp[i] * pow(P, int(A[i]) + 1) - my_poly[0];
	}

	std::vector<std::array<num, 2>> pref(N+1);
	pref[0] = {num(1), num(0)};
	for (int i = 0; i < N; i++) {
		pref[i+1][0] = pref[i][0] * (A[i]+1) + num(1);
		pref[i+1][1] = pref[i][1] * (A[i]+1) + pref[i][0] * A[i];
	}
	std::vector<std::array<num, 2>> suff(N+1);
	suff[N] = {num(1), num(0)};
	for (int i = N-1; i >= 0; i--) {
		suff[i][0] = suff[i+1][0] * (A[i]+1) + num(1);
		suff[i][1] = suff[i+1][1] * (A[i]+1) + suff[i+1][0] * A[i];
	}

	num ans = 0;
	for (int i = 0; i < N; i++) {
		

		num weight = pref[i][0] * suff[i+1][0] + pref[i][1] * suff[i+1][0] + pref[i][0] * suff[i+1][1];
		ans = ans + weight * resp[i];
	}
	cout << ans.v << '\n';

	return 0;
}