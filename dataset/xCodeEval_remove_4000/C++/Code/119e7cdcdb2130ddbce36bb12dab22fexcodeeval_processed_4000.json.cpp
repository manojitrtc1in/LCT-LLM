




using namespace std;














typedef pair<int, int> PII;



ll inf;
ll qpow(ll x, ll t) { return t ? qpow(sqr(x) % inf, t >> 1) * (t & 1 ? x : 1) % inf : 1ll; }
inline int gcd(int a, int b) { while (b ^= a ^= b ^= a %= b); return a; }
int getSum(int a, int b) { return a ^ b + (a & b) << 1; }
inline int read() {  

	char c = getchar();
	int x = 0, f = 1;
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

int m[200];
int n[200];
signed main()
{
	IOS;
	int _;
	cin >> _;
	while (_--) {
		int a;
		cin >> a;
		inc(i, 1, a )
			cin >> m[i];
		inc(i, 1, a )
			cin >> n[i];
		int ans = 0;
		int kz = a;
		dec(i, a, 1)
		{
			int sum=0;
			dec(k, i , 1)
			{
				int mx = 1;
				int pd = 0;
				inc(g, k + 1, i)
					if (m[g] - m[k - 1] < n[g]) { mx = 0; break; }
					else pd = max(pd,n[g] - n[k] - m[g] + m[k]);
				if (m[k]-m[k-1]>=n[k]&&mx) {
					sum += n[k] + pd;
					ans += (sum + 1) * sum / 2;
					i = k;
					break;
				}
				sum += m[k] - m[k - 1];
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}









































