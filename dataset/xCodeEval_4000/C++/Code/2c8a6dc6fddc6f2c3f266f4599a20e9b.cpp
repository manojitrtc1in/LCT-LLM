
















































#include <bits/stdc++.h>
























#define amd and
#define vd void
#define pb push_back
#define f first
#define s second
#define ret return
#define cont continue

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef char ch;
typedef string str;
typedef bool bl;


int main()
{






















    ll n,ans=0;
    cin >> n;

    ll k=0;
    for(ll i=0;i<n;i++)
    {
        ll a;
        cin >> a;
        k^=a;
    }

    vector<ll> v(n);
    for(ll i=1;i<n;i++)v[i]=v[i-1]^i;



    for(ll i=2;i<=n;i++)
    {




        if((n/i)%2==0)
        {
            if(n%i!=0)k^=v[n%i];
        }
        else
        {


            if(n%i!=0)k^=v[i-1]^v[n%i];
            else k^=v[i-1];
        }


    }

    cout << k << endl;


    ret 0;
}

