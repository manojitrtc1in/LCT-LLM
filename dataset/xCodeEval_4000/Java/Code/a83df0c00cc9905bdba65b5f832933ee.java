import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try {
            long startTime = System.currentTimeMillis();
 
            final FastPrinter fp = new FastPrinter(System.out);
            final FastReader fr = new FastReader(System.in);
 
            Solution solver = new Solution(fp, fr);
 
            boolean multipleTC = true;
            int test = multipleTC ? fr.nextInt() : 1;
 
            while (test-- > 0) {
                

                solver.solve();
            }
 
            solver.printAns();
 
            long endTime = System.currentTimeMillis();
            if (System.getProperty("ONLINE_JUDGE") == null) {
                

            }
 
            fp.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
 

class Solution {
 
    private final FastPrinter fPrinter;
    private final FastReader fReader;
 
    private final StringBuilder ans;
 
    private final long mod = (long) 1e9 + 7;
 
    public Solution(FastPrinter _fPrinter, FastReader _fReader) {
        fReader = _fReader;
        fPrinter = _fPrinter;
        ans = new StringBuilder();
        

    }
 
    @SuppressWarnings("unchecked")
    public void solve() throws IOException {
        int n = fReader.nextInt();
        long x = fReader.nextLong();
        long[] arr = new long[n];
        TreeMap<Long, Long> freq = new TreeMap<>();
        
        for (int i = 0; i < n; i++) {
            arr[i] = fReader.nextLong();
            freq.put(arr[i], !freq.containsKey(arr[i]) ? 1 : freq.get(arr[i]) + 1);
        }

        ArrayList<Long> list = new ArrayList<>(freq.keySet());

        int res1 = 0, res2 = 0;

        for (int i = 0; i < list.size(); i++) {
            long k = list.get(i);
            long r1 = 0, r2 = 0;
            if (k % x == 0 && freq.containsKey(k / x) && freq.containsKey(k * x)) {
                r1 = Math.min(freq.get(k / x), freq.get(k));
                r2 = Math.min(freq.get(k), freq.get(k * x));
                if (r1 >= r2) {
                    freq.put(k / x, freq.get(k / x) - r1);
                    freq.put(k, freq.get(k) - r1);
                    r2 = Math.min(freq.get(k), freq.get(k * x));
                    freq.put(k * x, freq.get(k * x) - r2);
                    freq.put(k, freq.get(k) - r2);
                } else {
                    freq.put(k * x, freq.get(k * x) - r2);
                    freq.put(k, freq.get(k) - r2);
                    r1 = Math.min(freq.get(k / x), freq.get(k));
                    freq.put(k / x, freq.get(k / x) - r1);
                    freq.put(k, freq.get(k) - r1);
                }
            } else if (k % x == 0 && freq.containsKey(k / x)) {
                r1 = Math.min(freq.get(k / x), freq.get(k));
                freq.put(k / x, freq.get(k / x) - r1);
                freq.put(k, freq.get(k) - r1);
            } else if (freq.containsKey(k * x)) {
                r2 = Math.min(freq.get(k), freq.get(k * x));
                freq.put(k * x, freq.get(k * x) - r2);
                freq.put(k, freq.get(k) - r2);
            }
        }

        long res = 0;
        for (long k : freq.keySet()) {
            if (freq.get(k) > 0) {
                res += freq.get(k);
            }
        }

        

        
        ans.append(res).append('\n');
    }
 
    char[][] rotate(char[][] grid, int n) {
        char[][] res = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[j][n - i - 1] = grid[i][j];
            }
        }
        return res;
    }
 
    private List<Integer> primeFactors(int num) {
        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i * i <= num; i++) {
            while (num % i == 0) {
                num /= i;
                primes.add(i);
            }
        }
        if (num != 1) {
            primes.add(num);
        }
        return primes;
    }
 
    private boolean nextPermutation(int[] arr) {
        for (int a = arr.length - 2; a >= 0; a--) {
            if (arr[a] < arr[a + 1]) {
                for (int b = arr.length - 1;; b--) {
                    if (arr[b] > arr[a]) {
                        int t = arr[a];
                        arr[a] = arr[b];
                        arr[b] = t;
                        for (++a, b = arr.length - 1; a < b; ++a, --b) {
                            t = arr[a];
                            arr[a] = arr[b];
                            arr[b] = t;
                        }
                        return true;
                    }
                }
            }
        }
        return false;
    }
 
    private boolean nextPermutation(char[] arr) {
        for (int a = arr.length - 2; a >= 0; a--) {
            if (arr[a] < arr[a + 1]) {
                for (int b = arr.length - 1;; b--) {
                    if (arr[b] > arr[a]) {
                        char t = arr[a];
                        arr[a] = arr[b];
                        arr[b] = t;
                        for (++a, b = arr.length - 1; a < b; ++a, --b) {
                            t = arr[a];
                            arr[a] = arr[b];
                            arr[b] = t;
                        }
                        return true;
                    }
                }
            }
        }
        return false;
    }
 
    public int kthLeftMostBti(long n) {
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        n |= n >> 32;
        n++;
        n = n >> 1;
        for (int i = 63; i >= 0; i--) {
            if (pow(2, i) == n) {
                return i;
            }
        }
        return 0;
    }
 
    public long pow(long a, long b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 0) {
                a *= a;
                b = b >> 1;
            } else {
                res *= a;
                b--;
            }
        }
        return res;
    }
 
    public long ways(long n, long r) {
        if (n < 0 || r < 0)
            return 0;
        if (n == 0 || r == 0)
            return 1;
        double res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
        }
        return (long) res;
    }
 
    private static boolean[] sieve = new boolean[1_000_000];
 
    private static void initializeSieve() {
        Arrays.fill(sieve, true);
        for (int i = 2; i * i < sieve.length; i++) {
            if (sieve[i]) {
                for (int j = i * i; j < sieve.length; j += i) {
                    sieve[j] = false;
                }
            }
        }
    }
 
    private long getSumArray(long[] arr, int n) {
        long sum = 0;
        for (long num : arr)
            sum += num;
        return sum;
    }
 
    private int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
 
    private long gcd(long a, long b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
 
    private void sortArray(String[] arr, int s, int n) {
        Random r = new Random();
        for (int i = s; i < n; i++) {
            int idx = r.nextInt(n);
            String temp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = temp;
        }
 
        Arrays.sort(arr, s, n);
    }
 
    private void sortArray(char[] arr, int s, int n) {
        Random r = new Random();
        for (int i = s; i < n; i++) {
            int idx = r.nextInt(n);
            char temp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = temp;
        }
 
        Arrays.sort(arr, s, n);
    }
 
    private void sortArray(long[] arr, int s, int n) {
        Random r = new Random();
        for (int i = s; i < n; i++) {
            int idx = r.nextInt(n);
            long temp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = temp;
        }
 
        Arrays.sort(arr, s, n);
    }
 
    private void sortArray(int[] arr, int s, int n) {
        Random r = new Random();
        for (int i = s; i < n; i++) {
            int idx = r.nextInt(n);
            int temp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = temp;
        }
 
        Arrays.sort(arr, s, n);
    }
 
    public void printAns() {
        fPrinter.println(ans);
    }
}
 
class Pair<T extends Comparable<T>, U extends Comparable<U>> implements Comparable<Pair<T, U>> {
    T first;
    U second;
 
    Pair(T f, U s) {
        first = f;
        second = s;
    }
 
    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Pair))
            return false;
        Pair<?, ?> p = (Pair<?, ?>) obj;
        return Objects.equals(p.first, first) && Objects.equals(p.second, second);
    }
 
    @Override
    public int hashCode() {
        return (first == null ? 0 : first.hashCode()) ^ (second == null ? 0 : second.hashCode());
    }
 
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[").append(first.toString());
        sb.append(", ").append(second.toString());
        sb.append("]");
        return sb.toString();
    }
 
    @Override
    public int compareTo(Pair<T, U> o) {
        int c;
        if ((c = this.first.compareTo(o.first)) == 0)
            return this.second.compareTo(o.second);
        

        return c;
        

    }
}
 
class DSU {
    int size;
    int[] parent;
    int[] rank;
 
    public DSU(int n) {
        size = n + 1;
        parent = new int[n + 1];
        rank = new int[n + 1];
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        Arrays.fill(rank, 1);
    }
 
    int getParent(int v) {
        if (parent[v] == v) {
            return v;
        }
        return parent[v] = getParent(parent[v]);
    }
 
    void union(int x, int y) {
        x = getParent(x);
        y = getParent(y);
        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
            rank[y]++;
        }
    }
}
 
class SegmentTree {
    int[] tree;
    int size;
 
    public SegmentTree(int n) {
        size = n;
        tree = new int[4 * size];
    }
 
    

    

    

    

    

    

    

    

    

    

}
 
class FastPrinter {
    private final PrintWriter out;
 
    FastPrinter(OutputStream out) {
        this.out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(out)));
    }
 
    public void printlnArray(int[] arr) {
        for (int i : arr) {
            out.println(i);
        }
    }
 
    public void printlnArray(long[] arr) {
        for (long i : arr) {
            out.println(i);
        }
    }
 
    public void printArray(int[] arr) {
        for (int i : arr) {
            out.print(i + " ");
        }
        out.println();
    }
 
    public void printArray(long[] arr) {
        for (long i : arr) {
            out.print(i + " ");
        }
        out.println();
    }
 
    public void println() {
        out.println();
    }
 
    public void println(String s) {
        out.println(s);
    }
 
    public void println(int s) {
        out.println(s);
    }
 
    public void println(long s) {
        out.println(s);
    }
 
    public void println(double s) {
        out.println(s);
    }
 
    public void println(Object o) {
        out.println(o);
    }
 
    public void print(String s) {
        out.print(s);
    }
 
    public void print(Object a) {
        out.print(a);
    }
 
    public void flush() {
        out.flush();
    }
 
    public void close() {
        out.close();
    }
}
 
class FastReader {
    private static final int BUFFER_SIZE = 1 << 17;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer;
    private int bytesRead;
 
    public FastReader(InputStream in) {
        din = new DataInputStream(in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }
 
    public FastReader(String file_name) throws IOException {
        din = new DataInputStream(new FileInputStream(file_name));
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }
 
    public char next() throws IOException {
        byte c = read();
        return c == -1 ? '\0' : (char) c;
    }
 
    public String nextLine() throws IOException {
        StringBuilder sb = new StringBuilder();
        byte c = read();
        while (c != '\r' && c != '\n' && c != -1) {
            sb.append((char) c);
            c = read();
        }
        return sb.toString();
    }
 
    public int nextInt() throws IOException {
        int ret = 0;
        byte c = read();
 
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
 
        if (neg)
            c = read();
 
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
 
        if (neg)
            return -ret;
        return ret;
    }
 
    public long nextLong() throws IOException {
        long ret = 0;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (neg)
            return -ret;
        return ret;
    }
 
    public double nextDouble() throws IOException {
        double ret = 0, div = 1;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();
 
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
 
        if (c == '.') {
            while ((c = read()) >= '0' && c <= '9') {
                ret += (c - '0') / (div *= 10);
            }
        }
 
        if (neg)
            return -ret;
        return ret;
    }
 
    public int[] nextIntArray(int size) throws IOException {
        int[] arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = nextInt();
        }
        return arr;
    }
 
    public int[] nextIntArray(int size, int pos) throws IOException {
        int[] arr = new int[size + pos];
        for (int i = pos; i < size + pos; i++) {
            arr[i] = nextInt();
        }
        return arr;
    }
 
    public long[] nextLongArray(int size) throws IOException {
        long[] arr = new long[size];
        for (int i = 0; i < size; i++) {
            arr[i] = nextLong();
        }
        return arr;
    }
 
    public long[] nextLongArray(int size, int pos) throws IOException {
        long[] arr = new long[size + pos];
        for (int i = pos; i < size + pos; i++) {
            arr[i] = nextLong();
        }
        return arr;
    }
 
    public int[][] nextIntMatrix(int n, int m) throws IOException {
        int[][] arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            arr[i] = nextIntArray(m);
        }
        return arr;
    }
 
    public long[][] nextLongMatrix(int n, int m) throws IOException {
        long[][] arr = new long[n][m];
        for (int i = 0; i < n; i++) {
            arr[i] = nextLongArray(m);
        }
        return arr;
    }
 
    public ArrayList<Integer> nextIntList(int size) throws IOException {
        ArrayList<Integer> arrayList = new ArrayList<>(size);
        for (int i = 0; i < size; i++) {
            arrayList.add(nextInt());
        }
        return arrayList;
    }
 
    public ArrayList<Long> nextLongList(int size) throws IOException {
        ArrayList<Long> arrayList = new ArrayList<>(size);
        for (int i = 0; i < size; i++) {
            arrayList.add(nextLong());
        }
        return arrayList;
    }
 
    private void fillBuffer() throws IOException {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1)
            buffer[0] = -1;
    }
 
    private byte read() throws IOException {
        if (bufferPointer == bytesRead)
            fillBuffer();
        return buffer[bufferPointer++];
    }
 
    public void close() throws IOException {
        if (din == null)
            return;
        din.close();
    }
}