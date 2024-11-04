

























































































using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef char ch;

vector<pll>a;



bool comp(pll a,pll b)
{


    return a.f<b.f or (a.f==b.f and a.s>b.s);
}

int main()
{






















    ll n;

    cin >> n;
    n*=2;

    for(int i=0;i<n;i+=2)
    {
        ll b,c;
        cin >> b >> c;
        a.pb({b,1});
        a.pb({c,-1});
    }

    sort(a.begin(),a.end(),comp);

    ll an=0;

    for(int i=0;i<n;i++)
    {
        an+=a[i].s;
        if(an>2)
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
