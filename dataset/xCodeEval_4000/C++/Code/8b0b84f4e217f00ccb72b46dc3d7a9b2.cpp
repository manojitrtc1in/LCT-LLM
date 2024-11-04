

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ten5 100000+10
#define MOD 1000000007
#define rep(i,a,n) for (int i=a;i<n;i++)
#define iif(c,t,f) ((c)?(t):(f))
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define me(x) memset(x,0,sizeof(x))
#define ms(x) memset(x,0x3f3f3f3f,sizeof(x))
const int  inf = 0x3f3f3f3f;
int intcmp(const void *v1,const void *v2)
{
    return *(int *)v1-*(int *)v2;
}

inline int read()
{
    int x=0,f=1;
    char cc=getchar();
    while(cc<'0' || cc>'9')
    {
        if(cc=='-') f=-1;
        cc=getchar();
    }
    while(cc>='0' && cc<='9')
    {
        x=x*10+cc-'0';
        cc=getchar();
    }
    return x*f;
}
int main()
{
    int n,k;
    string str;
    n = read();
    k = read();
    int cnt = 0;
    cin >> str;











































    list<char> li;
    for(int i = 0; i < n; i ++)
    {
        li.pb(str[i]);
    }
    for(char i = 'a'; i <='z'; i ++ )
    {
        for(auto it = li.begin(); it != li.end();it++)
        {
            if(k && *it == i)
            {
                it = li.erase(it);
                --it;
                k--;
            }
            if(!k)
            {
                for(char jj : li)
                    cout << jj;
                cout <<endl;
                return 0;
            }
        }
    }
    return 0;
}
