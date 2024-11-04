import java.util.Scanner;
import java.math.BigInteger;

class Main {
    static int qanak;

    static BigInteger solve(String s, int h) {
        boolean[] u = new boolean[26];
        BigInteger answer = BigInteger.ONE;
        int k = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '?')
                k++;
            if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z')
                u[s.charAt(i) - 'A'] = true;
        }
        for (int i = 0; i < k; ++i)
            qanak++;

        k = 0;
        for (int i = 0; i < 26; ++i)
            if (u[i])
                k++;
        if (k > 10)
            return BigInteger.ZERO;
        for (int i = 0; i < k; ++i)
            answer = answer.multiply(BigInteger.valueOf(10 - i - h));
        return answer;
    }

    public static void main(String[] args) {
        qanak = 0;
        BigInteger answer = BigInteger.ZERO;
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        if (s.length() == 1) {
            if (s.charAt(0) == '?' || (s.charAt(0) >= 'A' && s.charAt(0) <= 'Z'))
                answer = BigInteger.valueOf(9);
            else
                answer = BigInteger.ONE;
            System.out.println(answer);
            return;
        }
        if (s.charAt(0) == '?') {
            String st = s.substring(1);
            answer = BigInteger.valueOf(9).multiply(solve(st));
        } else if (s.charAt(0) >= 'A' && s.charAt(0) <= 'Z') {
            for (int k = 1; k < 10; ++k) {
                String st = s;
                qanak = 0;
                for (int i = 0; i < st.length(); ++i)
                    if (st.charAt(i) == s.charAt(0))
                        st = st.substring(0, i) + (char) ('0' + k) + st.substring(i + 1);
                answer = answer.add(solve(st, 1));
            }
        } else
            answer = solve(s);
        System.out.print(answer);
        for (int i = 0; i < qanak; ++i)
            System.out.print(0);
        System.out.println();
    }
}
