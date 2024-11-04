#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define IO std::ios::sync_with_stdio(false), cin.tie(NULL)
#define lp(i,n) for(int i = 0 ; i< int(n) ;++i)
#define lp2(i,j,n) for(int i =int(j) ; i< int(n) ;++i)
#define OO 2147483647
#define MOD 1000000007
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define all(c) c.begin(), c.end()
#define FindLog(container, element) (container.find(element) != container.end())
#define Find(container, element) (find(all(container),element) != container.end())
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define odd(n)  ((n&1) == 1)
#define even(n) !(odd(n))
#define PI 3.1415926536
#define sp system("pause")
#define mp(x,y) make_pair(x,y)
#define MASK(size) bitset<size>
typedef long long ll;
typedef long double ld;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi > vvi;
ll gcd(ll a, ll b)
{
	return (b == 0 ? a : gcd(b, a % b));
}
ll lcm(ll a, ll b)
{
	return (a * (b / gcd(a, b)));
}
bool getbit(int num, int idx)

{
	return (num >> idx & 1) == 1;
}
int setbit(int num, int idx, bool val)

{
	if (val == true)
		return (num | (1 << idx));
	return num & ~(1 << idx);
}
int flipbit(int num, int idx)

{
	return num ^ (1 << idx);
}
int cntbits(int mask)

{
	int res = 0;
	while (mask)
		mask &= (mask - 1), res++;
	return res;
}
int main()
{
	int n, count = 0;
	cin >> n;
	vector<pair<int,pair<int, int> > >points(n);
	lp(i, n)
	{
		scanf("%d%d", &points[i].second.first, &points[i].second.second);
		count += 6;
		points[i].first = fabs(points[i].second.first) + fabs(points[i].second.second);
		if (points[i].second.first == 0 || points[i].second.second == 0)
			count -= 2;
	}
	sort(all(points));
	printf("%d\n", count);
	lp(i, n)
	{
		if (points[i].second.first > 0)
			printf("1 %d R\n", points[i].second.first);
		else if (points[i].second.first < 0)
			printf("1 %d L\n", -points[i].second.first);
		if (points[i].second.second > 0)
			printf("1 %d U\n", points[i].second.second);
		else if (points[i].second.second < 0)
			printf("1 %d D\n", -points[i].second.second);
		printf("2\n");
		if (points[i].second.first > 0)
			printf("1 %d L\n", points[i].second.first);
		else if (points[i].second.first < 0)
			printf("1 %d R\n", -points[i].second.first);
		if (points[i].second.second > 0)
			printf("1 %d D\n", points[i].second.second);
		else if (points[i].second.second < 0)
			printf("1 %d U\n", -points[i].second.second);
		printf("3\n");
	}
}































































































































































































































































































































































