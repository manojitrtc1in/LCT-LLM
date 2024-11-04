










using   namespace            std;
typedef long long             ll;
typedef unsigned long long   ull;







const long long MAXN = 1e5 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
ll HASHprime = 1333331;


struct robot
{
	int x, y, f[4];
}robots[MAXN];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		int right[4] = {-1e5,1e5,1e5,-1e5};
		scanf("%d", &n);
		fi(0, n)
		{
			scanf("%d%d", &robots[i].x, &robots[i].y);
			fj(0, 4)
			{
				scanf("%d", &robots[i].f[j]);
				if (!robots[i].f[j])
				{
					int last = j % 2 ? robots[i].y : robots[i].x;
					if(j==0||j==3)
						right[j] = max(last, right[j]);
					else
						right[j] = min(last, right[j]);
				}
			}
		}
		if (right[0] > right[2] || right[1] < right[3])
			cout << 0 << endl;
		else
			cout << 1 << ' ' << (right[0] + right[2]) / 2 << ' ' << (right[1] + right[3]) / 2 << endl;
	}
	return 0;
}
