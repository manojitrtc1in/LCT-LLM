import java.io.*;
import java.util.*;

class TaskD {
    static final int MOD7 = 1000000007;
    static final int MOD9 = 1000000009;
    static final int MODF = 998244353;

    static int mod = MOD7;

    static class modint {
        int n;

        modint() {
            n = 0;
        }

        modint(long n) {
            if (n >= 0 && n < mod) {
                this.n = (int) n;
                return;
            }
            n %= mod;
            if (n < 0) {
                n += mod;
            }
            this.n = (int) n;
        }

        modint add(modint other) {
            n += other.n;
            if (n >= mod) {
                n -= mod;
            }
            return this;
        }

        modint subtract(modint other) {
            n -= other.n;
            if (n < 0) {
                n += mod;
            }
            return this;
        }

        modint multiply(modint other) {
            n = (int) ((long) n * other.n % mod);
            return this;
        }

        modint divide(modint other) {
            return multiply(other.inverse());
        }

        modint inverse() {
            long x, y;
            long g = gcd(n, mod, x, y);
            return new modint(x);
        }

        static long gcd(long a, long b, long x, long y) {
            if (a == 0) {
                x = 0;
                y = 1;
                return b;
            }
            long x1 = 0, y1 = 0;
            long d = gcd(b % a, a, x1, y1);
            x = y1 - (b / a) * x1;
            y = x1;
            return d;
        }

        int log(modint alpha) {
            HashMap<modint, Integer> base = new HashMap<>();
            int exp = 0;
            modint pow = new modint(1);
            modint inv = new modint(n);
            modint alInv = alpha.inverse();
            while (exp * exp < mod) {
                if (inv.n == 1) {
                    return exp;
                }
                base.put(inv, exp++);
                pow.multiply(alpha);
                inv.multiply(alInv);
            }
            modint step = new modint(pow.n);
            for (int i = 1; ; i++) {
                if (base.containsKey(pow)) {
                    return exp * i + base.get(pow);
                }
                pow.multiply(step);
            }
        }

        @Override
        public String toString() {
            return Integer.toString(n);
        }
    }

    static modint add(modint a, modint b) {
        return new modint(a.n).add(b);
    }

    static modint subtract(modint a, modint b) {
        return new modint(a.n).subtract(b);
    }

    static modint multiply(modint a, modint b) {
        return new modint(a.n).multiply(b);
    }

    static modint divide(modint a, modint b) {
        return new modint(a.n).divide(b);
    }

    static class Event implements Comparable<Event> {
        int type;
        int at;
        int dx;
        int v;

        Event(int type, int at, int dx, int v) {
            this.type = type;
            this.at = at;
            this.dx = dx;
            this.v = v;
        }

        @Override
        public int compareTo(Event b) {
            return Long.compare((long) dx * b.v, (long) b.dx * v);
        }
    }

    static void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] x = new int[n];
        int[] v = new int[n];
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            v[i] = in.nextInt();
            p[i] = in.nextInt();
        }
        mod = MODF;
        modint[][] pp = new modint[4 * n][4];
        modint[][] tmp = new modint[4 * n][4];
        boolean[][] allowed = new boolean[n][4];
        modint[][][] dp = new modint[4 * n][4][4];
        for (int i = 0; i < 4 * n; i++) {
            pp[i] = new modint[4];
            tmp[i] = new modint[4];
            for (int j = 0; j < 4; j++) {
                pp[i][j] = new modint(0);
                tmp[i][j] = new modint(0);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                allowed[i][j] = true;
            }
        }
        for (int i = 1; i < n; i++) {
            Event e1 = new Event(2, i, x[i] - x[i - 1], v[i] + v[i - 1]);
            Event e2 = new Event(0, i, x[i] - x[i - 1], v[i] - v[i - 1]);
            Event e3 = new Event(3, i, x[i] - x[i - 1], v[i - 1] - v[i]);
            if (v[i] > v[i - 1]) {
                allowed[i][0] = false;
                allowed[i][1] = false;
            } else if (v[i] < v[i - 1]) {
                allowed[i][2] = false;
                allowed[i][3] = false;
            }
            dp[i][0][0] = new modint(100 - p[i]).divide(new modint(100));
            dp[i][0][3] = new modint(1).subtract(dp[i][0][0]);
        }
        for (int i = 0; i < 4 * n; i++) {
            for (int j = 1; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    dp[i][j][k] = new modint(0);
                }
            }
        }
        for (int i = 0; i < 4 * n; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    pp[i][j].add(dp[i][j][k]);
                }
            }
        }
        Arrays.sort(pp, new Comparator<modint[]>() {
            @Override
            public int compare(modint[] o1, modint[] o2) {
                return o1[0].compareTo(o2[0]);
            }
        });
        modint answer = new modint(0);
        for (int i = 1; i < n; i++) {
            Event e1 = new Event(2, i, x[i] - x[i - 1], v[i] + v[i - 1]);
            Event e2 = new Event(0, i, x[i] - x[i - 1], v[i] - v[i - 1]);
            Event e3 = new Event(3, i, x[i] - x[i - 1], v[i - 1] - v[i]);
            if (v[i] > v[i - 1]) {
                allowed[i][0] = false;
                allowed[i][1] = false;
            } else if (v[i] < v[i - 1]) {
                allowed[i][2] = false;
                allowed[i][3] = false;
            }
            modint left = new modint(0);
            modint right = new modint(0);
            for (int j = 0; j < 4; j++) {
                if (allowed[i][j]) {
                    left.add(pp[i][j]);
                }
            }
            for (int j = 0; j < 4; j++) {
                if (allowed[i][j]) {
                    right.add(pp[i][j]);
                }
            }
            answer.add(new modint(e1.dx).divide(new modint(e1.v)).multiply(left).multiply(right));
            allowed[e1.at][e1.type] = false;
            for (int j = 0; j < 4 * n; j++) {
                for (int k = 0; k < 4; k++) {
                    for (int l = 0; l < 4; l++) {
                        dp[j][k][l] = new modint(0);
                    }
                }
            }
            for (int j = 0; j < 4 * n; j++) {
                for (int k = 0; k < 4; k++) {
                    for (int l = 0; l < 4; l++) {
                        if (allowed[j][k] && allowed[j][l]) {
                            dp[j][k][l].add(pp[j][k]).multiply(pp[j][l]);
                        }
                    }
                }
            }
            Arrays.sort(pp, new Comparator<modint[]>() {
                @Override
                public int compare(modint[] o1, modint[] o2) {
                    return o1[0].compareTo(o2[0]);
                }
            });
        }
        out.println(answer);
    }

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        solve(in, out);
        out.close();
    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
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
    }
}
