




using namespace std;

void solve()
{
    int tests = 0;
    int n = 0;
    int arr[100];
    scanf("%d", &tests);
    while (tests--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        set<int> cnt;
        bitset<1000000> forbidden;
        vector<int> ans;
        int i = 1;
        while (ans.size() < n && i <= 1000000)
        {
            bool ac = true;
            for (int j = 0; ac && j < n; j++)
                if (cnt.count(i + arr[j]))
                    ac = false;
            if (ac)
            {
                for (int j = 0; j < n; j++)
                {
                    cnt.insert(arr[j] + i);
                    for (int k = 0; k < n; k++)
                        if (arr[j] + i - arr[k] > 0)
                            forbidden[arr[j] + i - arr[k]] = true;
                }
                ans.push_back(i);
            }
            while (forbidden[i])
                i++;
        }
        assert(ans.size() == n);

        printf("YES\n");
        for (const int &e : ans)
            printf("%d ", e);
        printf("\n");
    }
}
int main()
{
    srand (time(nullptr));
    if (!ONLINE_JUDGE) 

    {




    } else
        freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
