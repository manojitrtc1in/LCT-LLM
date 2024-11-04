import java.io.*;
import java.util.*;

class Main {
    static final int MAXV = 1000001;
    static int N, K, Q;
    static int[] a, q;
    static long ans;
    static int[] ct;
    static long[] coeff;
    static sieve sv;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
        a = new int[N];
        q = new int[Q];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < Q; i++) {
            q[i] = Integer.parseInt(st.nextToken());
        }

        ans = 0;
        ct = new int[MAXV];
        coeff = new long[MAXV];
        sv = new sieve();

        for (int e : a) {
            ct[e]++;
        }

        for (int g = 1; g < MAXV; g++) {
            for (int m = g, c = 1; m < MAXV; m += g, c++) {
                coeff[m] += g * sv.mu[c];
                if (c > 1) {
                    ct[g] += ct[m];
                }
            }
            ans += coeff[g] * mn.ncr(ct[g], K);
        }

        for (int qv : q) {
            sv.for_each_divisor_unordered(qv, new DivisorHandler() {
                public void handle(int d) {
                    ans += coeff[d] * (mn.ncr(ct[d] + 1, K) - mn.ncr(ct[d], K));
                    ct[d]++;
                }
            });
            System.out.println(ans);
        }
    }

    static class sieve {
        int[] primes;
        num[] nums;

        sieve() {
            primes = new int[MAXV];
            nums = new num[MAXV];
            nums[1] = num.ONE();
            int idx = 0;
            for (int v = 2; v < MAXV; v++) {
                if (nums[v] == null) {
                    nums[v] = nums[1].prod(1, v);
                    primes[idx++] = v;
                }
                for (int i = 0; i < idx && primes[i] <= nums[v].least_prime && v * primes[i] < MAXV; i++) {
                    nums[v * primes[i]] = nums[v].prod(v, primes[i]);
                }
            }
        }

        boolean is_prime(int v) {
            return nums[v].least_prime == v;
        }

        int eliminate_least_prime(int v) {
            for (int m = nums[v].lp_multiplicity; m > 0; m--) {
                v = nums[v].div_least_prime;
            }
            return v;
        }

        void for_each_divisor_unordered(int v, DivisorHandler handler) {
            if (v == 1) {
                handler.handle(1);
                return;
            }
            int w = eliminate_least_prime(v);
            for (int m = 0; m <= nums[v].lp_multiplicity; m++) {
                handler.handle(v);
                v *= nums[v].least_prime;
            }
            for_each_divisor_unordered(w, handler);
        }

        interface DivisorHandler {
            void handle(int d);
        }

        class num {
            int least_prime;
            int div_least_prime;
            int lp_multiplicity;
            int mu;
            int phi;

            static num ONE() {
                return new num(Integer.MAX_VALUE, 1, 0, 1, 1);
            }

            num(int least_prime, int div_least_prime, int lp_multiplicity, int mu, int phi) {
                this.least_prime = least_prime;
                this.div_least_prime = div_least_prime;
                this.lp_multiplicity = lp_multiplicity;
                this.mu = mu;
                this.phi = phi;
            }

            num prod(int my_value, int p) {
                if (p < least_prime) {
                    return new num(p, my_value, 1, -mu, phi * (p - 1));
                }
                return new num(p, my_value, lp_multiplicity + 1, 0, phi * p);
            }
        }
    }

    static class mn {
        static final int MOD = 1000000007;
        int v;

        mn(int v) {
            this.v = v;
        }

        mn(long _v) {
            v = (int) (_v % MOD);
            if (v < 0) {
                v += MOD;
            }
        }

        mn() {
            this(0);
        }

        mn prod(mn o) {
            return new mn((long) v * o.v);
        }

        mn pow(int e) {
            if (e < 0) {
                return inv().pow(-e);
            }
            if (e == 0) {
                return new mn(1);
            }
            if ((e & 1) == 1) {
                return prod(pow(e - 1));
            }
            mn half = pow(e / 2);
            return half.prod(half);
        }

        mn inv() {
            int g = MOD, x = 0, y = 1;
            for (int r = v; r != 0; ) {
                int q = g / r;
                g %= r;
                int temp = x - q * y;
                x = y;
                y = temp;
                temp = g;
                g = r;
                r = temp;
            }
            assert g == 1;
            assert y == MOD || y == -MOD;
            return x < 0 ? new mn(x + MOD) : new mn(x);
        }

        static mn ncr(int n, int r) {
            if (r < 0 || n < r) {
                return new mn(0);
            }
            return factorial(n).prod(inverse_factorial(r)).prod(inverse_factorial(n - r));
        }

        static mn factorial(int n) {
            mn[] fact = new mn[n + 1];
            fact[0] = new mn(1);
            for (int i = 1; i <= n; i++) {
                fact[i] = fact[i - 1].prod(new mn(i));
            }
            return fact[n];
        }

        static mn inverse_factorial(int n) {
            mn[] finv = new mn[n + 1];
            finv[n] = factorial(n).inv();
            for (int i = n - 1; i >= 0; i--) {
                finv[i] = finv[i + 1].prod(new mn(i + 1));
            }
            return finv[n];
        }
    }
}
