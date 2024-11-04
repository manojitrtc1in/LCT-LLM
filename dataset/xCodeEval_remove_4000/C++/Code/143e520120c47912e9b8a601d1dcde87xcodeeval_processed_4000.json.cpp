




typedef long long ll;
using namespace std;

struct al { int s, a; };
bool cmp1(const al& a, const al& b) { return a.s < b.s; }
bool cmp2(const al& a, const al& b) { return a.a < b.a; }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    vector<al> t1, t2;
    for (int i = 0; i < n; i++)
    {
        al a;
        cin >> a.s >> a.a;
        if (a.s < d) continue;
        if (a.a <= a.s) t1.push_back(a);
        else t2.push_back(a);
    }
    sort(t1.begin(), t1.end(), cmp1);
    sort(t2.begin(), t2.end(), cmp2);
    int ans = t1.size();
    for (int i1 = 0, i2 = 0; i2 < t2.size(); i2++)
    {
        while (i1 < t1.size() && t1[i1].s < t2[i2].a) d = max(d, t1[i1].a), i1++;
        if (d <= t2[i2].s) d = max(d, t2[i2].a), ans++;
    }
    cout << ans << "\n";
    return 0;
}