


































#include <bits/stdc++.h>
using namespace std;
#define fro for
#define itn int
#define mp make_pair
#define pb push_back
#define one first
#define two second
#define fi(n) n.begin()
#define se(n) n.end()
#define all(n) (n).begin(),(n).end()
#define po(n) n.pop()
#define PI 3.141592653
#define son(n) int lf=2*n,ri=2*n+1
#define pr (int prime[]={0,2,3,5,7,11,13,17,19,23,29,31,37})
#define sz(n) n.size()
#define big int maxi=-1
#define rep(i,n) for(int (i)=1;(i)<=(n);(i)++)
#define small int mini=1e9+7
#define op(x) freopen(x,"r",stdin)
#define wr(x) freopen(x,"w",stdout)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > pipi;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef stack<int> sti;
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



int n,m,k;
int a[200005];



bool check(int x)
{
	int boxes=0,cnt=0;
	for(int i=x+1;i<=n;i++)
	{
		if(cnt+a[i]>k)
		{
			boxes++;
			cnt=a[i];
		}
		else cnt+=a[i];
	}
	if(cnt) boxes++;
	if(boxes>m) return 0;
	return 1;
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int l=0,r=n;
	int ans=inf;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid-1;ans=min(ans,mid);
		}
		else l=mid+1;
	}
	cout<<n-ans<<endl;
	return 0;
}

