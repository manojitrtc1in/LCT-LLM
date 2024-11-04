


































using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        cin.tie(0);
        int n;
        char c;
        cin >> n;
        

        

        set<char>s;
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            s.insert(c);
        }
        cout << s.size() + n << "\n";
    }
    return 0;
}