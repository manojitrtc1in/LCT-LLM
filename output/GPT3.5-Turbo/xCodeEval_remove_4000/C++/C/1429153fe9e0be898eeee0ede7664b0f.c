void solve() {
    int n;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int idx[n][n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == n-1-j || i == n/2 || j == n/2) {
                idx[i][j] = count;
                count++;
            } else {
                idx[i][j] = -1;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (idx[i][j] != -1) {
                sum += a[i][j];
            }
        }
    }
    printf("%d\n", sum);
}
