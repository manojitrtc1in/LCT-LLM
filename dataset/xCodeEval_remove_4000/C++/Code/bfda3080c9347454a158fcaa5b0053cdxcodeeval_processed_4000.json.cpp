

using namespace std;

void id0 ()
{
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for ( int i = 0; i < n; i++) cin >> a[i].first;
    for ( int i = 0; i < n; i++) cin >> a[i].second;
    vector<int> res;
    for ( int i = 0; i < n; i++)
    {
        res.push_back(1ll*(a[i].first - a[i].second));
    }
    sort ( res.begin(), res.end());
    int j = n - 1;
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        if ( res[i] > 0) break;
        else
        {
            auto it = upper_bound (res.begin() + i +1, res.begin() + j + 1, -res[i]) - res.begin() - 1;

            if (it> i) {val++; j = it - 1;}
        }
    }
    cout << val << '\n';

}
signed main ()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--)
    {
        id0();
    }
}

