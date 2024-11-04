











using namespace std;
const ll maxn=1e5+500;
const ll maxlog=3e6;
const ll inf=2e18+900;
ll mexx[maxlog];
ll minn[maxlog];
ll inpu[maxn][3];
ll noe[maxlog];
vector<ll> st;
vector<ll> kho;
ll xorr(ll a,ll b)
{
    if(b==1||b==2)return b;
    if(b==4)return a;
    if(a==1)return 2;
    if(a==2)return 1;
    if(a==3)return 4;
    if(a==4)return 3;
}
filll(ll L,ll R,ll ras)
{
    ll k=noe[ras];
    if(k==1)
    {
        minn[ras]=kho[L];
        mexx[ras]=inf;
    }
    if(k==2)
    {
        minn[ras]=inf;
        mexx[ras]=kho[L];
    }
    if(k==3)
    {
        swap(minn[ras],mexx[ras]);
    }
    noe[ras]=4;
    if(L!=R-1)
    {
        noe[2*ras]=xorr(noe[2*ras],k );
        noe[2*ras+1]=xorr(noe[2*ras+1],k  );
    }
}
void update(ll L,ll R,ll ras,ll l,ll r,ll t,ll tt)
{
    tt=xorr(noe[ras],tt);
    if(l==L&&R-1==r)
    {
          t=xorr(tt,t);
        if(t==1)
        {
            mexx[ras]=inf;
            minn[ras]=kho[l];
        }
        if(t==2)
        {
            mexx[ras]=kho[l];
            minn[ras]=inf;
        }
        if(t==3)
        {
            swap(minn[ras],mexx[ras]);
        }
        if(R!=L+1)
        {
            noe[2*ras]=xorr(noe[2*ras],t );
            noe[2*ras+1]=xorr(noe[2*ras+1],t  );
        }
        noe[ras]=4;
        return ;
    }
    ll mid=(L+R)/2;
    if(l<mid&&mid<=r)
    {
        update(L,mid,2*ras,l,mid-1,t,tt);
        update(mid,R,2*ras+1,mid,r,t,tt);
        minn[ras]=min(minn[2*ras],minn[2*ras+1]);
        mexx[ras]=min(mexx[2*ras],mexx[2*ras+1]);
        noe[ras]=4;
        return;
    }
    if(l<mid)
    {
        update(L,mid,2*ras,l,r,t,tt);
        noe[ras*2+1]=xorr(noe[2*ras+1],tt);
        filll(mid,R,ras*2+1);
        minn[ras]=min(minn[2*ras],minn[2*ras+1]);
        mexx[ras]=min(mexx[2*ras],mexx[2*ras+1]);
        noe[ras]=4;
        return;
    }
    update(mid,R,2*ras+1,l,r,t,tt);
    noe[ras*2]=xorr(noe[2*ras],tt);
    filll(L,mid,ras*2);
    minn[ras]=min(minn[2*ras],minn[2*ras+1]);
    mexx[ras]=min(mexx[2*ras],mexx[2*ras+1]);
    noe[ras]=4;
}
void por_seg(ll l,ll r,ll ras)
{
    minn[ras]=inf;
    mexx[ras]=kho[l];
    noe[ras]=4;
    if(l+1==r)return;
    ll mid=(l+r)/2;
    por_seg(l,mid,2*ras);
    por_seg(mid,r,2*ras+1);
}
int main()
{
    ll n,l,r,t;
    scanf("%I64d",&n);
    st.pb(1);
    for(ll i=0; i<n; i++)
    {
        scanf("%I64d%I64d%I64d",&t,&l,&r);
        inpu[i][0]=t;
        inpu[i][1]=l;
        inpu[i][2]=r;
        st.pb(l);
        st.pb(r+1);
    }
    sort(st.begin(),st.end());
    kho.pb(st[0]);
    for(ll j=1; j<st.an; j++)
    {
        if(st[j]!=st[j-1])
        {
            kho.pb(st[j]);
        }
    }
    por_seg(0,kho.an,1);
    ll rt;
    for(ll i=0; i<n; i++)
    {
        t=inpu[i][0];
        l=inpu[i][1];
        r=inpu[i][2];
        rt=(lower_bound(kho.begin(),kho.end(),r))-kho.begin();
        if(kho[rt]!=r)
        {
            rt--;
        }
        r=rt;
        l=(lower_bound(kho.begin(),kho.end(),l))-kho.begin();
        update(0,kho.an,1,l,r,t,4);
        printf("%I64d \n",mexx[1]);
    }
}


