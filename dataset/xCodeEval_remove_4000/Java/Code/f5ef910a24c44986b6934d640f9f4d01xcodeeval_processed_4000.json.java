
import java.io.*;
import java.math.BigInteger;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class Main {

    static final int INF = Integer.MAX_VALUE;

    static void mergeSort(int[] a, int p, int r) {
        if (p < r) {
            int q = (p + r) / 2;
            mergeSort(a, p, q);
            mergeSort(a, q + 1, r);
            merge(a, p, q, r);
        }
    }

    static void merge(int[] a, int p, int q, int r) {
        int n1 = q - p + 1;
        int n2 = r - q;
        int[] L = new int[n1 + 1], R = new int[n2 + 1];
        


        for (int i = 0; i < n1; i++) {
            L[i] = a[p + i];
            


        }
        for (int i = 0; i < n2; i++) {
            R[i] = a[q + 1 + i];
            


        }
        L[n1] = R[n2] = INF;
        


        for (int k = p, i = 0, j = 0; k <= r; k++) {
            if (L[i] <= R[j]) {

                a[k] = L[i++];
                


            } else {
                a[k] = R[j++];
                


            }
        }
    }

    static void mergeSort(int[] a, int[] b, int p, int r) {
        if (p < r) {
            int q = (p + r) / 2;
            mergeSort(a, b, p, q);
            mergeSort(a, b, q + 1, r);
            merge(a, b, p, q, r);
        }
    }

    static void merge(int[] a, int[] b, int p, int q, int r) {
        int n1 = q - p + 1;
        int n2 = r - q;
        int[] L = new int[n1 + 1], R = new int[n2 + 1];
        int[] L1 = new int[n1 + 1], R1 = new int[n2 + 1];
        


        for (int i = 0; i < n1; i++) {
            L[i] = a[p + i];
            L1[i] = b[p + i];
            

        }
        for (int i = 0; i < n2; i++) {
            R[i] = a[q + 1 + i];
            R1[i] = b[q + 1 + i];
            

        }
        L[n1] = R[n2] = INF;
        L1[n1] = R1[n2] = INF;
        


        for (int k = p, i = 0, j = 0; k <= r; k++) {
            if (L[i] <= R[j]) {
                a[k] = L[i];
                b[k] = L1[i++];
                

            } else {
                a[k] = R[j];
                b[k] = R1[j++];
                

            }
        }
    }

    public static int[] sieve(int n) {
        int a[] = new int[n + 1];
        for (int i = 2; i <= n; i++) {
            a[i] = 1;
        }
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (a[i] == 1) {
                for (int k = 2; i * k <= n; k++) {
                    a[i * k] = 0;
                }
            }
        }
        return a;
    }

    public static long sum(int a) {
        long su = 0;
        while (a > 0) {
            su += (long) a % 10;
            a /= 10;
        }
        return su;
    }

    public static int divi(int b) {
        int n = 0;
        for (int i = 2; i <= Math.sqrt(b); i++) {
            if (b % i == 0) {
                n = i;
                break;
            }
        }
        if (n == 0) {
            return b;
        }
        return n;
    }

    public static boolean prime(int n) {
        if (n == 1) {
            return true;
        }

        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static String reve(int a, int b, String s) {
        String q = "";
        for (int i = b; i >= a; i--) {
            q += s.charAt(i);
        }
        return q;
    }

    public static boolean id3(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            return true;
        } else {
            return false;
        }
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static int hole(int n) {
        int y = 0;
        if (n == 1) {
            return 0;
        }
        if (prime(n)) {
            return 1;
        }
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                if (prime(i)) {
                    y++;
                }
                if (prime(n / i) && i != (n / i)) {
                    y++;
                }
            }
        }
        return y;
    }

    static List<Integer> gd(int a, int b) {
        int m = (int) gcd(a, b);
        List<Integer> q = new ArrayList();
        for (int i = 1; i * i <= m; ++i) {
            if (m % i == 0) {
                q.add(i);
                if (i != m / i) {
                    q.add(m / i);
                }
            }
        }
        return q;
    }

    static boolean contain(int[] a) {
        for (int i = 1; i < a.length; i++) {
            if (a[i] == 0) {
                return true;
            }
        }
        return false;
    }

    static void decrease(int[] a) {
        for (int i = 1; i < a.length; i++) {
            a[i]--;
        }
    }

    static long power(StringBuilder s) {
        long c = 1, sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'C') {
                c *= 2;
            } else {
                sum += c;
            }
        }
        return sum;
    }

    static long sum(long n) {
        return n * (n + 1) / 2;
    }

    static int id0(int n) {
        Set<Integer> c = new HashSet();
        for (int i = 1; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                c.add(i);
                c.add((int) (n / i));
            }
        }
        return c.size();
    }

    static boolean cal(int val, int k, int t) {
        int res = val, p = 1;
        while (val / Math.pow(k, p) > 0) {
            res += val / Math.pow(k, p);
            p++;
        }
        return res >= t;
    }

    static int id1(List<Long> a, int n, long v) {
        int start = 0, end = n - 1, mid, ans = -1;

        while (start <= end) {
            mid = (start + end) >> 1;
            if (a.get(mid) > v) {
                ans = mid;
                end = mid - 1;
            } else if (a.get(mid) < v) {
                

                start = mid + 1;
            } else {
                return mid;
            }

        }
        return ans;
    }

    static void print(int a, String s) {

        if (a > 0) {
            

            System.out.println(s);
            print(a - 1, '*' + s);
        } else {
            return;
        }
    }

    static long max(int[] a) {

        long m = 0;
        int max = a[a.length - 1];
        for (int i = a.length - 1; i > 0; i--) {
            if (a[i] == a[i - 1]) {
                m++;
            }
        }
        if (m == 0) {
            m++;
        }
        return m;
    }

    static long summtion(long[] a) {
        long s = 0;
        for (int i = 1; i < a.length; i++) {
            s += a[i];
        }
        return s;
    }

    static boolean vv(int i, int j, int n, int m) {
        if (i >= 0 && i < n && j < m && j >= 0) {
            return true;
        }
        return false;
    }

    static boolean valid(char[][] a, int i, int j, int n, int m) {
        char k = a[i][j];
        if (Character.isDigit(k)) {
            int co = 0;
            if (vv(i, j + 1, n, m)) {

                if (a[i][j + 1] == '*') {
                    co++;
                }
            }
            if (vv(i + 1, j, n, m)) {

                if (a[i + 1][j] == '*') {
                    co++;
                }
            }
            if (vv(i + 1, j + 1, n, m)) {

                if (a[i + 1][j + 1] == '*') {
                    co++;
                }
            }
            if (vv(i - 1, j, n, m)) {

                if (a[i - 1][j] == '*') {
                    co++;
                }
            }
            if (vv(i, j - 1, n, m)) {

                if (a[i][j - 1] == '*') {
                    co++;
                }
            }
            if (vv(i - 1, j - 1, n, m)) {

                if (a[i - 1][j - 1] == '*') {
                    co++;
                }
            }
            if (vv(i - 1, j + 1, n, m)) {
                if (a[i - 1][j + 1] == '*') {
                    co++;
                }
            }
            if (vv(i + 1, j - 1, n, m)) {
                if (a[i + 1][j - 1] == '*') {
                    co++;
                }
            }
            if (co == Integer.parseInt(k + "")) {
                return true;
            }
            return false;
        } else if (k == '.') {
            if (vv(i, j + 1, n, m)) {

                if (a[i][j + 1] == '*') {
                    return false;
                }
            }
            if (vv(i + 1, j, n, m)) {

                if (a[i + 1][j] == '*') {
                    return false;
                }
            }
            if (vv(i + 1, j + 1, n, m)) {

                if (a[i + 1][j + 1] == '*') {
                    return false;
                }
            }
            if (vv(i - 1, j, n, m)) {

                if (a[i - 1][j] == '*') {
                    return false;
                }
            }
            if (vv(i, j - 1, n, m)) {

                if (a[i][j - 1] == '*') {
                    return false;
                }
            }
            if (vv(i - 1, j - 1, n, m)) {

                if (a[i - 1][j - 1] == '*') {
                    return false;
                }
            }
            if (vv(i - 1, j + 1, n, m)) {
                if (a[i - 1][j + 1] == '*') {
                    return false;
                }
            }
            if (vv(i + 1, j - 1, n, m)) {
                if (a[i + 1][j - 1] == '*') {
                    return false;
                }
            }

        }
        return true;
    }

    static double fact(long n) {
        if (n == 1 || n == 0) {
            return 1.0;
        }
        return (double) (n * fact(n - 1));
    }

    static boolean reachUp(char[][] a, int i, int j) {
        for (int k = i - 1; k >= 0; k--) {
            if (a[k][j] == 'W' || a[k][j] == 'B') {
                return false;
            }
        }
        return true;
    }

    static boolean reachDown(char[][] a, int i, int j) {
        for (int k = i + 1; k <= 7; k++) {
            if (a[k][j] != '.') {
                return false;
            }
        }
        return true;
    }

    static void prin(char[] a, TreeSet<Character> s, int k, int p, PrintWriter or) {
        int c = s.size();
        List<Character> e = new ArrayList<>();
        for (int i = 0; c != 26; i++) {
            if (!s.contains((char) (i + 'A'))) {
                e.add((char) (i + 'A'));
                c++;
            }
        }
        for (int i = k, o = 0; i <= p; i++) {
            if (a[i] == '?') {
                a[i] = e.get(o++);
            }
        }
        for (int j = 0; j < a.length; j++) {
            if (a[j] == '?') {
                or.print('A');
            } else {
                or.print(a[j]);
            }
        }
        or.flush();
    }

    public static void main(String[] args) throws IOException, ParseException {
        id2 in = new id2(System.in);
        PrintWriter or = new PrintWriter(System.out);
        

        

        int n = in.nextInt(), p = in.nextInt();
        char[] a = in.nextLine().toCharArray();
        boolean c = false;
        for (int i = 0; i < n - p; i++) {
            if (a[i] == a[i + p] && a[i] != '.') {
            } else {
                c = true;
            }
        }
        if (!c) {
            System.out.println("NO");
            return;
        }
        for (int i = 0; i + p < n; i++) {
            if (a[i] == a[i + p]) {
                if (a[i] == '.') {
                    a[i] = '0';
                    a[i + p] = '1';
                }
            } else if (a[i] == '.') {
                a[i] = (char) (a[i + p] ^ 1);
            } else if (a[i + p] == '.') {
                a[i + p] = (char) (a[i] ^ 1);
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i] == '.') {
                a[i] = '0';
            }

        }
        for (int i = 0; i < n; i++) {
            or.print(a[i]);
        }

        or.flush();
    }

    static class id2 {

        StringTokenizer st;
        BufferedReader br;

        public id2(FileReader fileReader) throws FileNotFoundException {
            br = new BufferedReader(fileReader);
        }

        public id2(InputStream s) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public double nextDouble() throws IOException {
            String x = next();
            StringBuilder sb = new StringBuilder("0");
            double res = 0, f = 1;
            boolean dec = false, neg = false;
            int start = 0;
            if (x.charAt(0) == '-') {
                neg = true;
                start++;
            }
            for (int i = start; i < x.length(); i++) {
                if (x.charAt(i) == '.') {
                    res = Long.parseLong(sb.toString());
                    sb = new StringBuilder("0");
                    dec = true;
                } else {
                    sb.append(x.charAt(i));
                    if (dec) {
                        f *= 10;
                    }
                }
            }
            res += Long.parseLong(sb.toString()) / f;
            return res * (neg ? -1 : 1);
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public boolean ready() throws IOException {
            return br.ready();
        }

    }

}

class Pair {

    int ind;
    int val;
    int u;

    public Pair(int n, int p, int r) {
        ind = n;
        val = p;
        u = r;
    }

}
