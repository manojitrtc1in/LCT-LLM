

















































































































































































































































































































































#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,N=2e5+5,M=5e6+5;
int seed = 0;
int base = 0;
int rnd(){
	int ret = seed;
	seed = (1ll*seed * base + 233)%mod;
	return ret;
}
int n,m,p[N],k[N],b[N],w[N],t[M],a[M],c[M];
void input(){
    cin>>n>>m;
    p[0] = 0;
    for(int i=1;i<=m;++i){
        cin >> p[i] >> k[i] >> b[i] >> w[i];
        seed = b[i];
        base = w[i];
        for(int j = p[i - 1] + 1; j <= p[i]; ++j)
            t[j] = rnd() % 2,
            a[j] = (rnd() % k[i])+1;
    }
}
long long sum[2];
signed main(){
    ios::sync_with_stdio(false);
    input();
    for(int i=1;i<=n;++i)
        sum[t[i]]+=a[i],c[i]=a[i];
    int T=0;
    if(sum[t[1]]>sum[t[1]^1]) a[1]--,T=t[1]^1;
    else T=t[1];
    long long cnt=0;
    for(int myhmd=0;myhmd<2;++myhmd)
        for(int i=1;i<=n;++i)
            if(t[i]==T) cnt+=a[i],a[i]=0;
            else{
                int tmp=min(cnt,(long long)a[i]);
                a[i]-=tmp,cnt-=tmp;
            }
    long long ans=1;
   

     

    for(int i=1;i<=n;++i){
        long long tmp=(1ll*i*i)^(c[i]-a[i]);
        tmp=(tmp+1)%mod;
        ans=1ll*ans*tmp%mod;
    }
    cout<<ans;
    return 0;
}                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                          
