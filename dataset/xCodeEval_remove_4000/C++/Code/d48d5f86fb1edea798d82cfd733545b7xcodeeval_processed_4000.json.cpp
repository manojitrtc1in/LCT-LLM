

























using namespace std;


void Solve()
{
    ll n, k;
    cin >> n >> k;
    if ((n - k)%2 == 0 && n >= k*k)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        Solve();
}
