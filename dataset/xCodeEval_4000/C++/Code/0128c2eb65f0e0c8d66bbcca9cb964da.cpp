#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;













































































bool can[15][150]={0};
void init()
{
	for(int i=1;i<=9;i++)
	{
		for(int k=1;k<=10;k++)
		{
			can[i][i*k]=1;
		}
		for(int k=1;k<=i;k++)
		{
			int thisOne=k*10+i;
			can[i][thisOne]=1;
			for(int j=1;j+thisOne<=i*10;j++)
			{
				if(can[i][j])
				{
					can[i][j+thisOne]=1;
				}
			}
		}
	}
}
void prt()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=i*10;j++)
		{
			printf("%d",can[i][j]);
		}
		puts("");
	}
}
int main()
{
	init();
	

	int N;
	cin >> N;
	while (N--)
	{
		int n, d;
		cin >> n >> d;
		for (int i = 0; i < n; i++)
		{
			int t;
			cd(t);
			

			if(t>=d*10)
			{
				puts("YES");
			}
			else
			{
				puts(can[d][t]?"YES":"NO");
			}
		}
	}
	return 0;
}





















