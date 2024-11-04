








using namespace std;
typedef pair<int,int>pii;
const ll MOD=1000000007;
int T;
struct data{int i,j,x,y;} luu[200005];
bool cmp(pii a, pii b)
{
    return a.fi<b.fi || (a.fi==b.fi && a.se<b.se);
}
bool cmp2(pii a, pii b)
{
    return a.se<b.se;
}
ll sqr(ll x)
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
string res;
int i, j, n;
string s[10];
bool ch;
string ss;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--)
    {
        for(i=0;i<=7;i++) cin>>s[i];
        for(i=0;i<=7;i++)
        {
            if (s[i]=="RRRRRRRR") res="R\n";
            if (s[0][i]=='B')
            {
                for(j=0;j<=7;j++) if (s[j][i]!='B') break;
                if (j==8) res="B\n";
            }
        }
        cout<<res;
    }
    return 0;
}

