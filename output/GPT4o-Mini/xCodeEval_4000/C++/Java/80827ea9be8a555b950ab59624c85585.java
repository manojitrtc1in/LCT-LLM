import java.util.*;
import java.io.*;

public class 80827ea9be8a555b950ab59624c85585_nc {
    static final long MOD = 1000000007;
    static long[] pos, w;
    static TreeSegment<Long, Long, Long, Long, Long> ts, resp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        long q = Long.parseLong(st.nextToken());
        
        pos = new long[(int) n];
        w = new long[(int) n];
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            pos[i] = Long.parseLong(st.nextToken());
        }
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            w[i] = Long.parseLong(st.nextToken());
        }

        ts = new TreeSegment<>(Arrays.asList(w), 
            (a, b) -> a + b, 
            (value, mod, tl, tr) -> mod, 
            (old, _new, tl, tr) -> _new, 
            1337L);

        long[] subw = new long[(int) n];
        for (int i = 0; i < n; i++) {
            subw[i] = (w[i] * (i - pos[i])) % MOD;
        }

        resp = new TreeSegment<>(Arrays.asList(subw), 
            (a, b) -> (a + b) % MOD, 
            (value, mod, tl, tr) -> mod, 
            (old, _new, tl, tr) -> _new, 
            1337L);

        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());

            if (x < 0) {
                int ind = (int) -x - 1;
                long _new = y;
                ts.update(ind, ind + 1, _new);
                resp.update(ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
            } else {
                int l = (int) x - 1;
                int r = (int) y;

                long sm = ts.query(l, r);

                int bestL = ts.findRight(l, (Long val) -> val * 2 >= sm, 0);

                long xValue = pos[bestL] - bestL + l;

                long left = 0;
                if (l < bestL) {
                    left = (resp.query(l, bestL) + ts.query(l, bestL) * (xValue - l)) % MOD;
                }
                long right = 0;
                if (bestL < r) {
                    right = (resp.query(bestL, r) + ts.query(bestL, r) * (xValue - l)) % MOD;
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

    static class TreeSegment<Value, Mod, Magic, ApplyMod, MergeMods> {
        class Node {
            boolean haveMod = false;
            Value value;
            Mod mod;
        }

        Magic magic;
        ApplyMod applyMod;
        MergeMods mergeMods;
        List<Node> S;
        int n;

        TreeSegment(List<Value> src, Magic magic, ApplyMod applyMod, MergeMods mergeMods, Mod mod) {
            this.magic = magic;
            this.applyMod = applyMod;
            this.mergeMods = mergeMods;
            init(src);
        }

        void init(List<Value> src) {
            n = src.size();
            S = new ArrayList<>(Collections.nCopies(2 * n + 1, new Node()));
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

        void recalcValue(int i, int tl, int tr) {
            if (tl + 1 != tr) {
                int mid = (tl + tr) / 2;
                S.get(i).value = magic.apply(
                    getValue(i + 1, tl, mid),
                    getValue(i + (mid - tl) * 2, mid, tr)
                );
            }
        }

        Value getValue(int i, int tl, int tr) {
            if (!S.get(i).haveMod) return S.get(i).value;
            return applyMod.apply(S.get(i).value, S.get(i).mod, tl, tr);
        }

        void update(int ql, int qr, Mod mod) {
            update(0, 0, n, ql, qr, mod);
        }

        void update(int i, int tl, int tr, int ql, int qr, Mod mod) {
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

        void addMod(int i, int tl, int tr, Mod sub) {
            if (S.get(i).haveMod) {
                S.get(i).mod = mergeMods.apply(S.get(i).mod, sub, tl, tr);
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

        Value query(int ql, int qr) {
            assert(ql < qr);
            return query(0, 0, n, ql, qr);
        }

        Value query(int i, int tl, int tr, int ql, int qr) {
            push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                return S.get(i).value;
            } else {
                int mid = (tl + tr) / 2;
                if (intersects(tl, mid, ql, qr) && intersects(mid, tr, ql, qr)) {
                    return magic.apply(
                        query(i + 1, tl, mid, ql, qr),
                        query(i + (mid - tl) * 2, mid, tr, ql, qr)
                    );
                } else if (intersects(tl, mid, ql, qr)) {
                    return query(i + 1, tl, mid, ql, qr);
                } else {
                    return query(i + (mid - tl) * 2, mid, tr, ql, qr);
                }
            }
        }

        boolean intersects(int tl, int tr, int ql, int qr) {
            return !(tr <= ql || qr <= tl);
        }

        int findRight(int L, Check<Long> checker, Value pref) {
            if (checker.check(pref)) return L - 1;
            int rez = findRight(0, 0, n, L, checker, pref).first;
            return (rez == -1) ? n : rez;
        }

        Pair<Integer, Value> findRight(int i, int tl, int tr, int L, Check<Long> checker, Value pref) {
            push(i, tl, tr);
            if (tr <= L) return new Pair<>(-1, pref);
            if (tl + 1 == tr) {
                Value _this = magic.apply(pref, getValue(i, tl, tr));
                if (checker.check(_this)) {
                    return new Pair<>(tl, _this);
                } else {
                    return new Pair<>(-1, _this);
                }
            } else {
                int mid = (tl + tr) / 2;
                if (L <= tl) {
                    Value _left = magic.apply(pref, getValue(i + 1, tl, mid));
                    if (checker.check(_left)) {
                        return findRight(i + 1, tl, mid, L, checker, pref);
                    } else {
                        return findRight(i + (mid - tl) * 2, mid, tr, L, checker, _left);
                    }
                } else {
                    Pair<Integer, Value> t = findRight(i + 1, tl, mid, L, checker, pref);
                    if (t.first != -1) return t;
                    return findRight(i + (mid - tl) * 2, mid, tr, L, checker, t.second);
                }
            }
        }

        interface Check<T> {
            boolean check(T value);
        }

        static class Pair<F, S> {
            F first;
            S second;

            Pair(F first, S second) {
                this.first = first;
                this.second = second;
            }
        }
    }
}
