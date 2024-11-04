 



#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<cstdio>
#include<map>
#include<stack>
#include<queue>
#include<cstring> 
#pragma comment(linker, "/STACK:1024000000,1024000000");  
using namespace std; 
int maxl[5000008];int n;
char s[5000008];
long long mod=51123987;long long ans=0;
void manancher()
{
	int m=n*2+1;
	int nnx=0,bel=0;maxl[1]=0;int ddd=0;
	for(int i=2;i<=m;i++)
	{
		if(nnx<i) nnx=i,bel=i;
		int reflect=bel+bel-i;
		if(maxl[reflect]!=nnx-i)
		{
			
			maxl[i]=min(nnx-i,maxl[reflect]);
		}
		else 
		{
			int j=nnx+1;
			while(i+i-j>-1 and s[j]==s[i+i-j]) j++;
			j--;
			maxl[i]=j-i;
		

		}
		if(nnx<i+maxl[i]) nnx=i+maxl[i],bel=i;
	};
	for(int i=1;i<=m;i++)
	{
		maxl[i]++;

		ans+=(long long)(maxl[i]-1)/2;if(i%2==0) ans++;
	}
	ans%=mod;ans=(ans)*(ans-1)/2;ans%=mod;
}
int c1[5000008],c2[5000008];
int calc()
{
	int m=n*2+1;
	for (int i=2;i<=m;i+=2)
    {
    	c1[i-maxl[i]+2]++;
    	c1[i+2]--;
    	c2[i]++;
    	c2[i+maxl[i]]--;
    }
    for (int i=1;i<=m;i+=2)
    {
    	c1[i-maxl[i]+2]++;
    	c1[i+1]--;
    	c2[i+1]++;
    	c2[i+maxl[i]]--;
    }
    for (int i=2;i<=m;i+=2)
    {
    	c1[i]+=c1[i-2];
    	if(c1[i]>=mod)c1[i]-=mod;
    	c2[i]+=c2[i-2];
    	if(c2[i]>=mod)c2[i]-=mod;
    }
    c1[m+1]=0;
    for (int i=m-1;i>=1;i-=2)
    {
    	c1[i]+=c1[i+2];
    	c1[i]%=mod;
    }
    for (int i=2;i<=m;i+=2)
    {
    	ans-=(long long)c2[i]*(long long)c1[i+2]%mod;
    	ans%=mod;
    }
	ans+=mod*5;
	cout<<ans%mod;
}
int main()
{
	cin>>n;s[0]=getchar();s[0]='1';
	for(int i=1;i<=n;i++)
	{
		s[i*2-1]='0',s[i*2]=getchar();
	}s[n*2+1]='0';s[n*2+2]='2';

	manancher();
	calc();
	return 0;
}


