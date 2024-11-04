
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long
#define endl "\n"
#define rep(i, a, b) for (ll i = (a); i <= (b); i++)
#define repr(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (b); i >= (a); i--)
#define rrepr(i, a, b) for (ll i = (b); i > (a); i--)
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define debug cout<<"here!"<<endl;

ll cnt,n,m,t,ans,ant;
const int N=1e5+10;
const int INF=0x3f3f3f3f;
const ll llINF=0x3f3f3f3f3f3f3f3f;
ll arr[N];
string str;

inline ll read()
{
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}

    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}

    return x*s;
}


void solve()
{
    cin>>n>>str;
    

    

    

    

    

    

    

    

    

    

    cnt=ant=0;
    repr(i,0,n)
        if(str[i]=='R')
            cnt++;
        else if(str[i]=='B')
            ant++;
        else
        {
            if(cnt==0&&ant)
            {
                no
                return;
            }else if(ant==0&&cnt)
            {
                no
                return;
            }
            ant=cnt=0;
        }
    
    if(cnt==0&&ant)
    {
        no
        return;
    }else if(ant==0&&cnt)
    {
        no
        return;
    }
    yes

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    

    

	cin.tie(0);
	cout.tie(0);
    cin>>t;
    while(t--)
        solve();
    return 0;
}
 								 	 				 					  	  	 	