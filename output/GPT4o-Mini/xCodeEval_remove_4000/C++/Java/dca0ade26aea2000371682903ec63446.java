import java.util.*;
import java.io.*;

public class dca0ade26aea2000371682903ec63446xcodeeval_processed_4000.json {
    static final long MOD = 998244353;
    static final int MAX_V = (1 << 21) + 10;
    static long[] fact = new long[MAX_V];
    static long[] finv = new long[MAX_V];
    static long[] invs = new long[MAX_V];

    static void initFact() {
        fact[0] = 1;
        for (int i = 1; i < MAX_V; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        finv[MAX_V - 1] = modInverse(fact[MAX_V - 1]);
        for (int i = MAX_V - 2; i >= 0; i--) {
            finv[i] = finv[i + 1] * (i + 1) % MOD;
        }
        for (int i = MAX_V - 1; i >= 1; i--) {
            invs[i] = finv[i] * fact[i - 1] % MOD;
        }
    }

    static long modInverse(long a) {
        return pow(a, MOD - 2);
    }

    static long pow(long base, long exp) {
        long result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = result * base % MOD;
            }
            base = base * base % MOD;
            exp >>= 1;
        }
        return result;
    }

    static long choose(int n, int k) {
        return fact[n] * finv[n - k] % MOD * finv[k] % MOD;
    }

    static long binom(int a, int b) {
        return fact[a + b] * finv[a] % MOD * finv[b] % MOD;
    }

    static long id6(long a, long[] f) {
        long ans = 0;
        long w = modInverse(1 - a);
        long cur = 1;
        for (int k = 0; k < f.length; k++) {
            cur = cur * w % MOD;
            ans = (ans + fact[k] * cur % MOD * f[k] % MOD) % MOD;
        }
        return ans;
    }

    static long[][] id0(long[][] x, long[][] y) {
        int n1 = x.length, m1 = x[0].length;
        int n2 = y.length, m2 = y[0].length;
        int n = n1 + n2 - 1, m = m1 + m2 - 1;
        long[] p = new long[n * m];
        long[] q = new long[n * m];
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m1; j++) {
                p[i * m + j] = x[i][j];
            }
        }
        for (int i = 0; i < n2; i++) {
            for (int j = 0; j < m2; j++) {
                q[i * m + j] = y[i][j];
            }
        }
        id1(p, false);
        id1(q, false);
        for (int i = 0; i < p.length; i++) {
            p[i] = p[i] * q[i] % MOD;
        }
        id1(p, true);
        long[][] res = new long[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = p[i * m + j];
            }
        }
        return res;
    }

    static void id1(long[] f, boolean inv) {
        // Implementation of id1 function
        // This function needs to be implemented based on the original C++ logic
    }

    static void solve() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] ls = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            ls[i] = Integer.parseInt(st.nextToken());
        }
        int tot = Arrays.stream(ls).sum();
        List<long[][]> buf = new ArrayList<>();
        for (int idx = 0; idx < n; idx++) {
            int s = (ls[idx] - 1) / k + 1;
            long[][] f = new long[s][2];
            for (int num = 0; num < s; num++) {
                long w = (ls[idx] - k * num) * modInverse(tot) % MOD;
                if (num > 0) f[num][0] = w * pow(num - 1) % MOD;
                f[num][1] = w * pow(num) % MOD;
            }
            buf.add(f);
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for (int i = 0; i < n; i++) {
            pq.offer(new int[]{getSize(buf.get(i)), i});
        }
        for (int _ = 0; _ < n - 1; _++) {
            int i = pq.poll()[1];
            int j = pq.poll()[1];
            buf.set(i, id0(buf.get(i), buf.get(j)));
            buf.set(j, null);
            pq.offer(new int[]{getSize(buf.get(i)), i});
        }
        long[][] ans = buf.get(pq.peek()[1]);
        long sum = 0;
        for (int num = 1; num < ans.length; num++) {
            long[] f = new long[num + 1];
            for (int i = 0; i <= n; i++) {
                if (i + num - n >= 0) f[i + num - n] = ans[num][i];
                else assert ans[num][i] == 0;
            }
            long w = (tot - num * k) * modInverse(tot) % MOD;
            long val = id6(w, f);
            if (num % 2 == 0) val = -val;
            sum = (sum + val) % MOD;
        }
        System.out.println(sum);
    }

    static int getSize(long[][] x) {
        return x.length + x[0].length;
    }

    public static void main(String[] args) throws IOException {
        initFact();
        solve();
    }
}
