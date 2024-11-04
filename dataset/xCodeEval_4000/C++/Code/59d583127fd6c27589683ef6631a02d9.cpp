

























































#include <bits/stdc++.h>












#define endl "\n"
#define amd and
#define vd void
#define pb push_back
#define f first
#define s second
#define ret return
#define cont continue
#define lcm(x,y) (x*y/__gcd(x,y))

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef char ch;
typedef string str;
typedef bool bl;

ll binpow(ll a,ll n,ll mod)
{
    ll ans=1;
    while(n)
    {
        if(n&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    ret ans;
}

ll binpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1)ans*=a;
        a*=a;
        n>>=1;
    }
    ret ans;
}

vector<ll> pr;
vd PrDoX(ll x)
{
    if(pr.size()>0)ret;

    vector<ll> p(x+1);

    for(ll i=2;i<=x;i++)
    {
        if(p[i]==0)
        {
            pr.pb(i);
            for(ll j=i+i;j<=x;j+=i)p[j]=1;
        }
    }
}

vector<ll> fact(ll x)
{
    PrDoX(sqrt(1e9));

    vector<ll> ans;

    ll i=0,c=sqrt(x),n=pr.size();
    while(x>1 and pr[i]<=c and i<n)
    {
        if(x%pr[i]==0)
        {
            x/=pr[i];
            ans.pb(pr[i]);
            c=sqrt(x);
        }
        else i++;
    }

    if(x!=1)ans.pb(x);

    ret ans;
}


int dp[501][26][26],cost[501][26][26];
pii ans[501][26][26];

int main()
{

   cin.tie(0);
   cout.tie(0);
   ios::sync_with_stdio(0);






    

    

    

    


    for(int i=1;i<501;i++)for(int j=0;j<26;j++)for(int l=0;l<26;l++)dp[i][j][l]=1e9;

    int n,m;
    cin >> n >> m;

    vector<vector<int> > v(n, vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ch c;
            cin >> c;

            v[i][j]=c-'a';
        }
    }    

    for(int i=0;i<n;i++)
    {
        for(int A=0;A<26;A++)
        {
            for(int B=0;B<26;B++)
            {
                if(A==B)cont;

                for(int j=0;j<m;j++)cost[i][A][B]+=( (A!=v[i][j])*(j%2==0) + (B!=v[i][j])*(j%2==1) );
            }
        }
    }

    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)dp[1][i][j]=cost[0][i][j];
    }

    for(int i=1;i<=n;i++)
    {
        for(int A=0;A<26;A++)
        {
            for(int B=0;B<26;B++)
            {
                if(A==B)cont;

                for(int A2=0;A2<26;A2++)
                {
                    if(A2==A)cont;

                    for(int B2=0;B2<26;B2++)
                    {
                        if(B2==B or A2==B2)cont;

                        if(dp[i-1][A2][B2]+cost[i-1][A][B] < dp[i][A][B])
                        {
                            dp[i][A][B]=dp[i-1][A2][B2]+cost[i-1][A][B];
                            ans[i][A][B]={A2,B2};
                        }
                    }
                }       
            }
        }
    }

    int mn=1e9;
    pii x={0,0};
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(i!=j and dp[n][i][j]<mn)mn=dp[n][i][j],x={i,j};
        }
    }

    cout << mn << endl;
    


    vector<pii> Ans;
    for(int i=n;i>0;i--)
    {
        Ans.pb(x);
        x=ans[i][x.f][x.s];
    }

    


    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            if(j%2==0)cout << ch(Ans[i].f+'a');
            else cout << ch(Ans[i].s+'a');
        }
        cout << endl;
    }


    

    

    


    

    

    

    

    

    

    

    


    

    

    



    ret 0;
}