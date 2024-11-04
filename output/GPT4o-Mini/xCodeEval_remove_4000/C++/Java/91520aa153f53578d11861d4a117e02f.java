import java.util.*;

public class 91520aa153f53578d11861d4a117e02fxcodeeval_processed_4000.json {
    static final double EPS = 0.000000001;
    static final double id0 = 1000000000;
    static final long INF64 = 1000000000000000000L;
    static final int INF32 = 1000000000;

    static int toInt(String s) {
        int x = 0;
        for (int i = 0; i < s.length(); ++i) {
            x *= 10;
            x += (s.charAt(i) - '0');
        }
        return x;
    }

    static long[] st10 = new long[20];

    static void solve() {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        st10[0] = 1;
        for (int i = 1; i < 20; ++i) {
            st10[i] = st10[i - 1] * 10;
        }
        
        s = new StringBuilder(s).reverse().toString();
        while (s.length() > 0 && (s.charAt(s.length() - 1) < '0' || s.charAt(s.length() - 1) > '9')) {
            s = s.substring(0, s.length() - 1);
        }
        s = new StringBuilder(s).reverse().toString();

        List<Integer> vec = new ArrayList<>();
        for (int i = s.length(); i > 0; --i) {
            vec.add(toInt(s));
            s = new StringBuilder(s).reverse().toString();
            s = s.substring(0, s.length() - 1);
            s = new StringBuilder(s).reverse().toString();
        }
        Collections.reverse(vec);

        Set<Integer> set = new HashSet<>();
        int ans = 0;
        for (int i = 0; i < vec.size(); ++i) {
            int x = vec.get(i);
            while (x < 1989 || set.contains(x)) {
                x += st10[i + 1];
            }
            set.add(x);
            ans = x;
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            solve();
        }
    }
}
