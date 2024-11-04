 
















































using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;
typedef pair<pii,pii > piiii;
const int INF=1e9+7;

itn d[4]={1<<0,1<<1,1<<2,1<<3};
itn dy[4]={-1,0,1,0};
itn dx[4]={0,1,0,-1};
int a[1005][1005];
queue<piii> q;
int n,m;
pii start,end;
int dist[1005][1005][5];
int change(char x)
{
	if(x=='+')
	{
		return d[0]|d[1]|d[2]|d[3];
	}
	if(x=='-')
	{
		return d[0]|d[2];
	}
	if(x=='|')
	{
		return d[1]|d[3];
	}
	if(x=='^')
	return d[3];
	if(x=='v')
	return d[1];
	if(x=='<')
	return d[0];
	if(x=='>')
	return d[2];
	if(x=='L')
	return d[1]|d[2]|d[3];
	if(x=='R')
	return d[0]|d[1]|d[3];
	if(x=='U')
	return d[0]|d[1]|d[2];
	if(x=='D')
	return d[0]|d[2]|d[3];
	return 0;
}
bool pass(int x,int y,int A,int B)
{
	return (a[x][y]&(1<<((A+B)%4)));
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(itn i=1;i<=n;i++)
	{
		for(itn j=1;j<=m;j++)
		{
			char c;
			cin>>c;
			a[i][j]=change(c);
		}
	}
	cin>>start.first >>start.second >>end.first >>end.second ;
	for(itn i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int o=0;o<4;o++)
			{
				dist[i][j][o]=INF;
			}
		}
	}
	dist[start.first ][start.second ][0]=0;
	q.push(piii(pii(start.first ,start.second ),0));
	while(!q.empty() )
	{
		piii p=q.front() ;
		q.pop() ;
		pii tmp=p.first ;
		int now=p.second ;
		int steps=dist[tmp.first ][tmp.second ][now];
		

		if(tmp.first ==end.first  and tmp.second ==end.second )
		{
			

			cout<<steps<<endl;
			return 0;
		}
		piii u=piii(pii(tmp.first ,tmp.second ),(now+1)%4);
		if(steps+1<dist[tmp.first ][tmp.second ][u.second ])
		{
			dist[tmp.first ][tmp.second ][u.second ]=steps+1;
			q.push(u); 
		}
		for(int i=0;i<4;i++)
		{
			int tx=tmp.first +dx[i],ty=tmp.second +dy[i];
			if(pass(tmp.first ,tmp.second ,i,now) and pass(tx,ty,(i+2)%4,now) and tx>=1 and tx<=n
			and ty>=0 and ty<=m and steps+1<dist[tx][ty][now])
			{
				

				dist[tx][ty][now]=steps+1;
				q.push(piii(pii(tx,ty),now)); 
			}
		}
	}
	cout<<"-1";
	return 0;
}
