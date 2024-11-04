import java.util.*;
import java.io.*;

class SegmentTree {
    final long inf = (long) 1e18;
    int n, n0;
    long[] max_v, smax_v, max_c;
    long[] min_v, smin_v, min_c;
    long[] sum;
    long[] len, ladd, lval;

    void update_node_max(int k, long x) {
        sum[k] += (x - max_v[k]) * max_c[k];

        if (max_v[k] == min_v[k]) {
            max_v[k] = min_v[k] = x;
        } else if (max_v[k] == smin_v[k]) {
            max_v[k] = smin_v[k] = x;
        } else {
            max_v[k] = x;
        }

        if (lval[k] != inf && x < lval[k]) {
            lval[k] = x;
        }
    }

    void update_node_min(int k, long x) {
        sum[k] += (x - min_v[k]) * min_c[k];

        if (max_v[k] == min_v[k]) {
            max_v[k] = min_v[k] = x;
        } else if (smax_v[k] == min_v[k]) {
            min_v[k] = smax_v[k] = x;
        } else {
            min_v[k] = x;
        }

        if (lval[k] != inf && lval[k] < x) {
            lval[k] = x;
        }
    }

    void push(int k) {
        if (n0 - 1 <= k) return;

        if (lval[k] != inf) {
            updateall(2 * k + 1, lval[k]);
            updateall(2 * k + 2, lval[k]);
            lval[k] = inf;
            return;
        }

        if (ladd[k] != 0) {
            addall(2 * k + 1, ladd[k]);
            addall(2 * k + 2, ladd[k]);
            ladd[k] = 0;
        }

        if (max_v[k] < max_v[2 * k + 1]) {
            update_node_max(2 * k + 1, max_v[k]);
        }
        if (min_v[2 * k + 1] < min_v[k]) {
            update_node_min(2 * k + 1, min_v[k]);
        }

        if (max_v[k] < max_v[2 * k + 2]) {
            update_node_max(2 * k + 2, max_v[k]);
        }
        if (min_v[2 * k + 2] < min_v[k]) {
            update_node_min(2 * k + 2, min_v[k]);
        }
    }

    void update(int k) {
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

    void _update_min(long x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a || max_v[k] <= x) return;
        if (a <= l && r <= b && smax_v[k] < x) {
            update_node_max(k, x);
            return;
        }

        push(k);
        _update_min(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_min(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _update_max(long x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a || x <= min_v[k]) return;
        if (a <= l && r <= b && x < smin_v[k]) {
            update_node_min(k, x);
            return;
        }

        push(k);
        _update_max(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_max(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void addall(int k, long x) {
        max_v[k] += x;
        if (smax_v[k] != -inf) smax_v[k] += x;
        min_v[k] += x;
        if (smin_v[k] != inf) smin_v[k] += x;

        sum[k] += len[k] * x;
        if (lval[k] != inf) {
            lval[k] += x;
        } else {
            ladd[k] += x;
        }
    }

    void updateall(int k, long x) {
        max_v[k] = x;
        smax_v[k] = -inf;
        min_v[k] = x;
        smin_v[k] = inf;
        max_c[k] = min_c[k] = len[k];

        sum[k] = x * len[k];
        lval[k] = x;
        ladd[k] = 0;
    }

    void _add_val(long x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            addall(k, x);
            return;
        }

        push(k);
        _add_val(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _add_val(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _update_val(long x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            updateall(k, x);
            return;
        }

        push(k);
        _update_val(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_val(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    long _query_max(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return -inf;
        if (a <= l && r <= b) return max_v[k];
        push(k);
        long lv = _query_max(a, b, 2 * k + 1, l, (l + r) / 2);
        long rv = _query_max(a, b, 2 * k + 2, (l + r) / 2, r);
        return Math.max(lv, rv);
    }

    long _query_min(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return inf;
        if (a <= l && r <= b) return min_v[k];
        push(k);
        long lv = _query_min(a, b, 2 * k + 1, l, (l + r) / 2);
        long rv = _query_min(a, b, 2 * k + 2, (l + r) / 2, r);
        return Math.min(lv, rv);
    }

    long _query_sum(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) return sum[k];
        push(k);
        long lv = _query_sum(a, b, 2 * k + 1, l, (l + r) / 2);
        long rv = _query_sum(a, b, 2 * k + 2, (l + r) / 2, r);
        return lv + rv;
    }

    public SegmentTree(int n) {
        this(n, null);
    }

    public SegmentTree(int n, long[] a) {
        this.n = n;
        n0 = 1;
        while (n0 < n) n0 <<= 1;

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

        Arrays.fill(ladd, 0);
        Arrays.fill(lval, inf);
        len[0] = n0;
        for (int i = 0; i < n0 - 1; ++i) len[2 * i + 1] = len[2 * i + 2] = (len[i] >> 1);

        for (int i = 0; i < n; ++i) {
            max_v[n0 - 1 + i] = min_v[n0 - 1 + i] = sum[n0 - 1 + i] = (a != null ? a[i] : 0);
            smax_v[n0 - 1 + i] = -inf;
            smin_v[n0 - 1 + i] = inf;
            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 1;
        }

        for (int i = n; i < n0; ++i) {
            max_v[n0 - 1 + i] = smax_v[n0 - 1 + i] = -inf;
            min_v[n0 - 1 + i] = smin_v[n0 - 1 + i] = inf;
            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 0;
        }
        for (int i = n0 - 2; i >= 0; i--) {
            update(i);
        }
    }

    void update_min(int a, int b, long x) {
        _update_min(x, a, b, 0, 0, n0);
    }

    void update_max(int a, int b, long x) {
        _update_max(x, a, b, 0, 0, n0);
    }

    void add_val(int a, int b, long x) {
        _add_val(x, a, b, 0, 0, n0);
    }

    void update_val(int a, int b, long x) {
        _update_val(x, a, b, 0, 0, n0);
    }

    long query_max(int a, int b) {
        return _query_max(a, b, 0, 0, n0);
    }

    long query_min(int a, int b) {
        return _query_min(a, b, 0, 0, n0);
    }

    long query_sum(int a, int b) {
        return _query_sum(a, b, 0, 0, n0);
    }
}

public class e45716e40e776874cf5682e36c6dffb5_nc {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        long[] v = new long[n];
        for (int i = 0; i < n; i++) {
            v[i] = i - 1;
        }
        SegmentTree seg = new SegmentTree(n, v);

        List<List<Long>> d = new ArrayList<>(200001);
        for (int i = 0; i < 200001; i++) {
            d.add(new ArrayList<>());
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j * j <= a[i]; j++) {
                if (a[i] % j == 0) {
                    d.get(j).add((long) i);
                    if (a[i] != j * j) d.get(a[i] / j).add((long) i);
                }
            }
        }

        long ans = 0;
        for (int i = 200000; i >= 1; i--) {
            List<Long> w = d.get(i);
            if (w.size() <= 1) continue;

            List<Integer> s = new ArrayList<>();
            s.add(w.get(0).intValue());
            s.add(w.get(1).intValue());
            s.add(w.get(w.size() - 2).intValue());
            s.add(w.get(w.size() - 1).intValue());

            long pre = seg.query_sum(0, n);
            seg.update_max(w.get(0).intValue() + 1, w.get(w.size() - 1).intValue());
            seg.update_max(0, w.get(w.size() - 2).intValue());
            seg.update_max(w.get(1).intValue() + 1, n);
            ans += (seg.query_sum(0, n) - pre) * i;
        }
        System.out.println(ans);
    }
}
