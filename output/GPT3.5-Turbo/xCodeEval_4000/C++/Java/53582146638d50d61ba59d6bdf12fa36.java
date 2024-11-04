import java.util.*;
import java.io.*;

class Main {
    static class Solver {
        static class Mint {
            int val;
            static final int MOD = 998244353;

            Mint(int val) {
                this.val = val;
            }

            Mint add(Mint other) {
                return new Mint((val + other.val) % MOD);
            }

            Mint subtract(Mint other) {
                return new Mint((val - other.val + MOD) % MOD);
            }

            Mint multiply(Mint other) {
                return new Mint((int) ((long) val * other.val % MOD));
            }

            Mint divide(Mint other) {
                return multiply(other.inverse());
            }

            Mint inverse() {
                int a = MOD, b = val, u = 0, v = 1, t;
                while (b != 0) {
                    t = a / b;
                    a ^= b ^= (a -= t * b) ^= b;
                    u ^= v ^= (u -= t * v) ^= v;
                }
                return new Mint(u);
            }

            Mint pow(long e) {
                if (e < 0) {
                    e = e % (MOD - 1) + MOD - 1;
                }
                Mint res = new Mint(1);
                Mint base = new Mint(val);
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
                return Integer.toString(val);
            }
        }

        int n;
        List<List<Integer>> tree;
        List<List<Mint>> dp;

        boolean isLeaf(int v) {
            return tree.get(v).size() == 1;
        }

        void treedp(int now, int pre) {
            List<Mint> ndp = dp.get(now);
            ndp.set(2, new Mint(1));
            for (int to : tree.get(now)) {
                if (to == pre) {
                    continue;
                }
                List<Mint> tmp = new ArrayList<>(3);
                treedp(to, now);
                List<Mint> tdp = dp.get(to);

                for (int i = 0; i < 3; i++) {
                    tmp.add(tdp.get(2).multiply(ndp.get(i)));
                }

                tmp.set(0, tmp.get(0).add(ndp.get(2).multiply(tdp.get(2))).add(ndp.get(1).multiply(tdp.get(2))));

                tmp.set(0, tmp.get(0).add((ndp.get(1).add(ndp.get(2))).multiply(tdp.get(1))));

                tmp.set(0, tmp.get(0).add(new Mint(2).multiply(ndp.get(0)).multiply(tdp.get(0))));
                tmp.set(1, tmp.get(1).add((ndp.get(1).multiply(new Mint(2)).add(ndp.get(2))).multiply(tdp.get(0))));
                tmp.set(2, tmp.get(2).add(ndp.get(2).multiply(tdp.get(0))));

                ndp = tmp;
            }
        }

        Solver() {
            FastScanner in = new FastScanner();
            PrintWriter out = new PrintWriter(System.out);

            n = in.nextInt();
            tree = new ArrayList<>();
            dp = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                tree.add(new ArrayList<>());
                dp.add(new ArrayList<>(Collections.nCopies(3, new Mint(0))));
            }

            for (int i = 1; i < n; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                tree.get(a).add(b);
                tree.get(b).add(a);
            }

            treedp(0, -1);
            List<Mint> rdp = dp.get(0);
            out.println(rdp.get(0).add(rdp.get(2)));
            out.flush();
        }
    }

    public static void main(String[] args) {
        new Solver();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() {
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
    }
}
