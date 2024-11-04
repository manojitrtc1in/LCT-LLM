import java.util.*;

public class 0b18f726366147e26db27df379fad323_nc {
    static List<String> A = Arrays.asList("0", "1", "2", "6", "(", "D", "E3", "_&", "/51", "n`6", "n4>", "!rR2", "E+a*", "j61h1", "!3ab!", "q`t6");

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int mod = scanner.nextInt();
        System.out.println(fromBase(A.get(N)) % mod);
    }

    static int fromBase(String X) {
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
}
