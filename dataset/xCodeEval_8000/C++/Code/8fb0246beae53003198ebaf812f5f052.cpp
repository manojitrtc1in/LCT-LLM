






















































































































#include<bits/stdc++.h>
#include <ctime>
using namespace std;
typedef unsigned long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
#define pb push_back
#define mp make_pair
#define mod 1000000007 
#define MxN 100000
#define pi acos(-1.0)










ll gcd(ll a, ll b)
{ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);
}  

ll findLcm(ll a, ll b)  
 {  
    return (a*b)/gcd(a, b);  
 }  

int gcd(int a, int b)
{ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);
}  

int findLcm(int a, int b)  
 {  
    return (a*b)/gcd(a, b);  
 }  



 





int xrr[]={-1,1,0,0};
int yrr[]={0,0,-1,1};
const int size=50;

void dfs(char arr[size][size], int visited[size][size], int x, int y,int n,int m)
{
	visited[x][y]=1;
	for(int k=0;k<4;k++)
	{
		int i = x+xrr[k];
		int j = y+yrr[k];
		if(i>=0 && i<=n && j>=0 && j<=m && visited[i][j]==0)
		{
			if(arr[i][j]=='G' || arr[i][j]=='.')
			{
				dfs(arr,visited,i,j,n,m);
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	

    

	

	
	
		int n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		ll ans = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				for(int k=j;k<n;k++)
				{
					ans = max(ans,(arr[i] | arr[j] | arr[k]));
				}
			}
		}
		cout<<ans<<endl;
	

    return(0);	
}




























































































































