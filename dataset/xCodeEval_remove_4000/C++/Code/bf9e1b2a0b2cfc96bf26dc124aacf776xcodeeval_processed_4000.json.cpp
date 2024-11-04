
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long M = pow(10, 9) + 7;
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n], c;
        vector<int> g, count;
        map<int, int> p;

        for (int &el : a)
            cin >> el;
        for (int &el : b)
            cin >> el;
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            if (c == 0 && a[i] != b[i])
            {
                p.insert({a[i], b[i]});
            }
        }

        int i = 0;
        while (p.size() > 0)
        {
            pair<int, int> x = *p.begin();
            int first = x.first;
            int hand = x.second;
            p.erase(first);
            g.push_back(1);
            while (first != hand)
            {
                if (p.count(hand))
                {
                    g[i]++;
                    int temp = hand;
                    hand = p[hand];
                    p.erase(temp);
                }
                else
                {
                    g.pop_back();
                    i--;
                    break;
                }
            }
            i++;
        }
        int pw = g.size();
        long long res = 1;
        while (pw--)
            res = res * 2 % M;

        cout << res << "\n";
     }
}

