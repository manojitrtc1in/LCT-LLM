#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <string>  
#include <cstdlib>  
#include <cmath>  
#include <vector>  
#include <queue>  
#include <map>  
#include <algorithm>  
#include <set>  
#include <functional>  
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1e9 + 5;
const int MAX = 100005;
#define size 100005
const int MOD = 1e9 + 7;
const double eps = 1e-8;
const double PI = acos(-1.0);
LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a%b); }
LL ppow(LL a, LL b)
{
	LL res = 1;
	for (int i = 1; i <= b; i++)
	{
		res *= a;
	}
	return res;
}

int num[15];
int mid;
int lll;
int FLAG;
int w;
int n;
int ANS;
int ansa[100005];
int ansb[100005];
int ansc[100005];
int ansd[100005];

int getD(LL x)
{
	if (x == 0)
		return 1;
	int ans = 0;
	while (x)
	{
		x /= 10;
		ans++;
	}
	return ans;
}
LL getnum(LL x, int l, int r)
{
	x %= ppow(10, l);
	x /= ppow(10, r);
	return x;
}
int getdigit(LL x, int i)
{
	x /= ppow(10, i - 1);
	x %= 10;
	return x;
}
bool JUDGE(int a, int b, int c, int d)
{
	LL ans;
	ans = a;
	ans += ppow(10, getD(a))*b;
	ans += ppow(10, getD(a) + getD(b))*c;
	ans += ppow(10, getD(a) + getD(b) + getD(c))*d;
	int L;
	L = getD(a) + getD(b) + getD(c) + getD(d);
	for (int i = 1; i <= L/2+1; i++)
	{
		if (getdigit(ans, i) != getdigit(ans, L - i + 1))
			return false;
	}
	return true;
}

void judge(LL x)
{
	LL a, b, c, d;
	int l = getD(x);
	for (int i = 1; i <= l-1; i++)
	{
		a = getnum(x, i, 0);
		if ((getdigit(x, i) == 0) && (a != 0))
			continue;
		if (a > 255)
			continue;
		for (int j = i+1; j <= l; j++)
		{
			b = getnum(x, j, i);
			if ((getdigit(x, j) == 0) && (b != 0))
				continue;
			if (b > 255)
				continue;
			for (int k = j+1; k <= l+1; k++)
			{
				c = getnum(x, k, j);
				d = getnum(x, l, k);
				if (a % 10 == 0 && d != 0)
					continue;
				if (k == l + 1 && j!=l)
					continue;




				if (c > 255)
					continue;
				if (d > 255)
					continue;
				if (getD(a) + getD(b) + getD(c) + getD(d) != lll)
					continue;
				if (!JUDGE(a, b, c, d))
					continue;
				ansa[ANS] = a;
				ansb[ANS] = b;
				ansc[ANS] = c;
				ansd[ANS] = d;
				ANS++;
			}
		}
	}
}
bool JU(LL x)
{
	int t;
	bool flag[15];
	for (int i = 1; i <= n; i++)
	{
		flag[i] = false;
	}
	if (getD(x) < w)
	{
		FLAG = w-getD(x);
		for (int i = 1; i <= n; i++)
		{
			if (num[i] == 0)
				flag[i] = true;
		}
	}
	while (x)
	{
		t = x % 10;
		x = x / 10;
		for (int i = 1; i <= n; i++)
		{
			if (num[i] == t)
				flag[i] = true;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (num[i] == mid)
			flag[i] = true;
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == false)
			return false;
	}
	return true;
}
bool JU2(LL x)
{
	int t;
	bool flag[15];
	for (int i = 1; i <= n; i++)
	{
		flag[i] = false;
	}
	if (getD(x) < w)
	{
		FLAG = w-getD(x);
		for (int i = 1; i <= n; i++)
		{
			if (num[i] == 0)
				flag[i] = true;
		}
	}
	while (x)
	{
		t = x % 10;
		x = x / 10;
		for (int i = 1; i <= n; i++)
		{
			if (num[i] == t)
				flag[i] = true;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == false)
			return false;
	}
	return true;
}
LL get1(LL num)
{
	LL ans = num;
	int l = getD(num);
	if (FLAG)
		l+=FLAG;
	ans += ppow(10, l)*mid;
	for (int i = 1; i <= l; i++)
	{
		ans += ppow(10, l + l + 1 - i)*getdigit(num, i);
	}
	

	return ans;
}
LL get2(LL num)
{
	LL ans = num;
	int l = getD(num);
	if (FLAG)
		l+=FLAG;
	for (int i = 1; i <= l; i++)
	{
		ans += ppow(10, l + l - i)*getdigit(num, i);
	}
	return ans;
}

void dfs1(int ans, int p)
{
	if (p >= w)
	{
		FLAG = 0;
		if (JU(ans))
		{
		

			judge(get1(ans));
		}
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		dfs1(ans + ppow(10, p)*num[i], p+1);
	}
}
void dfs2(int ans, int p)
{
	if (p >= w)
	{
		FLAG = 0;
		if (JU2(ans))
			judge(get2(ans));
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		dfs2(ans + ppow(10, p)*num[i], p+1);
	}
}

void solve(int x)
{
	if (x % 2 == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			mid = num[i];
			w = (x - 1) / 2;
			dfs1(0, 0);
		}
	}
	else
	{
		w = x / 2;
		dfs2(0, 0);
	}
}

int main()
{




	lll = 11;
	judge(10100100101);
	while (scanf("%d",&n)!=EOF)
	{
		ANS = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
		}
		if (n >= 7)
		{
			printf("0\n");
			continue;
		}
		else if (n == 1 && num[1] == 0)
		{
			printf("1\n");
			printf("0.0.0.0\n");
			continue;
		}
		else
		{
			for (int i = max(4,2*n-1); i <= 12; i++)
			{
				lll = i;
				solve(i);
			}
		}
		printf("%d\n", ANS);
		for (int i = 0; i < ANS; i++)
		{
			printf("%d.%d.%d.%d\n", ansd[i], ansc[i], ansb[i], ansa[i]);
		}
	}
}





