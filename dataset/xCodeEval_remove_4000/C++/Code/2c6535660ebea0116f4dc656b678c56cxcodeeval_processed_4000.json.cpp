








using namespace std;
typedef pair<int,int>pii;
typedef pair<ll,int>pli;
const ll MOD=1000000007;
int T;
struct data{int i,j,x,y;} luu[200005];
bool cmp1(pii a, pii b)
{
    return a.fi<b.fi || (a.fi==b.fi && a.se<b.se);
}
bool cmp2(pii a, pii b)
{
    return a.se<b.se || (a.se==b.se && a.fi<b.fi);
}
ll ssqr(ll x)
{
    return x*x;
}
ll po(ll a, ll n)
{
    if (n==0) return 1;
    ll s=po(a,n/2);
    s=(s*s)%MOD;
    if (n%2) s=(a*s)%MOD;
    return s;
}
int i, j, n, x, q, d, k;
string s;
long long a[200005], res[200005], su[3];
bool ch, cha;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--)
    {
        ch=true;
        cha=true;
        su[1]=1;
        su[2]=1;
        cin>>q;
        while(q--)
        {
            cin>>d>>k>>s;
            su[d]+=k*s.size();
            if (d==2)
            {
                for(i=0;i<s.size();i++) if (s[i]!='a') ch=false;
            } else
            {
                for(i=0;i<s.size();i++) if (s[i]!='a') cha=false;
            }
            if (ch==false)
            {
                cout<<"YES\n";
                continue;
            } else if (cha==false)
            {
                cout<<"NO\n";
                continue;
            } else if (cha==true && su[1]<su[2])
            {
                cout<<"YES\n";
                continue;
            } else
            {
                cout<<"NO\n";
            }
        }
    }
    return 0;
}
