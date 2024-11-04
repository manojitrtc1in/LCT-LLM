


using namespace std;
typedef long long ll;
typedef long long int lli;

    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void solve(int n, int m, int sx, int sy, int d)
{
    int count = 0;
    if ((abs(n - sx) > d) && (abs(1 - sy) > d))
        count++;
    if ((abs(1 - sx) > d) && abs((m - sy) > d) )
        count++;

    if (count >= 1)
        cout << n + m - 2;
    else
        cout << -1;
}
int main()
{
    KAMUI
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        
        solve(n, m, sx, sy, d);

        cout << "\n";
    }
    return 0;
}