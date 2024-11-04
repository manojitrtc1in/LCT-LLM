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

    static class Pair {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Triple {
        int first, second, third;

        public Triple(int first, int second, int third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }

    static final int MOD = (int) 1e9 + 7;
    static final int MX = (int) 2e5 + 5;
    static final long INF = (long) 1e18;
    static final double PI = Math.acos(-1);
    static final int[] xd = {1, 0, -1, 0}, yd = {0, 1, 0, -1};

    static long nod(long a, long b) {
        if (b > a) {
            long temp = a;
            a = b;
            b = temp;
        }
        while (b > 0) {
            a %= b;
            long temp = a;
            a = b;
            b = temp;
        }
        return a;
    }

    static long nok(long a, long b) {
        return a * b / nod(a, b);
    }

    static void sp(long a, double b) {
        System.out.printf("%.0f", b);
    }

    static long binpow(long a, long n) {
        if (n == 0) {
            return 1;
        }
        if (n % 2 == 1) {
            return binpow(a, n - 1) * a;
        } else {
            long b = binpow(a, n / 2);
            return b * b;
        }
    }

    static <A> void read(ArrayList<A> v) {
        for (int i = 0; i < v.size(); i++) {
            v.set(i, (A) in.next());
        }
    }

    static <A, S> void read(A[] a) {
        for (int i = 0; i < a.length; i++) {
            a[i] = (A) in.next();
        }
    }

    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            solve();
        }
        out.close();
    }

    static void solve() {
        Map<Long, Long> m = new HashMap<>();
        int n = in.nextInt();
        long s = in.nextLong();
        long k = in.nextLong();
        long ans = MOD;
        long cnt = 0;
        long[] a = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = in.nextLong();
            if (i >= k) {
                m.put(a[i - k], m.getOrDefault(a[i - k], 0L) - 1);
                if (m.get(a[i - k]) == 0) {
                    cnt--;
                }
                m.put(a[i], m.getOrDefault(a[i], 0L) + 1);
                if (m.get(a[i]) == 1) {
                    cnt++;
                }
                ans = Math.min(ans, cnt);
            } else {
                m.put(a[i], m.getOrDefault(a[i], 0L) + 1);
                if (m.get(a[i]) == 1) {
                    cnt++;
                }
            }
        }
        ans = Math.min(ans, cnt);
        out.println(ans);
    }
}
