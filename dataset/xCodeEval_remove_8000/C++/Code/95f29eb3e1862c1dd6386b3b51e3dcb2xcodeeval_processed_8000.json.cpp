



















using namespace std;
char s[2510][5010];
int n;
int m;
int num[10],numtot,pos;
int kind[30];
void check(char *s1, char *s2)
{
	for (int i = 0; i < m; i++)
	{
		if (s1[i] != s2[i])
			num[numtot++] = i;
	}
}
bool solve()
{
	for (int i = 1; i < n; i++)
	{
		int erro = 0;
		int tnum[10];
		for (int k = 0; k < 26; k++)
			kind[k] = 0;
		bool judge = 0;
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] != s[0][j])
				tnum[erro++] = j;
			kind[s[i][j] - 'a']++;
			if (kind[s[i][j] - 'a'] >= 2)
				judge = 1;
		}
		if (erro == 0&&judge)
			continue;
		if (erro != 2)
			return false;
		else
		{
			erro--;
			if (s[i][tnum[erro]] != s[0][tnum[erro ^ 1]] || s[i][tnum[erro ^ 1]] != s[0][tnum[erro]])
				return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
	}
	bool judgee = 0;
	for (int i = 0; i < m; i++)
	{
		kind[s[0][i]-'a']++;
		if (kind[s[0][i]-'a'] >= 2)
			judgee = 1;
	}
	if (n != 1)
	{
		for (int i = 1; i < n&&numtot == 0; i++)
		{
			pos = i;
			check(s[0], s[i]);
		}
		if (numtot == 0 || numtot >= 2 && numtot <= 4)
		{
			if (numtot == 0)
			{
				swap(s[0][0], s[0][1]);
				printf("%s\n", s[0]);
				return 0;
			}
			else
			{
				if (judgee&& solve())
				{
					printf("%s\n", s[0]);
					return 0;
				}
					for (int i = 0; i < numtot; i++)
					{
						for (int j = i + 1; j < numtot; j++)
						{
							swap(s[0][num[i]], s[0][num[j]]);
							if (solve())
							{
								printf("%s\n", s[0]);
								return 0;
							}
							swap(s[0][num[i]], s[0][num[j]]);
						}
					}
					if(numtot!=2)
						printf("-1\n");
					else
					{
						for (int i = 0; i < 2; i++)
						{
							for (int j = 0; j < m; j++)
							{
								if (s[pos][num[i]] == s[0][j] && j != num[0] && j != num[1])
								{
									swap(s[0][j], s[0][num[i]]);
									if (solve())
									{
										printf("%s\n", s[0]);
										return 0;
									}
									swap(s[0][j], s[0][num[i]]);
								}
							}
						}
						printf("-1\n");
					}
			}
		}
		else
		printf("-1\n");
	}
	else
	{
		swap(s[0][0], s[0][1]);
		printf("%s\n", s[0]);
	}
	return 0;
}