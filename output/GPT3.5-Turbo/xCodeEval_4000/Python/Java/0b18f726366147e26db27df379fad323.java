import java.util.*;
import java.io.*;

class Main {
    static List<Integer> RL(Class<?> type) {
        Scanner scanner = new Scanner(System.in);
        String[] inputs = scanner.nextLine().split(" ");
        List<Integer> result = new ArrayList<>();
        for (String input : inputs) {
            result.add(type.cast(input));
        }
        return result;
    }

    static List<String> A = Arrays.asList("0","1","2","6","(","D","E3","_&","/51","n`6","n4>","!rR2","E+a*","j61h1","!3ab!","q`t6");

    static int from_base(String X) {
        String base = "0123456789`~!@";
        int l = base.length();
        int r = 0;
        int e = 1;
        for (char c : X.toCharArray()) {
            r += base.indexOf(c) * e;
            e *= l;
        }
        return r;
    }

    static void solve() {
        List<Integer> input = RL(Integer.class);
        int N = input.get(0);
        int mod = input.get(1);
        System.out.println(from_base(A.get(N)) % mod);
    }

    public static void main(String[] args) {
        int T = 1;
        for (int t = 0; t < T; t++) {
            solve();
        }
    }
}
