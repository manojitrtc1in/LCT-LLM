import java.util.Scanner;

public class c62f5cb8b01e04269b025d2b74bf386excodeeval_processed_4000.json {
    static long MAXN = (long) (1.5 * 1e7);
    static int INF = ~0 >>> 1;
    static long LL_INF = (long) (1e18 + 420);
    static double EPS = 1e-4;
    static int N = (int) (1e6 + 7);
    static int MAX = (int) (2e5 + 9);
    static int MOD = (int) (1e9 + 7);
    static double PI = 3.14159265359;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int b = scanner.nextInt();
        int d = scanner.nextInt();
        String a = scanner.next();
        String c = scanner.next();
        
        int[] t = new int[128];
        int s = 0;
        int n = c.length();
        
        for (int i = 0; i < n; ++i) {
            int k = t[i];
            for (int j = 0; j < a.length(); ++j) {
                if (a.charAt(j) == c.charAt((i + k) % n)) {
                    k++;
                }
            }
            t[i] = k;
        }
        
        for (int i = 0; i < b; ++i) {
            s += t[s % n];
        }
        
        System.out.println(s / n / d);
    }
}
