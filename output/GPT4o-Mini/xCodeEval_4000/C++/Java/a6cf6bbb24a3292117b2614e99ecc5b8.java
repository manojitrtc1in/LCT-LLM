import java.util.*;
import java.io.*;

public class a6cf6bbb24a3292117b2614e99ecc5b8_nc {
    static final long MOD = 1000000007;
    static long[] pos, w;
    static TreeSegment<Long, Long, Long, Long, Long> ts, resp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        
        pos = new long[n];
        w = new long[n];
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            pos[i] = Long.parseLong(st.nextToken());
        }
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            w[i] = Long.parseLong(st.nextToken());
        }

        ts = new TreeSegment<>(w, (a, b) -> a + b, (value, mod, tl, tr) -> mod, (oldVal, newVal, tl, tr) -> newVal, 1337L);
        
        long[] subw = new long[n];
        for (int i = 0; i < n; i++) {
            subw[i] = (w[i] * (i - pos[i])) % MOD;
        }

        resp = new TreeSegment<>(subw, (a, b) -> (a + b) % MOD, (value, mod, tl, tr) -> mod, (oldVal, newVal, tl, tr) -> newVal, 1337L);

        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());

            if (x < 0) {
                int ind = (int) -x - 1;
                long newVal = y;
                ts.update(ind, ind + 1, newVal);
                resp.update(ind, ind + 1, (newVal * (ind - pos[ind])) % MOD);
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
        static class Node {
            boolean haveMod = false;
            long value;
            long mod;
        }

        Magic magic;
        ApplyMod applyMod;
        MergeMods mergeMods;
        Node[] S;
        int n;

        public TreeSegment(long[] src, Magic magic, ApplyMod applyMod, MergeMods mergeMods, long def) {
            this.magic = magic;
            this.applyMod = applyMod;
            this.mergeMods = mergeMods;
            init(src);
        }

        void init(long[] src) {
            n = src.length;
            S = new Node[2 * n + 1];
            for (int i = 0; i < S.length; i++) {
                S[i] = new Node();
            }
            init(0, 0, n, src);
        }

        void init(int i, int tl, int tr, long[] src) {
            if (tl + 1 == tr) {
                S[i].value = src[tl];
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
                S[i].value = magic.apply(S[i + 1].value, S[i + (mid - tl) * 2].value);
            }
        }

        void push(int i, int tl, int tr) {
            if (S[i].haveMod) {
                S[i].value = applyMod.apply(S[i].value, S[i].mod, tl, tr);
                if (tl + 1 != tr) {
                    int mid = (tl + tr) / 2;
                    addMod(i + 1, tl, mid, S[i].mod);
                    addMod(i + (mid - tl) * 2, mid, tr, S[i].mod);
                }
                S[i].haveMod = false;
            }
        }

        void addMod(int i, int tl, int tr, long sub) {
            if (S[i].haveMod) {
                S[i].mod = mergeMods.apply(S[i].mod, sub, tl, tr);
            } else {
                S[i].mod = sub;
                S[i].haveMod = true;
            }
        }

        long query(int ql, int qr) {
            assert(ql < qr);
            return __query(0, 0, n, ql, qr);
        }

        long __query(int i, int tl, int tr, int ql, int qr) {
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

        boolean intersects(int tl, int tr, int ql, int qr) {
            return !(tr <= ql || qr <= tl);
        }

        void update(int ql, int qr, long mod) {
            __update(0, 0, n, ql, qr, mod);
        }

        void __update(int i, int tl, int tr, int ql, int qr, long mod) {
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

        int findRight(int L, long sm, long start) {
            if (sm >= start) return L - 1;
            int rez = __findRight(0, 0, n, L, sm, start).first;
            return (rez == -1) ? n : rez;
        }

        Pair<Integer, Long> __findRight(int i, int tl, int tr, int L, long sm, long pref) {
            push(i, tl, tr);
            if (tr <= L) return new Pair<>(-1, pref);
            if (tl + 1 == tr) {
                long thisVal = magic.apply(pref, S[i].value);
                if (thisVal * 2 >= sm) {
                    return new Pair<>(tl, thisVal);
                } else {
                    return new Pair<>(-1, thisVal);
                }
            } else {
                int mid = (tl + tr) / 2;
                if (L <= tl) {
                    long left = magic.apply(pref, S[i + 1].value);
                    if (left * 2 >= sm) {
                        return __findRight(i + 1, tl, mid, L, sm, pref);
                    } else {
                        return __findRight(i + (mid - tl) * 2, mid, tr, L, sm, left);
                    }
                } else {
                    Pair<Integer, Long> t = __findRight(i + 1, tl, mid, L, sm, pref);
                    if (t.first != -1) return t;
                    return __findRight(i + (mid - tl) * 2, mid, tr, L, sm, t.second);
                }
            }
        }
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
