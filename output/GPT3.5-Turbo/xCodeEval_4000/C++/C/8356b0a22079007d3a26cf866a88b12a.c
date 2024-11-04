#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
#define rank rk124232
#define y1 y20160116
#define y0 y20160110
#define _ 0

inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

#define Maxn 9
#define Maxm 77

int x,k,n,q;
int tl;
struct mat{
    LL dist[Maxm][Maxm];
    mat(){
        for (int i=0;i<Maxm;i++){
            for (int j=0;j<Maxm;j++){
                dist[i][j]=1e18;
            }
        }
    }
};

int id[256];
mat T1;
int cc=0;
LL c[Maxn];
void _init(){
    for (int i=0;i<(1<<k);i++){
        int cnt=0;
        for (int j=0;j<k;++j){
            if (i>>j&1) cnt++;
        }
        if (cnt!=x) continue;

        id[i]=++cc;
    }
    for (int i=0;i<(1<<k);i++){
        int cnt=0;
        for (int j=0;j<k;++j){
            if (i>>j&1) cnt++;
        }
        if (cnt!=x) continue;

        int v=i>>1;
        int u=i&1;
        if (!u){
            T1.dist[id[i]][id[v]]=0;
        }
        else{
            for (int j=0;j<k;j++){
                if (v&(1<<j)) continue;
                T1.dist[id[i]][id[v^(1<<j)]]=c[j+1];
            }
        }
    }
}

int p[30],wp[30];
LL dp[Maxm],dp2[Maxm];
mat Build(int pos){
    mat ret=T1;
    for (int i=0;i<(1<<k);i++){
        if (!id[i]) continue;
        for (int j=1;j<=q;j++){
            if (p[j]<=pos && pos-p[j]<k){
                int pp=pos-p[j];
                pp=k-1-pp;
                if (i>>(pp+1)&1) continue;

                for (int l=0;l<(1<<k);l++){
                    if (!id[l]) continue;
                    if (l>>pp&1){
                        if (ret.dist[id[i]][id[l]]!=1e18) ret.dist[id[i]][id[l]]+=wp[j];
                    }
                }
            }
        }
    }
    return ret;
}

mat mul(mat x,mat y){
    mat ret;
    for (int i=1;i<=cc;i++){
        for (int j=1;j<=cc;j++){
            for (int k=1;k<=cc;k++){
                ret.dist[i][j]=min(ret.dist[i][j],x.dist[i][k]+y.dist[k][j]);
            }
        }
    }
    return ret;
}

void Mul(mat X){
    for (int i=1;i<=cc;i++){
        dp2[i]=1e18;
    }
    for (int i=1;i<=cc;i++){
        for (int j=1;j<=cc;j++){
            dp2[j]=min(dp2[j],dp[i]+X.dist[i][j]);
        }
    }
    for (int i=1;i<=cc;i++) dp[i]=dp2[i];
}

mat mqp(mat x,LL p){
    mat R;
    for (int i=1;i<=cc;i++) R.dist[i][i]=0;
    while (p){
        if (p&1) R=mul(R,x);
        x=mul(x,x);
        p>>=1;
    }
    return R;
}

int normal(int pos){
    for (int i=1;i<=q;i++){
        if (p[i]<=pos && pos-p[i]<k) return 0;
    }
    return 1;
}

int main(){
    x=read();k=read();n=read();q=read();
    n+=k-x;
    for (int i=1;i<=k;i++){
        c[i]=read();
    }
    _init();

    for (int i=1;i<=q;i++){
        p[i]=read();wp[i]=read();
    }
    for (int i=1;i<=cc;i++) dp[i]=1e18;
    dp[id[(1<<x)-1]]=0;
    int now=k;
    while (now<n){
        if (!normal(now+1)){
            mat Tra=Build(now+1);
            Mul(Tra);
            now++;
            continue;
        }
        int Nxt=n+1;
        for (int i=1;i<=q;i++){
            if (p[i]>now){
                Nxt=min(Nxt,p[i]);
            }
        }
        int di=Nxt-now-1;
        mat Tra=mqp(T1,di);
        Mul(Tra);
        now=Nxt-1;
    }
    printf("%I64d\n",dp[id[(1<<x)-1]]);
    return 0;
}
