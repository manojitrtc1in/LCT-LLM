

using namespace std;


















int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int64_t n;
        cin >> n;
        int64_t x = 0;
        int64_t a[n][n];
        for(int64_t i = 0;i < n;++i)
        {
            for(int64_t j= 0;j < n;++j)
            {
                cin >> a[i][j];
                if((min(i,min(n-i-1,min(j,n-j-1)))/2)%2 == 0)
                    x ^= a[i][j];
            }
        }
        for(int i = 0;i < n;++i)
        {
            for(int j = 0;j < n;++j)
            {
                if((i + j)%2 == 0 && i+j < n-1 && i%2 == 0)
                    x ^= a[i][j];
                if((i + n - j - 1)%2 == 0 && (i + n - j - 1) < n-1 && (n-j-1)%2 == 0)
                    x ^= a[i][j];
            }
        }
        cout << x << "\n";
    }
}
