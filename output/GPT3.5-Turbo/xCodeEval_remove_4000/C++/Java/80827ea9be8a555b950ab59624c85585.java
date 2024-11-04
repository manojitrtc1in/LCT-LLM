import java.util.*;

class Main {
    static class TreeSegment<Value, Mod> {
        static class Node {
            boolean have_mod = false;
            Value value;
            Mod mod;
        }

        interface Magic {
            Value apply(Value a, Value b);
        }

        interface ApplyMod {
            Value apply(Value value, Mod mod, int tl, int tr);
        }

        interface MergeMods {
            Mod merge(Mod a, Mod b, int tl, int tr);
        }

        Magic magic;
        ApplyMod apply_mod;
        MergeMods merge_mods;

        List<Node> S;
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

        <Check> Pair<Integer, Value> id0(int i, int tl, int tr, int L, Check checker, Value pref) {
            __push(i, tl, tr);
            if (tr <= L) return new Pair<>(-1, pref);
            if (tl + 1 == tr) {
                Value _this = magic.apply(pref, __get_value(i, tl, tr));
                if (checker.check(_this)) {
                    return new Pair<>(tl, _this);
                } else {
                    return new Pair<>(-1, _this);
                }
            } else {
                int mid = (tl + tr) / 2;
                if (L <= tl) {
                    Value _left = magic.apply(pref, __get_value(i + 1, tl, mid));
                    if (checker.check(_left)) {
                        return id0(i + 1, tl, mid, L, checker, pref);
                    } else {
                        return id0(i + (mid - tl) * 2, mid, tr, L, checker, _left);
                    }
                } else {
                    Pair<Integer, Value> t = id0(i + 1, tl, mid, L, checker, pref);
                    if (t.first != -1) return t;
                    return id0(i + (mid - tl) * 2, mid, tr, L, checker, t.second);
                }
            }
        }

        <Check> Pair<Integer, Value> id3(int i, int tl, int tr, int R, Check checker, Value pref) {
            __push(i, tl, tr);
            if (R < tl) return new Pair<>(-1, pref);
            if (tl + 1 == tr) {
                Value _this = magic.apply(pref, __get_value(i, tl, tr));
                if (checker.check(_this)) {
                    return new Pair<>(tl, _this);
                } else {
                    return new Pair<>(-1, _this);
                }
            } else {
                int mid = (tl + tr) / 2;
                if (tr <= R + 1) {
                    Value _right = magic.apply(pref, __get_value(S.get(i).r, mid, tr));
                    if (checker.check(_right)) {
                        return id3(S.get(i).r, mid, tr, R, checker, pref);
                    } else {
                        return id3(S.get(i).l, tl, mid, R, checker, _right);
                    }
                } else {
                    Pair<Integer, Value> t = id3(S.get(i).r, mid, tr, R, checker, pref);
                    if (t.first != -1) return t;
                    return id3(S.get(i).l, tl, mid, R, checker, t.second);
                }
            }
        }

        void init(List<Value> src) {
            n = src.size();
            S = new ArrayList<>();
            init(0, 0, src.size(), src);
        }

        TreeSegment(int n, Value def, Magic _magic, ApplyMod _apply_mod, MergeMods id1, Mod) {
            magic = _magic;
            apply_mod = _apply_mod;
            merge_mods = id1;
            init(new ArrayList<>(Collections.nCopies(n, def)));
        }

        TreeSegment(List<Value> def, Magic _magic, ApplyMod _apply_mod, MergeMods id1, Mod) {
            magic = _magic;
            apply_mod = _apply_mod;
            merge_mods = id1;
            init(def);
        }

        Value query(int ql, int qr) {
            assert ql < qr;
            return __query(0, 0, n, ql, qr);
        }

        void change(int i, Value value) {
            assert 0 <= i && i < n;
            __change(0, 0, n, i, value);
        }

        void update(int ql, int qr, Mod mod) {
            __update(0, 0, n, ql, qr, mod);
        }

        <Check> int find_right(int L, Check checker, Value start) {
            if (checker.check(start)) return L - 1;
            int rez = id0(0, 0, n, L, checker, start).first;
            return (rez == -1) ? n : rez;
        }

        <Check> int find_left(int R, Check checker, Value start) {
            if (checker.check(start)) return R + 1;
            int rez = id3(0, 0, n, R, checker, start).first;
            return (rez == -1) ? -1 : rez;
        }
    }

    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Check {
        interface Checker<T> {
            boolean check(T x);
        }

        static <T> Checker<T> create(Checker<T> checker) {
            return checker;
        }
    }

    static class Value {
        int value;

        Value(int value) {
            this.value = value;
        }
    }

    static class Mod {
        int value;

        Mod(int value) {
            this.value = value;
        }
    }

    static class ApplyMod {
        static Value apply(Value value, Mod mod, int tl, int tr) {
            return new Value(value.value + mod.value * (tr - tl));
        }
    }

    static class MergeMods {
        static Mod merge(Mod a, Mod b, int tl, int tr) {
            return new Mod(a.value + b.value);
        }
    }

    static class Magic {
        static Value apply(Value a, Value b) {
            return new Value(a.value + b.value);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        List<Integer> pos = new ArrayList<>();
        List<Integer> w = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            pos.add(scanner.nextInt());
        }
        for (int i = 0; i < n; i++) {
            w.add(scanner.nextInt());
        }

        TreeSegment<Value, Mod> ts = new TreeSegment<>(n, new Value(0), Magic::apply, ApplyMod::apply, MergeMods::merge, new Mod(1337));
        List<Value> subw = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            subw.add(new Value((w.get(i) * (i - pos.get(i))) % MOD));
        }
        TreeSegment<Value, Mod> resp = new TreeSegment<>(subw, Magic::apply, ApplyMod::apply, MergeMods::merge, new Mod(1337));

        for (int i = 0; i < q; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            if (x < 0) {
                int ind = -x;
                int _new = y;
                ind--;
                ts.update(ind, ind + 1, new Mod(_new));
                resp.update(ind, ind + 1, new Mod((_new * (ind - pos.get(ind))) % MOD));
            } else {
                int l = x;
                int r = y;
                l--;

                int sm = ts.query(l, r);

                int bestL = ts.find_right(l, Check.create(x -> x * 2 >= sm), new Value(0));

                int x = pos.get(bestL) - bestL + l;

                int left = 0;
                if (l < bestL) {
                    left = resp.query(l, bestL).value + ts.query(l, bestL).value * (x - l);
                }
                int right = 0;
                if (bestL < r) {
                    right = resp.query(bestL, r).value + ts.query(bestL, r).value * (x - l);
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

    static final int MOD = 1_000_000_007;
}
