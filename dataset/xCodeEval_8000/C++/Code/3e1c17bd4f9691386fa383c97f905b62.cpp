























#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<bitset>
#define ll long long
using namespace std;
const int maxn = 100010, inf = 1e9;
int n, ty, l, r, x;
bitset<maxn>v[26], ans;
char s[maxn], s2[maxn], c;
inline void read(int &k)
{
	int f = 1; k = 0; char c = getchar();
	while (c<'0' || c>'9') c == '-' && (f = -1), c = getchar();
	while (c <= '9' && c >= '0') k = k * 10 + c - '0', c = getchar();
	k *= f;
}
int main()
{
	scanf("%s", s + 1); int len = strlen(s + 1);
	for (int i = 1; i <= len; i++) v[s[i] - 'a'][i] = 1;
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(ty);
		if (ty == 1)
		{
			read(x); scanf("%c", &c);
			v[s[x] - 'a'][x] = 0;
			v[(s[x] = c) - 'a'][x] = 1;
		}
		else
		{
			read(l); read(r);
			scanf("%s", s2); int m = strlen(s2);
			if (r - l + 1<m) { puts("0"); continue; }
			ans.set();
			for (int j = 0; j<m; j++) ans &= (v[s2[j] - 'a'] >> j);
			printf("%d\n", (int)(ans >> (l)).count() - (int)(ans >> (r - m + 2)).count());
		}
	}
}
