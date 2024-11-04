
































































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
