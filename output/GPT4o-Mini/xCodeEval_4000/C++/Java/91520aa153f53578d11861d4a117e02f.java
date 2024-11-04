import java.util.*;

public class 91520aa153f53578d11861d4a117e02f_nc {
    static final long MOD = 1000000007;
    static final int maxN = 100300;
    static long[] st10 = new long[20];

    static long toInt(String s) {
        long x = 0;
        for (int i = 0; i < s.length(); ++i) {
            x *= 10;
            x += (s.charAt(i) - '0');
        }
        return x;
    }

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
        List<Long> VEC = new ArrayList<>();
        for (int i = s.length(); i > 0; --i) {
            VEC.add(toInt(s));
            s = new StringBuilder(s).reverse().toString();
            s = s.substring(0, s.length() - 1);
            s = new StringBuilder(s).reverse().toString();
        }
        Collections.reverse(VEC);

        Set<Long> SET = new HashSet<>();
        long ans = 0;
        for (int i = 0; i < VEC.size(); ++i) {
            long x = VEC.get(i);
            while (x < 1989 || SET.contains(x)) {
                x += st10[i + 1];
            }
            SET.add(x);
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
