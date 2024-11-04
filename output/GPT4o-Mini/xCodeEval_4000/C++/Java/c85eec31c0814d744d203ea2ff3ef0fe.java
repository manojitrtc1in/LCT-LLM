import java.util.*;
import java.io.*;

public class c85eec31c0814d744d203ea2ff3ef0fe_nc {
    static final long MOD = 1000000007;
    static long[] pos, w;

    static class TreeSegment<Value, Mod> {
        class Node {
            boolean have_mod = false;
            Value value;
            Mod mod;
        }

        private Node[] S;
        private int n;
        private BiFunction<Value, Value, Value> magic;
        private BiFunction<Value, Mod, Value> apply_mod;
        private BiFunction<Mod, Mod, Mod> merge_mods;

        public TreeSegment(int n, Value def, BiFunction<Value, Value, Value> magic,
                           BiFunction<Value, Mod, Value> apply_mod, BiFunction<Mod, Mod, Mod> merge_mods) {
            this.magic = magic;
            this.apply_mod = apply_mod;
            this.merge_mods = merge_mods;
            init(new Value[n]);
        }

        public TreeSegment(Value[] def, BiFunction<Value, Value, Value> magic,
                           BiFunction<Value, Mod, Value> apply_mod, BiFunction<Mod, Mod, Mod> merge_mods) {
            this.magic = magic;
            this.apply_mod = apply_mod;
            this.merge_mods = merge_mods;
            init(def);
        }

        private void init(Value[] src) {
            n = src.length;
            S = new Node[2 * n + 1];
            for (int i = 0; i < S.length; i++) {
                S[i] = new Node();
            }
            init(0, 0, n, src);
        }

        private void init(int i, int tl, int tr, Value[] src) {
            if (tl + 1 == tr) {
                S[i].value = src[tl];
            } else {
                int mid = (tl + tr) / 2;
                init(i + 1, tl, mid, src);
                init(i + (mid - tl) * 2, mid, tr, src);
                recalc_value(i, tl, tr);
            }
        }

        private void recalc_value(int i, int tl, int tr) {
            if (tl + 1 != tr) {
                int mid = (tl + tr) / 2;
                S[i].value = magic.apply(get_value(i + 1, tl, mid), get_value(i + (mid - tl) * 2, mid, tr));
            }
        }

        private Value get_value(int i, int tl, int tr) {
            if (!S[i].have_mod) return S[i].value;
            return apply_mod.apply(S[i].value, S[i].mod);
        }

        public Value query(int ql, int qr) {
            assert ql < qr;
            return __query(0, 0, n, ql, qr);
        }

        private Value __query(int i, int tl, int tr, int ql, int qr) {
            push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                return S[i].value;
            } else {
                int mid = (tl + tr) / 2;
                if (intersects(tl, mid, ql, qr) && intersects(mid, tr, ql, qr)) {
                    return magic.apply(__query(i + 1, tl, mid, ql, qr), __query(i + (mid - tl) * 2, mid, tr, ql, qr));
                } else if (intersects(tl, mid, ql, qr)) {
                    return __query(i + 1, tl, mid, ql, qr);
                } else {
                    return __query(i + (mid - tl) * 2, mid, tr, ql, qr);
                }
            }
        }

        private boolean intersects(int tl, int tr, int ql, int qr) {
            return !(tr <= ql || qr <= tl);
        }

        private void push(int i, int tl, int tr) {
            if (S[i].have_mod) {
                S[i].value = apply_mod.apply(S[i].value, S[i].mod);
                if (tl + 1 != tr) {
                    int mid = (tl + tr) / 2;
                    add_mod(i + 1, tl, mid, S[i].mod);
                    add_mod(i + (mid - tl) * 2, mid, tr, S[i].mod);
                }
                S[i].have_mod = false;
            }
        }

        private void add_mod(int i, int tl, int tr, Mod sub) {
            if (S[i].have_mod) {
                S[i].mod = merge_mods.apply(S[i].mod, sub);
            } else {
                S[i].mod = sub;
                S[i].have_mod = true;
            }
        }

        public void update(int ql, int qr, Mod mod) {
            __update(0, 0, n, ql, qr, mod);
        }

        private void __update(int i, int tl, int tr, int ql, int qr, Mod mod) {
            push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                add_mod(i, tl, tr, mod);
            } else {
                int mid = (tl + tr) / 2;
                if (intersects(tl, mid, ql, qr)) {
                    __update(i + 1, tl, mid, ql, qr, mod);
                }
                if (intersects(mid, tr, ql, qr)) {
                    __update(i + (mid - tl) * 2, mid, tr, ql, qr, mod);
                }
                recalc_value(i, tl, tr);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long q = scanner.nextLong();
        pos = new long[(int) n];
        w = new long[(int) n];
        for (int i = 0; i < n; i++) {
            pos[i] = scanner.nextLong();
        }
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextLong();
        }

        TreeSegment<Long, Long> ts = new TreeSegment<>(w, Long::sum,
                (value, mod) -> mod,
                (old, _new) -> _new);

        long[] subw = new long[(int) n];
        for (int i = 0; i < n; i++) {
            subw[i] = (w[i] * (i - pos[i])) % MOD;
        }

        TreeSegment<Long, Long> resp = new TreeSegment<>(subw, Long::sum,
                (value, mod) -> mod,
                (old, _new) -> _new);

        for (int i = 0; i < q; i++) {
            long x = scanner.nextLong();
            long y = scanner.nextLong();
            if (x < 0) {
                int ind = (int) -x - 1;
                long _new = y;
                ts.update(ind, ind + 1, _new);
                resp.update(ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
            } else {
                int l = (int) x - 1;
                int r = (int) y;

                long sm = ts.query(l, r);

                int bestL = ts.find_right(l, x1 -> x1 * 2 >= sm, 0);

                long x_val = pos[bestL] - bestL + l;

                long left = 0;
                if (l < bestL) {
                    left = (resp.query(l, bestL) + ts.query(l, bestL) * (x_val - l)) % MOD;
                }
                long right = 0;
                if (bestL < r) {
                    right = (resp.query(bestL, r) + ts.query(bestL, r) * (x_val - l)) % MOD;
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
