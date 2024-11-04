
#include<bits/stdc++.h>
#include<set>
#include<unordered_map>

using namespace std;


#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i--)
#define link(x) for(edge *j=h[x];j;j=j->next)
#define mem(a) memset(a,0,sizeof(a))
#define ll long long
#define int ll
#define eps 1e-8
#define succ(x) (1ll<<(x))
#define lowbit(x) (x&(-x))
#define sqr(x) ((x)*(x))
#define mid ((x+y)/2)
#define pi 3.1415926535897931
typedef pair<int, int> PII;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#pragma warning(disable :4996)
#define mod 998244353  
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

char m[10];
map<int, int>n;
signed main()
{
	IOS;
	int _;
	cin >> _;
	while (_--) {
		mem(m);
		n.clear();
		int a;
		cin >> a;
		int pd = 0;
		inc(i, 1, a)
		{
			cin >> m;
			int b = strlen(m);
			if (!pd) {
				if (b == 1) {
					pd = 1;
				}
				if (b == 2) {
					if (m[0] == m[1])pd = 1;
					else {
						if (n[(int)m[1] * 1000 + (int)m[0]] ) { pd = 1; }
						if (!n[(int)m[0] * 1000 + (int)m[1]]|| n[(int)m[0] * 1000 + (int)m[1]]==2) { n[(int)m[0] * 1000 + (int)m[1]] = 1; }
					}
				}
				if (b == 3) {
					if (m[0] == m[2])pd = 1;
					else {
						if (n[(int)m[2] * 1000 + (int)m[1]] == 1) { pd = 1; }
						if (n[(int)m[2] * 1000000 + (int)m[1] * 1000 + (int)m[0]] == 1) { pd = 1; }
						if (!n[(int)m[0] * 1000 + (int)m[1]]) { n[(int)m[0] * 1000 + (int)m[1]] = 2; }
						if (!n[(int)m[0] * 1000000 + (int)m[1] * 1000 + (int)m[2]]) { n[(int)m[0] * 1000000 + (int)m[1] * 1000 + (int)m[2]] = 1; }
					}
				}
			}
		}
		if (pd)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}









































