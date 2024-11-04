













using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;








int gcd(int x, int y){
    if (y == 0){
        return x;
    } else {
        return gcd(y, x % y);
    }
}
int quickPower(int a, int b)

{
    int ans = 1, base = a;

    while(b > 0)

        {
        if(b & 1)

            ans *= base;


            base *= base;

            b >>= 1;

        }
    return ans;
}
bool cmp(ld x,ld y){
    if (abs(x-y)<=1e-9)
        return true;
    return false;
}

ld Power(ld base,int exponent){
    ld sum=1;
    ld curr=base;
    int n;
    if(exponent>0)
        n=exponent;
    else if(exponent<0){
        if(base==0)
            exit(EXIT_FAILURE);
        n=-exponent;
    }
    else if(exponent==0){
        return 1;
    }
    while(n !=0){
        if((n&1)==1)
            sum*=curr;
        curr*=curr;
        n>>=1;
    }
    return (exponent>0)?sum : (ld ( 1)/ sum);
}






int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int kase;
    scanf("%d",&kase);
    while(kase--){
        ll n,x;
        scanf("%lld %lld",&n,&x);
        vector<ll>a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld",&a[i]);
        }
        map<ll,ll>d;
        for(auto i:a){
            if (d.find(i)!=d.end())
                d[i]+=1;
            else
                d[i]=1;
        }
        ll ans = 0;
        sort(a.begin(),a.end());
        

        

        

        

        

        

        for(auto i: a){
            if (d.find(i)!=d.end()&&d[i]>=1) {
                if (d.find(i) != d.end() && d[i * x] >= 1) {
                    d[i]-=1;
                    d[i * x]-=1;
                } else {
                    d[i]-=1;
                    ans+=1;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}