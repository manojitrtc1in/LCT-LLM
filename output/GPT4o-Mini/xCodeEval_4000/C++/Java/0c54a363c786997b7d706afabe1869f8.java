import java.util.*;
import java.io.*;

public class 0c54a363c786997b7d706afabe1869f8_nc {
    static final long MOD = 1000000007;

    static class TreeSegment<Value, Mod, Magic, ApplyMod, MergeMods> {
        static class Node<Value, Mod> {
            boolean haveMod = false;
            Value value;
            Mod mod;
        }

        Magic magic;
        ApplyMod applyMod;
        MergeMods mergeMods;
        List<Node<Value, Mod>> S;
        int n;

        public TreeSegment(int n, Value def, Magic magic, ApplyMod applyMod, MergeMods mergeMods) {
            this.magic = magic;
            this.applyMod = applyMod;
            this.mergeMods = mergeMods;
            init(new ArrayList<>(Collections.nCopies(n, def)));
        }

        public TreeSegment(List<Value> def, Magic magic, ApplyMod applyMod, MergeMods mergeMods) {
            this.magic = magic;
            this.applyMod = applyMod;
            this.mergeMods = mergeMods;
            init(def);
        }

        void init(List<Value> src) {
            n = src.size();
            S = new ArrayList<>(Collections.nCopies(2 * n + 1, new Node<>()));
            init(0, 0, n, src);
        }

        void init(int i, int tl, int tr, List<Value> src) {
            if (tl + 1 == tr) {
                S.get(i).value = src.get(tl);
            } else {
                int mid = (tl + tr) / 2;
                init(i + 1, tl, mid, src);
                init(i + (mid - tl) * 2, mid, tr, src);
                recalcValue(i, tl, tr);
            }
        }

        Value query(int ql, int qr) {
            assert ql < qr;
            return __query(0, 0, n, ql, qr);
        }

        void update(int ql, int qr, Mod mod) {
            __update(0, 0, n, ql, qr, mod);
        }

        void __update(int i, int tl, int tr, int ql, int qr, Mod mod) {
            push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                addMod(i, tl, tr, mod);
            } else {
                int mid = (tl + tr) / 2;
                if (intersects(tl, mid, ql, qr)) {
                    __update(i + 1, tl, mid, ql, qr, mod);
                }
                if (intersects(mid, tr, ql, qr)) {
                    __update(i + (mid - tl) * 2, mid, tr, ql, qr, mod);
                }
                recalcValue(i, tl, tr);
            }
        }

        void addMod(int i, int tl, int tr, Mod sub) {
            if (S.get(i).haveMod) {
                S.get(i).mod = mergeMods.merge(S.get(i).mod, sub, tl, tr);
            } else {
                S.get(i).mod = sub;
                S.get(i).haveMod = true;
            }
        }

        void push(int i, int tl, int tr) {
            if (S.get(i).haveMod) {
                S.get(i).value = applyMod.apply(S.get(i).value, S.get(i).mod, tl, tr);
                if (tl + 1 != tr) {
                    int mid = (tl + tr) / 2;
                    addMod(i + 1, tl, mid, S.get(i).mod);
                    addMod(i + (mid - tl) * 2, mid, tr, S.get(i).mod);
                }
                S.get(i).haveMod = false;
            }
        }

        Value __query(int i, int tl, int tr, int ql, int qr) {
            push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                return S.get(i).value;
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

        boolean intersects(int tl, int tr, int ql, int qr) {
            return !(tr <= ql || qr <= tl);
        }

        void recalcValue(int i, int tl, int tr) {
            if (tl + 1 != tr) {
                int mid = (tl + tr) / 2;
                S.get(i).value = magic.apply(
                        __getValue(i + 1, tl, mid),
                        __getValue(i + (mid - tl) * 2, mid, tr)
                );
            }
        }

        Value __getValue(int i, int tl, int tr) {
            if (!S.get(i).haveMod) return S.get(i).value;
            return applyMod.apply(S.get(i).value, S.get(i).mod, tl, tr);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long q = scanner.nextLong();
        List<Long> pos = new ArrayList<>();
        List<Long> w = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            pos.add(scanner.nextLong());
        }
        for (int i = 0; i < n; i++) {
            w.add(scanner.nextLong());
        }

        TreeSegment<Long, Long, BiFunction<Long, Long, Long>, BiFunction<Long, Long, Long>, BiFunction<Long, Long, Long>> ts =
                new TreeSegment<>(w, Long::sum, (value, mod, tl, tr) -> mod, (old, _new, tl, tr) -> _new);

        List<Long> subw = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            subw.add((w.get(i) * (i - pos.get(i))) % MOD);
        }

        TreeSegment<Long, Long, BiFunction<Long, Long, Long>, BiFunction<Long, Long, Long>, BiFunction<Long, Long, Long>> resp =
                new TreeSegment<>(subw, (a, b) -> (a + b) % MOD, (value, mod, tl, tr) -> mod, (old, _new, tl, tr) -> _new);

        for (int i = 0; i < q; i++) {
            long x = scanner.nextLong();
            long y = scanner.nextLong();
            if (x < 0) {
                int ind = (int) -x - 1;
                long _new = y;
                ts.update(ind, ind + 1, _new);
                resp.update(ind, ind + 1, (_new * (ind - pos.get(ind))) % MOD);
            } else {
                int l = (int) x - 1;
                int r = (int) y;

                long sm = ts.query(l, r);

                int bestL = ts.findRight(l, xVal -> xVal * 2 >= sm, 0);

                long xVal = pos.get(bestL) - bestL + l;

                long left = 0;
                if (l < bestL) {
                    left = (resp.query(l, bestL) + ts.query(l, bestL) * (xVal - l)) % MOD;
                }
                long right = 0;
                if (bestL < r) {
                    right = (resp.query(bestL, r) + ts.query(bestL, r) * (xVal - l)) % MOD;
                }

                System.out.println(floorMod(left - right, MOD));
            }
        }
    }

    static long floorMod(long a, long b) {
        if (a % b == 0) return 0;
        if (a >= 0 && b >= 0) return a % b;
        if (a <= 0 && b <= 0) return a % b;
        return Math.abs(b) - (Math.abs(a) % Math.abs(b));
    }
}
