


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ten5 100000+10
#define MOD 1000000007
#define rep(i,a,n) for (int i=a;i<n;i++)
#define iif(c,t,f) ((c)?(t):(f))
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define me(x) memset(x,0,sizeof(x))
#define ms(x) memset(x,0x3f3f3f3f,sizeof(x))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
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
void modify( int l, int r,int p, int x, int v)
{
    if (l == r)
    {
        s[p] = v;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
        modify( l, mid,p*2, x, v);
    else
        modify(mid + 1, r,p * 2 + 1, x, v);
    up(p);
}
































void query(int l,int r,int rt,int L,int R,int val)
{
    if(cnt==2) return;
    if(l==r)
    {
        if(s[rt]%val) cnt++;
        return;
    }
    int mid=(l+r)/2;
    if(L<=mid&&s[rt<<1]%val) query(lson,L,R,val);
    if(mid<R&&s[rt<<1|1]%val) query(rson,L,R,val);
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
            query(1,n,1,x,y,v);
            if(cnt <= 1) puts("YES");
            else puts("NO");

        }else
        modify(1,n,1,x,y);
    }

    return 0;
}
