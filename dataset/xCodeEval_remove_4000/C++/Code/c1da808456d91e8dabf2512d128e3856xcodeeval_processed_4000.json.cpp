



































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
int n,k,d;
string s;



bool cmp(int a,int b)
{
	int c1=abs((int)(s[a]-'0')-d);
	int c2=abs((int)(s[b]-'0')-d);
	if(c1<c2)return 1;
	if(c2<c1)return 0;
	if((s[a]-'0')>d)
	{
		if((s[b]-'0')<d)return 1;
		return (a<b);
	}
	else
	{
		if((s[b]-'0')>d)return 0;
		return (a>b);
	}
}


int main()
{
	ios_base::sync_with_stdio(false); 
	cin>>n>>k;
	cin>>s;
	int r=1e9+7;
	string r_val="";
	for(int j=0;j<=9;j++)
	{
		d=j;
		vi v;
		for(int i=0;i<n;i++)
		{
			v.pb(i);
		}
		sort(v.begin(),v.end(),cmp);
		string t=s; 
		int p=0;
		for(int i=0;i<k;i++)
		{
			t[v[i]]=char('0'+j);
			p+=abs(j-(s[v[i]]-'0'));
		}
		if(r>p || (r==p && r_val>t))
		{
			r=p;
			r_val=t;
		}
	}
	cout<<r<<endl<<r_val<<endl;
    return 0;
}

