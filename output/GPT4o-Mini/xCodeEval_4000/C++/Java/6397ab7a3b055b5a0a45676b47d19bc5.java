import java.util.*;
import java.io.*;

class SegTree<T> {
    protected int n, N;
    int base;
    List<T> nodes;

    public SegTree(int n, T init) {
        this.n = n;
        N = (int) Math.pow(2, Math.ceil(Math.log(n) / Math.log(2)));
        base = N - 1;
        nodes = new ArrayList<>(Collections.nCopies(base + N, init));
    }

    int left_of(int index) {
        return index >= base ? -1 : index * 2 + 1;
    }

    int right_of(int index) {
        return index >= base ? -1 : index * 2 + 2;
    }

    int parent_of(int index) {
        return index == 0 ? -1 : (index - 1) >> 1;
    }

    void update_rec(int s, int t, int l, int r, int index, T v) {
        if (s == l && t == r) {
            nodes.set(index, v);
        } else {
            int mid = (l + r) / 2;
            int index_l = left_of(index);
            int index_r = right_of(index);
            if (s < mid && mid < t) {
                update_rec(s, mid, l, mid, index_l, v);
                update_rec(mid, t, mid, r, index_r, v);
            } else if (s < mid) {
                update_rec(s, t, l, mid, index_l, v);
            } else if (mid < t) {
                update_rec(s, t, mid, r, index_r, v);
            }
            nodes.set(index, (T) ((Long) nodes.get(index_l) + (Long) nodes.get(index_r)));
        }
    }

    T add_rec(int s, int t, int l, int r, int index) {
        if (s == l && t == r) {
            return nodes.get(index);
        } else {
            int mid = (l + r) / 2;
            int index_l = left_of(index);
            int index_r = right_of(index);
            T v0 = (T) Long.valueOf(0), v1 = (T) Long.valueOf(0);
            if (s < mid && mid < t) {
                v0 = add_rec(s, mid, l, mid, index_l);
                v1 = add_rec(mid, t, mid, r, index_r);
            } else if (s < mid) {
                v0 = add_rec(s, t, l, mid, index_l);
            } else if (mid < t) {
                v1 = add_rec(s, t, mid, r, index_r);
            }
            return (T) ((Long) v0 + (Long) v1);
        }
    }

    void update(int k, T v) {
        update_rec(k, k + 1, 0, N, 0, v);
    }

    T sum(int s, int t) {
        return add_rec(s, t, 0, N, 0);
    }
}

class Modll {
    private static final long MOD = (long) 1e9 + 7;
    private long val;

    public Modll(long init) {
        val = modify(init);
    }

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

    public Modll add(Modll x) {
        return new Modll(modify(val + x.val));
    }

    public Modll subtract(Modll x) {
        return new Modll(modify(val - x.val));
    }

    public Modll multiply(Modll x) {
        return new Modll(modify(val * x.val));
    }

    public Modll divide(Modll x) {
        return new Modll(modify(val * inv(x.val)));
    }

    public long getVal() {
        return val;
    }

    public static Modll pow(Modll n, long p) {
        Modll ret = new Modll(0);
        if (p == 0) ret = new Modll(1);
        else if (p == 1) ret = n;
        else {
            ret = pow(n, p / 2);
            ret = ret.multiply(ret);
            if (p % 2 == 1) ret = ret.multiply(n);
        }
        return ret;
    }
}

class Bsargv {
    SegTree<Long> st;
    int s;
    long sum;

    Bsargv(SegTree<Long> st, int s, long sum) {
        this.st = st;
        this.s = s;
        this.sum = sum;
    }
}

public class 6397ab7a3b055b5a0a45676b47d19bc5_nc {
    static boolean evalfunc(int val, Bsargv v) {
        long buf = v.st.sum(v.s, val + 1);
        return buf <= v.sum / 2;
    }

    static long lowerBinarySearch(long l, long r, Bsargv v) {
        if (r - l == 1) {
            return evalfunc((int) l, v) ? l : l - 1;
        }
        long m = (l + r) / 2;
        if (evalfunc((int) m, v)) return lowerBinarySearch(m, r, v);
        else return lowerBinarySearch(l, m, v);
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
            astree.update(i, new Modll(w).multiply(new Modll(a[i])));
            lstree.update(i, new Modll(w).multiply(new Modll(n - 1 - i)));
            rstree.update(i, new Modll(w).multiply(new Modll(i)));
        }
        List<Modll> ans = new ArrayList<>();
        for (int unused = 0; unused < q; unused++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            if (x < 0) {
                x++;
                long y = Long.parseLong(st.nextToken());
                stree.update(-x, y);
                astree.update(-x, new Modll(y).multiply(new Modll(a[-x])));
                lstree.update(-x, new Modll(y).multiply(new Modll(n - 1 - (-x))));
                rstree.update(-x, new Modll(y).multiply(new Modll(-x)));
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
                        Bsargv v = new Bsargv(stree, x, stree.sum(x, y + 1));
                        halfid = (int) lowerBinarySearch(x + 1, y, v);
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
                    buf = buf.add(new Modll(dst).multiply(new Modll(stree.sum(x, dstid)))
                            .subtract(astree.sum(x, dstid))
                            .subtract(lstree.sum(x, dstid).subtract(new Modll(stree.sum(x, dstid)).multiply(new Modll(n - 1 - dstid)))));
                    buf = buf.add(astree.sum(dstid, y + 1)
                            .subtract(new Modll(dst).multiply(stree.sum(dstid, y + 1)))
                            .subtract(rstree.sum(dstid, y + 1).subtract(new Modll(stree.sum(dstid, y + 1)).multiply(new Modll(dstid)))));
                    ans.add(buf);
                }
            }
        }
        for (Modll modll : ans) {
            System.out.println(modll.getVal());
        }
    }
}
