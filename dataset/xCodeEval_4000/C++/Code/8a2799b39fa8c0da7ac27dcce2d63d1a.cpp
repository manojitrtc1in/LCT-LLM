
















































#include <bits/stdc++.h>
























#define amd and
#define vd void
#define pb push_back
#define f first
#define s second
#define ret return

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef char ch;
typedef string str;
typedef bool bl;

ll v[1003][1003];

int main()
{

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
















    ll n,an=0;

    cin >> n;
    for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)
    {
        cin >> v[i][j];
    }

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)an+=v[i][j]*v[j][i];
    }

    an%=2;

    ll m;
    cin >> m;

    for(ll i=0;i<m;i++)
    {
        ll a;
        cin >> a;

        if(a==3)cout << an;
        else
        {
            cin >> a;


                an=(an+1)%2;
        }
    }

    cout << endl;

    ret 0;
}
