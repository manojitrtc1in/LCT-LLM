import java.util.*;

class Main {
    static long[] powcnt;
    static long ans;

    public static void preprocess(long num) {
        for (int i = 30; i >= 0; i--) {
            if (num >= (1 << i)) {
                num -= (1 << i);
                powcnt[i]++;
            }
        }
    }

    public static void solve(long curp) {
        for (long i = curp; i <= 30; i++) {
            if (powcnt[(int)i] > 0) {
                powcnt[(int)i]--;
                ans++;
                for (long j = curp; j < i; j++) {
                    powcnt[(int)j]++;
                }
                break;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        powcnt = new long[N];
        ans = 0;
        for (int i = 0; i < n; i++) {
            long x = scanner.nextLong();
            preprocess(x);
        }
        List<Long> v = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            long x = scanner.nextLong();
            v.add(x);
        }
        Collections.sort(v);
        for (int i = 0; i < v.size(); i++) {
            solve(v.get(i));
        }
        System.out.println(ans);
    }
}
