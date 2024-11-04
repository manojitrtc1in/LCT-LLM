import java.util.*;

class DChaoticV {
    static final int MX = 5000;

    public void solve(Scanner cin, PrintWriter cout) {
        int N = cin.nextInt();
        int[] K = new int[N];
        for (int i = 0; i < N; i++) {
            K[i] = cin.nextInt();
        }
        Arrays.sort(K);
        int[] C = new int[MX + 1];
        for (int k : K) C[k]++;

        List<Integer> P = Sieve.primes(MX);
        int M = P.size();

        int[][] D = new int[MX + 1][M];
        for (int i = 0; i < M; ++i) {
            int p = P.get(i);
            for (int j = p; j <= MX; j *= p) {
                for (int k = 0; k <= MX; ++k) {
                    D[k][i] += k / j;
                }
            }
        }
        for (int i = 0; i <= MX; ++i) {
            int[] temp = D[i];
            for (int j = 0; j < temp.length / 2; j++) {
                int swap = temp[j];
                temp[j] = temp[temp.length - 1 - j];
                temp[temp.length - 1 - j] = swap;
            }
        }

        long[][] Pref = new long[MX + 1][M + 1];
        for (int i = 0; i <= MX; ++i) {
            for (int j = 0; j < M; ++j) {
                Pref[i][j + 1] = Pref[i][j] + D[i][j];
            }
        }

        int[] CountPref = new int[MX + 2];
        long tot = 0;
        for (int i = 0; i <= MX; ++i) {
            CountPref[i + 1] = CountPref[i] + C[i];
            tot += C[i] * Pref[i][M];
        }

        int use = K[N / 2];
        List<Pair> W = new ArrayList<>();
        long base = 0;
        for (int i = 0; i <= MX; ++i) {
            if (C[i] == 0) continue;

            int x = 0;
            long len = 0;
            while (x < M && D[i][x] == D[use][x]) {
                len += D[i][x];
                x++;
            }
            if (x < M) {
                len += Math.min(D[i][x], D[use][x]);
            }
            W.add(new Pair(len, C[i]));
            base += (Pref[i][M] - len) * C[i];
        }
        W.sort(Comparator.comparingLong(a -> a.x));

        long ans = Long.MAX_VALUE;
        for (Pair w : W) {
            long cur = 0;
            for (Pair ww : W) {
                cur += Math.abs(ww.x - w.x) * ww.y;
            }
            ans = Math.min(ans, base + cur);
        }
        cout.println(ans);
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        PrintWriter cout = new PrintWriter(System.out);
        DChaoticV solver = new DChaoticV();
        solver.solve(cin, cout);
        cout.flush();
    }
}

class Sieve {
    public static List<Integer> primes(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        if (n != 0) isPrime[1] = false;
        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= n; ++i) {
            if (isPrime[i]) primes.add(i);
        }
        return primes;
    }
}

class Pair {
    long x;
    int y;

    Pair(long x, int y) {
        this.x = x;
        this.y = y;
    }
}
