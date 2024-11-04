import java.util.*;

class Main {
    static class TreeSegment<Value, Mod> {
        static class Node {
            boolean haveMod = false;
            Value value;
            Mod mod;
        }

        interface Magic<Value> {
            Value apply(Value a, Value b);
        }

        interface ApplyMod<Value, Mod> {
            Value apply(Value value, Mod mod, int tl, int tr);
        }

        interface MergeMods<Mod> {
            Mod merge(Mod a, Mod b, int tl, int tr);
        }

        Node[] S;
        int n;
        Magic<Value> magic;
        ApplyMod<Value, Mod> applyMod;
        MergeMods<Mod> mergeMods;

        boolean __intersects(int tl, int tr, int ql, int qr) {
            return !(tr <= ql || qr <= tl);
        }

        Value __getValue(int i, int tl, int tr) {
            if (!S[i].haveMod) return S[i].value;
            return applyMod.apply(S[i].value, S[i].mod, tl, tr);
        }

        void __recalcValue(int i, int tl, int tr) {
            if (tl + 1 != tr) {
                int mid = (tl + tr) / 2;
                S[i].value = magic.apply(
                        __getValue(i + 1, tl, mid),
                        __getValue(i + (mid - tl) * 2, mid, tr)
                );
            }
        }

        void __addMod(int i, int tl, int tr, Mod sub) {
            if (S[i].haveMod) {
                S[i].mod = mergeMods.merge(S[i].mod, sub, tl, tr);
            } else {
                S[i].mod = sub;
                S[i].haveMod = true;
            }
        }

        void __push(int i, int tl, int tr) {
            if (S[i].haveMod) {
                S[i].value = applyMod.apply(S[i].value, S[i].mod, tl, tr);
                if (tl + 1 != tr) {
                    int mid = (tl + tr) / 2;
                    __addMod(i + 1, tl, mid, S[i].mod);
                    __addMod(i + (mid - tl) * 2, mid, tr, S[i].mod);
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
                __recalcValue(i, tl, tr);
            }
        }

        Value __query(int i, int tl, int tr, int ql, int qr) {
            __push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                return S[i].value;
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
                S[i].value = _new;
            } else {
                int m = (tl + tr) / 2;
                if (j < m) {
                    __change(S[i].l, tl, m, j, _new);
                } else {
                    __change(S[i].r, m, tr, j, _new);
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

        <Check> Pair<Integer, Value> __findRight(int i, int tl, int tr, int L, Check checker, Value pref) {
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
                        return __findRight(i + 1, tl, mid, L, checker, pref);
                    } else {
                        return __findRight(i + (mid - tl) * 2, mid, tr, L, checker, _left);
                    }
                } else {
                    Pair<Integer, Value> t = __findRight(i + 1, tl, mid, L, checker, pref);
                    if (t.getKey() != -1) return t;
                    return __findRight(i + (mid - tl) * 2, mid, tr, L, checker, t.getValue());
                }
            }
        }

        <Check> Pair<Integer, Value> __findLeft(int i, int tl, int tr, int R, Check checker, Value pref) {
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
                    Value _right = magic.apply(pref, __getValue(S[i].r, mid, tr));
                    if (checker.check(_right)) {
                        return __findLeft(S[i].r, mid, tr, R, checker, pref);
                    } else {
                        return __findLeft(S[i].l, tl, mid, R, checker, _right);
                    }
                } else {
                    Pair<Integer, Value> t = __findLeft(S[i].r, mid, tr, R, checker, pref);
                    if (t.getKey() != -1) return t;
                    return __findLeft(S[i].l, tl, mid, R, checker, t.getValue());
                }
            }
        }

        void init(List<Value> src) {
            n = src.size();
            S = new Node[2 * n + 1];
            init(0, 0, src.size(), src);
        }

        TreeSegment(int n, Value def, Magic<Value> magic, ApplyMod<Value, Mod> applyMod, MergeMods<Mod> mergeMods) {
            this.magic = magic;
            this.applyMod = applyMod;
            this.mergeMods = mergeMods;
            init(new ArrayList<>(Collections.nCopies(n, def)));
        }

        TreeSegment(List<Value> def, Magic<Value> magic, ApplyMod<Value, Mod> applyMod, MergeMods<Mod> mergeMods) {
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
            Pair<Integer, Value> rez = __findRight(0, 0, n, L, checker, start);
            return (rez.getKey() == -1) ? n : rez.getKey();
        }

        <Check> int findLeft(int R, Check checker, Value start) {
            if (checker.check(start)) return R + 1;
            Pair<Integer, Value> rez = __findLeft(0, 0, n, R, checker, start);
            return (rez.getKey() == -1) ? -1 : rez.getKey();
        }
    }

    static class Pair<K, V> {
        private final K key;
        private final V value;

        Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        K getKey() {
            return key;
        }

        V getValue() {
            return value;
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

        TreeSegment<Integer, Integer> ts = new TreeSegment<>(w, (a, b) -> a + b, (value, mod, tl, tr) -> mod, (old, _new, tl, tr) -> _new, 1337);

        int[] subw = new int[n];
        for (int i = 0; i < n; i++) {
            subw[i] = (w[i] * (i - pos[i])) % MOD;
        }

        TreeSegment<Integer, Integer> resp = new TreeSegment<>(Arrays.asList(subw), (a, b) -> (a + b) % MOD, (value, mod, tl, tr) -> mod, (old, _new, tl, tr) -> _new, 1337);

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