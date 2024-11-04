#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
long long matrix[1005][1005], n, m, k, p;
long long row[1005], col[1005], ans, a[2000005], b[2000005];


void solve() {
    ans = -999999999999999999;
    priority_queue<long long> rowq, colq;
    for (int i = 0; i < n; i++) {
        rowq.push(row[i]);
    }

    for (int i = 0; i < m; i++) {
        colq.push(col[i]);
    }



    for (int i = 1; i <= k; i++) {
        long long x = rowq.top();
        rowq.pop();
        long long y = colq.top();
        colq.pop();
        a[i] = a[i - 1] + x;
        rowq.push(x - p * m);
        b[i] = b[i - 1] + y;
        colq.push(y - p * n);
    }

    for (int i = 0; i <= k; i++) {
        long long diff = a[i] + b[k - i] - p * (k - i) * i ;
        ans = max(ans, diff);
    }
    printf("%I64d", ans);
}

int main() {
    cin >> n >> m >> k >> p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%I64d", &matrix[i][j]);
            row[i] += matrix[i][j];
            col[j] += matrix[i][j];
        }
    }

    solve();
    return 0;
}





























