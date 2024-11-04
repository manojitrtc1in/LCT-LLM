



































using namespace std;





















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

string s;
pii d[11111];




int main()
{
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	cin>>s;
	int ans=1e9+7;
	string as="";
	string os=s;
	for(char c='0';c<='9';c++)
	{
		s=os;
		for(int i=0;i<n;i++)
		{
			d[i]={abs(s[i]-c),s[i]>=c?-(n-i):n-i};
		}
		sort(d,d+n);
		int cur=0;
		for(int i=0;i<k;i++)
		{
			cur+=d[i].first;
			int x=d[i].second;
			if(x<0)
			{
				x=-x;
			}
			x=-x+n;
			s[x]=c;
		}
		if(cur<ans || (cur==ans && s<as))
		{
			as=s;
			ans=cur;
		}
	}
	cout<<ans<<endl<<as<<endl;
    return 0;
}
