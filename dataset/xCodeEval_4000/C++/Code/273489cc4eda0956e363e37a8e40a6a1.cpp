

#include<vector>
#include<iterator>
#include<cmath>
#include<algorithm>
#include<set>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pob pop_back
#define loop0(n) for(ll i=0;i<n;i++)
#define loopn(x,n,flow) for(ll j=x;j<n;j+=flow)
#define loop1(x,n,inc) for(ll i=x;i<n;i+=inc)
#define loop2(x,n,dec) for(ll i=x;i>=0;i-=dec)
#include<bits/stdc++.h>
#define t int t;cin>>t;while(t--)
using namespace std;

int main()
{
	t{
		int n , m;
		cin >> n >> m;
		int comp[n][m];
		for(int i=0;i<n;i++)
		    {
		    	for(int j=0;j<m;j++)
		    	    {
		    	    	cin>>comp[i][j];
					}
			}
			
		int arr[n][m];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i == 0 || i == n - 1)
				{
					if (j == 0 || j == m - 1)
						arr[i][j] = 2;
					else
						arr[i][j] = 3;
				}
				else
				{
					if (j == 0 || j == m - 1)
						arr[i][j] = 3;
					else
						arr[i][j] = 4;
				}
			}
		}
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if(arr[i][j]<comp[i][j])
				   {
				   	flag = 1;
				   	break;
				   }
				   
			}
		if(flag == 1)
		   break;
		}
		
		if(flag == 1)
		   cout<<"NO"<<endl;
		else
		   {
		   cout<<"YES"<<endl;
		  for(int i=0;i<n;i++)
		    {
		    	for(int j=0;j<m;j++)
		    	    {
		    	    	cout<<arr[i][j]<<" ";
					}
				cout<<endl;
			}
	}
}
return 0;
}