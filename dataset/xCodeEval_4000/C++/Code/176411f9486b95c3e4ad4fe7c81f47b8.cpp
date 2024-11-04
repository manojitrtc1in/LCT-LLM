#include              <algorithm>
#include               <iostream>
#include                <cstring>
#include                <stdio.h>
#include                 <string>
#include                 <vector>
#include                 <time.h>
#include                  <queue>
#include                  <cmath>
#include                    <map>
#include                    <set>
using   namespace            std;
typedef	long long             vt;
typedef unsigned long long   vt2;
typedef	pair<vt,vt>          PVV;
typedef	pair<char,vt>        PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt,vt>           MVV;
typedef map<char,vt>         MCV;
typedef map<string,vt>       MSV;
#define sd(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(x)   scanf("%s",&x)
#define fa(x)	for(auto &it:x)
#define fi(x,y) for(int i=x;i<y;i++)
#define fj(x,y) for(int j=x;j<y;j++)
#define fk(x,y) for(int k=x;k<y;k++)
const int MAXN = 1e6 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 1333331;



using namespace std;
const int N=2e5+5;
int a[N],id[N];
bool rule(int x, int y)
 {
    return a[x]<a[y];
}
int main()
{
    int n;
	sd(n);
	fi(1,n+1)
		sd(a[i]),id[i]=i;
    sort(id+1,id+1+n,rule);
    sort(a+1,a+1+n);
    if(n<=3)
    {
        cout<<1<<endl;
        return 0;
    }
    int del=0,cha;
    if(a[3]-a[2]!=a[2]-a[1])
    {
        if(a[3]-a[2]==a[4]-a[3])
        {
            del=1;
            cha=a[3]-a[2];
        }
        else if(a[3]-a[1]==a[4]-a[3])
        {
            del=2;
            cha=a[3]-a[1];
        }
        else if(a[2]-a[1]==a[4]-a[2])
        {
            del=3;
            cha=a[2]-a[1];
        }
        else
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    else
	 cha=a[2]-a[1];
    for(int i=del?4:3;i<=n;++i)
    {
        int l=(del==i-1?i-2:i-1);
        if(a[i]-a[l]!=cha)
        {
            if(del)
            {
                cout<<-1<<endl;
                return 0;
            }
            del=i;
        }
    }
    cout<<(!del?id[1]:id[del])<<endl;
}
