



using namespace std;

const int N = 1e6 + 5;
const int MASK0 = 1 << 0;
const int MASK1 = 1 << 1;
const int MASK2 = 1 << 2;
const int MASK01 = MASK0 | MASK1;
const int MASK02 = MASK0 | MASK2;
const int MASK12 = MASK1 | MASK2;
const int MASK012 = MASK0 | MASK1 | MASK2;

long long n, r1, r2, r3, d, a[N];
long long dp[N][1 << 3][2];



int test (int num, int bit) {
    return (num >> bit) & 1;
}

void minimize (long long &x, long long y) {
    x = min(x, y);
}



signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];

    memset(dp, 0x3f, sizeof(dp));
    dp[0][MASK012][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int pmask = 0; pmask < 8; pmask++) {
            

            if (dp[i][pmask | MASK2][0] > dp[i - 1][pmask][0] + r3 * (a[i] + test(pmask, 2)) + d) {
                minimize(dp[i][pmask | MASK2][0], dp[i - 1][pmask][0] + r3 * (a[i] + test(pmask, 2)) + d);
                

            }
            if (dp[i][pmask | MASK2][0] > dp[i - 1][pmask][1] + r3 * (a[i] + test(pmask, 2)) + d + (r3 + d + d) - (i == n ? d : 0)) {
                minimize(dp[i][pmask | MASK2][0], dp[i - 1][pmask][1] + r3 * (a[i] + test(pmask, 2)) + d + (r3 + d + d) - (i == n ? d : 0));
                

            }
            if (dp[i][pmask | MASK02][0] > dp[i - 1][pmask][1] + r3 * (a[i] + test(pmask, 2)) + d + (r1 * test(pmask, 0) + d + d) - (i == n ? d : 0)) {
                minimize(dp[i][pmask | MASK02][0], dp[i - 1][pmask][1] + r3 * (a[i] + test(pmask, 2)) + d + (r1 * test(pmask, 0) + d + d) - (i == n ? d : 0));
                

            }
            if (dp[i][pmask | MASK12][0] > dp[i - 1][pmask][1] + r3 * (a[i] + test(pmask, 2)) + d + (r2 * test(pmask, 1) + d + d) - (i == n ? d : 0)) {
                minimize(dp[i][pmask | MASK12][0], dp[i - 1][pmask][1] + r3 * (a[i] + test(pmask, 2)) + d + (r2 * test(pmask, 1) + d + d) - (i == n ? d : 0));
                

            }
            if (dp[i][pmask | MASK02][0] > dp[i - 1][pmask][0] + r1 * (a[i] - 1 + test(pmask, 0)) + r3 * test(pmask, 2) + d) {
                minimize(dp[i][pmask | MASK02][0], dp[i - 1][pmask][0] + r1 * (a[i] - 1 + test(pmask, 0)) + r3 * test(pmask, 2) + d);
                

            }
            if (dp[i][pmask | MASK02][0] > dp[i - 1][pmask][1] + r1 * (a[i] - 1 + test(pmask, 0)) + r3 * test(pmask, 2) + d + (r1 + d + d) - (i == n ? d : 0)) {
                minimize(dp[i][pmask | MASK02][0], dp[i - 1][pmask][1] + r1 * (a[i] - 1 + test(pmask, 0)) + r3 * test(pmask, 2) + d + (r1 + d + d) - (i == n ? d : 0));
                

            }
            if (dp[i][pmask | MASK012][0] > dp[i - 1][pmask][1] + r1 * (a[i] - 1 + test(pmask, 0)) + r3 * test(pmask, 2) + d + (r2 * test(pmask, 1) + d + d) - (i == n ? d : 0)) {
                minimize(dp[i][pmask | MASK012][0], dp[i - 1][pmask][1] + r1 * (a[i] - 1 + test(pmask, 0)) + r3 * test(pmask, 2) + d + (r2 * test(pmask, 1) + d + d) - (i == n ? d : 0));
                

            }
            if (dp[i][pmask | MASK02][0] > dp[i - 1][pmask][1] + r1 * (a[i] - 1 + test(pmask, 0)) + r3 * test(pmask, 2) + d + (r3 + d + d) - (i == n ? d : 0)) {
                minimize(dp[i][pmask | MASK02][0], dp[i - 1][pmask][1] + r1 * (a[i] - 1 + test(pmask, 0)) + r3 * test(pmask, 2) + d + (r3 + d + d) - (i == n ? d : 0));
                

            }
            if (dp[i][pmask | MASK1][1] > dp[i - 1][pmask][0] + r2 * test(pmask, 1) + d + (i == n ? d + d : 0)) {
                minimize(dp[i][pmask | MASK1][1], dp[i - 1][pmask][0] + r2 * test(pmask, 1) + d + (i == n ? d + d : 0));
                

            }
            if (dp[i][pmask | MASK01][0] > dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r1 * test(pmask, 0) + d + d + r1)) {
                minimize(dp[i][pmask | MASK01][0], dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r1 * test(pmask, 0) + d + d + r1));
                

            }
            if (dp[i][pmask | MASK01][0] > dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r1 * test(pmask, 0) + d + d + r2)) {
                minimize(dp[i][pmask | MASK01][0], dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r1 * test(pmask, 0) + d + d + r2));
                

            }
            if (dp[i][pmask | MASK012][0] > dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r1 * test(pmask, 0) + d + d + r3 * test(pmask, 2))) {
                minimize(dp[i][pmask | MASK012][0], dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r1 * test(pmask, 0) + d + d + r3 * test(pmask, 2)));
                

            }
            if (dp[i][pmask | MASK01][0] > dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r2 + d + d) + r1 * test(pmask, 0)) {
                minimize(dp[i][pmask | MASK01][0], dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r2 + d + d) + r1 * test(pmask, 0));
                

            }
            if (dp[i][pmask | MASK1][0] > dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r2 + d + d) + r2) {
                minimize(dp[i][pmask | MASK1][0], dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r2 + d + d) + r2);
                

            }
            if (dp[i][pmask | MASK12][0] > dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r2 + d + d) + r3 * test(pmask, 2)) {
                minimize(dp[i][pmask | MASK12][0], dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r2 + d + d) + r3 * test(pmask, 2));
                

            }
            if (dp[i][pmask | MASK012][0] > dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r3 * test(pmask, 2) + d + d + r1 * test(pmask, 0))) {
                minimize(dp[i][pmask | MASK012][0], dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r3 * test(pmask, 2) + d + d + r1 * test(pmask, 0)));
                

            }
            if (dp[i][pmask | MASK12][0] > dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r3 * test(pmask, 2) + d + d + r2)) {
                minimize(dp[i][pmask | MASK12][0], dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r3 * test(pmask, 2) + d + d + r2));
                

            }
            if (dp[i][pmask | MASK12][0] > dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r3 * test(pmask, 2) + d + d + r3)) {
                minimize(dp[i][pmask | MASK12][0], dp[i - 1][pmask][1] + r2 * test(pmask, 1) + d + (r3 * test(pmask, 2) + d + d + r3));
                

            }
            if (dp[i][pmask | MASK0][1] > dp[i - 1][pmask][0] + r1 * (a[i] + test(pmask, 0)) + d + (i == n ? d + d : 0)) {
                minimize(dp[i][pmask | MASK0][1], dp[i - 1][pmask][0] + r1 * (a[i] + test(pmask, 0)) + d + (i == n ? d + d : 0));
            }
            if (dp[i][pmask | MASK0][0] > dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r1 + r1 + d + d)) {
                minimize(dp[i][pmask | MASK0][0], dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r1 + r1 + d + d));
            }
            if (dp[i][pmask | MASK01][0] > dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r1 + r2 * test(pmask, 1) + d + d)) {
                minimize(dp[i][pmask | MASK01][0], dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r1 + r2 * test(pmask, 1) + d + d));
            }
            if (dp[i][pmask | MASK02][0] > dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r1 + r3 * test(pmask, 2) + d + d)) {
                minimize(dp[i][pmask | MASK02][0], dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r1 + r3 * test(pmask, 2) + d + d));
            }
            if (dp[i][pmask | MASK01][0] > dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r2 * test(pmask, 1) + r1 + d + d)) {
                minimize(dp[i][pmask | MASK01][0], dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r2 * test(pmask, 1) + r1 + d + d));
            }
            if (dp[i][pmask | MASK01][0] > dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r2 * test(pmask, 1) + r2 + d + d)) {
                minimize(dp[i][pmask | MASK01][0], dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r2 * test(pmask, 1) + r2 + d + d));
            }
            if (dp[i][pmask | MASK012][0] > dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r2 * test(pmask, 1) + r3 * test(pmask, 2) + d + d)) {
                minimize(dp[i][pmask | MASK012][0], dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r2 * test(pmask, 1) + r3 * test(pmask, 2) + d + d));
            }
            if (dp[i][pmask | MASK02][0] > dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r3 * test(pmask, 2) + r1 + d + d)) {
                minimize(dp[i][pmask | MASK02][0], dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r3 * test(pmask, 2) + r1 + d + d));
            }
            if (dp[i][pmask | MASK012][0] > dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r3 * test(pmask, 2) + r2 * test(pmask, 1) + d + d)) {
                minimize(dp[i][pmask | MASK012][0], dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r3 * test(pmask, 2) + r2 * test(pmask, 1) + d + d));
            }
            if (dp[i][pmask | MASK02][0] > dp[i - 1][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r3 * test(pmask, 2) + r3 + d + d)) {
                minimize(dp[i][pmask | MASK02][0], dp[i -1 ][pmask][1] + r1 * (a[i] + test(pmask, 0)) + d + (r3 * test(pmask, 2) + r3 + d + d));
            }
            if (dp[i][pmask | MASK02][1] > dp[i - 1][pmask][0] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (i == n ? d + d : 0)) {
                minimize(dp[i][pmask | MASK02][1], dp[i - 1][pmask][0] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (i == n ? d + d : 0));
            }
            if (dp[i][pmask | MASK02][0] > dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r1 + r1 + d + d)) {
                minimize(dp[i][pmask | MASK02][0], dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r1 + r1 + d + d));
            }
            if (dp[i][pmask | MASK012][0] > dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r1 + r2 * test(pmask, 1) + d + d)) {
                minimize(dp[i][pmask | MASK012][0], dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r1 + r2 * test(pmask, 1) + d + d));
            }
            if (dp[i][pmask | MASK02][0] > dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r1 + r3 + d + d)) {
                minimize(dp[i][pmask | MASK02][0], dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r1 + r3 + d + d));
            }
            if (dp[i][pmask | MASK012][0] > dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r2 * test(pmask, 1) + r1 + d + d)) {
                minimize(dp[i][pmask | MASK012][0], dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r2 * test(pmask, 1) + r1 + d + d));
            }
            if (dp[i][pmask | MASK012][0] > dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r2 * test(pmask, 1) + r2 + d + d)) {
                minimize(dp[i][pmask | MASK012][0], dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r2 * test(pmask, 1) + r2 + d + d));
            }
            if (dp[i][pmask | MASK012][0] > dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r2 * test(pmask, 1) + r3 + d + d)) {
                minimize(dp[i][pmask | MASK012][0], dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r2 * test(pmask, 1) + r3 + d + d));
            }
            if (dp[i][pmask | MASK02][0] > dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r3 + r1 + d + d)) {
                minimize(dp[i][pmask | MASK02][0], dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r3 + r1 + d + d));
            }
            if (dp[i][pmask | MASK012][0] > dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r3 + r2 * test(pmask, 1) + d + d)) {
                minimize(dp[i][pmask | MASK012][0], dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r3 + r2 * test(pmask, 1) + d + d));
            }
            if (dp[i][pmask | MASK02][0] > dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r3 + r3 + d + d)) {
                minimize(dp[i][pmask | MASK02][0], dp[i - 1][pmask][1] + r3 * (a[i] - 1 + test(pmask, 2)) + r1 * test(pmask, 0) + d + (r3 + r3 + d + d));
            }
            






            





        }

        
    }

    long long ans = 1e18;
    int pos = n, finmask = 0, type = 0;
    for (int mask = 0; mask < 8; mask++) {
        if (ans > dp[n][mask][0]) {
            ans = dp[n][mask][0];
            pos = n;
            finmask = mask;
            type = 0;
        }
        if (ans > dp[n][mask][1] + min(min(r1 * test(mask, 0), r2 * test(mask, 1)), r3 * test(mask, 2))) {
            ans = dp[n][mask][1] + min(min(r1 * test(mask, 0), r2 * test(mask, 1)), r3 * test(mask, 2));
            pos = n;
            finmask = mask;
            type = 1;
        }
    }

    cout << ans - d << "\n";
    

    

    return 0;
}
