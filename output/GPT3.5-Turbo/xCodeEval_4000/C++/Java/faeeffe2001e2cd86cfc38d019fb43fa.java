import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class faeeffe2001e2cd86cfc38d019fb43fa_nc {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        BitSet bits = new BitSet(30);
        int cnt = 0;
        char leading = s.charAt(0);
        boolean lead = true;
        BigInteger res;

        if (Character.isDigit(leading))
            lead = false;

        for (int i = 0; i < s.length(); i++) {
            if (Character.isAlphabetic(s.charAt(i)))
                bits.set(s.charAt(i) - 'A');
            else if (s.charAt(i) == '?')
                cnt++;
        }

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

    public static BigInteger alpha(int n) {
        BigInteger cnt = BigInteger.TEN;
        BigInteger res = BigInteger.ONE;
        for (int i = 0; i < Math.min(n, 11); i++) {
            res = res.multiply(cnt);
            cnt = cnt.subtract(BigInteger.ONE).max(BigInteger.ZERO);
        }
        return res;
    }

    public static BigInteger beta(int n) {
        BigInteger cnt = BigInteger.valueOf(9);
        BigInteger res = BigInteger.valueOf(9);
        for (int i = 0; i < Math.min(n - 1, 11); i++) {
            res = res.multiply(cnt);
            cnt = cnt.subtract(BigInteger.ONE).max(BigInteger.ZERO);
        }
        return res;
    }

    public static BigInteger power(BigInteger n, int p) {
        if (p <= 0)
            return BigInteger.ONE;

        BigInteger x = power(n, p / 2);

        if (p % 2 == 1)
            return x.multiply(x).multiply(n);
        else
            return x.multiply(x);
    }
}
