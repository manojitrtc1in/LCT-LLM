





























































using namespace std;
typedef long long ll;
template <typename T> T gcd (T a, T b)
{
    while (b ^= a ^= b ^= a %= b);
    return a;
}

const int N=1e6+10;
int num[N],num1[N],num2[N],num3[N];
int t;



int main()
{
    int t,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&x,&y);
        ll ans=0;
        for(int k=1; k*(k+2)<=x&&k<=y-1; k++)
        {
            int Min = k+1;
            int Max = min(y,x/k-1);
            if(Max>=Min)
                ans+=Max-Min+1;

        }
        printf("%lld\n",ans);
    }
    return 0;
}
