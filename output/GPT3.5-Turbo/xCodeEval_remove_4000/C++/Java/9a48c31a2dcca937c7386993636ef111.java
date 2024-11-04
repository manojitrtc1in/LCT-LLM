import java.util.*;

class Main {
    static class TreeSegment<Value, Mod> {
        static class Node {
            boolean haveMod = false;
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
        ApplyMod applyMod;
        MergeMods mergeMods;

        List<Node> S;
        int n;

        boolean __intersects(int tl, int tr, int ql, int qr) {
            return !(tr <= ql || qr <= tl);
        }

        Value __getValue(int i, int tl, int tr) {
            if (!S.get(i).haveMod) return S.get(i).value;
            return applyMod.apply(S.get(i).value, S.get(i).mod, tl, tr);
        }

        void __recalcValue(int i, int tl, int tr) {
            if (tl + 1 != tr) {
                int mid = (tl + tr) / 2;
                S.get(i).value = magic.apply(
                        __getValue(i + 1, tl, mid),
                        __getValue(i + (mid - tl) * 2, mid, tr)
                );
            }
        }

        void __addMod(int i, int tl, int tr, Mod sub) {
            if (S.get(i).haveMod) {
                S.get(i).mod = mergeMods.merge(S.get(i).mod, sub, tl, tr);
            } else {
                S.get(i).mod = sub;
                S.get(i).haveMod = true;
            }
        }

        void __push(int i, int tl, int tr) {
            if (S.get(i).haveMod) {
                S.get(i).value = applyMod.apply(S.get(i).value, S.get(i).mod, tl, tr);
                if (tl + 1 != tr) {
                    int mid = (tl + tr) / 2;
                    __addMod(i + 1, tl, mid, S.get(i).mod);
                    __addMod(i + (mid - tl) * 2, mid, tr, S.get(i).mod);
                }
                S.get(i).haveMod = false;
            }
        }

        void init(int i, int tl, int tr, List<Value> src) {
            if (tl + 1 == tr) {
                S.get(i).value = src.get(tl);
            } else {
                int mid = (tl + tr) / 2;
                init(i + 1, tl, mid, src);
                init(i + (mid - tl) * 2, mid, tr, src);
                __recalcValue(i, tl, tr);
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
                __recalcValue(i, tl, tr);
            }
        }

        void __update(int i, int tl, int tr, int ql, int qr, Mod mod) {
            __push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                __addMod(i, tl, tr, mod);
            } else {
                int mid = (tl + tr) / 2;
                if (__intersects(tl, mid, ql, qr)) {
                    __update(i + 1, tl, mid, ql, qr, mod);
                }
                if (__intersects(mid, tr, ql, qr)) {
                    __update(i + (mid - tl) * 2, mid, tr, ql, qr, mod);
                }
                __recalcValue(i, tl, tr);
            }
        }

        <Check> Pair<Integer, Value> id0(int i, int tl, int tr, int L, Check checker, Value pref) {
            __push(i, tl, tr);
            if (tr <= L) return new Pair<>(-1, pref);
            if (tl + 1 == tr) {
                Value _this = magic.apply(pref, __getValue(i, tl, tr));
                if (checker.check(_this)) {
                    return new Pair<>(tl, _this);
                } else {
                    return new Pair<>(-1, _this);
                }
            } else {
                int mid = (tl + tr) / 2;
                if (L <= tl) {
                    Value _left = magic.apply(pref, __getValue(i + 1, tl, mid));
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
                Value _this = magic.apply(pref, __getValue(i, tl, tr));
                if (checker.check(_this)) {
                    return new Pair<>(tl, _this);
                } else {
                    return new Pair<>(-1, _this);
                }
            } else {
                int mid = (tl + tr) / 2;
                if (tr <= R + 1) {
                    Value _right = magic.apply(pref, __getValue(S.get(i).r, mid, tr));
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
            S = new ArrayList<>(2 * n + 1);
            for (int i = 0; i < 2 * n + 1; i++) {
                S.add(new Node());
            }
            init(0, 0, src.size(), src);
        }

        TreeSegment(int n, Value def, Magic magic, ApplyMod applyMod, MergeMods mergeMods, Mod mod) {
            this.magic = magic;
            this.applyMod = applyMod;
            this.mergeMods = mergeMods;
            List<Value> defList = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                defList.add(def);
            }
            init(defList);
        }

        TreeSegment(List<Value> def, Magic magic, ApplyMod applyMod, MergeMods mergeMods, Mod mod) {
            this.magic = magic;
            this.applyMod = applyMod;
            this.mergeMods = mergeMods;
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

        <Check> int findRight(int L, Check checker, Value start) {
            if (checker.check(start)) return L - 1;
            Pair<Integer, Value> rez = id0(0, 0, n, L, checker, start);
            return (rez.first == -1) ? n : rez.first;
        }

        <Check> int findLeft(int R, Check checker, Value start) {
            if (checker.check(start)) return R + 1;
            Pair<Integer, Value> rez = id3(0, 0, n, R, checker, start);
            return (rez.first == -1) ? -1 : rez.first;
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
        int sm;

        Check(int sm) {
            this.sm = sm;
        }

        boolean check(int x) {
            return x * 2 >= sm;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        int[] pos = new int[n];
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            pos[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextInt();
        }

        TreeSegment<Integer, Integer> ts = new TreeSegment<>(n, 0,
                (a, b) -> a + b,
                (value, mod, tl, tr) -> mod,
                (a, b, tl, tr) -> b,
                1337);

        List<Integer> subw = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            subw.add((w[i] * (i - pos[i])) % MOD);
        }

        TreeSegment<Integer, Integer> resp = new TreeSegment<>(subw,
                (a, b) -> (a + b) % MOD,
                (value, mod, tl, tr) -> mod,
                (a, b, tl, tr) -> b,
                1337);

        for (int i = 0; i < q; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            if (x < 0) {
                int ind = -x;
                int _new = y;
                ind--;
                ts.update(ind, ind + 1, _new);
                resp.update(ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
            } else {
                int l = x;
                int r = y;
                l--;

                int sm = ts.query(l, r);

                Check checker = new Check(sm);

                int bestL = ts.findRight(l, checker, 0);

                int x = pos[bestL] - bestL + l;

                int left = 0;
                if (l < bestL) {
                    left = resp.query(l, bestL) + ts.query(l, bestL) * (x - l);
                }
                int right = 0;
                if (bestL < r) {
                    right = resp.query(bestL, r) + ts.query(bestL, r) * (x - l);
                }
                System.out.println((left - right + MOD) % MOD);
            }
        }
    }
}
