import java.util.*;
import java.io.*;

class Main {
    static int[] st10;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            solve(br);
        }
    }

    static void solve(BufferedReader br) throws IOException {
        String s = br.readLine();
        st10 = new int[20];
        st10[0] = 1;
        for (int i = 1; i < 20; ++i) {
            st10[i] = st10[i - 1] * 10;
        }
        s = new StringBuilder(s).reverse().toString();
        while (s.charAt(s.length() - 1) < '0' || s.charAt(s.length() - 1) > '9') {
            s = s.substring(0, s.length() - 1);
        }
        s = new StringBuilder(s).reverse().toString();
        List<Integer> VEC = new ArrayList<>();
        for (int i = s.length(); i > 0; --i) {
            VEC.add(toInt(s));
            s = new StringBuilder(s).reverse().toString();
            s = s.substring(0, s.length() - 1);
            s = new StringBuilder(s).reverse().toString();
        }
        Collections.reverse(VEC);
        Set<Integer> SET = new HashSet<>();
        int ans = 0;
        for (int i = 0; i < VEC.size(); ++i) {
            int x = VEC.get(i);
            while (x < 1989 || SET.contains(x)) {
                x += st10[i + 1];
            }
            SET.add(x);
            ans = x;
        }
        System.out.println(ans);
    }

    static int toInt(String s) {
        int x = 0;
        for (int i = 0; i < s.length(); ++i) {
            x *= 10;
            x += (s.charAt(i) - '0');
        }
        return x;
    }
}
