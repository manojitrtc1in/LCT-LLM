import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

public class Main
{
    static class Pair
    {
        String s,rev;
        public Pair(String s,String rev)
        {
            this.s=s;
            this.rev=rev;
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
            int t = in.ni();
            

            while (t-->0)
            {
                int n=in.ni();
                long[] arr=in.nla(n);
                ++arr[0];
                int f=1;
                for(int i=1;i<n;i++)
                {
                    if(arr[i]==arr[i-1])
                    {
                        ++arr[i];
                    }
                    else if(arr[i]==arr[i-1]+1)
                    {
                        continue;
                    }
                    else if(arr[i]==arr[i-1]+2)
                    {
                        --arr[i];
                    }
                    else
                    {
                        f=0;
                    }
                }
                out.printLine((f==1)?"YES":"NO");

            }
        }
    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id30 filter;

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

        public int ni() {
            int c = read();
            while (id6(c)) {
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
            } while (!id6(c));
            return res * sgn;
        }

        private char nc() { return (char)skip(); }

        public int[] na(int arraySize) {
            int[] array = new int[arraySize];

            for (int i = 0; i < arraySize; i++) {
                array[i] = ni();
            }

            return array;
        }

        private int skip() {
            int b;
            while ((b = read()) != -1 && id6(b)) ;
            return b;
        }

        private String ns() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!(id6(b))) { 

                sb.appendCodePoint(b);
                b = read();
            }
            return sb.toString();
        }

        private char[] ns(int n) {
            char[] buf = new char[n];
            int b = skip(), p = 0;
            while (p < n && !(id6(b))) {
                buf[p++] = (char) b;
                b = read();
            }
            return n == p ? buf : Arrays.copyOf(buf, p);
        }

        private char[][] nm(int n, int m)
        {
            char[][] map = new char[n][];
            for(int i = 0;i < n;i++)map[i] = ns(m);
            return map;
        }


        int[][] nim(int h, int w) {
            int[][] a = new int[h][w];
            for (int i = 0; i < h; i++) {
                a[i] = na(w);
            }
            return a;
        }

        long[][] nlm(int h, int w) {
            long[][] a = new long[h][w];
            for (int i = 0; i < h; i++) {
                a[i] = nla(w);
            }
            return a;
        }

        public String readString() {
            int c = read();
            while (id6(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id6(c));
            return res.toString();
        }

        public boolean id13(int c) {
            return c == '\n';
        }

        public String nextLine() {
            int c = read();

            StringBuilder result = new StringBuilder();

            do {
                result.appendCodePoint(c);

                c = read();
            } while (!id13(c));

            return result.toString();
        }

        public long nextLong() {
            int c = read();

            while (id6(c)) {
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
            } while (!id6(c));

            return result * sign;
        }

        public long[] nla(int arraySize) {
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

        public boolean id6(int c) {
            if (filter != null) {
                return filter.id6(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface id30 {
            public boolean id6(int ch);

        }
        boolean oj = System.getProperty("ONLINE_JUDGE") != null;
        void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }

    }

    public static class CP {

        static boolean isPrime(long n) {
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

        static void reverse(long arr[]){
            int l = 0, r = arr.length-1;
            while(l<r){
                long temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
                l++;
                r--;
            }
        }

        static void reverse(int arr[]){
            int l = 0, r = arr.length-1;
            while(l<r){
                int temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
                l++;
                r--;
            }
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

            int[] id18 = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
            for (int tp : id18) {
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

        static long digit(long s) {
            long brute = 0;
            while (s > 0) {
                brute+=s%10;
                s /= 10;
            }
            return brute;
        }

        public static int[] primefacts(int n, int[] primes) {
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


        static ArrayList<Integer> id22(int n) {
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

        static boolean[] id26(long size) {

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
            

            return prime;
        }

        static ArrayList<Integer> id19(int l, int r, ArrayList<Integer> primes) {
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

        static boolean id10(long n, int iteration) {

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

        static long id12(long a, long b) {
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

        static int id20(int a, int b) {
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

        static int id28(int bits, int i) {
            return (bits >> (i - 1)) & 1;
        }

        static long id17(long bits, int i) {
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

        

        private static int lower_bound(ArrayList<Long> list, long val) {
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
                if (arr[mid]>=val) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
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

        


        private static int[]  LIS(long arr[], int n) {
            List<Long> list = new ArrayList<>();
            int[] cnt=new int[n];
            for (int i = 0; i < n; i++) {
                int idx = find1(list, arr[i]);
                if (idx < list.size())
                    list.set(idx, arr[i]);
                else
                    list.add(arr[i]);
                cnt[i]=list.size();
            }
            return cnt;
        }

        private static int find1(List<Long> list, long val) {
            int ret = list.size(), i = 0, j = list.size() - 1;
            while (i <= j) {
                int mid = (i + j) / 2;
                if (list.get(mid)>=val) {
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

        private static long nCr(long n, long r,long mod) {
            if (n - r > r)
                r = n - r;
            long ans = 1L;
            for (long i = r + 1; i <= n; i++)
                ans = (ans%mod*i%mod)%mod;
            for (long i = 2; i <= n - r; i++)
                ans /= i;
            return ans%mod;
        }

        private static boolean isPalindrome(String str) {
            int i = 0, j = str.length() - 1;
            while (i < j)
                if (str.charAt(i++) != str.charAt(j--))
                    return false;
            return true;
        }

        static ArrayList<StringBuilder> id9(StringBuilder s)
        {
            int n=s.length();
            ArrayList<StringBuilder> al=new ArrayList<>();
            id15(s,al,0,n);
            return al;
        }














        static void id15(StringBuilder s,ArrayList<StringBuilder> al,int l, int r)
        {
            if(l==r)
            {
                al.add(s);
                return;
            }
            for(int i=l+1;i<r;++i)
            {
                char c=s.charAt(i);
                s.setCharAt(i,s.charAt(l));
                s.setCharAt(l,c);
                id15(s,al,l+1,r);
                c=s.charAt(i);
                s.setCharAt(i,s.charAt(l));
                s.setCharAt(l,c);
            }
        }

        static void id16(String s,long[] dp,long[] inv,long p)
        {
            long pow=1;
            inv[0]=1;
            int n=s.length();
            dp[0]=((s.charAt(0)-'a')+1);
            for(int i=1;i<n;++i)
            {
                pow=(pow*p)%mod;
                dp[i]=(dp[i-1]+((s.charAt(i)-'a')+1)*pow)%mod;
                inv[i]=CP.modinv(pow,mod)%mod;
            }
        }

        static long id5(long[] dp,long[] inv,int l,int r)
        {
            long ans=dp[r];
            if(l-1>=0)
            {
                ans-=dp[l-1];
            }
            ans=(ans*inv[l])%mod;
            return ans;
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

        static boolean id31(int x, int factor, int target) {
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


        public static int[] id29(int[] a) {
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

        static int[] id25(String pat) {
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
            int lps[] = id25(pat);
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

        static void id21(int a[]) {
            shuffle(a);
            Arrays.sort(a);
            for (int l = 0, r = a.length - 1; l < r; ++l, --r)
                fast_swap(a, l, r);

        }

        static void id8(int a[]) {
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

        static ArrayList<Long> primeFact(long n) {
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

        public static long totFact(long n) {
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

        static int id7(int n) {
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

        static long id27(long n, long k) {
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
            long res = fact[(int) n]%mod;
            res = (int) ((res%mod* inv[(int) k]%mod))%mod;
            res = (int) ((res%mod*inv[(int) (n - k)]%mod))%mod;
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
            facts.add(1L);
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

        public static HashMap<Long, Integer> id14(HashMap<Long,Integer> map) {

            List<Map.Entry<Long, Integer>> list = new LinkedList<>(map.entrySet());

            Collections.sort(list, (o1, o2) -> o2.getValue() - o1.getValue());

            HashMap<Long, Integer> temp = new LinkedHashMap<>();

            for (Map.Entry<Long, Integer> i : list) {
                temp.put(i.getKey(), i.getValue());
            }
            return temp;
        }

        public static HashMap<Character, Integer> id24(HashMap<Character, Integer> map) {

            List<Map.Entry<Character, Integer>> list = new LinkedList<>(map.entrySet());

            Collections.sort(list, (o1, o2) -> o2.getValue() - o1.getValue());

            HashMap<Character, Integer> temp = new LinkedHashMap<>();

            for (Map.Entry<Character, Integer> i : list) {
                temp.put(i.getKey(), i.getValue());
            }
            return temp;
        }

        public static HashMap<Long,Long> id23(HashMap<Long,Long> map) {

            List<Map.Entry<Long,Long>> list = new LinkedList<>(map.entrySet());

            Collections.sort(list, (o1, o2) -> (int)(o1.getValue() - o2.getValue()));

            HashMap<Long,Long> temp = new LinkedHashMap<>();

            for (Map.Entry<Long,Long> i : list) {
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

        public static int id11(String s, String t) {
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

        public static long[] facts(int n)
        {
            long[] fact=new long[1005];
            fact[0]=1;
            fact[1]=1;
            for(int i=2;i<n;i++)
            {
                fact[i]=(long)(i*fact[i-1])%mod;
            }
            return fact;
        }

        public static long[] inv(long[] fact,int n)
        {
            long[] inv=new long[n];
            inv[n-1]= CP.id0(fact[n-1],mod-2,mod)%mod;
            for(int i=n-2;i>=0;--i)
            {
                inv[i]=(inv[i+1]*(i+1))%mod;
            }
            return inv;
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

        public void print(long[] array) {
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

        public void printLine(long[] array) {
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

        public void py()
        {
            print("YES");
            writer.println();
        }

        public void pn()
        {
            print("NO");
            writer.println();
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