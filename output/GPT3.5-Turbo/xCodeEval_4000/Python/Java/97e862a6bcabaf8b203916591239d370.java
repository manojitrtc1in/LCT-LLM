import java.util.Scanner;

public class 97e862a6bcabaf8b203916591239d370_nc {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        long[] DP = new long[n + 5];
        long[] CUM = new long[n + 5];
        CUM[1] = 0;
        DP[1] = 1;
        
        long S = 1;
        
        for (int i = 2; i <= n; i++) {
            CUM[i] = (CUM[i - 1] + CUM[i]) % m;
            DP[i] = (S + CUM[i]) % m;
            S += DP[i];
            S %= m;
            
            for (int j = i + i; j <= n; j += i) {
                CUM[j] = (CUM[j] + DP[i] - DP[i - 1]) % m;
            }
        }
        
        System.out.println(DP[n]);
    }
}
