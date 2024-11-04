







































































































using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef char ch;
typedef string str;

ll p[200005];

ll f(ll t)
{
    t-=2;
    while(t>=0 and p[t]<=0)t-=3;
    return t;
}

int main()
{






















    ll n;

    cin >> n;

    map<ll,vector<ll> > mp;

    for(int i=0;i<n;i++)
    {
        ll a;
        cin >> a;

        mp[a].pb(i+1);
        p[a]++;
    }

    ll t=0;

    if(p[t]==0)
    {
        cout << "Impossible\n";
        return 0;
    }

    p[t]--;

    vector<ll> ans;
    ans.pb(mp[t][p[t]]);

    for(int i=0;i<n-1;i++)
    {
        if(p[t+1]>0)
        {
            t++;
            p[t]--;
            ans.pb(mp[t][p[t]]);
        }
        else
        {
            ll x=f(t);

            if(x>=0)
            {
                t=x;
                p[t]--;
                ans.pb(mp[t][p[t]]);
            }
            else
            {
                cout << "Impossible\n";
                return 0;
            }
        }
    }

    cout << "Possible\n";
    for(int i=0;i<n;i++)cout << ans[i] << " ";
    cout << endl;

    return 0;
}




