



using namespace std;
using ld = long double;
const ld eps = 1e-9;
















































































































































































































































































































































































































































































































































































































































































































































































namespace FastFourierTransform
{
	using C = complex< double >;

	void id0(vector< C > &F, bool rev)
	{
		const int N = (int)F.size();
		const double PI = (rev ? -1 : 1) * acos(-1);
		for (int i = 0, j = 1; j + 1 < N; j++) {
			for (int k = N >> 1; k > (i ^= k); k >>= 1);
			if (i > j) swap(F[i], F[j]);
		}
		C w, s, t;
		for (int i = 1; i < N; i <<= 1) {
			for (int k = 0; k < i; k++) {
				w = polar(1.0, PI / i * k);
				for (int j = 0; j < N; j += i * 2) {
					s = F[j + k];
					t = C(F[j + k + i].real() * w.real() - F[j + k + i].imag() * w.imag(),
						F[j + k + i].real() * w.imag() + F[j + k + i].imag() * w.real());
					F[j + k] = s + t, F[j + k + i] = s - t;
				}
			}
		}
		if (rev) for (int i = 0; i < N; i++) F[i] /= N;
	}

	vector< int> Multiply(const vector< int > &A, const vector<int > &B)
	{
		int sz = 1;
		while (sz <= A.size() + B.size()) sz <<= 1;
		vector< C > F(sz), G(sz);
		for (int i = 0; i < A.size(); i++) F[i] = A[i];
		for (int i = 0; i < B.size(); i++) G[i] = B[i];
		id0(F, false);
		id0(G, false);
		for (int i = 0; i < sz; i++) F[i] *= G[i];
		id0(F, true);
		vector< int > X(A.size() + B.size() - 1);
		for (int i = 0; i < A.size() + B.size() - 1; i++) X[i] = F[i].real() + 0.5;
		return (X);
	}
};

bool operator<(const vector<int>&l, const vector<int>&r) {
	if (l.size() != r.size())return l.size()<r.size();
	else {
		for (int i = 0; i < l.size(); ++i) {
			if (l[i]<r[i])return true;
			else if (l[i]>r[i])return false;
		}
		return false;
	}
}

vector<int>operator*(const vector<int>&l, const vector<int>&r) {
	vector<int>v;
	if (r.size() == 1) {
		v = l;
		for (int i = 0; i< v.size(); ++i) {
			v[i] *= r[0];
		}
	}
	else {
		v = FastFourierTransform::Multiply(l, r);

	}
	for (int i = v.size() - 1; i >= 1; --i) {
		if (v[i] >= 100) {
			v[i - 1] += v[i] / 100;
			v[i] %= 100;
		}
	}
	if (v[0] >= 100) {
		v.insert(v.begin(), v[0] / 100);
		v[1] %= 100;
	}
	return v;
}

vector<int>vpow(vector<int>&a, int num) {
	if (num == 0)return vector<int>(1, 1);
	if (num == 1)return a;
	else {
		auto b = vpow(a, num / 2);
		vector<int>ans(b);
		ans = ans*b;
		if (num % 2) {
			ans = ans*a;
		}
		return ans;
	}
}

vector<int> check(const vector<int>&v, int n, int k) {
	vector<int>th(1, 3);
	vector<int>tw(1, 2);
	auto x = vpow(th, k);
	auto y = vpow(tw, n);
	vector<int>s = x*y;
	return s;
}

int solve(vector<int>v) {
	int ans = 1e9;

	int xmin = 0;

	if (v.size() >= 500000) {
		xmin = v.size() * 2 * 2.0959 - 3;
		if (v[0]>60)xmin += 2;
		else if (v[0]>15)xmin += 1;
	}
	else if (v.size()>1000) {
		xmin = v.size() * 2 * 2.0959 - 6;
		if (v[0]>60)xmin += 2;
		else if (v[0]>15)xmin += 1;
	}
	vector<int>ak = check(v, 0, xmin);
	for (int n = 0; n <= 2; ++n) {
		int amin = xmin;
		auto k = ak;
		vector<int>tt(1, 2);
		k = k*vpow(tt, n);

		

		while (true) {
			

			if (!(k < v)) {
				break;
			}
			else {

				int num = 1;
				vector<int>th(1, 3);
				if (k.size() < v.size()) {
					int a(k[0]);
					int b(v[0] * 100);
					if ((a + 1) * 85 < b) {
						num = 4;
						th = vector<int>(1, 81);
					}
					else if ((a + 1) * 30 < b) {
						num = 3;
						th = vector<int>(1, 27);
					}
					else if ((a + 1) * 10 < b) {
						num = 2;
						th = vector<int>(1, 9);
					}
				}
				else {
					int a(k[0]);
					int b(v[0]);
					if ((a + 1) * 85 < b) {
						num = 4;
						th = vector<int>(1, 81);
					}
					else if ((a + 1) * 30 < b) {
						num = 3;
						th = vector<int>(1, 27);
					}
					else if ((a + 1) * 10 < b) {
						num = 2;
						th = vector<int>(1, 9);
					}
				}
				k = k*th;
				amin += num;
			}
			

		}
		int nans = n * 2 + amin * 3;
		ans = min(ans, nans);
	}
	if (ans == 0)ans = 1;
	return ans;
}

char chs[2000000];
int main()
{
	string st;
	scanf("%s", chs);
	int i = 0;
	while (isdigit(chs[i])) {
		st.push_back(chs[i]);
		i++;
	}

	vector<int>v;
	for (int i = 0; i < st.size(); ++i) {
		if (st.size() % 2) {
			if (i == 0) {
				v.push_back(st[i] - '0');
			}
			else if (i % 2) {
				v.push_back(10 * (st[i] - '0'));
			}
			else {
				v[i / 2] += st[i] - '0';
			}
		}
		else {
			if (i % 2) {
				v[i / 2] += st[i] - '0';
			}
			else {
				v.push_back(10 * (st[i] - '0'));
			}
		}
	}
	int ans = solve(v);
	cout << ans << endl;

	return 0;
}