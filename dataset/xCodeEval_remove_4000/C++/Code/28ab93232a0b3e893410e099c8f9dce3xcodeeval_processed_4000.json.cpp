












































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
int a[1005];
int main()
{
    

    int n;
    while(~sd(n))
    {
        int x;
        db l=-inf,r=inf;
        fup(i,1,n)
        {
            sd(x);
            db a,b;
            a=x*10.0/i;
            b=(x*10.0+10)/i;
            l=max(a,l);
            r=min(b,r);
        }
        db p=(n+1)*r-x*10;
        db q=(n+1)*l-x*10;
  

        int a=floor(q)/10;
        int b=floor(p)/10;
        if(a==b||(abs(a-b)==1&&p-b*10==0))
        {
            puts("unique");
            pf(x+(int)floor(q)/10);
        }
        else
        {
          puts("not unique");
        }
    }
    return 0;
}
