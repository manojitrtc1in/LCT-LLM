




















using namespace std;
typedef pair<long long,long long>p;
set<p>s;
long long time[300005],cost;
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n+k; i++)
	{
		long long b;
		if (i <= n)
		{
			scanf("%I64d", &b);
			s.insert(p(b, i));
		}
		if (i > k)
		{
			p now = *s.rbegin();
			cost += now.first*(i - now.second);
			s.erase(now);
			time[now.second] = i;
		}
	}
	printf("%I64d\n", cost);
	for (int i = 1; i <= n; i++)
		printf("%I64d ", time[i]);
	return 0;
}