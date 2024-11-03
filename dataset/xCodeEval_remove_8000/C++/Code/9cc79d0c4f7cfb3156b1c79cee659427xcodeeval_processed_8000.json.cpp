














using namespace std;
const int Rea=1e5+3;
struct Rin
{
    char c;
    inline char gc()
    {
        static char rea[Rea];
        static char *head,*tail;
        return head==tail&&(tail=(head=rea)+fread(rea,1,Rea,stdin),head==tail)?EOF:*head++;
    }
    inline Rin&operator >>(int &x)
    {
        x=0;
        bool tag=false;
        for(c=gc();c>'9'||c<'0';c=gc())if(c=='-'){c=gc();tag=true;break;}
        for(;c>='0'&&c<='9';c=gc())x=(x<<1)+(x<<3)+(c^'0');
        if(tag)x=-x;
        return *this;
    }
    inline Rin&operator >>(LL &x)
    {
        x=0;
        bool tag=false;
        for(c=gc();c>'9'||c<'0';c=gc())if(c=='-'){c=gc();tag=true;break;}
        for(;c>='0'&&c<='9';c=gc())x=(x<<1)+(x<<3)+(c^'0');
        if(tag)x=-x;
        return *this;
    }
    inline Rin&operator >>(string &x){x.clear();for(c=gc();c>'z'||c<'a';c=gc());for(;c>='a'&&c<='z';c=gc())x.push_back(c);return *this;}
}rin;
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}
inline LL max(LL x,LL y){return x>y?x:y;}
const int N=6e5+3;

int n,q,k;
int a[N];
int b[N];
int d[N];
LL val[N];
LL ans[N];
vector<pair<pair<int,int>,int> >qst[N];

int lg[N];
int f[22][N];
int check(int l,int r){int z=lg[r-l+1];return min(f[z][l],f[z][r-(1<<z)+1]);}
void Read()
{
    rin>>n>>q>>k;
    for(int i=1;i<=n;i++)rin>>a[i];
    for(int i=1;i<=q;i++)
    {
        int l,r;rin>>l>>r;r=l+((r-l)/k+1)*k;
        qst[l%k].push_back(make_pair(make_pair(l,r),i));
    }
    return;
}
void Init()
{
    for(int i=1;i<=n;i++)f[0][i]=a[i];
    for(int i=1;i<22;i++)for(int j=1;j+(1<<i)-1<=n;j++)f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
    for(int i=1;i<=n;i++){lg[i]=lg[i-1];if(i>(1<<lg[i]+1))lg[i]++;}
    for(int i=1;i<=n;i++)b[i]=check(max(1,i-k),i);
    return;
}
void Work()
{
    

    for(int i=0,now;i<k;i++)
    {
        sort(qst[i].begin(),qst[i].end());reverse(qst[i].begin(),qst[i].end());
        for(now=i;now+k<=n;now+=k);
        vector<pair<pair<int,int>,int> >::iterator it=qst[i].begin();
        

        
        int tail=0;d[++tail]=now+k;val[tail]=0;
        for(;now>0;now-=k)
        {
            for(;it!=qst[i].end()&&it->first.first==now;it++)
            {
                if(it->first.first+k==it->first.second){ans[it->second]=a[now];continue;}
                if(it->first.second==d[1]){ans[it->second]=a[now]+val[tail];continue;}
                int l=1,r=tail,fd=-1;
                for(;l<=r;)
                {
                    int mid=l+r>>1;
                    if(it->first.second<=d[mid])fd=mid,l=mid+1;
                    else r=mid-1;
                }
                if(fd==-1)throw;
                

                

                ans[it->second]=a[now]+val[tail]-val[fd]-1LL*b[d[fd+1]]*((d[fd]-it->first.second)/k);
            }
            for(;tail>0&&b[now]<=b[d[tail]];tail--);
            d[++tail]=now;val[tail]=val[tail-1]+1LL*((d[tail-1]-d[tail])/k)*b[now];
        }
    }
    for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
    return;
}
int main()
{
    Read();
    Init();
    Work();
    return 0;
}
