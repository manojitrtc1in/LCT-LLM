




using namespace std;

int n;
long long ans = 0;
deque<long long> a, t;

void solve() {
    scanf("%d", &n);
    if (n == 1) {
        printf("0");
        return;
    }
    a.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    sort(a.begin(), a.end());
    int n0 = (n % 2 == 0 ? 2 : 0);
    while (a.size() != 0 || t.size() != 1) {
        if (n0 != 0) {
            long long x = 0;
            for (int i = 0; i < n0; i++) {
                x += a.front();
                a.pop_front();
            }
            t.push_back(x);
            ans += x;
            n0 = 0;
            continue;
        }
        long long x = 0;
        for (int i = 0; i < 3 && (a.size() + t.size()) > 0; i++) {
            if (!t.empty() && (a.empty() || t.front() < a.front())) {
                x += t.front();
                t.pop_front();
            } else {
                x += a.front();
                a.pop_front();
            }	
        }
        t.push_back(x);
        ans += x;
    }
    printf("%I64d", ans);
}

int main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(false);
    if (!ONLINE_JUDGE) {





    } else {
        freopen("input.txt", "r", stdin);


    }


    solve();
    return 0;
}
