










using namespace std;
typedef __int64 vt;
typedef pair<vt,vt> PVV;
typedef pair<char,vt> PCV;
typedef pair<string,vt> PSV;
typedef map<vt,vt> MVV;
typedef map<char,vt> MCV;
typedef map<string,vt> MSV;





const int MAXN = 1e6 + 99, INF = 0x3f3f3f3f;
bool rule(PVV a, PVV b)
{
	return a.first < b.first;
}
int main()
{
	int n, d;
	scanf("%d%d", &n, &d);
	PVV ms[MAXN];
	fi(0, n)
		scanf("%I64d%I64d", &ms[i].first, &ms[i].second);
	sort(ms, ms + n, rule);
	vt ans = 0, maxv, minv, id0 = 0, j = 0;
	fi(0, n)
	{
		if (ms[i].first - ms[j].first < d)
		{
			id0 += ms[i].second;
			ans = max(ans, id0);
		}
		else
			id0 -= ms[j++].second,i--;
	}
	printf("%I64d", ans);
	return 0;
}
