






using namespace std;
int n, s = 1000000, a[1000005], use[500005], X[500005], p = 1;
vector<int> y;

int findpair() {
    while (use[p]) {
        p++;
    }
    use[p] = 1;
    return p;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &X[i]);
        a[X[i]] = 1;
        int index = X[i] <= s / 2? X[i] : s + 1 - X[i];
        use[index] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (a[X[i]] != -1) {
            if (!a[s+1-X[i]]) {
                y.push_back(s+1-X[i]);
                a[s+1-X[i]] = 1;
                use[min(X[i], s+1-X[i])] = 1;
            } else {
                a[s +1 - X[i]] = -1;
                int f = findpair();
                

                y.push_back(f);
                y.push_back(s + 1 - f);
            }
        }
    }
    int sz = y.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i++) {
        printf("%d ", y[i]);
    }

    return 0;
}

















































