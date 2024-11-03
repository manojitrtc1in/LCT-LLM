

using namespace std;


















int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        unsigned long long rc = count(s.begin(),s.end(),'R'),dc = count(s.begin(),s.end(),'D'),st = max(s.find('R'),s.find('D'));
        if(st == string::npos)
        {
            cout << n << "\n";
            continue;
        }
        cout << st + (n-rc)*(n-dc) + (s[0] == 'R' ? (rc-st)*(n-dc) + (n-rc)*(dc) : (rc)*(n-dc) + (n-rc)*(dc-st)) << "\n";
    }
}
