




















































































#define _CRT_SECURE_NO_WARNINGS
#define mp make_pair 
#define pb push_back 

#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
#include <vector>
#include <queue>
#include <iomanip>
#include <cassert>
#include <set>
#include <map>
#include <unordered_map>
#include <random>

using namespace std;

typedef long long ll;
typedef double ld;

const ll N = 1e6 + 10;
const ll alp = 30;
const ll inf = 1e9 + 10;
const ll INF = 1e14 + 10;
const ll mod = 1e9 + 7;

#define M_PI	3.14159265358979323846




ll n, m, k;

ll a[N], b[N], c[3];

signed main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	

	

#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test = 1;
	cin >> test;
	while (test--)
	{
		cin >> n;
		c[0] = 0;
		c[1] = 0;
		c[2] = 0;
		for (int q = 0; q < n; q++)
		{
			cin >> a[q];
			c[a[q] % 3]++;
		}
		sort(a, a + n);
		if (a[n - 1] == 1)
		{
			cout << 1 << '\n';
			continue;
		}
		if (a[n - 1] % 3 == 0)
		{
			if (c[2] == 0 && c[1] == 0)
			{
				cout << a[n - 1] / 3;
			}
			else
			{
				cout << a[n - 1] / 3 + 1;
			}
			cout << '\n';
		}
		else if (a[n - 1] % 3 == 1)
		{
			if (c[2] == 0)
			{
				cout << a[n - 1] / 3 + 1;
			}
			else if (a[0] != 1)
			{
				int fl = 0;
				for (int q = 0; q < n; q++)
				{
					if (a[q] == a[n - 1] - 1)
					{
						fl = 1;
						break;
					}
				}
				cout << a[n - 1] / 3 + 1 + fl;
			}
			else {
				cout << a[n - 1] / 3 + 2;
			}
			cout << '\n';
		}
		else
		{
			if (c[1] == 0)
			{
				cout << a[n - 1] / 3 + 1;
			}
			else
			{
				cout << a[n - 1] / 3 + 2;
			}
			cout << '\n';
		}
	}
}