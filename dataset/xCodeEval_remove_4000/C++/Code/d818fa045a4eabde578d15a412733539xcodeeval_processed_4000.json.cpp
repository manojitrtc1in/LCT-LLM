
































































































using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int uint;
typedef long long INT;
typedef long double ldouble;
typedef pair<INT,INT> PII;
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;

int n, k, dp[507][507], gao[507][507], killxu[507][507], ans = (13 * 13 * 13);
string s;
vpii out;

void id0(int n,int k)
{
	if(!n)
	{
		for (int i = SZ(out) - 1; i >= 0; i--)
		{
			if(i != SZ(out) - 1)
				cout << "+";
			int lxu = out[i].first, rxu = out[i].second;
			for (int j = lxu; j <= rxu; j++)
			{
				if(j<lxu+rxu-j)
					cout << s[lxu + rxu - j];
				else
					cout << s[j];
			}
		}
		return;
	}
	int xub = killxu[n][k];
	out.push_back(mp(xub + 1, n));
	id0(xub, k - 1);
}

int main()
{
	cin >> s;
	n = SZ(s);
	s = "B" + s;
	cin >> k;
	for (int l = 2; l <= n; l++)
		for (int i = 1; i <= n - l + 1; i++)
		{
			int j = i + l - 1;
			gao[i][j] = (s[i] != s[j]) + gao[i + 1][j - 1];
		}
	FILL1(dp);
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			if(dp[i][j] != -1)
				for (int x = i + 1; x <= n; x++)
					if(dp[x][j+1]==-1||dp[x][j+1]>dp[i][j]+gao[i+1][x])
					{
						dp[x][j + 1] = dp[i][j] + gao[i + 1][x];
						killxu[x][j + 1] = i;
					}
	for (int i = 1; i <= k; i++)
		if(dp[n][i]!=-1)
			ans = min(ans, dp[n][i]);
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		if(dp[n][i]==ans)
		{
			id0(n, i);
			return 0;
		}
}