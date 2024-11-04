













using namespace std;
inline LL rin()
{
    LL x=0;
    char c;
    bool tag=false;
    for(c=getchar();c>'9'||c<'0';c=getchar())if(c=='-'){c=getchar();tag=true;break;}
    for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^'0');
    if(tag)x=-x;
    return x;
}
inline bool get_typ(){char c=getchar(),x;for(;c!='Y'&&c!='N';c=getchar());if(c=='Y')return true;return false;}
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}
inline LL max(LL x,LL y){return x>y?x:y;}
const int N=5e2+3;
int n;
int k[N];
inline int que(int x,int y){printf("? %d %d\n",x,y);fflush(stdout);return get_typ();}

int cutt;
pair<int,int>a[N*N];
int val[N*N];
int d[N*N];
int num[N*N];
int tail;
inline void jh_(int &x,int &y){jh(d[x],d[y]);jh(x,y);return;}
inline void up(int x){if(x==1)return;if(val[d[x]]>val[d[x>>1]])jh_(num[d[x]],num[d[x>>1]]),up(x>>1);return;}
inline void down(int x)
{
    if((x<<1)>tail)return;
    int nxt=x;if(val[d[x<<1]]>val[d[nxt]])nxt=x<<1;if(((x<<1)|1)<=tail&&val[d[(x<<1)|1]]>val[d[nxt]])nxt=(x<<1)|1;
    if(nxt!=x)jh_(num[d[x]],num[d[nxt]]),down(nxt);return;
}
inline int top(){return d[1];}
inline void pop_top(){jh_(num[d[1]],num[d[tail]]);tail--;down(1);return;}
inline void push(int x){d[++tail]=x;num[x]=tail;up(tail);return;}
inline void work()
{
    n=rin();
    if(n==2){puts("! 0 0\n");fflush(stdout);}
    for(int i=1;i<=n;i++)k[i]=rin();
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)a[++cutt]=make_pair(i,j),val[cutt]=abs(k[i]-k[j]);
    for(int i=1;i<=cutt;i++)push(i);
    for(;tail;)
    {
        int now=top();pop_top();
        int x=a[now].first,y=a[now].second;if(k[x]>k[y])jh(x,y);
        if(k[x]==k[y]){printf("! %d %d\n",x,y);fflush(stdout);return;}
        if(que(y,x)){printf("! %d %d\n",x,y);fflush(stdout);return;}
    }
    puts("! 0 0\n");fflush(stdout);
    return;
}
int main()
{
    work();
    return 0;
}



