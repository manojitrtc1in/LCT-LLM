



#include <bits/stdc++.h>
#define int long long
#define thaonguyen main

using namespace std;

const int Thaonguyen = 1e3+6;

string s,p;
int f[Thaonguyen][Thaonguyen], x,y, type[Thaonguyen][Thaonguyen];
void trace()
{
	x--;
	y--;
	while(x!=0||y!=0)
	{
		

		if(s[x]==p[y]&&x>=1&&y>=1)
		{
			x--;
			y--;
		}
		else
		{
			if(f[x][y]==f[x-1][y-1]+1&&x>=1&&y>=1)
			{
				cout<<"REPLACE "<<x<<" "<<p[y]<<endl;
				s[x]=p[y];
				x--;
				y--;
			}
			else
			{
				if(f[x][y]==f[x][y-1]+1&&y>=1)
				{
					cout<<"INSERT "<<x+1<<" "<<p[y]<<endl;
					y--;
				}
				else
				{
					cout<<"DELETE "<<x<<endl;
					x--;
				}
			}
		}
	}
	
}

signed thaonguyen()
{
	cin>>s>>p;	
	s='!'+s;
	p='_'+p;
	
	x = s.length();
	y = p.length();
	for(int i=0;i<=x;i++)
	{
		f[i][0] = i;
	}
	for(int i=0;i<=y;i++)
	{
		f[0][i] = i;
	}
	for(int i=1;i<x;i++)
	{
		for(int j=1;j<y;j++)
		{
			if(s[i] == p[j]) f[i][j] = f[i-1][j-1];
			else
			{
				f[i][j] = min(f[i-1][j-1], min(f[i][j-1], f[i-1][j])) + 1;
			}
		}
	}
	cout<<f[x-1][y-1]<<endl; trace();
}