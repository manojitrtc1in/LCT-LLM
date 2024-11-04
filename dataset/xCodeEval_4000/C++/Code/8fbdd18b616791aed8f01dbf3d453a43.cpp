#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 10;

int p[maxN], t, num[6][6], n;

vector <int> v[5][maxN];

string s;

void sang()
{
    for(int i=2; i*i<=1e5; ++i)
		if (p[i] == 0)
			for (long long j=i*i; j<=1e5; j+=i)
				p[j]=1;
	for(int i=2; i<1e5; ++i)
		if (p[i] == 0)
			for(int x=i, j=1; j<5; ++j)
				v[j][x/=10].push_back(i);
}

int DFS(int u)
{
    int x = 0;
    int res = 0;
	for (int i=0; i<u; ++i)
		x = x * 10 + num[u][i];
	if (u == n-1)
		return v[1][x].size();
	for (int i=0; i<v[n-u][x].size(); ++i)
	{
		int now = v[n-u][x][i];
		for(int j=n-1; j>u; --j)
		{
			num[u][j] = num[j][u] = now % 10;
			now /= 10;
		}
		res += DFS(u+1);
	}
	return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sang();
    cin >> t;
    while (t--)
    {
        cin >> s;
        n = s.length();
        for (int i=0; i<n; ++i)
            num[i][0] = num[0][i] = s[i] - '0';
        cout << DFS(1) << "\n";
    }
}



