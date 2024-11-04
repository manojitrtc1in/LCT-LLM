import java.util.*;
import java.io.*;

public class 0c54a363c786997b7d706afabe1869f8xcodeeval_processed_4000.json {
    static final int MAXMEM = 200 * 1000 * 1024;
    static byte[] _memory = new byte[MAXMEM];
    static int _ptr = 0;

    static void* new(size_t _x) {
        _ptr += _x;
        assert(_ptr < MAXMEM);
        return _memory + _ptr - _x;
    }

    static void delete(void* ptr) {}

    static String[] string_in_buffer = new String[260];

    static void fast_scan(int[] x) throws IOException {
        x[0] = Integer.parseInt(next());
    }

    static void fast_scan(long[] x) throws IOException {
        x[0] = Long.parseLong(next());
    }

    static void fast_scan(double[] x) throws IOException {
        x[0] = Double.parseDouble(next());
    }

    static void fast_scan(char[] x) throws IOException {
        x[0] = next().charAt(0);
    }

    static void fast_scan(String[] x) throws IOException {
        x[0] = next();
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
        for (int i = 0; i < v.length; i++) {
            fast_print(v[i]);
            if (i < v.length - 1) {
                System.out.print(" ");
            }
        }
    }

    static void fast_print(long[] v) {
        for (int i = 0; i < v.length; i++) {
            fast_print(v[i]);
            if (i < v.length - 1) {
                System.out.print(" ");
            }
        }
    }

    static void fast_print(double[] v) {
        for (int i = 0; i < v.length; i++) {
            fast_print(v[i]);
            if (i < v.length - 1) {
                System.out.print(" ");
            }
        }
    }

    static void fast_print(String[] v) {
        for (int i = 0; i < v.length; i++) {
            fast_print(v[i]);
            if (i < v.length - 1) {
                System.out.print(" ");
            }
        }
    }

    static String next() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        return br.readLine();
    }

    static class TreeSegment<Value, Mod, Magic, ApplyMod, MergeMods> {
        static class Node {
            boolean have_mod = false;
            Value value;
            Mod mod;
        }

        Magic magic;
        ApplyMod apply_mod;
        MergeMods merge_mods;

        List<Node> S;

        int n;

        boolean __intersects(int tl, int tr, int ql, int qr) {
            return !(tr <= ql || qr <= tl);
        }

        Value __get_value(int i, int tl, int tr) {
            if (!S.get(i).have_mod) return S.get(i).value;
            return apply_mod.apply(S.get(i).value, S.get(i).mod, tl, tr);
        }

        void __recalc_value(int i, int tl, int tr) {
            if (tl + 1 != tr) {
                int mid = (tl + tr) / 2;
                S.get(i).value = magic.apply(
                        __get_value(i + 1, tl, mid),
                        __get_value(i + (mid - tl) * 2, mid, tr)
                );
            }
        }

        void __add_mod(int i, int tl, int tr, Mod sub) {
            if (S.get(i).have_mod) {
                S.get(i).mod = merge_mods.merge(S.get(i).mod, sub, tl, tr);
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
                    __add_mod(i + 1, tl, mid, S.get(i).mod);
                    __add_mod(i + (mid - tl) * 2, mid, tr, S.get(i).mod);
                }
                S.get(i).have_mod = false;
            }
        }

        void init(int i, int tl, int tr, List<Value> src) {
            if (tl + 1 == tr) {
                S.get(i).value = src.get(tl);
            } else {
                int mid = (tl + tr) / 2;
                init(i + 1, tl, mid, src);
                init(i + (mid - tl) * 2, mid, tr, src);
                __recalc_value(i, tl, tr);
            }
        }

        Value __query(int i, int tl, int tr, int ql, int qr) {
            __push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                return S.get(i).value;
            } else {
                int mid = (tl + tr) / 2;
                if (__intersects(tl, mid, ql, qr) && __intersects(mid, tr, ql, qr)) {
                    return magic.apply(
                            __query(i + 1, tl, mid, ql, qr),
                            __query(i + (mid - tl) * 2, mid, tr, ql, qr)
                    );
                } else if (__intersects(tl, mid, ql, qr)) {
                    return __query(i + 1, tl, mid, ql, qr);
                } else {
                    return __query(i + (mid - tl) * 2, mid, tr, ql, qr);
                }
            }
        }

        void __change(int i, int tl, int tr, int j, Value _new) {
            __push(i, tl, tr);
            if (tl + 1 == tr) {
                S.get(i).value = _new;
            } else {
                int m = (tl + tr) / 2;
                if (j < m) {
                    __change(S.get(i).l, tl, m, j, _new);
                } else {
                    __change(S.get(i).r, m, tr, j, _new);
                }
                __recalc_value(i, tl, tr);
            }
        }

        void __update(int i, int tl, int tr, int ql, int qr, Mod mod) {
            __push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                __add_mod(i, tl, tr, mod);
            } else {
                int mid = (tl + tr) / 2;
                if (__intersects(tl, mid, ql, qr)) {
                    __update(i + 1, tl, mid, ql, qr, mod);
                }
                if (__intersects(mid, tr, ql, qr)) {
                    __update(i + (mid - tl) * 2, mid, tr, ql, qr, mod);
                }
                __recalc_value(i, tl, tr);
            }
        }

        void init(List<Value> src) {
            n = src.size();
            S = new ArrayList<>(2 * n + 1);
            init(0, 0, n, src);
        }

        TreeSegment(List<Value> def, Magic _magic, ApplyMod _apply_mod, MergeMods id1) {
            magic = _magic;
            apply_mod = _apply_mod;
            merge_mods = id1;
            init(def);
        }

        Value query(int ql, int qr) {
            assert(ql < qr);
            return __query(0, 0, n, ql, qr);
        }

        void change(int i, Value value) {
            assert(0 <= i && i < n);
            __change(0, 0, n, i, value);
        }

        void update(int ql, int qr, Mod mod) {
            __update(0, 0, n, ql, qr, mod);
        }
    }

    public static void main(String[] args) throws IOException {
        int n, q;
        fast_scan(new int[]{n});
        fast_scan(new int[]{q});
        List<Integer> pos = new ArrayList<>(n);
        List<Integer> w = new ArrayList<>(n);
        fast_scan(pos.toArray(new Integer[n]));
        fast_scan(w.toArray(new Integer[n]));

        TreeSegment<Integer, Integer, Function<Integer, Integer>, Function<Integer, Integer>, Function<Integer, Integer>> ts =
                new TreeSegment<>(w, (a, b) -> a + b, (value, mod, tl, tr) -> mod);

        List<Integer> subw = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            subw.add((w.get(i) * (i - pos.get(i))) % MOD);
        }

        TreeSegment<Integer, Integer, Function<Integer, Integer>, Function<Integer, Integer>, Function<Integer, Integer>> resp =
                new TreeSegment<>(subw, (a, b) -> (a + b) % MOD, (value, mod, tl, tr) -> mod);

        for (int i = 0; i < q; i++) {
            int[] x = new int[1];
            int[] y = new int[1];
            fast_scan(x);
            fast_scan(y);
            if (x[0] < 0) {
                int ind = -x[0];
                int _new = y[0];
                ind--;
                ts.update(ind, ind + 1, _new);
                resp.update(ind, ind + 1, (_new * (ind - pos.get(ind))) % MOD);
            } else {
                int l = x[0], r = y[0];
                l--;

                int sm = ts.query(l, r);

                int bestL = ts.find_right(l, sm, 0);

                int x_val = pos.get(bestL) - bestL + l;

                int left = 0;
                if (l < bestL) {
                    left = resp.query(l, bestL) + ts.query(l, bestL) * (x_val - l);
                }
                int right = 0;
                if (bestL < r) {
                    right = resp.query(bestL, r) + ts.query(bestL, r) * (x_val - l);
                }
                fast_print(floor_mod(left - right, MOD));
            }
        }
    }
}
