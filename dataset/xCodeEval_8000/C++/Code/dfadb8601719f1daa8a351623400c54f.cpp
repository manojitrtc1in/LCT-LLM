#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include<queue>
#include<map>
#include<string>
#include<string.h>
#include<vector>
#include<stack>
#include<set>
#include<fstream>

using namespace std;

long long d[200005], fs[200005], es[200005];
int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i];
	}
	memset(fs, 0, sizeof(fs));
	memset(es, 0, sizeof(es));
	fs[1] = d[1]; es[1] = d[n];
	for (int i = 2; i <= n; i++)
	{
		fs[i] = fs[i - 1] + d[i];
		es[i] = es[i - 1] + d[n - i + 1];
	}
	long long res = 0;
	int k=n;
	for (int i = n - 1; i > 0; i--)
	{
		if (fs[i] > es[n - i])
			continue;
		else if (fs[i] == es[n - i])
		{
			res = fs[i];
			break;
		}
		else
		{
			bool f = false;
			k = min(k, n - i - 1);
			for (int j = k; j > 0; j--)
			{
				if (fs[i] > es[j])
					break;
				else if (fs[i] < es[j])
				{
					k--;
					continue;
				}
				else
				{
					res = fs[i];
					f = true;
				}
			}
			if (f)
				break;
		}
	}
	cout << res << endl;
	return 0;
}







































