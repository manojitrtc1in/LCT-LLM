import java.util.*;
import java.io.*;

class Main {
    static class Solver {
        static class ModInt {
            private static final int MOD = 998244353;
            private int value;

            public ModInt(int value) {
                this.value = value % MOD;
                if (this.value < 0) {
                    this.value += MOD;
                }
            }

            public int getValue() {
                return value;
            }

            public ModInt add(ModInt other) {
                return new ModInt((value + other.value) % MOD);
            }

            public ModInt subtract(ModInt other) {
                return new ModInt((value - other.value + MOD) % MOD);
            }

            public ModInt multiply(ModInt other) {
                return new ModInt((int) ((long) value * other.value % MOD));
            }

            public ModInt divide(ModInt other) {
                return multiply(other.inverse());
            }

            public ModInt inverse() {
                int a = MOD, b = value, u = 0, v = 1;
                while (b != 0) {
                    int t = a / b;
                    a ^= b ^= (a -= t * b) ^= b;
                    u ^= v ^= (u -= t * v) ^= v;
                }
                return new ModInt(u);
            }

            public ModInt pow(long e) {
                if (e < 0) {
                    e = e % (MOD - 1) + MOD - 1;
                }
                ModInt res = new ModInt(1);
                ModInt base = new ModInt(value);
                while (e > 0) {
                    if ((e & 1) == 1) {
                        res = res.multiply(base);
                    }
                    base = base.multiply(base);
                    e >>= 1;
                }
                return res;
            }

            @Override
            public String toString() {
                return Integer.toString(value);
            }
        }

        private int n;
        private List<List<Integer>> tree;
        private List<List<ModInt>> dp;

        public Solver() {
            n = in.nextInt();
            tree = new ArrayList<>();
            dp = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                tree.add(new ArrayList<>());
                dp.add(new ArrayList<>(Collections.nCopies(3, new ModInt(0))));
            }
            for (int i = 1; i < n; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                tree.get(a).add(b);
                tree.get(b).add(a);
            }
            treedp(0, -1);
            List<ModInt> rdp = dp.get(0);
            out.println(rdp.get(0).add(rdp.get(2)));
        }

        private boolean leaf(int v) {
            return tree.get(v).size() == 1;
        }

        private void treedp(int now, int pre) {
            List<ModInt> ndp = dp.get(now);
            ndp.set(2, new ModInt(1));
            for (int to : tree.get(now)) {
                if (to == pre) {
                    continue;
                }
                List<ModInt> tmp = new ArrayList<>(Collections.nCopies(3, new ModInt(0)));
                treedp(to, now);
                List<ModInt> tdp = dp.get(to);

                for (int i = 0; i < 3; i++) {
                    tmp.set(i, tdp.get(2).multiply(ndp.get(i)));
                }

                tmp.set(0, tmp.get(0).add(ndp.get(2).multiply(tdp.get(2))).add(ndp.get(1).multiply(tdp.get(2))));

                tmp.set(0, tmp.get(0).add((ndp.get(1).add(ndp.get(2))).multiply(tdp.get(1))));

                tmp.set(0, tmp.get(0).add(new ModInt(2).multiply(ndp.get(0)).multiply(tdp.get(0))));
                tmp.set(1, tmp.get(1).add((ndp.get(1).multiply(new ModInt(2)).add(ndp.get(2))).multiply(tdp.get(0))));
                tmp.set(2, tmp.get(2).add(ndp.get(2).multiply(tdp.get(0))));

                ndp = tmp;
            }
            dp.set(now, ndp);
        }
    }

    static final InputReader in = new InputReader(System.in);
    static final PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;

        while (t-- > 0) {
            new Solver();
        }

        out.close();
    }

    static class InputReader {
        private final BufferedReader reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
