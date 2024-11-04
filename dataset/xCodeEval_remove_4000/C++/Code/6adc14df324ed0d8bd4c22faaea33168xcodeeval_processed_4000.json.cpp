










using namespace std;
typedef long long ll;

inline int read() {
	char ch = getchar();int x = 0, f = 1;
	while (ch < '0' || ch>'9') { if (ch == '-')f = -1;ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0';ch = getchar(); }
	return x * f;
}






















































































ll t, a, ans, last;int n, m;
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n == 1)
		{
			cout << "a\n";
			continue;
		}
		a = n / 2;last = n - 2 * a + 1;
		for (int i = 1;i <= a;i++)
			cout << "a";
		if (last == 1)
			cout << "b";
		else if (last == 2)
			cout << "bc";
		for (int i = 1;i <= a - 1;i++)
			cout << "a";
		cout << endl;
	}
}


