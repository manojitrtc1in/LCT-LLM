import java.util.*;
import java.io.*;

public class ca6ea48cf9da9db36c8e288abf73773dxcodeeval_processed_4000.json {
    static final int MAXMEM = 200 * 1000 * 1024;
    static byte[] _memory = new byte[MAXMEM];
    static int _ptr = 0;

    static void* new(size_t _x) {
        _ptr += _x;
        assert(_ptr < MAXMEM);
        return _memory + _ptr - _x;
    }

    static void delete(void*) {}

    static final int MOD = (int)1e9 + 7;

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
            return apply_mod(S.get(i).value, S.get(i).mod, tl, tr);
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
                S.get(i).value = apply_mod(S.get(i).value, S.get(i).mod, tl, tr);
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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        List<Integer> pos = new ArrayList<>(n);
        List<Integer> w = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            pos.add(scanner.nextInt());
        }
        for (int i = 0; i < n; i++) {
            w.add(scanner.nextInt());
        }

        TreeSegment<Integer, Integer, BiFunction<Integer, Integer, Integer>, 
                     BiFunction<Integer, Integer, Integer>, 
                     BiFunction<Integer, Integer, Integer>> ts = 
            new TreeSegment<>(w, (a, b) -> a + b, (value, mod, tl, tr) -> mod);

        List<Integer> subw = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            subw.add((w.get(i) * (i - pos.get(i))) % MOD);
        }

        TreeSegment<Integer, Integer, BiFunction<Integer, Integer, Integer>, 
                     BiFunction<Integer, Integer, Integer>, 
                     BiFunction<Integer, Integer, Integer>> resp = 
            new TreeSegment<>(subw, (a, b) -> (a + b) % MOD, (value, mod, tl, tr) -> mod);

        for (int i = 0; i < q; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            if (x < 0) {
                int ind = -x - 1;
                int _new = y;
                ts.update(ind, ind + 1, _new);
                resp.update(ind, ind + 1, (_new * (ind - pos.get(ind))) % MOD);
            } else {
                int l = x - 1;
                int r = y;

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
                System.out.println(floor_mod(left - right, MOD));
            }
        }
    }

    static int floor_mod(int a, int b) {
        if (a % b == 0) return 0;
        if (a >= 0 && b >= 0) return a % b;
        if (a <= 0 && b <= 0) return a % b;
        return Math.abs(b) - (Math.abs(a) % Math.abs(b));
    }
}
