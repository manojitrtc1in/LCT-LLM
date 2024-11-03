













































































































using namespace std;








static auto _ = []()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
}();



typedef std::vector<int> vi;

int global_mod(int x, int y)
{
	return (((x % y) + y) % y);
}

int ipow(int base, int exp)
{
	int result = 1;
	for (;;)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		if (!exp)
			break;
		base *= base;
	}

	return result;
}






	for (auto i : x) \
		cout << i << " ";

	for (auto i : x) \
		cout << i.first << " " << i.second << endl;












template <class T>
void in(T &x) { cin >> x; }
void in(float &d)
{
	string t;
	in(t);
	d = stof(t);
}
void in(double &d)
{
	string t;
	in(t);
	d = stod(t);
}
void in(long double &d)
{
	string t;
	in(t);
	d = stold(t);
}
template <class A, class B>
void in(pair<A, B> &a)
{
	in(a.fr);
	in(a.sc);
}
template <class A>
void in(vector<A> &a) { each(i, a) in(i); }
template <class H, class... T>
void in(H &h, T &...t)
{
	in(h);
	in(t...);
}



string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char *s) { return string(s); }
string to_string(string s) { return s; }
template <class A, class B>
string to_string(pair<A, B> &a)
{
	return to_string(a.fr) + " " + to_string(a.sc);
}
template <class T>
void prr(T x) { cout << to_string(x); }
template <class H, class... T>
void prr(const H &h, const T &...t)
{
	prr(h);
	prr(t...);
}

void prn() { prr("\n"); }
template <class T>
void prn(vector<T> x)
{
	each(i, x)
	{
		prr(i);
		prr(" ");
	}
	prn();
}
template <class H, class... T>
void prn(const H &h, const T &...t)
{
	prr(h);
	if (sizeof...(t))
		prr(' ');
	prn(t...);
}


	vi v;                       \
	for (int i = 0; i < x; i++) \
	{                           \
		int a;                  \
		cin >> a;               \
		v.push_back(a);         \
	}












void solve()
{
	int n;
	in(n);
	vip(v, n);
	string ans = "YES";

	for (int i = 0; i < n; i++)
	{
		int c = 0;
		for (int j = 2; j <= i + 2; j++)
		{
			if (v[i] % j != 0)
			{
				c = 1;
				break;
			}
		}
		if (c == 0)
		{
			ans = "NO";
			

		}
	}
	prn(ans);
}

main()
{
	sync


		freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);


	int test;
	in(test);
	while (test--)
		solve();
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}