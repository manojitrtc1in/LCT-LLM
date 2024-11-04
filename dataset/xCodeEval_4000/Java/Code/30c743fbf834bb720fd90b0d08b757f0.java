import java.io.DataInputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.*;
import java.util.function.Consumer;
import java.util.stream.Collectors;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.Math.pow;
import java.math.*;

public class DivideAndMultiply {
    @SuppressWarnings("FieldCanBeLocal")
    private static Reader in;
    private static PrintWriter out;
    private static String YES = "YES";
    private static String NO = "NO";

    private static void solve() throws IOException{
        

        long n = in.nextLong();
        long[] arr = new long[(int) n];
        long count = 0, maximum = 0, sum = 0;
        for(int i = 0; i < n; i++){
            arr[i] = in.nextLong();
            while(arr[i] % 2 == 0){
                count++;
                arr[i] /= 2;
            }
            maximum = max(maximum, arr[i]);
            sum += arr[i];
        }
        sum -= maximum;
        long total = (long) (sum + maximum * pow(2, count));
        System.out.println(total);
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        in = new Reader();
        out = new PrintWriter(new OutputStreamWriter(System.out));
        int T = in.nextInt();
        while(T --> 0){
            solve();
        }
        out.flush();
        in.close();
        out.close();
    }
    static final Random random = new Random();
    static final int mod = 1_000_000_007;
    private static boolean check(long[] arr, long n){
        long ch = arr[0];
        for(int i = 0; i < n; i++){
            if(ch != arr[i]){
                return false;
            }
        }
        return true;
    }
    

    private static long maxFreqHashMap(long[] arr, long n){
        Map<Long, Long> hp = new HashMap<Long, Long>();
        for(int i = 0; i < n; i++) {
            long key = arr[i];
            if(hp.containsKey(key)) {
                long freq = hp.get(key);
                freq++;
                hp.put(key, freq);
            }
            else {
                hp.put(key, 1L);
            }
        }
        long max_count = 0, res = 1, count = 0;
        for(Map.Entry<Long, Long> val : hp.entrySet()) {
            if (max_count < val.getValue()) {
                res = Math.toIntExact(val.getKey());
                max_count = Math.toIntExact(val.getValue());
                count = max_count;
            }
        }
        return count;
    }
    

    private static long maxFreq(long []arr, long n) {
        

        long res = 0;
        long count = -1;
        for(int i = 1; i < n; i++) {
            if(arr[i] == arr[(int) res]) {
                count++;
            }
            else {
                count--;
            }
            if(count == 0) {
                res = i;
                count = 1;
            }

        }
        return arr[(int) res];
        
    }
    private static int LCSubStr(char[] X, char[] Y, int m, int n) {
        int[][] LCStuff = new int[m + 1][n + 1];
        int result = 0;
        for (int i = 0; i <= m; i++){
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    LCStuff[i][j] = 0;
                }
                else if (X[i - 1] == Y[j - 1]) {
                    LCStuff[i][j] = LCStuff[i - 1][j - 1] + 1;
                    result = Integer.max(result, LCStuff[i][j]);
                }
                else {
                    LCStuff[i][j] = 0;
                }
            }
        }
        return result;
    }
    private static long longCusBsearch(long[] arr, long n, long h){
        long ans = h;
        long l = 1;
        long r = h;
        while(l <= r){
            long mid = (l + r) / 2;
            long ok = 0;
            for(long i = 0; i < n; i++){
                if(i == n - 1) {
                    ok += mid;
                }
                else{
                    long x = arr[(int) (i + 1)] - arr[(int) i];
                    if(x >= mid) {
                        ok += mid;
                    }
                    else{
                        ok += x;
                    }
                }
            }
            if(ok >= h){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    public static int intCusBsearch(int[] arr, int n, int h){
        int ans = h, l = 1, r = h;
        while(l <= r){
            int mid = (l + r) / 2;
            int ok = 0;
            for(int i = 0; i < n; i++){
                if(i == n - 1){
                    ok += mid;
                }
                else{
                    int x = arr[i + 1] - arr[i];
                    if(x >= mid){
                        ok += mid;
                    }
                    else{
                        ok += x;
                    }
                }
            }
            if(ok >= h){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    
    private static boolean isPowerOfTwo (int x) {
      
        return x!=0 && ((x&(x-1)) == 0);

    }
    

    static void ruffleSort(int[] a){
        int n = a.length;

        for(int i=0; i<n; i++){
            int oi = random.nextInt(n), temp = a[oi];
            a[oi] = a[i]; a[i] = temp;
        }
        sort(a);
    }
    private static void longRuffleSort(long[] a){
        long n = a.length;
        for(long i = 0;i<n;i++){
            long oi = random.nextInt((int) n), temp = a[(int) oi];
            a[(int) oi] = a[(int) i]; a[(int) i] = temp;
        }
        longSort(a);
    }
    private static int gcd(int a, int b){
        if(a == 0 || b == 0){
            return 0;
        }
        while(b != 0){
            int temp;
            temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    private static long gcd(long a, long b){
        if(a == 0 || b == 0){
            return 0;
        }
        while(b != 0){
            long temp;
            temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    private static int lowestCommonMultiple(int a, int b){
        return (a / gcd(a, b) * b);
    }
    
    private static void pDivisors(int n){
        for(int i=1;i<Math.sqrt(n);i++){
            if(n % i == 0){
                if(n / i == i){
                    System.out.println(i + " ");
                }
                else{
                    System.out.println(i + " " + (n / i) + " ");
                }
            }
        }
    }
    private static void returnNothing(){return;}
    private static int numOfdigitsinN(int a){return (int) (Math.floor(Math.log10(a)) + 1);}
    

    

    private static boolean isPrime(int n){
        if(n <= 1) return false;
        if(n <= 3) return true;
        

        if(n % 2 == 0 || n % 3 == 0) return false;
        for(int i = 5; i * i <= n; i = i + 6){
            if(n % i == 0 || n % (i + 2) == 0){
                return false;
            }
        }
        return true;
    }
    

    private static void printTheIsPrimeFunc(int n){
        for(int i=2;i<=n;i++){
            if(isPrime(i)) System.out.println(i + " ");
        }
    }
    public static boolean primeFinder(int n){
        int m = 0;
        int flag = 0;
        m = n / 2;
        if(n == 0 ||n == 1){
            return false;
        }
        else{
            for(int i=2;i<=m;i++){
                if(n % i == 0){
                    return false;
                }
            }
            return true;
        }
    }
    private static boolean evenOdd(int num){
        

        return (num & 1) == 0 ? true : false;
    }
    private static boolean[] sieveOfEratosthenes(long n) {
        boolean prime[] = new boolean[(int)n + 1];
        for (int i = 0; i <= n; i++) {
            prime[i] = true;
        }
        for (long p = 2; p * p <= n; p++) {
            if (prime[(int)p] == true) {
                for (long i = p * p; i <= n; i += p)
                    prime[(int)i] = false;
            }
        }
        return prime;
    }
    private static int log2(int n){
        int result = (int) (Math.log(n) / Math.log(2));
        return result;
    }
    private static long add(long a, long b){
        return (a + b) %  mod;
    }
    private static long lcm(long a, long b){
        return (a / gcd((int) a, (int) b) * b);
    }
    private static void sort(int[] a){
        ArrayList<Integer> l = new ArrayList<>();
        for(int i:a) l.add(i);
        Collections.sort(l);
        for(int i=0;i<a.length;i++)a[i] = l.get(i);
    }
    private static void longSort(long[] a){
        ArrayList<Long> l = new ArrayList<Long>();
        for(long i:a) l.add(i);
        Collections.sort(l);
        for(int i=0;i<a.length;i++)a[i] = l.get(i);
    }
    public static int[][] prefixsum( int n , int m , int arr[][] ){
        int prefixsum[][] = new int[n+1][m+1];
        for( int i = 1 ;i <= n ;i++) {
            for( int j = 1 ; j<= m ; j++) {
                int toadd = 0;
                if( arr[i-1][j-1] == 1) {
                    toadd = 1;
                }
                prefixsum[i][j] = toadd + prefixsum[i][j-1] + prefixsum[i-1][j] - prefixsum[i-1][j-1];
            }
        }
        return prefixsum;
    }

    

    private static int[] readArray(int len) throws IOException{
        int[] a = new int[len];
        for(int i=0;i<len;i++)a[i] = in.nextInt();
        return a;
    }
    

    private static long[] readLongArray(int len) throws IOException{
        long[] a = new long[len];
        for(int i=0;i<len;i++) a[i] = in.nextLong();
        return a;
    }
    

    private static void printArray(int[] array){
        for(int now : array) out.print(now);out.print(' ');out.close();
    }
    

    private static void printLongArray(long[] array){
        for(long now:array) out.print(now); out.print(' '); out.close();
    }


    
    private static class Reader {
        private static final int BUFFER_SIZE = 1 << 16;
        private final DataInputStream din;
        private final byte[] buffer;
        private int bufferPointer, bytesRead;

        Reader() {

            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {

            final byte[] buf = new byte[1024]; 

            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    break;
                }
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextSign() throws IOException {

            byte c = read();
            while ('+' != c && '-' != c) {
                c = read();
            }
            return '+' == c ? 0 : 1;
        }

        private static boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        public int skip() throws IOException {
            int b;
            

            while ((b = read()) != -1 && isSpaceChar(b)) {
                ;
            }
            return b;
        }

        public char nc() throws IOException {
            return (char) skip();
        }

        public String next() throws IOException {
            int b = skip();
            final StringBuilder sb = new StringBuilder();
            while (!isSpaceChar(b)) { 

                sb.appendCodePoint(b);
                b = read();
            }
            return sb.toString();
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            final boolean neg = c == '-';
            if (neg) {
                c = read();
            }
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg) {
                return -ret;
            }
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            final boolean neg = c == '-';
            if (neg) {
                c = read();
            }
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg) {
                return -ret;
            }
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            final boolean neg = c == '-';
            if (neg) {
                c = read();
            }

            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg) {
                return -ret;
            }
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1) {
                buffer[0] = -1;
            }
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead) {
                fillBuffer();
            }
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            din.close();
        }
    }
    
    private static class Multiset<E> {
        
        private List<E> values;
        
        private List<Integer> frequency;
        private final String ERROR_MSG = "Count cannot be negative: ";
        
        public Multiset() {
            values = new ArrayList<>();
            frequency = new ArrayList<>();
        }
        
        public int add(E element, int count) {
            if (count < 0) {
                throw new IllegalArgumentException(ERROR_MSG + count);
            }
            int index = values.indexOf(element);
            int prevCount = 0;
            if (index != -1) {
                prevCount = frequency.get(index);
                frequency.set(index, prevCount + count);
            }
            else if (count != 0) {
                values.add(element);
                frequency.add(count);
            }
            return prevCount;
        }
        
        public boolean add(E element) {
            return add(element, 1) >= 0;
        }
        
        boolean addAll(Collection<? extends E> c) {
            for (E element: c) {
                add(element, 1);
            }
            return true;
        }
        
        public void addAll(E... arr) {
            for (E element: arr) {
                add(element, 1);
            }
        }
        
        public void forEach(Consumer<? super E> action) {
            List<E> all = new ArrayList<>();

            for (int i = 0; i < values.size(); i++)
            {
                for (int j = 0; j < frequency.get(i); j++) {
                    all.add(values.get(i));
                }
                all.forEach(action);
            }
        }
        
        public boolean remove(Object element) {
            return remove(element, 1) > 0;
        }
        
        public int remove(Object element, int count) {
            if (count < 0) {
                throw new IllegalArgumentException(ERROR_MSG + count);
            }
            int index = values.indexOf(element);
            if (index == -1) {
                return 0;
            }
            int prevCount = frequency.get(index);
            if (prevCount > count) {
                frequency.set(index, prevCount - count);
            }
            else {
                values.remove(index);
                frequency.remove(index);
            }
            return prevCount;
        }
        
        public boolean contains(Object element) {
            return values.contains(element);
        }
        
        public boolean containsAll(Collection<?> c) {
            return values.containsAll(c);
        }
        
        public int setCount(E element, int count) {
            if (count < 0) {
                throw new IllegalArgumentException(ERROR_MSG + count);
            }
            if (count == 0) {
                remove(element);
            }
            int index = values.indexOf(element);
            if (index == -1) {
                return add(element, count);
            }
            int prevCount = frequency.get(index);
            frequency.set(index, count);
            return prevCount;
        }

        
        public int count(Object element) {
            int index = values.indexOf(element);

            return (index == -1) ? 0 : frequency.get(index);
        }

        
        public Set<E> elementSet() {
            return values.stream().collect(Collectors.toSet());
        }

        
        public boolean isEmpty() {
            return values.size() == 0;
        }

        
        public int size() {
            int size = 0;
            for (Integer i: frequency) {
                size += i;
            }
            return size;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder("[");
            for (int i = 0; i < values.size(); i++)
            {
                sb.append(values.get(i));

                if (frequency.get(i) > 1) {
                    sb.append(" x ").append(frequency.get(i));
                }

                if (i != values.size() - 1) {
                    sb.append(", ");
                }
            }
            return sb.append("]").toString();
        }
    }
}