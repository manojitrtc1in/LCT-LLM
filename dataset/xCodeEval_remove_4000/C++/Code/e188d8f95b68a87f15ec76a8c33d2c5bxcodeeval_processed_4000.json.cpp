

























































using namespace std;

					

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;


const int MAXN = 2007;
const ll inf = 2e9 + 239;
const ld EPS = 1e-4;
const ld PI = acos(-1);
int mod = (int)998244353;
const int MOD7 = 1000000007;
const int MOD9 = 1000000009;
const int a228 = 18;
const ll id0 = 1791791791;
const ll bestmod = 1148822869;
vector<ll> mods = { id0,bestmod,mod,MOD9,1000000007 };
vector<ll> id1 = { 29,31,37,43,47,53,179,229 };
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count() + 228 + 'i' + 'q' + 1337 + 1488);
ll MOD = mods[rnd() % mods.size()];
ll hashpow = id1[rand() % id1.size()];
signed main()
{
	fastio();
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	ll c1 = 1;
	ll c2 = 1;
	ll c3 = 1;
	ll c4 = 1;
	for (int i = 0; i < s1.size(); ++i)
	{
		c1 *= (s1[i] == '?' ? 10 : 1);
		c1 *= (s2[i] == '?' ? 10 : 1);
		c1 %= MOD7;
		if (s1[i] != '?' && s2[i] != '?' && s1[i] < s2[i]) c2 = 0;
		if (s1[i] != '?' && s2[i] != '?' && s1[i] > s2[i]) c3 = 0;
		if (s1[i] != '?' && s2[i] != '?' && s1[i] != s2[i]) c4 = 0;
		if (s1[i] == '?' && s2[i] == '?')
		{
			c4 *= 10;
			c4 %= MOD7;
			c2 *= 55;
			c2 %= MOD7;
			c3 *= 55;
			c3 %= MOD7;
		}
		if (s1[i] == '?' && s2[i] != '?')
		{
			c2 *= '9' - s2[i] + 1;
			c2 %= MOD7;
			c3 *= s2[i] - '0' + 1;
			c3 %= MOD7;
		}
		else if (s1[i] != '?' && s2[i] == '?')
		{
			c2 *= s1[i] - '0' + 1;
			c3 *= '9' - s1[i] + 1;
			c2 %= MOD7;
			c3 %= MOD7;
		}
	}
	cout << (c1 - c2 - c3 + c4 + 1ll *  MOD7 * 3) % MOD7;
	

}