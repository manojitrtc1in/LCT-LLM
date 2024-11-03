#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <cmath>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <bitset>
#include <functional>
using namespace std;
typedef long long ll;


#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))
#define PI 3.14159265358979323846
#define ABS(a) ((a)<0?-(a):(a))
const long long MOD = 1000000007;
const long long LLONG = 9223372036854775807;
const int N = 250000;
const double EPS = 0.0001;



void mult22(long long matrres[2][2], long long matrmult[2][2], long long mod)
{
	long long tmatr[2][2];
	tmatr[0][0] = (matrres[0][0] * matrmult[0][0]) % mod + (matrres[0][1] * matrmult[1][0]) % mod;
	tmatr[0][1] = (matrres[0][0] * matrmult[0][1]) % mod + (matrres[0][1] * matrmult[1][1]) % mod;
	tmatr[1][1] = (matrres[1][0] * matrmult[0][1]) % mod + (matrres[1][1] * matrmult[1][1]) % mod;
	tmatr[1][0] = (matrres[1][0] * matrmult[0][0]) % mod + (matrres[1][1] * matrmult[1][0]) % mod;
	matrres[0][0] = (tmatr[0][0]) % mod;
	matrres[1][0] = (tmatr[1][0]) % mod;
	matrres[1][1] = (tmatr[1][1]) % mod;
	matrres[0][1] = (tmatr[0][1]) % mod;
}

long long fibo(long long n, long long mod)
{
	if (n == 0)return 0;
	long long matr[2][2];
	matr[0][0] = 0;
	matr[1][0] = 1;
	matr[1][1] = 1;
	matr[0][1] = 1;
	long long multmatr[2][2];
	multmatr[0][0] = 0;
	multmatr[1][0] = 1;
	multmatr[1][1] = 1;
	multmatr[0][1] = 1;
	n = n - 1;
	while (n > 0)
	{
		if (n & 1)
			mult22(matr, multmatr, mod);
		mult22(multmatr, multmatr, mod);
		n >>= 1;
	}
	return(matr[0][1]);
}

long long myNpow(long long a, long long n, long long mod)
{
	long long multi = a % mod;
	long long res = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			res *= multi;
			res %= mod;
		}
		multi *= multi;
		multi %= mod;
		n >>= 1;
	}
	return res;
}

bool issqr(int k)
{
	int t = (int)sqrt(k);
	return (t * t) == k;
}

void multNN(long long* matrres, long long* matrmult, long long mod, int n)
{
	long long* tmatr = (long long*)malloc(n * n * 8);
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			tmatr[i * n + j] = 0;
			for (k = 0; k < n; k++)
			{
				tmatr[i * n + j] += matrres[i * n + k] * matrmult[k * n + j];
				tmatr[i * n + j] %= mod;
			}
		}

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			matrres[i * n + j] = tmatr[i * n + j];
	free(tmatr);
}

void matrPOW(long long* matrres, int n, long long pow, long long mod)
{
	long long* multmatr = (long long*)malloc(n * n * 8);
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			multmatr[i * n + j] = matrres[i * n + j];
	pow = pow - 1;
	while (pow > 0)
	{
		if (pow & 1)
			multNN(matrres, multmatr, mod, n);
		multNN(multmatr, multmatr, mod, n);
		pow >>= 1;
	}
}

double calcdet33(double* matr)
{
	double res = 0;
	res += matr[0] * matr[4] * matr[8];
	res += matr[1] * matr[5] * matr[6];
	res += matr[2] * matr[3] * matr[7];
	res -= matr[2] * matr[4] * matr[6];
	res -= matr[1] * matr[3] * matr[8];
	res -= matr[0] * matr[5] * matr[7];
	return res;
}

class Longnum
{
public:

	vector < long long > c;

	Longnum()
	{
		c.push_back(0);
	}
	Longnum(int n)
	{
		for (int i = 0; i < n; i++)
			c.push_back(0);
	}

	~Longnum()
	{
		c.clear();
		c.shrink_to_fit();
	}

	int slongsub(Longnum& temp, Longnum& b)
	{
		long long carry = 0;
		vector<long long> a(temp.c);
		for (size_t i = 0; i < b.c.size() || carry; ++i) {
			a[i] -= carry + (i < b.c.size() ? b.c[i] : 0);
			carry = a[i] < 0;
			if (carry)  a[i] += slongbase;
		}
		if (carry)
			return -1;
		else
		{
			while (a.size() > 1 && a.back() == 0)
				a.pop_back();
			temp.c = a;
			return 0;
		}
	}

	void add(int b)
	{
		long long carry = 0;
		for (size_t i = 0; i < c.size() || carry; ++i) {
			if (i == c.size())
				c.push_back(0);
			c[i] += carry + (i > 0 ? 0 : b);
			carry = c[i] >= slongbase;
			if (carry)  c[i] -= slongbase;
		}
	}

	void mult(long long b)
	{
		long long carry = 0;
		for (size_t i = 0; i < c.size() || carry; ++i) {
			if (i == c.size())
				c.push_back(0);
			long long cur = carry + c[i] * 1ll * (b % slongbase);
			carry = cur / slongbase + c[i] * (b / slongbase);
			c[i] = int(cur % slongbase);
		}
		while (c.size() > 1 && c.back() == 0)
			c.pop_back();
	}

	void longmult(Longnum b)
	{
		Longnum n(c.size() + b.c.size());

		for (size_t i = 0; i < c.size(); ++i)
			for (int j = 0, carry = 0; j < (int)b.c.size() || carry; ++j) {
				long long cur = n.c[i + j] + c[i] * 1ll * (j < (int)b.c.size() ? b.c[j] : 0) + carry;
				n.c[i + j] = int(cur % slongbase);
				carry = int(cur / slongbase);
			}
		while (n.c.size() > 1 && n.c.back() == 0)
			n.c.pop_back();
		c = n.c;
	}

	int slongcomp(Longnum a, Longnum b)
	{
		if (a.c.size() != b.c.size())
			return (a.c.size() > b.c.size() ? 1 : -1);
		else
		{
			for (int i = a.c.size() - 1; i >= 0; i--)
				if (a.c[i] != b.c[i])
					return (a.c[i] > b.c[i] ? 1 : -1);
			return 0;
		}
	}

	void slongdel(Longnum& b)
	{
		Longnum temp, temp2;
		Longnum res;
		for (int i = 0; i < c.size() - b.c.size(); i++)
		{
			temp.c.push_back(0);
			res.c.push_back(0);
		}
		res.c.push_back(0);
		for (int i = 0; i < b.c.size(); i++)
			temp.c.push_back(b.c[i]);

		for (int i = c.size() - b.c.size(); i >= 0; i--)
		{
			temp2.c = temp.c;
			res.c[i] = (c[c.size() - 1] / temp.c[temp.c.size() - 1]);
			temp.mult(c[c.size() - 1] / temp.c[temp.c.size() - 1]);
			if (slongcomp(temp, *this) > 0)
			{
				slongsub(temp, temp2);
				res.c[i]--;
			}
			slongsub(*this, temp);
			temp.c.clear();
			for (int j = 1; j < temp2.c.size(); j++)
				temp.c.push_back(temp2.c[i + 1]);
		}
		if (c.size() > 1 || c[0] > 0)
		{
			res.c[0] += 1;
			int carry = res.c[0] / slongbase;
			int i = 0;
			while (carry)
			{
				res.c[i] %= slongbase;
				i++;
				if (i == res.c.size())
					res.c.push_back(0);
				res.c[i] += carry;
				carry = res.c[i] / slongbase;
			}
		}
		c = res.c;
		return;
	}

	void slongprint()
	{
		printf("%lldd", c.empty() ? 0 : c.back());
		for (int i = (int)c.size() - 2; i >= 0; --i)
			printf("%09lld", c[i]);
		printf(" ");
	}

	void slongread()
	{
		string s;
		cin >> s;
		for (int i = (int)s.length(); i > 0; i -= 9)
			if (i < 9)
				c.push_back(atoi(s.substr(0, i).c_str()));
			else
				c.push_back(atoi(s.substr(i - 9, 9).c_str()));
	}

	void longadd(Longnum& b)
	{
		long long carry = 0;
		for (size_t i = 0; i < max(c.size(), b.c.size()) || carry; ++i) {
			if (i == c.size())
				c.push_back(0);
			c[i] += carry + (i < b.c.size() ? b.c[i] : 0);
			carry = c[i] >= slongbase;
			if (carry)  c[i] -= slongbase;
		}
	}

private:

	const long long slongbase = 1000 * 1000 * 1000;
};

class SeTree
{
public:
	SeTree() {}
	~SeTree() {}
	void build(int a, int l, int r, int*inp)
	{
		int m = (l + r + 1) / 2;
		vup[a] = 0;
		if (l != r)
		{
			build(a * 2, l, m - 1, inp);
			build(a * 2 + 1, m, r, inp);
			v[a] = (v[a * 2 + 1] * (r - m + 1) + v[a * 2] * (m - l)) / (double)(r - l + 1);
		}
		else
			v[a] = (double)(inp[l]);
	}
	void  update(int a, int l, int r, double k, int lr, int rr)
	{
		if ((lr == l) && (rr == r))
		{
			v[a] = k;
			vup[a] = 1;
		}
		else
		{
			int m = (l + r + 1) / 2;
			if (vup[a])
			{
				v[a * 2 + 1] = v[a];
				vup[a * 2 + 1] = 1;
				v[a * 2] = v[a];
				vup[a * 2] = 1;
				vup[a] = 0;
			}
			if (rr < m)
			{
				update(a * 2, l, m - 1, k, lr, rr);
			}
			else
			{
				if (lr >= m)
				{
					update(a * 2 + 1, m, r, k, lr, rr);
				}
				else
				{
					update(a * 2, l, m - 1, k, lr, m - 1);
					update(a * 2 + 1, m, r, k, m, rr);
				}
			}
			v[a] = (v[a * 2 + 1] * (r - m + 1) + v[a * 2] * (m - l)) / (double)(r - l + 1);
		}
	}
	double getav(int a, int l, int r, int lr, int rr)
	{
		if (vup[a] || (l == lr && r == rr))
			return v[a];
		else
		{
			int m = (l + r + 1) / 2;
			if (rr < m)
			{
				return getav(a * 2, l, m - 1, lr, rr);
			}
			else
			{
				if (lr >= m)
					return getav(a * 2 + 1, m, r, lr, rr);
				else
				{
					return (getav(a * 2 + 1, m, r, m, rr) * (rr - m + 1) + getav(a * 2, l, m - 1, lr, m - 1) * (m - lr)) / (double)(rr - lr + 1);
				}
			}
		}
	}
	double get(int a, int l, int r, int i)
	{
		if (vup[a]||(l==r))
			return v[a];
		else
		{
			int m = (l + r + 1) / 2;
			if (i < m)
			{
				return get(a * 2, l, m - 1, i);
			}
			else
			{
				return get(a * 2 + 1, m, r, i);
			}
		}
	}

private:

	bool vup[N * 4];
	double v[N * 4];
};

long long  gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}

void eratosfen(char* erat, int n)
{
	int sr = (int)ceil(sqrt(n + 1)), i, j;
	erat[0] = erat[1] = 0;
	erat[2] = 0;
	for (i = 3; i <= n; i++)
		erat[i] = i % 2;
	for (i = 3; i*i <= n; i++)
		for (j = i * i; j <= n; j += i)
			erat[j] = 0;
}


long long findp(long long& a)
{
	long long r = (long long)ceil(sqrt(a)) + 1000;
	long long l = r - 2000;
	if (l < 0)
		l = 0;
	while (r > l)
	{
		long long m = (r + l + 1) / 2;
		if (m * m > a)
			r = m - (long long)1;
		else
			if (m * m == a)
			{
				a = 0;
				return m;
			}
			else
				l = m + (long long)1;
	}
	if (l * l < a)
		l++;
	a = l * l - a;
	return l;
}

int popcount32(int x)
{
	const int m1 = 0x55555555; 

	const int m2 = 0x33333333; 

	const int m4 = 0x0f0f0f0f; 

	const int m8 = 0x00ff00ff; 

	const int m16 = 0x0000ffff; 

	x -= (x >> 1) & m1;             

	x = (x & m2) + ((x >> 2) & m2); 

	x = (x + (x >> 4)) & m4;        

	x += x >> 8;  

	x += x >> 16;  

	return x & 0x7f;
}


void GUsolve()
{
	int T, n, k, s, f,t;
	long long sum = 0, tp, m,p;
	scanf("%i", &T);
	for (int t = 0; t < T; t++)
	{

		scanf("%i %i", &n, &k);
		if (k % 2)
			printf("0\n");
		else
		{
			sum = 0;
			for (int i = 1; i <= k / 2; i++)
			{
				tp = myNpow((myNpow(2, i, MOD)), n / (i * 2), MOD);
				p = n % (i * 2);
				if (p == i)
				{
					m = 2 * (myNpow(2, i, MOD) - 1) + 2 * (myNpow(2, i - 1, MOD) - 1) + 1;
				}
				else
				{
					if (p > i)
						m = (myNpow(2, p - i, MOD) + myNpow(2, i, MOD)) * (p - i - 1) + 2 * myNpow(2, p - i, MOD) * (myNpow(2, 2 * i - p + 1, MOD) - 1);
					else
						if (p > 0)
							m = 2 * (myNpow(2, p + 1, MOD) - 1) + 1 * (i - p - 1) + myNpow(2, p, MOD) * (i - p - 1);

						else
							m = i*2;
				}
				tp *= m;
				tp %= MOD;
				sum += tp;

			}
			sum %= MOD;
			printf("%I64d\n", sum);
		}
	}
}


void B8solve()
{
	string s,lo;
	cin >> s;
	int n,csum,targ,cards[70], nplus, nminus;
	scanf("%i", &n);
	for (int i = 0; i < n; i++)
	{
		csum = 0;
		for (int j = 0; j < 64; j++)
		{
			scanf("%i", cards+j);
			if (cards[j])
				csum ^= j;
		}
		if (s[0] == 'M')
		{
			scanf("%i", &targ);
			targ--;
			nplus =targ^csum;
			cards[nplus] ^= 1;
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < 8; k++)
					printf("%i ", cards[j * 8 + k]);
				printf("\n");
			}
			printf("---\n");
		}
		else
		{
			printf("%i\n", csum + 1);
			cin >> lo;
		}
	}
}

void K9solve()
{
	

	vector<int> stickstemp;
	int a, T,triangles[4][3],ntria,b,c,mindiff[12],fl;
	int sticks[12], nstick,taken[12], ntriangles[4][3], nntria;
	scanf("%i", &T);
	for (int t = 0; t < T; t++)
	{
		ntria = 0;
		stickstemp.clear();
		for (int i = 0; i < 12; i++)
		{
			scanf("%i", &a);
			
			

			stickstemp.push_back(a);
		}
		sort(stickstemp.begin(), stickstemp.end());
		
		mindiff[11] = MOD;
		for (int i = 10; i >= 0; i--)
		{
			mindiff[i] = min(stickstemp[i + 1] - stickstemp[i], mindiff[i + 1]);
		}
		fl =0;
		nstick = 0;
		for (int i = 0; i < 10; i++)
		{
			if (stickstemp[i] > mindiff[i + 1])
			{
				fl = 1;
			}
			if (fl)
			{
					sticks[nstick] = stickstemp[i];
					nstick++;
			}
		}
		sticks[nstick] = stickstemp[10];
		nstick++;
		sticks[nstick] = stickstemp[11];
		while (nstick >= 2 && sticks[nstick] - sticks[nstick - 1] > sticks[nstick - 2])
			nstick--;
		nstick++;
		if (nstick > 2)
		{
			for (int i = 0; i < nstick; i++)
				taken[i] = 0;
			for (int i = 1; i < nstick - 1; i++)
			{
				fl = 0;
				c = (sticks[i + 1] - sticks[i]);
				for (int j = 0; j < i&&!fl; j++)
				{
					if (!taken[j] && sticks[j] > c)
					{
						taken[j] = 1;
						taken[i] = 1;
						taken[i + 1] = 1;
						triangles[ntria][0] = sticks[j];
						triangles[ntria][1] = sticks[i];
						triangles[ntria][2] = sticks[i + 1];
						ntria++;
						i += 2;
						fl = 1;
					}
				}
			}
			if ((nstick > 5) && (ntria < (nstick / 3)))
			{

				unordered_map<int, int> possib[4];
				for (int i = 1; i < nstick - 1; i++)
				{
					for (int k = i + 1; k < nstick; k++)
					{
						c = (sticks[k] - sticks[i]);
						for (int j = 0; j < i; j++)
						{
							if (sticks[j] > c)
							{
								possib[0].insert({ (1 << i) + (1 << k) + (1 << j),0 });
							}
						}
					}
				}
				int mn;
				if (possib[0].size() < 1)
					mn = -1;
				else
					mn = 0;
				for (int i = 0; i < 3 && possib[i].size()>0; i++)
				{
					for (auto it = possib[i].begin(); it != possib[i].end(); it++)
					{
						for (auto it2 = possib[0].begin(); it2 != possib[0].end(); it2++)
						{
							if ((it->first ^ it2->first) == (it->first | it2->first))
							{
								possib[i + 1][(it->first | it2->first)] = it->first;
								mn = i + 1;
							}
						}
					}
				}
				if (mn >= ntria)
				{
					int sum, cur;
					sum = possib[mn].begin()->first;
					ntria = mn+1;

					for (int i = 0; i <= mn; i++)
					{
						cur = sum ^ possib[mn - i][sum];
						int cnt = 0;
						for (int j = 0; j < 12 && cnt < 3; j++)
						{
							if (cur & (1 << j))
							{
								triangles[i][cnt] = sticks[j];
								cnt++;
							}
						}
						sum ^= cur;
						possib[mn - i].clear();
					}
				}

			}

			printf("Case #%i: %i\n", t + 1, ntria);
			for (int i = 0; i < ntria; i++)
			{
				printf("%i %i %i\n", triangles[i][0], triangles[i][1], triangles[i][2]);
			}
		}
		else
		{
			printf("Case #%i: 0\n", t + 1);
		}
		
	}
}



int lprcomp(long long a, long long b, long long c)
{
	long long au = a / 1000000000, ab = a % 1000000000,bu= b / 1000000000, bb = b % 1000000000;
	long long ru = au * bu + (ab * bu + au * bb) / 1000000000;
	long long rb = ((ab * bu + au * bb) % 1000000000) * 1000000000 + ab * bb;
	if ((ru > 0)||(rb>c))
		return 1;
	else
		if (rb < c)
			return -1;
		else
			return 0;
}

long long funcmax(long long n, long long k)
{
	long long t = 1;
	while (t < n)
	{
		if (lprcomp(t, k, n) <= 0)
			t *= k;
		else
			return min(n, t + k - 1);
		t += k - 1;
	}
	return  min(n, t);
}

long long funclm(long long n, long long k)
{
	long long ans=0;
	while (n > 0)
	{
		ans += n % k;
		n /= k;
		if (n > 0)
			ans++;
	}
	ans--;
	return ans;
}

long long funcfind(long long l, long long r, long long k)
{
	if (r>l&&r>2&&r % k == 0)
		r--;
	if (r > l)
	{
		long long lm = min(funcfind(l / k, r / k, k) * k + k - 1, r);
		long long lm1 = funclm(lm, k);
		for (long long i = lm+1; i <= r; i++)
			if (funclm(i, k) > lm1)
			{
				lm = i;
				long long lm1 = funclm(lm, k);
			}
		return lm;
	}
	else
		return l;
}

void E699solve()
{
	unordered_map<int, int> prnums, grab, pasd;
	vector<int> nums[15];
	int k,tn,a;
	long long fsum = 0, bsum, sums[15];
	scanf("%I64d", &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%I64d", &tn);
		bsum = 0;
		for (int j = 0; j < tn ;j++)
		{
			scanf("%I64d", &a);
			prnums[a] = i;
			pasd[a] = 0;
			bsum += a;
			nums[i].push_back(a);
		}
		fsum += bsum;
		sums[i] = bsum;
	}
	if (fsum % k)
	{
		printf("No\n");
		return;
	}
	else
		bsum = fsum / k;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < nums[i].size(); j++)
		{
			if (prnums.find(bsum - sums[i] + nums[i][j]) != prnums.end())
			{
				grab[nums[i][j]] = bsum - sums[i] + nums[i][j];
			}
		}
	}
	unordered_map<int,int> ies, ns;
	vector<pair<int, int>>  grabd;
	unordered_map<int, vector<pair<int, int>>> cicles;
	unordered_map<int, int> combi;
	for (auto it = grab.begin(); it!=grab.end(); it++)
	{
		

		{
			ies.clear();
			ns.clear();
			grabd.clear();
			int cur = it->first;
			int i = prnums[cur];
			int ncur = it->second;
			int ni = prnums[ncur];
			while (ies.find(ni) == ies.end() && ns.find(ncur) == ns.end()&&grab.find(ncur)!=grab.end())
			{
				ies[ni] = grabd.size();
				ns[ncur] = grabd.size();
				grabd.push_back({ ncur,i + 1 });
				cur = ncur;
				i = ni;
				ncur = grab[cur];
				ni = prnums[ncur];
			}
			if (ns.find(ncur) != ns.end())
			{
				int mask = 0;
				for (int i = ns[ncur]; i < grabd.size(); i++)
				{
					mask |= 1 << prnums[grabd[i].first];
				}
				if (cicles.find(mask) == cicles.end())
				{
					for (int i = ns[ncur]; i < grabd.size(); i++)
					{
						cicles[mask].push_back(grabd[i]);
					}
					combi[mask] = 0;
				}
				for (int i = 0; i < grabd.size(); i++)
					pasd[grabd[i].first] = 1;
			}
			else
			{
				if (grab.find(ncur) == grab.end()||pasd[ncur])
				{
					for (int i = 0; i < grabd.size(); i++)
						pasd[grabd[i].first] = 1;
				}
				else
					for (int i = 0; i <= ies[ni]; i++)
						pasd[grabd[i].first] = 1;
			}
		}
	}
	int bits[15], bitc = 0, nmask, ov;
	for (int c = 0; c < 5 && combi.find((1 << k) - 1) == combi.end(); c++)
	{
		for (int i = 1; i < ((1<<k)-1); i++)
			if (combi.find(i) != combi.end())
			{
				bitc = 0;
				for (int b =0; b < k; b++)
					if (!((1 << b) & i))
					{
						bits[bitc] = b;
						bitc++;
					}
				nmask = 1<<bits[0];
				ov = 1;
				for (int j = 0; j < (1 << bitc)-1; j++)
				{
					if (combi.find(nmask) != combi.end()&&combi.find(nmask|i)==combi.end())
					{
						combi[i | nmask] = i | (nmask << 15);
					}
					for (int b = 0; ov && b < bitc; b++)
					{
						ov &= nmask >> bits[b];
						nmask ^= 1 << bits[b];
					}
				}
			}
	}
	if (combi.find((1 << k) - 1) != combi.end())
	{
		printf("Yes\n");
		queue<int> unpack;
		vector<int> masks;
		pair<int, int> outp[15];
		int mask;
		unpack.push((1 << k) - 1);
		while (unpack.size() > 0)
		{
			mask = unpack.front();
			unpack.pop();
			if (combi[mask])
			{
				unpack.push(combi[mask] >> 15);
				unpack.push(combi[mask] & ((1 << 15) - 1));
			}
			else
				masks.push_back(mask);
		}
		for (int i = masks.size()-1; i >=0; i--)
		{
			int a = masks[i];
			for (int j = cicles[a].size() - 1; j >= 0; j--)
				outp[prnums[cicles[a][j].first]] = cicles[a][j];
		}
		for (int i = 0; i < k; i++)
			printf("%I64d %I64d\n", outp[i].first, outp[i].second);
	}
	else
	{
		printf("No\n");
	}
}


unordered_map <int, int> cuts;
int j, n;
int rf[4000], lf[4000];
int solveD(int l, int r, int dir)
{
	if (cuts.find(dir * 25000000 + l * 5000 + r) != cuts.end())
		return cuts[dir * 25000000 + l * 5000 + r];
	else
	{
		int mincost = 400000000;
		if (r - l > 2)
		{
			for (int i = 1; i <= j && l + i < r; i++)
				if (dir)
				{
					mincost = min(mincost, rf[i - 1] + max(solveD(l, r - i , 1), solveD(r - i, r, 0)));
				}
				else
					mincost = min(mincost, lf[i - 1] + max(solveD(l, l + i, 1), solveD(l + i, r, 0)));
		}
		else
			if (r - l == 2)
			{
				if (dir)
					mincost = rf[0];
				else
					mincost = lf[0];
			}
			else
				mincost = 0;
		cuts[dir * 25000000 + l * 5000 + r] = mincost;
		return mincost;
	}
}

void solveDO()
{
	scanf("%i %i", &n, &j);
	for (int i = 0; i < j; i++)
		scanf("%i", lf + i);
	for (int i = 0; i < j; i++)
		scanf("%i", rf + i);
	printf("%i\n", solveD(0, n, 0));
}
string s;
vector<int> cs;
void solveCA()
{
	cin >> s;
	int n = s.size();
	for (int i = 0; i < (n - 2); i++)
	{
		if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o')
		{
			if (i < (n - 3))
			{
				if (s[i + 3] == 'o')
					cs.push_back(i + 2);
				else
				{
					cs.push_back(i + 3);
					s[i + 2] = 'x';
				}
			}
			else
			{
				cs.push_back(i + 3);
				s[i + 2] = 'x';
			}
		}
		else
			if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e')
			{
				cs.push_back(i + 2);
			}
	}
	printf("%i\n", cs.size());
	for (int i = 0; i < cs.size(); i++)
		printf("%i ", cs[i]);
	s.clear();
	cs.clear();
	printf("\n");
}

void solveD()
{
	unordered_map<string,int> s01, s10;
	int cnt00 = 0, cnt11 = 0, n;
	string s;
	scanf("%i", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s[0] == s[s.size() - 1])
		{
			if (s[0] == '0')
				cnt00++;
			else
				cnt11++;
		}
		else
		{
			if (s[0] == '0')
				s01.insert({ s,i });
			else
				s10.insert({ s,i });
		}
	}
	if (cnt11 > 0 && cnt00 > 0 && s10.size() == 0 && s01.size() == 0)
	{
		printf("-1\n");
		return;
	}
	vector<int> ans;
	if (s10.size() + 1 < s01.size())
	{
		int diff = s01.size() - s10.size() ;
		diff /= 2;
		for (auto st : s01)
		{
			string ts;
			for (int i = 0; i < st.first.size(); i++)
			{
				ts.push_back(st.first[st.first.size() - i - 1]);
			}
			

			auto t = s10.find(ts);
			if (s10.find(ts) == s10.end())
			{	
				diff--;
				ans.push_back(st.second);
				if (!diff)
					break;
			}

		}
		if (diff == 0)
		{
			printf("%i\n", ans.size());
			for (int i = 0; i < ans.size(); i++)
			printf("%i ", ans[i]+1);
			printf("\n");
		}
		else
			printf("-1\n");
	}
	else
	{
		if (s01.size() + 1 < s10.size())
		{
			int diff = s10.size() - s01.size();
			diff /= 2;
			for (auto st : s10)
			{
				string ts;
				for (int i = 0; i < st.first.size(); i++)
				{
					ts.push_back(st.first[st.first.size() - i - 1]);
				}
				if (s01.find(ts) == s01.end())
				{
					diff--;
					ans.push_back(st.second);
					if (!diff)
						break;
				}

			}
			if (diff == 0)
			{
				printf("%i\n", ans.size());
				for (int i = 0; i < ans.size(); i++)
				printf("%i ", ans[i]+1);
				printf("\n");
			}
			else
				printf("-1\n");
		}
		else
			printf("0\n\n");
	}

}

int main()
{
	int t;
	scanf("%i", &t);
	for (int i = 0; i < t; i++)
		solveD();
	return 0;
}

