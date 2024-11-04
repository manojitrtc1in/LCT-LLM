


























using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;


	

	


template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += val;
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += node_val[i];
		return ret;
	}
};

using id3 = long long;
id3 MOD; 


id3 proot; 

vector<id3> W[19];

template <bool rev>
inline __attribute__((always_inline)) void NTT(id3 * __restrict A, int N) {
	

	for(int i = 0, j = 0; i < N; ++i) {
		if(i < j) swap(A[i], A[j]);
		for(int k = N>>1; (j^=k) < k; k >>= 1) {}
	}
	for(int len = 1, d = 1; len != N; len *= 2, d++) {
		if(W[d].empty()) {
			W[d].resize(1<<d, 1);
			id3 root = pw(proot, (MOD-1)/(1<<d), MOD);
			for(int j = 1; j < (1<<d); j++) W[d][j] = W[d][j-1] * root % MOD;
		}
		for(int j = 0; j < N; j += 2*len) {
			id3 * __restrict ptr_l = A + j;
			id3 * __restrict ptr_r = A + j + len;
			const id3 * __restrict ptr_w = W[d].data();
			for(int k = 0; k < len; k++, ptr_l++, ptr_r++, ptr_w++) {
				id3 u = *ptr_l, v = *ptr_r * (*ptr_w) % MOD;
				*ptr_l = u + v;
				if(*ptr_l >= MOD) *ptr_l -= MOD;
				*ptr_r = u + (MOD - v);
				if(*ptr_r >= MOD) *ptr_r -= MOD;
			}
		}
	}
	if(rev) {
		reverse(A+1, A+N);
		id3 inv_N = pw(N, MOD-2, MOD);
		for(int i = 0; i < N; ++i) A[i] = A[i] * inv_N % MOD;
	}
}

vector<id3> convolution(const vector<id3> & A, const vector<id3> & B) {
	int sz = (int)A.size() + (int)B.size() - 1, n = 2;
	if(sz <= (1<<7)) {
		vector<id3> ret(sz, 0);
		id3 mod2 = MOD * MOD * 4;
		for(int i = 0; i < (int)A.size(); i++) for(int j = 0; j < (int)B.size(); j++) {
			ret[i+j] += A[i] * B[j];
			if(ret[i+j] >= mod2) ret[i+j] -= mod2;
		}
		for(int i = 0; i < sz; i++) ret[i] %= MOD;
		return ret;
	}
	while(n < sz) n *= 2;
 
	constexpr int MAX_N = 1<<18;
	static id3 tmp_A[MAX_N];
	memcpy(tmp_A, A.data(), sizeof(id3) * A.size());
	memset(tmp_A+A.size(), 0, sizeof(id3) * (n - A.size()));
	for(int i = 0; i < n; i++) if(tmp_A[i] < 0) tmp_A[i] += MOD;
	static id3 tmp_B[MAX_N];
	memcpy(tmp_B, B.data(), sizeof(id3) * B.size());
	memset(tmp_B+B.size(), 0, sizeof(id3) * (n - B.size()));
	for(int i = 0; i < n; i++) if(tmp_B[i] < 0) tmp_B[i] += MOD;

	NTT<false>(tmp_A, n);
	NTT<false>(tmp_B, n);

	for(int i = 0; i < n; i++) tmp_A[i] = tmp_A[i] * tmp_B[i] % MOD;

	NTT<true>(tmp_A, n);
	
	vector<id3> ret(sz, 0);
	memcpy(const_cast<id3 *>(ret.data()), tmp_A, sizeof(id3) * sz);
	return ret;
}

vector<id3> invert(const vector<id3> & A, int e) {
	

	int sz = A.size();
	if(e == 0) return (A[0] == 1) ? vector<id3>{1} : vector<id3>{pw(A[0], MOD-2, MOD)};
	vector<id3> B = invert(A, e-1);
	vector<id3> AB;
	if(sz < (1<<e)) AB = convolution(A, B);
	else {
		vector<id3> Ar(begin(A), begin(A)+(1<<e));
		AB = convolution(Ar, B);
	}
	vector<id3> C(1<<(e-1), 0);
	for(int i = (1<<(e-1)); i < min(1<<e, (int)AB.size()); i++)
		C[i-(1<<(e-1))] = MOD-AB[i];
	vector<id3> B_hi = convolution(C, B);
	B_hi.resize(1<<(e-1));
	B.insert(end(B), begin(B_hi), end(B_hi));
	return B;
}

pair< vector<id3>, vector<id3> > id2(const vector<id3> & A, int e) {
	

	if(e == 0) return {vector<id3>{1}, vector<id3>{1}};
	int sz = A.size();
	auto [B, B_inv] = id2(A, e-1);
	

	

	

	

	

	vector<id3> dA((1<<(e-1))-1, 0);
	for(int i = 1; i < min(sz, 1<<(e-1)); i++) dA[i-1] = i * A[i] % MOD;
	vector<id3> C = convolution(dA, B);
	C.resize((1<<e)-1, 0);
	for(int i = 1; i < (1<<(e-1)); i++) C[i-1] = (i * B[i] + MOD - C[i-1]) % MOD;
	for(int i = (1<<(e-1)); i < (1<<e)-1; i++) C[i-1] = (MOD - C[i-1]) % MOD;
	C = convolution(C, B_inv);
	C.resize((1<<e)-1, 0);
	for(int i = 0; i < (1<<(e-1))-1; i++) C[i] = dA[i];
	vector<id3> lB(1<<e, 0);
	for(int i = 1; i < (1<<e); i++) lB[i] = C[i-1] * pw(i, MOD-2, MOD) % MOD;
	for(int i = 0; i < (1<<e); i++) lB[i] = ((i>=sz?0:A[i]) + MOD - lB[i]) % MOD;
	vector<id3> B_hi = convolution(lB, B);
	B.resize(1<<e, 0);
	for(int i = (1<<(e-1)); i < (1<<e); i++) B[i] = B_hi[i];
	C = convolution(B, B_inv);
	C[0] = 0;
	C = convolution(C, B_inv);
	B_inv.resize(1<<e, 0);
	for(int i = (1<<(e-1)); i < (1<<e); i++) B_inv[i] = (MOD - C[i]) % MOD;
	return {B, B_inv};
}

vector<id3> exp(const vector<id3> & A, int e) {
	return id2(A, e).ff;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cat mod;
	cin >> N >> mod;
	MOD = mod;
	vector<int> primes{2};
	cat cur = (mod-1)>>18;
	for(int i = 2; i <= cur; i++) if(cur%i == 0) {
		primes.push_back(i);
		while(cur%i == 0) cur /= i;
	}
	for(int i = 1; ; i++) {
		bool id5 = true;
		for(auto p : primes) if(pw(i, (mod-1)/p, mod) == 1) {
			id5 = false;
			break;
		}
		if(!id5) continue;
		proot = i;
		break;
	}

	vector<cat> fac(N+2), fac_inv(N+2);
	fac[0] = 1;
	for(int i = 1; i <= N+1; i++) fac[i] = fac[i-1] * i % mod;
	fac_inv[N+1] = pw(fac[N+1], mod-2, mod);
	for(int i = N+1; i >= 1; i--) fac_inv[i-1] = fac_inv[i] * i % mod;

	vector<id3> F{0, 1};
	int e = 1;
	while((int)F.size()-1 < N+1) {
		auto [E, E_inv] = id2(F, e+1); 

		auto A_bot = E_inv; 

		for(int i = 0; i < (1<<e); i++) A_bot[i] = (A_bot[i] + mod - F[i]) % mod;
		auto id0 = invert(A_bot, e+1); 

		auto A_top = convolution(F, F); 

		A_top.resize(1<<(e+1), 0);
		auto A = convolution(A_top, id0); 

		A.resize(1<<(e+1), 0);
		auto [EA, EA_inv] = id2(A, e+1); 

		auto id1 = convolution(EA_inv, F); 

		id1.resize(1<<(e+1), 0);
		id1[1] = (id1[1] + mod - 1) % mod;
		id1 = convolution(id1, EA); 

		id1.resize(1<<(e+1), 0);
		auto id6 = F;
		id6[0] = (id6[0] + 2) % mod;
		id6 = convolution(E_inv, id6);
		id6.resize(1<<e, 0);
		for(int i = 0; i < (1<<e); i++) id6[i] = (id6[i] + mod - F[i]) % mod;
		auto C = convolution(F, id0);
		C.resize(1<<e, 0);
		C = convolution(C, C);
		C.resize(1<<e, 0);
		id6 = convolution(id6, C);
		id6.resize(1<<e, 0);
		for(int i = 0; i < (1<<e); i++) id6[i] = (mod - id6[i]) % mod;
		id6[0] = (id6[0] + 1) % mod;
		auto id4 = invert(id6, e); 

		auto F_hi = convolution(id1, id4); 

		F.resize(1<<(e+1), 0);
		for(int i = (1<<e); i < (1<<(e+1)); i++) F[i] = (mod - F_hi[i]) % mod;
		e++;
	}

	for(int i = 1; i < (1<<e); i++) F[i-1] = F[i];
	auto F_inv = invert(F, e);

	for(int i = 1; i <= N; i++) cout << (mod - F_inv[i]) * (i-1) % mod * fac[i] % mod << "\n";


}





