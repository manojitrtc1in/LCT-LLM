




using namespace std;













typedef pair<int, int> PII;



ll inf;
ll qpow(ll x, ll t) { return t ? qpow(sqr(x) % inf, t >> 1) * (t & 1 ? x : 1) % inf : 1ll; }
inline int gcd(int a, int b) { while (b ^= a ^= b ^= a %= b); return a; }
int getSum(int a, int b) { return a ^ b + (a & b) << 1; }
inline void Prin(ll x) { if (x < 0) { putchar('-'); x = -x; }if (x > 9) Prin(x / 10); putchar(x % 10 + '0'); }
inline ll read() { ll x = 0, f = 1; char ch = getchar(); while (ch < '0' || ch>'9') { if (ch == '-') f = -1; ch = getchar(); }while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }return x * f; }


int m[200];
int n[200];
int mex(int a, int b) {
	int ans = b-a+1;
	inc(i, a, b)
		if (m[i] == 0)ans++;
	return ans;
}
signed main()
{
	IOS;
	int _;
	cin >> _;
	while (_--) {
		int ans = 0;
		int a;
		cin >> a;    
		inc(i, 1, a)
		{
			cin >> m[i];
		}
		inc(i, 1, a)
			inc(k, i, a)
			ans += mex(i, k);
		cout << ans << endl;
	}
	return 0;
}









































