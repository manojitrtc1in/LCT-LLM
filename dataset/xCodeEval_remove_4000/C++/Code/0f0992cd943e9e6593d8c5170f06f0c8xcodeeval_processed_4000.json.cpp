







using namespace std;
const int Rea=1e5+3;
struct Rin
{
    char c;
    char gc()
    {
        static char rea[Rea];
        static char *head,*tail;
        return head==tail&&(tail=(head=rea)+fread(rea,1,Rea,stdin),head==tail)?EOF:*head++;
    }
    Rin&operator >>(int &x)
    {
        bool tag=false;x=0;
        for(c=gc();c>'9'||c<'0';c=gc())if(c=='-'){c=gc();tag=true;break;}
        for(;c>='0'&&c<='9';c=gc())x=(x<<1)+(x<<3)+(c^'0');if(tag)x=-x;return *this;
    }
    Rin&operator >>(LL &x)
    {
        bool tag=false;x=0;
        for(c=gc();c>'9'||c<'0';c=gc())if(c=='-'){c=gc();tag=true;break;}
        for(;c>='0'&&c<='9';c=gc())x=(x<<1)+(x<<3)+(c^'0');if(tag)x=-x;return *this;
    }
    Rin&operator >>(string &x){x.clear();x.push_back('?');for(c=gc();c>'z'||c<'a';c=gc());for(;c>='a'&&c<='z';c=gc())x.push_back(c);return *this;}
}rin;
void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}
int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}
LL min(LL x,LL y){return x<y?x:y;}
LL max(LL x,LL y){return x>y?x:y;}


const int N=1e5+3;
const LL INF=0x3f3f3f3f3f3f3f3f;
int n,m,q;

struct eage
{
    int x,y,z,typ,t;
    void Read(int typ_,int t_){typ=typ_;t=t_;rin>>x>>y;if(typ)rin>>z;else z=0;return;}
}E[N<<1];

int id2;
int val[N<<1];
int num[N<<1];

LL sum[N];
LL minl[N];
set<pair<int,int> >a[N];
set<pair<int,int> >c[N];
set<pair<LL,int> >b;
set<pair<LL,int> >d;

int id1;
int st[N];
int ls[N<<7];
int rs[N<<7];
int gyq[N<<7];

void insert(int l,int r,int i,int qx,int qv)
{
    

    gyq[i]+=qv;if(l==r)return;
    int mid=l+r>>1;
    if(qx<=mid)insert(l,mid,(ls[i]==0)?(ls[i]=++id1):ls[i],qx,qv);
    else insert(mid+1,r,(rs[i]==0)?(rs[i]=++id1):rs[i],qx,qv);
    return;
}
LL check(int l,int r,int x,int y,int z,LL v)
{
    

    if((gyq[z]>>1)-gyq[x]-gyq[y]+(v>=val[l]&&v<=val[r])==0)return INF;
    if(l==r)return val[l];
    int mid=l+r>>1;
    LL ans=INF;
    if(ans==INF)ans=min(ans,check(l,mid,ls[x],ls[y],ls[z],v));
    if(ans==INF)ans=min(ans,check(mid+1,r,rs[x],rs[y],rs[z],v));
    return ans;
}
void change(int x)
{
    LL cutt=0;
    if(a[x].size()>=3)
    {
        int j=3;
        for(auto i=a[x].begin();j>0;i++,j--)cutt+=val[i->first];
    }
    else cutt=INF;
    if(cutt!=sum[x])
    {
        b.erase(b.find(make_pair(sum[x],x)));
        b.insert(make_pair(sum[x]=cutt,x));
    }

    cutt=0;
    if(a[x].size()>=1)
    {
        int j=1;
        for(auto i=a[x].begin();j>0;i++,j--)cutt+=val[i->first];
    }
    else cutt=INF;
    if(cutt!=minl[x])
    {
        d.erase(d.find(make_pair(minl[x],x)));
        d.insert(make_pair(minl[x]=cutt,x));
    }
    return;
}
void add(int x,int y,int z)
{
    a[x].insert(make_pair(z,y));
    c[x].insert(make_pair(y,z));
    insert(1,id2,st[x],z,1);
    insert(1,id2,st[n+1],z,1);
    change(x);
    return;
}
void earse(int x,int y)
{
    int z;
    auto it=c[x].lower_bound(make_pair(y,0));
    a[x].erase(a[x].find(make_pair(z=it->second,it->first)));
    c[x].erase(it);
    insert(1,id2,st[x],z,-1);
    insert(1,id2,st[n+1],z,-1);
    change(x);
    return;
}
bool id0(int x,int y){return E[x].z<E[y].z;}
void Read()
{
    rin>>n>>m;
    for(int i=1;i<=m;i++)E[i].Read(1,i);
    rin>>q;
    for(int i=1;i<=q;i++){int typ;rin>>typ;E[i+m].Read(typ,m+i);}
    return;
}
void Init()
{
    id1=n+1;id2=0;
    for(int i=1;i<=n;i++)st[i]=i,b.insert(make_pair(sum[i]=INF,i)),d.insert(make_pair(minl[i]=INF,i));st[n+1]=n+1;
    for(int i=1;i<=(m+q);i++)num[i]=i;
    sort(num+1,num+m+q+1,id0);
    for(int i=1,j;i<=(m+q);i=j)
    {
        val[++id2]=E[num[i]].z;
        for(j=i;j<=(m+q)&&E[num[j]].z==val[id2];j++)E[num[j]].z=id2;
    }
    return;
}
void work(eage &x)
{
    if(x.typ)add(x.x,x.y,x.z),add(x.y,x.x,x.z);
    else earse(x.x,x.y),earse(x.y,x.x);
    return;
}
void pri()
{
    LL ans=b.begin()->first,sum=d.begin()->first;
    int x=d.begin()->second,y=a[x].begin()->second;
    ans=min(ans,sum+check(1,id2,st[x],st[y],st[n+1],sum));
    int x_j,y_j;x_j=3;
    for(auto i=a[x].begin();i!=a[x].end()&&x_j>0;i++,x_j--)
    {
        y_j=3;for(auto k=a[y].begin();k!=a[y].end()&&y_j>0;k++,y_j--)
        {
            if(i->second!=y&&k->second!=x&&i->second!=k->second)ans=min(ans,0LL+val[i->first]+val[k->first]);
        }
    }
    printf("%lld\n",ans);
    return;
}
void Work()
{
    for(int i=1;i<=m;i++)work(E[i]);pri();
    for(int i=1;i<=q;i++)work(E[m+i]),pri();
    return;
}

int main()
{
    Read();
    Init();
    Work();
    return 0;
}