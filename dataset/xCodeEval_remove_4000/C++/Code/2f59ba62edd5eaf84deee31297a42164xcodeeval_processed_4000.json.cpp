
using namespace std;
















int vis[1000000];
int col[10000];
int ro[10000];
int ans;
int n,m;
vector<vector<int> >mk;
void dfs(int i,int j,vector<string>&s,int val)
{
	if(mk[i][j]==-1)
	return;
	else
	mk[i][j]=-1;
	if(col[j]==0||col[j]==val)
	col[j]=val;
	else
	ans=-1;
	if(ro[i]==0||ro[i]==val)
	ro[i]=val;
	else
	ans=-1;
	int vvc=1;
	if(mk[i-1][j]==0)
	{
		if(s[i-1][j]=='
		dfs(i-1,j,s,val);
	}
	if(mk[i+1][j]==0)
	{
		if(s[i+1][j]=='
		dfs(i+1,j,s,val);
	}
	if(mk[i][j+1]==0)
	{
		if(s[i][j+1]=='
		dfs(i,j+1,s,val);
	}
	if(mk[i][j-1]==0)
	{
		if(s[i][j-1]=='
		dfs(i,j-1,s,val);
	}
}

































int ispalin(string s){for(int i=0;i<s.size()/2;i++){if(s[i]!=s[s.size()-1-i]){	return 0;}}return 1;}


void id4(string pat, int M,int* lps) { int len = 0; lps[0] = 0; int i = 1; while (i < M) { if (pat[i] == pat[len]) { len++; lps[i] = len; i++; } else { if (len != 0) { len = lps[len - 1]; } else { lps[i] = 0; i++; } } } }
void kmp(string pat, string txt,vector<int>&v) { int M = pat.size(); int N = txt.size(); int lps[M]; id4(pat, M, lps); int i = 0; int j = 0; while (i < N) { if (pat[j] == txt[i]) { j++; 	i++; } if (j == M) { 	v.push_back(i-j);	j = lps[j - 1]; } else if (i < N && pat[j] != txt[i]) { 	if (j != 0) j = lps[j - 1]; else i = i + 1; } } }








const int MAXS = 500; 
const int MAXC = 26; 
int out[MAXS]; 
int f[MAXS]; 
int g[MAXS][MAXC]; 
int id1(vector<string>arr, int k) { memset(out, 0, sizeof out); memset(g, -1, sizeof g); int states = 1; for (int i = 0; i < k; ++i) { const string &word = arr[i]; int currentState = 0; for (int j = 0; j < word.size(); ++j) { int ch = word[j] - 'a'; if (g[currentState][ch] == -1) g[currentState][ch] = states++; currentState = g[currentState][ch]; } out[currentState] |= (1 << i); } for (int ch = 0; ch < MAXC; ++ch) if (g[0][ch] == -1) g[0][ch] = 0; memset(f, -1, sizeof f); queue<int> q; for (int ch = 0; ch < MAXC; ++ch) { if (g[0][ch] != 0) { f[g[0][ch]] = 0; q.push(g[0][ch]); } } while (q.size()) { int state = q.front(); q.pop(); for (int ch = 0; ch <= MAXC; ++ch) { if (g[state][ch] != -1) { int failure = f[state]; while (g[failure][ch] == -1) failure = f[failure]; failure = g[failure][ch]; f[g[state][ch]] = failure; out[g[state][ch]] |= out[failure]; 	q.push(g[state][ch]); } } } return states; } 
int id2(int currentState, char nextInput) { int answer = currentState; int ch = nextInput - 'a'; while (g[answer][ch] == -1) answer = f[answer]; return g[answer][ch]; } 
void aho(vector<string>arr, string text,vector<vector<pair<int,int> > >&v) { int k=arr.size();id1(arr, k); int currentState = 0; 	for (int i = 0; i < text.size(); ++i) { currentState = id2(currentState, text[i]); if (out[currentState] == 0) 	continue; for (int j = 0; j < k; ++j) { if (out[currentState] & (1 << j)) { pair<int,int>pr;pr.first=i - arr[j].size() + 1;pr.second=i;v[j].push_back(pr);} } } } 








void id3(int limit, vector<int>& prime) {  bool mark[limit + 1];  memset(mark, false, sizeof(mark));  for (int i = 2; i <= limit; ++i) {   if (mark[i] == false) {   prime.push_back(i); for (int j = i; j <= limit; j += i) mark[j] = true; } } } 
void primes(int low, int high,vector<int>&x,map<int,int>&mp) { int limit = floor(sqrt(high)) + 1; vector<int> prime; id3(limit, prime); int n = high - low + 1;  bool mark[n + 1];  memset(mark, false, sizeof(mark));  for (int i = 0; i < prime.size(); i++) {  int loLim = floor(low / prime[i]) * prime[i]; if (loLim < low) loLim += prime[i]; if(loLim==prime[i])   loLim += prime[i]; for (int j = loLim; j <= high; j += prime[i]) mark[j - low] = true; } for (int i = low; i <= high; i++) if (!mark[i - low]) {x.push_back(i);mp[i]=1;}mp[1]=0;} 






int spf[MAXN];  
void sieve() { spf[1] = 1; for (int i=2; i<MAXN; i++) spf[i] = i; for (int i=4; i<MAXN; i+=2) spf[i] = 2; for (int i=3; i*i<MAXN; i++) { if (spf[i] == i) { 	for (int j=i*i; j<MAXN; j+=i) if (spf[j]==j) spf[j] = i; } } } 
void primefact(int x,vector<int>&v,map<int,int>&mp) {  sieve();while (x != 1) { if(mp[spf[x]]==0)		v.push_back(spf[x]); 	mp[spf[x]]++;x = x / spf[x]; }  }




int power(int x, int y, int p){int res = 1;x = x % p;while (y > 0){if (y & 1)res=(res*x) % p;y = y>>1;x = (x*x) % p;}return res;}


const int N = 1000001;

  int factorialNumInverse[N + 1]; int naturalNumInverse[N + 1]; int fact[N + 1]; void id5(int p) {  naturalNumInverse[0] = naturalNumInverse[1] = 1;  for (int i = 2; i <= N; i++)   naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; } void id0(int p) {  factorialNumInverse[0] = factorialNumInverse[1] = 1; for (int i = 2; i <= N; i++) factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; } void factorial(int p) {  fact[0] = 1;  for (int i = 1; i <= N; i++) {  fact[i] = (fact[i - 1] * i) % p; } } int ncr(int N, int R, int p) {    int ans = ((fact[N] * factorialNumInverse[R])   % p * factorialNumInverse[N - R])  % p; return ans; }  







int sum(vector<int>v,int a,int b){int ans=0;for(int i=a;i<=b;i++)ans=ans+v[i];return ans;}
int sum(int arr[],int a,int b){int ans=0;for(int i=a;i<=b;i++)ans=ans+arr[i];return ans;}
void count(vector<int>v,int a,int b,vector<int>&x,map<int,int>&m){for(int i=a;i<=b;i++){if(m[v[i]]==0){x.push_back(v[i]);}m[v[i]]++;}}





main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	vector<string>s(n+2);
	string temp="";
	for(int i=0;i<=m+1;i++)
	temp=temp+'0';
	s[0]=temp;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]='0'+s[i]+'0';
	}
	s[n+1]=temp;
	for(int i=0;i<=n+1;i++)
	{
		vector<int>x(m+2);
		for(int j=0;j<=m+1;j++)
		x[j]=0;
		mk.push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		int ch=0;
		for(int j=2;j<=m;j++)
		{
			if(s[i][j-1]!=s[i][j])
			ch++;
		}
		if(s[i][1]=='
		{
			cout<<-1;return 0;
		}
		if(s[i][1]=='.'&&ch>=3)
		{
			cout<<-1;return 0;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int ch=0;
		for(int i=2;i<=n;i++)
		{
			if(s[i-1][j]!=s[i][j])
			ch++;
		}
		if(s[1][j]=='
		{
			cout<<-1;return 0;
		}
		if(s[1][j]=='.'&&ch>=3)
		{
			cout<<-1;return 0;
		}
	}	
	int val=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='
			{
				if(mk[i][j]==0)
				{
			

					dfs(i,j,s,val);
					if(ans==-1)
					{
						cout<<-1;
						return 0;
					}
					else
					val++;
				}
			}
			else
			{
				mk[i][j]=-1;
			}
		}
	}
	if(val==1)
	{
		cout<<0;
		return 0;
	}
	int z1=0,z2=0;
	for(int i=1;i<=n;i++)
	{
		if(ro[i]==0)
		{
			z1=1;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(col[i]==0)
		{
			z2=1;
			break;
		}
	}
	if((z1==0&&z2==1)||(z1==1&&z2==0))
	{
		cout<<-1;return 0;
	}	
	cout<<val-1;
}