import java.util.Scanner;

class Atcoder {
    static class DynamicModint {
        private static int mod;
        private int value;

        public DynamicModint() {
            this.value = 0;
        }

        public DynamicModint(int v) {
            this.value = (v % mod + mod) % mod;
        }

        public static void setMod(int m) {
            mod = m;
        }

        public int val() {
            return value;
        }

        public DynamicModint add(DynamicModint other) {
            return new DynamicModint((this.value + other.value) % mod);
        }

        public DynamicModint subtract(DynamicModint other) {
            return new DynamicModint((this.value - other.value + mod) % mod);
        }

        public DynamicModint multiply(DynamicModint other) {
            return new DynamicModint((int)((1L * this.value * other.value) % mod));
        }

        public DynamicModint pow(long n) {
            DynamicModint result = new DynamicModint(1);
            DynamicModint base = this;
            while (n > 0) {
                if ((n & 1) == 1) {
                    result = result.multiply(base);
                }
                base = base.multiply(base);
                n >>= 1;
            }
            return result;
        }

        public DynamicModint inv() {
            return this.pow(mod - 2);
        }
    }

    static class TaskB {
        public void solve(Scanner in, Scanner out) {
            int n = in.nextInt();
            int m = in.nextInt();
            DynamicModint.setMod(m);
            DynamicModint[] ways = new DynamicModint[n + 1];
            DynamicModint[] extras = new DynamicModint[n + 1];
            ways[1] = new DynamicModint(1);
            DynamicModint sum = new DynamicModint(0);
            DynamicModint extra = new DynamicModint(0);
            for (int i = 1; i <= n; ++i) {
                ways[i] = ways[i].add(sum);
                extra = extra.add(extras[i]);
                ways[i] = ways[i].add(extra);
                for (int j = 2; i * j <= n; ++j) {
                    extras[i * j] = extras[i * j].add(ways[i]);
                    if ((i + 1) * j <= n) {
                        extras[(i + 1) * j] = extras[(i + 1) * j].subtract(ways[i]);
                    }
                }
                sum = sum.add(ways[i]);
            }
            out.println(ways[n].val());
        }
    }

    public static void main(String[] args) {
        TaskB solver = new TaskB();
        Scanner in = new Scanner(System.in);
        Scanner out = new Scanner(System.out);
        solver.solve(in, out);
    }
}
