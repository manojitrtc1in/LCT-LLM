










using   namespace            std;
typedef	long long             vt;
typedef unsigned long long   vt2;








const int MAXN = 1e6 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 1333331;



struct inf {
	string info;
	inf(pair<int, int> a, char* b)
	{
		info += to_string(a.first);
		info += to_string(a.second);
		fi(0, 3)
			info += b[i];
		info += '\0';
	}
};
struct can {
	bool rig;
	vector<inf> ste;
}vis[10000];
int main()
{
	int n, m;
	vt2 ans = 0;
	sd(n); sd(m);
	getchar();
	char ma[10000][10000];
	memset(ma, '\0', sizeof(ma));
	fi(0, n)
	{
		fj(0, m)
			scanf("%c", &ma[i][j]);
		getchar();
	}
	fi(0, m)
	{
		char cl[4], last = '\0';
		int cnt[4], chg = 0, next = 0, star = 0;
		memset(cl, '\0', sizeof(cl));
		memset(cnt, 0, sizeof(cnt));
		fj(0, n)
		{
			if (ma[j][i] != last)
			{
				last = ma[j][i], ++chg;
				cl[chg - 1] = last;
				cnt[chg - 1]++;
				if (chg == 2)
					next = j;
			}
			else
				cnt[chg - 1]++;
			if (chg > 3 || (chg == 3 && j == n - 1))
			{
				if (j == n - 1 && chg == 3)
					++j;
				if ((cnt[1] == cnt[2] && cnt[0] >= cnt[1]) || (cnt[0] == cnt[1] && cnt[2] >= cnt[1]) || (cnt[1] > 0 && cnt[0] >= cnt[1] && cnt[2] >= cnt[1]))
				{
					int st, et;
					if (cnt[1] == cnt[2] && cnt[0] == cnt[1])
						st = star, et = j - 1;
					else if (cnt[1] > 0 && cnt[0] >= cnt[1] && cnt[2] >= cnt[1])
						st = star + (cnt[0] - cnt[1]), et = j - 1 - cnt[2] + cnt[1];
					else
						st = star + ((cnt[1] == cnt[2] && cnt[0] > cnt[1]) ? (cnt[0] - cnt[1]) : 0), et = (cnt[0] == cnt[1] && cnt[2] > cnt[1]) ? j - 1 - cnt[2] + cnt[1] : j - 1;
					inf temp(pair<int, int>(st, et), cl);
					vis[i].rig = 1;
					vis[i].ste.push_back(temp);
				}
				memset(cl, 0, sizeof(cl));
				memset(cnt, 0, sizeof(cnt));
				chg = 0, last = '\0', j = next - 1, star = next;
			}
		}
	}
	map<string, pair<int, int>> ki;
	fi(0, m)
	{
		fa(vis[i].ste)
		{
			if (ki[it.info] == pair<int, int>(0, 0))
				ki[it.info].second++, ki[it.info].first = i;
			else
			{
				if (ki[it.info].first == i - 1)
					ki[it.info].first = i, ki[it.info].second++;
				else
				{
					vt2 tn = ki[it.info].second;
					ans +=(tn*tn+tn)/2;
					ki[it.info].second = 1;
					ki[it.info].first = i;
				}
			}
		}
	}
	fa(ki)
		if (it.second.second != 0)
		{
			vt2 tn = it.second.second;
			ans += (tn * tn + tn) / 2;
		}
	printf("%llu", ans);
	return 0;
}