#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,s1,t1,s2,t2;
int p2[2000001];
int a[2000001][2],b[2000001][2],c[2];
map<int,int>mp[2000001];
void c1(int x,int y,int z){
    if(a[y][0])c[y&1]+=z;if(a[y][1])c[(y&1)^1]+=z;
    if(a[y][0]&&a[y][1])t1+=z;if(!a[y][0]&&!a[y][1])s1+=z;
    if(b[x][0]&&b[x][1])t2+=z;if(!b[x][0]&&!b[x][1])s2+=z;
}
void d(int x,int y,int z){
    a[y][(x&1)^z]--;
    b[x][(y&1)^z]--;
    mp[x][y]=0;
}
void q(int x,int y,int z){
    a[y][(x&1)^z]++;
    b[x][(y&1)^z]++;
    mp[x][y]=z+1;
}
int main(){
    p2[0]=1;
    for(int i=1;i<2000001;i++)p2[i]=(1ll*p2[i-1]<<1ll)%mod;
    int s;
	cin>>n>>m>>s;
    s1=m;s2=n;
    while(s--){
        int x,y,z,ans;
        cin>>x>>y>>z;
        c1(x,y,-1);
        if(mp[x][y])d(x,y,mp[x][y]-1);
        if(z!=-1)q(x,y,z);
        c1(x,y,1);
        ans=(p2[s1]*(t1==0)+p2[s2]*(t2==0))%mod;
        ans=(ans-!c[0]-!c[1]+mod)%mod;
        cout<<ans<<endl;
    }
    return 0;
}

