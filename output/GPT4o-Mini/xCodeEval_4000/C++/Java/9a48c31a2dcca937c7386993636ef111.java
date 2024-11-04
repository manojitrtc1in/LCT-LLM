import java.util.*;
import java.io.*;

public class 9a48c31a2dcca937c7386993636ef111_nc {
    static final long MOD = 1000000007;
    static int n, q;
    static int[] pos;
    static int[] w;

    static class TreeSegment<Value, Mod, Magic, ApplyMod, MergeMods> {
        static class Node {
            boolean have_mod = false;
            long value;
            long mod;
        }

        Magic magic;
        ApplyMod apply_mod;
        MergeMods merge_mods;
        Node[] S;
        int n;

        public TreeSegment(int n, long def, Magic magic, ApplyMod apply_mod, MergeMods merge_mods) {
            this.magic = magic;
            this.apply_mod = apply_mod;
            this.merge_mods = merge_mods;
            init(new long[n], def);
        }

        public TreeSegment(long[] def, Magic magic, ApplyMod apply_mod, MergeMods merge_mods) {
            this.magic = magic;
            this.apply_mod = apply_mod;
            this.merge_mods = merge_mods;
            init(def);
        }

        void init(long[] src) {
            n = src.length;
            S = new Node[4 * n];
            for (int i = 0; i < S.length; i++) {
                S[i] = new Node();
            }
            build(0, 0, n, src);
        }

        void build(int i, int tl, int tr, long[] src) {
            if (tl + 1 == tr) {
                S[i].value = src[tl];
            } else {
                int mid = (tl + tr) / 2;
                build(i * 2 + 1, tl, mid, src);
                build(i * 2 + 2, mid, tr, src);
                recalc_value(i, tl, tr);
            }
        }

        void recalc_value(int i, int tl, int tr) {
            if (tl + 1 != tr) {
                int mid = (tl + tr) / 2;
                S[i].value = magic.apply(S[i * 2 + 1].value, S[i * 2 + 2].value);
            }
        }

        void update(int ql, int qr, long mod) {
            update(0, 0, n, ql, qr, mod);
        }

        void update(int i, int tl, int tr, int ql, int qr, long mod) {
            if (ql <= tl && tr <= qr) {
                add_mod(i, tl, tr, mod);
            } else {
                int mid = (tl + tr) / 2;
                if (ql < mid) update(i * 2 + 1, tl, mid, ql, qr, mod);
                if (mid < qr) update(i * 2 + 2, mid, tr, ql, qr, mod);
                recalc_value(i, tl, tr);
            }
        }

        void add_mod(int i, int tl, int tr, long sub) {
            if (S[i].have_mod) {
                S[i].mod = merge_mods.merge(S[i].mod, sub, tl, tr);
            } else {
                S[i].mod = sub;
                S[i].have_mod = true;
            }
        }

        long query(int ql, int qr) {
            return query(0, 0, n, ql, qr);
        }

        long query(int i, int tl, int tr, int ql, int qr) {
            if (ql <= tl && tr <= qr) {
                return S[i].value;
            } else {
                int mid = (tl + tr) / 2;
                long res = 0;
                if (ql < mid) res += query(i * 2 + 1, tl, mid, ql, qr);
                if (mid < qr) res += query(i * 2 + 2, mid, tr, ql, qr);
                return res;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());
        pos = new int[n];
        w = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            pos[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            w[i] = Integer.parseInt(st.nextToken());
        }

        TreeSegment<Long, Long, BiFunction<Long, Long, Long>, BiFunction<Long, Long, Long>, BiFunction<Long, Long, Long>> ts =
                new TreeSegment<>(w, (a, b) -> a + b, (value, mod) -> mod, (old, _new) -> _new);

        long[] subw = new long[n];
        for (int i = 0; i < n; i++) {
            subw[i] = (w[i] * (i - pos[i])) % MOD;
        }

        TreeSegment<Long, Long, BiFunction<Long, Long, Long>, BiFunction<Long, Long, Long>, BiFunction<Long, Long, Long>> resp =
                new TreeSegment<>(subw, (a, b) -> (a + b) % MOD, (value, mod) -> mod, (old, _new) -> _new);

        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            if (x < 0) {
                int ind = -x - 1;
                long _new = y;
                ts.update(ind, ind + 1, _new);
                resp.update(ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
            } else {
                int l = x - 1, r = y;
                long sm = ts.query(l, r);
                int bestL = ts.find_right(l, sm);
                int xValue = pos[bestL] - bestL + l;

                long left = 0;
                if (l < bestL) {
                    left = (resp.query(l, bestL) + ts.query(l, bestL) * (xValue - l)) % MOD;
                }
                long right = 0;
                if (bestL < r) {
                    right = (resp.query(bestL, r) + ts.query(bestL, r) * (xValue - l)) % MOD;
                }
                System.out.println(floor_mod(left - right, MOD));
            }
        }
    }

    static long floor_mod(long a, long b) {
        if (a % b == 0) return 0;
        if (a >= 0 && b >= 0) return a % b;
        if (a <= 0 && b <= 0) return a % b;
        return Math.abs(b) - (Math.abs(a) % Math.abs(b));
    }
}
