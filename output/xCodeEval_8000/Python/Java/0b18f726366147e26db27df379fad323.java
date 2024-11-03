import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = 1;
        for (int t = 0; t < T; t++) {
            solve(scanner);
        }
    }

    static List<Integer> RL() {
        Scanner scanner = new Scanner(System.in);
        List<Integer> result = new ArrayList<>();
        String[] inputs = scanner.nextLine().split(" ");
        for (String input : inputs) {
            result.add(Integer.parseInt(input));
        }
        return result;
    }

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

    static void solve(Scanner scanner) {
        List<Integer> RL = RL();
        int N = RL.get(0);
        int mod = RL.get(1);
        String[] A = {"0","1","2","6","(","D","E3","_&","/51","n`6","n4>","!rR2","E+a*","j61h1","!3ab!","q`t6"};
        System.out.println(from_base(A[N]) % mod);
    }
}
