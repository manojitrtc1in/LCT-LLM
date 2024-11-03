



















using namespace std;











    
	

	

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;


const int inf=1e18;
const int mod=1e9+7;
const int maxn=505;
int hasher[maxn], power[maxn];
vector<int> occurances;

void init(string s, int n)
{
	

	hasher[0]=(s[0]-'a'+1);
	int cur=31, p=31;
	loop(i,1,n)
	{
		hasher[i]=hasher[i-1]+((s[i]-'a'+1)*power[i]);
		hasher[i]%=mod;
	}
}
int getHash(string s, int n)
{
	int res=0;
	int cur=1;
	loop(i,0,n)
	{
		int val=(s[i]-'a'+1)*power[i];
		val%=mod;
		res+=val;
		res%=mod;
	}
	return res;
}
void solve(int test)
{
	string s, t;
	cin >> s >> t;
	int n=s.size();
	int t_size=t.size();
	init(s, n);
	int t_hash=getHash(t, t_size);
	occurances.clear();
	loop(i,0,n)
	{
		int j=i+t_size-1;
		if(j>=n)
			break;
		int sub_hash=hasher[j];
		if(i>0ll)
		{
			sub_hash-=hasher[i-1];
			sub_hash+=mod;
		}
		sub_hash%=mod;
		int id0=t_hash*power[i];
		id0%=mod;
		if(sub_hash==id0)
		{
			occurances.push_back(i+t_size);
		}
	}
	int os=occurances.size();
	loop(i,0,os)
	{
		

	}
	

	int dp[n+1][n+1];
	

	memset(dp, 0, sizeof(dp));
	dp[0][0]=1;
	loop(i,1,n+1)
	{
		auto it=lower_bound(occurances.begin(), occurances.end(), i);
		if(it==occurances.end()||((*it)!=i))
			continue;
		if(i%t_size)
			break;
		dp[i][0]=1;
	}
	loop(i,1,n+1)
	{
		auto it=lower_bound(occurances.begin(), occurances.end(), i);
		loop(j,1,i+1)
		{
			if(it==occurances.end()||((*it)!=i))
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else
			{
				loop(k,0,os)
				{
					if(occurances[k]>=i-t_size+1&&occurances[k]<=i)
					{
						if(((occurances[k]-t_size)<0ll)||(j-(i-occurances[k])<0ll))
							continue;
						dp[i][j]+=dp[occurances[k]-t_size][j-(i-occurances[k])];
						dp[i][j]%=mod;
					}
				}
			}
		}
	}
	loop(i,0,n+1)
	{
		loop(j,0,n+1)
		{
			

		}
		

	}
	int pos;
	for(int i=n;i>=0;i--)
	{
		if(dp[n][i])
		{
			pos=i;
			break;
		}
	}
	cout << (n-pos)/t_size << ' ' << dp[n][pos] << nl;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);




	int T;
	

	cin >> T;
	power[0]=1;
	loop(i,1,maxn)
	{
		power[i]=power[i-1]*31;
		power[i]%=mod;
	}
	loop(test,1,T+1){
		

		solve(test);
	}
	return 0;
}
