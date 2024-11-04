 















































using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;
const int INF=1e9+7;

vector<int> pc[27];
int change(char x)
{
	return int(x-'a');
}
string n,m;
int ans;
int pos;
int check;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	vector<int> ::iterator check;
	for(int i=0;i<n.length() ;i++)
	{
		

		pc[change(n[i])].pb(i);
	}
	if(pc[change(m[0])].size() !=0)
	pos=pc[change(m[0])][0];
	else
	{
		cout<<"-1";
		return 0;
	}
	ans=1;
	for(int i=1;i<m.length() ;i++)
	{
		

		

		check=upper_bound(pc[change(m[i])].begin(),pc[change(m[i])].end() ,pos );
		if(check==pc[change(m[i])].end()  )
		{
			if(pc[change(m[i])].size()==0 )
		    {
				cout<<"-1"<<endl;
				return 0;
		    }
			ans++;
			

			pos=pc[change(m[i])][0];
		}
		else
		pos=*check;
	}
	cout<<ans<<endl;
	return 0;
}
