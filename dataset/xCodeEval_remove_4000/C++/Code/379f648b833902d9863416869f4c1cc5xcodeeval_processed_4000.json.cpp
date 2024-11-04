


using namespace std;

const int k = 70;
int g[k][k];
void answer(int a, int b, int c, int d, int e) {
    cout << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << " " << e + 1 << "\n"; 
    exit(0);
}
void id0(int n) {
    int a[5], b[2];
    for (a[0] = 0; a[0] < n; a[0]++)
        for (a[1] = a[0] + 1; a[1] < n; a[1]++)
            for (a[2] = a[1] + 1; a[2] < n; a[2]++)
                for (a[3] = a[2] + 1; a[3] < n; a[3]++)
                    for (a[4] = a[3] + 1; a[4] < n; a[4]++) {
                        b[0] = b[1] = 1;
                        for (int i = 0; i < 5; i++) for (int j = 0; j < i; j++) {
                            b[0] &= !g[a[i]][a[j]];
                            b[1] &= g[a[i]][a[j]];
                        }
                        if (b[0] || b[1]) answer(a[0], a[1], a[2], a[3], a[4]);
                    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a < k && b < k)
            g[a][b] = g[b][a] = 1;
    }
    id0(min(n, k));
    cout << "-1\n";
    return 0;
}