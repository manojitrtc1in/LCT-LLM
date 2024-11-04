import java.util.*;
import java.math.BigInteger;

class Id3 extends Exception {
    private String txt;

    public Id3(String txt) {
        super();
        this.txt = txt;
    }

    @Override
    public String getMessage() {
        return txt;
    }
}

class InfInt {
    private static final int BASE = 1000000000;
    private static final int id5 = 999999999;
    private static final int id0 = 9;
    private List<Integer> val;
    private boolean pos;

    public static final InfInt zero = new InfInt(0);
    public static final InfInt one = new InfInt(1);
    public static final InfInt two = new InfInt(2);

    public InfInt() {
        this.pos = true;
        val = new ArrayList<>();
        val.add(0);
    }

    public InfInt(String s) {
        fromString(s);
    }

    public InfInt(int l) {
        this.pos = l >= 0;
        val = new ArrayList<>();
        if (!pos) {
            l = -l;
        }
        do {
            val.add(l % BASE);
            l /= BASE;
        } while (l > 0);
    }

    public InfInt(long l) {
        this.pos = l >= 0;
        val = new ArrayList<>();
        if (!pos) {
            l = -l;
        }
        do {
            val.add((int) (l % BASE));
            l /= BASE;
        } while (l > 0);
    }

    public InfInt(long long l) {
        this.pos = l >= 0;
        val = new ArrayList<>();
        if (!pos) {
            l = -l;
        }
        do {
            val.add((int) (l % BASE));
            l /= BASE;
        } while (l > 0);
    }

    public InfInt multiplyByDigit(int factor) {
        InfInt result = new InfInt();
        int carry = 0;
        for (int i = 0; i < val.size(); i++) {
            long pval = val.get(i) * (long) factor + carry;
            carry = (int) (pval / BASE);
            result.val.add((int) (pval % BASE));
        }
        if (carry > 0) {
            result.val.add(carry);
        }
        result.correct();
        return result;
    }

    public InfInt add(InfInt rhs) {
        InfInt result = new InfInt();
        result.val = new ArrayList<>(Collections.nCopies(Math.max(val.size(), rhs.val.size()), 0));
        for (int i = 0; i < result.val.size(); i++) {
            int left = (i < val.size() ? (pos ? val.get(i) : -val.get(i)) : 0);
            int right = (i < rhs.val.size() ? (rhs.pos ? rhs.val.get(i) : -rhs.val.get(i)) : 0);
            result.val.set(i, left + right);
        }
        result.correct();
        return result;
    }

    public InfInt subtract(InfInt rhs) {
        InfInt result = new InfInt();
        result.val = new ArrayList<>(Collections.nCopies(Math.max(val.size(), rhs.val.size()), 0));
        for (int i = 0; i < result.val.size(); i++) {
            int left = (i < val.size() ? (pos ? val.get(i) : -val.get(i)) : 0);
            int right = (i < rhs.val.size() ? (rhs.pos ? rhs.val.get(i) : -rhs.val.get(i)) : 0);
            result.val.set(i, left - right);
        }
        result.correct();
        return result;
    }

    public InfInt multiply(InfInt rhs) {
        InfInt result = new InfInt();
        result.val = new ArrayList<>(Collections.nCopies(val.size() + rhs.val.size(), 0));
        for (int i = 0; i < val.size(); i++) {
            for (int j = 0; j < rhs.val.size(); j++) {
                long pval = result.val.get(i + j) + (long) val.get(i) * rhs.val.get(j);
                result.val.set(i + j, (int) (pval % BASE));
                if (pval >= BASE) {
                    result.val.set(i + j + 1, result.val.get(i + j + 1) + (int) (pval / BASE));
                }
            }
        }
        result.correct();
        return result;
    }

    public InfInt divide(InfInt rhs) throws Id3 {
        if (rhs.equals(zero)) {
            throw new Id3("division by zero");
        }
        InfInt quotient = new InfInt();
        InfInt remainder = new InfInt();
        for (int i = val.size() - 1; i >= 0; i--) {
            remainder.val.add(0, val.get(i));
            remainder.correct();
            int cnt = dInR(remainder, rhs);
            remainder = remainder.subtract(rhs.multiply(cnt));
            quotient.val.add(cnt);
        }
        quotient.correct();
        return quotient;
    }

    public InfInt mod(InfInt rhs) throws Id3 {
        if (rhs.equals(zero)) {
            throw new Id3("division by zero");
        }
        InfInt remainder = new InfInt();
        for (int i = val.size() - 1; i >= 0; i--) {
            remainder.val.add(0, val.get(i));
            remainder.correct();
            remainder = remainder.subtract(rhs.multiply(dInR(remainder, rhs)));
        }
        remainder.correct();
        return remainder;
    }

    private int dInR(InfInt R, InfInt D) {
        int min = 0, max = id5;
        while (max - min > 0) {
            int avg = (max + min) / 2;
            InfInt prod = D.multiply(avg);
            if (R.equals(prod)) {
                return avg;
            } else if (R.isGreater(prod)) {
                min = avg;
            } else {
                max = avg - 1;
            }
        }
        return min;
    }

    private void correct() {
        removeLeadingZeros();
        if (val.size() == 1 && val.get(0) == 0) {
            pos = true;
        }
    }

    private void removeLeadingZeros() {
        while (val.size() > 1 && val.get(val.size() - 1) == 0) {
            val.remove(val.size() - 1);
        }
    }

    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof InfInt)) return false;
        InfInt other = (InfInt) obj;
        return pos == other.pos && val.equals(other.val);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (!pos) {
            sb.append('-');
        }
        for (int i = val.size() - 1; i >= 0; i--) {
            sb.append(String.format("%09d", val.get(i)));
        }
        return sb.toString();
    }

    private void fromString(String s) {
        pos = true;
        val = new ArrayList<>();
        for (int i = s.length() - 1; i >= 0; i -= 9) {
            int start = Math.max(0, i - 8);
            val.add(Integer.parseInt(s.substring(start, i + 1)));
        }
        if (val.get(val.size() - 1) < 0) {
            val.set(val.size() - 1, -val.get(val.size() - 1));
            pos = false;
        }
        correct();
    }
}

public class faeeffe2001e2cd86cfc38d019fb43faxcodeeval_processed_4000.json {
    private static final double EPS = 1e-9;
    private static String s;
    private static BitSet bits = new BitSet(30);
    private static int cnt;
    private static char leading;
    private static boolean lead = true;
    private static InfInt res;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        s = scanner.nextLine();
        leading = s.charAt(0);
        if (Character.isDigit(leading)) lead = false;

        for (int i = 0; i < s.length(); i++) {
            if (Character.isLetter(s.charAt(i))) {
                bits.set(s.charAt(i) - 'A');
            } else if (s.charAt(i) == '?') {
                cnt++;
            }
        }

        if (!lead) {
            res = alpha(bits.cardinality()).multiply(power(10, cnt));
        } else {
            if (leading == '?') {
                res = alpha(bits.cardinality()).multiply(power(10, cnt - 1)).multiply(9);
            } else {
                res = beta(bits.cardinality()).multiply(power(10, cnt));
            }
        }

        System.out.println(res);
    }

    private static InfInt alpha(int n) {
        InfInt cnt = new InfInt(10);
        InfInt res = new InfInt(1);
        for (int i = 0; i < Math.min(n, 11); i++) {
            res = res.multiply(cnt);
            cnt = new InfInt(Math.max(cnt.toInt() - 1, 0));
        }
        return res;
    }

    private static InfInt beta(int n) {
        InfInt cnt = new InfInt(9);
        InfInt res = new InfInt(9);
        for (int i = 0; i < Math.min(n - 1, 11); i++) {
            res = res.multiply(cnt);
            cnt = new InfInt(Math.max(cnt.toInt() - 1, 0));
        }
        return res;
    }

    private static InfInt power(InfInt n, int p) {
        if (p <= 0) return new InfInt(1);
        InfInt x = power(n, p / 2);
        if (p % 2 == 1) return x.multiply(x).multiply(n);
        else return x.multiply(x);
    }
}
