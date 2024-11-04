import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static class SegTree<T> {
        protected int n, N;

        int base;
        ArrayList<T> nodes;

        int leftOf(int index) {
            if (index >= base) return -1;
            else return index * 2 + 1;
        }

        int rightOf(int index) {
            if (index >= base) return -1;
            else return index * 2 + 2;
        }

        int parentOf(int index) {
            if (index == 0) return -1;
            else return (index - 1) >> 1;
        }

        void updateRec(int s, int t, int l, int r, int index, T v) {
            if (s == l && t == r) {
                nodes.set(index, v);
            } else {
                int mid = (l + r) / 2;
                int indexL = leftOf(index);
                int indexR = rightOf(index);
                if (s < mid && mid < t) {
                    updateRec(s, mid, l, mid, indexL, v);
                    updateRec(mid, t, mid, r, indexR, v);
                } else if (s < mid) {
                    updateRec(s, t, l, mid, indexL, v);
                } else if (mid < t) {
                    updateRec(s, t, mid, r, indexR, v);
                }
                nodes.set(index, nodes.get(indexL) + nodes.get(indexR));
            }
        }

        T addRec(int s, int t, int l, int r, int index) {
            if (s == l && t == r) {
                return nodes.get(index);
            } else {
                int mid = (l + r) / 2;
                int indexL = leftOf(index);
                int indexR = rightOf(index);
                T v0 = null, v1 = null;
                if (s < mid && mid < t) {
                    v0 = addRec(s, mid, l, mid, indexL);
                    v1 = addRec(mid, t, mid, r, indexR);
                } else if (s < mid) {
                    v0 = addRec(s, t, l, mid, indexL);
                } else if (mid < t) {
                    v1 = addRec(s, t, mid, r, indexR);
                }
                return v0 + v1;
            }
        }

        public SegTree(int n, T init) {
            this.n = n;
            N = (int) Math.pow(2, Math.ceil(Math.log(n) / Math.log(2)));
            base = N - 1;
            nodes = new ArrayList<>(Collections.nCopies(base + N, init));
        }

        ArrayList<Integer> getIndexAbove(int index, boolean fromBase) {
            if (fromBase) index += base;
            ArrayList<Integer> ret = new ArrayList<>();
            while (index >= 0) {
                ret.add(index);
                index = parentOf(index);
            }
            return ret;
        }

        int coverSize(int index) {
            int cnt = 1;
            while (leftOf(index) != -1) {
                index = leftOf(index);
                cnt *= 2;
            }
            int l = index - base;
            int r = Math.min(l + cnt, n);
            return Math.max(0, r - l);
        }

        void update(int k, T v) {
            updateRec(k, k + 1, 0, N, 0, v);
        }

        T sum(int s, int t) {
            return addRec(s, t, 0, N, 0);
        }
    }

    static class bsargv_t {
        SegTree<Long> st;
        int s;
        long sum;

        bsargv_t(SegTree<Long> st, int s, long sum) {
            this.st = st;
            this.s = s;
            this.sum = sum;
        }
    }

    static boolean evalfunc(int val, bsargv_t v) {
        long buf = v.st.sum(v.s, val + 1);
        if (buf <= v.sum / 2) return true;
        else return false;
    }

    static class modll {
        static final long MOD = (long) 1e9 + 7;

        long val;

        modll(long init) {
            val = modify(init);
        }

        modll(modll another) {
            val = another.val;
        }

        modll add(modll x) {
            return modify(val + x.val);
        }

        modll subtract(modll x) {
            return modify(val - x.val);
        }

        modll multiply(modll x) {
            return modify(val * x.val);
        }

        modll divide(modll x) {
            return modify(val * inv(x.val));
        }

        modll modify(long x) {
            long ret = x % MOD;
            if (ret < 0) ret += MOD;
            return new modll(ret);
        }

        long inv(long x) {
            if (x == 0) return 1 / x;
            else if (x == 1) return 1;
            else return modify(inv(MOD % x) * modify(-MOD / x)).val;
        }

        public modll clone() {
            return new modll(val);
        }

        public boolean equals(modll x) {
            return val == x.val;
        }

        public boolean notEquals(modll x) {
            return val != x.val;
        }

        public String toString() {
            return Long.toString(val);
        }

        long getVal() {
            return val;
        }
    }

    static modll pow(modll n, long p) {
        modll ret;
        if (p == 0) ret = new modll(1);
        else if (p == 1) ret = n.clone();
        else {
            ret = pow(n, p / 2);
            ret.multiply(ret);
            if (p % 2 == 1) ret.multiply(n);
        }
        return ret;
    }

    static ArrayList<modll> facts = new ArrayList<>();

    static void makeFacts(int n) {
        if (facts.isEmpty()) facts.add(new modll(1));
        for (int i = facts.size(); i <= n; ++i) facts.add(new modll(facts.get(i - 1).multiply(new modll(i))));
    }

    static ArrayList<modll> ifacts = new ArrayList<>();
    static ArrayList<modll> invs = new ArrayList<>();

    static void makeInvs(int n) {
        if (invs.isEmpty()) {
            invs.add(new modll(0));
            invs.add(new modll(1));
        }
        for (int i = invs.size(); i <= n; ++i) {
            invs.add(invs.get((int) (MOD % i)).multiply(new modll(MOD - MOD / i)));
        }
    }

    static void makeIfacts(int n) {
        makeInvs(n);
        if (ifacts.isEmpty()) ifacts.add(new modll(1));
        for (int i = ifacts.size(); i <= n; ++i) ifacts.add(new modll(ifacts.get(i - 1).multiply(invs.get(i))));
    }

    static modll combination(long n, long r) {
        if (n >= r && r >= 0) {
            modll ret;
            makeFacts((int) n);
            makeIfacts((int) n);
            ret = facts.get((int) n).multiply(ifacts.get((int) r)).multiply(ifacts.get((int) (n - r)));
            return ret;
        } else return new modll(0);
    }

    static modll getFact(long n) {
        makeFacts((int) n);
        return facts.get((int) n);
    }

    static modll getIfact(long n) {
        makeIfacts((int) n);
        return ifacts.get((int) n);
    }

    static long discLog(modll a, modll b) {
        long ret = -1;
        long m = (long) Math.ceil(Math.sqrt(MOD));
        HashMap<Long, Long> mp = new HashMap<>();
        modll x = new modll(1);
        for (int i = 0; i < m; i++) {
            mp.put(x.getVal(), (long) i);
            x.multiply(a);
        }
        x = new modll(1).divide(pow(a, m));
        modll k = b.clone();
        for (int i = 0; i < m; i++) {
            if (!mp.containsKey(k.getVal())) k.multiply(x);
            else {
                ret = i * m + mp.get(k.getVal());
                break;
            }
        }
        return ret;
    }

    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().trim().split("\\s+");
        int n = Integer.parseInt(input[0]);
        int q = Integer.parseInt(input[1]);
        ArrayList<Long> a = new ArrayList<>();
        input = br.readLine().trim().split("\\s+");
        for (int i = 0; i < n; i++) {
            a.add(Long.parseLong(input[i]));
        }
        SegTree<Long> st = new SegTree<>(n, 0L);
        SegTree<modll> ast = new SegTree<>(n, new modll(0));
        SegTree<modll> lst = new SegTree<>(n, new modll(0));
        SegTree<modll> rst = new SegTree<>(n, new modll(0));
        input = br.readLine().trim().split("\\s+");
        for (int i = 0; i < n; i++) {
            long w = Long.parseLong(input[i]);
            st.update(i, w);
            ast.update(i, new modll(w).multiply(new modll(a.get(i))));
            lst.update(i, new modll(w).multiply(new modll(n - 1 - i)));
            rst.update(i, new modll(w).multiply(new modll(i)));
        }
        ArrayList<modll> ans = new ArrayList<>();
        for (int unused = 0; unused < q; unused++) {
            input = br.readLine().trim().split("\\s+");
            int x = Integer.parseInt(input[0]);
            if (x < 0) {
                x++;
                long y = Long.parseLong(input[1]);
                st.update(-x, y);
                ast.update(-x, new modll(y).multiply(new modll(a.get(-x))));
                lst.update(-x, new modll(y).multiply(new modll(n - 1 - (-x))));
                rst.update(-x, new modll(y).multiply(new modll(-x)));
            } else {
                int y = Integer.parseInt(input[1]);
                x--;
                y--;
                if (x == y) {
                    ans.add(new modll(0));
                } else {
                    int halfId;
                    if (y - x == 1) {
                        halfId = x;
                    } else {
                        bsargv_t v = new bsargv_t(st, x, st.sum(x, y + 1));
                        halfId = lowerBinarySearch(x + 1, y, v, Main::evalfunc);
                    }
                    long cand0 = st.sum(x, halfId + 1);
                    long cand1 = st.sum(halfId + 1, y + 1);
                    long dst;
                    int dstId;
                    if (cand0 <= cand1) {
                        dst = a.get(halfId + 1);
                        dstId = halfId + 1;
                    } else {
                        dst = a.get(halfId);
                        dstId = halfId;
                    }
                    modll buf = new modll(0);
                    buf.add(new modll(dst).multiply(st.sum(x, dstId))).subtract(ast.sum(x, dstId)).subtract(lst.sum(x, dstId).subtract(new modll(st.sum(x, dstId)).multiply(new modll(n - 1 - dstId)))));
                    buf.add(ast.sum(dstId, y + 1).subtract(new modll(dst).multiply(st.sum(dstId, y + 1))).subtract(rst.sum(dstId, y + 1).subtract(new modll(st.sum(dstId, y + 1)).multiply(new modll(dstId))))));
                    ans.add(buf);
                }
            }
        }
        for (modll val : ans) {
            System.out.println(val);
        }
    }

    static int lowerBinarySearch(int l, int r, bsargv_t v, BiFunction<Integer, bsargv_t, Boolean> evalFunc) {
        if (r - l == 1) {
            if (evalFunc.apply(l, v)) return l;
            else return l - 1;
        }
        int m = (l + r) / 2;
        if (evalFunc.apply(m, v)) return lowerBinarySearch(m, r, v, evalFunc);
        else return lowerBinarySearch(l, m, v, evalFunc);
    }
}
