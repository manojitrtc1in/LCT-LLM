#include<bits/stdc++.h>

using namespace std;

#define iOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front


#define L(x) x.length()
#define B(x) x.begin()
#define E(x) x.end()
#define F(x) x.front()
#define SZ(x) x.size()
#define CLR(x) x.clear()
#define SORT(x) sort(x.begin(),x.end())
#define REV(x) reverse(x.begin(),x.end())
#define FOR(i,x,y) for(int i=x;i<y;i++)
#define S(x) scanf("%d",&x)
#define SL(x) cin>>x
#define SD(x) scanf("%lf",&x)
#define SC(x) scanf("%1s",&x)
#define SS(x) scanf("%s",x)
#define DUM() scanf("%c",&dum)
#define READ(x) freopen(x,"r",stdin)
#define WRITE(x) freopen(x,"w",stdout)
#define FILL(x,y) memset(x,y,sizeof(x))
#define IT iterator



using namespace std;
typedef long long int lli;
typedef long double ld;
typedef unsigned long long int llu;
typedef pair<int,int> P;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef vector< P > VP;
typedef vector< VP > VVP;
typedef vector<string> VS;
typedef vector< VS> VVS;
typedef map<int,int> MAP;




long long int ans=0;
lli gcd(lli a,lli b)
{
    if(b==0)
        return a;
    ans+=a/b;
    return gcd(b,a%b);
}




















#define all(c) c.begin(),c.end()



long long int mod=1000000007;

lli fact[300005];

void factorial()
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<300005;++i)
        fact[i]=(fact[i-1]*i)%mod;
    

    return;
}

long long int binpower(long long int a, long long int b)
{
    long long int ans=1;
    while(b>0)
    {
        if(b&1)
            ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}

bool isPrime(int n)
{
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
lli gprime[10000001];
void grsieve()
{
    gprime[1]=1;
    gprime[0]=1;
    for(lli i=2;i<10000001;++i)
    {
        if(gprime[i]==0)
        {
            for(lli j=i;j<10000001;j+=i)
                gprime[j]=i;
        }
    }
}





lli C(int u,int v)   

{
    lli c=(fact[v]*fact[u-v])%mod;
    lli in=binpower(c,mod-2);
    lli res=(in*fact[u])%mod;
    return res;
}





int main()
{
    
    iOS;
    int test=1;
    

    while(test--)
    {
        int n;
        cin>>n;
        int a[n];
        int aprev[n];
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            aprev[i]=a[i];
        }
        int counter=0;
        
        vector<vector<int> >v(1000);
        while(true)
        {
            int checker=0;
            for(int i=0;i<n;++i)
            {
                if(a[i]!=i+1)
                {
                    checker=1;
                    break;
                }
            }
            if(checker==0)
            {
                break;
            }
            int pos=-1;
            for(int i=0;i<n;++i)
            {
                if(a[i]==1)
                {
                    pos=i;
                    break;
                }
            }
            int flag=0;
            for(int i=pos;i<n-1;++i)
            {
                if((a[i+1]-a[i])!=1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag!=1)
            {
                for(int i=0;i<pos-1;++i)
                {
                    if((a[i+1]-a[i])!=1)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0)
            {
                v[counter].pb(pos);
                v[counter].pb(n-pos);
                counter++;
                break;
            }
            for(int i=0;i<n-1;++i)
            {
                if(a[i]!=i+1)
                {
                    pos=i;
                    break;
                }
            }
            int found=-1;
            for(int i=0;i<n;++i)
            {
                if(a[i]==a[pos]-1)
                {
                    found=i;
                    break;
                }
            }
            int br;
            for(int i=pos;i<found;++i)
            {
                if(a[i]>a[i+1])
                {
                    br=i;
                    break;
                }
            }
            if(pos!=0)
                v[counter].pb(pos);
            v[counter].pb(br-pos+1);
            v[counter].pb(found-br);
            if((n-found-1)!=0)
                v[counter].pb(n-found-1);
            vector<int>b;
            int prev=0;
            for(int i=v[counter].size()-1;i>=0;--i)
            {
                for(int j=n-(prev+v[counter][i]);j<n-prev;++j)
                {
                    b.pb(a[j]);
                }
                prev+=v[counter][i];
            }
            

            for(int i=0;i<n;++i)
                aprev[i]=b[i];
            int ch=0;
            for(int i=0;i<n;++i)
            {
                if(aprev[i]!=a[i])
                {
                    ch=1;
                    break;
                }
            }
            if(ch==1)
            {
                for(int i=0;i<n;++i)
                    a[i]=aprev[i];
                counter++;
                continue;
            }
            



            if(pos!=0)
                v[counter].pb(pos);
            v[counter].pb(1);
            v[counter].pb(found-pos);
            if((n-found-1)!=0)
                v[counter].pb(n-found-1);
            b.clear();
            prev=0;
            for(int i=v[counter].size()-1;i>=0;--i)
            {
                for(int j=n-(prev+v[counter][i]);j<n-prev;++j)
                {
                    b.pb(a[j]);
                }
                prev+=v[counter][i];
            }
            

            for(int i=0;i<n;++i)
            {
                aprev[i]=b[i];
                a[i]=aprev[i];
            }
            counter++;
        }
        cout<<counter<<endl;
        for(int i=0;i<counter;++i)
        {
            cout<<v[i].size()<<" ";
            for(int j=0;j<v[i].size();++j)
            {
                if(v[i][j]!=0)
                    cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
