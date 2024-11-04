



using namespace std;
const int maxn = 1e6+5;
int lps[maxn];
bool cmp(int x, int y)
{
    return x > y;
}
signed main()
{
    int n, flag, l1, l2, ans;
    while(~scanf("%lld", &n))
    {
        l1 = l2 = flag = ans = 0;
        int in = 1e9;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld", &lps[i]);
            if(lps[i] == 0) flag = 1;
            else if(lps[i] > 0) l1 ++;
            else l2 ++;
            ans += abs(lps[i]);
        }
        if(n == 1)
        {
            printf("%lld\n", lps[1]);
            continue;
        }
        if(flag == 1||(l1<n&&l1>0))
        {
            printf("%lld\n", ans);
        }
        if(l1 == n)
        {
            sort(lps+1, lps+1+n);
            printf("%lld\n", ans -= lps[1] * 2);
        }
        else if(l2 == n)
        {
            sort(lps+1, lps+1+n, cmp);
            printf("%lld\n", ans += lps[1] * 2);
        }
    }
    return 0;
}



