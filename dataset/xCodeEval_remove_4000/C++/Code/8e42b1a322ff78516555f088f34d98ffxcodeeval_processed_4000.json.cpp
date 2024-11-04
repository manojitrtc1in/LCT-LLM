




























































using namespace std;


ll M=1e9+7;
const int sz=1e5+10;
const int OO=0x3f3f3f3f;
ll gcd(ll a,ll b){
    while(b!=0)
    {
        ll a2=a;
        a=b;
        b=a2%b;
    }
    return a;
}
ll lcm(ll a,ll b)
{
    return a/ gcd(a,b)*b;
}
ll mul(ll a,ll b,ll m)
{
    return ((a%m)*(b%m))%m;
}
int id1(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n%2==1){result=result*x;}
        x=x*x;
        n=n/2;
    }
    return result;
}
int id2(int x,int n,int m)
{
    int result=1;
    while(n>0)
    {
        if(n%2==1){result=(result*x)%m;}
        x=(x*x)%m;
        n=n/2;
    }
    return result;
}
ll id0(ll x,ll n,ll m)
{
    ll result=1;
    while(n>0)
    {
        if(n%2==1){result=mul(result,x,m);}
        x=mul(x,x,m);
        n=n/2;
    }
    return result;
}
const int NMAX=105;



int main() {
    fast
    int t;cin>>t;
    while (t--)
    {
        int n,d;
        cin>>n>>d;
        vector<int>v;
        int c=0,s=0;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            if(x>d)c++;
            if(x<d)
            {
                v.push_back(x);
            }
        }

        if(!c)
        {cout<<"YES\n";
            }
        else
        {
            if(v.size()<2){cout<<"NO\n";
                continue;}
            int z=0,b=0;
            sort(v.begin(),v.end());
            for(auto  &i:v)
            { b++;
                if(b!=3) {
                    z += i;
                }
                else
                {
                    break;
                }
            }
          

            if(z<=d)cout<<"YES\n";
            else cout<<"NO\n";
        }

    }
}