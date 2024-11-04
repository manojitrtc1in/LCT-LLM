import java.util.*;
import java.io.*;

public class dc37cd46e578d29248104389008598aa_nc {
    static int[] x = new int[101010];
    static int[] a = new int[101010];
    static List<Pair> v[] = new ArrayList[2];
    static int w;

    static {
        v[0] = new ArrayList<>();
        v[1] = new ArrayList<>();
    }

    static class F implements Comparable<F> {
        int p, q;

        public int compareTo(F f) {
            return Long.compare((long) p * f.q, (long) f.p * q);
        }

        public boolean equals(F f) {
            return (long) p * f.q == (long) f.p * q;
        }
    }

    static class Fenw {
        int[] tr = new int[202020];

        void add(int pos) {
            for (int i = pos; i <= 200020; i |= i + 1) {
                tr[i]++;
            }
        }

        int sum(int pos) {
            int res = 0;
            for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
                res += tr[i];
            }
            return res;
        }

        int sum(int l, int r) {
            return sum(r) - sum(l - 1);
        }
    }

    static Fenw f1 = new Fenw();
    static Fenw[] f = new Fenw[2];

    static {
        f[0] = new Fenw();
        f[1] = new Fenw();
    }

    static long solve1(List<Pair> v) {
        List<F> allF = new ArrayList<>();
        for (Pair p : v) {
            F from = new F();
            from.p = p.first;
            from.q = p.second + w;
            F to = new F();
            to.p = p.first;
            to.q = p.second - w;
            allF.add(from);
            allF.add(to);
        }
        allF.add(new F());
        allF.get(allF.size() - 1).p = 0;
        allF.get(allF.size() - 1).q = 1;
        Collections.sort(allF);
        reunique(allF);
        for (Pair p : v) {
            F from = new F();
            from.p = p.first;
            from.q = p.second + w;
            F to = new F();
            to.p = p.first;
            to.q = p.second - w;
            p.first = lowerBound(allF, from);
            p.second = lowerBound(allF, to);
        }
        Collections.sort(v, (p1, p2) -> p1.first != p2.first ? Integer.compare(p1.first, p2.first) : Integer.compare(p2.second, p1.second));
        long res = 0;
        Arrays.fill(f1.tr, 0);
        for (int i = 0; i < v.size(); i++) {
            res += i - f1.sum(v.get(i).second - 1);
            f1.add(v.get(i).second);
        }
        return res;
    }

    static long solve2(List<Pair>[] v) {
        List<F> allF = new ArrayList<>();
        for (int i = 0; i < 2; i++) {
            for (Pair p : v[i]) {
                F from = new F();
                from.p = p.first;
                from.q = p.second + w;
                F to = new F();
                to.p = p.first;
                to.q = p.second - w;
                allF.add(from);
                allF.add(to);
            }
        }
        allF.add(new F());
        allF.get(allF.size() - 1).p = 0;
        allF.get(allF.size() - 1).q = 1;
        Collections.sort(allF);
        long res = 0;
        for (int i = 0; i < 2; i++) {
            for (Pair p : v[i]) {
                F from = new F();
                from.p = p.first;
                from.q = p.second + w;
                F to = new F();
                to.p = p.first;
                to.q = p.second - w;
                p.first = lowerBound(allF, from);
                p.second = lowerBound(allF, to);
                f[i].add(p.first);
            }
        }

        for (Pair p : v[0]) {
            res += f[1].sum(p.first, p.second);
        }
        for (Pair p : v[1]) {
            res += f[0].sum(p.first + 1, p.second);
        }
        return res;
    }

    static long solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        w = sc.nextInt();
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextInt();
            a[i] = sc.nextInt();
            v[x[i] < 0 ? 0 : 1].add(new Pair(Math.abs(x[i]), Math.abs(a[i])));
        }
        long ans = 0;
        ans += solve1(v[0]);
        ans += solve1(v[1]);
        ans += solve2(v);
        System.out.println(ans);
        return ans;
    }

    public static void main(String[] args) {
        solve();
    }

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static void reunique(List<F> allF) {
        Set<F> set = new HashSet<>(allF);
        allF.clear();
        allF.addAll(set);
    }

    static int lowerBound(List<F> allF, F key) {
        int low = 0, high = allF.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (allF.get(mid).compareTo(key) < 0) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}
