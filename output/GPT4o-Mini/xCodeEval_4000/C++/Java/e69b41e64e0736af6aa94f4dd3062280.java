import java.util.*;
import java.io.*;

public class e69b41e64e0736af6aa94f4dd3062280_nc {
    static final long MOD = 1000000007;

    static class TreeSegment<Value, Mod> {
        static class Node<Value, Mod> {
            boolean haveMod = false;
            int l = -1, r = -1;
            Value value;
            Mod mod;
        }

        private final List<Node<Value, Mod>> S = new ArrayList<>();
        private int n;
        private final BiFunction<Value, Value, Value> magic;
        private final BiFunction<Value, Mod, Value> applyMod;
        private final TriFunction<Mod, Mod, Mod> mergeMods;

        public TreeSegment(List<Value> src, BiFunction<Value, Value, Value> magic,
                           BiFunction<Value, Mod, Value> applyMod,
                           TriFunction<Mod, Mod, Mod> mergeMods) {
            this.magic = magic;
            this.applyMod = applyMod;
            this.mergeMods = mergeMods;
            init(src);
        }

        private void init(List<Value> src) {
            n = src.size();
            init(0, n, src);
        }

        private int init(int tl, int tr, List<Value> src) {
            int i = createNode();
            if (tl + 1 == tr) {
                S.get(i).value = src.get(tl);
            } else {
                int mid = (tl + tr) / 2;
                S.get(i).l = init(tl, mid, src);
                S.get(i).r = init(mid, tr, src);
                recalcValue(i, tl, tr);
            }
            return i;
        }

        private int createNode() {
            S.add(new Node<>());
            return S.size() - 1;
        }

        private void recalcValue(int i, int tl, int tr) {
            if (tl + 1 != tr) {
                int mid = (tl + tr) / 2;
                S.get(i).value = magic.apply(getValue(S.get(i).l, tl, mid), getValue(S.get(i).r, mid, tr));
            }
        }

        private Value getValue(int i, int tl, int tr) {
            if (!S.get(i).haveMod) return S.get(i).value;
            return applyMod.apply(S.get(i).value, S.get(i).mod);
        }

        public Value query(int ql, int qr) {
            return query(0, 0, n, ql, qr);
        }

        private Value query(int i, int tl, int tr, int ql, int qr) {
            push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                return S.get(i).value;
            } else {
                int mid = (tl + tr) / 2;
                if (intersects(tl, mid, ql, qr) && intersects(mid, tr, ql, qr)) {
                    return magic.apply(query(S.get(i).l, tl, mid, ql, qr), query(S.get(i).r, mid, tr, ql, qr));
                } else if (intersects(tl, mid, ql, qr)) {
                    return query(S.get(i).l, tl, mid, ql, qr);
                } else if (intersects(mid, tr, ql, qr)) {
                    return query(S.get(i).r, mid, tr, ql, qr);
                } else {
                    throw new AssertionError();
                }
            }
        }

        private void push(int i, int tl, int tr) {
            if (S.get(i).haveMod) {
                S.get(i).value = applyMod.apply(S.get(i).value, S.get(i).mod);
                if (tl + 1 != tr) {
                    int mid = (tl + tr) / 2;
                    addMod(S.get(i).l, tl, mid, S.get(i).mod);
                    addMod(S.get(i).r, mid, tr, S.get(i).mod);
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

        private boolean intersects(int tl, int tr, int ql, int qr) {
            return !(tr <= ql || qr <= tl);
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
                    update(S.get(i).l, tl, mid, ql, qr, mod);
                }
                if (intersects(mid, tr, ql, qr)) {
                    update(S.get(i).r, mid, tr, ql, qr, mod);
                }
                recalcValue(i, tl, tr);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        long q = Long.parseLong(st.nextToken());

        List<Integer> pos = new ArrayList<>();
        List<Integer> w = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            pos.add(Integer.parseInt(st.nextToken()));
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            w.add(Integer.parseInt(st.nextToken()));
        }

        TreeSegment<Integer, Integer> ts = new TreeSegment<>(w,
                Integer::sum,
                (value, mod) -> mod,
                (old, _new) -> _new);

        List<Integer> subw = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            subw.add((int) ((w.get(i) * (i - pos.get(i))) % MOD));
        }

        TreeSegment<Integer, Integer> resp = new TreeSegment<>(subw,
                (a, b) -> (a + b) % MOD,
                (value, mod) -> mod,
                (old, _new) -> _new);

        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            if (x < 0) {
                int ind = -x - 1;
                int _new = y;
                ts.update(ind, ind + 1, _new);
                resp.update(ind, ind + 1, (_new * (ind - pos.get(ind))) % MOD);
            } else {
                int l = x - 1;
                int r = y;

                int sm = ts.query(l, r);

                int bestL = ts.findRight(l, xValue -> xValue * 2 >= sm, 0);

                int xValue = pos.get(bestL) - bestL + l;

                int left = 0;
                if (l < bestL) {
                    left = (resp.query(l, bestL) + ts.query(l, bestL) * (xValue - l)) % MOD;
                }
                int right = 0;
                if (bestL < r) {
                    right = (resp.query(bestL, r) + ts.query(bestL, r) * (xValue - l)) % MOD;
                }
                System.out.println(floorMod(left - right, MOD));
            }
        }
    }

    private static long floorMod(long a, long b) {
        if (a % b == 0) return 0;
        if (a >= 0 && b >= 0) return a % b;
        if (a <= 0 && b <= 0) return a % b;
        return Math.abs(b) - (Math.abs(a) % Math.abs(b));
    }

    @FunctionalInterface
    interface TriFunction<A, B, C> {
        C apply(A a, B b);
    }
}
