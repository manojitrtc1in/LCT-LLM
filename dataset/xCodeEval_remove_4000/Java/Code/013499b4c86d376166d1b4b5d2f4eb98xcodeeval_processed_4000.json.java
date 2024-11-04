
import java.io.*;
import java.util.*;

public class Main {

    static class Pair {
        int l,r;

        public Pair(int l,int r) {
            this.l=l;
            this.r=r;
        }
    }

    static long mod= (long)1e9+7;

    public static final double  PI =  3.141592653589793d;

    public static void main(String[] args) throws IOException
    {
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
            int t=in.readInt();
            while(t-->0)
            {
                int n=in.readInt();
                int a=in.readInt();
                int b=in.readInt();
                if(a+b>n-2 || Math.abs(a-b)>1)
                {
                    out.printLine(-1);
                }
                else
                {
                    int arr[]=new int[n];
                    if(a>=b)
                    {
                        for(int i=0;i<n;i++)
                        {
                            arr[i]=i+1;
                        }
                    }
                    else
                    {
                        for(int i=0;i<n;i++)
                        {
                            arr[i]=n-i;
                        }
                    }
                    for(int i=1;i<n && a!=0 && b!=0;i+=2)
                    {
                        CP.fast_swap(arr,i,i+1);
                        --a;
                        --b;
                    }
                    if(a>0 || b>0)
                    {
                        CP.fast_swap(arr,n-2,n-1);
                    }
                    for(int i=0;i<n;i++)
                    {
                        out.print(arr[i]+" ");
                    }
                    out.printLine();
                }
            }
        }
    }


    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id19 filter;

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
            while (id4(c)) {
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
            } while (!id4(c));
            return res * sgn;
        }

        public int[] id9(int arraySize) {
            int[] array = new int[arraySize];

            for (int i = 0; i < arraySize; i++) {
                array[i] = readInt();
            }

            return array;
        }

        public String readString() {
            int c = read();
            while (id4(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id4(c));
            return res.toString();
        }

        public boolean id8(int c) {
            return c == '\n';
        }

        public String nextLine() {
            int c = read();

            StringBuilder result = new StringBuilder();

            do {
                result.appendCodePoint(c);

                c = read();
            } while (!id8(c));

            return result.toString();
        }

        public long nextLong() {
            int c = read();

            while (id4(c)) {
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
            } while (!id4(c));

            return result * sign;
        }

        public long[] id21(int arraySize) {
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

        public boolean id4(int c) {
            if (filter != null) {
                return filter.id4(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface id19 {
            public boolean id4(int ch);

        }
    }

    static class CP {

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

        static String addChar(String s, int n, String ch) {
            String res =s+String.join("", Collections.nCopies(n, ch));
            return res;
        }

        static int id2(int[] prime, int x) {

            return (prime[x / 64] & (1 << ((x >> 1) & 31)));
        }

        static int log2(long n)
        {
            return (int)(Math.log10(n) / Math.log10(2));
        }

        static void makeComposite(int[] prime, int x) {

            prime[x / 64] |= (1 << ((x >> 1) & 31));
        }

        static ArrayList<Integer> id14(int n) {
            ArrayList<Integer> al = new ArrayList<>();
            int prime[] = new int[n / 64 + 1];


            for (int i = 3; i * i <= n; i += 2) {

                if (id2(prime, i) == 0)
                    for (int j = i * i, k = i << 1;
                         j < n; j += k)
                        makeComposite(prime, j);
            }

            al.add(2);

            for (int i = 3; i <= n; i += 2)
                if (id2(prime, i) == 0)
                    al.add(i);

            return al;
        }

        public static long[] sort(long arr[]){
            List<Long> list = new ArrayList<>();
            for(long n : arr){list.add(n);}
            Collections.sort(list);
            for(int i=0;i<arr.length;i++){
                arr[i] = list.get(i);
            }
            return arr;
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

        static ArrayList<Integer> id10(int l, int r, ArrayList<Integer> primes) {
            ArrayList<Integer> al=new ArrayList<>();
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
                    al.add(l+i);
                }
            }
            return al;
        }

        static boolean id6(long n, int iteration) {

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
                    ;
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

        static long id7(long a, long b) {
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

        static long id0(long a, long b) {
            long res = 1;
            while (b != 0) {
                if ((b & 1) == 1) {
                    res = (res * a) % 1000000007 ;
                    --b;
                }
                a = (a * a) % 1000000007;
                b /= 2;
            }
            return res%1000000007;
        }

        static int id12(int a, int b) {
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

        static int id17(int bits, int i) {
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

        static long id11(long a[], long x) {
            long l = -1, r = a.length;
            while (l + 1 < r) {
                long m = (l + r) >>> 1;
                if (a[(int) m] <= x)
                    l = m;
                else
                    r = m;
            }
            return l + 1;
        }

        static int id18(ArrayList<Integer> a,int x) {
            int l = 0, r = a.size()-1,ans=-1,mid=0;
            while(l<=r)
            {
                mid=(l+r)>>1;
                if(a.get(mid)<=x)
                {
                    ans=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            return ans;
        }

        static long id18(long a[],long x) {
            int l = -1, r = a.length;
            while (l + 1 < r) {
                int m = (l + r) >>> 1;
                if (a[(int) m] >= x)
                    r = m;
                else
                    l = m;
            }
            return (long)r;
        }

        static int upperBound(int a[], int x) {

            int l=-1,r=a.length;
            while(l+1<r) {
                int m=(l+r)>>>1;
                if(a[m]<=x) l=m;
                else r=m;
            }
            return l+1;
        }

        static int bsh(int  a[],int t) {
            int ans =-1;
            int i = 0, j = a.length - 1;
            while (i <= j) {
                int mid = i + (j - i) / 2;
                if (a[mid] > t) {
                    ans = mid;
                    

                    j=mid-1;
                }
                else{
                    

                    i=mid+1;
                }
            }
            return ans;
        }

        static int bsl(int a[],int t) {
            int ans =-1;
            int i = 0, j = a.length-1;
            while (i <= j) {
                int mid = i + (j - i) / 2;
                if (a[mid] <= t) {
                    ans = mid;
                    i=mid+1;
                } else if (a[mid] > t) {
                    j = mid - 1;
                }
            }
            return ans;
        }

        static int id11(ArrayList<Integer> a,int x)  

        {
            int l = 0, r = a.size()-1,ans=-1,mid=0;
            while(l<=r)
            {
                mid=(l+r)>>1;
                if(a.get(mid)>x)
                {
                    ans=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            return ans;
        }

        static boolean id20(int x, int factor, int target) {
            int s = (int) Math.round(Math.sqrt(x));
            return factor * s * s == target;
        }

        static boolean isSquare(int x) {
            int s = (int) Math.round(Math.sqrt(x));
            return x * x == s;
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

        static boolean isPalindrome(String s)
        {
            StringBuilder sb=new StringBuilder(s);
            sb.reverse();
            if(s.equals(sb.toString()))
            {
                return true;
            }
            return false;
        }

        static int[] id15(String pat) {
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

        static void kmp(String s, String pat,int[] prf,int[] st) {
            int n = s.length(), m = pat.length();
            int lps[] = id15(pat);
            int i = 0, j = 0;
            while (i < n) {
                if (s.charAt(i) == pat.charAt(j)) {
                    i++;
                    j++;
                    if (j == m) {
                        ++prf[(i-j)+m];
                        ++st[(i-j)+1];
                        j=lps[j - 1];
                    }

                } else {
                    if (j != 0) {
                        j = lps[j - 1];
                    } else {
                        i++;
                    }
                }
            }
        }

        static void id13(int a[]) {
            shuffle(a);
            Arrays.sort(a);
            for (int l = 0, r = a.length - 1; l < r; ++l, --r)
                fast_swap(a, l, r);

        }

        static void id5(int a[]) {
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
                if(!al.contains(2L))
                {
                    al.add(2L);
                }
                n /= 2L;
            }

            for (int i = 3; (long) i * i <= n; i += 2) {
                while ((n % i == 0)) {
                    if(!al.contains((long)i))
                    {
                        al.add((long) i);
                    }
                    n /= i;
                }
            }

            if (n > 2) {
                if(!al.contains(n))
                {
                    al.add(n);
                }
            }
            return al;
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

        static void swap(int a[], int idx1, int idx2) {
            a[idx1] += a[idx2];
            a[idx2] = a[idx1] - a[idx2];
            a[idx1] -= a[idx2];
        }

        static void fast_swap(int[] a, int idx1, int idx2) {
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

        static int divCount(int n) {
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

        static long id16(long n,long k)
        {
            long res = 1;

            if (k > n - k)
                k = n - k;

            for (int i = 0; i < k; ++i) {
                res = (res*(n - i));
                res /= (i + 1);
            }
            return res;
        }

        static long c(long fact[],long n,long k)
        {
            if(k>n) return 0;
            long res=fact[(int)n];
            res= (int) ((res * id0(fact[(int)k], mod - 2))%mod);
            res= (int) ((res * id0(fact[(int)n - (int)k], mod - 2))%mod);
            return res%mod;
        }

        public static ArrayList<Long> getFactors(long x) {

            ArrayList<Long> facts=new ArrayList<>();
            for(long i=2;i*i<=x;++i)
            {
                if(x%i==0)
                {
                    facts.add(i);
                    if(i!=x/i)
                    {
                        facts.add(x/i);
                    }
                }
            }
            return facts;
        }

        static void id3(long n,long[][] A, long[][] I){
            while(n>0){
                if(n%2==0){
                    Multiply(A,A);
                    n/=2;
                }
                else{
                    Multiply(I,A);
                    n--;
                }
            }
        }

        static void Multiply(long[][] A , long[][]B){

            int n= A.length , m=A[0].length, p=B[0].length;

            long [][] C=new long[n][p];

            for(int i=0;i<n;i++){
                for(int j=0;j<p;j++){
                    for(int k=0;k<m;k++){
                        C[i][j]+=((A[i][k]%mod)*(B[k][j]%mod))%mod;
                        C[i][j]=C[i][j]%mod;
                    }
                }
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<p;j++){
                    A[i][j]=C[i][j];
                }
            }
        }

        public static HashMap<Integer, Integer> sortMap(HashMap<Integer, Integer> map) {

            List<Map.Entry<Integer,Integer>> list=new LinkedList<>(map.entrySet());

            Collections.sort(list,(o1,o2)->o2.getValue()-o1.getValue());

            HashMap<Integer,Integer> temp=new LinkedHashMap<>();

            for(Map.Entry<Integer,Integer> i:list)
            {
                temp.put(i.getKey(),i.getValue());
            }
            return temp;
        }

        public static long lcm(long l,long l2) {

            long val=CP.gcd(l,l2);
            return (l*l2)/val;

        }
    }

    static void py() {
        System.out.println("YES");
    }

    static void pn() {
        System.out.println("NO");
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
        public void printLine(char c)
        {
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
    }
}




