#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<math.h>
#define SYNC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define F(i,m,n) for(int i=m;i<=n;i++)
#define f(i,m,n) for(int i=m;i>=n;i--)
#define debug(n) if(deb==1) cout<<#n<<"="<<n<<endl
#define deb(n) if(deb==1) cout<<#n<<"="<<n<<"	"
#define div(ch) if(deb==1) { for(int i=1;i<=20;i++) cout<<#ch; cout<<endl; }
#define mm(A,n) memset(A,n,sizeof(A))
#define lb(x) ((x)&(-x))
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 5010;
bool deb = 0;

int dp[maxn][maxn];

int main()
{
	int n;
	cin >> n;
	int a;
	vector<int> A, B;
	A.emplace_back(0);
	B.emplace_back(0);
	F(i, 1, n)
	{
		cin >> a;
		if (a)
			A.emplace_back(i);
		else
			B.emplace_back(i);
	}
	F(i, 1, A.size() - 1)
	{
		for (int j = 1; j < B.size(); j++)
		{
			if (i == 0)
				dp[i][j] = 0;
			else
				dp[i][j] = inf;
		}
	}
	for (int i = 1; i < A.size(); i++)
	{
		for (int j = i; j < B.size(); j++)
		{
			deb(i); debug(j);
			if (i < j)
				dp[i][j] = min(dp[i][j - 1], dp[i][j]);
			dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(A[i] - B[j]));
		}
	}
	cout << dp[A.size() - 1][B.size() - 1] << endl;
}


