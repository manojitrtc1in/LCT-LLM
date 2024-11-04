











#pragma GCC optimize("O3")
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <stack>
#include <ctime>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <bitset>


#define en "\n"
#define sqrt(n) sqrt((long double) n)


#define all(c) (c).begin() , (c).end()
#define int long long
#define MOD 1000000007
#define mem0(a) memset(a,0,sizeof(a))
#define FAST() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
#define pii pair<int, int>
#define double long double
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int cnt=0;
int n,k,p;
bool q(int l,int r){
    ++cnt;
    if (l>r) cout<<2/0;
    if (cnt>4500){
        if (2/0)
            ++cnt;
    }
    cout<<l<<" "<<r<<endl;
    string s;
    cin>>s;
    if (s[0]=='B'){
        exit(0);
    }
    return s[0]=='Y';
}
void query (int x){
    ++cnt;
    if (cnt>4500){
        if (2/0)++cnt;
    }
    x=min(x,n);
    x=max(1ll,x);
    cout<<x<<" "<<x<<endl;
    string s;
    cin>>s;
    if (s[0]=='Y' || s[0]=='B'){
        exit(0);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    

    srand( time(NULL));
    cin>>n>>k;
    

    int mod=44;
    int l=1,r=n;
    while (true){
        while (l+43<r){
            int m=(l+r)/2;
            if (l==m) query(l);
                else
            if (q(l,m)){
                r=m;
            }else
                l=m+1;
             l=max(1ll,l-k),r=min(n,r+k);
        }
        mod=44;
        mod=min(mod,r-l+1);
        query(l+(rand()%mod));
        l=max(1ll,l-k),r=min(n,r+k);
    }
    return 0;
}














