

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<list>
#define inf 99999999999999999
#define MOD 1000000007
#define endl "\n"
#define ll long long


#define forl(i,a,b) for(ll i=a;i<=b;i++)
#define forx(i,a,b) for(ll i=a;i>=b;i--)
#define fi first
#define se second



#define maxn 205
using namespace std;


typedef pair<long long,long long> ii;
typedef pair<ii,long long> iii;
typedef pair<int,int> pii;
typedef pair<long long,ii> piii;
int tdong[5]={0,1,-1,0,0};
int tcot[5]={0,0,0,1,-1};
char direct[5]={'A','U','D','L','R'};
int tdm[9]={0,-2,-2,-1,-1,1,1,2,2};
int tcm[9]={0,-1,1,-2,2,-2,2,-1,1};
ll t,n,m;
string cong( string s1,string s2)
{
    if(s1=="0" && s2=="0")return "0";
    if(s1.length()>s2.length())swap(s1,s2);
    s2="0"+s2;
    while(s1.length()!=s2.length())
    {
        s1="0"+s1;
    }
    int nho=0,nho_1=0;
    forx(i,s1.length()-1,0)
    {
        nho=(bool)(((int)s1[i]-48+(int)s2[i]-48)+nho_1>=10);
        s1[i]=(char)((((int)s1[i]-48+(int)s2[i]-48)+nho_1)%10+48);
        nho_1=nho;
        

    }

    while(s1[0]=='0')s1.erase(0,1);
    return s1;
}
ll ucln(ll a,ll b)
{
    while(a!=b && a!=0 && b!=0)
    {
        

        if(a>b)a=a%b;
        else b=b%a;
    }
    return max(a,b);
}
struct fenwick_tree
{
    ll tree[100005];
    ll mang[100005];
    void khoi_tao(ll max_n)
    {
        forl(i,0,max_n)tree[i]=0;
    }
    void update(ll to,ll value)
    {
        for(to;to<100004;to+=to&(-to))tree[to]=(tree[to]+value);
    }
    ll tinh_tong(ll to)
    {
        ll kq=0;
        if(to!=0)for(to;to>0;to-=to&(-to))kq=(kq+tree[to])%MOD;
        return kq;
    }
    ll sum(ll from,ll to)
    {
        return (tinh_tong(to)-tinh_tong(from-1))%MOD;
    }
    void update_gcd(ll to,ll value)
    {
        for(to;to<100004;to+=to&(-to))tree[to]=ucln(tree[to],value);
    }
    ll gcd_range(int l,int r)
    {
        ll kq=0;
        l--;
        while(r>l)
        {
           

            if((r-r&(-r))>=l)
            {
                kq=ucln(kq,tree[r]);
                r-=r&(-r);
            }
            else
            {
                kq=ucln(kq,mang[r]);
                r--;
            }
        }
        return kq;
    }
};


struct segment_tree
{
    ll lazy[200005],s_tree[200005];
    void khoi_tao()
    {
        forl(i,1,200004){lazy[i]=0;s_tree[i]=0;}
    }
    void update_range(ll vt,ll r_left,ll r_right,ll t_left,ll t_right,ll value)
    {
        if(lazy[vt]!=0)
        {
            s_tree[vt]+=lazy[vt];
            lazy[vt*2]+=lazy[vt];
            lazy[vt*2+1]+=lazy[vt];
            lazy[vt]=0;
        }
        if(r_left>t_right || t_left>r_right)return;
        else if(r_left<=t_left && r_right>=t_right)
        {
            s_tree[vt]+=value;
            lazy[vt*2]+=value;
            lazy[vt*2+1]+=value;
            return;
        }
        else
        {
            ll mid=(t_left+t_right)/2;
            update_range(vt*2,r_left,r_right,t_left,mid,value);
            update_range(vt*2+1,r_left,r_right,mid+1,t_right,value);
            

            s_tree[vt]=max(s_tree[vt*2],s_tree[vt*2+1]);
        }
    }
    ll max_range(ll vt,ll r_left,ll r_right,ll t_left,ll t_right )
    {
        if(lazy[vt]!=0)
        {
            s_tree[vt]+=lazy[vt];
            lazy[vt*2]+=lazy[vt];
            lazy[vt*2+1]+=lazy[vt];
            lazy[vt]=0;
        }
        if(r_left>t_right || r_right<t_left)return -inf;
        else if(r_left<=t_left && r_right>=t_right)return s_tree[vt];
        else
        {
            ll mid=(t_left+t_right)/2;
            return max(max_range(vt*2,r_left,r_right,t_left,mid),max_range(vt*2+1,r_left,r_right,mid+1,t_right));
        }
    }
};

ll toi_uu_nhan(ll a,ll b,ll mod)
{
    if(mod==0)return 999999999;
    if(a==0 || b==0 || mod==1)return 0;
    if(a<(mod/b+1))return a*b;
    a=a%mod;b=b%mod;

    if(a<b)swap(a,b);

    ll tam=mod/a+(bool)(mod%a!=0);

    ll mod_a=(a*tam)%mod;

    ll need=b/tam;

    ll du=b-tam*need;

    ll con_lai=du*a;

    

    return (toi_uu_nhan(mod_a,need,mod)+con_lai)%mod;

}
ll pow_f(ll a,ll b,ll k)
{
    if(k==0)return 999999999;
    if(k==1)return 0;
    ll kq=1;
    a%=k;
    while(b>0)
    {
        if(b%2!=0){kq=toi_uu_nhan(kq,a,k);}
        a=toi_uu_nhan(a,a,k);
        b/=2;

    }
    return kq;
}
    int parent[100005];
    bool visit[100005];
    long long d[100005],table[2005][2005];
int getmin()
{
    ll dd=inf,u=0;
    forl(i,1,n)if(!visit[i] && d[i]<dd){dd=d[i];u=i;}
    return u;
}
void prim(int s)
{
    forl(i,1,n){visit[i]=false;d[i]=inf;}
    d[s]=0;
    while(true)
    {
        int u=getmin();
        

        if(u==0)break;
        visit[u]=true;
        forl(i,1,n)
        {
            if(!visit[i])d[i]=min(d[i],table[u][i]);
        }
    }
}
ll distra(int s,int t)
{
    forl(i,1,n){visit[i]=false;d[i]=inf;}
    d[s]=0;
    while(true)
    {
        int u=getmin();
        

        if(u==0 || u==t)return d[t];
        visit[u]=true;
        forl(i,1,n)
        {
            if(!visit[i])d[i]=min(d[i],max(table[u][i],d[u]));
        }
    }
}
struct DSU
{
    int r[100005];int sl[100005];
    int find_parent(int a)
    {
        if(parent[a]==a)return parent[a];
        else return parent[a]=find_parent(parent[a]);
    }
    void join(int a,int b)
    {
        a=find_parent(a);
        b=find_parent(b);
        if(r[b]>r[a]){parent[a]=b;sl[b]+=sl[a];}
        else {parent[b]=a;sl[a]+=sl[b];r[a]++;}
    }

};
bool check(int i,int j,int n,int m)
{
    return(i>=1 && j>=1 && i<=n && j<=m);
}
struct edge
{
    ll ii,jj,ww;
    edge(int ii,int jj, int ww)
    {
        this->ii=ii;
        this->jj=jj;
        this->ww=ww;
    }
};
void distra_heap(int s,int t,vector<ii> canh[])
{
    forl(i,1,n){d[i]=inf;visit[i]=false;}
    d[s]=0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0,s));
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(visit[u])continue;
        visit[u]=true;
        forl(i,0,canh[u].size()-1)
        {
            d[canh[u][i].first]=min(d[canh[u][i].first],d[u]+canh[u][i].second);
            pq.push(ii( d[canh[u][i].first],canh[u][i].first));
        }
    }
}
bool kt[1000005];

vector<ll> snt;
void sang()
{
    forl(i,1,50001)kt[i]=false;
    kt[2]=1;
    snt.push_back(2);
    ll vt=3;
    while(vt<=50000)
    {
        while(kt[vt] && vt<=50000)vt+=2;
        kt[vt]=true;snt.push_back(vt);

        for(ll k=vt*vt;k<=50000;k+=vt){if(k<50000)kt[k]=true;}
    }
}


int bb[19];
void bin(int x,int sl)
{
    stack<int> s;
    int dem=0;
    while(x>0)
    {
        if(x%2!=0)s.push(1);
        else s.push(0);
        x/=2;
        dem++;
    }
    while(dem<sl){s.push(0);dem++;}
    while(!s.empty()){cout<<s.top();s.pop();}
    cout<<endl;
}

string intostring(ll a)
{
    stack<int> st;
    while(a>0)
    {
        st.push(a%10);
        a/=10;
    }
    string s;
    while(!st.empty())
    {
        s+=(char)(st.top()+'0');st.pop();
    }
    return s;
}


struct combinatoric
{
    ll gt[1000005],nghich_dao[1000004];
    void gt_va_nghichdao()
    {
        gt[0]=nghich_dao[0]=1;
        forl(i,1,1000001)
        {
            gt[i]=(gt[i-1]*i)%MOD;
        }
        nghich_dao[1000001]=pow_f(gt[1000001],MOD-2,MOD);
        forx(i,1000000,0)nghich_dao[i]=(nghich_dao[i+1]*(i+1))%MOD;
    }
    ll nck(ll n,ll k)
    {
        if(n<k || n<0 || k<0)return 0;
        else return  1LL* gt[n] * nghich_dao[n-k] % MOD *nghich_dao[k] % MOD;
    }
};
int fn(ll s1,ll s2,ll m)
{
    if(s1<=s2){return (s2-s1);}
    ll tam=s1-s2;
    ll kq=tam/m+(tam%m!=0);
    return kq*m+s2-s1;
}
bool ch(ll n,ll adj[],ll m)
{
    ll tam=fn(adj[1],adj[2],m);
    forl(i,3,n)if((adj[i]+m-tam)%m!=adj[i-1])return false;
    return true;
}

struct matran
{
    ll m[4][4];
};
matran nhanmatran(matran a,matran b,ll sz)
{
    matran kq;
    forl(i,1,sz)
        forl(j,1,sz)kq.m[i][j]=0;
    forl(i,1,sz)
        forl(j,1,sz)
            forl(k,1,sz)kq.m[i][j]=(kq.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
    return kq;
}
matran luythuamatran(matran a,ll b,ll sz)
{
    matran kq=a;
    while(b>0)
    {
        if(b%2!=0){kq=nhanmatran(a,kq,sz);}
        a=nhanmatran(a,a,sz);
        b/=2;

        

        

        

    }
    return kq;
}
ll fibo(ll k)
{
    if(k<1)return 1;
    matran a;
    a.m[1][1]=0;a.m[1][2]=1;a.m[2][1]=1;a.m[2][2]=1;
    matran tam=luythuamatran(a,k,2);
    return tam.m[2][2];
}
void dfs(int s,bool visit[],vector<int>v[])
{
    visit[s]=true;
    

    

    if(v[s].size()>0)
    forl(i,0,v[s].size()-1)
    {
        int j=v[s][i];
        if(!visit[j])dfs(j,visit,v);
    }
}
void bfs(int from,int to,int step,bool visit[],int d[],int parent[])
{
    forl(i,0,n){d[i]=99999999;visit[i]=false;parent[i]=i;}
    d[from]=0;
    queue<int> q;
    q.push(from);
    while(!q.empty())
    {
        int u=q.front();q.pop();if(visit[u] || u>to)continue;
       

        visit[u]=true;
        if(u==to)break;
        if(u==from){d[u+step]=d[u]+1;parent[u+step]=from;q.push(u+step);}
        else
        {
            int n0=step+1,n1=-1;
            for(int i=-step;i<=step;i+=2)
            {
                n0--;n1++;
                int v=to-u;

                if(n0>u || n1>v){continue;}
                if(u+i<=to && u+i>=0)if(!visit[u+i] && d[u+i]>d[u]+1){d[u+i]=d[u]+1;parent[u+i]=u;q.push(u+i);}
                if(u==-1)
                {
                    cout<<"* "<<i<<endl;
                    cout<<n0<<" "<<n1<<endl;
                    cout<<u<<" "<<v<<endl;
                }
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("test.inp","r",stdin);
   freopen("test.out","w",stdout);
#endif 

   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

   

   

   

   
    t=1;

    int cas=0;
    ll ans,k;
    

    while(t--)
    {
        cin>>n>>k;
        stack<int> s0,s1;
        int d[505], parent[505];bool visit[505];
        bfs(0,n,k,visit,d,parent);

        forl(i,1,n)s0.push(i);
       

        stack<int> pat;
        int vt=n;
        pat.push(n);
        if(d[n]>500){cout<<-1;break;}
        else
        {
        while(vt!=0)
        {
            {
                vt=parent[vt];

                pat.push(vt);
            }
        }
       

        {
            int ans=0;
            int vt=0;
            while(vt!=n)
            {
                vt=pat.top();
                if(vt==n)break;
                pat.pop();
              

                int vti=pat.top();
                for(int i=-k;i<=k;i+=2)
                {
                    if(!(vt+i==vti))continue;

                 

                    if(vt+i<vt)
                    {
                        int slout=abs(-k+i)/2;

                        int slin=abs(-k-i)/2;
                     

                        queue<int> q;
                        stack<int> tg0_1,tg1_0;   

                        forl(i,1,slout)
                        {
                            int tam=s1.top();
                            tg1_0.push(tam);
                            q.push(tam);
                            s1.pop();
                        }
                        forl(i,1,slin)
                        {
                            int tam=s0.top();
                            tg0_1.push(tam);
                            q.push(tam);
                            s0.pop();
                        }

                        while(!tg1_0.empty()){s0.push(tg1_0.top());tg1_0.pop();}
                        while(!tg0_1.empty()){s1.push(tg0_1.top());tg0_1.pop();}
                      

                        

                        int gt;
                        cout<<"? ";
                        while(!q.empty()){cout<<q.front()<<" ";q.pop();}cout<<endl;
                        cout.flush();
                        cin>>gt;
                        ans=ans^gt;
                       

                        break;
                    }
                    

                    if(vt+i>vt)
                    {
                        int slout=(k-i)/2;

                        int slin=(k+i)/2;
                     

                        queue<int> q;
                        stack<int> tg0_1,tg1_0;   

                        forl(i,1,slout)
                        {
                            int tam=s1.top();
                            tg1_0.push(tam);
                            q.push(tam);
                            s1.pop();
                        }
                        forl(i,1,slin)
                        {
                            int tam=s0.top();
                            tg0_1.push(tam);
                            q.push(tam);
                            s0.pop();
                        }

                        while(!tg1_0.empty()){s0.push(tg1_0.top());tg1_0.pop();}
                        while(!tg0_1.empty()){s1.push(tg0_1.top());tg0_1.pop();}
                     

                        

                        int gt;
                        cout<<"? ";
                        while(!q.empty()){cout<<q.front()<<" ";q.pop();}cout<<endl;
                        cout.flush();
                        cin>>gt;
                        ans=ans^gt;
                        

                        break;
                    }
                }
             

            }
            cout<<"! "<<ans;
            

            

        }
    }}
}
