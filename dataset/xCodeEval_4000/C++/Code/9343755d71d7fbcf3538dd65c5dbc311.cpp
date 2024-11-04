#include<algorithm>
#include <iostream>
#include  <cstring>
#include  <stdio.h>
#include   <string>
#include    <cmath>
#include      <map>
#include      <set>
#include   <vector>
#include    <queue>
#include   <time.h>
using namespace std;
typedef __int64 vt;
const int MAXM = 5e2+99;
using namespace std;
vt matrice1[600][600], matrice2[600][600];
int main()
{
	int n, m;
	cin >> n >> m;
	int cnt1 = 0;
	memset(matrice1, -1, sizeof(matrice1));
	memset(matrice2, -1, sizeof(matrice2));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >>matrice1[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> matrice2[i][j];
			if (matrice2[i][j] < matrice1[i][j])
				swap(matrice2[i][j], matrice1[i][j]);
		}
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
		{
			if (matrice1[x][y] <= matrice1[x - 1][y] || matrice1[x][y] <= matrice1[x][y - 1] || matrice2[x][y] <= matrice2[x - 1][y] || matrice2[x][y] <= matrice2[x][y - 1])
			{
				cout << "Impossible" << endl;
				return 0;
			}
		}
	cout << "Possible" << endl;
	return 0;
}
