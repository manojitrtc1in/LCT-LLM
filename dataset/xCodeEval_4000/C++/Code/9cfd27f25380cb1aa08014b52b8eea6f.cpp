#define ln '\n'
#define All(x) x.begin(), x.end()
#define Len(x) (int)x.size()
#define len(x) (int)x.size()
#define _CRT_SECURE_NO_WARNINGS
#define CF int _t; cin >> _t; while(_t--) solve();
#define Files freopen("hamming.in", "r", stdin); freopen("hamming.out", "w", stdout);
#define fi(a, b) for(int i = a; i <= b; i++)
#define fj(a,b) for(int j = a; j <= b; j++)
#define fo(a,b) for(int o = a; o <= b; o++)
#define fw(a,b) for(int w = a; w <= b; w++)
#define fq(a, b) for(int q = a; q <= b; q++)

#define rfi(a, b) for(int i = a; i >= b; i--)
#define rfj(a, b) for(int j = a; j >= b; j--)
#define rfo(a, b) for(int o = a; o >= b; o--)
#define rfw(a, b) for(int w = a; w >= b; w--)
#define rfq(a, b) for(int q = a; q >= b; q--)

#define FI(a, b, c) for (int i = (a); i <= (b); i += (c))
#define FJ(a, b, c) for (int j = (a); j <= (b); j += (c))
#define FO(a, b, c) for (int o = (a); o <= (b); o += (c))
#define FQ(a, b, c) for (int q = (a); q <= (b); q += (c))
#define FE(a, b, c) for (int e = (a); e <= (b); e += (c))

#define RFI(a, b, c) for (int i = (a); i >= (b); i -= (c))
#define RFJ(a, b, c) for (int j = (a); j >= (b); j -= (c))
#define RFO(a, b, c) for (int o = (a); o >= (b); o -= (c))
#define RFQ(a, b, c) for (int q = (a); q >= (b); q -= (c))
#define RFE(a, b, c) for (int e = (a); e >= (b); e -= (c))

#define fel(v) for(auto el : v)
#define fto(v) for(auto to : v)
#define fu(v) for(auto u : v)
#define fai(A) for (auto i : (A))
#define faj(A) for (auto j : (A))
#define fao(A) for (auto o : (A))
#define faq(A) for (auto q : (A))
#define fae(A) for (auto e : (A))

#define pb push_back
#define ins insert
#define er erase
#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <cstdlib>
#include <climits>
#include <numeric>
#include <bitset>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;

typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}
class RMQ 

{
private:
	struct result
	{
		ll val; 

		int id; 

	};
	struct node
	{
		ll sum;
		ll mx;
		ll mn = 1e9;
		int id_mx;
		int id_mn;
		int left;
		int right;
		int bufN = 0;
		pair<ll, char>buf[2];
	};
	int ns;
	vector<node>d;
	result res;
	void addBuffer(pair<ll, char>bf, int i)
	{
		if (i >= d.size() || i < 1)
			return;
		if (d[i].bufN == 0)
		{
			d[i].buf[0] = bf;
			d[i].bufN++;
			return;
		}
		if (bf.second == 'p')
		{
			d[i].buf[0] = bf;
			d[i].bufN = 1;
			return;
		}
		if (d[i].buf[d[i].bufN - 1].second == 'p')
		{
			d[i].buf[1] = bf;
			d[i].bufN = 2;
			return;
		}
		d[i].buf[d[i].bufN - 1].first += bf.first;
		return;
	}
	void push(int i)
	{
		if (d[i].bufN == 0)
			return;
		if (d[i].buf[0].second == 's')
		{
			ll val = d[i].buf[0].first;
			if (d[i].left == d[i].right)
			{
				d[i].sum += val;
				d[i].mn += val;
				d[i].mx += val;
			}
			else
			{
				addBuffer({ val, 's' }, 2 * i);
				addBuffer({ val, 's' }, 2 * i + 1);
				d[i].sum += (d[i].right - d[i].left + 1) * val;
				d[i].mn += val;
				d[i].mx += val;
			}
			d[i].bufN = 0;
			return;
		}
		if (d[i].buf[0].second != 'p')
			exit(-1);
		ll el = d[i].buf[0].first;
		addBuffer({ el, 'p' }, 2 * i);
		addBuffer({ el, 'p' }, 2 * i + 1);
		d[i].sum = el * (d[i].right - d[i].left + 1);
		d[i].mn = d[i].mx = el;
		d[i].buf[0] = d[i].buf[1];
		d[i].bufN--;
		push(i); 

	}
	void updateNode(int i) 

	{
		push(i);
		push(2 * i);
		push(2 * i + 1);
		d[i].sum = d[2 * i].sum + d[2 * i + 1].sum;
		if (d[2 * i].mx >= d[2 * i + 1].mx)
		{
			d[i].mx = d[2 * i].mx;
			d[i].id_mx = d[2 * i].id_mx;
		}
		else
		{
			d[i].mx = d[2 * i + 1].mx;
			d[i].id_mx = d[2 * i + 1].id_mx;
		}
		if (d[2 * i].mn <= d[2 * i + 1].mn)
		{
			d[i].mn = d[2 * i].mn;
			d[i].id_mn = d[2 * i].id_mn;
		}
		else
		{
			d[i].mn = d[2 * i + 1].mn;
			d[i].id_mn = d[2 * i + 1].id_mn;
		}
	}
	void recAddNumber(int L, int R, ll x, int i = 1)
	{
		push(i);
		if (d[i].left > R || d[i].right < L)
			return;
		if (d[i].left >= L && d[i].right <= R)
		{
			addBuffer({ x, 's' }, i);
			push(i);
			return;
		}
		recAddNumber(L, R, x, 2 * i);
		recAddNumber(L, R, x, 2 * i + 1);
		updateNode(i);
	}
	void recCountSum(int L, int R, int i = 1)
	{
		push(i);
		if (d[i].right < L || d[i].left > R)
			return;
		if (d[i].left >= L && d[i].right <= R)
		{
			res.val += d[i].sum;
			return;
		}
		recCountSum(L, R, 2 * i);
		recCountSum(L, R, 2 * i + 1);
	}
	void recCountMin(int L, int R, int i = 1)
	{
		push(i);
		if (d[i].left > R || d[i].right < L)
			return;
		if (d[i].left >= L && d[i].right <= R)
		{
			if (res.val > d[i].mn)
			{
				res.val = d[i].mn;
				res.id = d[i].id_mn;
			} if (res.val == d[i].mn && res.id > d[i].id_mn)
			{
				res.val = d[i].mn;
				res.id = d[i].id_mn;
			}
			return;
		}
		recCountMin(L, R, 2 * i);
		recCountMin(L, R, 2 * i + 1);
	}
	void recCountMax(int L, int R, int i = 1)
	{
		push(i);
		if (d[i].left > R || d[i].right < L)
			return;
		if (d[i].left >= L && d[i].right <= R)
		{
			if (res.val < d[i].mx)
			{
				res.val = d[i].mx;
				res.id = d[i].id_mx;
			}
			else if (res.val == d[i].mx && res.id > d[i].id_mx)
			{
				res.val = d[i].mx;
				res.id = d[i].id_mx;
			}
			return;
		}
		recCountMax(L, R, 2 * i);
		recCountMax(L, R, 2 * i + 1);
	}
	void recSetNumber(int L, int R, ll x, int i = 1)
	{
		push(i);
		if (d[i].left > R || d[i].right < L)
			return;
		if (d[i].left >= L && d[i].right <= R)
		{
			addBuffer({ x, 'p' }, i);
			push(i);
			return;
		}
		recSetNumber(L, R, x, 2 * i);
		recSetNumber(L, R, x, 2 * i + 1);
		updateNode(i);
	}
public:
	RMQ(vector<ll>& a)
	{
		int n = (int)a.size();
		ns = 1;
		while (ns < n)
			ns *= 2;
		d.resize(2 * ns);
		for (int i = ns; i < d.size(); i++)
		{
			d[i].left = d[i].right = i;
		}
		for (int i = 0; i < n; i++)
		{
			d[i + ns].sum = d[i + ns].mn = d[i + ns].mx = a[i];
			d[i + ns].id_mn = d[i + ns].id_mx = i;
		}
		for (int i = ns - 1; i >= 1; i--)
		{
			d[i].left = d[2 * i].left;
			d[i].right = d[2 * i + 1].right;
			d[i].sum = d[2 * i].sum + d[2 * i + 1].sum;
			if (d[2 * i].mx >= d[2 * i + 1].mx)
			{
				d[i].mx = d[2 * i].mx;
				d[i].id_mx = d[2 * i].id_mx;
			}
			else
			{
				d[i].mx = d[2 * i + 1].mx;
				d[i].id_mx = d[2 * i + 1].id_mx;
			}
			if (d[2 * i].mn <= d[2 * i + 1].mn)
			{
				d[i].mn = d[2 * i].mn;
				d[i].id_mn = d[2 * i].id_mn;
			}
			else
			{
				d[i].mn = d[2 * i + 1].mn;
				d[i].id_mn = d[2 * i + 1].id_mn;
			}
		}
	}
	result findMinimum(int L, int R)
	{
		if (L > R)
			return { (ll)1e18, -1 };
		res.val = 1e18;
		res.id = -1;
		recCountMin(L + ns, R + ns);
		return res;
	}
	result findMaximum(int L, int R)
	{
		if (L > R)
			return { (ll)-1e18, -1 };
		res.val = -1e18;
		res.id = -1;
		recCountMax(L + ns, R + ns);
		return res;
	}
	void addNumber(int L, int R, ll x) 

	{
		if (L > R)
			return;
		recAddNumber(L + ns, R + ns, x);
	}
	void setNumber(int L, int R, ll x)
	{
		if (L > R)
			return;
		recSetNumber(L + ns, R + ns, x);
	}
	result findSum(int L, int R)
	{
		res.val = 0;
		res.id = -1;
		recCountSum(L + ns, R + ns);
		return res;
	}
	result findElement(int i)
	{
		res.val = 0;
		res.id = -1;
		recCountSum(i + ns, i + ns);
		return res;
	}
};


ll rnd(ll a, ll b)
{
	return rand() % (b - a + 1) + a;
}

void solveF()
{
	ll q;
	cin >> q;
	string s = "a", t = "a";
	vector<vector<ll>>v(3, vector<ll>(27));
	v[1][0] = 1;
	v[2][0] = 1;
	fi(1, q)
	{
		ll d, k;
		cin >> d >> k;
		string x;
		cin >> x;
		for (auto h : x)
		{
			v[d][h - 'a'] += k;
		}
		int b = -1;
		rfj(25, 0) if (v[2][j] != 0) {
			b = j;
			break;
		}
		int a = -1;
		fj(0, 25) if (v[1][j] != 0)
		{
			a = j;
			break;
		}
		bool answer = 1;
		ll mna = 0, mnb = 0;
		while (a < 26 && b > -1)
		{
			while (a < 26 && v[1][a] == 0)
				a++;
			while (b > -1 && v[2][b] == 0)
				b--;
			if (a == 26 || b == -1) break;
			

			if (a < b)
			{
				answer = 1;
				break;
			}
			if (b < a)
			{
				answer = 0;
				break;
			}
			ll mn = min(v[1][a], v[2][b]);
			if (v[1][a] == mn)
			{
				a++;
			}
			if (v[2][b] == mn)
			{
				b--;
			}
		}
		if (b == -1)
		{
			answer = 0;
		}
		if (answer)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
void solveG()
{
	ll n;
	cin >> n;
	vector<ll>a(n + 1);
	vector<pair<string, ll>>b;
	fi(1, n)
	{
		cin >> a[i];
		ll d = a[i];
		string t = "";
		while (d > 0)
		{
			t = t + char(d % 2 + '0');
			d /= 2;
		}
		while (t.size() != 32)
			t += "0";
		reverse(All(t));
		b.push_back({ t,a[i] });
	}
	vector<ll>ans;
	vector<bool>visited(n, false);
	fi(0, 31)
	{
		ll OR = 0;
		fw(0, Len(ans) - 1)
			OR |= ans[w];
		int id = -1;
		ll mx = -1;
		fj(0, Len(b) - 1)
		{
			if (visited[j])
				continue;
			ll d = (b[j].second | OR);
			if (mx < d)
			{
				mx = d;
				id = j;
			}
		}
		if (id != -1)
		{
			visited[id] = 1;
			ans.push_back(b[id].second);
		}
	}
	rfi(Len(b) - 1, 0)
		if (!visited[i])
			ans.push_back(b[i].second);
	fi(0, Len(ans) - 1)
		cout << ans[i]<< ' ';
	cout << ln;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solveG();
}


