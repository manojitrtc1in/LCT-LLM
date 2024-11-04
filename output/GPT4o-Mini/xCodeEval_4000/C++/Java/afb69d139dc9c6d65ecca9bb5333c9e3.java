import java.util.*;
import java.io.*;

public class afb69d139dc9c6d65ecca9bb5333c9e3_nc {
    static final int MAXN = 300000 + 42;
    static Random rand = new Random();
    static Treap root = new Treap(0, 0, 0);

    static class Treap {
        Treap left, right;
        long t, prefixSum, speed, push = 0, minPrefixSumInSubtree;

        Treap(long t, long val, long speed) {
            this.t = t;
            this.prefixSum = val;
            this.speed = speed;
            this.minPrefixSumInSubtree = val;
        }
    }

    static void vertexAdd(Treap a, long push) {
        a.prefixSum += push;
        a.minPrefixSumInSubtree += push;
        a.push += push;
    }

    static void push(Treap a) {
        long push = a.push;
        if (push == 0) return;
        if (a.left != null) {
            vertexAdd(a.left, push);
        }
        if (a.right != null) {
            vertexAdd(a.right, push);
        }
        a.push = 0;
    }

    static long smin(Treap a) {
        return a == null ? Long.MAX_VALUE : a.minPrefixSumInSubtree;
    }

    static void recalc(Treap a) {
        a.minPrefixSumInSubtree = Math.min(Math.min(smin(a.left), smin(a.right)), a.prefixSum);
    }

    static Treap merge(Treap a, Treap b) {
        if (a == null) return b;
        if (b == null) return a;
        if (a.y < b.y) {
            push(a);
            a.right = merge(a.right, b);
            recalc(a);
            return a;
        } else {
            push(b);
            b.left = merge(a, b.left);
            recalc(b);
            return b;
        }
    }

    static Pair<Treap, Treap> split(Treap a, long k) {
        if (a == null) return new Pair<>(a, a);
        push(a);
        if (a.t < k) {
            Pair<Treap, Treap> pair = split(a.right, k);
            a.right = pair.first;
            recalc(a);
            return new Pair<>(a, pair.second);
        } else {
            Pair<Treap, Treap> pair = split(a.left, k);
            a.left = pair.second;
            recalc(a);
            return new Pair<>(pair.first, a);
        }
    }

    static Treap getLeast(Treap a) {
        push(a);
        return a.left == null ? a : getLeast(a.left);
    }

    static Treap getGreatest(Treap a) {
        push(a);
        return a.right == null ? a : getGreatest(a.right);
    }

    static Treap findFirstLess(Treap a, long v) {
        push(a);
        if (smin(a.left) <= v) {
            return findFirstLess(a.left, v);
        }
        if (a.prefixSum <= v) return a;
        return findFirstLess(a.right, v);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st;

        root = merge(root, new Treap(2000000000, 0, 0));
        int q = Integer.parseInt(br.readLine());
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int type = Integer.parseInt(st.nextToken());
            if (type == 1) {
                long t = Long.parseLong(st.nextToken());
                long s = Long.parseLong(st.nextToken());
                Pair<Treap, Treap> pair = split(root, t);
                Treap vr = getLeast(pair.second);
                Treap vl = getGreatest(pair.first);
                long psum = vl.prefixSum + (t - vl.t) * vl.speed;
                long newPsum = psum + (vr.t - t) * s;
                vertexAdd(pair.second, newPsum - vr.prefixSum);
                root = merge(pair.first, merge(new Treap(t, psum, s), pair.second));
            } else if (type == 2) {
                long t = Long.parseLong(st.nextToken());
                Pair<Treap, Treap> pair = split(root, t);
                Pair<Treap, Treap> pair2 = split(pair.second, t + 1);
                Treap vl = getGreatest(pair.first);
                Treap vr = getLeast(pair2.second);
                long newPsum = vl.prefixSum + (vr.t - vl.t) * vl.speed;
                vertexAdd(pair2.second, newPsum - vr.prefixSum);
                root = merge(pair.first, pair2.second);
            } else {
                int L = Integer.parseInt(st.nextToken());
                int R = Integer.parseInt(st.nextToken());
                long v = Long.parseLong(st.nextToken());
                if (v == 0) {
                    out.println(L);
                    continue;
                }
                Pair<Treap, Treap> pair = split(root, L);
                Pair<Treap, Treap> pair2 = split(pair.second, R + 1);
                if (pair2.first == null) {
                    out.println(-1);
                } else {
                    Treap vl = getLeast(pair2.first);
                    Treap vr = getGreatest(pair2.first);
                    long searchingV = vl.prefixSum - v;
                    if (pair2.first.minPrefixSumInSubtree > searchingV) {
                        long newPsum = vr.prefixSum + (R - vr.t) * vr.speed;
                        if (newPsum > searchingV) {
                            out.println("-1");
                        } else {
                            out.println(vr.t + (double) (searchingV - vr.prefixSum) / vr.speed);
                        }
                    } else {
                        Treap h = findFirstLess(pair2.first, searchingV);
                        Pair<Treap, Treap> splitPair = split(pair2.first, h.t);
                        Treap vyl = getGreatest(splitPair.first);
                        out.println(vyl.t + (double) (searchingV - vyl.prefixSum) / vyl.speed);
                        pair2.first = merge(splitPair.first, splitPair.second);
                    }
                }
                root = merge(pair.first, merge(pair2.first, pair2.second));
            }
        }
        out.flush();
    }

    static class Pair<T, U> {
        T first;
        U second;

        Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    }
}
