#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

#define M 998244353

long long int power(long long int p, long long int q) {
	long long int r = 1;
	long long int z = p;
	while (q) {
		if (q & 1) { r = (r * z) % M; }
		q >>= 1;
		if (q) { z = (z * z) % M; }
	}
	return r;
}

class BIG_INT {
public:
	const static int MAX_LEN = 524288;

	vector<int> v;
	int vl;
	BIG_INT() { vl = 0; }
	BIG_INT(const BIG_INT& p) { set(p.v, p.vl); }
	~BIG_INT() {}
	BIG_INT& operator=(BIG_INT& p) { set(p.v, p.vl); return *this; }
	BIG_INT& operator=(const BIG_INT& p) { set(p.v, p.vl); return *this; }
	void set(const vector<int> &a, int al) {
		vl = al;
		v.resize(vl);
		for (int i = 0; i < vl; i++) {
			v[i] = a[i];
		}
	}
	void set(const long long int *a, int al) {
		vl = al;
		v.resize(vl);
		for (int i = 0; i < vl; i++) {
			v[i] = a[i];
		}
	}
	void set(const int* a, int al) {
		vl = al;
		v.resize(vl);
		for (int i = 0; i < vl; i++) {
			v[i] = a[i];
		}
	}
	static int odd[MAX_LEN * 2];
	static int evv[MAX_LEN * 2];
	static int temp_p[MAX_LEN];
	static int temp_q[MAX_LEN];
	static int temp_r[MAX_LEN];
	static long long int w_list[24];
	static long long int rw_list[24];
	static void dft(int* a, int n, long long int w)
	{
		if (n == 1)return;
		int i;
		long long int ww, offset;

		for (i = 0; i < n / 2; i++) {
			evv[n / 2 + i] = a[2 * i];
			odd[n / 2 + i] = a[2 * i + 1];
		}
		ww = (w * w)%M;
		dft(evv + n / 2, n / 2, ww);
		dft(odd + n / 2, n / 2, ww);

		ww = 1;
		for (i = 0; i < n / 2; i++) {
			offset = (ww * odd[n / 2 + i])%M;
			a[i] = (evv[n / 2 + i] + offset)%M;
			a[i + n / 2] = (evv[n / 2 + i] + M - offset)%M;
			ww = (ww*w)%M;
		}
	}

	BIG_INT friend operator *(BIG_INT& p, BIG_INT& q) {
		BIG_INT r;
		int zn, zc;
		zn = 1;
		zc = 0;
		while (zn < MAX_LEN && (zn < p.vl + q.vl)) {
			zn <<= 1;
			zc++;
		}
		
		if (zc <= 3) {
			return naive(p, q);
		}

		int i, j;
		for (i = 0; i < p.vl; i++) BIG_INT::temp_p[i] = p.v[i];
		for (; i < zn; i++) BIG_INT::temp_p[i] = 0;
		for (i = 0; i < q.vl; i++) BIG_INT::temp_q[i] = q.v[i];
		for (; i < zn; i++) BIG_INT::temp_q[i] = 0;

		long long int w = BIG_INT::w_list[zc];

		BIG_INT::dft(BIG_INT::temp_p, zn, w);
		BIG_INT::dft(BIG_INT::temp_q, zn, w);

		for (i = 0; i < zn; i++) {
			BIG_INT::temp_q[i] = ((long long int)BIG_INT::temp_q[i] * BIG_INT::temp_p[i])%M;
		}

		w = power(w, M - 2);
		BIG_INT::dft(BIG_INT::temp_q, zn, w);

		long long int invzn = power(zn, M - 2);
		for (i = 0; i < zn; i++) {
			temp_r[i] = (BIG_INT::temp_q[i] * invzn)%M;
		}
		int zl;
		for (zl = zn; zl > 1; zl--) {
			if (temp_r[zl - 1])
				break;
		}
		r.set(temp_r, zl);

		return r;
	}
	static void fft(int *a, int n, bool invert)
	{
		for (int i = 1, j = 0; i < n; i++) {
			int bit = n >> 1;
			for (; j >= bit; bit >>= 1) j -= bit;
			j += bit;
			if (i < j) swap(a[i], a[j]);
		}
		int dep = 1;
		for (int len = 2; len <= n; len <<= 1) {
			long long int wlen = w_list[dep];
			if (invert)wlen = rw_list[dep];
			dep++;
			for (int i = 0; i < n; i += len) {
				long long int w = 1;
				for (int j = 0; j < len / 2; j++) {
					long long  u = a[i + j], v = ((long long int)a[i + j + len / 2] * w)%M;
					a[i + j] = (u + v)%M;
					a[i + j + len / 2] = (u + M - v)%M;
					w = (w*wlen)%M;
				}
			}
		}
		if (invert) {
			static unordered_map<int, long long int> memoi;
			if (memoi.find(n) == memoi.end())memoi[n] = power(n, M - 2);
			long long int invzn = memoi[n];
			for (int i = 0; i < n; i++) a[i] = ((long long int)a[i] * invzn) % M;
		}
	}
	static void mult(BIG_INT &r, const BIG_INT& p, const BIG_INT& q) {
		if (q.vl == 1 && q.v[0] == 1) { r = p; return; }
		if (p.vl == 1 && p.v[0] == 1) { r = q; return; }
		int zn, zc;
		zn = 1;
		zc = 0;
		while (zn < MAX_LEN && (zn < p.vl + q.vl)) {
			zn <<= 1;
			zc++;
		}
		
		

		if (zc < 4 || p.vl < 4 || q.vl < 4) {
			return naive_mult(r, p, q);
		}

		int i, j;
		for (i = 0; i < p.vl; i++) BIG_INT::temp_p[i] = p.v[i];
		for (; i < zn; i++) BIG_INT::temp_p[i] = 0;
		for (i = 0; i < q.vl; i++) BIG_INT::temp_q[i] = q.v[i];
		for (; i < zn; i++) BIG_INT::temp_q[i] = 0;

		BIG_INT::fft(BIG_INT::temp_p, zn, false);
		BIG_INT::fft(BIG_INT::temp_q, zn, false);

		for (i = 0; i < zn; i++) {
			BIG_INT::temp_q[i] = ((long long int)BIG_INT::temp_q[i] * BIG_INT::temp_p[i]) % M;
		}
		BIG_INT::fft(BIG_INT::temp_q, zn, true);

		for (i = 0; i < zn; i++) {
			temp_r[i] = BIG_INT::temp_q[i];
		}
		int zl;
		for (zl = zn; zl > 1; zl--) {
			if (temp_r[zl - 1])
				break;
		}
		r.set(temp_r, zl);
	}


	static BIG_INT naive(BIG_INT& p, BIG_INT& q) {
		BIG_INT r;
		r.vl = p.vl + q.vl;
		r.v.resize(r.vl);
		for (int i = 0; i < r.vl; i++)r.v[i] = 0;
		for (int i = 0; i < p.vl; i++) {
			for (int j = 0; j < q.vl; j++) {
				r.v[i + j] = (r.v[i + j] + (long long int)p.v[i] * q.v[j]) % M;
			}
		}
		for (; r.vl > 0; r.vl--) if (r.v[r.vl - 1])break;
		if (r.vl == 0)r.vl = 1;
		return r;
	}
	static void naive_mult(BIG_INT &r, const BIG_INT& p, const BIG_INT& q) {
		int vl = p.vl + q.vl;
		for (int i = 0; i < vl; i++)temp_r[i] = 0;
		for (int i = 0; i < p.vl; i++) {
			for (int j = 0; j < q.vl; j++) {
				temp_r[i + j] = (temp_r[i + j] + (long long int)p.v[i] * q.v[j]) % M;
			}
		}
		r.v.resize(vl);
		for (int i = 0; i < vl; i++)r.v[i] = temp_r[i];
		r.vl = vl;
		for (; r.vl > 0; r.vl--) if (r.v[r.vl - 1])break;
		if (r.vl == 0)r.vl = 1;
	}
	
	void print() {
		for (int i = vl - 1; i >= 0; i--) {
			printf("%d ", v[i]);
		}
		printf("\n");
	}
};

int BIG_INT::odd[BIG_INT::MAX_LEN * 2];
int BIG_INT::evv[BIG_INT::MAX_LEN * 2];
int BIG_INT::temp_p[BIG_INT::MAX_LEN];
int BIG_INT::temp_q[BIG_INT::MAX_LEN];
int BIG_INT::temp_r[BIG_INT::MAX_LEN];
long long int BIG_INT::w_list[24];
long long int BIG_INT::rw_list[24];
void test() {
	int i, j, k;
	long long int w = 3;
	w = power(w, 119);
	for (i = 0; i < 24; i++) {
		BIG_INT::w_list[23 - i] = w;
		BIG_INT::rw_list[23 - i] = power(w, M-2);
		w = (w * w) % M;
	}
}

int n, m;
int a[300009];
int acount[300009];
int b[9];
int bsi[9];
int bss[9];

int tmp[2];
BIG_INT to[2];
BIG_INT bb, cc, dd;
int I;
int st;
void bigpower(BIG_INT& b, int type, int q) {
	if (q == 0) { b.set(tmp, 1); return; }
	if (q == 1) { b = to[type]; return; }
	bigpower(b, type, q / 2);
	BIG_INT::mult(b, b, b);
	if (q & 1) BIG_INT::mult(b, b, to[type]);
}
long long memoi[600009];
void build_bb() {
	int i, j, k;
	tmp[0] = 1;
	tmp[1] = 2;
	to[0].set(tmp, 2);
	tmp[1] = 1;
	to[1].set(tmp, 2);
	j = 0;
	k = 0;
	bb.set(tmp, 1);
	for (i = 0; i < m; i++) {
		int nn = bsi[i];
		int mm = bss[i];
		bigpower(cc, 0, nn - 2 * mm - j);
		bigpower(dd, 1, 2 * mm - 2 * k);
		BIG_INT::mult(cc, cc, dd);
		BIG_INT::mult(bb, bb, cc);
		for (int ti = 0; ti < bb.vl; ti++) {
			memoi[ti + b[i]] = (memoi[ti + b[i]] + bb.v[ti]) % M;
		}
		j = nn - 2 * mm;
		k = mm;
	}
}
int main() {
	int i, j, k, l;
	test();
	scanf("%d %d", &n, &m);




	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);


		if (acount[a[i]] < 2)
			acount[a[i]]++;
	}
	n = 0;
	for (i = 1; i <= 300000; i++)
	{
		while (acount[i]--) {
			a[n++] = i;
		}
	}
	a[n] = 0;
	j = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);


	}
	sort(b, b + m);
	bss[0] = 0;
	for (i = 0; i < m; i++)
	{
		if (i > 0)bss[i] = bss[i - 1];
		while (j < n && a[j] < b[i]) {
			if (a[j] == a[j + 1])bss[i]++;
			j++;
		}
		bsi[i] = j;
	}
	build_bb();

	int t;
	scanf("%d", &t);
	while (t--) {
		int qm;
		scanf("%d", &qm);
		qm /= 2;
		printf("%lld\n", memoi[qm-1]);
	}
}