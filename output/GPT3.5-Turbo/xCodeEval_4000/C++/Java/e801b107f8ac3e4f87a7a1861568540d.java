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

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Triple {
        int first, second, third;

        Triple(int first, int second, int third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }
    }

    static class Quadruple {
        int first, second, third, fourth;

        Quadruple(int first, int second, int third, int fourth) {
            this.first = first;
            this.second = second;
            this.third = third;
            this.fourth = fourth;
        }
    }

    static class FastWriter {
        BufferedWriter bw;

        public FastWriter() {
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        void print(Object object) throws IOException {
            bw.write(object.toString());
        }

        void println(Object object) throws IOException {
            print(object);
            bw.newLine();
        }

        void close() throws IOException {
            bw.close();
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

    static void solve() throws IOException {
        FastReader reader = new FastReader();
        FastWriter writer = new FastWriter();

        Map<Long, Long> m = new HashMap<>();
        int n = reader.nextInt();
        long s = reader.nextLong();
        long k = reader.nextLong();
        long ans = MOD;
        long cnt = 0;
        for (int i = 1; i <= n; i++) {
            long a = reader.nextLong();
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
        writer.println(ans);
        writer.close();
    }

    public static void main(String[] args) throws IOException {
        FastReader reader = new FastReader();
        FastWriter writer = new FastWriter();

        int t = reader.nextInt();
        while (t-- > 0) {
            solve();
        }
    }
}
