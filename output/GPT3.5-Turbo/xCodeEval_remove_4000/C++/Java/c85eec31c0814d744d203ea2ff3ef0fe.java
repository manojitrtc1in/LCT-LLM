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

        Node[] S;
        int n;
        Magic magic;
        ApplyMod applyMod;
        MergeMods mergeMods;

        boolean intersects(int tl, int tr, int ql, int qr) {
            return !(tr <= ql || qr <= tl);
        }

        Value getValue(int i, int tl, int tr) {
            if (!S[i].haveMod) return S[i].value;
            return applyMod.apply(S[i].value, S[i].mod, tl, tr);
        }

        void recalcValue(int i, int tl, int tr) {
            if (tl + 1 != tr) {
                int mid = (tl + tr) / 2;
                S[i].value = magic.apply(getValue(i + 1, tl, mid), getValue(i + (mid - tl) * 2, mid, tr));
            }
        }

        void addMod(int i, int tl, int tr, Mod sub) {
            if (S[i].haveMod) {
                S[i].mod = mergeMods.merge(S[i].mod, sub, tl, tr);
            } else {
                S[i].mod = sub;
                S[i].haveMod = true;
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

        public TreeSegment(int n, Value def, Magic magic, ApplyMod applyMod, MergeMods mergeMods, Mod mod) {
            this.magic = magic;
            this.applyMod = applyMod;
            this.mergeMods = mergeMods;
            this.n = n;
            S = new Node[2 * n + 1];
            for (int i = 0; i < 2 * n + 1; i++) {
                S[i] = new Node();
            }
            init(0, 0, n, Collections.nCopies(n, def));
        }

        public TreeSegment(List<Value> def, Magic magic, ApplyMod applyMod, MergeMods mergeMods, Mod mod) {
            this.magic = magic;
            this.applyMod = applyMod;
            this.mergeMods = mergeMods;
            this.n = def.size();
            S = new Node[2 * n + 1];
            for (int i = 0; i < 2 * n + 1; i++) {
                S[i] = new Node();
            }
            init(0, 0, n, def);
        }

        public Value query(int ql, int qr) {
            assert ql < qr;
            return __query(0, 0, n, ql, qr);
        }

        private Value __query(int i, int tl, int tr, int ql, int qr) {
            push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                return S[i].value;
            } else {
                int mid = (tl + tr) / 2;
                if (intersects(tl, mid, ql, qr) && intersects(mid, tr, ql, qr)) {
                    return magic.apply(
                            __query(i + 1, tl, mid, ql, qr),
                            __query(i + (mid - tl) * 2, mid, tr, ql, qr)
                    );
                } else if (intersects(tl, mid, ql, qr)) {
                    return __query(i + 1, tl, mid, ql, qr);
                } else {
                    return __query(i + (mid - tl) * 2, mid, tr, ql, qr);
                }
            }
        }

        public void change(int i, Value value) {
            assert 0 <= i && i < n;
            __change(0, 0, n, i, value);
        }

        private void __change(int i, int tl, int tr, int j, Value _new) {
            push(i, tl, tr);
            if (tl + 1 == tr) {
                S[i].value = _new;
            } else {
                int m = (tl + tr) / 2;
                if (j < m) {
                    __change(S[i].l, tl, m, j, _new);
                } else {
                    __change(S[i].r, m, tr, j, _new);
                }
                recalcValue(i, tl, tr);
            }
        }

        public void update(int ql, int qr, Mod mod) {
            __update(0, 0, n, ql, qr, mod);
        }

        private void __update(int i, int tl, int tr, int ql, int qr, Mod mod) {
            push(i, tl, tr);
            if (ql <= tl && tr <= qr) {
                __addMod(i, tl, tr, mod);
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

        private void __addMod(int i, int tl, int tr, Mod sub) {
            if (S[i].haveMod) {
                S[i].mod = mergeMods.merge(S[i].mod, sub, tl, tr);
            } else {
                S[i].mod = sub;
                S[i].haveMod = true;
            }
        }

        public int findRight(int L, Check checker, Value start) {
            if (checker.check(start)) return L - 1;
            Pair<Integer, Value> t = id0(0, 0, n, L, checker, start);
            return (t.first == -1) ? n : t.first;
        }

        public int findLeft(int R, Check checker, Value start) {
            if (checker.check(start)) return R + 1;
            Pair<Integer, Value> t = id3(0, 0, n, R, checker, start);
            return (t.first == -1) ? -1 : t.first;
        }

        interface Check {
            boolean check(Value value);
        }

        private Pair<Integer, Value> id0(int i, int tl, int tr, int L, Check checker, Value pref) {
            push(i, tl, tr);
            if (tr <= L) return new Pair<>(-1, pref);
            if (tl + 1 == tr) {
                Value _this = magic.apply(pref, getValue(i, tl, tr));
                if (checker.check(_this)) {
                    return new Pair<>(tl, _this);
                } else {
                    return new Pair<>(-1, _this);
                }
            } else {
                int mid = (tl + tr) / 2;
                if (L <= tl) {
                    Value _left = magic.apply(pref, getValue(i + 1, tl, mid));
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

        private Pair<Integer, Value> id3(int i, int tl, int tr, int R, Check checker, Value pref) {
            push(i, tl, tr);
            if (R < tl) return new Pair<>(-1, pref);
            if (tl + 1 == tr) {
                Value _this = magic.apply(pref, getValue(i, tl, tr));
                if (checker.check(_this)) {
                    return new Pair<>(tl, _this);
                } else {
                    return new Pair<>(-1, _this);
                }
            } else {
                int mid = (tl + tr) / 2;
                if (tr <= R + 1) {
                    Value _right = magic.apply(pref, getValue(S[i].r, mid, tr));
                    if (checker.check(_right)) {
                        return id3(S[i].r, mid, tr, R, checker, pref);
                    } else {
                        return id3(S[i].l, tl, mid, R, checker, _right);
                    }
                } else {
                    Pair<Integer, Value> t = id3(S[i].r, mid, tr, R, checker, pref);
                    if (t.first != -1) return t;
                    return id3(S[i].l, tl, mid, R, checker, t.second);
                }
            }
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

        TreeSegment<Integer, Integer> ts = new TreeSegment<>(n, 0, Integer::sum, (value, mod, tl, tr) -> mod, (a, b, tl, tr) -> b, 1337);

        List<Integer> subw = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            subw.add((w.get(i) * (i - pos.get(i))) % MOD);
        }

        TreeSegment<Integer, Integer> resp = new TreeSegment<>(subw, (a, b) -> (a + b) % MOD, (value, mod, tl, tr) -> mod, (old, _new, tl, tr) -> _new, 1337);

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
                int l = x;
                int r = y;
                l--;

                int sm = ts.query(l, r);

                int bestL = ts.findRight(l, (sm1) -> sm1 * 2 >= sm, 0);

                int x1 = pos.get(bestL) - bestL + l;

                int left = 0;
                if (l < bestL) {
                    left = resp.query(l, bestL) + ts.query(l, bestL) * (x1 - l);
                }
                int right = 0;
                if (bestL < r) {
                    right = resp.query(bestL, r) + ts.query(bestL, r) * (x1 - l);
                }
                System.out.println((left - right + MOD) % MOD);
            }
        }
    }
}
