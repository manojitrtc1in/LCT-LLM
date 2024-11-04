import java.util.*;
import java.io.*;

class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class Fenw {
        int[] tr;

        public Fenw() {
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

    static class F implements Comparable<F> {
        int p, q;

        public F(int p, int q) {
            this.p = p;
            this.q = q;
        }

        public int compareTo(F f) {
            return Integer.compare(p * f.q, f.p * q);
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            F f = (F) o;
            return p * f.q == f.p * q;
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        int[] x = new int[n];
        int[] a = new int[n];
        int w = sc.nextInt();
        List<pii> v0 = new ArrayList<>();
        List<pii> v1 = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextInt();
            a[i] = sc.nextInt();
            if (x[i] < 0) {
                v0.add(new pii(Math.abs(x[i]), Math.abs(a[i])));
            } else {
                v1.add(new pii(Math.abs(x[i]), Math.abs(a[i])));
            }
        }
        long ans = 0;
        ans += solve1(v0, w);
        ans += solve1(v1, w);
        ans += solve2(v0, v1, w);
        System.out.println(ans);
    }

    static long solve1(List<pii> v, int w) {
        List<F> allF = new ArrayList<>();
        for (pii p : v) {
            F from = new F(p.first, p.second + w);
            F to = new F(p.first, p.second - w);
            allF.add(from);
            allF.add(to);
        }
        allF.add(new F(0, 1));
        Collections.sort(allF);
        Set<F> set = new HashSet<>(allF);
        for (pii p : v) {
            F from = new F(p.first, p.second + w);
            F to = new F(p.first, p.second - w);
            p.first = Collections.binarySearch(allF, from);
            p.second = Collections.binarySearch(allF, to);
        }
        Collections.sort(v, new Comparator<pii>() {
            public int compare(pii p1, pii p2) {
                if (p1.first < p2.first) {
                    return -1;
                } else if (p1.first > p2.first) {
                    return 1;
                } else {
                    return Integer.compare(p1.second, p2.second);
                }
            }
        });
        long res = 0;
        Fenw f1 = new Fenw();
        for (int i = 0; i < v.size(); i++) {
            res += i - f1.sum(v.get(i).second - 1);
            f1.add(v.get(i).second);
        }
        return res;
    }

    static long solve2(List<pii> v0, List<pii> v1, int w) {
        List<F> allF = new ArrayList<>();
        for (pii p : v0) {
            F from = new F(p.first, p.second + w);
            F to = new F(p.first, p.second - w);
            allF.add(from);
            allF.add(to);
        }
        for (pii p : v1) {
            F from = new F(p.first, p.second + w);
            F to = new F(p.first, p.second - w);
            allF.add(from);
            allF.add(to);
        }
        allF.add(new F(0, 1));
        Collections.sort(allF);
        Set<F> set = new HashSet<>(allF);
        for (pii p : v0) {
            F from = new F(p.first, p.second + w);
            F to = new F(p.first, p.second - w);
            p.first = Collections.binarySearch(allF, from);
            p.second = Collections.binarySearch(allF, to);
        }
        for (pii p : v1) {
            F from = new F(p.first, p.second + w);
            F to = new F(p.first, p.second - w);
            p.first = Collections.binarySearch(allF, from);
            p.second = Collections.binarySearch(allF, to);
        }
        Collections.sort(v0, new Comparator<pii>() {
            public int compare(pii p1, pii p2) {
                if (p1.first < p2.first) {
                    return -1;
                } else if (p1.first > p2.first) {
                    return 1;
                } else {
                    return Integer.compare(p1.second, p2.second);
                }
            }
        });
        Collections.sort(v1, new Comparator<pii>() {
            public int compare(pii p1, pii p2) {
                if (p1.first < p2.first) {
                    return -1;
                } else if (p1.first > p2.first) {
                    return 1;
                } else {
                    return Integer.compare(p1.second, p2.second);
                }
            }
        });
        long res = 0;
        Fenw[] f = new Fenw[2];
        f[0] = new Fenw();
        f[1] = new Fenw();
        for (pii p : v0) {
            res += f[1].sum(p.first, p.second);
        }
        for (pii p : v1) {
            res += f[0].sum(p.first + 1, p.second);
        }
        return res;
    }

    static class pii {
        int first, second;

        public pii(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
