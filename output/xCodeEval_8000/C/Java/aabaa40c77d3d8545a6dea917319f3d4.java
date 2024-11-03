import java.util.Arrays;

public class aabaa40c77d3d8545a6dea917319f3d4_nc {
    static final int MAXP = 20000;
    static boolean[] sieve = new boolean[MAXP];
    static int[] prime = new int[6000];
    static int primes;

    public static void main(String[] args) {
        createsieve();
        genprimes();
        int a, b;
        int ans = 0;
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        b++;
        int c = a / INTER;
        if (a % INTER != 0)
            c++;
        int d = b / INTER;
        if (d % INTER != 0)
            d--;
        int e = c * INTER;
        int f = d * INTER;
        if (a <= e && e <= f && f <= b) {
            for (int i = a; i < e; i++) {
                if ((i == 2 || (i & 3) == 1) && isprime(i))
                    ans++;
            }
            for (int i = f; i < b; i++) {
                if ((i == 2 || (i & 3) == 1) && isprime(i))
                    ans++;
            }
            for (int i = c; i < d; i++) {
                ans += partial[i];
            }
        } else {
            for (int i = a; i < b; i++) {
                if ((i == 2 || (i & 3) == 1) && isprime(i))
                    ans++;
            }
        }
        System.out.println(ans);
    }

    static void createsieve() {
        Arrays.fill(sieve, true);
        int q = (int) Math.sqrt(MAXP);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i < q; i++) {
            if (sieve[i]) {
                for (int j = i * i; j < MAXP; j += i) {
                    sieve[j] = false;
                }
            }
        }
    }

    static void genprimes() {
        primes = 0;
        for (int i = 0; i < MAXP; i++) {
            if (sieve[i]) {
                prime[primes++] = i;
            }
        }
    }

    static boolean isprime(int n) {
        if (n < 2)
            return false;
        if (n == 2)
            return true;
        if ((n & 1) == 0)
            return false;
        for (int i = 0; prime[i] * prime[i] <= n; i++) {
            if (n % prime[i] == 0)
                return false;
        }
        return true;
    }

    static final int INTER = 100000;
