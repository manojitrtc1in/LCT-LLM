













































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
struct node
{
    int x,id;
    bool operator<(const node b) const
    {
        return x<b.x;
    }
}t[4];
int m;
int ok(int x)
{
    fup(i,1,m)
    if(x==t[i].x)
    {
        t[i].id++;
        return 0;
    }
    return 1;
}
int main()
{
    

    int n;
    while(~sd(n))
    {
        fill(t,0);
        m=0;
        fup(i,1,n)
        {
            int x;
            sd(x);
            if(ok(x)) t[++m].x=x,t[m].id++;
        }
        int flag=1;
        if(m==1)
        {
            pf(n);
            fup(i,1,m)
            {
                while(t[i].id--)
                {
                    if(!flag) printf(" ");
                    printf("%d",t[i].x);
                    flag=0;
                }
            }
        }
        else if(m==2)
        {
            if(abs(t[2].x-t[1].x)==2)
            {
                int l=min(t[1].id,t[2].id);
                t[3].x=(t[2].x+t[1].x)/2;
                t[3].id=l*2;
                t[1].id-=l;
                t[2].id-=l;
                pf(n-l*2);
                m++;
            }
            else pf(n);
            fup(i,1,m)
            {
                while(t[i].id--)
                {
                    if(!flag) printf(" ");
                    printf("%d",t[i].x);
                    flag=0;
                }
            }
        }
        else
        {
            sort(t+1,t+4);
            int l=min(t[1].id,t[3].id),r=t[2].id/2*2;
            if(l*2>=r)
            {
                t[1].id-=l;
                t[3].id-=l;
                t[2].id+=2*l;
                pf(n-2*l);
            }
            else
            {
                pf(n-r);
               t[1].id+=r/2;
               t[3].id+=r/2;
               t[2].id-=r;
            }
            fup(i,1,m)
            {
                while(t[i].id--)
                {
                    if(!flag) printf(" ");
                    printf("%d",t[i].x);
                    flag=0;
                }
            }
        }
        puts("");
    }
    return 0;
}