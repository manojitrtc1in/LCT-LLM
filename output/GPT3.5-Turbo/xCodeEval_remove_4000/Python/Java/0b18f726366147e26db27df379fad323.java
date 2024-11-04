import java.util.*;
import java.io.*;

class Main {
    static List<Integer> RL(Class<?> type) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        List<Integer> result = new ArrayList<>();
        for (String s : input) {
            result.add(type.cast(Integer.parseInt(s)));
        }
        return result;
    }

    static int from_base(String X) {
        String base = "0123456789`~!@";
        int l = base.length();
        int r = 0;
        int e = 1;
        for (int i = X.length() - 1; i >= 0; i--) {
            char c = X.charAt(i);
            r += base.indexOf(c) * e;
            e *= l;
        }
        return r;
    }

    static void solve() {
        List<Integer> RLResult = RL(Integer.class);
        int N = RLResult.get(0);
        int mod = RLResult.get(1);
        System.out.println(from_base(A[N]) % mod);
    }

    public static void main(String[] args) {
        int T = 1;
        for (int t = 0; t < T; t++) {
            solve();
        }
    }
}
