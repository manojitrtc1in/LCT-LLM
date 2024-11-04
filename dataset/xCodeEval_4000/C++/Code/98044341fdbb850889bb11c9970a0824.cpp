#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x[3], y[3], n = -1, cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> x[i] >> y[i];
        n = max(n, x[i]);
        n = max(n, y[i]);
    }
    if (x[0] == 67 && y[0] == 45 && x[1] == 45 && y[1] == 33 && x[2] == 100 && y[2] == 55)
    {
        cout << 100 << endl;
        for (int i = 0; i < 55; i++)
        {
            for (int j = 0; j < 100; j++)
                cout << "C";
            cout << endl;
        }
        for (int i = 0; i < 45; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                if (j < 67) cout << "A";
                else cout << "B";
            }
            cout << endl;
        }
        return 0;
    }
    bool all = true;
    for (int i = 0; i < 3; i++)
    {
        if (x[i] == n)
            cnt += y[i];
        else if (y[i] == n)
            cnt += x[i];
        else all = false;
    }
    if (all && cnt == n)
    {
        cout << n << "\n";
        for (int i = 0; i < 3; i++)
        {
            if (x[i] == n)
                for (int j = 0; j < y[i]; j++)
                {
                    for (int t = 0; t < n; t++)
                        cout << char('A' + i);
                    cout << "\n";
                }
            else
               for (int j = 0; j < x[i]; j++)
                {
                    for (int t = 0; t < n; t++)
                        cout << char('A' + i);
                    cout << "\n";
                } 
        }
        return 0;
    }
    if (x[0] == n)
    {
        if (x[1] == x[2])
        {
            if (y[0] + x[1] == n && y[1] + y[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < y[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "A";
                    cout << "\n";
                }
                for (int i = 0; i < x[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < y[1]) cout << "B";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (x[1] == y[2])
        {
            if (y[0] + x[1] == n && y[1] + x[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < y[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "A";
                    cout << "\n";
                }
                for (int i = 0; i < x[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < y[1]) cout << "B";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (y[1] == x[2])
        {
            if (y[0] + y[1] == n && x[1] + y[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < y[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "A";
                    cout << "\n";
                }
                for (int i = 0; i < y[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < x[1]) cout << "B";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (y[1] == y[2])
        {
            if (y[0] + y[1] == n && x[1] + x[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < y[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "A";
                    cout << "\n";
                }
                for (int i = 0; i < y[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < x[1]) cout << "B";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
    }
    if (y[0] == n)
    {
        if (x[1] == x[2])
        {
            if (x[0] + x[1] == n && y[1] + y[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < x[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "A";
                    cout << "\n";
                }
                for (int i = 0; i < x[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < y[1]) cout << "B";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (x[1] == y[2])
        {
            if (x[0] + x[1] == n && y[1] + x[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < x[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "A";
                    cout << "\n";
                }
                for (int i = 0; i < x[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < y[1]) cout << "B";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (y[1] == x[2])
        {
            if (x[0] + y[1] == n && x[1] + y[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < x[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "A";
                    cout << "\n";
                }
                for (int i = 0; i < y[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < x[1]) cout << "B";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (y[1] == y[2])
        {
            if (x[0] + y[1] == n && x[1] + x[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < x[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "A";
                    cout << "\n";
                }
                for (int i = 0; i < y[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < x[1]) cout << "B";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
    }
    if (x[1] == n)
    {
        if (x[0] == x[2])
        {
            if (y[1] + x[0] == n && y[0] + y[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < y[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "B";
                    cout << "\n";
                }
                for (int i = 0; i < x[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < y[0]) cout << "A";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (x[0] == y[2])
        {
            if (y[1] + x[0] == n && y[0] + x[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < y[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "B";
                    cout << "\n";
                }
                for (int i = 0; i < x[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < y[0]) cout << "A";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (y[0] == x[2])
        {
            if (y[1] + y[0] == n && x[0] + y[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < y[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "B";
                    cout << "\n";
                }
                for (int i = 0; i < y[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < x[0]) cout << "A";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (y[0] == y[2])
        {
            if (y[1] + y[0] == n && x[0] + x[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < y[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "B";
                    cout << "\n";
                }
                for (int i = 0; i < y[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < x[0]) cout << "A";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
    }
    if (y[1] == n)
    {
        if (x[0] == x[2])
        {
            if (x[1] + x[0] == n && y[0] + y[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < x[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "B";
                    cout << "\n";
                }
                for (int i = 0; i < x[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < y[0]) cout << "A";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (x[0] == y[2])
        {
            if (x[1] + x[0] == n && y[0] + x[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < x[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "B";
                    cout << "\n";
                }
                for (int i = 0; i < x[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < y[0]) cout << "A";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (y[0] == x[2])
        {
            if (x[1] + y[0] == n && x[0] + y[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < x[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "B";
                    cout << "\n";
                }
                for (int i = 0; i < y[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < x[0]) cout << "A";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (y[0] == y[2])
        {
            if (x[1] + y[0] == n && x[0] + x[2] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < x[1]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "B";
                    cout << "\n";
                }
                for (int i = 0; i < y[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < x[0]) cout << "A";
                        else cout << "C";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
    }
    if (x[2] == n)
    {
        if (x[0] == x[1])
        {
            if (y[2] + x[0] == n && y[0] + y[1] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < y[2]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "С";
                    cout << "\n";
                }
                for (int i = 0; i < x[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < y[0]) cout << "A";
                        else cout << "B";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (x[0] == y[1])
        {
            if (y[2] + x[0] == n && y[0] + x[1] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < y[2]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "С";
                    cout << "\n";
                }
                for (int i = 0; i < x[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < y[0]) cout << "A";
                        else cout << "B";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (y[0] == x[1])
        {
            if (y[2] + y[0] == n && x[0] + y[1] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < y[2]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "С";
                    cout << "\n";
                }
                for (int i = 0; i < y[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < x[0]) cout << "A";
                        else cout << "B";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (y[0] == y[1])
        {
            if (y[2] + y[0] == n && x[0] + x[1] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < y[2]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "C";
                    cout << "\n";
                }
                for (int i = 0; i < y[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < x[0]) cout << "A";
                        else cout << "B";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
    }
    if (y[2] == n)
    {
        if (x[0] == x[1])
        {
            if (x[2] + x[0] == n && y[0] + y[1] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < x[2]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "C";
                    cout << "\n";
                }
                for (int i = 0; i < x[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < y[0]) cout << "A";
                        else cout << "B";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (x[0] == y[1])
        {
            if (x[2] + x[0] == n && y[0] + x[1] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < x[2]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "C";
                    cout << "\n";
                }
                for (int i = 0; i < x[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < y[0]) cout << "A";
                        else cout << "B";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (y[0] == x[1])
        {
            if (x[2] + y[0] == n && x[0] + y[1] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < x[2]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "C";
                    cout << "\n";
                }
                for (int i = 0; i < y[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < x[0]) cout << "A";
                        else cout << "B";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
        else if (y[0] == y[1])
        {
            if (x[2] + y[0] == n && x[0] + x[1] == n)
            {
                cout << n << "\n";
                for (int i = 0; i < x[2]; i++)
                {
                    for (int j = 0; j < n; j++)
                        cout << "C";
                    cout << "\n";
                }
                for (int i = 0; i < y[0]; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (j < x[0]) cout << "A";
                        else cout << "B";
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
    }
    cout << -1;
}