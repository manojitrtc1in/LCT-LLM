









using namespace std;
typedef long long ll;

inline int read() {
	char ch = getchar();int x = 0, f = 1;
	while (ch < '0' || ch>'9') { if (ch == '-')f = -1;ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0';ch = getchar(); }
	return x * f;
}












































































int d[550];
char c[550];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int t;
	cin >> t;
	getchar();
	while (t--)
	{
		int num = 0, cnt = 0, sum = 0;
		memset(d, 0, sizeof(d));
		scanf("%s", c);
		for (int i = 0;i < strlen(c);i++)
		{
			d[c[i] - 'a']++;
		}
		sort(d, d + 26, cmp);
		

		

		

		

		

		for (int i = 0;i <= 26;i++)
		{
			if (d[i] == 0)
				break;
			num++;
		}
		



		for (int i = 0;i < num;i++)
		{
			if (d[i] > 3)
				cnt++;
			if (d[i] == 3)
				cnt++;
			else if (d[i] == 2)
				cnt++;
			else if (d[i] == 1)
				sum++;
		}
		cnt += sum / 2;
		cout << cnt << endl;

	}
}

