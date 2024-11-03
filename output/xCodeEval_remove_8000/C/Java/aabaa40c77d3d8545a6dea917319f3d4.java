import java.util.Arrays;
import java.util.Scanner;

public class aabaa40c77d3d8545a6dea917319f3d4xcodeeval_processed_8000.json {
    static final int MAXP = 1000000;
    static final int INTER = 10000;

    static boolean[] sieve = new boolean[MAXP];
    static int[] prime = new int[6000];
    static int primes;

    public static void createsieve() {
        int q = (int) Math.sqrt(MAXP);
        Arrays.fill(sieve, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i < q; i++) {
            if (sieve[i]) {
                for (int j = i * i; j < MAXP; j += i) {
                    sieve[j] = false;
                }
            }
        }
    }

    public static void id0() {
        primes = 0;
        for (int i = 0; i < MAXP; i++) {
            if (sieve[i]) {
                prime[primes++] = i;
            }
        }
    }

    public static boolean isprime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 0; prime[i] * prime[i] <= n; i++) {
            if (n % prime[i] == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        createsieve();
        id0();
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt() + 1;
        int c = a / INTER;
        if (a % INTER != 0) c++;
        int d = b / INTER;
        if (d % INTER != 0) d--;
        int e = c * INTER;
        int f = d * INTER;
        int ans = 0;
        if (a <= e && e <= f && f <= b) {
            for (int i = a; i < e; i++) {
                if ((i == 2 || (i & 3) == 1) && isprime(i)) {
                    ans++;
                }
            }
            for (int i = f; i < b; i++) {
                if ((i == 2 || (i & 3) == 1) && isprime(i)) {
                    ans++;
                }
            }
            for (int i = c; i < d; i++) {
                ans += partial[i];
            }
        } else {
            for (int i = a; i < b; i++) {
                if ((i == 2 || (i & 3) == 1) && isprime(i)) {
                    ans++;
                }
            }
        }
        System.out.println(ans);
    }

