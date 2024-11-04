import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class D {
    private final static int oo = Integer.MAX_VALUE;
    private final static int id0 = 1000000;
    private boolean[] id1 = new boolean[id0];
    private final static int id3 = 3385;
    private long[] primes = new long[id3];
    int[] dx4 = { -1, 0, 1, 0 };
    int[] dy4 = { 0, 1, 0, -1 };
    int[] dx6 = { -1, -1, 0, 0, 1, 1 };
    int[] dy6 = { -1, 0, -1, 1, 0, 1 };
    int[] dx8 = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int[] dy8 = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int[] kdx = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int[] kdy = { -1, -2, -2, -1, 1, 2, 2, 1 };
    String[] id2 = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
            "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
    private final static String DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    private final static String SYMBOLS = " \t\n\r\b~!@

    private String readLine() {
        StringBuffer sb = new StringBuffer();
        int b = 0;
        while (b != '\n' && b >= 0) {
            try {
                b = System.in.read();
            } catch (IOException e) {
                return null;
            }
            if (b != '\r' && b != '\n' && b >= 0) {
                sb.append((char) b);
            }
        }
        if (sb.length() == 0 && b < 0) {
            return null;
        }
        return sb.toString().trim();
    }

    private int parseInt(String s) {
        int result = 0;
        int sign = (s.charAt(0) == '-') ? -1 : 1;
        if (sign == -1) {
            s = s.substring(1);
        }
        if (s.charAt(0) == '+') {
            s = s.substring(1);
        }
        int i = 0, max = s.length();
        if (max > 0) {
            while (i < max) {
                result *= 10;
                result += s.charAt(i++) - 48;
            }
        }
        return sign * result;
    }

    private long parseLong(String s) {
        long result = 0;
        int sign = (s.charAt(0) == '-') ? -1 : 1;
        if (sign == -1) {
            s = s.substring(1);
        }
        int i = 0, max = s.length();
        if (max > 0) {
            while (i < max) {
                result *= 10;
                result += s.charAt(i++) - 48;
            }
        }
        return sign * result;
    }

    private double parseDouble(String s) {
        double exp = 1;
        if (s.indexOf('e') != -1) {
            int e = parseInt(s.substring(s.indexOf('e') + 1));
            exp = Math.pow(10, e);
            s = s.substring(0, s.indexOf('e'));
        }
        if (s.indexOf('E') != -1) {
            int e = parseInt(s.substring(s.indexOf('E') + 1));
            exp = Math.pow(10, e);
            s = s.substring(0, s.indexOf('E'));
        }
        double result = 0;
        int sign = (s.charAt(0) == '-') ? -1 : 1;
        if (sign == -1) {
            s = s.substring(1);
        }
        int i = 0, max = s.length();
        boolean dot = false;
        if (max > 0) {
            while (i < max) {
                if (s.charAt(i) == '.') {
                    dot = true;
                    break;
                }
                result *= 10;
                result += s.charAt(i++) - 48;
            }
            if (dot) {
                i++;
                double dec = 0.1;
                while (i < max) {
                    result += dec * (s.charAt(i++) - 48);
                    dec /= 10;
                }
            }
        }
        return exp * sign * result;
    }

    private String fmt(double d, int prec) {
        d += 1e-12;
        long pow10 = 1;
        for (int i = 0; i < prec; i++) {
            pow10 *= 10;
        }
        long l = Math.round(pow10 * d);
        String sign = "";
        if (l < 0) {
            sign = "-";
            l = 0 - l;
        }
        String s = Long.toString(l);
        int len = s.length();
        for (int i = 0; i < prec + 1 - len; i++) {
            s = "0" + s;
        }
        len = s.length();
        return sign + s.substring(0, len - prec) + "." + s.substring(len - prec);
    }

    private boolean isPrime(long p) {
        if (p < 2) {
            return false;
        }
        for (int i = 0; i < id3; i++) {
            if (primes[i] * primes[i] > p) {
                return true;
            }
            if (p % primes[i] == 0) {
                return false;
            }
        }
        return true;
    }

    private void sieve() {
        id1[0] = true;
        id1[1] = true;
        for (int i = 4; i < id0; i += 2) {
            id1[i] = true;
        }
        for (int i = 3; i <= (int) Math.round(Math.sqrt(id0)) + 1; i += 2) {
            if (!id1[i]) {
                int tmp = i * i;
                while (tmp < id0) {
                    id1[tmp] = true;
                    tmp += i << 1;
                }
            }
        }
    }

    private void sort(int array[], int begin, int end) {
        int mid;
        if (end - begin <= 1) {
            return;
        }
        mid = (begin + end) / 2;
        sort(array, begin, mid);
        sort(array, mid, end);
        merge(array, begin, mid, end);
    }

    private void merge(int[] array, int start, int mid, int end) {
        int i = start;
        int j = mid;
        int k = 0;
        int[] temp = new int[end - start];
        while ((i < mid) && (j < end)) {
            if (array[i] <= array[j]) {
                temp[k++] = array[i++];
            } else {
                temp[k++] = array[j++];
            }
        }
        while (i < mid) {
            temp[k++] = array[i++];
        }
        while (j < end) {
            temp[k++] = array[j++];
        }
        for (i = start; i < end; i++) {
            array[i] = temp[i - start];
        }
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    private boolean nextPerm(int[] a) {
        if (a.length <= 1) {
            return false;
        }
        int i = a.length - 1;
        while (a[i - 1] >= a[i]) {
            i--;
            if (i == 0) {
                return false;
            }
        }
        int j = a.length;
        while (a[j - 1] <= a[i - 1]) {
            j--;
            if (j == 0) {
                return false;
            }
        }
        int tmp = a[i - 1];
        a[i - 1] = a[j - 1];
        a[j - 1] = tmp;
        i++;
        j = a.length;
        while (i < j) {
            tmp = a[i - 1];
            a[i - 1] = a[j - 1];
            a[j - 1] = tmp;
            i++;
            j--;
        }
        return true;
    }

    

    private void heapPerm(int n, int[] a) {
        if (n == 0) {
            

        } else {
            for (int i = 0; i < n; i++) {
                heapPerm(n - 1, a);
                if ((n & 1) == 0) { 

                    int tmp = a[i];
                    a[i] = a[n - 1];
                    a[n - 1] = tmp;
                } else {
                    

                    int tmp = a[0];
                    a[0] = a[n - 1];
                    a[n - 1] = tmp;
                }
            }
        }
    }

    private int editDistance(char[] ca1, char[] ca2) {
        int len1 = ca1.length;
        int len2 = ca2.length;
        int[][] d = new int[len1 + 1][len2 + 1];
        for (int i = 0; i <= len1; i++) {
            d[i][0] = i;
        }
        for (int j = 0; j <= len2; j++) {
            d[0][j] = j;
        }
        for (int i = 1; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                d[i][j] = Math.min(d[i - 1][j] + 1,
                        Math.min(d[i][j - 1] + 1, d[i - 1][j - 1] + (ca1[i - 1] == ca2[j - 1] ? 0 : 1)));
            }
        }
        return d[len1][len2];
    }

    private void reverse(int[] a, int start, int end) {
        if (start > end) {
            reverse(a, end, start);
            return;
        }
        int dif = end - start;
        int[] tmp = new int[dif + 1];
        for (int i = start; i <= end; i++) {
            tmp[i - start] = a[i];
        }
        for (int i = dif; i >= 0; i--) {
            a[start + dif - i] = tmp[i];
        }
    }

    private void print(int[][] grid) {
        System.out.println("=========================================");
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                System.out.print(grid[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("=========================================");
    }

    private int snoob(int x) {
        int smallest, ripple, ones;
        smallest = x & -x;
        ripple = x + smallest;
        ones = x ^ ripple;
        ones = (ones >>> 2) / smallest;
        x = ripple | ones;
        return x;
    }

    private double fastPow(double n, int k) {
        if (k == 1) {
            return n;
        }
        while (n > 1000) {
            n /= 1000;
        }
        return (k & 1) == 0 ? fastPow(n * n, k >> 1) : n * fastPow(n, k - 1);
    }

    private long powMod(long n, long k, long m) {
        long r = 1;
        for (int i = (1 << 30); i != 0; i >>= 1) {
            r *= r;
            r %= m;
            if ((k & i) != 0) {
                r *= n;
                r %= m;
            }
        }
        return r;
    }

    

    private void floyd(int[][] dist, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && dist[j][i] != oo) {
                    for (int k = 0; k < n; k++) {
                        if (j != k && dist[i][k] != oo) {
                            if (dist[j][k] > dist[j][i] + dist[i][k]) {
                                dist[j][k] = dist[j][i] + dist[i][k];
                            }
                        }
                    }
                }
            }
        }
    }

    
    private boolean rectFit(long a, long b, long c, long d) {
        if (c < d) {
            long t = c;
            c = d;
            d = t;
        }
        if (a < b) {
            long t = a;
            a = b;
            b = t;
        }
        if (a <= c && b <= d) {
            return true;
        }
        if (b > d) {
            return false;
        }
        double dsq = a * a + b * b;
        if (dsq <= d * d) {
            return true;
        }
        if (dsq > c * c + d * d) {
            return false;
        }
        double xc = 0.5 * (c - Math.sqrt(dsq - d * d));
        double xd = 0.5 * (d - Math.sqrt(dsq - c * c));
        double res = xc * xc + xd * xd;
        if (res < b * b - 1e-10) {
            return false;
        }
        return true;
    }

    private int bitCount(int i) {
        

        i = i - ((i >>> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
        i = (i + (i >>> 4)) & 0x0f0f0f0f;
        i = i + (i >>> 8);
        i = i + (i >>> 16);
        return i & 0x3f;
    }

    private int lcsLen(char[] s1, char[] s2) {
        int m = s1.length;
        int n = s2.length;
        int[][] c = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    c[i][j] = c[i - 1][j - 1] + 1;
                } else if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                } else {
                    c[i][j] = c[i][j - 1];
                }
            }
        }
        return c[m][n];
    }

    private double toRadians(double angdeg) {
        return angdeg / 180.0 * Math.PI;
    }

    private double greatCircleDistance(double r, double lattitude0, double longitude0, double lattitude1,
                                       double longitude1) {
        double dlam = longitude1 - longitude0;
        double y = Math.cos(lattitude0) * Math.sin(lattitude1)
                - Math.sin(lattitude0) * Math.cos(lattitude1) * Math.cos(dlam);
        y = y * y;
        y += Math.cos(lattitude0) * Math.cos(lattitude0) * Math.sin(dlam) * Math.sin(dlam);
        y = Math.sqrt(y);
        double x = Math.sin(lattitude0) * Math.sin(lattitude1)
                + Math.cos(lattitude0) * Math.cos(lattitude1) * Math.cos(dlam);
        return r * Math.atan2(y, x);
    }

    

    private int getSmallestCircularString(int n, char[] str) {
        int[] f = new int[2 * n];
        f[0] = -1;
        int k = 0;
        for (int j = 1; j < 2 * n; j++) {
            

            

            

            

            int i = f[j - k - 1];
            while (i >= 0 && str[j] != str[k + i + 1]) {
                if (str[j] < str[k + i + 1]) {
                    k = j - i - 1;
                }
                i = f[i];
            }
            if (i < 0 && str[j] != str[k + i + 1]) {
                if (str[j] < str[k + i + 1]) {
                    k = j;
                }
                f[j - k] = -1;
            } else {
                f[j - k] = i + 1;
            }
        }
        return k;
    }

    private int[] countDigitsUsedUpTo(int N) {
        int[] ret = new int[10];
        if (N < 10) {
            for (int i = 1; i <= N; i++) {
                ret[i] = 1;
            }
            return ret;
        }
        while (N % 10 != 9) {
            int t = N--;
            while (t > 0) {
                ret[t % 10]++;
                t /= 10;
            }
        }
        N++;
        for (int i = 0; i < 10; i++) {
            ret[i] += N / 10;
        }
        int[] tmp = countDigitsUsedUpTo(N / 10 - 1);
        for (int i = 0; i < 10; i++) {
            ret[i] += 10 * tmp[i];
        }
        ret[0]--;
        return ret;
    }

    private void work() {
        String[] spl = readLine().split(" ");
        n = parseInt(spl[0]);
        m = parseInt(spl[1]);
        a = new int[m][];
        pos = new int[m][];
        for (int i = 0; i < m; i++) {
            a[i] = new int[n];
            pos[i] = new int[n];
            spl = readLine().split(" ");
            for (int j = 0; j < n; j++) {
                a[i][j] = parseInt(spl[j]) - 1;
                pos[i][a[i][j]] = j;
            }
        }

        len = new int[n];
        long res = 0;
        for (int i = 0; i < n; i++) {
            if (len[i] == 0) go(i);
            res += len[i];
        }

        System.out.println(res);
    }

    private int go(int k) {
        if (len[k] > 0) return len[k];
        if (pos[0][k] == n - 1) {
            return len[k] = 1;
        }

        int next = a[0][pos[0][k] + 1];
        int i = 1;
        while (i < m) {
            if (pos[i][k] == n - 1 || a[i][pos[i][k] + 1] != next) break;
            i++;
        }

        if (i < m) return len[k] = 1;
        return len[k] = 1 + go(next);
    }

    private int n, m, len[], a[][], pos[][];

    public static void main(String[] args) {
        new D().work();
    }
}
