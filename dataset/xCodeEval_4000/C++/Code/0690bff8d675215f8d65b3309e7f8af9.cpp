






























#include<bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define Unique(x) x.erase(unique(all(x)),x.end());

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

using namespace std;

const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

inline int read()
{
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	
	return f?ans:-ans;
	
	#undef gc
}

typedef long long ll;



ll n,m;

bool CanMove(ll x,ll y){return (x>=0&&x<n&&y>=0&&y<m);}

ll DFS1(ll x,ll y,ll sx,ll sy)
{
	x--,y--;
	sx--,sy--;
	
	ll val[n][m];
	queue<pair<ll,ll> > q;
	
	for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)val[i][j]=0;
	
	q.push(mp(x,y));
	val[x][y]=1;
	
	while(!q.empty())
	{
		pair<ll,ll> p=q.front();
		q.pop();
		
		ll X=p.first,Y=p.second;
		
		if(CanMove(X+1,Y+2)&&val[X+1][Y+2]==0){q.push(mp(X+1,Y+2));val[X+1][Y+2]=val[X][Y]+1;}
		if(CanMove(X+1,Y-2)&&val[X+1][Y-2]==0){q.push(mp(X+1,Y-2));val[X+1][Y-2]=val[X][Y]+1;}
		if(CanMove(X-1,Y+2)&&val[X-1][Y+2]==0){q.push(mp(X-1,Y+2));val[X-1][Y+2]=val[X][Y]+1;}
		if(CanMove(X-1,Y-2)&&val[X-1][Y-2]==0){q.push(mp(X-1,Y-2));val[X-1][Y-2]=val[X][Y]+1;}
		if(CanMove(X+2,Y+1)&&val[X+2][Y+1]==0){q.push(mp(X+2,Y+1));val[X+2][Y+1]=val[X][Y]+1;}
		if(CanMove(X+2,Y-1)&&val[X+2][Y-1]==0){q.push(mp(X+2,Y-1));val[X+2][Y-1]=val[X][Y]+1;}
		if(CanMove(X-2,Y+1)&&val[X-2][Y+1]==0){q.push(mp(X-2,Y+1));val[X-2][Y+1]=val[X][Y]+1;}
		if(CanMove(X-2,Y-1)&&val[X-2][Y-1]==0){q.push(mp(X-2,Y-1));val[X-2][Y-1]=val[X][Y]+1;}
	}
	
	return val[sx][sy];
}

vector<pair<ll,ll> > DFS2(ll x,ll y,ll sx,ll sy)
{
	x--,y--;
	sx--,sy--;
	
	ll val[n][m];
	pair<ll,ll> pre[n][m];
	
	for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)val[i][j]=0;
	
	vector<pair<ll,ll> > v;
	v.clear();
	
	queue<pair<ll,ll> > q;
	
	q.push(mp(x,y));
	val[x][y]=1;
	
	while(!q.empty())
	{
		pair<ll,ll> pp=q.front();
		q.pop();
		
		ll X=pp.first,Y=pp.second;
		
		if(CanMove(X+1,Y+2)&&val[X+1][Y+2]==0){q.push(mp(X+1,Y+2));val[X+1][Y+2]=val[X][Y]+1;pre[X+1][Y+2]=mp(X,Y);}
		if(CanMove(X+1,Y-2)&&val[X+1][Y-2]==0){q.push(mp(X+1,Y-2));val[X+1][Y-2]=val[X][Y]+1;pre[X+1][Y-2]=mp(X,Y);}
		if(CanMove(X-1,Y+2)&&val[X-1][Y+2]==0){q.push(mp(X-1,Y+2));val[X-1][Y+2]=val[X][Y]+1;pre[X-1][Y+2]=mp(X,Y);}
		if(CanMove(X-1,Y-2)&&val[X-1][Y-2]==0){q.push(mp(X-1,Y-2));val[X-1][Y-2]=val[X][Y]+1;pre[X-1][Y-2]=mp(X,Y);}
		if(CanMove(X+2,Y+1)&&val[X+2][Y+1]==0){q.push(mp(X+2,Y+1));val[X+2][Y+1]=val[X][Y]+1;pre[X+2][Y+1]=mp(X,Y);}
		if(CanMove(X+2,Y-1)&&val[X+2][Y-1]==0){q.push(mp(X+2,Y-1));val[X+2][Y-1]=val[X][Y]+1;pre[X+2][Y-1]=mp(X,Y);}
		if(CanMove(X-2,Y+1)&&val[X-2][Y+1]==0){q.push(mp(X-2,Y+1));val[X-2][Y+1]=val[X][Y]+1;pre[X-2][Y+1]=mp(X,Y);}
		if(CanMove(X-2,Y-1)&&val[X-2][Y-1]==0){q.push(mp(X-2,Y-1));val[X-2][Y-1]=val[X][Y]+1;pre[X-2][Y-1]=mp(X,Y);}
	}
	
	while(sx!=x||sy!=y)
	{
		v.pb(mp(sx+1,sy+1));
		
		pair<ll,ll> pp=pre[sx][sy];
		
		sx=pp.first,sy=pp.second;
	}
	
	return v;
}

vector<pair<ll,ll> > v;

ll x,y,sx,sy;

ll fl1,fl2;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m>>x>>y>>sx>>sy;
	
	fl1=((x+y)%2!=(sx+sy)%2);
	
	ll aa=DFS1(x,y,n/2,m/2);
	ll bb=DFS1(sx,sy,n/2,m/2);
	ll cc=DFS1(x,y,n/2+1,m/2);
	ll dd=DFS1(sx,sy,n/2+1,m/2);
	
	if(fl1==0)fl2=((dd<aa)||(bb<=aa));
	else fl2=(!((aa<=dd)||((cc-1)<=dd)));
	
	cout<<(fl2 ? "BLACK" : "WHITE")<<endl;
	
	if(fl2)
	{
		if(fl1)
		{
			v=DFS2(sx,sy,n/2+1,m/2);
			
			for(ll i=(ll)v.size()-1;i>=0;i--)
			{
				ll a,b;
				cin>>a>>b;
				
				cout<<v[i].first<<' '<<v[i].second<<endl;
			}
		}
		else
		{
			if(dd<aa)
			{
				v=DFS2(sx,sy,n/2+1,m/2);
				
				for(ll i=(ll)v.size()-1;i>=0;i--)
				{
					ll a,b;
					cin>>a>>b;
					
					cout<<v[i].first<<' '<<v[i].second<<endl;
					
					if((a==v[i].first)&&(b==v[i].second))return 0;
				}
			}
			else
			{
				v=DFS2(sx,sy,n/2,m/2);
				
				for(ll i=(ll)v.size()-1;i>=0;i--)
				{
					ll a,b;
					cin>>a>>b;
					
					ll c,d;
					
					c=abs(sx-a);
					d=abs(sy-b);
					
					if((c==1&&d==2)||(c==2&&d==1))
					{
						cout<<a<<' '<<b<<endl;
						
						return 0;
					}
					else
					{
						cout<<v[i].first<<' '<<v[i].second<<endl;
						
						sx=v[i].first,sy=v[i].second;
					}
				}
				
				ll a,b;
				cin>>a>>b;
				
				ll c,d;
				
				c=abs(sx-a);
				d=abs(sy-b);
				
				if((c==1&&d==2)||(c==2&&d==1))
				{
					cout<<a<<' '<<b<<endl;
					
					return 0;
				}
				else
				{
					sx++,sy+=2;
					
					cout<<sx<<' '<<sy<<endl;
					
					cin>>a>>b;
					
					c=abs(sx-a);
					d=abs(sy-b);
					
					if((c==1&&d==2)||(c==2&&d==1))
					{
						cout<<a<<' '<<b<<endl;
						
						return 0;
					}
					else
					{
						sx-=2;
						sy--;
						
						cout<<sx<<' '<<sy<<endl;
						
						sx+=2;
						sy--;
						
						cin>>a>>b;
						
						cout<<sx<<' '<<sy<<endl;
					}
				}
			}
		}
	}
	else
	{
		if(!fl1)
		{
			v=DFS2(x,y,n/2,m/2);
			
			cout<<v[v.size()-1].first<<' '<<v[v.size()-1].second<<endl;
			
			for(ll i=(ll)v.size()-2;i>=0;i--)
			{
				ll a,b;
				cin>>a>>b;
				
				cout<<v[i].first<<' '<<v[i].second<<endl;
			}
		}
		else
		{
			if(aa<=dd)
			{
				v=DFS2(x,y,n/2,m/2);
				
				cout<<v[v.size()-1].first<<' '<<v[v.size()-1].second<<endl;
				
				if(v[v.size()-1].first==x&&v[v.size()-1].second==y)return 0;
				
				for(ll i=(ll)v.size()-2;i>=0;i--)
				{
					ll a,b;
					cin>>a>>b;
					
					cout<<v[i].first<<' '<<v[i].second<<endl;
					
					if(v[i].first==x&&v[i].second==y)return 0;
				}
			}
			else
			{
				v=DFS2(x,y,n/2+1,m/2);
				
				ll P=sx,Q=sy;
				ll X=x,Y=y;
				
				for(ll i=(ll)v.size()-1;i>=0;i--)
				{
					ll c,d;
					
					c=abs(X-P);
					d=abs(Y-Q);
					
					if((c==1&&d==2)||(c==2&&d==1))
					{
						cout<<P<<' '<<Q<<endl;
						
						return 0;
					}
					else
					{
						cout<<v[i].first<<' '<<v[i].second<<endl;
						
						cin>>P>>Q;
						
						X=v[i].first;
						Y=v[i].second;
					}
				}
				
				ll c,d;
				
				c=abs(X-P);
				d=abs(Y-Q);
				
				if((c==1&&d==2)||(c==2&&d==1))
				{
					cout<<P<<' '<<Q<<endl;
					
					return 0;
				}
				else
				{
					X-=2,Y++;
					
					cout<<X<<' '<<Y<<endl;
					
					cin>>P>>Q;
					
					c=abs(X-P);
					d=abs(Y-Q);
					
					if((c==1&&d==2)||(c==2&&d==1))
					{
						cout<<P<<' '<<Q<<endl;
						
						return 0;
					}
					else
					{
						X+=2,Y++;
						
						cout<<X<<' '<<Y<<endl;
						
						cin>>P>>Q;
						
						X--,Y-=2;
						
						cout<<X<<' '<<Y<<endl;
						
						return 0;
					}
				}
			}
		}
	}
	
	

	return 0;
}