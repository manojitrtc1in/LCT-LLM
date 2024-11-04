










using   namespace            std;
typedef	long long             vt;
typedef unsigned long long   vt2;
typedef	pair<vt,vt>          PVV;
typedef	pair<char,vt>        PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt,vt>           MVV;
typedef map<char,vt>         MCV;
typedef map<string,vt>       MSV;









const int MAXN = 6e6 + 99, INF = 0x3f3f3f3f;
const int MAXR = 1e5 + 99, MAXC = 1e5 + 99;
vt HASHprime = 13331;



char g[5000][5000];
int main()
{
	int f_y = -1, f_x = -1;
	int ans = 0;
	int cntx = 0, cnty = 0;
	int lastx=-1, lasty=-1, cx = 6666666, cy = 6666666, firstx=-1, firsty=-1;
	int h, w;
	cin >> h >> w;
	getchar();
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			scanf("%c", &g[i][j]);
			if (g[i][j] == '*')
			{
				if (f_y == -1)
				{
					f_y = j;
					firstx = i;
					cnty++;
					continue;
				}
				else
				{
					if (f_x == -1 && f_y != j)
					{
						f_x = i;
						firsty = j;
						cntx++;
						continue;
					}
				}
				if (j != f_y && i != f_x)
				{
					cout << "NO" << endl;
					return 0;
				}
				if (j == f_y && i != f_x)
				{
					cnty++;
					lasty = i;
				}
				else if (i == f_x && j != f_y)
				{
					cntx++;
					lastx = j;
				}
				else
				{
					cntx++;
					cnty++;
					cx = i;
					cy = j;
				}
			}
		}
		getchar();
	}
	if (lasty > cx && lastx > cy && cntx >= 3 && cnty >= 3 && firstx < cx && firsty < cy && cx != 6666666 && cy != 6666666 && lasty-firstx==cnty-1&&lastx-firsty==cntx-1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
