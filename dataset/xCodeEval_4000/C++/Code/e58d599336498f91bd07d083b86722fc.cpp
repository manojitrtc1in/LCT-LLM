


































#include <bits/stdc++.h>
using namespace std;



#define fro for
#define itn int
#define mp make_pair
#define pb push_back
#define on first
#define tw second
#define be(n) n.begin()
#define en(n) n.end()
#define all(n) (n.begin(),n.end())
#define po(n) n.pop()
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
const int maxn=5005;
const int maxm=200005;
int Read(){
    int x=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x;
}
int n,k;
int a[10005],b[10005];
int ans=1e9+7;
string ans1;



int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	string ss;
	cin>>ss;
	ss='0'+ss;
	string tt=ss;
	for(int i=1;i<=10005;i++)
	{
		ans1=ans1+'z';
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=ss[i]-'0';
	}
	for(int i=0;i<=9;i++)
	{
		ss=tt;
		int cnt=0,s=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]==i)
			{
				cnt++;
			}
		}
		int d=0;
		while(cnt<k)
		{
			d++;
			for(int j=1;j<=n;j++)
			{
				if(i+d==a[j])
				{
					if(cnt<k)
					{
						cnt++;
						s+=d;
						ss[j]=i+'0';
					}
				}
			}
			for(int j=n;j>=1;j--)
			{
				if(i-d==a[j])
				{
					if(cnt<k)
					{
						cnt++;
						s+=d;
						ss[j]=i+'0';
					}
				}
			}
		}
		if(s<ans)
		{
			ans=s;
			ans1=ss;
		}
		else if(s==ans)
		{
			if(ans1>ss)
			{
				ans1=ss;
			}
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<ans1[i];
	}
	cout<<endl;
	return 0;
}

