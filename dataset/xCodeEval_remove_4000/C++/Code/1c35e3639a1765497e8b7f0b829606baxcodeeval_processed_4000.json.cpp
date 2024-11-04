








using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }




	for(auto v: x) cerr << v << ","; cerr << "}" << endl;





template<unsigned int mod_>
struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

	constexpr static uint mod = mod_;

	uint v;
	ModInt():v(0){}
	ModInt(ll _v):v(normS(_v%mod+mod)){}
	explicit operator bool() const {return v!=0;}
	static uint normS(const uint &x){return (x<mod)?x:x-mod;}		

	static ModInt make(const uint &x){ModInt m; m.v=x; return m;}
	ModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}
	ModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}
	ModInt operator-() const { return make(normS(mod-v)); }
	ModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}
	ModInt operator/(const ModInt& b) const { return *this*b.inv();}
	ModInt& operator+=(const ModInt& b){ return *this=*this+b;}
	ModInt& operator-=(const ModInt& b){ return *this=*this-b;}
	ModInt& operator*=(const ModInt& b){ return *this=*this*b;}
	ModInt& operator/=(const ModInt& b){ return *this=*this/b;}
	ModInt& operator++(int){ return *this=*this+1;}
	ModInt& operator--(int){ return *this=*this-1;}
	ll extgcd(ll a,ll b,ll &x,ll &y) const{
		ll p[]={a,1,0},q[]={b,0,1};
		while(*q){
			ll t=*p/ *q;
			rep(i,3) swap(p[i]-=t*q[i],q[i]);
		}
		if(p[0]<0) rep(i,3) p[i]=-p[i];
		x=p[1],y=p[2];
		return p[0];
	}
	ModInt inv() const {
		ll x,y;
		extgcd(v,mod,x,y);
		return make(normS(x+mod));
	}
	ModInt pow(ll p) const {
		if(p<0) return inv().pow(-p);
		ModInt a = 1;
		ModInt x = *this;
		while(p){
			if(p&1) a *= x;
			x *= x;
			p >>= 1;
		}
		return a;
	}
	bool operator==(const ModInt& b) const { return v==b.v;}
	bool operator!=(const ModInt& b) const { return v!=b.v;}
	friend istream& operator>>(istream &o,ModInt& x){
		ll tmp;
		o>>tmp;
		x=ModInt(tmp);
		return o;
	}
	friend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}
};
using mint = ModInt<998244353>;

int bsr(int x) { return 31 - __builtin_clz(x); }
using D = double;
const D pi = acos(-1);
using Pc = complex<D>;

void fft(bool type, vector<Pc> &c){	

	static vector<Pc> buf[30];
	int N = c.size();
	int s = bsr(N);
	assert(1<<s == N);
	if(buf[s].empty()){
		buf[s]=vector<Pc>(N);
		rep(i,N) buf[s][i] = polar<D>(1,i*2*pi/N);
	}
	vector<Pc> a(N),b(N);
	copy(begin(c),end(c),begin(a));
	rep1(i,s){
		int W = 1<<(s-i);
		for(int y=0;y<N/2;y+=W){
			Pc now = buf[s][y];
			if(type) now = conj(now);
			rep(x,W){
				auto l =       a[y<<1 | x];
				auto r = now * a[y<<1 | x | W];
				b[y | x]        = l+r;
				b[y | x | N>>1] = l-r;
			}
		}
		swap(a,b);
	}
	copy(begin(a),end(a),begin(c));
}
template<class Mint>
vector<Mint> id4(const vector<Mint>& x,const vector<Mint>& y){
	const int B = 15;
	int S = x.size()+y.size()-1;
	int N = 2<<bsr(S-1);
	vector<Pc> a[2],b[2];
	rep(t,2){
		a[t] = vector<Pc>(N);
		b[t] = vector<Pc>(N);
		rep(i,x.size()) a[t][i] = Pc( (x[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		rep(i,y.size()) b[t][i] = Pc( (y[i].v >> (t*B)) & ((1<<B)-1) , 0 );
		fft(false,a[t]);
		fft(false,b[t]);
	}
	vector<Mint> z(S);
	vector<Pc> c(N);
	Mint base = 1;
	rep(t,3){
		fill_n(begin(c),N,Pc(0,0));
		for(int xt = max(t-1,0); xt<=min(1,t); xt++){
			int yt = t-xt;
			rep(i,N) c[i] += a[xt][i]*b[yt][i];
		}
		fft(true,c);
		rep(i,S){
			c[i] *= 1.0/N;
			z[i] += Mint(ll(round(c[i].real()))) * base;
		}
		base *= 1<<B;
	}
	return z;
}
template<class Mint>
vector<Mint> multiply_fft(const vector<Mint>& x,const vector<Mint>& y){
	return id4(x,y);
}


template<class D>
struct Poly{
	vector<D> v;
	int size() const{ return v.size();}	

	Poly(int N=0) : v(vector<D>(N)){}
	Poly(vector<D> v) : v(v){shrink();}

	Poly& shrink(){
		while(!v.empty()&&v.back()==D(0)) v.pop_back();	

		return *this;
	}
	D at(int i) const{
		return (i<size())?v[i]:D(0);
	}
	void set(int i,const D& x){		

		if(i>=size() && !x) return;
		while(i>=size()) v.push_back(D(0));
		v[i]=x;
		shrink();
		return;
	}
	
	Poly operator+(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)+r.at(i);
		return Poly(ret);
	}
	Poly operator-(const Poly &r) const{
		int N=max(size(),r.size());
		vector<D> ret(N);
		rep(i,N) ret[i]=at(i)-r.at(i);
		return Poly(ret);
	}
	Poly operator-() const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i] = -at(i);
		return Poly(ret);
	}
	Poly operator*(const Poly &r) const{
		if(size()==0||r.size()==0) return Poly();
		return mul_fft(r);
	}
	Poly operator*(const D &r) const{
		int N=size();
		vector<D> ret(N);
		rep(i,N) ret[i]=v[i]*r;
		return Poly(ret);
	}
	Poly operator/(const Poly &y) const{
		return div_fast(y);
	}
	Poly operator%(const Poly &y) const{
		return rem_fast(y);


	}
	Poly operator<<(const int &n) const{	

		assert(n>=0);
		int N=size();
		vector<D> ret(N+n);
		rep(i,N) ret[i+n]=v[i];
		return Poly(ret);
	}
	Poly operator>>(const int &n) const{	

		assert(n>=0);
		int N=size();
		if(N<=n) return Poly();
		vector<D> ret(N-n);
		rep(i,N-n) ret[i]=v[i+n];
		return Poly(ret);
	}
	bool operator==(const Poly &y) const{
		return v==y.v;
	}
	bool operator!=(const Poly &y) const{
		return v!=y.v;
	}

	Poly& operator+=(const Poly &r) {return *this = *this+r;}
	Poly& operator-=(const Poly &r) {return *this = *this-r;}
	Poly& operator*=(const Poly &r) {return *this = *this*r;}
	Poly& operator*=(const D &r) {return *this = *this*r;}
	Poly& operator%=(const Poly &y) {return *this = *this%y;}
	Poly& operator<<=(const int &n) {return *this = *this<<n;}
	Poly& operator>>=(const int &n) {return *this = *this>>n;}


	Poly mul_naive(const Poly &r) const{
		int N=size(),M=r.size();
		vector<D> ret(N+M-1);
		rep(i,N) rep(j,M) ret[i+j]+=at(i)*r.at(j);
		return Poly(ret);
	}
	Poly mul_ntt(const Poly &r) const{
		return Poly(multiply_ntt(this->v,r.v));
	}
	Poly mul_fft(const Poly &r) const{
		vector<D> ret = multiply_fft(v,r.v);
		return Poly(ret);
	}

	Poly div_fast_with_inv(const Poly &inv, int B) const {
		return (*this * inv)>>(B-1);
	}
	Poly div_fast(const Poly &y) const{
		if(size()<y.size()) return Poly();
		int n = size();
		return div_fast_with_inv(y.inv(n),n);
	}
	Poly rem_naive(const Poly &y) const{
		Poly x = *this;
		while(y.size()<=x.size()){
			int N=x.size(),M=y.size();
			D coef = x.v[N-1]/y.v[M-1];
			x -= (y<<(N-M))*coef;
		}
		return x;
	}
	Poly rem_fast(const Poly &y) const{
		return *this - y * div_fast(y);
	}
	Poly strip(int n) const {	

		vector<D> res = v;
		res.resize(min(n,size()));
		return Poly(res);
	}
	Poly rev(int n = -1) const {	

		vector<D> res = v;
		if(n!=-1) res.resize(n);
		reverse(all(res));
		return Poly(res);
	}
	Poly inv(int n) const{		

		int N = size();
		assert(N>=1);		

		assert(n>=N-1);		

		D coef = D(1)/at(N-1);
		Poly a = rev();
		Poly g(vector<D>(1,coef));
		for(int i=1; i+N-2<n; i*=2){		

			g *= (Poly(vector<D>{2})-a*g).strip(2*i);
		}
		return g.rev(n+1-N);
	}

	friend ostream& operator<<(ostream &o,const Poly& x){
		if(x.size()==0) return o<<0;
		rep(i,x.size()) if(x.v[i]!=D(0)){
			o<<x.v[i]<<"x^"<<i;
			if(i!=x.size()-1) o<<" + ";
		}
		return o;
	}
};
V<mint> fact,ifact;
mint Choose(int a,int b){
	if(b<0 || a<b) return 0;
	return fact[a] * ifact[b] * ifact[a-b];
}
void InitFact(int N){
	fact.resize(N);
	ifact.resize(N);
	fact[0] = 1;
	rep1(i,N-1) fact[i] = fact[i-1] * i;
	ifact[N-1] = fact[N-1].inv();
	for(int i=N-2;i>=0;i--) ifact[i] = ifact[i+1] * (i+1);
}

template<class D>
Poly<D> id0(const vector<D> &u){
	int N = u.size();
	vector<D> b = {D(-1)}, c = {D(-1)};
	D y = D(1);
	rep1(n,N){
		int L = c.size(), M = b.size();
		D x = 0;
		rep(i,L) x += c[i]*u[n-L+i];
		b.pb(0);
		M++;
		if(!x) continue;
		D coef = x/y;
		if(L<M){
			auto tmp = c;
			c.insert(begin(c),M-L,D(0));
			rep(i,M) c[M-1-i] -= coef*b[M-1-i];
			b=tmp;
			y=x;
		}else{
			rep(i,M) c[L-1-i] -= coef*b[M-1-i];
		}
	}
	return Poly<D>(c);
}

vector<mint> extended(int n, const vector< vector<mint> >& coeffs, const vector<mint>& terms) {

	vector<mint> ret(max<int>(n + 1, terms.size()));
	copy(terms.begin(), terms.end(), ret.begin());
	const int order = coeffs.size() - 1;
	const int deg = coeffs[0].size() - 1;
	assert((int) terms.size() >= order);
	for (int m = terms.size(); m <= n; ++m) {
		mint s = 0;
		for (int i = 1; i <= order; ++i) {
			int k = m - i;
			mint t = ret[k];
			for (int d = 0; d <= deg; ++d) {
				s += t * coeffs[i][d];
				t *= k;
			}
		}
		mint denom = 0, mpow = 1;
		for (int d = 0; d <= deg; ++d) {
			denom += mpow * coeffs[0][d];
			mpow *= m;
		}
		ret[m] = -s/denom;
	}
	return ret;
}

vector< vector<mint> > id3(vector<mint> terms, int deg, int ord = -1, bool verify=true) {

	if(ord != -1){		

		int n = (deg+1)*(ord+1)+ord-1;
		while((int)terms.size()>n) terms.pop_back();
	}

	const int n = terms.size();
	const int B = (n + 2) / (deg + 2); 

	const int C = B * (deg + 1); 

	const int R = n - (B - 1); 

	assert(B >= 2); assert(R >= C - 1);

	auto error = [] (int order, int deg) {
		fprintf(stderr, 
			"Error: Could not find a recurrence relation "
			"of order <= %d and degree <= %d.\n\n", 
			order, deg);
		assert(0);
	};

	vector< vector<mint> > mat(R, vector<mint>(C));
	for (int y = 0; y < R; ++y) {
		for (int b = 0; b < B; ++b) {
			mint v = terms[y+b];
			for (int d = 0; d <= deg; ++d) {
				mat[y][b * (deg + 1) + d] = v;
				v *= y+b;
			}
		}
	}

	int rank = 0;
	for (int x = 0; x < C; ++x) {
		int pivot = -1;
		for (int y = rank; y < R; ++y) if (mat[y][x] != 0) {
			pivot = y; break;
		}
		if (pivot < 0) break;
		if (pivot != rank) swap(mat[rank], mat[pivot]);
		mint inv = mat[rank][x].inv();
		for (int x2 = x; x2 < C; ++x2) mat[rank][x2] *= inv;
		for (int y = rank + 1; y < R; ++y) if (mat[y][x]) {
			mint c = -mat[y][x];
			for (int x2 = x; x2 < C; ++x2) {
				mat[y][x2] += c * mat[rank][x2];
			}
		}
		++rank;
	}

	if (rank == C) error(B - 1, deg);

	for (int y = rank - 1; y >= 0; --y) if (mat[y][rank]) {
		assert(mat[y][y] == 1);
		mint c = -mat[y][rank];
		for (int y2 = 0; y2 < y; ++y2) {
			mat[y2][rank] += c * mat[y2][y];
		}
	}

	int order = rank / (deg + 1);

	vector< vector<mint> > ret(order + 1, vector<mint>(deg + 1));
	ret[0][rank % (deg + 1)] = 1;
	for (int y = rank - 1; y >= 0; --y) {
		int k = order - y / (deg + 1), d = y % (deg + 1);
		ret[k][d] = -mat[y][rank];
	}

	if (verify) {
		auto extended_terms = extended(n - 1, ret, 
				vector<mint>(terms.begin(), terms.begin() + order));
		for (int i = 0; i < (int) terms.size(); ++i) {
			if (terms[i] != extended_terms[i]) error(B - 1, deg);
		}
	}

	auto verbose = [&] {
		int last = verify ? n - 1 : order + R - 1;
		fprintf(stderr, 
			"[ Found a recurrence relation ]\n"
			"- order %d\n"
			"- degree %d\n"
			"- verified up to a(%d) (number of non-trivial terms: %d)\n",
			order, deg, last, (last + 1) - ((deg + 2) * (order + 1) - 2)
		);
		fprintf(stderr, "{\n");
		for (int k = 0; k <= order; ++k) {
			fprintf(stderr, "  {");
			for (int d = 0; d <= deg; ++d) {
				if (d) fprintf(stderr, ", ");
				fprintf(stderr, "%d", ret[k][d].v);
			}
			fprintf(stderr, "}%s\n", k == order ? "" : ",");
		}
		fprintf(stderr, "}\n\n");
	};
	verbose();

	return ret;
}

void id1(int n, const vector<mint>& terms, int degree, int order = -1) {
	auto coeffs = id3(terms, degree, order);
	auto extended_terms = extended(n, coeffs, terms);
	for (int i = 0; i < (int) extended_terms.size(); ++i) {
		printf("%d %d\n", i, extended_terms[i].v);
	}
	puts("");
}
V<mint> id2(int n, const vector<mint>& terms, int degree, int order = -1) {
	auto coeffs = id3(terms, degree, order);
	return extended(n, coeffs, terms);
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		

	cout << fixed << setprecision(20);
	InitFact(2000010);

	auto brute = [&](int N){
		mint res = 0;
		rep(i_,N+1) rep(j_,N+1){
			int i = i_, j = j_; if(i>j) swap(i,j);
			if(j == 0){
				continue;
			}
			if(i == 0){
				res += mint(-1).pow(i+j) * Choose(N,j) * mint(3).pow(j + N*(N-j));
			}else{
				res += mint(-1).pow(i+j) * Choose(N,i) * Choose(N,j) * 3 * mint(3).pow((N-i)*(N-j));
			}
		}
		return -res;
	};
	auto solve = [&](ll N){
		mint res = 0;
		rep(i,N+1){
			if(i == 0){
				rep1(j,N){
					res += mint(-1).pow(i+j) * Choose(N,j) * mint(3).pow(j + N*(N-j));
				}
			}else{
				res += mint(-1).pow(i) * Choose(N,i) * (( mint(3).pow(N-i) - 1 ).pow(N) - mint(3).pow((N-i)*N)) * 3;
				res += mint(-1).pow(i) * Choose(N,i) * mint(3).pow(i + N*(N-i));
			}
		}
		return -res;
	};
	int N; cin >> N;
	cout << solve(N) << endl;


}
