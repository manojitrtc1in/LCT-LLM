import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    static final long MOD = (long) 1e9 + 7;

    static class Modll {
        private long val;

        private long modify(long x) {
            long ret = x % MOD;
            if (ret < 0) ret += MOD;
            return ret;
        }

        private long inv(long x) {
            if (x == 0) return 1 / x;
            else if (x == 1) return 1;
            else return modify(inv(MOD % x) * modify(-MOD / x));
        }

        Modll(long init) {
            val = modify(init);
        }

        Modll(Modll another) {
            val = another.val;
        }

        Modll add(Modll x) {
            return new Modll(modify(val + x.val));
        }

        Modll sub(Modll x) {
            return new Modll(modify(val - x.val));
        }

        Modll mul(Modll x) {
            return new Modll(modify(val * x.val));
        }

        Modll div(Modll x) {
            return new Modll(modify(val * inv(x.val)));
        }

        long getVal() {
            return val;
        }

        public String toString() {
            return Long.toString(val);
        }
    }

    static class SegTree<T> {
        private int n, N, base;
        private List<T> nodes;

        SegTree(int n, T init) {
            this.n = n;
            N = (int) Math.pow(2, Math.ceil(Math.log(n) / Math.log(2)));
            base = N - 1;
            nodes = new ArrayList<>(Collections.nCopies(base + N, init));
        }

        private int leftOf(int index) {
            return index >= base ? -1 : index * 2 + 1;
        }

        private int rightOf(int index) {
            return index >= base ? -1 : index * 2 + 2;
        }

        private int parentOf(int index) {
            return index == 0 ? -1 : (index - 1) >> 1;
        }

        private void updateRec(int s, int t, int l, int r, int index, T v) {
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
                nodes.set(index, (T) ((Long) nodes.get(indexL) + (Long) nodes.get(indexR)));
            }
        }

        private T addRec(int s, int t, int l, int r, int index) {
            if (s == l && t == r) {
                return nodes.get(index);
            } else {
                int mid = (l + r) / 2;
                int indexL = leftOf(index);
                int indexR = rightOf(index);
                long v0 = 0, v1 = 0;
                if (s < mid && mid < t) {
                    v0 = (Long) addRec(s, mid, l, mid, indexL);
                    v1 = (Long) addRec(mid, t, mid, r, indexR);
                } else if (s < mid) {
                    v0 = (Long) addRec(s, t, l, mid, indexL);
                } else if (mid < t) {
                    v1 = (Long) addRec(s, t, mid, r, indexR);
                }
                return (T) (Long) (v0 + v1);
            }
        }

        void update(int k, T v) {
            updateRec(k, k + 1, 0, N, 0, v);
        }

        T sum(int s, int t) {
            return addRec(s, t, 0, N, 0);
        }
    }

    static class Bsargv {
        SegTree<Long> st;
        int s;
        long sum;
    }

    static boolean evalFunc(int val, Bsargv v) {
        long buf = v.st.sum(v.s, val + 1);
        return buf <= v.sum / 2;
    }

    static long discLog(Modll a, Modll b) {
        long ret = -1;
        long m = (long) Math.sqrt(MOD);
        Map<Long, Long> mp = new HashMap<>();
        Modll x = new Modll(1);
        for (long i = 0; i < m; i++) {
            mp.put(x.getVal(), i);
            x = x.mul(a);
        }
        x = new Modll(1).div(pow(a, m));
        Modll k = b;
        for (long i = 0; i < m; i++) {
            if (!mp.containsKey(k.getVal())) {
                k = k.mul(x);
            } else {
                ret = i * m + mp.get(k.getVal());
                break;
            }
        }
        return ret;
    }

    static Modll pow(Modll n, long p) {
        Modll ret = new Modll(0);
        if (p == 0) ret = new Modll(1);
        else if (p == 1) ret = n;
        else {
            ret = pow(n, p / 2);
            ret = ret.mul(ret);
            if (p % 2 == 1) ret = ret.mul(n);
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        long[] a = new long[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Long.parseLong(st.nextToken());
        }
        SegTree<Long> stree = new SegTree<>(n, 0L);
        SegTree<Modll> astree = new SegTree<>(n, new Modll(0));
        SegTree<Modll> lstree = new SegTree<>(n, new Modll(0));
        SegTree<Modll> rstree = new SegTree<>(n, new Modll(0));
        for (int i = 0; i < n; i++) {
            long w = Long.parseLong(br.readLine());
            stree.update(i, w);
            astree.update(i, new Modll(w).mul(new Modll(a[i])));
            lstree.update(i, new Modll(w).mul(n - 1 - i));
            rstree.update(i, new Modll(w).mul(i));
        }
        List<Modll> ans = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            if (x < 0) {
                x++;
                long y = Long.parseLong(st.nextToken());
                stree.update(-x, y);
                astree.update(-x, new Modll(y).mul(new Modll(a[-x])));
                lstree.update(-x, new Modll(y).mul(n - 1 - (-x)));
                rstree.update(-x, new Modll(y).mul(-x));
            } else {
                int y = Integer.parseInt(st.nextToken());
                x--;
                y--;
                if (x == y) {
                    ans.add(new Modll(0));
                } else {
                    int halfid;
                    if (y - x == 1) {
                        halfid = x;
                    } else {
                        Bsargv v = new Bsargv();
                        v.st = stree;
                        v.s = x;
                        v.sum = stree.sum(x, y + 1);
                        halfid = id4(x + 1, y, v, Main::evalFunc);
                    }
                    long cand0 = stree.sum(x, halfid + 1);
                    long cand1 = stree.sum(halfid + 1, y + 1);
                    long dst;
                    int dstid;
                    if (cand0 <= cand1) {
                        dst = a[halfid + 1];
                        dstid = halfid + 1;
                    } else {
                        dst = a[halfid];
                        dstid = halfid;
                    }
                    Modll buf = new Modll(0);
                    buf = buf.add(new Modll(dst).mul(stree.sum(x, dstid)).sub(astree.sum(x, dstid)).sub(lstree.sum(x, dstid).sub(new Modll(stree.sum(x, dstid)).mul(n - 1 - dstid))));
                    buf = buf.add(astree.sum(dstid, y + 1).sub(new Modll(dst).mul(stree.sum(dstid, y + 1))).sub(rstree.sum(dstid, y + 1).sub(new Modll(stree.sum(dstid, y + 1)).mul(dstid))));
                    ans.add(buf);
                }
            }
        }
        for (Modll modll : ans) {
            System.out.println(modll);
        }
    }

    static <T> int id4(int l, int r, Bsargv v, BiPredicate<Integer, Bsargv> evalFunc) {
        if (r - l == 1) {
            return evalFunc.test(l, v) ? l : l - 1;
        }
        int m = (l + r) / 2;
        if (evalFunc.test(m, v)) return id4(m, r, v, evalFunc);
        else return id4(l, m, v, evalFunc);
    }
}
