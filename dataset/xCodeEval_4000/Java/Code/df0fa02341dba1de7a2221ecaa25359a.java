


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.io.Writer;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;
import java.util.Vector;

public class Abra {
    public static void main(String[] args) throws IOException {
        new Abra().run();
    }

    StreamTokenizer in;
    PrintWriter out;
    boolean oj;
    BufferedReader br;

    void init() throws IOException {
        Reader reader = new InputStreamReader(System.in);
        Writer writer = new OutputStreamWriter(System.out);
        in = new StreamTokenizer(new BufferedReader(reader));
        br = new BufferedReader(reader);
        out = new PrintWriter(writer);
    }

    void run() throws IOException {
        long beginTime = System.currentTimeMillis();
        init();
        solve();
        long endTime = System.currentTimeMillis();
        out.flush();
    }

    int nextInt() throws IOException {
        in.nextToken();
        return (int) in.nval;
    }

    long nextLong() throws IOException {
        in.nextToken();
        return (long) in.nval;
    }

    String nextString() throws IOException {
        in.nextToken();
        return in.sval;
    }

    double nextDouble() throws IOException {
        in.nextToken();
        return in.nval;
    }

    long fact(long x) {
        long a = 1;
        for (long i = 2; i <= x; i++) {
            a *= i;
        }
        return a;
    }

    long digitSum(String x) {
        long a = 0;
        for (int i = 0; i < x.length(); i++) {
            a += x.charAt(i) - '0';
        }
        return a;
    }

    long digitSum(long x) {
        long a = 0;
        while (x > 0) {
            a += x % 10;
            x /= 10;
        }
        return a;
    }

    long digitMul(long x) {
        long a = 1;
        while (x > 0) {
            a *= x % 10;
            x /= 10;
        }
        return a;
    }

    int digitCubesSum(int x) {
        int a = 0;
        while (x > 0) {
            a += (x % 10) * (x % 10) * (x % 10);
            x /= 10;
        }
        return a;
    }

    double pif(double ax, double ay, double bx, double by) {
        return Math.sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    }

    long gcd(long a, long b) {
        if (a < b) {
            long c = b;
            b = a;
            a = c;
        }
        while (a % b != 0) {
            a = a % b;
            if (a < b) {
                long c = b;
                b = a;
                a = c;
            }
        }
        return b;
    }

    int gcd(int a, int b) {
        if (a < b) {
            int c = b;
            b = a;
            a = c;
        }
        while (a % b != 0) {
            a = a % b;
            if (a < b) {
                int c = b;
                b = a;
                a = c;
            }
        }
        return b;
    }

    long lcm(long a, long b) throws IOException {
        return a * b / gcd(a, b);
    }

    int lcm(int a, int b) throws IOException {
        return a * b / gcd(a, b);
    }

    int countOccurences(String x, String y) {
        int a = 0, i = 0;
        while (true) {
            i = y.indexOf(x);
            if (i == -1)
                break;
            a++;
            y = y.substring(i + 1);
        }
        return a;
    }

    int[] findPrimes(int x) {
        boolean[] forErato = new boolean[x - 1];
        List<Integer> t = new Vector<Integer>();
        int l = 0, j = 0;
        for (int i = 2; i < x; i++) {
            if (forErato[i - 2])
                continue;
            t.add(i);
            l++;
            j = i * 2;
            while (j < x) {
                forErato[j - 2] = true;
                j += i;
            }
        }
        int[] primes = new int[l];
        Iterator<Integer> it = t.iterator();
        for (int i = 0; it.hasNext(); i++) {
            primes[i] = it.next().intValue();
        }
        return primes;
    }

    int rev(int x) {
        int a = 0;
        while (x > 0) {
            a = a * 10 + x % 10;
            x /= 10;
        }
        return a;
    }

    class myDate {
        int d, m, y;

        public myDate(int da, int ma, int ya) {
            d = da;
            m = ma;
            y = ya;
        }

        int[] ml = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        void inc() {
            if ((d == 31) && (m == 12)) {
                y++;
                d = 1;
                m = 1;
            } else {
                if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) {
                    ml[1] = 29;
                }
                if (d == ml[m - 1]) {
                    m++;
                    d = 1;
                } else
                    d++;
            }
        }
    }

    int partition(int n, int l, int m) {

        

        if (n < l)
            return 0;
        if (n < l + 2)
            return 1;
        if (l == 1)
            return 1;
        int c = 0;
        for (int i = Math.min(n - l + 1, m); i >= (n + l - 1) / l; i--) {
            c += partition(n - i, l - 1, i);
        }
        return c;
    }

    int rifmQuality(String a, String b) {
        if (a.length() > b.length()) {
            String c = a;
            a = b;
            b = c;
        }
        int c = 0, d = b.length() - a.length();
        for (int i = a.length() - 1; i >= 0; i--) {
            if (a.charAt(i) == b.charAt(i + d))
                c++;
            else
                break;
        }
        return c;
    }

    String numSym = "0123456789ABCDEF";

    String ZFromXToYNotation(int x, int y, String z) {
        String a = "";
        long q = 0, t = 1;
        for (int i = z.length() - 1; i >= 0; i--) {
            q += (z.charAt(i) - 48) * t;
            t *= x;
        }
        while (q > 0) {
            a = numSym.charAt((int) (q % y)) + a;
            q /= y;
        }
        return a;
    }

    double angleFromXY(int x, int y) {
        if ((x == 0) && (y > 0))
            return Math.PI / 2;
        if ((x == 0) && (y < 0))
            return -Math.PI / 2;
        if ((y == 0) && (x > 0))
            return 0;
        if ((y == 0) && (x < 0))
            return Math.PI;
        if (x > 0)
            return Math.atan((double) y / x);
        else {
            if (y > 0)
                return Math.atan((double) y / x) + Math.PI;
            else
                return Math.atan((double) y / x) - Math.PI;
        }
    }

    static boolean isNumber(String x) {
        try {
            Integer.parseInt(x);
        } catch (NumberFormatException ex) {
            return false;
        }
        return true;
    }

    static boolean stringContainsOf(String x, String c) {
        for (int i = 0; i < x.length(); i++) {
            if (c.indexOf(x.charAt(i)) == -1)
                return false;
        }
        return true;
    }

    long pow(long a, long n) { 

        if (n == 0)
            return 1;
        long k = n, b = 1, c = a;
        while (k != 0) {
            if (k % 2 == 0) {
                k /= 2;
                c *= c;
            } else {
                k--;
                b *= c;
            }
        }
        return b;
    }

    int pow(int a, int n) { 

        if (n == 0)
            return 1;
        int k = n, b = 1, c = a;
        while (k != 0) {
            if (k % 2 == 0) {
                k /= 2;
                c *= c;
            } else {
                k--;
                b *= c;
            }
        }
        return b;
    }

    double log2(double x) {
        return Math.log(x) / Math.log(2);
    }

    int lpd(int[] primes, int x) {

        int i;
        for (i = 0; primes[i] <= x / 2; i++) {
            if (x % primes[i] == 0) {
                return primes[i];
            }
        }
        ;
        return x;
    }

    int np(int[] primes, int x) {

        for (int i = 0; true; i++) {
            if (primes[i] == x)
                return i;
        }
    }

    int[] dijkstra(int[][] map, int n, int s) {
        int[] p = new int[n];
        boolean[] b = new boolean[n];
        Arrays.fill(p, Integer.MAX_VALUE);
        p[s] = 0;
        b[s] = true;
        for (int i = 0; i < n; i++) {
            if (i != s)
                p[i] = map[s][i];
        }
        while (true) {
            int m = Integer.MAX_VALUE, mi = -1;
            for (int i = 0; i < n; i++) {
                if (!b[i] && (p[i] < m)) {
                    mi = i;
                    m = p[i];
                }
            }
            if (mi == -1)
                break;
            b[mi] = true;
            for (int i = 0; i < n; i++)
                if (p[mi] + map[mi][i] < p[i])
                    p[i] = p[mi] + map[mi][i];
        }
        return p;
    }

    boolean isLatinChar(char x) {
        if (((x >= 'a') && (x <= 'z')) || ((x >= 'A') && (x <= 'Z')))
            return true;
        else
            return false;
    }

    class NotANumberException extends Exception {
        private static final long serialVersionUID = 1L;
        String mistake;

        NotANumberException() {
            mistake = "Unknown.";
        }

        NotANumberException(String message) {
            mistake = message;
        }
    }

    class Real {
        String num = "0";
        int exp = 0;
        boolean pos = true;

        int length() {
            return num.length();
        }

        void check(String x) throws NotANumberException {
            if (!stringContainsOf(x, "0123456789+-.eE"))
                throw new NotANumberException("Illegal character.");
            int j = 0;
            for (int i = 0; i < x.length(); i++) {
                if ((x.charAt(i) == '-') || (x.charAt(i) == '+')) {
                    if (j == 0)
                        j = 1;
                    else if (j == 5)
                        j = 6;
                    else
                        throw new NotANumberException("Unexpected sign.");
                } else if ("0123456789".indexOf(x.charAt(i)) != -1) {
                    if (j == 0)
                        j = 2;
                    else if (j == 1)
                        j = 2;
                    else if (j == 2)
                        ;
                    else if (j == 3)
                        j = 4;
                    else if (j == 4)
                        ;
                    else if (j == 5)
                        j = 6;
                    else if (j == 6)
                        ;
                    else
                        throw new NotANumberException("Unexpected digit.");
                } else if (x.charAt(i) == '.') {
                    if (j == 0)
                        j = 3;
                    else if (j == 1)
                        j = 3;
                    else if (j == 2)
                        j = 3;
                    else
                        throw new NotANumberException("Unexpected dot.");
                } else if ((x.charAt(i) == 'e') || (x.charAt(i) == 'E')) {
                    if (j == 2)
                        j = 5;
                    else if (j == 4)
                        j = 5;
                    else
                        throw new NotANumberException("Unexpected exponent.");
                } else
                    throw new NotANumberException("O_o.");
            }
            if ((j == 0) || (j == 1) || (j == 3) || (j == 5))
                throw new NotANumberException("Unexpected end.");
        }

        public Real(String x) throws NotANumberException {
            check(x);
            if (x.charAt(0) == '-')
                pos = false;
            int j = 0;
            String e = "";
            boolean epos = true;
            for (int i = 0; i < x.length(); i++) {
                if ("0123456789".indexOf(x.charAt(i)) != -1) {
                    if (j == 0)
                        num += x.charAt(i);
                    if (j == 1) {
                        num += x.charAt(i);
                        exp--;
                    }
                    if (j == 2)
                        e += x.charAt(i);
                }
                if (x.charAt(i) == '.') {
                    if (j == 0)
                        j = 1;
                }
                if ((x.charAt(i) == 'e') || (x.charAt(i) == 'E')) {
                    j = 2;
                    if (x.charAt(i + 1) == '-')
                        epos = false;
                }
            }
            while ((num.length() > 1) && (num.charAt(0) == '0'))
                num = num.substring(1);
            while ((num.length() > 1) && (num.charAt(num.length() - 1) == '0')) {
                num = num.substring(0, num.length() - 1);
                exp++;
            }
            if (num.equals("0")) {
                exp = 0;
                pos = true;
                return;
            }
            while ((e.length() > 1) && (e.charAt(0) == '0'))
                e = e.substring(1);
            try {
                if (e != "")
                    if (epos)
                        exp += Integer.parseInt(e);
                    else
                        exp -= Integer.parseInt(e);
            } catch (NumberFormatException exc) {
                if (!epos) {
                    num = "0";
                    exp = 0;
                    pos = true;
                } else {
                    throw new NotANumberException("Too long exponent");
                }
            }
        }

        public Real() {
        }

        String toString(int mantissa) {
            String a = "", b = "";
            if (exp >= 0) {
                a = num;
                if (!pos)
                    a = '-' + a;
                for (int i = 0; i < exp; i++)
                    a += '0';
                for (int i = 0; i < mantissa; i++)
                    b += '0';
                if (mantissa == 0)
                    return a;
                else
                    return a + "." + b;
            } else {
                if (exp + length() <= 0) {
                    a = "0";
                    if (mantissa == 0) {
                        return a;
                    }
                    if (mantissa < -(exp + length() - 1)) {
                        for (int i = 0; i < mantissa; i++)
                            b += '0';
                        return a + "." + b;
                    } else {
                        if (!pos)
                            a = '-' + a;
                        for (int i = 0; i < mantissa; i++)
                            if (i < -(exp + length()))
                                b += '0';
                            else if (i + exp >= 0)
                                b += '0';
                            else
                                b += num.charAt(i + exp + length());
                        return a + "." + b;
                    }
                } else {
                    if (!pos)
                        a = "-";
                    for (int i = 0; i < exp + length(); i++)
                        a += num.charAt(i);
                    if (mantissa == 0)
                        return a;
                    for (int i = exp + length(); i < exp + length() + mantissa; i++)
                        if (i < length())
                            b += num.charAt(i);
                        else
                            b += '0';
                    return a + "." + b;
                }
            }
        }
    }

    boolean containsRepeats(int... num) {
        Set<Integer> s = new TreeSet<Integer>();
        for (int d : num)
            if (!s.contains(d))
                s.add(d);
            else
                return true;
        return false;
    }

    int[] rotateDice(int[] a, int n) {
        int[] c = new int[6];
        if (n == 0) {
            c[0] = a[1];
            c[1] = a[5];
            c[2] = a[2];
            c[3] = a[0];
            c[4] = a[4];
            c[5] = a[3];
        }
        if (n == 1) {
            c[0] = a[2];
            c[1] = a[1];
            c[2] = a[5];
            c[3] = a[3];
            c[4] = a[0];
            c[5] = a[4];
        }
        if (n == 2) {
            c[0] = a[3];
            c[1] = a[0];
            c[2] = a[2];
            c[3] = a[5];
            c[4] = a[4];
            c[5] = a[1];
        }
        if (n == 3) {
            c[0] = a[4];
            c[1] = a[1];
            c[2] = a[0];
            c[3] = a[3];
            c[4] = a[5];
            c[5] = a[2];
        }
        if (n == 4) {
            c[0] = a[0];
            c[1] = a[2];
            c[2] = a[3];
            c[3] = a[4];
            c[4] = a[1];
            c[5] = a[5];
        }
        if (n == 5) {
            c[0] = a[0];
            c[1] = a[4];
            c[2] = a[1];
            c[3] = a[2];
            c[4] = a[3];
            c[5] = a[5];
        }
        return c;
    }

    int min(int... a) {
        int c = Integer.MAX_VALUE;
        for (int d : a)
            if (d < c)
                c = d;
        return c;
    }

    int max(int... a) {
        int c = Integer.MIN_VALUE;
        for (int d : a)
            if (d > c)
                c = d;
        return c;
    }

    int[] normalizeDice(int[] a) {
        int[] c = a.clone();
        if (c[0] != 0) {
            if (c[1] == 0)
                c = rotateDice(c, 0);
            else if (c[2] == 0)
                c = rotateDice(c, 1);
            else if (c[3] == 0)
                c = rotateDice(c, 2);
            else if (c[4] == 0)
                c = rotateDice(c, 3);
            else if (c[5] == 0)
                c = rotateDice(rotateDice(c, 0), 0);
        }
        while (c[1] != min(c[1], c[2], c[3], c[4]))
            c = rotateDice(c, 4);
        return c;
    }

    boolean sameDice(int[] a, int[] b) {
        for (int i = 0; i < 6; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

    void solve() throws IOException {
        int n = nextInt();
        int[] c = new int[n], d1 = new int[n], d2 = new int[n];
        Arrays.fill(c, -1);
        for (int i = 0; i < n; i++) {
            d1[i] = nextInt() - 1;
            d2[i] = nextInt() - 1;
            c[i] = nextInt();
        }
        int a = 0, b = 0, k = d2[0];
        boolean[] v = new boolean[n];
        while (k != d1[0]) {
            boolean f = false;
            for (int j = 1; j < n; j++) {
                if ((d1[j] == k) && (!v[d2[j]])) {
                    v[k] = true;
                    k = d2[j];
                    f = true;
                    break;
                }
            }
            if (f) continue;
            for (int j = 1; j < n; j++) {
                if ((d2[j] == k) && (!v[d1[j]])) {
                    v[k] = true;
                    k = d1[j];
                    a += c[j];
                    break;
                }
            }
        }
        k = d1[0];
        b = c[0];
        v = new boolean[n];
        while (k != d2[0]) {
            boolean f = false;
            for (int j = 1; j < n; j++) {
                if ((d1[j] == k) && (!v[d2[j]])) {
                    v[k] = true;
                    k = d2[j];
                    f = true;
                    break;
                }
            }
            if (f) continue;
            for (int j = 1; j < n; j++) {
                if ((d2[j] == k) && (!v[d1[j]])) {
                    v[k] = true;
                    k = d1[j];
                    b += c[j];
                    break;
                }
            }
        }
        out.println(min(a, b));
        

    }
}