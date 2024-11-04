import java.util.*;
import java.math.*;

class InfInt {
    private static final BigInteger BASE = BigInteger.valueOf(1000000000);
    private BigInteger value;

    public InfInt() {
        this.value = BigInteger.ZERO;
    }

    public InfInt(String s) {
        this.value = new BigInteger(s);
    }

    public InfInt(long l) {
        this.value = BigInteger.valueOf(l);
    }

    public InfInt add(InfInt other) {
        return new InfInt(this.value.add(other.value).toString());
    }

    public InfInt multiply(InfInt other) {
        return new InfInt(this.value.multiply(other.value).toString());
    }

    public InfInt multiply(long n) {
        return new InfInt(this.value.multiply(BigInteger.valueOf(n)).toString());
    }

    public InfInt power(int p) {
        return new InfInt(this.value.pow(p).toString());
    }

    public String toString() {
        return this.value.toString();
    }

    public static InfInt max(InfInt a, InfInt b) {
        return a.value.compareTo(b.value) > 0 ? a : b;
    }

    public static InfInt min(InfInt a, InfInt b) {
        return a.value.compareTo(b.value) < 0 ? a : b;
    }
}

public class faeeffe2001e2cd86cfc38d019fb43fa_nc {
    static String s;
    static BitSet bits = new BitSet(30);
    static int cnt;
    static char leading;
    static boolean lead = true;
    static InfInt res;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        s = scanner.nextLine();

        leading = s.charAt(0);

        if (Character.isDigit(leading)) {
            lead = false;
        }

        for (int i = 0; i < s.length(); i++) {
            if (Character.isLetter(s.charAt(i))) {
                bits.set(s.charAt(i) - 'A');
            } else if (s.charAt(i) == '?') {
                cnt++;
            }
        }

        if (!lead) {
            res = alpha(bits.cardinality()).multiply(InfInt.power(10, cnt));
        } else {
            if (leading == '?') {
                res = alpha(bits.cardinality()).multiply(InfInt.power(10, cnt - 1)).multiply(9);
            } else {
                res = beta(bits.cardinality()).multiply(InfInt.power(10, cnt));
            }
        }

        System.out.println(res);
    }

    static InfInt alpha(int n) {
        InfInt cnt = new InfInt(10);
        InfInt res = new InfInt(1);
        for (int i = 0; i < Math.min(n, 11); i++) {
            res = res.multiply(cnt);
            cnt = InfInt.max(cnt.subtract(new InfInt(1)), new InfInt(0));
        }
        return res;
    }

    static InfInt beta(int n) {
        InfInt cnt = new InfInt(9);
        InfInt res = new InfInt(9);
        for (int i = 0; i < Math.min(n - 1, 11); i++) {
            res = res.multiply(cnt);
            cnt = InfInt.max(cnt.subtract(new InfInt(1)), new InfInt(0));
        }
        return res;
    }
}
