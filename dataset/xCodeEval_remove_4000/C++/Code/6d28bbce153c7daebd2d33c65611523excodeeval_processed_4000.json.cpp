


using namespace std;
typedef long long ll;









const int  inf = 0x3f3f3f3f;
const int MAX_N = 5e5+500;
int s[MAX_N*4];
int n,q,cnt;
int intcmp(const void *v1,const void *v2)
{
    return *(int *)v1-*(int *)v2;
}

inline int read()
{
    int x=0,f=1;
    char cc=getchar();
    while(cc<'0' || cc>'9')
    {
        if(cc=='-') f=-1;
        cc=getchar();
    }
    while(cc>='0' && cc<='9')
    {
        x=x*10+cc-'0';
        cc=getchar();
    }
    return x*f;
}
int gcd(int x,int y)
{
    return y == 0? x : gcd(y,x%y);
}
void up(int pos)
{
    s[pos] = gcd(s[pos<<1],s[pos<<1|1]);
}
void bulid(int l,int r,int p)
{
    if(l == r)
    {
        scanf("%d",s+p);
        return;
    }
    int mid = (l + r) / 2;
    bulid(l,mid,p * 2);
    bulid(mid + 1,r,p * 2 + 1);
    up(p);

}
void modify(int p, int l, int r, int x, int v)
{
    if (l == r)
    {
        s[p] = v;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
        modify(p * 2, l, mid, x, v);
    else
        modify(p * 2 + 1, mid + 1, r, x, v);
    up(p);
}
void query(int p,int l,int r,int x,int y,int v)
{
    if(cnt == 2) return;
    if(l == r)
    {
        if(s[p] % v) cnt++;
        return;
    }
    int mid = (l+r) / 2;
    if(x <= mid && s[p<<1] % v)
    {
        query(p * 2,l,mid,x,y,v);
    }
   if(y > mid && s[p << 1 | 1] % v)
        query(p*2 + 1,mid+1,r,x,y,v);
}
int main()
{

    n = read();
    bulid(1,n,1);

    q  =read();
    while(q--)
    {
        int op,x,y,v;
        op= read();
        x = read();
        y = read();
        if(op == 1)
        {
            cnt = 0;
            v = read();
            query(1,1,n,x,y,v);
            if(cnt <= 1) puts("YES");
            else puts("NO");

        }else
        modify(1,1,n,x,y);
    }
    

    return 0;
}