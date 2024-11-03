import java.util.*;
import java.io.*;
import java.math.BigInteger;

class Main {
    static BigInteger alpha(int n) {
        BigInteger cnt = BigInteger.TEN;
        BigInteger res = BigInteger.ONE;
        for (int i = 0; i < Math.min(n, 11); ++i) {
            res = res.multiply(cnt);
            cnt = cnt.subtract(BigInteger.ONE).max(BigInteger.ZERO);
        }
        return res;
    }

    static BigInteger beta(int n) {
        BigInteger cnt = BigInteger.valueOf(9);
        BigInteger res = BigInteger.valueOf(9);
        for (int i = 0; i < Math.min(n - 1, 11); ++i) {
            res = res.multiply(cnt);
            cnt = cnt.subtract(BigInteger.ONE).max(BigInteger.ZERO);
        }
        return res;
    }

    static BigInteger power(BigInteger n, int p) {
        if (p <= 0)
            return BigInteger.ONE;

        BigInteger x = power(n, p / 2);

        if (p % 2 == 1)
            return x.multiply(x).multiply(n);
        else
            return x.multiply(x);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        char leading = s.charAt(0);
        boolean lead = true;

        if (Character.isDigit(leading))
            lead = false;

        BitSet bits = new BitSet(30);
        int cnt = 0;

        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (Character.isAlphabetic(c))
                bits.set(c - 'A');
            else if (c == '?')
                ++cnt;
        }

        BigInteger res;

        if (!lead) {
            res = alpha(bits.cardinality()).multiply(power(BigInteger.TEN, cnt));
        } else {
            if (leading == '?')
                res = alpha(bits.cardinality()).multiply(power(BigInteger.TEN, cnt - 1)).multiply(BigInteger.valueOf(9));
            else
                res = beta(bits.cardinality()).multiply(power(BigInteger.TEN, cnt));
        }

        System.out.println(res);
    }
}
