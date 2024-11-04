import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class Main {

    static class Pair
    {
        long l;
        char c;
        public Pair(long l,char c)
        {
            this.l = l;
            this.c=c;
        }
        public String toString() {
            return l +" "+c;
        }
    }

    static class Node
    {
        int val;
        Node left,right;
        public Node(int val,Node left,Node right)
        {
            this.val=val;
            this.left=left;
            this.right=right;
        }
    }

    static final int INF = 1 << 30;
    static final long INFL = 1L << 60;
    static final long NINF = INFL * -1;
    static final long mod = (long) 1e9 + 7;
    static final long mod2 = 998244353;
    static DecimalFormat df = new DecimalFormat("0.00000000000000");
    public static final double PI = 3.141592653589793d, eps = 1e-9;

    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC
    {
        public static void solve(int testNumber, InputReader in, OutputWriter out)
        {
            int t1=in.readInt();
            while (t1-->0)
            {
                long n=in.nextLong();
                long olcm=1,ans=0,nlcm=0;
                for(long i=2;olcm<=n;++i)
                {
                    nlcm=olcm/CP.gcd(olcm,i)*i;
                    ans=(ans%mod+((n/olcm)-(n/nlcm))*i)%mod;
                    olcm=nlcm;
                }
                out.printLine(ans);
            }
        }
    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id25 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (id5(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id5(c));
            return res * sgn;
        }

        public int[] id16(int arraySize) {
            int[] array = new int[arraySize];

            for (int i = 0; i < arraySize; i++) {
                array[i] = readInt();
            }

            return array;
        }

        private int skip() {
            int b;
            while ((b = read()) != -1 && id5(b)) ;
            return b;
        }

        private String ns() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!(id5(b))) { 

                sb.appendCodePoint(b);
                b = read();
            }
            return sb.toString();
        }

        private char[] ns(int n) {
            char[] buf = new char[n];
            int b = skip(), p = 0;
            while (p < n && !(id5(b))) {
                buf[p++] = (char) b;
                b = read();
            }
            return n == p ? buf : Arrays.copyOf(buf, p);
        }

        public String readString() {
            int c = read();
            while (id5(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id5(c));
            return res.toString();
        }

        public boolean id11(int c) {
            return c == '\n';
        }

        public String nextLine() {
            int c = read();

            StringBuilder result = new StringBuilder();

            do {
                result.appendCodePoint(c);

                c = read();
            } while (!id11(c));

            return result.toString();
        }

        public long nextLong() {
            int c = read();

            while (id5(c)) {
                c = read();
            }

            int sign = 1;

            if (c == '-') {
                sign = -1;

                c = read();
            }

            long result = 0;

            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }

                result *= 10;
                result += c & 15;

                c = read();
            } while (!id5(c));

            return result * sign;
        }

        public long[] id29(int arraySize) {
            long array[] = new long[arraySize];

            for (int i = 0; i < arraySize; i++) {
                array[i] = nextLong();
            }

            return array;
        }

        public double nextDouble() {
            double ret = 0, div = 1;
            byte c = (byte) read();

            while (c <= ' ') {
                c = (byte) read();
            }

            boolean neg = (c == '-');

            if (neg) {
                c = (byte) read();
            }

            do {
                ret = ret * 10 + c - '0';
            } while ((c = (byte) read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = (byte) read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg) {
                return -ret;
            }

            return ret;
        }

        public boolean id5(int c) {
            if (filter != null) {
                return filter.id5(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface id25 {
            public boolean id5(int ch);

        }
    }

    public static class CP {

        static boolean isp(long n) {
            if (n <= 1)
                return false;
            if (n == 2 || n == 3)
                return true;
            if (n % 2 == 0 || n % 3 == 0)
                return false;
            for (int i = 5; (long) i * i <= n; i += 6) {
                if (n % i == 0 || n % (i + 2) == 0)
                    return false;
            }
            return true;
        }

        public static int log2(int N) {
            int result = (int) (Math.log(N) / Math.log(2));
            return result;
        }

        public static long pow(long a, long n, long mod) {
            

            long ret = 1;
            int x = 63 - Long.numberOfLeadingZeros(n);
            for (; x >= 0; x--) {
                ret = ret * ret % mod;
                if (n << 63 - x < 0)
                    ret = ret * a % mod;
            }
            return ret;
        }

        public static boolean isComposite(long n) {
            if (n < 2)
                return true;
            if (n == 2 || n == 3)
                return false;
            if (n % 2 == 0 || n % 3 == 0)
                return true;
            for (long i = 6L; i * i <= n; i += 6)
                if (n % (i - 1) == 0 || n % (i + 1) == 0)
                    return true;
            return false;
        }

        static int id3(int[] prime, int x) {

            return (prime[x / 64] & (1 << ((x >> 1) & 31)));
        }

        static int log2(long n) {
            return (int) (Math.log10(n) / Math.log10(2));
        }

        static void makeComposite(int[] prime, int x) {

            prime[x / 64] |= (1 << ((x >> 1) & 31));
        }

        public static String swap(String a, int i, int j) {
            char temp;
            char[] charArray = a.toCharArray();
            temp = charArray[i];
            charArray[i] = charArray[j];
            charArray[j] = temp;
            return String.valueOf(charArray);
        }

        public static int[] id2(int n) {
            if (n <= 32) {
                int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
                for (int i = 0; i < primes.length; i++) {
                    if (n < primes[i]) {
                        return Arrays.copyOf(primes, i);
                    }
                }
                return primes;
            }

            int u = n + 32;
            double lu = Math.log(u);
            int[] ret = new int[(int) (u / lu + u / lu / lu * 1.5)];
            ret[0] = 2;
            int pos = 1;

            int[] isnp = new int[(n + 1) / 32 / 2 + 1];
            int sup = (n + 1) / 32 / 2 + 1;

            int[] id15 = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
            for (int tp : id15) {
                ret[pos++] = tp;
                int[] ptn = new int[tp];
                for (int i = (tp - 3) / 2; i < tp << 5; i += tp)
                    ptn[i >> 5] |= 1 << (i & 31);
                for (int j = 0; j < sup; j += tp) {
                    for (int i = 0; i < tp && i + j < sup; i++) {
                        isnp[j + i] |= ptn[i];
                    }
                }
            }

            

            

            int[] magic = {0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4,
                    13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14};
            int h = n / 2;
            for (int i = 0; i < sup; i++) {
                for (int j = ~isnp[i]; j != 0; j &= j - 1) {
                    int pp = i << 5 | magic[(j & -j) * 0x076be629 >>> 27];
                    int p = 2 * pp + 3;
                    if (p > n)
                        break;
                    ret[pos++] = p;
                    if ((long) p * p > n)
                        continue;
                    for (int q = (p * p - 3) / 2; q <= h; q += p)
                        isnp[q >> 5] |= 1 << q;
                }
            }

            return Arrays.copyOf(ret, pos);
        }

        static int digit(long s) {
            int brute = 0;
            while (s > 0) {
                s /= 10;
                brute++;
            }
            return brute;
        }

        public static int[] id26(int n, int[] primes) {
            int[] ret = new int[15];
            int rp = 0;
            for (int p : primes) {
                if (p * p > n) break;
                int i;
                for (i = 0; n % p == 0; n /= p, i++) ;
                if (i > 0) ret[rp++] = p;
            }
            if (n != 1) ret[rp++] = n;
            return Arrays.copyOf(ret, rp);
        }


        static ArrayList<Integer> id20(int n) {
            ArrayList<Integer> al = new ArrayList<>();
            int prime[] = new int[n / 64 + 1];


            for (int i = 3; i * i <= n; i += 2) {

                if (id3(prime, i) == 0)
                    for (int j = i * i, k = i << 1;
                         j < n; j += k)
                        makeComposite(prime, j);
            }

            al.add(2);

            for (int i = 3; i <= n; i += 2)
                if (id3(prime, i) == 0)
                    al.add(i);

            return al;
        }

        public static long[] sort(long arr[]) {
            List<Long> list = new ArrayList<>();
            for (long n : arr) {
                list.add(n);
            }
            Collections.sort(list);
            for (int i = 0; i < arr.length; i++) {
                arr[i] = list.get(i);
            }
            return arr;
        }

        public static long[] revsort(long[] arr) {
            List<Long> list = new ArrayList<>();
            for (long n : arr) {
                list.add(n);
            }
            Collections.sort(list, Collections.reverseOrder());
            for (int i = 0; i < arr.length; i++) {
                arr[i] = list.get(i);
            }
            return arr;
        }

        public static int[] revsort(int[] arr) {
            List<Integer> list = new ArrayList<>();
            for (int n : arr) {
                list.add(n);
            }
            Collections.sort(list, Collections.reverseOrder());
            for (int i = 0; i < arr.length; i++) {
                arr[i] = list.get(i);
            }
            return arr;
        }


        public static ArrayList<Integer> reverse(
                ArrayList<Integer> data,
                int left, int right)
        {
            

            while (left < right)
            {
                int temp = data.get(left);
                data.set(left++,
                        data.get(right));
                data.set(right--, temp);
            }

            

            return data;
        }

        static ArrayList<Integer> sieve(long size) {

            ArrayList<Integer> pr = new ArrayList<Integer>();
            boolean prime[] = new boolean[(int) size];
            for (int i = 2; i < prime.length; i++) prime[i] = true;
            for (int i = 2; i * i < prime.length; i++) {
                if (prime[i]) {
                    for (int j = i * i; j < prime.length; j += i) {
                        prime[j] = false;
                    }
                }
            }
            for (int i = 2; i < prime.length; i++) if (prime[i]) pr.add(i);
            return pr;
        }

        static ArrayList<Integer> id17(int l, int r, ArrayList<Integer> primes) {
            ArrayList<Integer> al = new ArrayList<>();
            if (l == 1) ++l;
            int max = r - l + 1;
            int arr[] = new int[max];
            for (int p : primes) {
                if (p * p <= r) {
                    int i = (l / p) * p;
                    if (i < l) i += p;
                    for (; i <= r; i += p) {
                        if (i != p) {
                            arr[i - l] = 1;
                        }
                    }
                }
            }
            for (int i = 0; i < max; ++i) {
                if (arr[i] == 0) {
                    al.add(l + i);
                }
            }
            return al;
        }

        static boolean id8(long n, int iteration) {

            if (n == 0 || n == 1)
                return false;

            if (n == 2)
                return true;

            if (n % 2 == 0)
                return false;

            Random rand = new Random();
            for (int i = 0; i < iteration; i++) {
                long r = Math.abs(rand.nextLong());
                long a = r % (n - 1) + 1;
                if (modPow(a, n - 1, n) != 1)
                    return false;
            }
            return true;
        }

        static long modPow(long a, long b, long c) {
            long res = 1;
            for (int i = 0; i < b; i++) {
                res *= a;
                res %= c;
            }
            return res % c;
        }

        private static long binPower(long a, long l, long mod) {

            long res = 0;

            while (l > 0) {
                if ((l & 1) == 1) {
                    res = mulmod(res, a, mod);
                    l >>= 1;
                }
                a = mulmod(a, a, mod);
            }
            return res;
        }

        private static long mulmod(long a, long b, long c) {

            long x = 0, y = a % c;
            while (b > 0) {
                if (b % 2 == 1) {
                    x = (x + y) % c;
                }
                y = (y * 2L) % c;
                b /= 2;
            }
            return x % c;

        }

        static long id10(long a, long b) {
            long res = 1;
            while (b != 0) {
                if ((b & 1) == 1) {
                    res *= a;
                    --b;
                }
                a *= a;
                b /= 2;
            }
            return res;
        }

        static void swap(int a, int b) {
            int tp = b;
            b = a;
            a = tp;
        }

        static long id0(long a, long b, long mod) {
            long res = 1;
            while (b != 0) {
                if ((b & 1) == 1) {
                    res = (res * a) % mod;
                    --b;
                }
                a = (a * a) % mod;
                b /= 2;
            }
            return res % mod;
        }

        static int id18(int a, int b) {
            while (true) {
                if (b == 0)
                    return a;
                int c = a;
                a = b;
                b = c % b;
            }
        }

        static long gcd(long a, long b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

        static long ceil_div(long a, long b) {
            return (a + b - 1) / b;
        }

        static int id23(int bits, int i) {
            return (bits >> (i - 1)) & 1;
        }

        private static TreeMap<Long, Long> id1(long n) {
            TreeMap<Long, Long> pf = new TreeMap<>(Collections.reverseOrder());
            long cnt = 0;
            long total = 1;
            for (long i = 2; (long) i * i <= n; ++i) {
                if (n % i == 0) {
                    cnt = 0;
                    while (n % i == 0) {
                        ++cnt;
                        n /= i;
                    }
                    pf.put(cnt, i);
                    

                }
            }
            if (n > 1) {
                pf.put(1L, n);
                

            }
            return pf;
        }

        

        private static int lower_bound(List<Integer> list, int val) {
            int ans = -1, lo = 0, hi = list.size() - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (list.get(mid) <= val) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            return ans;
        }

        private static int lower_bound(int[] arr, int val) {
            int ans = -1, lo = 0, hi = arr.length - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (arr[mid] <= val) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            return ans;
        }

        private static int lower_bound(long[] arr, long val) {
            int ans = -1, lo = 0, hi = arr.length - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (arr[mid] <= val) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            return ans;
        }

        

        private static int upper_bound(List<Integer> list, int val) {
            int ans = list.size(), lo = 0, hi = ans - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (list.get(mid) >= val) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            return ans;
        }

        private static int upper_bound(int[] arr, int val) {
            int ans = arr.length, lo = 0, hi = ans - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (arr[mid] >= val) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            return ans;
        }

        private static int upper_bound(long[] arr, long val) {
            int ans = arr.length, lo = 0, hi = ans - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (arr[mid] >= val) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            return ans;
        }

        


        private static int LIS(int arr[], int n) {
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int idx = find1(list, arr[i]);
                if (idx < list.size())
                    list.set(idx, arr[i]);
                else
                    list.add(arr[i]);
            }
            return list.size();
        }

        private static int find1(List<Integer> list, int val) {
            int ret = list.size(), i = 0, j = list.size() - 1;
            while (i <= j) {
                int mid = (i + j) / 2;
                if (list.get(mid) >= val) {
                    ret = mid;
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
            }
            return ret;
        }

        private static int LNDS(int[] arr, int n) {
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int idx = find2(list, arr[i]);
                if (idx < list.size())
                    list.set(idx, arr[i]);
                else
                    list.add(arr[i]);
            }
            return list.size();
        }

        private static int find2(List<Integer> list, int val) {
            int ret = list.size(), i = 0, j = list.size() - 1;
            while (i <= j) {
                int mid = (i + j) / 2;
                if (list.get(mid) <= val) {
                    i = mid + 1;
                } else {
                    ret = mid;
                    j = mid - 1;
                }
            }
            return ret;
        }

        private static long nCr(long n, long r) {
            if (n - r > r)
                r = n - r;
            long ans = 1L;
            for (long i = r + 1; i <= n; i++)
                ans *= i;
            for (long i = 2; i <= n - r; i++)
                ans /= i;
            return ans;
        }

        private static boolean isPalindrome(String str) {
            int i = 0, j = str.length() - 1;
            while (i < j)
                if (str.charAt(i++) != str.charAt(j--))
                    return false;
            return true;
        }

        private static String reverseString(String str) {
            StringBuilder sb = new StringBuilder(str);
            return sb.reverse().toString();
        }

        private static String sortString(String str) {
            int[] arr = new int[256];
            for (char ch : str.toCharArray())
                arr[ch]++;
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 256; i++)
                while (arr[i]-- > 0)
                    sb.append((char) i);
            return sb.toString();
        }

        static boolean id28(int x, int factor, int target) {
            int s = (int) Math.round(Math.sqrt(x));
            return factor * s * s == target;
        }

        static boolean isSquare(int x) {
            int s = (int) Math.round(Math.sqrt(x));
            return x * x == s;
        }

        static int bs(ArrayList<Integer> al, int val) {
            int l = 0, h = al.size() - 1, mid = 0, ans = -1;
            while (l <= h) {
                mid = (l + h) >> 1;
                if (al.get(mid) == val) {
                    return mid;
                } else if (al.get(mid) > val) {
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return ans;
        }

        static void sort(int a[]) 

        {
            PriorityQueue<Integer> q = new PriorityQueue<>();
            for (int i = 0; i < a.length; i++)
                q.add(a[i]);
            for (int i = 0; i < a.length; i++)
                a[i] = q.poll();
        }

        static void shuffle(int[] in) {
            for (int i = 0; i < in.length; i++) {
                int idx = (int) (Math.random() * in.length);
                fast_swap(in, idx, i);
            }
        }


        public static int[] id24(int[] a) {
            int n = a.length;
            int[] c0 = new int[0x101];
            int[] c1 = new int[0x101];
            int[] c2 = new int[0x101];
            int[] c3 = new int[0x101];
            for (int v : a) {
                c0[(v & 0xff) + 1]++;
                c1[(v >>> 8 & 0xff) + 1]++;
                c2[(v >>> 16 & 0xff) + 1]++;
                c3[(v >>> 24 ^ 0x80) + 1]++;
            }
            for (int i = 0; i < 0xff; i++) {
                c0[i + 1] += c0[i];
                c1[i + 1] += c1[i];
                c2[i + 1] += c2[i];
                c3[i + 1] += c3[i];
            }
            int[] t = new int[n];
            for (int v : a) t[c0[v & 0xff]++] = v;
            for (int v : t) a[c1[v >>> 8 & 0xff]++] = v;
            for (int v : a) t[c2[v >>> 16 & 0xff]++] = v;
            for (int v : t) a[c3[v >>> 24 ^ 0x80]++] = v;
            return a;
        }

        static int[] id21(String pat) {
            int len = 0, i = 1, m = pat.length();
            int lps[] = new int[m];
            lps[0] = 0;
            while (i < m) {
                if (pat.charAt(i) == pat.charAt(len)) {
                    ++len;
                    lps[i] = len;
                    ++i;
                } else {
                    if (len != 0) {
                        len = lps[len - 1];
                    } else {
                        lps[i] = len;
                        ++i;
                    }
                }
            }
            return lps;
        }

        static ArrayList<Integer> kmp(String s, String pat) {
            ArrayList<Integer> al = new ArrayList<>();
            int n = s.length(), m = pat.length();
            int lps[] = id21(pat);
            int i = 0, j = 0;
            while (i < n) {
                if (s.charAt(i) == pat.charAt(j)) {
                    i++;
                    j++;
                    if (j == m) {
                        al.add(i - j);
                        j = lps[j - 1];
                    }

                } else {
                    if (j != 0) {
                        j = lps[j - 1];
                    } else {
                        i++;
                    }
                }
            }
            return al;
        }

        static void id19(int a[]) {
            shuffle(a);
            Arrays.sort(a);
            for (int l = 0, r = a.length - 1; l < r; ++l, --r)
                fast_swap(a, l, r);

        }

        static void id7(int a[]) {
            shuffle(a);
            Arrays.sort(a);
        }

        static int getMax(int arr[], int n) {
            int mx = arr[0];
            for (int i = 1; i < n; i++)
                if (arr[i] > mx)
                    mx = arr[i];
            return mx;
        }

        static ArrayList<Long> primeFactors(long n) {
            ArrayList<Long> al = new ArrayList<>();
            al.add(1L);
            while (n % 2 == 0) {
                if (!al.contains(2L)) {
                    al.add(2L);
                }
                n /= 2L;
            }

            for (long i = 3; (long) i * i <= n; i += 2) {
                while ((n % i == 0)) {
                    if (!al.contains((long) i)) {
                        al.add((long) i);
                    }
                    n /= i;
                }
            }

            if (n > 2) {
                if (!al.contains(n)) {
                    al.add(n);
                }
            }
            return al;
        }

        public static long totFactors(long n) {
            long cnt = 0, tot = 1;
            while (n % 2 == 0) {
                n /= 2;
                ++cnt;
            }
            tot *= (cnt + 1);
            for (int i = 3; i <= Math.sqrt(n); i += 2) {
                cnt = 0;
                while (n % i == 0) {
                    n /= i;
                    ++cnt;
                }
                tot *= (cnt + 1);
            }

            if (n > 2) {
                tot *= 2;
            }
            return tot;
        }

        static int[] z_function(String s) {
            int n = s.length(), z[] = new int[n];

            for (int i = 1, l = 0, r = 0; i < n; ++i) {
                if (i <= r)
                    z[i] = Math.min(z[i - l], r - i + 1);

                while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i]))
                    ++z[i];

                if (i + z[i] - 1 > r) {
                    l = i;
                    r = i + z[i] - 1;
                }
            }
            return z;
        }


        static void fast_swap(int[] a, int idx1, int idx2) {
            if (a[idx1] == a[idx2])
                return;

            a[idx1] ^= a[idx2];
            a[idx2] ^= a[idx1];
            a[idx1] ^= a[idx2];
        }

        static void fast_swap(long[] a, int idx1, int idx2) {
            if (a[idx1] == a[idx2])
                return;

            a[idx1] ^= a[idx2];
            a[idx2] ^= a[idx1];
            a[idx1] ^= a[idx2];
        }

        public static void fast_sort(long[] array) {
            ArrayList<Long> copy = new ArrayList<>();
            for (long i : array)
                copy.add(i);
            Collections.sort(copy);
            for (int i = 0; i < array.length; i++)
                array[i] = copy.get(i);
        }

        static int id6(int n) {
            boolean hash[] = new boolean[n + 1];
            Arrays.fill(hash, true);
            for (int p = 2; p * p < n; p++)
                if (hash[p] == true)
                    for (int i = p * 2; i < n; i += p)
                        hash[i] = false;

            int total = 1;
            for (int p = 2; p <= n; p++) {
                if (hash[p]) {
                    int count = 0;
                    if (n % p == 0) {
                        while (n % p == 0) {
                            n = n / p;
                            count++;
                        }
                        total = total * (count + 1);
                    }
                }
            }
            return total;
        }

        static long id22(long n, long k) {
            long res = 1;

            if (k > n - k)
                k = n - k;

            for (int i = 0; i < k; ++i) {
                res = (res * (n - i));
                res /= (i + 1);
            }
            return res;
        }

        static long nck(long fact[], long inv[], long n, long k) {
            if (k > n) return 0;
            long res = fact[(int) n];
            res = (int) ((res * inv[(int) k]));
            res = (int) ((res * inv[(int) (n - k)]));
            return res % mod;
        }

        public static long fact(long x) {
            long fact = 1;
            for (int i = 2; i <= x; ++i) {
                fact = fact * i;
            }
            return fact;
        }

        public static ArrayList<Long> getFact(long x) {

            ArrayList<Long> facts = new ArrayList<>();
            for (long i = 2; i * i <= x; ++i) {
                if (x % i == 0) {
                    facts.add(i);
                    if (i != x / i) {
                        facts.add(x / i);
                    }
                }
            }
            return facts;
        }

        static void matrix_ex(long n, long[][] A, long[][] I) {
            while (n > 0) {
                if (n % 2 == 0) {
                    Multiply(A, A);
                    n /= 2;
                } else {
                    Multiply(I, A);
                    n--;
                }
            }
        }

        static void Multiply(long[][] A, long[][] B) {

            int n = A.length, m = A[0].length, p = B[0].length;

            long[][] C = new long[n][p];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < p; j++) {
                    for (int k = 0; k < m; k++) {
                        C[i][j] += ((A[i][k] % mod) * (B[k][j] % mod)) % mod;
                        C[i][j] = C[i][j] % mod;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < p; j++) {
                    A[i][j] = C[i][j];
                }
            }
        }

        public static HashMap<Character, Integer> id13(HashMap<Character, Integer> map) {

            List<Map.Entry<Character, Integer>> list = new LinkedList<>(map.entrySet());

            Collections.sort(list, (o1, o2) -> o2.getValue() - o1.getValue());

            HashMap<Character, Integer> temp = new LinkedHashMap<>();

            for (Map.Entry<Character, Integer> i : list) {
                temp.put(i.getKey(), i.getValue());
            }
            return temp;
        }

        public static HashMap<Integer, Integer> id4(HashMap<Integer, Integer> map) {

            List<Map.Entry<Integer, Integer>> list = new LinkedList<>(map.entrySet());

            Collections.sort(list, (o1, o2) -> o1.getValue() - o2.getValue());

            HashMap<Integer, Integer> temp = new LinkedHashMap<>();

            for (Map.Entry<Integer, Integer> i : list) {
                temp.put(i.getKey(), i.getValue());
            }
            return temp;
        }

        public static long lcm(long l, long l2) {

            long val = gcd(l, l2);
            return (l * l2) / val;

        }

        public static int id9(String s, String t) {
            int n = s.length();
            int m = t.length();
            if (m > n) {
                return Integer.MAX_VALUE;
            }

            int i = 0, j = 0, skip = 0;
            while (i < n && j < m) {
                if (s.charAt(i) == t.charAt(j)) {
                    --skip;
                    ++j;
                }
                ++skip;
                ++i;
            }
            while (i < n) {
                ++i;
                ++skip;
            }
            if (j != m) {
                skip = Integer.MAX_VALUE;
            }
            return skip;
        }

        static class id27<T> implements Iterable<T> {
            private final TreeMap<T, Integer> map;
            private int size;

            public id27() {
                map = new TreeMap<>();
                size = 0;
            }

            public id27(boolean reverse) {
                if (reverse) map = new TreeMap<>(Collections.reverseOrder());
                else map = new TreeMap<>();
                size = 0;
            }

            public void clear() {
                map.clear();
                size = 0;
            }

            public int size() {
                return size;
            }

            public int setSize() {
                return map.size();
            }

            public boolean contains(T a) {
                return map.containsKey(a);
            }

            public boolean isEmpty() {
                return size == 0;
            }

            public Integer get(T a) {
                return map.getOrDefault(a, 0);
            }

            public void add(T a, int count) {
                int cur = get(a);
                map.put(a, cur + count);
                size += count;
                if (cur + count == 0) map.remove(a);
            }

            public void addOne(T a) {
                add(a, 1);
            }

            public void remove(T a, int count) {
                add(a, Math.max(-get(a), -count));
            }

            public void removeOne(T a) {
                remove(a, 1);
            }

            public void removeAll(T a) {
                remove(a, Integer.MAX_VALUE - 10);
            }

            public T ceiling(T a) {
                return map.ceilingKey(a);
            }

            public T floor(T a) {
                return map.floorKey(a);
            }

            public T first() {
                return map.firstKey();
            }

            public T last() {
                return map.lastKey();
            }

            public T higher(T a) {
                return map.higherKey(a);
            }

            public T lower(T a) {
                return map.lowerKey(a);
            }

            public T pollFirst() {
                T a = first();
                removeOne(a);
                return a;
            }

            public T pollLast() {
                T a = last();
                removeOne(a);
                return a;
            }

            public Iterator<T> iterator() {
                return new Iterator<T>() {
                    private final Iterator<T> iter = map.keySet().iterator();
                    private int count = 0;
                    private T curElement;

                    public boolean hasNext() {
                        return iter.hasNext() || count > 0;
                    }

                    public T next() {
                        if (count == 0) {
                            curElement = iter.next();
                            count = get(curElement);
                        }
                        count--;
                        return curElement;
                    }
                };
            }
        }

        public static long[][] combination(int l, int r) {
            long[][] pascal = new long[l + 1][r + 1];
            pascal[0][0] = 1;
            for (int i = 1; i <= l; ++i) {
                pascal[i][0] = 1;
                for (int j = 1; j <= r; ++j) {
                    pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
                }
            }
            return pascal;
        }


        public static long gcd(long... array) {
            long ret = array[0];
            for (int i = 1; i < array.length; ++i) ret = gcd(ret, array[i]);
            return ret;
        }


        public static long lcm(int... array) {
            long ret = array[0];
            for (int i = 1; i < array.length; ++i) ret = lcm(ret, array[i]);
            return ret;
        }


        public static int min(int a, int b) {
            return a < b ? a : b;
        }


        public static int min(int... array) {
            int ret = array[0];
            for (int i = 1; i < array.length; ++i) ret = min(ret, array[i]);
            return ret;
        }


        public static long min(long a, long b) {
            return a < b ? a : b;
        }


        public static long min(long... array) {
            long ret = array[0];
            for (int i = 1; i < array.length; ++i) ret = min(ret, array[i]);
            return ret;
        }


        public static int max(int a, int b) {
            return a > b ? a : b;
        }


        public static int max(int... array) {
            int ret = array[0];
            for (int i = 1; i < array.length; ++i) ret = max(ret, array[i]);
            return ret;
        }


        public static long max(long a, long b) {
            return a > b ? a : b;
        }

        public static long max(long... array) {
            long ret = array[0];
            for (int i = 1; i < array.length; ++i) ret = max(ret, array[i]);
            return ret;
        }


        public static long sum(int... array) {
            long ret = 0;
            for (int i : array) ret += i;
            return ret;
        }


        public static long sum(long... array) {
            long ret = 0;
            for (long i : array) ret += i;
            return ret;
        }

        public static int modinv(long x, long mod) {
            return (int) (CP.id0(x, mod - 2, mod) % mod);
        }

        public static int lcs(String s, String t) {
            int n = s.length(), m = t.length();
            int dp[][] = new int[n + 1][m + 1];
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j <= m; ++j) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 0;
                    } else if (s.charAt(i - 1) == t.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[n][m];
        }
    }

    

    public static class SegmentTree {
        int n;
        int[] arr, tree, lazy;

        SegmentTree(int arr[]) {
            this.arr = arr;
            this.n = arr.length;
            this.tree = new int[(n << 2)];
            this.lazy = new int[(n << 2)];
            build(1, 0, n - 1);
        }

        void build(int id, int start, int end) {
            if (start == end)
                tree[id] = arr[start];
            else {
                int mid = (start + end) / 2, left = (id << 1), right = left + 1;
                build(left, start, mid);
                build(right, mid + 1, end);
                tree[id] = tree[left] + tree[right];
            }
        }

        void update(int l, int r, int val) {
            update(1, 0, n - 1, l, r, val);
        }

        void update(int id, int start, int end, int l, int r, int val) {
            distribute(id, start, end);
            if (end < l || r < start)
                return;
            if (start == end)
                tree[id] += val;
            else if (l <= start && end <= r) {
                lazy[id] += val;
                distribute(id, start, end);
            } else {
                int mid = (start + end) / 2, left = (id << 1), right = left + 1;
                update(left, start, mid, l, r, val);
                update(right, mid + 1, end, l, r, val);
                tree[id] = tree[left] + tree[right];
            }
        }

        int query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }

        int query(int id, int start, int end, int l, int r) {
            if (end < l || r < start)
                return 0;
            distribute(id, start, end);
            if (start == end)
                return tree[id];
            else if (l <= start && end <= r)
                return tree[id];
            else {
                int mid = (start + end) / 2, left = (id << 1), right = left + 1;
                return query(left, start, mid, l, r) + query(right, mid + 1, end, l, r);
            }
        }

        void distribute(int id, int start, int end) {
            if (start == end)
                tree[id] += lazy[id];
            else {
                tree[id] += lazy[id] * (end - start + 1);
                lazy[(id << 1)] += lazy[id];
                lazy[(id << 1) + 1] += lazy[id];
            }
            lazy[id] = 0;
        }
    }

    

    static class Trie {
        class Node {
            Node[] children;
            boolean isEnd;

            Node() {
                children = new Node[26];
            }
        }

        Node root;

        Trie() {
            root = new Node();
        }

        public void insert(String word) {
            Node curr = root;
            for (char ch : word.toCharArray()) {
                if (curr.children[ch - 'a'] == null)
                    curr.children[ch - 'a'] = new Node();
                curr = curr.children[ch - 'a'];
            }
            curr.isEnd = true;
        }

        public boolean find(String word) {
            Node curr = root;
            for (char ch : word.toCharArray()) {
                if (curr.children[ch - 'a'] == null)
                    return false;
                curr = curr.children[ch - 'a'];
            }
            return curr.isEnd;
        }
    }

    

    static class FT {
        long[] tree;
        int n;

        FT(int n) {
            this.n = n;
            this.tree = new long[n + 1];
        }

        FT(int[] arr, int n) {
            this.n = n;
            this.tree = new long[n + 1];
            for (int i = 1; i <= n; i++) {
                update(i, arr[i - 1]);
            }
        }

        void update(int idx, int val) {
            while (idx <= n) {
                tree[idx] += val;
                idx += idx & -idx;
            }
        }

        long query(int l, int r) {
            return getSum(r) - getSum(l - 1);
        }

        long getSum(int idx) {
            long ans = 0L;
            while (idx > 0) {
                ans += tree[idx];
                idx -= idx & -idx;
            }
            return ans;
        }
    }

    

    static class BIT {
        long[][] tree;
        int n, m;

        BIT(int[][] mat, int n, int m) {
            this.n = n;
            this.m = m;
            tree = new long[n + 1][m + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    update(i, j, mat[i - 1][j - 1]);
                }
            }
        }

        void update(int x, int y, int val) {
            while (x <= n) {
                int t = y;
                while (t <= m) {
                    tree[x][t] += val;
                    t += t & -t;
                }
                x += x & -x;
            }
        }

        long query(int x1, int y1, int x2, int y2) {
            return getSum(x2, y2) - getSum(x1 - 1, y2) - getSum(x2, y1 - 1) + getSum(x1 - 1, y1 - 1);
        }

        long getSum(int x, int y) {
            long ans = 0L;
            while (x > 0) {
                int t = y;
                while (t > 0) {
                    ans += tree[x][t];
                    t -= t & -t;
                }
                x -= x & -x;
            }
            return ans;
        }
    }

    static class BSTCustom<T extends Comparable<? super T>> {
        private Node<T> __root;
        private Node<T> id12;
        private Node<T> id14;
        private long __size;
        private boolean __multi;

        public BSTCustom() {
            __root = null;
            __size = 0;
            __multi = false;

        }

        public BSTCustom(boolean __multi) {
            __root = null;
            __size = 0;
            this.__multi = __multi;
        }

        public long lower_bound(T data) {
            id12 = __root;
            long index = 0;
            while (id12 != null) {
                int _comparator = data.compareTo(id12.data);
                if (_comparator < 0) {
                    id12 = id12._left;
                } else if (_comparator > 0) {
                    index += (id12.count + id12._leftside);
                    id12 = id12._right;
                } else {
                    index += (id12._leftside);
                    break;
                }
            }
            return index;
        }

        private Node<T> remove(Node<T> temp, T data, long count) {
            if (temp == null) return temp;
            int _comparator = data.compareTo(temp.data);
            if (_comparator < 0) temp._left = remove(temp._left, data, count);
            else if (_comparator > 0) temp._right = remove(temp._right, data, count);
            else {
                if (__multi && count < temp.count && temp.count > 1) {
                    __size -= count;
                    temp.count -= count;
                } else {
                    __size -= temp.count;
                    if (temp._left == null && temp._right == null) return null;
                    else if (temp._left == null) return temp._right;
                    else if (temp._right == null) return temp._left;
                    else {
                        id12 = minValue(temp._right);
                        temp.data = id12.data;
                        temp.count = id12.count;
                        temp._right = remove(temp._right, id12.data, id12.count);
                        __size += temp.count;
                    }
                }
            }
            

            if (temp._left != null)
                temp._leftside = temp._left._leftside + temp._left._rightside + temp._left.count;
            else temp._leftside = 0;
            if (temp._right != null)
                temp._rightside = temp._right._leftside + temp._right._rightside + temp._right.count;
            else temp._rightside = 0;

            temp._height = Math.max(getheight(temp._left), getheight(temp._right)) + 1;
            


            long diff = getDiff(temp);
            if (diff > 1) {
                if (getDiff(temp._left) >= 0) {
                    temp = rightRotate(temp);
                } else {
                    temp._left = leftRotate(temp._left);
                    temp = rightRotate(temp);
                }
            } else if (diff < -1) {
                if (getDiff(temp._right) <= 0) {
                    temp = leftRotate(temp);
                } else {
                    temp._right = rightRotate(temp._right);
                    temp = leftRotate(temp);
                }
            }
            return temp;
        }

        public T get(long index) {
            id12 = __root;
            long current = 0;
            while (id12 != null) {
                if (id12._left == null) {
                    if (id12.count + current > index) return id12.data;
                    else {
                        current += id12.count;
                        id12 = id12._right;
                    }
                } else {
                    if (current + id12._leftside > index) id12 = id12._left;
                    else if (current + id12._leftside + id12.count > index)
                        return id12.data;
                    else {
                        current += id12.count + id12._leftside;
                        id12 = id12._right;
                    }

                }
            }
            return null;
        }

        private Node<T> minValue(Node<T> temp) {
            id12 = temp;
            while (id12._left != null) id12 = id12._left;
            return id12;
        }

        public void insert(T data, long... count) {
            if (count.length == 0) __root = insert(__root, data, 1);
            else if (count[0] > 0) __root = insert(__root, data, count[0]);

        }

        public void remove(T data, long... count) {
            if (count.length == 0) __root = remove(__root, data, 1);
            else if (count[0] > 0) __root = remove(__root, data, count[0]);

        }

        private Node<T> insert(Node<T> temp, T data, long count) {
            if (temp == null) {
                if (__multi) {
                    __size += count;
                    return new Node<>(data, count);
                } else {
                    __size++;
                    return new Node<>(data);
                }
            }
            int _comparator = data.compareTo(temp.data);
            if (_comparator < 0) temp._left = insert(temp._left, data, count);
            else if (_comparator > 0) temp._right = insert(temp._right, data, count);
            else if (__multi) {
                __size += count;
                temp.count += count;
            }


            

            if (temp._left != null)
                temp._leftside = temp._left._leftside + temp._left._rightside + temp._left.count;
            else temp._leftside = 0;
            if (temp._right != null)
                temp._rightside = temp._right._leftside + temp._right._rightside + temp._right.count;
            else temp._rightside = 0;

            temp._height = Math.max(getheight(temp._left), getheight(temp._right)) + 1;
            


            long diff = getDiff(temp);
            if (diff > 1) {
                if (data.compareTo(temp._left.data) < 0) {
                    temp = rightRotate(temp);
                } else if (data.compareTo(temp._left.data) > 0) {
                    temp._left = leftRotate(temp._left);
                    temp = rightRotate(temp);
                }
            } else if (diff < -1) {
                if (data.compareTo(temp._right.data) > 0) {

                    temp = leftRotate(temp);
                } else if (data.compareTo(temp._right.data) < 0) {
                    temp._right = rightRotate(temp._right);
                    temp = leftRotate(temp);
                }
            }
            return temp;

        }

        private Node<T> rightRotate(Node<T> temp) {
            id12 = temp._left;
            id14 = id12._right;

            id12._right = temp;
            temp._left = id14;

            

            temp._height = Math.max(getheight(temp._left), getheight(temp._right)) + 1;
            id12._height = Math.max(getheight(id12._left), getheight(id12._right)) + 1;
            


            if (temp._left != null)
                temp._leftside = temp._left._leftside + temp._left._rightside + temp._left.count;
            else temp._leftside = 0;
            if (temp._right != null)
                temp._rightside = temp._right._leftside + temp._right._rightside + temp._right.count;
            else temp._rightside = 0;

            if (id12._left != null)
                id12._leftside = id12._left._leftside + id12._left._rightside + id12._left.count;
            else id12._leftside = 0;
            if (id12._right != null)
                id12._rightside = id12._right._leftside + id12._right._rightside + id12._right.count;
            else id12._rightside = 0;


            return id12;
        }

        private Node<T> leftRotate(Node<T> temp) {
            id12 = temp._right;
            id14 = id12._left;

            id12._left = temp;
            temp._right = id14;

            

            temp._height = Math.max(getheight(temp._left), getheight(temp._right)) + 1;
            id12._height = Math.max(getheight(id12._left), getheight(id12._right)) + 1;
            


            if (temp._left != null)
                temp._leftside = temp._left._leftside + temp._left._rightside + temp._left.count;
            else temp._leftside = 0;
            if (temp._right != null)
                temp._rightside = temp._right._leftside + temp._right._rightside + temp._right.count;
            else temp._rightside = 0;


            if (id12._left != null)
                id12._leftside = id12._left._leftside + id12._left._rightside + id12._left.count;
            else id12._leftside = 0;
            if (id12._right != null)
                id12._rightside = id12._right._leftside + id12._right._rightside + id12._right.count;
            else id12._rightside = 0;

            return id12;
        }

        private long getDiff(Node<T> temp) {
            if (temp == null) return 0;
            return getheight(temp._left) - getheight(temp._right);
        }

        public long getheight(Node<T> temp) {
            if (temp == null) return 0;
            return temp._height;
        }

        public long size() {
            return this.__size;
        }

        private class Node<T> {
            T data;
            Node<T> _left;
            Node<T> _right;
            long _leftside;
            long _rightside;
            long _height;
            long count;

            public Node(T data) {
                this.data = data;
                this._left = null;
                this._right = null;
                this._leftside = 0;
                this._rightside = 0;
                this._height = 1;
                this.count = 1;
            }

            public Node(T data, long count) {
                this.data = data;
                this._left = null;
                this._right = null;
                this._leftside = 0;
                this._rightside = 0;
                this._height = 1;
                this.count = count;
            }

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void printLine(int[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void printLine(long i) {
            writer.println(i);
        }

        public void printLine(int i) {
            writer.println(i);
        }

        public void printLine(char c) {
            writer.println(c);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        void flush() {
            writer.flush();
        }
    }
}




