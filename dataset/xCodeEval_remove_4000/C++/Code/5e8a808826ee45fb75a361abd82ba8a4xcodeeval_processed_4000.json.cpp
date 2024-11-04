





using namespace std;
typedef long long ll;
const ll N = 2e5 + 7;

int n;
int tmp[N];
int a[N], val[N], sta[N];
int dpl[N], dpr[N];


void init(int n, int *dp)
{
    int top = 0;
    int mx = 0;
    for (int i = 1; i <= n;i++)
    {
        int ma = 0;
        while(top && a[sta[top]] > a[i])
        {
            ma = max(ma, val[top]);
            top--;   
        }

        sta[++top] = i;

        if(ma == 0) val[top] = top;
        else val[top] = ma + 1;

        mx = max(mx, val[top]);
        dp[i] = mx;
    }
}


int main()
{
    scanf("%d", &n);
    if(n == 1) 
    {
        printf("%d %d\n", 1, 0);
        return 0;
    }
    int mi = 1e9, rt;
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &tmp[i]);
        if(tmp[i] < mi) mi = tmp[i], rt = i;
    }

    for (int i = 1, j = rt - 1; i < n;i++, j--)
    {
        if(j < 1) j += n;
        a[i] = tmp[j];
    }
    init(n - 1, dpl);
    for (int i = 1, j = rt + 1; i < n;i++,j++)
    {
        if (j > n) j -= n;
        a[i] = tmp[j];
    }
    init(n - 1, dpr);
    int ans = 1e9, shft;
    for (int i = 0; i < n;i++)
    {
        if(ans > max(dpl[i], dpr[n - 1 - i]) + 1)
        {
            ans = max(dpl[i], dpr[n - 1 - i]) + 1;
            shft = rt - (i + 1);
        }
    }
    

    if(shft < 0) shft += n;
    printf("%d %d\n", ans, shft);
    return 0;
}