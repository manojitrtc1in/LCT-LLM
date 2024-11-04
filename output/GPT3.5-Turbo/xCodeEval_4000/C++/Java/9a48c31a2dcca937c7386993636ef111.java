import java.util.*;

class Main {
    static class TreeSegment<Value, Mod> {
        class Node {
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

        boolean intersects(int tl, int tr, int ql, int qr) {
            return !(tr <= ql || qr <= tl);
        }

        Value getValue(int i, int tl, int tr) {
            if (!S.get(i).haveMod) return S.get(i).value;
            return applyMod.apply(S.get(i).value, S.get(i).mod, tl, tr);
        }

        void recalcValue(int i, int tl, int tr) {
            if (tl + 1 != tr) {
                int mid = (tl + tr) / 2;
                S.get(i).value = magic.apply(getValue(i + 1, tl, mid), getValue(i + (mid - tl) * 2, mid, tr));
            }
        }

        void addMod(int i, int tl, int tr, Mod sub) {
            if (S.get(i).haveMod) {
                S.get(i).mod = mergeMods.merge(S.get(i).mod, sub, tl, tr);
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
                    addMod(i + 1, tl, mid, S.get(i).mod);
                    addMod(i + (mid - tl) * 2, mid, tr, S.get(i).mod);
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
                recalcValue(i, tl, tr);
            }
        }

        Value query(int i, int tl, int tr, int ql, int qr) {
            push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                return S.get(i).value;
            } else {
                int mid = (tl + tr) / 2;
                if (intersects(tl, mid, ql, qr) && intersects(mid, tr, ql, qr)) {
                    return magic.apply(query(i + 1, tl, mid, ql, qr), query(i + (mid - tl) * 2, mid, tr, ql, qr));
                } else if (intersects(tl, mid, ql, qr)) {
                    return query(i + 1, tl, mid, ql, qr);
                } else {
                    return query(i + (mid - tl) * 2, mid, tr, ql, qr);
                }
            }
        }

        void change(int i, Value value) {
            push(0, 0, n, i, value);
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

        Pair<Integer, Value> findRight(int i, int tl, int tr, int L, Predicate<Value> checker, Value pref) {
            push(i, tl, tr);
            if (tr <= L) return new Pair<>(-1, pref);
            if (tl + 1 == tr) {
                Value _this = magic.apply(pref, getValue(i, tl, tr));
                if (checker.test(_this)) {
                    return new Pair<>(tl, _this);
                } else {
                    return new Pair<>(-1, _this);
                }
            } else {
                int mid = (tl + tr) / 2;
                if (L <= tl) {
                    Value _left = magic.apply(pref, getValue(i + 1, tl, mid));
                    if (checker.test(_left)) {
                        return findRight(i + 1, tl, mid, L, checker, pref);
                    } else {
                        return findRight(i + (mid - tl) * 2, mid, tr, L, checker, _left);
                    }
                } else {
                    Pair<Integer, Value> t = findRight(i + 1, tl, mid, L, checker, pref);
                    if (t.getKey() != -1) return t;
                    return findRight(i + (mid - tl) * 2, mid, tr, L, checker, t.getValue());
                }
            }
        }

        Pair<Integer, Value> findLeft(int i, int tl, int tr, int R, Predicate<Value> checker, Value pref) {
            push(i, tl, tr);
            if (R < tl) return new Pair<>(-1, pref);
            if (tl + 1 == tr) {
                Value _this = magic.apply(pref, getValue(i, tl, tr));
                if (checker.test(_this)) {
                    return new Pair<>(tl, _this);
                } else {
                    return new Pair<>(-1, _this);
                }
            } else {
                int mid = (tl + tr) / 2;
                if (tr <= R + 1) {
                    Value _right = magic.apply(pref, getValue(S.get(i).r, mid, tr));
                    if (checker.test(_right)) {
                        return findLeft(S.get(i).r, mid, tr, R, checker, pref);
                    } else {
                        return findLeft(S.get(i).l, tl, mid, R, checker, _right);
                    }
                } else {
                    Pair<Integer, Value> t = findLeft(S.get(i).r, mid, tr, R, checker, pref);
                    if (t.getKey() != -1) return t;
                    return findLeft(S.get(i).l, tl, mid, R, checker, t.getValue());
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
            init(new ArrayList<>(Collections.nCopies(n, def)));
        }

        TreeSegment(List<Value> def, Magic magic, ApplyMod applyMod, MergeMods mergeMods, Mod mod) {
            this.magic = magic;
            this.applyMod = applyMod;
            this.mergeMods = mergeMods;
            init(def);
        }

        Value query(int ql, int qr) {
            return query(0, 0, n, ql, qr);
        }
    }

    static int floorMod(int a, int b) {
        if (a % b == 0) return 0;
        if (a >= 0 && b >= 0) return a % b;
        if (a <= 0 && b <= 0) return a % b;
        return Math.abs(b) - (Math.abs(a) % Math.abs(b));
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
                (old, _new, tl, tr) -> _new,
                1337);

        List<Integer> subw = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            subw.add((w[i] * (i - pos[i])) % MOD);
        }

        TreeSegment<Integer, Integer> resp = new TreeSegment<>(subw,
                (a, b) -> (a + b) % MOD,
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
                resp.update(ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
            } else {
                int l = x;
                int r = y;
                l--;

                int sm = ts.query(l, r);

                int bestL = ts.findRight(l, x -> x * 2 >= sm, 0);

                int x = pos[bestL] - bestL + l;

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
}
