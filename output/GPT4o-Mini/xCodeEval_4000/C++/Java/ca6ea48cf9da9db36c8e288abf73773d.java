import java.util.*;
import java.io.*;

public class ca6ea48cf9da9db36c8e288abf73773d_nc {
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

        ts = new TreeSegment<>(w, (a, b) -> a + b, (value, mod, tl, tr) -> mod, (old, _new, tl, tr) -> _new, 1337L);
        
        long[] subw = new long[(int) n];
        for (int i = 0; i < n; i++) {
            subw[i] = (w[i] * (i - pos[i])) % MOD;
        }

        resp = new TreeSegment<>(subw, (a, b) -> (a + b) % MOD, (value, mod, tl, tr) -> mod, (old, _new, tl, tr) -> _new, 1337L);

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

                int bestL = ts.findRight(l, sm, 0);

                long xVal = pos[bestL] - bestL + l;

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

    static class TreeSegment<Value, Mod, Magic, ApplyMod, MergeMods> {
        class Node {
            boolean haveMod = false;
            int l = -1, r = -1;
            Value value;
            Mod mod;
        }

        Magic magic;
        ApplyMod applyMod;
        MergeMods mergeMods;

        List<Node> S = new ArrayList<>();
        int n;

        boolean intersects(int tl, int tr, int ql, int qr) {
            return !(tr <= ql || qr <= tl);
        }

        int createNode() {
            S.add(new Node());
            return S.size() - 1;
        }

        Value getValue(int i, int tl, int tr) {
            if (!S.get(i).haveMod) return S.get(i).value;
            return applyMod.apply(S.get(i).value, S.get(i).mod, tl, tr);
        }

        void recalcValue(int i, int tl, int tr) {
            if (tl + 1 != tr) {
                int mid = (tl + tr) / 2;
                S.get(i).value = magic.apply(getValue(S.get(i).l, tl, mid), getValue(S.get(i).r, mid, tr));
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
                    addMod(S.get(i).l, tl, mid, S.get(i).mod);
                    addMod(S.get(i).r, mid, tr, S.get(i).mod);
                }
                S.get(i).haveMod = false;
            }
        }

        int init(int tl, int tr, List<Value> src) {
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

        Value query(int i, int tl, int tr, int ql, int qr) {
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

        void update(int i, int tl, int tr, int ql, int qr, Mod mod) {
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

        int findRight(int i, int tl, int tr, int L, Check checker, Value pref) {
            push(i, tl, tr);
            if (tr <= L) return -1;
            if (tl + 1 == tr) {
                Value _this = magic.apply(pref, getValue(i, tl, tr));
                if (checker.check(_this)) {
                    return tl;
                } else {
                    return -1;
                }
            } else {
                int mid = (tl + tr) / 2;
                if (L <= tl) {
                    Value _left = magic.apply(pref, getValue(S.get(i).l, tl, mid));
                    if (checker.check(_left)) {
                        return findRight(S.get(i).l, tl, mid, L, checker, pref);
                    } else {
                        return findRight(S.get(i).r, mid, tr, L, checker, _left);
                    }
                } else {
                    int t = findRight(S.get(i).l, tl, mid, L, checker, pref);
                    if (t != -1) return t;
                    return findRight(S.get(i).r, mid, tr, L, checker, t);
                }
            }
        }

        void init(List<Value> src) {
            n = src.size();
            init(0, n, src);
        }

        TreeSegment(List<Value> def, Magic _magic, ApplyMod _applyMod, MergeMods _mergeMods, Mod) {
            magic = _magic;
            applyMod = _applyMod;
            mergeMods = _mergeMods;
            init(def);
        }

        Value query(int ql, int qr) {
            return query(0, 0, n, ql, qr);
        }

        void update(int ql, int qr, Mod mod) {
            update(0, 0, n, ql, qr, mod);
        }

        interface Check {
            boolean check(Value value);
        }
    }
}
