












using   namespace            std;
typedef long long             ll;
typedef unsigned long long   llu;
typedef pair<int, int>       pii;
const long long MAXN = 2e5 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
ll HASHprime = 1333331;



int main()
{
	int ans = INF, n, k;
	map<int, bool> t;
	vector<int> a[MAXN];
	scanf("%d%d", &n, &k);
	for (int i = 0, temp, cnt = 0; i < n; ++i, cnt = 0)
	{
		scanf("%d", &temp);
		while (temp)
			a[temp].push_back(cnt++), t[temp] = 1, temp /= 2;
	}
	for (auto it : t)
	{
		int i = it.first;
		if (a[i].size() < k)
			continue;
		sort(a[i].begin(), a[i].end());
		ans = min(ans, accumulate(a[i].begin(), a[i].begin() + k, 0));
	}
	cout << ans << endl;
}
