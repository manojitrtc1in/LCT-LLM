



using namespace std;
typedef long long ll;











const int  inf = 0x3f3f3f3f;
const int MAX_N = 500005;
int s[MAX_N<<2];
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
    bulid(lson);
    bulid(rson);
    up(p);

}
void modify( int l, int r,int p, int x, int v)
{
    if (l == r)
    {
        s[p] = v;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
        modify( l, mid,p<<1, x, v);
    else
        modify(mid + 1, r,p<<1|1, x, v);
    up(p);
}
































void query(int l,int r,int p,int L,int R,int val)
{
    if(cnt==2) return;
    if(l==r)
    {
        if(s[p]%val) cnt++;
        return;
    }
    int mid=(l+r)/2;
    if(L<=mid&&s[p<<1]%val) query(lson,L,R,val);
    if(mid<R&&s[p<<1|1]%val) query(rson,L,R,val);
}
int main()
{
    scanf("%d",&n);
    bulid(1,n,1);
    scanf("%d",&q);
    while(q--)
    {
        int op,x,y,val;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1)
        {
            cnt=0;
            scanf("%d",&val);
            query(1,n,1,x,y,val);
            if(cnt<=1) puts("YES");
            else puts("NO");
        }
        else modify(1,n,1,x,y);
    }

    return 0;
}
