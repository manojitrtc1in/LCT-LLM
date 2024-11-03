






















using namespace std;
bitset<100020>b[26],ans;
char s[100020],temp[100020];
void read(int &k)
{
	int v=0, f=1; char c = getchar();
	while (c <'0' || c>'9')
	{
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
	{
		v = v * 10 + c - '0';
		c = getchar();
	}
	k = v*f;
}
int main()
{
	scanf("%s", s+1);
	int lenn = strlen(s+1);
		for (int j = 1; j <=lenn; j++)
		{
				b[s[j]-'a'][j] = 1;
		}
	
	int m,kind;
	read(m);
	for (int i = 0; i < m; i++)
	{
		read(kind);
		if (kind == 2)
		{
			int l, r;
			read(l); read(r);
			scanf("%s", temp);
			int ll = strlen(temp);
			if (r-l+1<ll)
			{
				printf("0\n");
				continue;
			}
			ans.set();
			for (int i = 0; i < ll; i++)
			{
				ans &= (b[temp[i] - 'a']>>i);
			}
			
			printf("%d\n",(ans>>l).count()-(ans>>(r-ll+2)).count());
		}
		if (kind == 1)
		{
			int pos;
			char cc;
			read(pos);
			scanf("%c", &cc);
			char kk = s[pos] - 'a';
			b[kk][pos] = 0;
			b[(s[pos]=cc) - 'a'][pos] = 1;
		}
	}
}





