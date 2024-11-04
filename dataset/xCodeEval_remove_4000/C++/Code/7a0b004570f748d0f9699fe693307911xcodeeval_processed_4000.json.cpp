

using namespace std;
















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































































































































































































































































































































































