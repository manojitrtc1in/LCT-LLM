import java.util.*;
import java.io.*;

public class c85eec31c0814d744d203ea2ff3ef0fexcodeeval_processed_4000.json {
    static final int MAXMEM = 200 * 1000 * 1024;
    static byte[] _memory = new byte[MAXMEM];
    static int _ptr = 0;

    static void* newInstance(int size) {
        _ptr += size;
        assert _ptr < MAXMEM;
        return _memory + _ptr - size;
    }

    static void deleteInstance() {}

    static String[] stringInBuffer = new String[260];

    static void fastScan(int[] x) throws IOException {
        x[0] = Integer.parseInt(br.readLine());
    }

    static void fastScan(long[] x) throws IOException {
        x[0] = Long.parseLong(br.readLine());
    }

    static void fastScan(double[] x) throws IOException {
        x[0] = Double.parseDouble(br.readLine());
    }

    static void fastScan(String[] x) throws IOException {
        x[0] = br.readLine();
    }

    static void fastPrint(int x) {
        System.out.print(x);
    }

    static void fastPrint(long x) {
        System.out.print(x);
    }

    static void fastPrint(double x) {
        System.out.printf("%.15f", x);
    }

    static void fastPrint(String x) {
        System.out.print(x);
    }

    static void fastPrint(char x) {
        System.out.print(x);
    }

    static void fastPrint(int[] v) {
        if (v.length == 0) return;
        fastPrint(v[0]);
        for (int i = 1; i < v.length; i++) {
            System.out.print(" ");
            fastPrint(v[i]);
        }
    }

    static void fastPrint(long[] v) {
        if (v.length == 0) return;
        fastPrint(v[0]);
        for (int i = 1; i < v.length; i++) {
            System.out.print(" ");
            fastPrint(v[i]);
        }
    }

    static void fastPrint(double[] v) {
        if (v.length == 0) return;
        fastPrint(v[0]);
        for (int i = 1; i < v.length; i++) {
            System.out.print(" ");
            fastPrint(v[i]);
        }
    }

    static void fastPrint(String[] v) {
        if (v.length == 0) return;
        fastPrint(v[0]);
        for (int i = 1; i < v.length; i++) {
            System.out.print(" ");
            fastPrint(v[i]);
        }
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

        Node[] S;
        int n;

        boolean intersects(int tl, int tr, int ql, int qr) {
            return !(tr <= ql || qr <= tl);
        }

        Value getValue(int i, int tl, int tr) {
            if (!S[i].haveMod) return S[i].value;
            return applyMod(S[i].value, S[i].mod, tl, tr);
        }

        void recalcValue(int i, int tl, int tr) {
            if (tl + 1 != tr) {
                int mid = (tl + tr) / 2;
                S[i].value = magic(
                        getValue(i + 1, tl, mid),
                        getValue(i + (mid - tl) * 2, mid, tr)
                );
            }
        }

        void addMod(int i, int tl, int tr, Mod sub) {
            if (S[i].haveMod) {
                S[i].mod = mergeMods(S[i].mod, sub, tl, tr);
            } else {
                S[i].mod = sub;
                S[i].haveMod = true;
            }
        }

        void push(int i, int tl, int tr) {
            if (S[i].haveMod) {
                S[i].value = applyMod(S[i].value, S[i].mod, tl, tr);
                if (tl + 1 != tr) {
                    int mid = (tl + tr) / 2;
                    addMod(i + 1, tl, mid, S[i].mod);
                    addMod(i + (mid - tl) * 2, mid, tr, S[i].mod);
                }
                S[i].haveMod = false;
            }
        }

        void init(int i, int tl, int tr, List<Value> src) {
            if (tl + 1 == tr) {
                S[i].value = src.get(tl);
            } else {
                int mid = (tl + tr) / 2;
                init(i + 1, tl, mid, src);
                init(i + (mid - tl) * 2, mid, tr, src);
                recalcValue(i, tl, tr);
            }
        }

        Value query(int i, int tl, int tr, int ql, int qr) {
            push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                return S[i].value;
            } else {
                int mid = (tl + tr) / 2;
                if (intersects(tl, mid, ql, qr) && intersects(mid, tr, ql, qr)) {
                    return magic(
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

        void change(int i, int tl, int tr, int j, Value _new) {
            push(i, tl, tr);
            if (tl + 1 == tr) {
                S[i].value = _new;
            } else {
                int m = (tl + tr) / 2;
                if (j < m) {
                    change(S[i].l, tl, m, j, _new);
                } else {
                    change(S[i].r, m, tr, j, _new);
                }
                recalcValue(i, tl, tr);
            }
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

        void init(List<Value> src) {
            n = src.size();
            S = new Node[2 * n + 1];
            init(0, 0, n, src);
        }

        TreeSegment(List<Value> def, Magic _magic, ApplyMod _applyMod, MergeMods id2, Mod) {
            magic = _magic;
            applyMod = _applyMod;
            mergeMods = id2;
            init(def);
        }

        Value query(int ql, int qr) {
            assert ql < qr;
            return query(0, 0, n, ql, qr);
        }

        void change(int i, Value value) {
            assert 0 <= i && i < n;
            change(0, 0, n, i, value);
        }

        void update(int ql, int qr, Mod mod) {
            update(0, 0, n, ql, qr, mod);
        }
    }

    static int n, q;
    static List<Integer> pos = new ArrayList<>();
    static List<Integer> w = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            pos.add(Integer.parseInt(br.readLine()));
        }
        for (int i = 0; i < n; i++) {
            w.add(Integer.parseInt(br.readLine()));
        }

        TreeSegment<Integer, Integer, Integer, Integer, Integer> ts = new TreeSegment<>(w, (a, b) -> a + b, (value, mod, tl, tr) -> mod, (old, _new, tl, tr) -> _new, 1337);

        List<Integer> subw = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            subw.add((w.get(i) * (i - pos.get(i))) % MOD);
        }

        TreeSegment<Integer, Integer, Integer, Integer, Integer> resp = new TreeSegment<>(subw, (a, b) -> (a + b) % MOD, (value, mod, tl, tr) -> mod, (old, _new, tl, tr) -> _new, 1337);

        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            if (x < 0) {
                int ind = -x;
                int _new = y;
                ind--;
                ts.update(ind, ind + 1, _new);
                resp.update(ind, ind + 1, (_new * (ind - pos.get(ind))) % MOD);
            } else {
                int l = x, r = y;
                l--;

                int sm = ts.query(l, r);

                int bestL = ts.findRight(l, sm, 0);

                int x = pos.get(bestL) - bestL + l;

                int left = 0;
                if (l < bestL) {
                    left = resp.query(l, bestL) + ts.query(l, bestL) * (x - l);
                }
                int right = 0;
                if (bestL < r) {
                    right = resp.query(bestL, r) + ts.query(bestL, r) * (x - l);
                }
                if (l == 2 && r == 5) {
                    // Additional logic can be added here if needed
                }
                System.out.println(floorMod(left - right, MOD));
            }
        }
    }

    static int floorMod(int a, int b) {
        if (a % b == 0) return 0;
        if (a >= 0 && b >= 0) return a % b;
        if (a <= 0 && b <= 0) return a % b;
        return Math.abs(b) - (Math.abs(a) % Math.abs(b));
    }
}
