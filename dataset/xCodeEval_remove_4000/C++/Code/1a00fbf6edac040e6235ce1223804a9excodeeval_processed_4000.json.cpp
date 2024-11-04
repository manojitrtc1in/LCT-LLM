















































using namespace std;
typedef long long ll;
typedef double db;
inline int scan(int &n)
{
    int res=0,ch,flag=0;
    if((ch=getchar())=='-')flag=1;
    else if(ch>='0' && ch<='9')res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')res=res*10+ch-'0';
    n= flag ? -res : res;
}
int t[M][2],sum[M],tot=0;
void add(int x)
{
    int now=0;
    for(int i=1<<30; i; i>>=1)
    {
        int w;
        w=(x&i)?1:0;
        if(!t[now][w]) t[now][w]=++tot;
        now=t[now][w];
        sum[now]++;
    }
}
void del(int x)
{
    int now=0;
    for(int i=1<<30; i; i>>=1)
    {
        int w;
        w=(x&i)?1:0;
        now=t[now][w];
        sum[now]--;
    }
}
int cal(int x)
{
    int now=0,ans=0;
    for(int i=1<<30; i; i>>=1)
    {
        int w;
        w=(x&i) ? 0:1;
        if(sum[t[now][w]]>0) ans|=i,now=t[now][w];
        else now=t[now][!w];
    }
    return ans;
}
int main()
{
    int n,now=0;
    while(~sd(n))
    {
        tot=0;
        fill(sum,0);
        fill(t,0);
        add(0);
        while(n--)
        {
            char c[3];
            int x;
            cin>>c;
            sd(x);
            if(c[0]=='+') add(x);
            else if(c[0]=='-') del(x);
            else pf(cal(x));
        }
    }
    return 0;
}