
using namespace std;
















int vis[1000000];
void dfs(vector<int>g[],int v)
{
	vis[v]=1;
	cout<<v<<" ";
	for(int i=0;i<g[v].size();i++)
	{
		if(vis[g[v][i]]==0)
		{
			dfs(g,g[v][i]);
		}
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



int md;

void cmpv(vector<int>&v,vector<int>&a,vector<int>&b)
{
	a.push_back(1);
	b.push_back(v[0]);
	int ptr=0;
	for(int i=1;i<=v.size()-1;i++)
	{
		if(v[i]==b[ptr])
		{
			a[ptr]++;
		}
		else
		{
			a.push_back(1);
			b.push_back(v[i]);
			ptr++;
		}
	}
}

int fnn(int x,int t,int tp)
{
	if(tp==0)
	{
		int ans=0;
		int fc;
		if(t%2==1)
		{
			fc=x;
		}
		else
		fc=-1*x;
		for(int i=1;i<=t;i++)
		{
			ans=(ans+fc)%md;
			fc=(fc*(-1*x))%md;
		}
		return ans;
	}
	else
	{
		int ans=0;
		int fc;
		if(t%2==0)
		{
			fc=-1;
		}
		else
		fc=1;
		for(int i=1;i<=t;i++)
		{
			ans=(ans+fc)%md;
			fc=(fc*(-1*x))%md;
		}
		return ans;
	}
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,k;
	cin>>n>>k;
	inv2(v,n);
	md=998244353;
	vector<int>vv;


	for(int i=1;i<=n;i=i+2)
	{
		vv.push_back(v[i]);
	}


	int ans1=1;
	int tans;




	for(int i=0;i<vv.size()-1;i++)
	{
		if(vv[i]!=-1&&vv[i]==vv[i+1])
		{
			cout<<0;
			return 0;
		}
	}
	int tc1=0,tc2=0;
	vector<int>a,b;
	cmpv(vv,a,b);
	if(b.size()==1)
	{
		if(b[0]==-1)
		{
			ans1=k;
			for(int i=1;i<a[0];i++)
			ans1=ans1*(k-1);
		}
		else
		{
			tc1=1;
		}
	}
	else
	{
		for(int i=0;i<b.size();i++)
		{
			if(i!=0&&i!=b.size()-1&&b[i]==-1&&a[i]==1&&k==2)
			{
				ans1=0;
				break;
			}
			if(b[i]==-1)
			{
				if(i==0||i==b.size()-1)
				{
					tans=power(k-1,a[i],md);
					ans1=(ans1*tans)%md;
				}
				else if(b[i-1]==b[i+1])
				{
					tans=fnn(k-1,a[i],0);
					ans1=(ans1*tans)%md;
				}
				else
				{
					tans=fnn(k-1,a[i]+1,1);
					ans1=(ans1*tans)%md;
				}
			}
			else
			{
				
			}
		}
	}
	vv.clear();
	for(int i=2;i<=n;i=i+2)
	vv.push_back(v[i]);
	for(int i=0;i<vv.size()-1;i++)
	{
		if(vv[i]!=-1&&vv[i]==vv[i+1])
		{
			cout<<0;
			return 0;
		}
	}




	int ans2=1;
	a.clear();
	b.clear();
	cmpv(vv,a,b);
	if(b.size()==1)
	{
		if(b[0]==-1)
		{
			ans2=k;
			for(int i=1;i<a[0];i++)
			ans2=ans2*(k-1);
		}
		else
		{
			tc2=1;
		}
	}
	else
	{
		for(int i=0;i<b.size();i++)
		{
			if(i!=0&&i!=b.size()-1&&b[i]==-1&&a[i]==1&&k==2)
			{
				ans2=0;
				break;
			}
			if(b[i]==-1)
			{
				if(i==0||i==b.size()-1)
				{
					tans=power(k-1,a[i],md);
					ans2=(ans2*tans)%md;
				}
				else if(b[i-1]==b[i+1])
				{
					tans=fnn(k-1,a[i],0);
					ans2=(ans2*tans)%md;
				}
				else
				{
					tans=fnn(k-1,a[i]+1,1);
					ans2=(ans2*tans)%md;
				}
			}
			else
			{
				
			}
		}
	}


	if(tc1==1&&tc2==1)
	{
		cout<<1;
		return 0;
	}
	if(tc1==1)
	{
		cout<<ans2;
		return 0;
	}
	if(tc2==1)
	{
		cout<<ans1;
		return 0;
	}
	int ans=(ans1*ans2+md)%md;
	if(ans<0)
	cout<<ans+md;
	else
	cout<<ans;
}