

using namespace std;


















const int64_t mod = 1000000007;
const int64_t maxn = 1000005;

vector<int64_t> fact,invfact;

int64_t binpow(int64_t a,int64_t b)
{
    return (b == 0 ? 1 : (b%2 == 0 ? (binpow((a*a)%mod,b/2)) : (a*binpow(a,b-1))%mod));
}
int64_t del(int64_t a,int64_t b)
{
    return (a*binpow(b,mod-2))%mod;
}
int64_t cnk(int64_t n,int64_t k)
{
    return (((fact[n]*invfact[k])%mod)*invfact[n-k])%mod;
}

int main()
{
    int64_t t;
    cin >> t;
    fact.resize(maxn);
    invfact.resize(maxn);
    fact[0] = 1;
    invfact[0] = 1;
    for(int i = 1;i < maxn;++i)
    {
        fact[i] = (fact[i-1]*i)%mod;
        invfact[i] = del(1,fact[i]);
    }
    while(t--)
    {
        int64_t n,m,k;
        cin >> n >> m >> k;
        int64_t ans = 0;
        int64_t sum = 0;
        for(int i = 0;i < m;++i)
        {
            int64_t di = (((i+1)*binpow(2,i))%mod-sum+mod)%mod;
            int64_t c = cnk(n-i-1,m-i-1);
            ans += (di*c)%mod;
            ans = ans%mod;
            sum += di;
            sum = sum%mod;
        }
        cout << (del(ans,(binpow(2,n-1)))*k)%mod << "\n";
    }
}
