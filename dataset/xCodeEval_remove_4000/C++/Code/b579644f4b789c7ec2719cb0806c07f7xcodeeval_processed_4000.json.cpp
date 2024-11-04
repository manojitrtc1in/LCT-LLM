


using namespace std;
void solve()
{
    string s;
    cin >> s;
    

    for (int i = 0; i < s.size(); i ++) s [ i ] = tolower(s [ i ]);
    cout << (s == "yes" ? "YES\n" : "NO\n");
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}



