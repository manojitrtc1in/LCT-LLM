import java.util.*;
import java.io.*;
import java.util.Map.Entry;
public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));;
    private static PrintWriter out;
    private static Reader in;
    private static StringTokenizer st;
    private static String next() throws IOException {
        while(st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    private static String readLine() throws IOException { return br.readLine().trim(); }
    private static int readInt() throws IOException { return Integer.parseInt(next()); }
    private static long readLong() throws IOException{ return Long.parseLong(next()); }
    private static char readCharacter() throws IOException { return next().charAt(0); }
    private static void exit() throws IOException {
        in.close();
        out.close();
        System.exit(0);
    }
    private static void print(Object o) { out.print(o); }
    private static void println(Object o) { out.println(o); }
    private static void flush() { out.flush(); }
    private static void println() { out.println(); }
    static void fill1D (int [] array, int l, int r, int val) { for(int i=l; i<r; i++) array[i] = val; }
    static void fill2D (int [][] array, int val) { for(int i=0; i<array.length; i++) Arrays.fill(array[i], val); }
    static void fill1D (String [] array, int l, int r, String val) { for(int i=l; i<r; i++) array[i] = val; }
    static void fill2D (String [][] array, String val) { for(int i=0; i<array.length; i++) Arrays.fill(array[i], val); }
    static void fill1D (double [] array, int l, int r, double val) { for(int i=l; i<r; i++) array[i] = val; }
    static void fill2D (double [][] array, double val) { for(int i=0; i<array.length; i++) Arrays.fill(array[i], val); }
    static void fill1D (long [] array, int l, int r, long val) { for(int i=l; i<r; i++) array[i] = val; }
    static void fill2D (long [][] array, long val) { for(int i=0; i<array.length; i++) Arrays.fill(array[i], val); }
    static void sort (int array[], int l, int r) { Arrays.sort(array, l, r); }
    static void sort (double array[], int l, int r){ Arrays.sort(array, l, r); }
    static void sort (long array[], int l, int r) { Arrays.sort(array, l, r); }
    static void sort (String array[], int l, int r) { Arrays.sort(array, l, r); }
    static void read1D (int array[], int N)throws IOException{
        for(int i=0; i<N; i++)
            array[i] = in.readInt();
    }
    static void Read1D (int array[], int N) throws IOException {
        for(int i=1; i<=N; i++)
            array[i] = in.readInt();
    }
    static void read2D (int array[][], int R, int C) throws IOException {
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                array[i][j] = in.readInt();
    }
    static void Read2D (int array[][], int R, int C) throws IOException {
        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
                array[i][j] = in.readInt();
    }
    static void read1D (double array[], int N)throws IOException{
        for(int i=0; i<N; i++)
            array[i] = in.readDouble();
    }
    static void Read1D (double array[], int N) throws IOException {
        for(int i=1; i<=N; i++)
            array[i] = in.readDouble();
    }
    static void read2D (double array[][], int R, int C) throws IOException {
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                array[i][j] = in.readDouble();
    }
    static void Read2D (double array[][], int R, int C) throws IOException {
        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
                array[i][j] = in.readDouble();
    }
    static void read1D (long array[], int N)throws IOException{
        for(int i=0; i<N; i++)
            array[i] = in.readLong();
    }
    static void Read1D (long array[], int N) throws IOException {
        for(int i=1; i<=N; i++)
            array[i] = in.readLong();
    }
    static void read2D (long array[][], int R, int C) throws IOException {
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                array[i][j] = in.readLong();
    }
    static void Read2D (long array[][], int R, int C) throws IOException {
        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
                array[i][j] = in.readLong();
    }
    static void read1D (String array[], int N)throws IOException{
        for(int i=0; i<N; i++)
            array[i] = in.read();
    }
    static void Read1D (String array[], int N) throws IOException {
        for(int i=1; i<=N; i++)
            array[i] = in.read();
    }
    static void read2D (char array[][], int R, int C) throws IOException {
        for(int i=0; i<R; i++) {
            String s = in.read();
            for (int j = 0; j < C; j++)
                array[i][j] = s.charAt(j);
        }
    }
    static void Read2D (char array[][], int R, int C) throws IOException {
        for(int i=1; i<=R; i++) {
            String s = in.read();
            for (int j = 1; j <= C; j++)
                array[i][j] = s.charAt(j-1);
        }
    }
    static int dijkstras(ArrayList<ArrayList<pii>> adj, int N, int st, int ed) {
        PriorityQueue<pii> pq = new PriorityQueue<pii>();
        int dis[] = new int[N+1];
        fill1D(dis, 0, dis.length, Integer.MAX_VALUE);
        dis[st] = 0;
        pq.add(new pii(0, st));
        while(!pq.isEmpty()) {
            pii u = pq.poll();
            if(u.f > dis[u.s]) continue;
            for(pii e: adj.get(u.s)){
                if(dis[e.s] > dis[u.s] + e.f) {
                    dis[e.s] = dis[u.s] + e.f;
                    pq.add(new pii(e.s, dis[e.s]));
                }
            }
        }
        return dis[ed];
    }
    static long dijkstras2(ArrayList<ArrayList<pli>> adj, int N, int st, int ed) {
        PriorityQueue<pli> pq = new PriorityQueue<pli>();
        long dis[] = new long[N+1];
        fill1D(dis, 0, dis.length, Integer.MAX_VALUE);
        dis[st] = 0;
        pq.add(new pli(0, st));
        while(!pq.isEmpty()) {
            pli u = pq.poll();
            if(u.f > dis[u.s]) continue;
            for(pli e: adj.get(u.s)){
                if(dis[e.s] > dis[u.s] + e.f) {
                    dis[e.s] = dis[u.s] + e.f;
                    pq.add(new pli(dis[e.s], e.s));
                }
            }
        }
        return dis[ed];
    }
    static int lowerBound(int[] array, int length, int value) {
        int low = 0;
        int high = length; 

        while (low < high) {
            final int mid = low + (high - low) / 2;
            if (value > array[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    static int lowerBound(long[] array, int length, long value) {
        int low=0;
        int high=length; 

        while(low < high) {
            final int mid = low + (high - low)/2;
            if(value > array[mid])
                low = mid + 1;
            else high = mid;
        }
        return low;
    }
    static int upperBound(int[] array, int length, int value) {
        int low = 0;
        int high = length;
        while (low < high) {
            final int mid = (low + high) / 2;
            if (value >= array[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    static int upperBound(long[] array, int length, long value) {
        int low = 0;
        int high = length;
        while (low < high) {
            final int mid = (low + high) / 2;
            if (value >= array[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    static int binarySearch(int[] array, int length, int value) {
        int lo=0, hi=length;
        while(lo < hi) {
            int m = (lo + hi)/2;
            if(array[m] == value) return m;
            if(array[m] < value) lo = m+1;
            else hi = m-1;
        }
        return -1;
    }
    static int binarySearch(long[] array, int length, long value) {
        int lo=0, hi=length;
        while(lo < hi) {
            int m = (lo + hi)/2;
            if(array[m] == value) return m;
            if(array[m] < value) lo = m+1;
            else hi = m-1;
        }
        return -1;
    }
    static int randInt(int lower, int upper) { return (int)(Math.random() * (upper-lower)) + lower; }
    static int max(int a, int b) {return Math.max(a, b);}
    static double max(double a, double b){return Math.max(a, b);}
    static long max(long a, long b) {return Math.max(a, b);}
    static int min(int a, int b) {return Math.min(a, b);}
    static double min(double a, double b){return Math.min(a, b);}
    static long min(long a, long b) {return Math.min(a, b);}
    static int abs(int a, int b) {return Math.abs(a - b);}
    static double abs(double a, double b) {return Math.abs(a - b);}
    static long abs(long a, long b) {return Math.abs(a - b);}
    static long randLong() { return new Random().nextLong(); }
    static int gcd(int p, int q) {
        if (q==0) return p;
        return gcd(q, p%q);
    }
    static long gcd(long p, long q){
        if(q == 0) return p;
        return gcd(q, p%q);
    }
    private static final String INPUT_FILE_NAME = ""; 

    private static final String OUTPUT_FILE_NAME = ""; 

    private static final int NUM_OF_TEST_CASES = 1; 

    private static boolean crash = true;
    private static boolean flush = false;
    private static final int MAXN = 100010; 

    private static final int INF = 0x3f3f3f3f;
    private static final long MOD = 998244353;
    public static void main(String[]args) throws Exception{
        if(INPUT_FILE_NAME.equals("")) in = new Reader(System.in);
        else in = new Reader(INPUT_FILE_NAME);
        if(OUTPUT_FILE_NAME.equals("")) out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        else out = new PrintWriter(new BufferedWriter(new FileWriter(OUTPUT_FILE_NAME)));
        for(int i=1 ;i<=NUM_OF_TEST_CASES; i++) {
            try {
                run(i);
            } catch (Exception e) {
                System.err.println("Exception thrown on test case " + i);
                e.printStackTrace(System.err);
                out.flush();
                if (crash) throw new Exception();
            }
            if(flush) out.flush();
        }
        exit();
    }
    private static void run(int testCaseNum) throws Exception {
        LinkedList<Integer> list = new LinkedList<>();
        int a[] = new int[101];
        System.out.print("? ");
        for(int i=1; i<=100; i++) {
            a[i] = i;
            System.out.print(a[i] + " ");
        }
        int res = in.readInt();
        int b[] = new int[101];
        System.out.print("? ");
        for(int i=1; i<=100; i++) {
            b[i] = i<<7;
            System.out.print(b[i] + " ");
        }
        int res2 = in.readInt();
        int x = 0;
        x |= (res & ((1<<7)-1)<<7);
        x |= (res2 & (1<<7)-1);
        System.out.println("! " + x);
    }
    static class Reader {
        final private static int BUFFER_SIZE = 1 << 16;
        private static DataInputStream din = new DataInputStream(System.in);
        private static byte[] buffer = new byte[BUFFER_SIZE];
        private static int bufferPointer = 0, bytesRead = 0;
        public Reader(InputStream stream) {
            din = new DataInputStream(stream);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        public Reader(String fileName) throws IOException {
            din = new DataInputStream(new FileInputStream(fileName));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        public  String readLine() throws IOException {
            byte[] buf = new byte[64]; 

            int cnt = 0, c;
            while ((c = Read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }
        public  String read() throws IOException{
            byte[] ret = new byte[1024];
            int idx = 0;
            byte c = Read();
            while (c <= ' ') {
                c = Read();
            }
            do {
                ret[idx++] = c;
                c = Read();
            } while (c != -1 && c != ' ' && c != '\n' && c != '\r');
            return new String(ret, 0, idx);
        }
        public int readInt() throws IOException {
            int ret = 0;
            byte c = Read();
            while (c <= ' ')
                c = Read();
            boolean neg = (c == '-');
            if (neg)
                c = Read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = Read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }
        public  long readLong() throws IOException {
            long ret = 0;
            byte c = Read();
            while (c <= ' ')
                c = Read();
            boolean neg = (c == '-');
            if (neg)
                c = Read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = Read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
        public  double readDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = Read();
            while (c <= ' ')
                c = Read();
            boolean neg = (c == '-');
            if (neg)
                c = Read();

            do {
                ret = ret * 10 + c - '0';
            } while ((c = Read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = Read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }
        private  void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
        private  byte Read() throws IOException {
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
    static class pii implements Comparable<pii> {
        int f, s;
        public pii(int f, int s) {
            this.f=f;
            this.s=s;
        }
        @Override
        public int compareTo(pii other) {
            if(f == other.f)
                return Integer.compare(s, other.s);
            return Integer.compare(f, other.f);
        }
    }
    static class pli implements Comparable<pli> {
        long f; int s;
        public pli(long f, int s){
            this.f=f;
            this.s=s;
        }
        @Override
        public int compareTo(pli other){
            if(f == other.f)
                return Integer.compare(s, other.s);
            return Long.compare(f, other.f);
        }
    }
    static class pll implements Comparable<pll> {
        long f, s;
        public pll(long f, long s) {
            this.f=f;
            this.s=s;
        }
        @Override
        public int compareTo(pll other){
            if(f == other.f)
                return Long.compare(s, other.s);
            return Long.compare(f, other.f);
        }
    }
    static class psi implements Comparable<psi> {
        String f; int s;
        public psi(String f, int s) {
            this.f=f; this.s=s;
        }
        @Override
        public int compareTo(psi other) {
            if(s == other.s)
                return f.compareTo(other.f);
            return Integer.compare(s, other.s);
        }
    }
    static class psl implements Comparable<psl> {
        String f;
        long s;

        public psl(String f, long s) {
            this.f = f;
            this.s = s;
        }

        @Override
        public int compareTo(psl other) {
            if (s == other.s)
                return f.compareTo(other.f);
            return Long.compare(s, other.s);
        }
    }
    static class DUS {
        int rank[];
        int parent[];
        int n;
        public DUS(int n) {
            rank = new int[n];
            parent = new int[n];
            this.n = n;
            makeSet();
        }
        public void makeSet() {
            for(int i = 0; i < n; i++)
                parent[i] = i;
        }
        public int find(int x) { 

            if(parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        public void union(int x, int y) { 

            int xRoot = find(x);
            int yRoot = find(y);

            if(xRoot == yRoot) return;

            if(rank[xRoot] < rank[yRoot]) parent[xRoot] = yRoot;

            else if(rank[yRoot] < rank[xRoot]) parent[yRoot] = xRoot;

            else {
                parent[yRoot] = xRoot;
                rank[xRoot]++;
            }
        }
    }
    static class Node implements Comparable<Node>{
        int u, v, w;
        public Node(int u, int v, int w){
            this.u=u;
            this.v=v;
            this.w=w;
        }
        @Override
        public int compareTo(Node o) {
            return Integer.compare(w, o.w);
        }
    }
}