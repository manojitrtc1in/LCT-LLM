
































































































using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int uint;
typedef long long INT;
typedef long double ldouble;
typedef pair<INT,INT> PII;
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;

char s[507];
int k;
int dp[507][507];
int last[507][507];

int pal(int l,int r)
{
	int cnt = 0;
	while(l<r)
	{
		cnt += (s[l] != s[r]);
		l++;
		r--;
	}
	return cnt;
}

string getstr(int l,int r)
{
	string str;
	for (int i = l, j = r; i < j; i++, j--)
		s[i] = s[j];
	for (int i = l; i <= r; i++)
		str += s[i];
	return str;
}

int main()
{
	scanf("%s", s);
	scanf("%d", &k);
	for (int i = 0; s[i]; i++)
	{
		dp[i][1] = pal(0, i);
		last[i][1] = -1;
		for (int j = 2; j <= k; j++)
			dp[i][j] = 13131313;

		for (int j = 0; j <= i; j++)
    {
      int rr = pal(j + 1, i);
      for (int x = 2; x <= k; x++)
      {
        if(dp[i][x]>dp[j][x-1]+rr)
        {
          dp[i][x] = dp[j][x - 1] + rr;
          last[i][x] = j;
        }
      }
    }
	}
  int strs = strlen(s);
  int x, ming = Inf;
  for (int i = 1; i <= k; i++)
    if(ming>dp[strs-1][i])
    {
      ming = dp[strs - 1][i];
      x = i;
    }
  cout << ming << endl;
  string out;
  int cur = strs - 1, curr = x;
  while (cur != -1)
  {
    if(cur!=strs-1)
      out = "+" + out;
    out = getstr(last[cur][curr] + 1, cur) + out;
    cur = last[cur][curr];
    curr--;
  }
  cout << out << endl;
  return 0;
}