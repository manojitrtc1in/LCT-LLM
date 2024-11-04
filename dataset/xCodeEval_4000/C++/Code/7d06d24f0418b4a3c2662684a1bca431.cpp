#include<bits/stdc++.h>
#define INF 2000000001 

using namespace std;
typedef pair<int,int> p;
int n;
int arrx[1001];
int arry[1001];
vector<int> vs[5];
int par[1001];
int rant[1001];
vector<p> tmp;
void init()
{
	for(int i=0 ; i<1000 ; i++)
	{
		par[i]=i;
		rant[i]=0;
	}
}
int find(int x)
{
	if(par[x]==x)
	{
		return x;
	}
	else
	{
		return par[x]=find(par[x]);
	}
}
void unit(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
	{
		return ;
	}
	if(rant[x]<rant[y])
	{
		par[x]=y;
		

	}
	else
	{
		par[y]=x;
		if(rant[x]==rant[y])
		{
			rant[x]++;
		}
	}
}

bool same(int x,int y)
{
	return find(x)==find(y);
}
bool solve_4(int t)
{
	if(t==270)
	{
		cout<<"yes"<<"\n";
	}
	vector<int>::iterator u,v;
	vector<p>::iterator h,k;
	bool ok=0;
	for(u=vs[1].begin() ; u!=vs[1].end() ; u++)
	{
		for(v=vs[2].begin() ; v!=vs[2].end() ; v++)
		{
			if(arrx[*u]==arrx[*v]&&abs(arry[*u]-arry[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
			if(arry[*u]==arry[*v]&&abs(arrx[*u]-arrx[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
		}
	}
	for(u=vs[4].begin() ; u!=vs[4].end() ; u++)
	{
		for(v=vs[3].begin() ; v!=vs[3].end() ; v++)
		{
			if(arrx[*u]==arrx[*v]&&abs(arry[*u]-arry[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
			if(arry[*u]==arry[*v]&&abs(arrx[*u]-arrx[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
		}
	}
	
	for(h=tmp.begin() ; h!=tmp.end()  ;h++)
	{
		for(k=tmp.begin() ; k!=h  ;k++)
		{
			if(arrx[(*h).first]==arrx[(*h).second]&&arrx[(*k).first]==arrx[(*k).second])
			{
				continue;
			}
			if(arry[(*h).first]==arry[(*h).second]&&arry[(*k).first]==arry[(*k).second])
			{
				continue;
			}
			if(arrx[(*h).first]==arrx[(*h).second])
			{
				if((abs(arrx[(*h).first]-arrx[(*k).first])<=t&&abs(arrx[(*h).first]-arrx[(*k).second])<=t)&&(abs(arry[(*k).first]-arry[(*h).first])<=t&&abs(arry[(*k).first]-arry[(*h).second])<=t))
				{
					ok=1;
				}
			}
			else if(arry[(*h).first]==arry[(*h).second])
			{
				if((abs(arry[(*h).first]-arry[(*k).first])<=t&&abs(arry[(*h).first]-arry[(*k).second])<=t)&&(abs(arrx[(*k).first]-arrx[(*h).first])<=t&&abs(arrx[(*k).first]-arrx[(*h).second])<=t))
				{
					ok=1;
				}
			}
		}
		if(ok)
		{
			break;
		}
	}
	tmp.clear();
	for(u=vs[1].begin() ; u!=vs[1].end() ; u++)
	{
		for(v=vs[3].begin() ; v!=vs[3].end() ; v++)
		{
			if(arrx[*u]==arrx[*v]&&abs(arry[*u]-arry[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
			if(arry[*u]==arry[*v]&&abs(arrx[*u]-arrx[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
		}
	}
	for(u=vs[2].begin() ; u!=vs[2].end() ; u++)
	{
		for(v=vs[4].begin() ; v!=vs[4].end() ; v++)
		{
			if(arrx[*u]==arrx[*v]&&abs(arry[*u]-arry[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
			if(arry[*u]==arry[*v]&&abs(arrx[*u]-arrx[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
		}
	}
	for(h=tmp.begin() ; h!=tmp.end()  ;h++)
	{
		for(k=tmp.begin() ; k!=h  ;k++)
		{
			if(arrx[(*h).first]==arrx[(*h).second]&&arrx[(*k).first]==arrx[(*k).second])
			{
				continue;
			}
			if(arry[(*h).first]==arry[(*h).second]&&arry[(*k).first]==arry[(*k).second])
			{
				continue;
			}
			if(arrx[(*h).first]==arrx[(*h).second])
			{
				if((abs(arrx[(*h).first]-arrx[(*k).first])<=t&&abs(arrx[(*h).first]-arrx[(*k).second])<=t)&&(abs(arry[(*k).first]-arry[(*h).first])<=t&&abs(arry[(*k).first]-arry[(*h).second])<=t))
				{
					ok=1;
				}
			}
			else if(arry[(*h).first]==arry[(*h).second])
			{
				if((abs(arry[(*h).first]-arry[(*k).first])<=t&&abs(arry[(*h).first]-arry[(*k).second])<=t)&&(abs(arrx[(*k).first]-arrx[(*h).first])<=t&&abs(arrx[(*k).first]-arrx[(*h).second])<=t))
				{
					ok=1;
				}
			}
		}
		if(ok)
		{
			break;
		}
	}
	tmp.clear();
	for(u=vs[1].begin() ; u!=vs[1].end() ; u++)
	{
		for(v=vs[4].begin() ; v!=vs[4].end() ; v++)
		{
			if(arrx[*u]==arrx[*v]&&abs(arry[*u]-arry[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
			if(arry[*u]==arry[*v]&&abs(arrx[*u]-arrx[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
		}
	}
	for(u=vs[3].begin() ; u!=vs[3].end() ; u++)
	{
		for(v=vs[2].begin() ; v!=vs[2].end() ; v++)
		{
			if(arrx[*u]==arrx[*v]&&abs(arry[*u]-arry[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
			if(arry[*u]==arry[*v]&&abs(arrx[*u]-arrx[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
		}
	}
	for(h=tmp.begin() ; h!=tmp.end()  ;h++)
	{
		for(k=tmp.begin() ; k!=h  ;k++)
		{
			if(arrx[(*h).first]==arrx[(*h).second]&&arrx[(*k).first]==arrx[(*k).second])
			{
				continue;
			}
			if(arry[(*h).first]==arry[(*h).second]&&arry[(*k).first]==arry[(*k).second])
			{
				continue;
			}
			if(arrx[(*h).first]==arrx[(*h).second])
			{
				if((abs(arrx[(*h).first]-arrx[(*k).first])<=t&&abs(arrx[(*h).first]-arrx[(*k).second])<=t)&&(abs(arry[(*k).first]-arry[(*h).first])<=t&&abs(arry[(*k).first]-arry[(*h).second])<=t))
				{
					ok=1;
				}
			}
			else if(arry[(*h).first]==arry[(*h).second])
			{
				if((abs(arry[(*h).first]-arry[(*k).first])<=t&&abs(arry[(*h).first]-arry[(*k).second])<=t)&&(abs(arrx[(*k).first]-arrx[(*h).first])<=t&&abs(arrx[(*k).first]-arrx[(*h).second])<=t))
				{
					ok=1;
				}
			}
		}
		if(ok)
		{
			break;
		}
	}
	tmp.clear();
	return ok;
}
bool solve_3(int t)
{
	vector<int>::iterator u,v;
	vector<p>::iterator h;
	bool ok=0;
	for(u=vs[1].begin() ; u!=vs[1].end() ; u++)
	{
		for(v=vs[2].begin() ; v!=vs[2].end() ; v++)
		{
			if(arrx[*u]==arrx[*v]&&abs(arry[*u]-arry[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
			if(arry[*u]==arry[*v]&&abs(arrx[*u]-arrx[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
		}
		
	}
	for(h=tmp.begin() ; h!=tmp.end()  ;h++)
	{
		
		for(u=vs[3].begin() ; u!=vs[3].end() ; u++)
		{
			if(*u==(*h).first||*u==(*h).second)
			{
				continue;
			}
			if(arrx[(*h).first]==arrx[(*h).second])
			{
				if(abs(arrx[*u]-arrx[(*h).first])<=t&&(abs(arry[*u]-arry[(*h).first])<=t&&abs(arry[*u]-arry[(*h).second])<=t))
				{
					ok=1;
				}
			}
			else if(arry[(*h).first]==arry[(*h).second])
			{
				if(abs(arry[*u]-arry[(*h).first])<=t&&(abs(arrx[*u]-arrx[(*h).first])<=t&&abs(arrx[*u]-arrx[(*h).second])<=t))
				{
					ok=1;
				}
			}
		}
		if(ok==1)
		{
			break;
		}
	}
	tmp.clear();
	for(u=vs[2].begin() ; u!=vs[2].end() ; u++)
	{
		for(v=vs[3].begin() ; v!=vs[3].end() ; v++)
		{
			if(arrx[*u]==arrx[*v]&&abs(arry[*u]-arry[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
			if(arry[*u]==arry[*v]&&abs(arrx[*u]-arrx[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
		}
	}
	for(h=tmp.begin() ; h!=tmp.end()  ;h++)
	{
		
		for(u=vs[1].begin() ; u!=vs[1].end() ; u++)
		{
			if(*u==(*h).first||*u==(*h).second)
			{
				continue;
			}
			if(arrx[(*h).first]==arrx[(*h).second])
			{
				if(abs(arrx[*u]-arrx[(*h).first])<=t&&(abs(arry[*u]-arry[(*h).first])<=t&&abs(arry[*u]-arry[(*h).second])<=t))
				{
					ok=1;
				}
			}
			else if(arry[(*h).first]==arry[(*h).second])
			{
				if(abs(arry[*u]-arry[(*h).first])<=t&&(abs(arrx[*u]-arrx[(*h).first])<=t&&abs(arrx[*u]-arrx[(*h).second])<=t))
				{
					ok=1;
				}
			}
		}
		if(ok==1)
		{
			break;
		}
	}
	tmp.clear();
	for(u=vs[1].begin() ; u!=vs[1].end() ; u++)
	{
		for(v=vs[3].begin() ; v!=vs[3].end() ; v++)
		{
			if(arrx[*u]==arrx[*v]&&abs(arry[*u]-arry[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
			if(arry[*u]==arry[*v]&&abs(arrx[*u]-arrx[*v])<=2*t)
			{
				tmp.push_back(p(*u,*v));
			}
		}
	}
	for(h=tmp.begin() ; h!=tmp.end()  ;h++)
	{
		
		for(u=vs[2].begin() ; u!=vs[2].end() ; u++)
		{
			if(*u==(*h).first||*u==(*h).second)
			{
				continue;
			}
			if(arrx[(*h).first]==arrx[(*h).second])
			{
				if(abs(arrx[*u]-arrx[(*h).first])<=t&&(abs(arry[*u]-arry[(*h).first])<=t&&abs(arry[*u]-arry[(*h).second])<=t))
				{
					ok=1;
				}
			}
			else if(arry[(*h).first]==arry[(*h).second])
			{
				if(abs(arry[*u]-arry[(*h).first])<=t&&(abs(arrx[*u]-arrx[(*h).first])<=t&&abs(arrx[*u]-arrx[(*h).second])<=t))
				{
					ok=1;
				}
			}
		}
		if(ok==1)
		{
			break;
		}
	}
	return ok;
}
bool solve_2(int t)
{
	vector<int>::iterator u,v;
	bool ok=0;
	for(u=vs[1].begin() ; u!=vs[1].end() ; u++)
	{
		for(v=vs[2].begin() ; v!=vs[2].end() ; v++)
		{
			if(arrx[*u]==arrx[*v]&&abs(arry[*u]-arry[*v])<=2*t)
			{
				ok=1;
			}
			if(arry[*u]==arry[*v]&&abs(arrx[*u]-arrx[*v])<=2*t)
			{
				ok=1;
			}
			if(abs(arrx[*u]-arrx[*v])<=t&&abs(arry[*u]-arry[*v])<=t)
			{
				ok=1;
			}
			
		}
		if(ok)
		{
			break;
		}
	}
	return ok;
}
bool solve(int k,int m)
{
	int r[n];
	int t=1;
	for(int i=0;  i<n ; i++)
	{
		bool create=1;
		for(int j=0 ; j<i ; j++)
		{
			if(same(i,j))
			{
				vs[r[j]].push_back(i);
				create=0;
				break;
			}
			
		}
		if(create)
		{
			r[i]=t;
			vs[t].push_back(i);
			t++;
		}
	}
	vector<int>::iterator u;
	if(m==4862)
	{
		for(int i=1 ; i<=3 ; i++)
		{
			for(u=vs[i].begin() ; u!=vs[i].end() ; u++)
			{
				cout<<*u<<" ";
			}
			cout<<"\n";
		}
	}
	if(k==2)
	{
		return solve_2(m);
	}
	if(k==3)
	{
		return solve_3(m);
	}
	if(k==4)
	{
		return solve_4(m);
	}
}
bool begin(int t)
{
	
	for(int i=1 ; i<=4 ; i++)
	{
		vs[i].clear();
	}
	tmp.clear();
	int res=n;
	init();
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<i ; j++)
		{
			if(arrx[i]==arrx[j]&&abs(arry[i]-arry[j])<=t)
			{
				if(!same(i,j))
				{
					unit(i,j);
					res--;
				}
			}
			if(arry[i]==arry[j]&&abs(arrx[i]-arrx[j])<=t)
			{
				if(!same(i,j))
				{
					unit(i,j);
					res--;
				}
			}
		}
	}
	
	if(res>=5)
	{
		return false;
	}
	else if(res==4)
	{
		return solve(4,t);
	}
	else if(res==3)
	{
		return solve(3,t);
	}
	else if(res==2)
	{
		return solve(2,t);
	}
	else if(res==1)
	{
		return true;
	}
}
int main()
{
	cin.tie(0);
	while(cin>>n)
	{
		for(int i=0 ; i<n ; i++)
		{
			cin>>arrx[i];
			cin>>arry[i];
		}
		long long int ub=INF;
		long long int lb=-1;
		while(ub-lb>1)
		{
			long long int mid=(ub+lb)/2;
			
			if(begin(mid))
			{
				
				ub=mid;
			}
			else
			{
				lb=mid;
			}
			
		}
		

		if(ub==INF)
		{
			cout<<-1<<"\n";
		}
		else
		{
			cout<<ub<<"\n";
		}
	}
}