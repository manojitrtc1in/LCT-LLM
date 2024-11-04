import java.util.*;
import java.io.*;

public class e69b41e64e0736af6aa94f4dd3062280xcodeeval_processed_4000.json {
    static final int MAXMEM = 200 * 1000 * 1024;
    static byte[] _memory = new byte[MAXMEM];
    static int _ptr = 0;

    static void* new(size_t _x) {
        _ptr += _x;
        assert(_ptr < MAXMEM);
        return _memory + _ptr - _x;
    }

    static void delete(void*) {}

    static String[] string_in_buffer = new String[260];

    static void fast_scan(int[] x) throws IOException {
        x[0] = Integer.parseInt(br.readLine());
    }

    static void fast_scan(long[] x) throws IOException {
        x[0] = Long.parseLong(br.readLine());
    }

    static void fast_scan(double[] x) throws IOException {
        x[0] = Double.parseDouble(br.readLine());
    }

    static void fast_scan(char[] x) throws IOException {
        x[0] = (char) br.read();
        if (x[0] == '\n') {
            fast_scan(x);
        }
    }

    static void fast_scan(String[] x) throws IOException {
        x[0] = br.readLine();
    }

    static void fast_print(int x) {
        System.out.print(x);
    }

    static void fast_print(long x) {
        System.out.print(x);
    }

    static void fast_print(double x) {
        System.out.printf("%.15f", x);
    }

    static void fast_print(String x) {
        System.out.print(x);
    }

    static void fast_print(char x) {
        System.out.print(x);
    }

    static void fast_print(int[] v) {
        if (v.length == 0) return;
        fast_print(v[0]);
        for (int i = 1; i < v.length; i++) {
            System.out.print(" ");
            fast_print(v[i]);
        }
    }

    static void fast_print(long[] v) {
        if (v.length == 0) return;
        fast_print(v[0]);
        for (int i = 1; i < v.length; i++) {
            System.out.print(" ");
            fast_print(v[i]);
        }
    }

    static void fast_print(double[] v) {
        if (v.length == 0) return;
        fast_print(v[0]);
        for (int i = 1; i < v.length; i++) {
            System.out.print(" ");
            fast_print(v[i]);
        }
    }

    static void fast_print(String[] v) {
        if (v.length == 0) return;
        fast_print(v[0]);
        for (int i = 1; i < v.length; i++) {
            System.out.print(" ");
            fast_print(v[i]);
        }
    }

    static void fast_print(char[] v) {
        if (v.length == 0) return;
        fast_print(v[0]);
        for (int i = 1; i < v.length; i++) {
            System.out.print(" ");
            fast_print(v[i]);
        }
    }

    static long MOD = 1000000007;

    static class TreeSegment<Value, Mod, Magic, ApplyMod, MergeMods> {
        static class Node {
            boolean have_mod = false;
            int l = -1, r = -1;
            Value value;
            Mod mod;
        }

        Magic magic;
        ApplyMod apply_mod;
        MergeMods merge_mods;

        List<Node> S = new ArrayList<>();
        int n;

        boolean __intersects(int tl, int tr, int ql, int qr) {
            return !(tr <= ql || qr <= tl);
        }

        int __create_node() {
            S.add(new Node());
            return S.size() - 1;
        }

        Value __get_value(int i, int tl, int tr) {
            if (!S.get(i).have_mod) return S.get(i).value;
            return apply_mod.apply(S.get(i).value, S.get(i).mod, tl, tr);
        }

        void __recalc_value(int i, int tl, int tr) {
            if (tl + 1 != tr) {
                int mid = (tl + tr) / 2;
                S.get(i).value = magic.apply(
                    __get_value(S.get(i).l, tl, mid),
                    __get_value(S.get(i).r, mid, tr)
                );
            }
        }

        void __add_mod(int i, int tl, int tr, Mod sub) {
            if (S.get(i).have_mod) {
                S.get(i).mod = merge_mods.apply(S.get(i).mod, sub, tl, tr);
            } else {
                S.get(i).mod = sub;
                S.get(i).have_mod = true;
            }
        }

        void __push(int i, int tl, int tr) {
            if (S.get(i).have_mod) {
                S.get(i).value = apply_mod.apply(S.get(i).value, S.get(i).mod, tl, tr);
                if (tl + 1 != tr) {
                    int mid = (tl + tr) / 2;
                    __add_mod(S.get(i).l, tl, mid, S.get(i).mod);
                    __add_mod(S.get(i).r, mid, tr, S.get(i).mod);
                }
                S.get(i).have_mod = false;
            }
        }

        int init(int tl, int tr, List<Value> src) {
            int i = __create_node();
            if (tl + 1 == tr) {
                S.get(i).value = src.get(tl);
            } else {
                int mid = (tl + tr) / 2;
                S.get(i).l = init(tl, mid, src);
                S.get(i).r = init(mid, tr, src);
                __recalc_value(i, tl, tr);
            }
            return i;
        }

        Value __query(int i, int tl, int tr, int ql, int qr) {
            __push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                return S.get(i).value;
            } else {
                int mid = (tl + tr) / 2;
                if (__intersects(tl, mid, ql, qr) && __intersects(mid, tr, ql, qr)) {
                    return magic.apply(
                        __query(S.get(i).l, tl, mid, ql, qr),
                        __query(S.get(i).r, mid, tr, ql, qr)
                    );
                } else if (__intersects(tl, mid, ql, qr)) {
                    return __query(S.get(i).l, tl, mid, ql, qr);
                } else if (__intersects(mid, tr, ql, qr)) {
                    return __query(S.get(i).r, mid, tr, ql, qr);
                } else {
                    throw new AssertionError();
                }
            }
        }

        void __update(int i, int tl, int tr, int ql, int qr, Mod mod) {
            __push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                __add_mod(i, tl, tr, mod);
            } else {
                int mid = (tl + tr) / 2;
                if (__intersects(tl, mid, ql, qr)) {
                    __update(S.get(i).l, tl, mid, ql, qr, mod);
                }
                if (__intersects(mid, tr, ql, qr)) {
                    __update(S.get(i).r, mid, tr, ql, qr, mod);
                }
                __recalc_value(i, tl, tr);
            }
        }

        void init(List<Value> src) {
            n = src.size();
            init(0, n, src);
        }

        TreeSegment(List<Value> def, Magic _magic, ApplyMod _apply_mod, MergeMods id1) {
            magic = _magic;
            apply_mod = _apply_mod;
            merge_mods = id1;
            init(def);
        }

        Value query(int ql, int qr) {
            return __query(0, 0, n, ql, qr);
        }

        void update(int ql, int qr, Mod mod) {
            __update(0, 0, n, ql, qr, mod);
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

        TreeSegment<Integer, Integer, BiFunction<Integer, Integer, Integer>, BiFunction<Integer, Integer, Integer>, BiFunction<Integer, Integer, Integer>> ts = 
            new TreeSegment<>(w, (a, b) -> a + b, (value, mod, tl, tr) -> mod);

        List<Integer> subw = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            subw.add((w.get(i) * (i - pos.get(i))) % MOD);
        }

        TreeSegment<Integer, Integer, BiFunction<Integer, Integer, Integer>, BiFunction<Integer, Integer, Integer>, BiFunction<Integer, Integer, Integer>> resp = 
            new TreeSegment<>(subw, (a, b) -> (a + b) % MOD, (value, mod, tl, tr) -> mod);

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
                int l = x - 1, r = y;
                int sm = ts.query(l, r);

                int bestL = ts.find_right(l, sm, 0);

                int x = pos.get(bestL) - bestL + l;

                int left = 0;
                if (l < bestL) {
                    left = resp.query(l, bestL) + ts.query(l, bestL) * (x - l);
                }
                int right = 0;
                if (bestL < r) {
                    right = resp.query(bestL, r) + ts.query(bestL, r) * (x - l);
                }
                fast_print(floor_mod(left - right, MOD));
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
