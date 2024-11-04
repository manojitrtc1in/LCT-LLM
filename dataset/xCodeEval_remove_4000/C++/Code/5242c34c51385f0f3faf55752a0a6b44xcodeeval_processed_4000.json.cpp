






























using namespace std;



typedef long long ll;
typedef long double ld;
typedef short int si;
typedef unsigned long long ull;

typedef pair <int, int> pt;





int main()
{
    ios_base::sync_with_stdio(0); istream::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q;

    cin >> q;

    for (; q > 0; q--)
    {
        int n, m;

        cin >> n >> m;

        int a[n][m];

        string s[n];

        for (int i = 0; i < n; i++) cin >> s[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) a[i][j] = (s[i][j] - '0');

        vector <array <int, 6> > vr; vr.clear();

        if (n % 2)
        {
            for (int j = 0; j < m - 1; j += 2)
            {
                if (a[n - 1][j] == a[n - 1][j + 1] && a[n - 1][j] == 0) continue;

                if (a[n - 1][j] == 1 && a[n - 1][j + 1] != 1)
                {
                    vr.PB({n - 1, j, n - 2, j, n - 2, j + 1});

                    int t = 0;

                    while (t < 6)
                    {
                        int x = vr.back()[t], y = vr.back()[t + 1];

                        a[x][y] = (a[x][y] + 1) % 2;

                        t += 2;
                    }

                    continue;
                }

                if (a[n - 1][j] == 0 && a[n - 1][j + 1] != 0)
                {
                    vr.PB({n - 1, j + 1, n - 2, j, n - 2, j + 1});

                    int t = 0;

                    while (t < 6)
                    {
                        int x = vr.back()[t], y = vr.back()[t + 1];

                        a[x][y] = (a[x][y] + 1) % 2;

                        t += 2;
                    }

                    continue;
                }


                vr.PB({n - 1, j, n - 2, j, n - 1, j + 1});

                int t = 0;

                while (t < 6)
                {
                    int x = vr.back()[t], y = vr.back()[t + 1];

                    a[x][y] = (a[x][y] + 1) % 2;

                    t += 2;
                }
            }
        }

        if (m % 2)
        {
            for (int i = 0; i < n - 1; i += 2)
            {
                if (a[i][m - 1] == a[i + 1][m - 1] && a[i][m - 1] == 0) continue;

                if (a[i][m - 1] == 1 && a[i + 1][m - 1] != 1)
                {
                    vr.PB({i, m - 1, i + 1, m - 2, i, m - 2});

                    int t = 0;

                    while (t < 6)
                    {
                        int x = vr.back()[t], y = vr.back()[t + 1];

                        a[x][y] = (a[x][y] + 1) % 2;

                        t += 2;
                    }

                    continue;
                }

                if (a[i][m - 1] == 0 && a[i + 1][m - 1] != 0)
                {
                    vr.PB({i + 1, m - 1, i + 1, m - 2, i, m - 2});

                    int t = 0;

                    while (t < 6)
                    {
                        int x = vr.back()[t], y = vr.back()[t + 1];

                        a[x][y] = (a[x][y] + 1) % 2;

                        t += 2;
                    }

                    continue;
                }

                vr.PB({i, m - 1, i + 1, m - 1, i, m - 2});

                int t = 0;

                while (t < 6)
                {
                    int x = vr.back()[t], y = vr.back()[t + 1];

                    a[x][y] = (a[x][y] + 1) % 2;

                    t += 2;
                }
            }
        }

        for (int i = 0; i < n - 1; i += 2)
            for (int j = 0; j < m - 1; j += 2)
            {
                if (a[i][j] == 0 && a[i + 1][j] == a[i][j] && a[i + 1][j + 1] == a[i][j] && a[i][j] == a[i][j + 1]) continue;

                if (a[i][j] == 1 && a[i + 1][j] == a[i][j] && a[i + 1][j + 1] == a[i][j] && a[i][j] == a[i][j + 1])
                {
                    vr.PB({i, j, i, j + 1, i + 1, j + 1});

                    vr.PB({i, j, i + 1, j, i, j + 1});

                    vr.PB({i, j, i + 1, j + 1, i + 1, j});

                    vr.PB({i + 1, j, i + 1, j + 1, i, j + 1});

                    a[i][j] = a[i][j + 1] = a[i + 1][j] = a[i + 1][j + 1] = 0;

                    continue;
                }

                int kl = 0;

                if (a[i][j] == 1) kl++;
                if (a[i + 1][j] == 1) kl++;
                if (a[i][j + 1] == 1) kl++;
                if (a[i + 1][j + 1] == 1) kl++;

                if (kl == 3)
                {
                    int t = 0;

                    vr.emplace_back();

                    if (a[i][j] == 1) {vr.back()[t++] = i; vr.back()[t++] = j;}
                    if (a[i + 1][j] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j;}
                    if (a[i][j + 1] == 1){vr.back()[t++] = i; vr.back()[t++] = j + 1;}
                    if (a[i + 1][j + 1] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1;}

                    a[i][j] = a[i][j + 1] = a[i + 1][j] = a[i + 1][j + 1] = 0;

                    continue;
                }

                if (kl == 2)
                {
                    int t = 0;

                    bool f = 0;

                    vr.emplace_back();

                    if (a[i][j] == 0) {vr.back()[t++] = i; vr.back()[t++] = j; a[i][j] = 1;} else {vr.back()[t++] = i; vr.back()[t++] = j; f = 1; a[i][j] = 0;}
                    if (a[i + 1][j] == 0) {vr.back()[t++] = i + 1; vr.back()[t++] = j; a[i + 1][j] = 1;} else if (!f) {vr.back()[t++] = i + 1; vr.back()[t++] = j; f = 1; a[i + 1][j] = 0;}
                    if (a[i][j + 1] == 0) {vr.back()[t++] = i; vr.back()[t++] = j + 1; a[i][j + 1] = 1;} else if (!f) {vr.back()[t++] = i; vr.back()[t++] = j + 1; f = 1; a[i][j + 1] = 0;}
                    if (a[i + 1][j + 1] == 0) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1; a[i + 1][j + 1] = 1;} else if (!f) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1; f = 1; a[i + 1][j + 1] = 0;}

                    vr.emplace_back();

                    t = 0;

                    if (a[i][j] == 1) {vr.back()[t++] = i; vr.back()[t++] = j;}
                    if (a[i + 1][j] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j;}
                    if (a[i][j + 1] == 1){vr.back()[t++] = i; vr.back()[t++] = j + 1;}
                    if (a[i + 1][j + 1] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1;}

                    a[i][j] = a[i][j + 1] = a[i + 1][j] = a[i + 1][j + 1] = 0;
                }

                if (kl == 1)
                {
                    int t = 0;

                    vr.emplace_back();

                    if (a[i][j] == 1) {vr.back()[t++] = i; vr.back()[t++] = j; }
                    if (a[i + 1][j] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j; }
                    if (a[i][j + 1] == 1){vr.back()[t++] = i; vr.back()[t++] = j + 1; }
                    if (a[i + 1][j + 1] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1; }

                    if (a[i][j] == 0 && t < 6) {vr.back()[t++] = i; vr.back()[t++] = j; }
                    if (a[i + 1][j] == 0 && t < 6) {vr.back()[t++] = i + 1; vr.back()[t++] = j; }
                    if (a[i][j + 1] == 0 && t < 6){vr.back()[t++] = i; vr.back()[t++] = j + 1; }
                    if (a[i + 1][j + 1] == 0 && t < 6) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1; }

                    t = 0;

                    while (t < 6)
                    {
                        int x = vr.back()[t], y = vr.back()[t + 1];

                        a[x][y] = (a[x][y] + 1) % 2;

                        t += 2;
                    }

                    bool f = 0;

                    t = 0;

                    vr.emplace_back();

                    if (a[i][j] == 0) {vr.back()[t++] = i; vr.back()[t++] = j; a[i][j] = 1;} else {vr.back()[t++] = i; vr.back()[t++] = j; f = 1; a[i][j] = 0;}
                    if (a[i + 1][j] == 0) {vr.back()[t++] = i + 1; vr.back()[t++] = j; a[i + 1][j] = 1;} else if (!f) {vr.back()[t++] = i + 1; vr.back()[t++] = j; f = 1; a[i + 1][j] = 0;}
                    if (a[i][j + 1] == 0) {vr.back()[t++] = i; vr.back()[t++] = j + 1; a[i][j + 1] = 1;} else if (!f) {vr.back()[t++] = i; vr.back()[t++] = j + 1; f = 1; a[i][j + 1] = 0;}
                    if (a[i + 1][j + 1] == 0) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1; a[i + 1][j + 1] = 1;} else if (!f) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1; f = 1; a[i + 1][j + 1] = 0;}

                    vr.emplace_back();

                    t = 0;

                    if (a[i][j] == 1) {vr.back()[t++] = i; vr.back()[t++] = j;}
                    if (a[i + 1][j] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j;}
                    if (a[i][j + 1] == 1){vr.back()[t++] = i; vr.back()[t++] = j + 1;}
                    if (a[i + 1][j + 1] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1;}

                    a[i][j] = a[i][j + 1] = a[i + 1][j] = a[i + 1][j + 1] = 0;
                }
            }

        for (int i = n - 2; i <= n - 2; i++)
            for (int j = m - 2; j <= m - 2; j++)
            {
                if (a[i][j] == 0 && a[i + 1][j] == a[i][j] && a[i + 1][j + 1] == a[i][j] && a[i][j] == a[i][j + 1]) continue;

                if (a[i][j] == 1 && a[i + 1][j] == a[i][j] && a[i + 1][j + 1] == a[i][j] && a[i][j] == a[i][j + 1])
                {
                    vr.PB({i, j, i, j + 1, i + 1, j + 1});

                    vr.PB({i, j, i + 1, j, i, j + 1});

                    vr.PB({i, j, i + 1, j + 1, i + 1, j});

                    vr.PB({i + 1, j, i + 1, j + 1, i, j + 1});

                    a[i][j] = a[i][j + 1] = a[i + 1][j] = a[i + 1][j + 1] = 0;

                    continue;
                }

                int kl = 0;

                if (a[i][j] == 1) kl++;
                if (a[i + 1][j] == 1) kl++;
                if (a[i][j + 1] == 1) kl++;
                if (a[i + 1][j + 1] == 1) kl++;

                if (kl == 3)
                {
                    int t = 0;

                    vr.emplace_back();

                    if (a[i][j] == 1) {vr.back()[t++] = i; vr.back()[t++] = j;}
                    if (a[i + 1][j] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j;}
                    if (a[i][j + 1] == 1){vr.back()[t++] = i; vr.back()[t++] = j + 1;}
                    if (a[i + 1][j + 1] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1;}

                    a[i][j] = a[i][j + 1] = a[i + 1][j] = a[i + 1][j + 1] = 0;

                    continue;
                }

                if (kl == 2)
                {
                    int t = 0;

                    bool f = 0;

                    vr.emplace_back();

                    if (a[i][j] == 0) {vr.back()[t++] = i; vr.back()[t++] = j; a[i][j] = 1;} else {vr.back()[t++] = i; vr.back()[t++] = j; f = 1; a[i][j] = 0;}
                    if (a[i + 1][j] == 0) {vr.back()[t++] = i + 1; vr.back()[t++] = j; a[i + 1][j] = 1;} else if (!f) {vr.back()[t++] = i + 1; vr.back()[t++] = j; f = 1; a[i + 1][j] = 0;}
                    if (a[i][j + 1] == 0) {vr.back()[t++] = i; vr.back()[t++] = j + 1; a[i][j + 1] = 1;} else if (!f) {vr.back()[t++] = i; vr.back()[t++] = j + 1; f = 1; a[i][j + 1] = 0;}
                    if (a[i + 1][j + 1] == 0) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1; a[i + 1][j + 1] = 1;} else if (!f) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1; f = 1; a[i + 1][j + 1] = 0;}

                    vr.emplace_back();

                    t = 0;

                    if (a[i][j] == 1) {vr.back()[t++] = i; vr.back()[t++] = j;}
                    if (a[i + 1][j] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j;}
                    if (a[i][j + 1] == 1){vr.back()[t++] = i; vr.back()[t++] = j + 1;}
                    if (a[i + 1][j + 1] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1;}

                    a[i][j] = a[i][j + 1] = a[i + 1][j] = a[i + 1][j + 1] = 0;
                }

                if (kl == 1)
                {
                    int t = 0;

                    vr.emplace_back();

                    if (a[i][j] == 1) {vr.back()[t++] = i; vr.back()[t++] = j; }
                    if (a[i + 1][j] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j; }
                    if (a[i][j + 1] == 1){vr.back()[t++] = i; vr.back()[t++] = j + 1; }
                    if (a[i + 1][j + 1] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1; }

                    if (a[i][j] == 0 && t < 6) {vr.back()[t++] = i; vr.back()[t++] = j; }
                    if (a[i + 1][j] == 0 && t < 6) {vr.back()[t++] = i + 1; vr.back()[t++] = j; }
                    if (a[i][j + 1] == 0 && t < 6){vr.back()[t++] = i; vr.back()[t++] = j + 1; }
                    if (a[i + 1][j + 1] == 0 && t < 6) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1; }

                    t = 0;

                    while (t < 6)
                    {
                        int x = vr.back()[t], y = vr.back()[t + 1];

                        a[x][y] = (a[x][y] + 1) % 2;

                        t += 2;
                    }

                    bool f = 0;

                    t = 0;

                    vr.emplace_back();

                    if (a[i][j] == 0) {vr.back()[t++] = i; vr.back()[t++] = j; a[i][j] = 1;} else {vr.back()[t++] = i; vr.back()[t++] = j; f = 1; a[i][j] = 0;}
                    if (a[i + 1][j] == 0) {vr.back()[t++] = i + 1; vr.back()[t++] = j; a[i + 1][j] = 1;} else if (!f) {vr.back()[t++] = i + 1; vr.back()[t++] = j; f = 1; a[i + 1][j] = 0;}
                    if (a[i][j + 1] == 0) {vr.back()[t++] = i; vr.back()[t++] = j + 1; a[i][j + 1] = 1;} else if (!f) {vr.back()[t++] = i; vr.back()[t++] = j + 1; f = 1; a[i][j + 1] = 0;}
                    if (a[i + 1][j + 1] == 0) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1; a[i + 1][j + 1] = 1;} else if (!f) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1; f = 1; a[i + 1][j + 1] = 0;}

                    vr.emplace_back();

                    t = 0;

                    if (a[i][j] == 1) {vr.back()[t++] = i; vr.back()[t++] = j;}
                    if (a[i + 1][j] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j;}
                    if (a[i][j + 1] == 1){vr.back()[t++] = i; vr.back()[t++] = j + 1;}
                    if (a[i + 1][j + 1] == 1) {vr.back()[t++] = i + 1; vr.back()[t++] = j + 1;}

                    a[i][j] = a[i][j + 1] = a[i + 1][j] = a[i + 1][j + 1] = 0;
                }
            }

        pri(sz(vr));

        for (auto it : vr) pri(it[0] + 1 _ it[1] + 1 _ it[2] + 1 _ it[3] + 1 _ it[4] + 1 _ it[5] + 1);
    }
}
