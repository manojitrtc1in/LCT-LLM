










using namespace std;

int32_t main() {
    cout.precision(20);
    int n, r;
    cin >> n >> r;
    vector <int> num(pow(2, n));
    int sum = 0;
    for (int i = 0; i < pow(2, n); i++) {
        cin >> num[i];
        sum += num[i];
    }
    long double ans = (long double) sum / (long double) num.size();
    cout << ans << "\n";
    for (int i = 0; i < r; i++) {
        int pos, x;
        cin >> pos >> x;
        sum = sum + x - num[pos];
        num[pos] = x;
        cout <<  (long double) sum / (long double) num.size() << "\n";
    }
    return 0;
}
