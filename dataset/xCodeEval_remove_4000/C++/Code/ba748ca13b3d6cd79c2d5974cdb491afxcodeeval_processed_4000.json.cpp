



using namespace std;
typedef long long ll;
typedef pair<int,int> pii;



ll f[MAXN];
pii p[MAXN][MAXN];

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

pii sum(pii x,pii y)
{
    ll xx=x.first;
    ll xy=x.second;
    ll yx=y.first;
    ll yy=y.second;
    return pii((xx*yy+xy*yx)%mod,(yy*xy)%mod);
}

pii mul(pii x,pii y)
{
    ll xx=x.first;
    ll xy=x.second;
    ll yx=y.first;
    ll yy=y.second;
    return pii((xx*yx)%mod,(xy*yy)%mod);
}

int main()
{







    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        f[a]++;
    }
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++)
            p[i][j]=pii(0,1);

    for(int i=1;i<=n;i++)
        p[i][0]=pii(f[i],n);

    pii res=pii(0,1);
    for(int i=1;i<n;i++)
    {
        pii su=pii(0,1);
        for(int j=1;j<=n;j++)
        {
            res=sum(res,mul(p[j][i-1],pii(f[j]-1,n-i)));
            p[j][i]=mul(su,pii(f[j],n-i));
            su=sum(su,p[j][i-1]);
        }
    }
    printf("%d\n",(res.first*qp(res.second,mod-2))%mod);

    return 0;
}
