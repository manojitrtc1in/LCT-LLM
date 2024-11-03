



























































































































































































































































































































































































































































































































































#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <iomanip>
#include <sstream>
#include <stack>
using namespace std;
const int MAXN = 1e5 + 20;
int n, m;
int turn[ 4 ][ 2 ] = {{ 1, 0 }, { -1 , 0 } , {0 , 1} , {0 , -1}};
int ans [ MAXN ];
int pop = 1;
int now [ MAXN ];
int f [ 30 ] [ 30 ];
int num [ 30 ] [ 30 ];
int ar [ 30 ] [ 30 ];
int flag = 0;
stack<int> s;
void dfs(int x, int y)
{
	if (x == n * m + 1)
	{
		flag = 1;
		for (int i = n ; i >= 1 ; i--)
		{
			for (int j = m ; j >= 1 ; j--)
			{
				s.push(ar [ i ] [ j ]);
			}
		}
		return ;
	}
	if (flag)
	{
		return ;
	}
	int maxx = (x - 1) / m + 1;
	int maxy = (x - 1) % m + 1;
	for (int i = 1 ; i <= n * m ; i++)
	{
		if ((y & (1 << i)) == 0)
		{
			if ((!num [ ar [ maxx - 1 ] [ maxy ] ] [ i ]) && (!num [ ar [ maxx ] [ maxy - 1 ] ] [ i ]))
			{
				int numar = y | (1 << i);
				

				ar [ maxx ] [ maxy ] = i;
				dfs(x + 1, numar);
			}
		}
	}
}
void solve()
{
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++)
		{
			f [ i ] [ j ] = (i - 1) * m + j;
		}
	}
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++)
		{
			for (int k = 0 ; k <= 3 ; k++)
			{
				int dx = i + turn [ k ] [ 0 ];
				int dy = j + turn [ k ] [ 1 ];
				if (f [ dx ] [ dy ] != 0)
				{
					num [ f [ i ] [ j ] ] [ f [ dx ] [ dy ] ] = num [ f [ dx ] [ dy ] ] [ f [ i ] [ j ] ] = 1;
				}
			}

		}
	}
	dfs(1, 0);
	if (flag)
	{
		cout << "YES" << endl;
		for (int i = 1 ; i <= n ; i++)
		{
			for (int j = 1 ; j <= m ; j++)
			{
				cout << s.top() << " ";
				s.pop();
			}
			cout << endl;
		}
	}
	else
	{
		cout << "NO" << endl;
	}
}
int main()
{
		cin >> n >> m;
		if (n <= 4 && m <= 4)
		{
			solve();
			return 0;
		}
		if (n < m)
		{
			cout << "YES" << endl;
			for (int i = 1 ; i <= n ; i++)
			{
				if (i & 1)
				{
					for (int j = (i - 1) * m + 1 ; j <= i * m ; j += 2)
					{
						cout << j << " ";
					}
					for (int j = (i - 1) * m + 2 ; j <= i * m ; j += 2)
					{
						cout << j << " ";
					}
					cout << endl;
				}
				else
				{
					for (int j = (i - 1) * m + 2 ; j <= i * m ; j += 2)
					{
						cout << j << " ";
					}
					for (int j = (i - 1) * m + 1 ; j <= i * m ; j += 2)
					{
						cout << j << " ";
					}
					cout << endl;
				}
			}
		}
		else
		{
			cout << "YES" << endl;
			for (int i = 1 ; i <= m ; i++)
			{
				if (i & 1)
				{
					now [ i ] = 1;
				}
				else
				{
					now [ i ] = 2;
				}
			}
			for (int i = 1 ; i <= n ; i++)
			{
				for (int j = 1 ; j <= m ; j++)
				{
					ans [ pop++ ] = (now [ j ] - 1) * m + j;
					now [ j ] += 2;
					if (now [ j ] > n)
					{
						now [ j ] = (j & 1) + 1;
					}
					

				}
			}
			for (int i = 1 ; i < pop ; i++)
			{
				cout << ans  [ i ];
				if (i % m == 0)
					cout << endl;
				else
					cout << ' ';
			}
		}
	}
