#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pip pair<int,pii>
#define plp pair<ll,pll>
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007
#define FASTIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define OO 1000000000000000000

using namespace std;

ll power(ll x,ll y,ll mod)
{
    if(y==0) return  1;

    ll z=power(x,y>>1,mod);
    z=(z*z)%mod;

    if(y&1) return (z*x)%mod;

            return z;
}
ll gcd(ll a, ll b)
{
    for (;;)
    {
        if (a == 0)
            return b;
        b %= a;
        if (b == 0)
            return a;
        a %= b;
    }
}

ll ciel(ll x,ll y)
{
    return x/y+(x%y!=0);
}

ll lcm(ll a, ll b)
{
    int temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}
plp extendedEuclid(ll a, ll b)
{
    if(a == 0)
        return mp(b, mp(0, 1));
    plp p;
    p = extendedEuclid(b % a, a);
    return mp(p.F, mp(p.S.S - p.S.F*(b/a), p.S.F));
}
ll modInverse(ll a, ll mod)
{
    return (extendedEuclid(a,mod).S.F + mod) % mod;
}


class FACT
{
private:
public:
    vector <ll> fact;
    FACT(int Maximum_n_Possible)
    {
        int n=Maximum_n_Possible;

        fact.assign(n+2,1);

        for(int i=2;i<=n;i++)   fact[i]=(fact[i-1]*i)%MOD;
    }
};









#define DSU_









#ifdef PRIMES_
bool _mat[1000006];


class PRIMES
{
private:
public:
    vector<int>prime;

    PRIMES(int n)
    {
        prime.push_back(2);
        for(int i=3;i*i<=n;i+=2)
        {
            if(mat[i]==0)
            {
                for(int j=i*i; j<n;j+=2*i)
                    _mat[j]=1;
            }
        }
        for(int i=3;i<=n;i+=2)
            if(!_mat[i])
                prime.push_back(i);
    }

};
#endif
#ifdef twafiq_
vector<vector<ll> > memTwafiq;


class twafiq
{
private:
    ll dp(int x,int n)
    {
        if(x==0||x==n) return 1;
        if(x==1)       return n;

        ll &res=memTwafiq[x][n];

        if(res!=-1) return res;

        return res=(dp(x-1,n-1)+dp(x,n-1))%MOD;
    }

public:
    twafiq(int Maximum_n_Possible)
    {
        int n=Maximum_n_Possible;
        memTwafiq.resize(n+10,vector<ll>(n+10,-1));

        for(int i=2;i<=n;i++)
            for(int j=i+1;j<=n;j++)   dp(i,j);
    }

    ll clc(int x,int n)
    {
        if(x==0||x==n) return 1;
        if(x==1)       return n;
        return memTwafiq[x][n];
    }

};
#endif
#ifdef TWAFIQ_


class TWAFIQ
{
private:
    FACT *fc;
public:
    TWAFIQ(int Maximum_n_Possible)
    {
        int n=Maximum_n_Possible;

        fc=new FACT(n);
    }

    ll clc(int x,int n)
    {
        return (fc->fact[n]*(modInverse(fc->fact[x]*fc->fact[n-x],MOD)))%MOD;
    }


};
#endif
#ifdef SEGMENT_TREE_
vector <ll> seg,lazy;


class SEGMENT_TREE
{
private:
    char op1,op2;
    ll neutral;
    vector <ll> *ve;

    ll OP(ll x,ll y)
    {
        if(op1=='+') return x+y;
        if(op1=='^') return x^y;
        if(op1=='>') return max(x,y);
        if(op1=='<') return min(x,y);
    }

    ll build(int index,int l,int r)
    {
        if(l==r) return seg[index]=(*ve)[r];

        int mid=(l+r)/2;

        return seg[index]=OP(build(2*index,l,mid),build(2*index+1,mid+1,r));

    }

    ll editsum(int L,int R,ll val,int index,int l,int r)
    {
        if(l!=r)
        {
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }

        if(op1=='+')   seg[index]+=lazy[index]*(r-l+1);
        else           seg[index]+=lazy[index];

        lazy[index]=0;

        if(l>R||r<L) return seg[index];

        if(l>=L&&r<=R)
        {
            if(l!=r)
            {
                lazy[2*index]+=val;
                lazy[2*index+1]+=val;
            }
            if(op1=='+')  seg[index]+=val*(r-l+1);
            else          seg[index]+=val;

            return seg[index];
        }

        int mid=(l+r)/2;

        return seg[index]=OP(editsum(L,R,val,2*index,l,mid),editsum(L,R,val,2*index+1,mid+1,r));

    }

    ll editequal(int L,int R,ll val,int index,int l,int r)
    {
        if(lazy[index]!=-INT_MAX)
        {
            if(l!=r)
            {
                lazy[2*index]=lazy[index];
                lazy[2*index+1]=lazy[index];
            }
            if(op1=='+')                seg[index]=lazy[index]*(r-l+1);
            else if(op1=='>'||op1=='<') seg[index]=lazy[index];
            else                        seg[index]=(r-l+1)%2?lazy[index]:0;

            lazy[index]=-INT_MAX;
        }

        if(l>R||r<L) return seg[index];

        if(l>=L&&r<=R)
        {
            if(l!=r)
            {
                lazy[2*index]=val;
                lazy[2*index+1]=val;
            }

            if(op1=='+')                seg[index]=val*(r-l+1);
            else if(op1=='>'||op1=='<') seg[index]=val;
            else                        seg[index]=(r-l+1)%2?val:0;

            return seg[index];
        }

        int mid=(l+r)/2;

        return seg[index]=OP(editequal(L,R,val,2*index,l,mid),editequal(L,R,val,2*index+1,mid+1,r));

    }

    ll editmult(int L,int R,ll val,int index,int l,int r)
    {
        if(l!=r)
        {
            lazy[2*index]*=lazy[index];
            lazy[2*index+1]*=lazy[index];
        }

        seg[index]*=lazy[index];
        lazy[index]=1;

        if(l>R||r<L) return seg[index];

        if(l>=L&&r<=R)
        {
            if(l!=r)
            {
                lazy[2*index]*=val;
                lazy[2*index+1]*=val;
            }
            seg[index]*=val;
            return seg[index];
        }

        int mid=(l+r)/2;

        return seg[index]=OP(editmult(L,R,val,2*index,l,mid),editmult(L,R,val,2*index+1,mid+1,r));

    }

    ll getseg(int L,int R,int index,int l,int r)
    {
        if(l!=r)
        {
                 if(op2=='+')               seg[2*index]+=lazy[index], seg[2*index+1]+=lazy[index];
            else if(op2=='*')               seg[2*index]*=lazy[index], seg[2*index+1]*=lazy[index];
            else if(lazy[index]!=-INT_MAX)  seg[2*index]=lazy[index], seg[2*index+1]=lazy[index];

        }

        if(op2=='+')
        {
            if(op1=='+') seg[index]+=lazy[index]*(r-l+1);
            else         seg[index]+=lazy[index];

            lazy[index]=0;
        }
        else if(op2=='*')
        {
            seg[index]*=lazy[index];
            lazy[index]=1;
        }
        else
        {
            if(lazy[index]!=-INT_MAX)
            {
                     if(op1=='+')  seg[index]=lazy[index]*(r-l+1);
                else if(op1=='^')  seg[index]=(r-l+1)%2?lazy[index]:0;
                else               seg[index]=lazy[index];

                lazy[index]=-INT_MAX;
            }
        }

        if(l>=L&&r<=R)  return seg[index];

        if(l>R||r<L) return neutral;

        int mid=(l+r)/2;

        return OP(getseg(L,R,2*index,l,mid),getseg(L,R,2*index+1,mid+1,r));

    }

public:
    SEGMENT_TREE(vector<ll>*ve,char opSEG,char opLAZY)
    {
        this->ve=ve;

        op1=opSEG;
        op2=opLAZY;

        if(op1!='+'&&op1!='>'&&op1!='<'&&op1!='^') cout<<" ! Not available such segment operation !\n";
        if(op1=='^'&&(op2=='+'||op2=='*')) cout<<"\n ! Not available to process XOR segment with + or * lazy !\n";

             if(op1=='+'||op1=='^') neutral=0;
        else if(op1=='>')           neutral=-OO;
        else if(op1=='<')           neutral= OO;

        seg.resize(4*ve->size()+100,0);

             if(op2=='+') lazy.resize(4*ve->size()+100,0);
        else if(op2=='*') lazy.resize(4*ve->size()+100,1);
        else if(op2=='=') lazy.resize(4*ve->size()+100,-INT_MAX);

        build(1,0,ve->size()-1);
    }

    void edit(int L,int R,ll val)
    {
             if(op2=='+') editsum(L,R,val,1,0,ve->size()-1);
        else if(op2=='*') editmult(L,R,val,1,0,ve->size()-1);
        else              editequal(L,R,val,1,0,ve->size()-1);
    }

    ll get(int L,int R)
    {
        return getseg(L,R,1,0,ve->size()-1);
    }

};
#endif
#ifdef DIJKSTRA_
class DIJKSTRA
{
private: vector<pii> *ve;
         set<pii> se;
         bool *ok;
public:

    ll *dist;

    DIJKSTRA(vector<pii> *ve,int n,int source)
    {
        this->ve=ve;
        dist=new ll[n+10];
        ok=new bool[n+10];

        for(int i=1;i<=n;i++) dist[i]=1e17 , ok[i]=false;

        dist[source]=0;

        se.insert(mp(0,source));

        pii pa,pa2;

        while(se.size())
        {
            pa=*se.begin();
            se.erase(se.begin());
            ok[pa.S]=true;

            for(int i=0;i<ve[pa.S].size();i++)
            {
                pa2=ve[pa.S][i];
                if(!ok[pa2.S])
                {
                    if(pa.F+pa2.F<dist[pa2.S])
                    {
                        se.erase(se.find(mp(dist[pa2.S],pa2.S)));
                        dist[pa2.S]=pa.F+pa2.F;
                        se.insert(mp(dist[pa2.S],pa2.S));
                    }
                }
            }
        }
    }
};
#endif
#ifdef FLOYD_WARSHALL_
ll ***mem;
class FLOYD_WARSHALL
{
private:
public:
    ll **dist;

    FLOYD_WARSHALL(vector<pii>*ve,int n)
    {
        

                              mem       =  new ll** [n+2];

        for(int i=0;i<=n;i++) mem[i]    =  new ll*  [n+2];

        for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) mem[i][j] =  new ll   [n+2];

        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) mem[0][i][j]=1e17;

        for(int i=1;i<=n;i++)
        for(int j=0;j<ve[i].size();j++) mem[0][i][ve[i][j].S]=ve[i][j].F;

        for(int i=1;i<=n;i++) mem[0][i][i]=0;
        


        for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)   mem[k][i][j]=min(mem[k-1][i][j],mem[k-1][i][k]+mem[k-1][k][j]);

        dist=mem[n];

    }
};
#endif
#ifdef MOS_
int sq_;
struct query
{
    int l , r , idx , q_idx ;
    ll ans;
    int cnt[10004]={0};

    query() {  }

    query(int l,int r,int idx) { this->l=l; this->r=r; this->idx=idx; q_idx=l/sq_; ans=0; }

    bool operator <(query &q)
    {
        if(q_idx<q.q_idx) return true;
        if(q_idx>q.q_idx) return false;

        if(r<q.r) return true;
                  return false;
    }
};
query *q_,temp;
ll *ans_;


class MOS
{
private: int m,l,r;
public:
    MOS(vector<ll>*ve)
    {
        sq_= sqrt(ve->size());

        cin>>m;

        q_   = new query [m+5];
        ans_ = new ll [m+5];

        for(int i=0;i<m;i++)
        {
            cin>>l>>r;
            q_[i]=query(l,r,i);
        }

        sort(q_,q_+m);

        for(int i=q_[0].l;i<=q_[0].r;i++)
        {
            

        }

        for(int i=1;i<m;i++)
        {
            int curL=q_[i-1].l , curR=q_[i-1].r ;

            temp=q_[i];
            q_[i]=q_[i-1];
            q_[i].l=temp.l; q_[i].r=temp.r; q_[i].idx=temp.idx;

        

        

        



            while(curL<q_[i].l)
            {

            }


            curL--;
            while(curL>=q_[i].l)
            {

            }


            while(curR>q_[i].r)
            {

            }


            curR++;
            while(curR<=q_[i].r)
            {

            }
        }

        for(int i=0;i<m;i++) ans_[q_[i].idx]=q_[i].ans;

        for(int i=0;i<m;i++) cout<<ans_[i]<<endl;

    }
};
#endif
#ifdef MATREX_
class MATREX
{
private:
public:

    ll n,m;
    vector< vector<ll> > mat;

    MATREX(const MATREX& x) { *this=x; }

    MATREX(int n,int m,ll val=0) { this->n=n; this->m=m; mat.resize(n+10,vector<ll>(m+10,val)); }

};

MATREX operator +(MATREX x,MATREX y)
{
    MATREX res(x.n,x.m);
    if(x.n!=y.n||x.m!=y.m){ cout<<"invalid operation + (not same domains)"<<endl; return res; }

    for(int i=0;i<x.n;i++)
    for(int j=0;j<x.m;j++)  res.mat[i][j] = ( x.mat[i][j] + y.mat[i][j] ) % MOD ;

    return res;
}

MATREX operator *(MATREX x,MATREX y)
{
    MATREX res(x.n,y.m);
    if(x.m!=y.n){ cout<<"invalid operation * (m1!=n2)"<<endl; return res; }

    ll sum;

    for(int i=0;i<res.n;i++)
        for(int j=0;j<res.m;j++)
        {
            sum=0;
            for(int k=0;k<x.m;k++)  sum+=(x.mat[i][k]*y.mat[k][j])%MOD , sum%=MOD;
            res.mat[i][j]=sum;
        }

    return res;
}

MATREX power(MATREX x,ll y)
{
    if(y==0)
    {
        MATREX nat(x.n,x.n);
        for(int i=0;i<nat.n;i++) nat.mat[i][i]=1;
        return nat;
    }

    if(y==1) return x;

    MATREX z(power(x,y>>1));

    z=z*z;

    if(y&1) return z*x;

            return z;
}
#endif 


ll m,k;
ll a[1003][1003];
#ifdef DSU_
vector<ll> Parent , Rank , Cmp , mark;
class DSU
{
    private:
    public:

    DSU(int n)
    {
        Parent.assign(n+2, 0);
        Rank.assign(n+2, 0);
        Cmp.assign(n+2, 1);
        mark.assign(n+2,OO);
        for (int i=0;i<n;i++) Parent[i] = i;
        for (int i=0;i<n;i++) if(k%a[i/m][i%m]==0) mark[i]=a[i/m][i%m];
    }

    int FindSet(int i) {return (Parent[i] == i) ? i : Parent[i] = FindSet(Parent[i]);}
    bool isSameSet(int i, int j) {return (FindSet(i) == FindSet(j));}
    void UnionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int x = FindSet(i), y = FindSet(j);

            if(Rank[x]==Rank[y])         Parent[y]=x , Cmp[x]+=Cmp[y] , mark[x]=min(mark[x],mark[y]), Rank[x]++ ;
            else if(Rank[y] < Rank[x])   Parent[y]=x , Cmp[x]+=Cmp[y] , mark[x]=min(mark[x],mark[y]);
            else                         Parent[x]=y , Cmp[y]+=Cmp[x] , mark[y]=min(mark[x],mark[y]);
        }
    }
};
#endif
ll n;
bool vis[1003][1003];
map<int,bool>MP;
map<int,bool>::iterator it;
vector<pair<ll,pii> >ve;

pii loc;
void dfs_find(int i,int j,int f)
{
    if(i==-1||i==n||j==-1||j==m)return;
    if(a[i][j]<f)return;
    if(vis[i][j])return;
    if(a[i][j]==f){ loc=mp(i,j); return; }

    vis[i][j]=1;
    dfs_find(i-1,j,f);
    dfs_find(i+1,j,f);
    dfs_find(i,j-1,f);
    dfs_find(i,j+1,f);
}

int cnt=0;
void dfs(int i,int j,int f)
{
    if(i==-1||i==n||j==-1||j==m)return;
    if(a[i][j]<f)return;
    if(vis[i][j])return;

    if(cnt==k/f) return;
    vis[i][j]=1;
    cnt++;
    if(cnt==k/f) return;

    dfs(i-1,j,f);
    dfs(i+1,j,f);
    dfs(i,j-1,f);
    dfs(i,j+1,f);
}

int main()
{
	FASTIO

	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        cin>>a[i][j];
        ve.pb(mp(a[i][j],mp(i,j)));
        if(k%a[i][j]==0) MP[a[i][j]]=1;
    }

	DSU dsu(n*m);

    sort(ve.begin(),ve.end());
    reverse(ve.begin(),ve.end());

    if(MP.size()==0)return cout<<"NO",0;

    it=MP.end();
    it--;
    int f=it->F;

    for(int ai=0;ai<n*m;ai++)
    {
        if(ve[ai].F>=f)
        {
            int i=ve[ai].S.F , j=ve[ai].S.S;
            if(i!=0)   if(a[i-1][j]>=f) dsu.UnionSet(i*m+j,(i-1)*m+j);
            if(i!=n-1) if(a[i+1][j]>=f) dsu.UnionSet(i*m+j,(i+1)*m+j);
            if(j!=0)   if(a[i][j-1]>=f) dsu.UnionSet(i*m+j, i*m+j-1) ;
            if(j!=m-1) if(a[i][j+1]>=f) dsu.UnionSet(i*m+j, i*m+j+1) ;

            int pa=dsu.FindSet(i*m+j);

            if(mark[pa]==f&&Cmp[pa]>=k/f)
            {
                cout<<"YES"<<endl;
                dfs_find(i,j,f);
                memset(vis,0,sizeof vis);
                dfs(loc.F,loc.S,f);
                for(int r=0;r<n;r++)
                {
                    for(int c=0;c<m;c++)
                    {
                        if(vis[r][c])cout<<f<<' ';
                        else         cout<<"0 ";
                    }
                    cout<<endl;
                }
                return 0;
            }
        }
        else
        {
            if(it==MP.begin())break;
            it--;
            f=it->F;
            ai--;
        }
    }

    cout<<"NO";






}
