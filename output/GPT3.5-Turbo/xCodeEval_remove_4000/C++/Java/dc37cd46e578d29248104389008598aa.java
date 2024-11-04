import java.util.*;

class Main {
    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class F implements Comparable<F> {
        int p;
        int q;

        F(int p, int q) {
            this.p = p;
            this.q = q;
        }

        @Override
        public int compareTo(F f) {
            return Integer.compare(this.p * f.q, f.p * this.q);
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (obj == null || getClass() != obj.getClass()) {
                return false;
            }
            F f = (F) obj;
            return this.p * f.q == f.p * this.q;
        }
    }

    static class Fenw {
        int[] tr;

        Fenw() {
            tr = new int[202020];
        }

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
    static Fenw[] f = { new Fenw(), new Fenw() };

    static long solve1(List<Pair> v) {
        List<F> allF = new ArrayList<>();
        for (Pair p : v) {
            F from = new F(p.first, p.second + w);
            F to = new F(p.first, p.second - w);
            allF.add(from);
            allF.add(to);
        }
        allF.add(new F(0, 1));
        Collections.sort(allF);
        allF = reunique(allF);
        for (Pair p : v) {
            F from = new F(p.first, p.second + w);
            F to = new F(p.first, p.second - w);
            p.first = lowerBound(allF, from);
            p.second = lowerBound(allF, to);
        }
        Collections.sort(v, (p1, p2) -> {
            if (p1.first != p2.first) {
                return Integer.compare(p1.first, p2.first);
            } else {
                return Integer.compare(p1.second, p2.second);
            }
        });
        long res = 0;
        Arrays.fill(f1.tr, 0);
        for (int i = 0; i < v.size(); ++i) {
            res += i - f1.sum(v.get(i).second - 1);
            f1.add(v.get(i).second);
        }
        return res;
    }

    static long solve2(List<Pair>[] v) {
        List<F> allF = new ArrayList<>();
        for (int i = 0; i < 2; i++) {
            for (Pair p : v[i]) {
                F from = new F(p.first, p.second + w);
                F to = new F(p.first, p.second - w);
                allF.add(from);
                allF.add(to);
            }
        }
        allF.add(new F(0, 1));
        Collections.sort(allF);
        allF = reunique(allF);
        long res = 0;
        List<Triple> events = new ArrayList<>();
        for (int i = 0; i < 2; i++) {
            for (Pair p : v[i]) {
                F from = new F(p.first, p.second + w);
                F to = new F(p.first, p.second - w);
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

    static int lowerBound(List<F> list, F target) {
        int low = 0;
        int high = list.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (list.get(mid).compareTo(target) < 0) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    static List<F> reunique(List<F> list) {
        List<F> result = new ArrayList<>();
        for (F f : list) {
            if (result.isEmpty() || !result.get(result.size() - 1).equals(f)) {
                result.add(f);
            }
        }
        return result;
    }

    static class Triple {
        int a;
        int b;
        int c;

        Triple(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    static int[] x;
    static int[] a;
    static List<Pair>[] v;
    static int w;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        w = sc.nextInt();
        x = new int[n];
        a = new int[n];
        v = new List[2];
        v[0] = new ArrayList<>();
        v[1] = new ArrayList<>();
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
    }
}
