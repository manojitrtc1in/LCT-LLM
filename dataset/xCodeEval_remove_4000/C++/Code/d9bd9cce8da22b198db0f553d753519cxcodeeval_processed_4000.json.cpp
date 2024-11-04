

using namespace std;




int quickpow(int , int , int );
inline int read();
void id0(int );
int fuyi(int );
int C(int , int );
int A(int , int );
int pow2(int );
int pow3(int );

const int N = 366536;
int mod = 998244353, n, k, L, x, y;

vector <int > Fact, Invfact;

namespace Shengyu2{
	
	LL I, p, mod;

	struct Complex2{ 

		LL real, fals;
		
		Complex2(double a = 0, double b = 0){
			real = a, fals = b;
		}
		
		Complex2 operator * (const Complex2 & x){
			LL a, b;
			a = (real * x.real + fals * x.fals % mod * I) % mod;
			b = (real * x.fals + fals * x.real) % mod;
			return Complex2(a > 0 ? a : a + mod, b > 0 ? b : b + mod);
		}
		
		Complex2 operator % (const LL & mod){
			real = real % mod;
			fals  = fals  % mod;
			return Complex2(real > 0 ? real : real + mod, fals > 0 ? fals : fals + mod);			
		}	
	};	
		
	Complex2 quickpow(Complex2 x, LL b, LL mod){
	
		if(b == 0) return Complex2(1, 0);
		if(b == 1) return x % mod;
		
		Complex2 l = quickpow(x, b >> 1, mod);
		l = (l * l) % mod;
		if(b & 1)
		l = (l * x) % mod;
		return l;
	}
	
	bool id4(LL x, LL p){
		return (::quickpow(x, (p - 1) >> 1, p) == 1) || (x == 0);
	}

	pair<LL, LL> id1(long long n, LL MOD){ 

		p = mod = MOD;
		
		if(n == 0) return make_pair(0, 0);
		if(id4(n, p) == false) 
			return make_pair(-1, -1); 

		
		srand(time(0));
		long long a = rand();
		
		while(id4((a * a - n + mod) % mod, p)) a = rand();
		
		Complex2 ans(a, 1);
		I = ((a * a - n) % mod + mod) % mod;
		
		ans = quickpow(ans, (p + 1) >> 1, mod);
		LL ans1 = ans.real, ans2 = mod - ans.real;
		

		return make_pair(min(ans1, ans2), max(ans1, ans2));
	}
}

namespace poly{
	
	
	typedef vector <int> vec;
	

	const int N = 5e5 + 10,  g = 3, invg = ::quickpow(g, mod - 2, mod);
	vec xi, yi, f, v, a, InterP, id3;
	vec Q[N], P[N];

	long long p = mod, I, out1, out2, inv2 = (mod + 1) >> 1, realK;
	vec aa, bb, tmpInv, id5, F, G;
	int rev[N], Inv[N];
	int kp;
	int gpow[33], invgpow[333];
	bool id8;
	
	int GetInv(int x){
		return ::quickpow(x, mod - 2, mod);
	}
	
	vec id2(vec a){
		
		int n = a.size() - 1;
		vec s(n + 1), sinv(n + 1);
		
		s[0] = a[0];
		for(int i = 1; i <= n; i ++)
			s[i] = 1ll * s[i - 1] * a[i] % mod;
		sinv[n] = GetInv(s[n]);
		
		for(int i = n - 1; i >= 0; i --)
			sinv[i] = 1ll * sinv[i + 1] * a[i + 1] % mod;
		
		for(int i = 1; i <= n; i ++)
			sinv[i] = 1ll * sinv[i] * s[i - 1] % mod;
			
		return sinv;
	}
	
	vec Add(const vec &A, const vec &B){
		vec ret = A;
		ret.resize(max(A.size(), B.size()));
		for(int i = 0; i <= B.size() - 1; i ++)
			ret[i] = (ret[i] + B[i]) % mod;
		return ret;
	}
	
	void NTT(vec &A, int type = 1){
		
		if(id8 == false){
			for(int i = 1; i <= 22; i ++){ 

				gpow[i] = quickpow(g, (mod - 1) / (1 << i), mod);
				invgpow[i] = quickpow(invg, (mod - 1) / (1 << i), mod);
			}
			id8 = true;
		}
		
		int limit = A.size();
		
		for(int i = 0;i <= limit - 1;i ++) 
			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * limit >> 1);
		for(int i = 0; i <= limit - 1;i ++)
			if(i > rev[i]) swap(A[i], A[rev[i]]);
		
		for(int half = 1, num = 1; half <= limit - 1; half <<= 1, num ++){ 

			int gn = (type == 1) ? gpow[num] : invgpow[num];
			for(int L = 0; L <= limit - 1; L += (half << 1)){
				long long gn_k = 1;
				for(int k = 0; k <= half - 1; k ++, gn_k = gn_k * gn % mod){
					int x = A[L + k], y = gn_k * A[L + half + k] % mod;
					A[L + k] = (x + y) % mod;
					A[L + half + k] = ((x - y) % mod + mod) % mod;
				}
			}
	    }
	    
	    if(type == -1){

	    	int inv = quickpow(limit, mod - 2, mod);
	    	for(int i = 0; i <= limit - 1; i ++)
	    		A[i] = (long long)A[i] * inv % mod;
		}
		
	}
	
	void out(vec x){
		
		for(int i = 0; i <= x.size() - 1; i ++)
			cout << x[i] << " ";
		cout << endl;
	}
	
	vec Multiply(vec A, vec B){
		
		if(!A.size() || !B.size())	
			return vec(1);
		
	    int n = A.size() + B.size() - 1, limit = 1;
	    while(limit < (A.size() + B.size())) limit <<= 1;
	
		A.resize(limit), NTT(A);
		B.resize(limit), NTT(B);
	
	    for(int i = 0; i <= limit - 1; i ++) 
			A[i] = 1ll * A[i] * B[i] % mod;
	    
	    NTT(A, -1), A.resize(n);
		
		return A;
	}
	
	vec GetInv(int Deg, vec A){
		A.resize(Deg << 1);
		
		vec ret(1, quickpow(A[0], mod - 2, mod));
		
		for(int limit = 4; limit < (Deg << 2); limit <<= 1){
			int deg = limit >> 1;
			
			tmpInv.resize(limit), ret.resize(limit);
		    for(int i = 0; i <= deg - 1; i ++) 

				tmpInv[i] = A[i];
		    for(int i = deg; i <= limit - 1; i ++) 
				tmpInv[i] = 0;
				
		    NTT(tmpInv), NTT(ret);
		    
		    for(int i = 0; i <= limit - 1; i ++) 
				ret[i] = (2 - 1LL * tmpInv[i] * ret[i] % mod) * ret[i] % mod;
		    
		    NTT(ret, -1), ret.resize(deg);
		}
		
		ret.resize(Deg);
		for(int i = 0; i <= Deg - 1; i ++)
			if(ret[i] < 0) ret[i] += mod;
		
		return ret;
	}
	
	vec differ(vec A){ 

		int n = A.size() - 1;
		for(int i = 0; i <= n - 1; i ++)
			A[i] = 1LL * A[i + 1] % mod * (i + 1) % mod;
		A[n] = 0;
		return A;
	}
	
	vec integ(vec A){ 

		int n = A.size() - 1;
		A.push_back(0);
		Inv[1] = 1;
		for(int i = 2; i <= n + 1; i ++)
			Inv[i] = (long long)(mod - mod / i) * Inv[mod % i] % mod;
			
		for(int i = n; i >= 0; i --)
			A[i + 1] = 1LL * A[i] % mod * Inv[i + 1] % mod;
		A[0] = 0;
		return A;
	}
	
	vec GetLin(int deg, vec F){ 

		F.resize(deg);
		F = Multiply(differ(F), GetInv(deg, F)), F.resize(deg - 1);
		return integ(F);
	}
	
	vec id6(int Deg, vec A){ 

		A.resize(Deg << 1);
		vec ret(1, Shengyu2::id1(A[0], mod).first); 

		
		for(int limit = 4; limit < (Deg << 2); limit <<= 1){
			int deg = limit >> 1;
			
			id5.resize(deg);ret.resize(deg);
			for(int i = 0; i <= deg - 1; i ++)
				id5[i] = A[i];

			
			id5 = Multiply(id5, GetInv(deg, ret)); 

			
		    for(int i = 0; i <= deg - 1; i ++)
				ret[i] = (long long)(id5[i] + ret[i]) * inv2 % mod;
		   
		   ret.resize(deg);				
		}
		
		ret.resize(Deg);
		return ret;
	}
	
	vec GetExp(int Deg, vec A){ 

		A.resize(Deg << 1);
		vec ret = vec(1, 1);
		
		for(int limit = 4; limit < (Deg << 2); limit <<= 1){
			int deg = limit >> 1;
			
			vec linret = GetLin(deg, ret);
				
			for(int i = 0; i <= deg - 1; i ++)
				linret[i] = (A[i] - linret[i] + mod) % mod;
			linret[0] = (linret[0] + 1) % mod;
			
			ret = Multiply(ret, linret);
			ret.resize(deg);		
		}
	
		ret.resize(Deg);
	
		return ret;
	}
	
	vec opR(vec A){
		for(int i = 0; i <= (A.size() - 1) >> 1; i ++)
			swap(A[i], A[A.size() - 1 - i]);	
		return A;
	}
	
	pair<vec, vec> GetDiv(vec F, vec G){ 

		
		pair<vec, vec> ret;
		
		int n = F.size() - 1, m = G.size() - 1;
		
		ret.first = Multiply(opR(F), GetInv(n - m + 1, opR(G))); 
		ret.first.resize(n - m + 1);
		ret.first = opR(ret.first);
		
		vec GQ = Multiply(G, ret.first);
		GQ.resize(m), ret.second.resize(m);
		for(int i = 0; i <= m - 1; i ++)
			ret.second[i] = (F[i] - GQ[i] + mod) % mod;
			
		return ret; 

	}
	
	struct big{
		
		vector < int > num;
		
		big(){
			num.clear(); num.push_back(0);
		}
		
		void scan(){
			
			num.clear();
			char c = getchar();
			
			while('0' > c || c > '9')
				c = getchar();
			while('0' <= c && c <= '9')
			num.push_back(c - '0'), c = getchar();
			
			for(int i = 0; i <= (num.size() - 1) >> 1; i ++)
				swap(num[i], num[num.size() - 1 - i]);
		}
		
		void print(){
			cout << num.back();
			for(int i = num.size() - 2, x; i >= 0; i --)				
				putchar(num[i] + '0');
		}
		
	}K, bigK, bigKK;
	
	vec GetPow(vec aa, big k, int n){
		
		int km = 0, ke = 0;
		
		{ 
			if(bigK.num.size() >= 8) realK = 1e8;
			else
				for(int i = (int)bigK.num.size() - 1; i >= 0; i --)
					realK = realK * 10 + bigK.num[i];

			
			{
				for(int i = bigK.num.size() - 1; i >= 1; i --)
					bigK.num[i - 1] = (bigK.num[i - 1] + (long long)bigK.num[i] % mod * 10) % mod;
					bigK.num.pop_back();
				
				km = bigK.num[0] % mod; 

				
				bigK = bigKK;
				for(int i = bigK.num.size() - 1; i >= 1; i --)
					bigK.num[i - 1] = (bigK.num[i - 1] + (long long)bigK.num[i] % (mod - 1) * 10) % (mod - 1);
					bigK.num.pop_back();
					
				ke = bigK.num[0] % (mod - 1); 

				
			}		
		}
		
		aa.resize(n);
		
		aa = opR(aa);
		while(aa.size() && aa[aa.size() - 1] == 0) aa.pop_back();
		int id7 = n - aa.size(); 
		aa = opR(aa);
		
		if(id7 * realK >= n)
			return vec(n);
			
		int first = aa[0], invfirst = quickpow(aa[0], mod - 2, mod);	
		int first_ke = quickpow(first, ke, mod);
		
		for(int i = 0; i <= aa.size() - 1; i ++)
			aa[i] = 1ll * aa[i] * invfirst % mod;
			
		aa = GetLin(n, aa);
		for(int i = 0; i <= aa.size() - 1; i ++)
			aa[i] = 1ll * aa[i] * km % mod;
		aa = GetExp(n, aa);
		
		for(int i = 0; i <= aa.size() - 1; i ++)
			aa[i] = 1ll * aa[i] * first_ke % mod;
		
		id7 = min(1ll * id7 * realK, (long long)n); 

		
		aa = opR(aa);
		for(int i = 1; i <= id7; i ++)
			aa.push_back(0);
		aa = opR(aa);
		aa.resize(n);
		
		return aa;
	}
	
	vec MulT(vec a, vec b){

		int n = a.size(), m = b.size();
		reverse(b.begin(), b.end()),
		b = Multiply(a, b);
		for(int i = 0; i <= n - 1; i ++)
			a[i] = b[i + m - 1];
		return a;
	}
	
	void Init(vec &A, int k, int l, int r){
		
		if(l == r){
			Q[k].resize(2);
			Q[k][0] = 1, Q[k][1] = (mod - A[l]);
			return ;
		}
		
		int mid = (l + r) >> 1;
		Init(A, k << 1, l, mid), Init(A, k << 1 | 1, mid + 1, r);
		Q[k] = Multiply(Q[k << 1], Q[k << 1 | 1]);
		return ;
	}
	
	void Multipoints(int k, int l, int r, vec F, vec &g){
		F.resize(r - l + 1);
		if(l == r)  return void(g[l] = F[0]);
		int mid = (l + r) >> 1;
		
		Multipoints(k << 1, l, mid, MulT(F, Q[k << 1 | 1]), g);
		Multipoints(k << 1 | 1, mid + 1, r, MulT(F, Q[k << 1]), g);
	}
	
	void Multipoint(vec f, vec a, vec &v, int n){ 
		f.resize(n + 1), a.resize(n);
		

		

		

		for(int i = 0; i <= a.size() - 1; i ++)
			a[i] %= mod;
		
		Init(a, 1, 0, n - 1), v.resize(n);
		Multipoints(1, 0, n - 1, MulT(f, GetInv(n + 1, Q[1])), v);
		return ;
	}
	
	void GetP(int p, int l, int r, const vec &xi){ 

		
		if(l == r){
			P[p].resize(2);
			P[p][0] = -xi[l], P[p][1] = 1; 

			return ;
		}
		
		int mid = l + r >> 1;
		
		GetP(p << 1, l, mid, xi);
		GetP(p << 1 | 1, mid + 1, r, xi);
		P[p] = Multiply(P[p << 1], P[p << 1 | 1]);
	}
	
	vec InterPart(int p, int l, int r, const vec &xi, const vec &yi, const vec &id3){
		
		if(l == r){	
			vec ret;
			ret.push_back(1ll * yi[l] * id3[l] % mod);
			return 	ret;
		}
		
		int mid = l + r >> 1;
		
		return Add(Multiply(InterPart(p << 1, l, mid, xi, yi, id3), P[p << 1 | 1]), Multiply(InterPart(p << 1 | 1, mid + 1, r, xi, yi, id3), P[p << 1]));
	}
	
	void Interpolation(const vec &xi, const vec &yi, vec &f){
			
		

		

		

		
		GetP(1, 0, xi.size() - 1, xi);
		
		
		InterP = differ(P[1]); 
		InterP.pop_back(); 

	
		Multipoint(InterP, xi, id3, xi.size());
	
		id3 = id2(id3); 

		f = InterPart(1, 0, xi.size() - 1, xi, yi, id3);
		return ; 
	}
	
	vec ChaMultiply(int n, vec A, vec B){
		

		

		A.resize(n + 1);
		B.resize(n + 1);
		vec Ans = Multiply(A, opR(B));
		Ans.resize(n + 1);
		return opR(Ans);
	}

}

namespace matrix{
	
	struct matrix{
		int hang, lie;
		vector <vector<int >> num;
		
		matrix(int x = 0, int y = 0){
			
			hang = x;
			lie = y;
			num.resize(x + 1);
			for(int i = 1; i <= x; i ++)
				num[i].resize(y + 1);
		}
		
		void out(){
			for(int i = 1; i <= hang; i ++){
				for(int j = 1; j <= lie; j ++)
					cout << num[i][j] << " ";
				cout << endl;
			}		
		}
	
	}no;
	
	matrix E(int n){
		matrix ret(n, n);
		for(int i = 1; i <= n; i ++)
			ret.num[i][i] = 1;
		return ret;
	}
	
	matrix operator * (matrix a, matrix b){
	
		matrix ret(a.hang, b.lie);
		
		for(int i = 1; i <= ret.hang; i ++)
			for(int j = 1; j <= ret.lie; j ++)
				for(int k = 1; k <= a.lie; k ++)
					ret.num[i][j] = (ret.num[i][j] + 1ll * a.num[i][k] * b.num[k][j]) % mod;
	
		return ret;
	}

	matrix operator * (int k, matrix b){
		
		matrix ret = b;
		
		for(int i = 1; i <= b.hang; i ++)
			for(int j = 1; j <= b.lie; j ++)
				ret.num[i][j] = 1ll * k * b.num[i][j] % mod;
				
		return ret;
	}
	
	matrix operator + (matrix a, matrix b){
		
		matrix ret = a;
		for(int i = 1; i <= a.hang; i ++)
			for(int j = 1; j <= a.lie; j ++){
				ret.num[i][j] = a.num[i][j] + b.num[i][j];
				if(ret.num[i][j] >= mod) ret.num[i][j] -= mod;
			}
				
		return ret;
	}
	
	matrix quickpow(matrix x, int b){
		if(b == 0) return E(x.lie);
		if(b == 1) return x;
		
		matrix l = quickpow(x, b >> 1);
		l = l * l;
		if(b & 1)
			l = l * x;
		return l;
	}

}

int rk[N], s[N];

void work(){
	
	int n, k, m, Ans = 0, z = 0;
	cin >> n >> k;
	for(int i = 0, x; i < n; i ++)
		cin >> x, rk[x] = i, s[i] = x;
	rk[n] = -1;
	
	for(int i = 0; i <= n - 2; i ++){
		int a = s[i];
		int b = s[i + 1];
		
		if(rk[a + 1] < rk[b + 1])
			z ++;
	}
	
	for(int i = 1; i <= k; i ++)
		Ans = (Ans + 1ll * C(i + z - 1, i - 1) * C(k - i, n - z - 1)) % mod;
	
	cout << Ans << endl;
		
}

void init(){
	id0(5e5+10);
}

signed main(){
	
	init();
	
	int T = 1;


	while(T --) work();
	return 0;
}

int pow2(int x){
	return 1ll * x * x % mod;
}

int pow3(int x){
	return 1ll * x * x % mod * x % mod;
}

int C(int a, int b){
	if(a < b) return 0;
	return 1ll * Fact[a] * Invfact[b] % mod * Invfact[a - b] % mod;
}

int A(int a, int b){
	if(a < b) return 0;
	return 1ll * Fact[a] * Invfact[a - b] % mod;
}

inline int quickpow(int x, int b, int mod){
	int j = 1;
	for(; b; b >>= 1, x = 1ll * x * x % mod)
		if(b & 1) 
			j = 1ll * j * x % mod;
	return j % mod;
}

inline int read(){
	
	int x = 0, f = 1;
	char c = getchar();
	
	while(c < '0' || c > '9'){
		if(c == '-')
			f = -1;
		c = getchar();
	}
	
	while('0' <= c && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	
	return x * f;
}

int fuyi(int x){
	return (abs(x) & 1) ? (mod - 1) : (+1);
}

void id0(int n){
	Fact.resize(n + 1);
	Fact[0] = 1;
	for(int i = 1; i <= n; i ++)
		Fact[i] = 1ll * Fact[i - 1] * i % mod;
	Invfact = poly::id2(Fact);
}



