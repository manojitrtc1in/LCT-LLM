import java.util.*;
import java.io.*;

public class 9a48c31a2dcca937c7386993636ef111xcodeeval_processed_4000.json {
    static final long MOD = 1000000007;
    static int n, q;
    static int[] pos;
    static int[] w;

    static class TreeSegment<Value, Mod> {
        static class Node<Value, Mod> {
            boolean haveMod = false;
            Value value;
            Mod mod;
        }

        private final List<Node<Value, Mod>> S;
        private final int n;
        private final BiFunction<Value, Value, Value> magic;
        private final BiFunction<Value, Mod, Value> applyMod;
        private final BiFunction<Mod, Mod, Mod> mergeMods;

        TreeSegment(List<Value> src, BiFunction<Value, Value, Value> magic,
                    BiFunction<Value, Mod, Value> applyMod,
                    BiFunction<Mod, Mod, Mod> mergeMods) {
            this.magic = magic;
            this.applyMod = applyMod;
            this.mergeMods = mergeMods;
            this.n = src.size();
            S = new ArrayList<>(2 * n + 1);
            for (int i = 0; i < 2 * n + 1; i++) {
                S.add(new Node<>());
            }
            init(0, 0, n, src);
        }

        private void init(int i, int tl, int tr, List<Value> src) {
            if (tl + 1 == tr) {
                S.get(i).value = src.get(tl);
            } else {
                int mid = (tl + tr) / 2;
                init(i + 1, tl, mid, src);
                init(i + (mid - tl) * 2, mid, tr, src);
                recalcValue(i, tl, tr);
            }
        }

        private void recalcValue(int i, int tl, int tr) {
            if (tl + 1 != tr) {
                int mid = (tl + tr) / 2;
                S.get(i).value = magic.apply(getValue(i + 1, tl, mid), getValue(i + (mid - tl) * 2, mid, tr));
            }
        }

        private Value getValue(int i, int tl, int tr) {
            if (!S.get(i).haveMod) return S.get(i).value;
            return applyMod.apply(S.get(i).value, S.get(i).mod);
        }

        public Value query(int ql, int qr) {
            assert ql < qr;
            return query(0, 0, n, ql, qr);
        }

        private Value query(int i, int tl, int tr, int ql, int qr) {
            push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                return S.get(i).value;
            } else {
                int mid = (tl + tr) / 2;
                if (intersects(tl, mid, ql, qr) && intersects(mid, tr, ql, qr)) {
                    return magic.apply(query(i + 1, tl, mid, ql, qr), query(i + (mid - tl) * 2, mid, tr, ql, qr));
                } else if (intersects(tl, mid, ql, qr)) {
                    return query(i + 1, tl, mid, ql, qr);
                } else {
                    return query(i + (mid - tl) * 2, mid, tr, ql, qr);
                }
            }
        }

        private boolean intersects(int tl, int tr, int ql, int qr) {
            return !(tr <= ql || qr <= tl);
        }

        private void push(int i, int tl, int tr) {
            if (S.get(i).haveMod) {
                S.get(i).value = applyMod.apply(S.get(i).value, S.get(i).mod);
                if (tl + 1 != tr) {
                    int mid = (tl + tr) / 2;
                    addMod(i + 1, tl, mid, S.get(i).mod);
                    addMod(i + (mid - tl) * 2, mid, tr, S.get(i).mod);
                }
                S.get(i).haveMod = false;
            }
        }

        private void addMod(int i, int tl, int tr, Mod sub) {
            if (S.get(i).haveMod) {
                S.get(i).mod = mergeMods.apply(S.get(i).mod, sub);
            } else {
                S.get(i).mod = sub;
                S.get(i).haveMod = true;
            }
        }

        public void update(int ql, int qr, Mod mod) {
            update(0, 0, n, ql, qr, mod);
        }

        private void update(int i, int tl, int tr, int ql, int qr, Mod mod) {
            push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                addMod(i, tl, tr, mod);
            } else {
                int mid = (tl + tr) / 2;
                if (intersects(tl, mid, ql, qr)) {
                    update(i + 1, tl, mid, ql, qr, mod);
                }
                if (intersects(mid, tr, ql, qr)) {
                    update(i + (mid - tl) * 2, mid, tr, ql, qr, mod);
                }
                recalcValue(i, tl, tr);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        q = scanner.nextInt();
        pos = new int[n];
        w = new int[n];
        for (int i = 0; i < n; i++) {
            pos[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextInt();
        }

        TreeSegment<Integer, Integer> ts = new TreeSegment<>(Arrays.asList(Arrays.stream(w).boxed().toArray(Integer[]::new)),
                Integer::sum,
                (value, mod) -> mod,
                (old, _new) -> _new);

        int[] subw = new int[n];
        for (int i = 0; i < n; i++) {
            subw[i] = (int) ((w[i] * (i - pos[i])) % MOD);
        }

        TreeSegment<Integer, Integer> resp = new TreeSegment<>(Arrays.asList(Arrays.stream(subw).boxed().toArray(Integer[]::new)),
                (a, b) -> (a + b) % MOD,
                (value, mod) -> mod,
                (old, _new) -> _new);

        for (int i = 0; i < q; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            if (x < 0) {
                int ind = -x - 1;
                int _new = y;
                ts.update(ind, ind + 1, _new);
                resp.update(ind, ind + 1, (int) ((_new * (ind - pos[ind])) % MOD));
            } else {
                int l = x - 1;
                int r = y;

                int sm = ts.query(l, r);
                int bestL = ts.findRight(l, sm);

                int newX = pos[bestL] - bestL + l;

                int left = 0;
                if (l < bestL) {
                    left = (resp.query(l, bestL) + ts.query(l, bestL) * (newX - l)) % MOD;
                }
                int right = 0;
                if (bestL < r) {
                    right = (resp.query(bestL, r) + ts.query(bestL, r) * (newX - l)) % MOD;
                }
                System.out.println(floorMod(left - right, MOD));
            }
        }
        scanner.close();
    }

    static int floorMod(int a, long b) {
        if (a % b == 0) return 0;
        if (a >= 0 && b >= 0) return (int) (a % b);
        if (a <= 0 && b <= 0) return (int) (a % b);
        return (int) (Math.abs(b) - (Math.abs(a) % Math.abs(b)));
    }
}
