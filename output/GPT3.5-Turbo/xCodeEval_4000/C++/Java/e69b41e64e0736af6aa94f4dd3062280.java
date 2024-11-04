import java.util.*;

class TreeSegment<Value, Mod> {
    class Node {
        boolean haveMod = false;
        int l = -1, r = -1;
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

    int __createNode() {
        S.add(new Node());
        return S.size() - 1;
    }

    Value __getValue(int i, int tl, int tr) {
        if (!S.get(i).haveMod) return S.get(i).value;
        return applyMod.apply(S.get(i).value, S.get(i).mod, tl, tr);
    }

    void __recalcValue(int i, int tl, int tr) {
        if (tl + 1 != tr) {
            int mid = (tl + tr) / 2;
            S.get(i).value = magic.apply(
                    __getValue(S.get(i).l, tl, mid),
                    __getValue(S.get(i).r, mid, tr)
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
                __addMod(S.get(i).l, tl, mid, S.get(i).mod);
                __addMod(S.get(i).r, mid, tr, S.get(i).mod);
            }
            S.get(i).haveMod = false;
        }
    }

    int init(int tl, int tr, List<Value> src) {
        int i = __createNode();
        if (tl + 1 == tr) {
            S.get(i).value = src.get(tl);
        } else {
            int mid = (tl + tr) / 2;
            S.get(i).l = init(tl, mid, src);
            S.get(i).r = init(mid, tr, src);
            __recalcValue(i, tl, tr);
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
            __addMod(i, tl, tr, mod);
        } else {
            int mid = (tl + tr) / 2;
            if (__intersects(tl, mid, ql, qr)) {
                __update(S.get(i).l, tl, mid, ql, qr, mod);
            }
            if (__intersects(mid, tr, ql, qr)) {
                __update(S.get(i).r, mid, tr, ql, qr, mod);
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
                Value _left = magic.apply(pref, __getValue(S.get(i).l, tl, mid));
                if (checker.check(_left)) {
                    return __findRight(S.get(i).l, tl, mid, L, checker, pref);
                } else {
                    return __findRight(S.get(i).r, mid, tr, L, checker, _left);
                }
            } else {
                Pair<Integer, Value> t = __findRight(S.get(i).l, tl, mid, L, checker, pref);
                if (t.getKey() != -1) return t;
                return __findRight(S.get(i).r, mid, tr, L, checker, t.getValue());
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
                Value _right = magic.apply(pref, __getValue(S.get(i).r, mid, tr));
                if (checker.check(_right)) {
                    return __findLeft(S.get(i).r, mid, tr, R, checker, pref);
                } else {
                    return __findLeft(S.get(i).l, tl, mid, R, checker, _right);
                }
            } else {
                Pair<Integer, Value> t = __findLeft(S.get(i).r, mid, tr, R, checker, pref);
                if (t.getKey() != -1) return t;
                return __findLeft(S.get(i).l, tl, mid, R, checker, t.getValue());
            }
        }
    }

    void init(List<Value> src) {
        n = src.size();
        init(0, src.size(), src);
    }

    TreeSegment(int n, Value def, Magic magic, ApplyMod applyMod, MergeMods mergeMods, Mod mod) {
        this.magic = magic;
        this.applyMod = applyMod;
        this.mergeMods = mergeMods;
        init(new ArrayList<>(Collections.nCopies(n, def)));
    }

    TreeSegment(List<Value> def, Magic magic, ApplyMod applyMod, MergeMods mergeMods, Mod mod) {
        this.magic = magic;
        this.applyMod = applyMod;
        this.mergeMods = mergeMods;
        init(def);
    }

    Value query(int ql, int qr) {
        return __query(0, 0, n, ql, qr);
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

class Pair<K, V> {
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

class Main {
    static int n, q;
    static List<Integer> pos;
    static List<Integer> w;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        q = scanner.nextInt();
        pos = new ArrayList<>(n);
        w = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            pos.add(scanner.nextInt());
        }
        for (int i = 0; i < n; i++) {
            w.add(scanner.nextInt());
        }

        TreeSegment<Integer, Integer> ts = new TreeSegment<>(w, (a, b) -> a + b,
                (value, mod, tl, tr) -> mod,
                (old, _new, tl, tr) -> _new,
                1337);

        List<Integer> subw = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            subw.add((w.get(i) * (i - pos.get(i))) % MOD);
        }

        TreeSegment<Integer, Integer> resp = new TreeSegment<>(subw, (a, b) -> (a + b) % MOD,
                (value, mod, tl, tr) -> mod,
                (old, _new, tl, tr) -> _new,
                1337);

        for (int i = 0; i < q; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
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

                int bestL = ts.findRight(l, x -> x * 2 >= sm, 0);

                int x = pos.get(bestL) - bestL + l;

                int left = 0;
                if (l < bestL) {
                    left = resp.query(l, bestL) + ts.query(l, bestL) * (x - l);
                }
                int right = 0;
                if (bestL < r) {
                    right = resp.query(bestL, r) + ts.query(bestL, r) * (x - l);
                }
                System.out.println(floorMod(left - right, MOD));
            }
        }
    }

    static final int MOD = 1_000_000_007;

    static int floorMod(int a, int b) {
        if (a % b == 0) return 0;
        if (a >= 0 && b >= 0) return a % b;
        if (a <= 0 && b <= 0) return a % b;
        return Math.abs(b) - (Math.abs(a) % Math.abs(b));
    }
}
