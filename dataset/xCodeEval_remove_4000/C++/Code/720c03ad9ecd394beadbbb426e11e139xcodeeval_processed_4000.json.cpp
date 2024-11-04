





























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
    int nho=0,id0=0;
    forx(i,s1.length()-1,0)
    {
        nho=(bool)(((int)s1[i]-48+(int)s2[i]-48)+id0>=10);
        s1[i]=(char)((((int)s1[i]-48+(int)s2[i]-48)+id0)%10+48);
        id0=nho;
        

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
    int tree[200055];
    int mang[200055];
    void khoi_tao(int max_n)
    {
        forl(i,0,max_n)tree[i]=0;
        mang[0]=0;
    }
    void update(ll to,ll value,int max_n)
    {
        for(to;to<max_n+2;to+=to&(-to))tree[to]=(tree[to]+value);
    }
    ll tinh_tong(ll to,int max_n)
    {
        ll kq=0;
        if(to!=0)for(to;to>0;to-=(to&(-to)))kq=(kq+tree[to]);
        return kq;
    }
    ll sum(ll from,ll to,int max_n)
    {
        if(from>to)swap(from,to);
        

        

        return (tinh_tong(to,max_n)-tinh_tong(from-1,max_n));
    }
    void update_gcd(ll to,ll value,int max_n)
    {
        mang[to]=value;
        for(to;to<=max_n+2;to+=to&(-to))tree[to]=ucln(tree[to],value);
    }
    ll gcd_range(int l,int r,int max_n)
    {
        if(r>max_n)return(ucln(gcd_range(l,max_n,max_n),gcd_range(1,r-max_n,max_n)));
        if(l>r)swap(l,r);
       

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
            if (kq==1) break;
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

ll id1(ll a,ll b,ll mod)
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

    ll id2=du*a;

    

    return (id1(mod_a,need,mod)+id2)%mod;

}
ll pow_f(ll a,ll b,ll k)
{
    if(k==0)return 99999999999999;
    if(k==1)return 0;
    ll kq=1;
    a%=k;
    while(b>0)
    {
        if(b%2!=0){kq=id1(kq,a,k);}
        a=id1(a,a,k);
        b/=2;

    }
    return kq;
}
 struct DSU
{
    int r[100005];
    int par[100005];
    void khoitao(int max_n)
    {
        forl(i,1,max_n){r[i]=0;par[i]=i;}
    }
    int find_parent(int a)
    {
        if(par[a]==a)return par[a];
        else return par[a]=find_parent(par[a]);
    }
    int check(int a,int b)
    {
        return (find_parent(a)==find_parent(b));
    }
    void join(int a,int b)
    {
        a=find_parent(a);
        b=find_parent(b);
        if(r[b]>r[a]){par[a]=b;}
        else {par[b]=a;if(r[a]==r[b])r[a]++;}
    }

};

struct sparse_table
{
    ll mang[100005];
    ll sp[100005][25];
    int log2[100005];

    void build(int max_n)
    {
        log2[0]=-1; 

        forl(i,1,max_n){sp[i][0]=mang[i];log2[i]=log2[(i>>1)]+1;}
        forl(j,1,20)
        for(ll i=1; i+(1<<j)<=max_n;i++)
        {
            

            sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
        }
    }
    ll query(int L,int R)
    {
        

        ll j=log2[R-L+1];
        return ucln(sp[L][j],sp[R-(1<<j)+1][j]);
    }
};


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

int LCS(string s1,string s2)
{
    int kq=0,vt=0;
    forl(i,0,s1.length()-1)
    {
        if(s1[i]==s2[vt]){vt++;kq++;}
        if(vt==s2.length())break;
    }
    return kq;
}

struct combinatoric
{
    ll gt[200005],nghich_dao[200004];
    void gt_va_nghichdao()
    {
        gt[0]=nghich_dao[0]=1;
        forl(i,1,200001)
        {
            gt[i]=(gt[i-1]*i)%MOD;
        }
        nghich_dao[200001]=pow_f(gt[200001],MOD-2,MOD);
        forx(i,200000,0)nghich_dao[i]=(nghich_dao[i+1]*(i+1))%MOD;
    }
    ll nck(ll n,ll k)
    {
        if(n<k || n<0 || k<0)return 0;
        else return  1LL* gt[n] * nghich_dao[n-k] % MOD *nghich_dao[k] % MOD;
    }
    ll nak(ll n,ll k)
    {
        if(n<k || n<0 || k<0)return 0;
        else return 1LL* gt[n] * nghich_dao[n-k] % MOD;
    }
    ll nak_lap(ll n,ll k)
    {
        return pow_f(n,k,MOD);
    }
};

stack<int> st;

pair<int,string> solve(string s,ll start,char ch)
{
    if(s.length()<=1 && s[0]!='?')return pair<int,string>(0,s);
    if(s.length()<=1)return pair<int,string>(0,"B");
    if(start!=-1)s[start]=ch;
    ll kq=0;
    forl(i,1,s.length()-1)
    if(s[i]=='?')
    {
        if(s[i-1]=='B')s[i]='R';
        else s[i]='B';
    }
    forl(i,1,s.length()-1)
    {
        if(s[i]==s[i-1])kq++;
    }
    return pair<int,string>(kq,s);
}
bool ccheck(int a)
{
    if(a%3==0 || a%10==3)return false;

    return true;
}
int main()
{

   freopen("test.inp","r",stdin);
   freopen("test.out","w",stdout);


   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

   

   

   

   
    

    

    

    

    t=1;
    cin>>t;
    int cas=0,cc=t;
        

        string s[70];
        forl(i,0,63)
        {
            ll tam=pow_f(2,i,1e18);
            s[i]=intostring(tam);
        }
    if(t==0)
    while(t--)

    {
        cas++;int a[n+5],b[n+5];
        cin>>n;
        forl(i,1,n){cin>>a[i];}
        forl(i,1,n){cin>>b[i];}
        if(cas==102)
        {
            cout<<n<<endl;
            forl(i,1,n)cout<<a[i]<<" ";cout<<endl;
            forl(i,1,n)cout<<b[i]<<" ";
        }
    }
    else
    while(t--)
    {
        string k;cin>>k;
        if(k.length()==1 && k[0]=='0'){cout<<2<<endl;continue;}
        int ans=k.length()+1;
        int n=k.length();
        forl(i,0,63)
        {
            int tam=LCS(k,s[i]);
            int kq=k.length()+s[i].length()-2*tam;
            ans=min(ans,kq);
        }
        cout<<ans<<endl;
        

       

    }
}
