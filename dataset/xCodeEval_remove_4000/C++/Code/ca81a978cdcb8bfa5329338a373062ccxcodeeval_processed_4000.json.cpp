















































































using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef char ch;
typedef string str;

int main()
{






















    ll n,m,mx,x,mn,sum=0;

    cin >> n >> m >> mx >> x >> mn;

    vector<ll>a(m);

    for(int i=0;i<m;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }

    sort(a.begin(),a.end());

    ll mi=-1;

    for(int i=0;i<m;i++)
    {
        if(a[i]>=mn)
        {
            mi=i;
            break;
        }
    }

    bool fl=0;

    if(mi==-1)mi=m,fl=1,sum+=mn,m++;

    ll mm=min(n/2-mi,n-m);

    if(mm<0)
    {
        cout << "-1\n";
        return 0;
    }
    sum+=mm+(mn*(n-m-mm));

    if(sum>x)
    {
        cout << "-1\n";
        return 0;
    }

    if(fl==1)cout << mn << " ";
    for(int i=0;i<mm;i++)cout << "1 ";
    for(int i=0;i<n-m-mm;i++)cout << mn << " ";
    cout << endl;

    return 0;
}
