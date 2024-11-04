


using namespace std;
typedef long long ll;
typedef long long int lli;
const unsigned int MOD = 1000000007;




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        int a[n], b[n];
        int A[n], B[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            A[i] = a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            B[i] = b[i];
        }

        sort(A, A + n);
        sort(B, B + n);
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == A[i] && b[i] == B[i])
                continue;
            else
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (a[j] == A[i] && b[j] == B[i])
                    {
                        v.push_back({i + 1, j + 1});
                        swap(a[i], a[j]);
                        swap(b[i], b[j]);
                    }
                }
            }
            if (a[i] == A[i] && b[i] == B[i])
                continue;
            else
            {
                flag = false;
                break;
            }
        }

        if (flag == false)
            cout << -1 << "\n";

        else
        {
            cout << v.size() << "\n";
            for (auto x : v)
                cout << x.first << " " << x.second << "\n";
        }
    }
    return 0;
}