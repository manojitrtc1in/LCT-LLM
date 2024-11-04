





















































#include <bits/stdc++.h>
























#define amd and
#define vd void
#define pb push_back





using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef char ch;

int main()
{

























    ll a,b;
    string s;

    cout << "a" << endl;
    cin >> a;
    if(a<=0)return 0;

    if(a==300)
    {
        while(a--)cout << "b";
        cout << endl;
        return 0;
    }

    for(int i=0;i<a+1;i++)s+="a";

    cout << s << endl;
    cin >> b;
    if(b<=0)return 0;

    if(!(a+1>b))
    {
        while(a--)cout << "b";
        cout << endl;
        return 0;
    }

    for(int i=0;i<s.size()-1;i++)
    {
        s[i]='b';
        cout << s << endl;
        cin >> a;
        if(a<=0)return 0;
        if(a>b)s[i]='a';
        else b=a;
    }

    s[s.size()-1]='b';
    cout << s << endl;

    return 0;
}


