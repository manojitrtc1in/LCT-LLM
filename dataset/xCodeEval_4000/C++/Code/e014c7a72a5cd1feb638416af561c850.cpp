

#include <bits/stdc++.h>
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#define nn "\n"
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define mapa(a,b) make_pair(a,b)
#define mm(a,b) memset(a,b, sizeof(a));
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Forr(i,a,b,c) for(int i=a,c=a;i<=b;i++)
#define Rof(i,a,b) for(int i=a;i>=b;i--)
#define Roff(i,a,b,c) for(int i=a,c=a;i>=b;i--)
#define put(x) cout<<x<<"\n";
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
template <typename T> T gcd (T a, T b)
{
    while (b ^= a ^= b ^= a %= b);
    return a;
}
#define o (judge(i)+judge(i-1)+judge(i+1))
const int N=1e6+10;
int num[N],num1[N],num2[N],num3[N];


int t;
int n1,n2,n3;
string str1,str2;



int main()
{
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        For(i,0,n-1)
        {
            cin>>num[i];
        }
        if(n==1&&num[0]>1&&m!=0)
        {
            cout<<2<<endl;
            continue;
        }
        sort(num,num+n);
        int Min=0;
        For(i,1,n-1)
        {
            if(num[i]-num[i-1]>1)
            {
                Min=num[i-1]+1;
                break;
            }
        }
        if(Min==0)
        {
            if(num[0]!=0)
                cout<<n<<endl;
            else
                cout<<n+m<<endl;
            continue;
        }
        int ans=Min+num[n-1];
        if(ans%2==0)
            ans/=2;
        else
            ans=ans/2+1;
        int sum1=lower_bound(num,num+n,ans)-num;
        int sum2=upper_bound(num,num+n,ans)-num;
        if(m==0)
            cout<<n<<endl;
        else if(sum1==sum2)
        {
            cout<<n+1<<endl;
        }
        else
            cout<<n<<endl;
    }
    return 0;
}
