import java.util.Scanner;

public class 9d7f573977944a7404f5020f3ff2c687_nc {
    
    static final int SegmentLen = 200000;
    static int size = 0;
    static int[] primes = new int[SegmentLen];
    
    public static boolean isPrime(int x) {
        if (x == 2) return true;
        
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        
        return true;
    }
    
    public static void getPrimes(int x) {
        for (int i = 2; i <= x; i++) {
            if (isPrime(i)) {
                size++;
                primes[size] = i;
            }
        }
    }
    
    public static boolean good(int x) {
        if (x == 1) return false;
        
        if (x != 2 && x % 4 != 1) return false;
        
        for (int i = 1; primes[i] * primes[i] <= x; i++) {
            if (x % primes[i] == 0) return false;
        }
        
        return true;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        int ans = 0;
        
        getPrimes(33000);
        
        while (l % SegmentLen != 1 && l <= r) {
            if (good(l)) ans++;
            l++;
        }
        
        if (l > r) {
            System.out.println(ans);
            return;
        }
        
        while (r % SegmentLen != 0 && l <= r) {
            if (good(r)) ans++;
            r--;
        }
        
        if (l > r) {
            System.out.println(ans);
            return;
        }
        
        int ll = (l / SegmentLen) + 1;
        int rr = (r / SegmentLen);
        
        for (int i = ll; i <= rr; i++) {
            ans += Precalculated[i];
        }
        
        System.out.println(ans);
    }
}
