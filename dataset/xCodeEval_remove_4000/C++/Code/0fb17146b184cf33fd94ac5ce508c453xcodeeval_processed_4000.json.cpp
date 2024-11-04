


 




typedef long long ll;







typedef std::pair<int, int> PII;
typedef std::pair<int, PII> PIII;
const int N = 2e5 + 5;
const int mod = 1000000007;



void Yes()
{
	std::cout << "YES" << endl;
	return;
}
void No()
{
	std::cout << "NO" << endl;
	return;
}





int id0(int a, int b) { return a ^ (1 << b); }


int setBit(int a, int b) { return a | (1 << b); }


int unsetBit(int a, int b) { return a & ~(1 << b); }


int getBit(int a, int b) { return (a >> b) & 1; }
void cmax(int& a, int b) {
	(a < b) && (a = b);
}
void cmin(int& a, int b) {
	(a > b) && (a = b);
}
ll qpow(ll a, ll n, ll mod)
{
	ll ans = 1;
	while (n)
	{
		if (n & 01)ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}
int inv(int x, int mod)
{
	return qpow(x, mod - 2, mod) % mod;
}
int gcd(int a, int b)
{
	if (b == 0)return a;
	return gcd(b, a % b);
}
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch>'9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}
struct reader
{
	template<typename Type>
	reader& operator >> (Type& ret)
	{
		int f = 1; ret = 0; char ch = getchar();
		for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
		for (; isdigit(ch); ch = getchar()) ret = (ret * 10) + ch - '0';
		ret *= f; return *this;
	}
}fin;

using namespace std;



struct preClass {
	bool init;
	preClass() { init = 1; }
};
template <typename _Ty>
struct Mat :preClass
{

public:
	Mat(const int& _row = 2, const int& _col = 2, const int& x = 0, const int& _MOD = 1000) {

		row = _row; col = _col;
		m = new _Ty[row * col];
		init = 0; MOD = _MOD;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (i == j && x)
					m[i * col + j] = x;
				else m[i * col + j] = 0;
			}
		}
	}
	~Mat() {

		MOD = 1, row = 2, col = 2;
		delete[]m;
		init = 1;
		m = nullptr;
	}
	Mat(const Mat<_Ty>& M) {

		if (init || m == nullptr)
		{
			row = M.row, col = M.col;
			m = new _Ty[row * col];
			MOD = M.MOD;
		}
		init = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				m[i * col + j] = M.m[i * col + j];
			}
		}
	}

	_Ty* operator [] (int pos) const
	{
		return &m[pos * col];
	}

	void operator = (initializer_list<_Ty> list) {
		auto k = list.begin();
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				m[i * col + j] = *(k++);
			}
		}
	}
	void operator = (const Mat<_Ty>& M) {
		if (init || m == nullptr)
		{
			row = M.row, col = M.col;
			m = new _Ty[row * col];
			MOD = M.MOD;
		}
		init = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				m[i * col + j] = M.m[i * col + j];
			}
		}
	}
	Mat<_Ty> operator +(const Mat<_Ty>& M)const
	{
		Mat<_Ty> c(row, col);
		row = M.row, col = M.col;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				c.m[i * col + j] = (m[i * col + j] + M.m[i * col + j]);
			}
		}
		return c;
	}
	Mat<_Ty> operator -(const Mat<_Ty>& M)const
	{
		Mat<_Ty> c(row, col);
		row = M.row, col = M.col;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				c.m[i * col + j] = (m[i * col + j] - M.m[i * col + j]);
			}
		}
		return c;
	}
	Mat<_Ty> operator * (const Mat<_Ty>& M)const {
		Mat<_Ty> c(row, M.col);
		int _col = M.col;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < _col; ++j) {
				for (int k = 0; k < col; ++k) {
					c.m[i * _col + j] =
						(c.m[i * _col + j] + m[i * col + k] * M.m[k * _col + j]) % MOD;
				}
			}
		}
		return c;
	}

	Mat<_Ty> operator / (const int& x) {
		Mat<_Ty> c(row, col);
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				c.m[i * col + j] = m[i * col + j] / x;
			}
		}
		return c;
	}
	Mat<_Ty> operator % (const int& mod)const {
		Mat<_Ty> c(row, col);
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				c.m[i * col + j] = m[i * col + j] % mod;
			}
		}
		return c;
	}
	void operator +=(const Mat<_Ty>& M) {
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				m[i * col + j] += M.m[i * col + j];
			}
		}
	}
	void operator -=(const Mat<_Ty>& M) {
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				m[i * col + j] -= M.m[i * col + j];
			}
		}
	}
	void operator %=(const int& x) {
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				m[i * col + j] %= x;
			}
		}
	}
	Mat<_Ty> pow(int y)const

	{
		Mat<_Ty> tem = *this;

		Mat<_Ty> ans(row, col, 1);
		while (y) {
			if (y & 1)
				ans = tem * ans;
			tem = tem * tem;
			y >>= 1;
		}
		return ans;
	}

	

	void Pow(int y)

	{
		Mat<_Ty> ans(row, col, 1);
		while (y) {
			if (y & 1)
				ans = m * ans;
			Self = Self * Self;
			y >>= 1;
		}
		*this = ans;
	}

	Mat<_Ty> Spow(Mat<_Ty>& a, string& s)const {

		Mat<_Ty> m(row, col, 1);
		int n = s.size() - 1;
		while (n >= 0) {
			int b = (int)(s[n] - '0');
			for (int i = 1; i <= b; i++)
				m = m * a;
			a = a * a;
			Mat<_Ty> y = a * a;
			y = y * y;
			a = a * y;
			n--;
		}
		return m;
	}
	int Row() { return row; }
	int Col() { return col; }
	

	friend ostream& operator<<(ostream& io, const Mat<_Ty>& mat)
	{
		int row = mat.Row(), col = mat.Col();
		for (int i = 0; i < row; i++)
		{
			cout << mat[i][0];
			for (int j = 1; j < col; j++)
				cout << ' ' << mat[i][j];
			cout << '\n';
		}
		return io;
	}
private:
	ll MOD;
	int row, col;
protected:
	_Ty* m;
};


void solve() {

	int n; cin >> n;
	if (n == 3) {
		cout << -1 << endl;
		return;
	}

	for (int i = 1; i <= n - 2;++i) 
		cout << i + 2 << ' ';
	cout << 2 << ' ' << 1 << endl;


}

signed main()
{
	Fast;
	int _ = 1;
	cin >> _;
	while (_--)
		solve();
}


