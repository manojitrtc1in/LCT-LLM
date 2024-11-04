import java.util.*;

class Main {
    static final int mod = 1000000007;

    static long powe(long b, long e) {
        long r = 1;
        while (e > 0) {
            if ((e & 1) == 1)
                r = r * b % mod;
            b = b * b % mod;
            e >>= 1;
        }
        return r;
    }

    static void admul(long[] a, long b, long c) {
        a[0] = (a[0] + b * c) % mod;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[][] p = new long[n][n];
        long i100 = powe(100, mod - 2);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                long x = sc.nextLong();
                p[i][j] = x * i100 % mod;
            }
        Map<State, Long> x = new HashMap<>();
        State init = new State();
        for (int i = 0; i < (1 << n); ++i)
            init.a[i] = 0;
        x.put(init, 1L);
        for (int turn = 0; turn < n; ++turn) {
            Map<State, Long> newx = new HashMap<>();
            for (int s = 0; s < (1 << n); ++s) {
                long mul = 1;
                for (int i = 0; i < n; ++i)
                    if ((s >> i & 1) == 1)
                        mul = mul * p[i][turn] % mod;
                    else
                        mul = mul * (1 - p[i][turn]) % mod;
                for (Map.Entry<State, Long> c : x.entrySet()) {
                    State state = c.getKey();
                    long[] a = state.a;
                    for (int k = 0; k < (1 << n); ++k)
                        if ((k & s) != 0 && a[k] < popc(k))
                            a[k]++;
                    boolean add = true;
                    for (int k = 0; k < (1 << n); ++k)
                        if (a[k] + (n - turn - 1) < popc(k))
                            add = false;
                    if (add)
                        admul(newx.computeIfAbsent(state, k -> 0L), mul, c.getValue());
                }
            }
            x = newx;
            System.err.println(x.size());
        }
        State fin = new State();
        for (int i = 0; i < (1 << n); ++i)
            fin.a[i] = popc(i);
        long ans = x.get(fin);
        ans %= mod;
        if (ans < 0)
            ans += mod;
        System.out.println(ans);
    }

    static int popc(int x) {
        return Integer.bitCount(x);
    }

    static class State {
        long[] a = new long[1 << 6];

        @Override
        public int hashCode() {
            return Arrays.hashCode(a);
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null || getClass() != obj.getClass())
                return false;
            State state = (State) obj;
            return Arrays.equals(a, state.a);
        }
    }
}