


































#include <bits/stdc++.h>
using namespace std;



#define mp make_pair
#define pb push_back
#define on first
#define tw second
#define be(n) n.begin()
#define en(n) n.end()
#define all(n) (n.begin(),n.end())
#define pop(n) n.pop_back()
#define PI 3.141592653
#define son(n) int lf=2*n,ri=2*n+1
#define pr int prime[]={0,2,3,5,7,11,13,17,19,23,29,31,37}
#define sz(n) n.size()
#define big int maxi=-1
#define small int mini=1e9+7
#define op(x) freopen(x,"r",stdin)
#define wr(x) freopen(x,"w",stdout)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > pipi;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef stack<int> st;
typedef set<int> jihe;
typedef queue<int> qi;
typedef vector<pair<int,int> > vp;
const int inf=1e9+7;
const int maxn=400;
const int maxm=200005;
int n,d;
int s=0;
int maxi=-1;
int dp[30005][2*maxn+10];
int cnt[30005];




int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>d;
	memset(cnt,0,sizeof(cnt));
	int m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		cnt[x]++;
		m=max(m,x);
	}
	for(int i=0;i<=30000;i++)
	{
		for(int j=-maxn;j<=maxn;j++)
		{
			dp[i][maxn+j]=-123456312;
		}
	}
	dp[d][0+maxn]=cnt[0]+cnt[d];
	for(int i=d;i<=30000;i++)
	{
		for(int j=-maxn;j<=maxn;j++)
		{
			if(dp[i][j]+maxn==-123456312) continue;
			for(int z=-1;z<=1;z++)
			{
				int len=j+d+z;
				if(j+z<-maxn||j+z>maxn ||len<1 ||i+len>30000)
					continue;
			
			    dp[i+len][j+z+maxn]=max(dp[i+len][j+z+maxn],dp[i][j+maxn]+cnt[i+len]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=30000;i++)
	{
		for(int j=-maxn;j<=maxn;j++)
		{
			ans=max(ans,dp[i][j+maxn]);
		}
	}
	cout<<ans<<endl;
    return 0;
}

