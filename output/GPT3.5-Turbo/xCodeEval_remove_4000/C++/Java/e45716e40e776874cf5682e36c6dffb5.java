import java.util.*;

class Main {
    static class SegmentTree {
        private static final long INF = (long) 1e18;
        private int n, n0;
        private long[] max_v, smax_v, max_c;
        private long[] min_v, smin_v, min_c;
        private long[] sum;
        private long[] len, ladd, lval;

        public SegmentTree(int n) {
            this.n = n;
            this.n0 = 1;
            while (n0 < n) {
                n0 <<= 1;
            }

            max_v = new long[4 * n0];
            smax_v = new long[4 * n0];
            max_c = new long[4 * n0];
            min_v = new long[4 * n0];
            smin_v = new long[4 * n0];
            min_c = new long[4 * n0];
            sum = new long[4 * n0];
            len = new long[4 * n0];
            ladd = new long[4 * n0];
            lval = new long[4 * n0];

            len[0] = n0;
            for (int i = 0; i < n0 - 1; ++i) {
                len[2 * i + 1] = len[2 * i + 2] = (len[i] >> 1);
            }

            for (int i = 0; i < n; ++i) {
                max_v[n0 - 1 + i] = min_v[n0 - 1 + i] = sum[n0 - 1 + i] = 0;
                smax_v[n0 - 1 + i] = -INF;
                smin_v[n0 - 1 + i] = INF;
                max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 1;
            }

            for (int i = n; i < n0; ++i) {
                max_v[n0 - 1 + i] = smax_v[n0 - 1 + i] = -INF;
                min_v[n0 - 1 + i] = smin_v[n0 - 1 + i] = INF;
                max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 0;
            }
            for (int i = n0 - 2; i >= 0; i--) {
                update(i);
            }
        }

        private void updateNodeMax(int k, long x) {
            sum[k] += (x - max_v[k]) * max_c[k];

            if (max_v[k] == min_v[k]) {
                max_v[k] = min_v[k] = x;
            } else if (max_v[k] == smin_v[k]) {
                max_v[k] = smin_v[k] = x;
            } else {
                max_v[k] = x;
            }

            if (lval[k] != INF && x < lval[k]) {
                lval[k] = x;
            }
        }

        private void updateNodeMin(int k, long x) {
            sum[k] += (x - min_v[k]) * min_c[k];

            if (max_v[k] == min_v[k]) {
                max_v[k] = min_v[k] = x;
            } else if (smax_v[k] == min_v[k]) {
                min_v[k] = smax_v[k] = x;
            } else {
                min_v[k] = x;
            }

            if (lval[k] != INF && lval[k] < x) {
                lval[k] = x;
            }
        }

        private void push(int k) {
            if (n0 - 1 <= k) {
                return;
            }

            if (lval[k] != INF) {
                updateAll(2 * k + 1, lval[k]);
                updateAll(2 * k + 2, lval[k]);
                lval[k] = INF;
                return;
            }

            if (ladd[k] != 0) {
                addAll(2 * k + 1, ladd[k]);
                addAll(2 * k + 2, ladd[k]);
                ladd[k] = 0;
            }

            if (max_v[k] < max_v[2 * k + 1]) {
                updateNodeMax(2 * k + 1, max_v[k]);
            }
            if (min_v[2 * k + 1] < min_v[k]) {
                updateNodeMin(2 * k + 1, min_v[k]);
            }

            if (max_v[k] < max_v[2 * k + 2]) {
                updateNodeMax(2 * k + 2, max_v[k]);
            }
            if (min_v[2 * k + 2] < min_v[k]) {
                updateNodeMin(2 * k + 2, min_v[k]);
            }
        }

        private void update(int k) {
            sum[k] = sum[2 * k + 1] + sum[2 * k + 2];

            if (max_v[2 * k + 1] < max_v[2 * k + 2]) {
                max_v[k] = max_v[2 * k + 2];
                max_c[k] = max_c[2 * k + 2];
                smax_v[k] = Math.max(max_v[2 * k + 1], smax_v[2 * k + 2]);
            } else if (max_v[2 * k + 1] > max_v[2 * k + 2]) {
                max_v[k] = max_v[2 * k + 1];
                max_c[k] = max_c[2 * k + 1];
                smax_v[k] = Math.max(smax_v[2 * k + 1], max_v[2 * k + 2]);
            } else {
                max_v[k] = max_v[2 * k + 1];
                max_c[k] = max_c[2 * k + 1] + max_c[2 * k + 2];
                smax_v[k] = Math.max(smax_v[2 * k + 1], smax_v[2 * k + 2]);
            }

            if (min_v[2 * k + 1] < min_v[2 * k + 2]) {
                min_v[k] = min_v[2 * k + 1];
                min_c[k] = min_c[2 * k + 1];
                smin_v[k] = Math.min(smin_v[2 * k + 1], min_v[2 * k + 2]);
            } else if (min_v[2 * k + 1] > min_v[2 * k + 2]) {
                min_v[k] = min_v[2 * k + 2];
                min_c[k] = min_c[2 * k + 2];
                smin_v[k] = Math.min(min_v[2 * k + 1], smin_v[2 * k + 2]);
            } else {
                min_v[k] = min_v[2 * k + 1];
                min_c[k] = min_c[2 * k + 1] + min_c[2 * k + 2];
                smin_v[k] = Math.min(smin_v[2 * k + 1], smin_v[2 * k + 2]);
            }
        }

        private void updateAll(int k, long x) {
            max_v[k] += x;
            if (smax_v[k] != -INF) {
                smax_v[k] += x;
            }
            min_v[k] += x;
            if (smin_v[k] != INF) {
                smin_v[k] += x;
            }

            sum[k] += len[k] * x;
            if (lval[k] != INF) {
                lval[k] += x;
            } else {
                ladd[k] += x;
            }
        }

        private void updateAll(int k, long x) {
            max_v[k] = x;
            smax_v[k] = -INF;
            min_v[k] = x;
            smin_v[k] = INF;
            max_c[k] = min_c[k] = len[k];

            sum[k] = x * len[k];
            lval[k] = x;
            ladd[k] = 0;
        }

        public void updateMin(int a, int b, long x) {
            _updateMin(x, a, b, 0, 0, n0);
        }

        private void _updateMin(long x, int a, int b, int k, int l, int r) {
            if (b <= l || r <= a || max_v[k] <= x) {
                return;
            }
            if (a <= l && r <= b && smax_v[k] < x) {
                updateNodeMax(k, x);
                return;
            }

            push(k);
            _updateMin(x, a, b, 2 * k + 1, l, (l + r) / 2);
            _updateMin(x, a, b, 2 * k + 2, (l + r) / 2, r);
            update(k);
        }

        public void updateMax(int a, int b, long x) {
            _updateMax(x, a, b, 0, 0, n0);
        }

        private void _updateMax(long x, int a, int b, int k, int l, int r) {
            if (b <= l || r <= a || x <= min_v[k]) {
                return;
            }
            if (a <= l && r <= b && x < smin_v[k]) {
                updateNodeMin(k, x);
                return;
            }

            push(k);
            _updateMax(x, a, b, 2 * k + 1, l, (l + r) / 2);
            _updateMax(x, a, b, 2 * k + 2, (l + r) / 2, r);
            update(k);
        }

        public void addVal(int a, int b, long x) {
            _addVal(x, a, b, 0, 0, n0);
        }

        private void _addVal(long x, int a, int b, int k, int l, int r) {
            if (b <= l || r <= a) {
                return;
            }
            if (a <= l && r <= b) {
                addAll(k, x);
                return;
            }

            push(k);
            _addVal(x, a, b, 2 * k + 1, l, (l + r) / 2);
            _addVal(x, a, b, 2 * k + 2, (l + r) / 2, r);
            update(k);
        }

        public void updateVal(int a, int b, long x) {
            _updateVal(x, a, b, 0, 0, n0);
        }

        private void _updateVal(long x, int a, int b, int k, int l, int r) {
            if (b <= l || r <= a) {
                return;
            }
            if (a <= l && r <= b) {
                updateAll(k, x);
                return;
            }

            push(k);
            _updateVal(x, a, b, 2 * k + 1, l, (l + r) / 2);
            _updateVal(x, a, b, 2 * k + 2, (l + r) / 2, r);
            update(k);
        }

        public long queryMax(int a, int b) {
            return _queryMax(a, b, 0, 0, n0);
        }

        private long _queryMax(int a, int b, int k, int l, int r) {
            if (b <= l || r <= a) {
                return -INF;
            }
            if (a <= l && r <= b) {
                return max_v[k];
            }
            push(k);
            long lv = _queryMax(a, b, 2 * k + 1, l, (l + r) / 2);
            long rv = _queryMax(a, b, 2 * k + 2, (l + r) / 2, r);
            return Math.max(lv, rv);
        }

        public long queryMin(int a, int b) {
            return _queryMin(a, b, 0, 0, n0);
        }

        private long _queryMin(int a, int b, int k, int l, int r) {
            if (b <= l || r <= a) {
                return INF;
            }
            if (a <= l && r <= b) {
                return min_v[k];
            }
            push(k);
            long lv = _queryMin(a, b, 2 * k + 1, l, (l + r) / 2);
            long rv = _queryMin(a, b, 2 * k + 2, (l + r) / 2, r);
            return Math.min(lv, rv);
        }

        public long querySum(int a, int b) {
            return _querySum(a, b, 0, 0, n0);
        }

        private long _querySum(int a, int b, int k, int l, int r) {
            if (b <= l || r <= a) {
                return 0;
            }
            if (a <= l && r <= b) {
                return sum[k];
            }
            push(k);
            long lv = _querySum(a, b, 2 * k + 1, l, (l + r) / 2);
            long rv = _querySum(a, b, 2 * k + 2, (l + r) / 2, r);
            return lv + rv;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        SegmentTree seg = new SegmentTree(n);
        List<List<Integer>> d = new ArrayList<>();
        for (int i = 0; i <= 200000; i++) {
            d.add(new ArrayList<>());
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j * j <= a[i]; j++) {
                if (a[i] % j == 0) {
                    d.get(j).add(i);
                    if (a[i] != j * j) {
                        d.get(a[i] / j).add(i);
                    }
                }
            }
        }

        long ans = 0;
        for (int i = 200000; i >= 1; i--) {
            List<Integer> w = d.get(i);
            if (w.size() <= 1) {
                continue;
            }

            List<Integer> s = new ArrayList<>();
            s.add(w.get(0));
            s.add(w.get(1));
            s.add(w.get(w.size() - 2));
            s.add(w.get(w.size() - 1));

            ans += (seg.querySum(0, n) - seg.querySum(0, n)) * i;
        }

        System.out.println(ans);
    }
}
