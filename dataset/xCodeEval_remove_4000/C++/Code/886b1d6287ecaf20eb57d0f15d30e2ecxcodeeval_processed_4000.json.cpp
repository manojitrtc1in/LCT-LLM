






using namespace std;

int main()
{
    const long long M = 1000000000;
    int n, m;
    cin >> n >> m;
    vector <int> a(n + 1);
    for (int i = 1; i <= n ; ++i)
        cin >> a[i];
    for (int t = 0; t < m; ++t)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            cin >> x >> y;
            a[x] = y;
        }
        if (type == 2)
        {
            int start, end;
            cin >> start >> end;
            long long answer = 0;
            vector <long long> f(end - start + 3);
            f[0] = f[1] = 1;
            for (int x = 0; x <= end- start; ++x)
            {
                if (x >= 2)
                    f[x] = (f[x - 1] + f[x - 2])% M;
                answer += f[x] * a[start + x];
                answer %= M;                
            }
            cout << answer << endl;
        }
    }
}




