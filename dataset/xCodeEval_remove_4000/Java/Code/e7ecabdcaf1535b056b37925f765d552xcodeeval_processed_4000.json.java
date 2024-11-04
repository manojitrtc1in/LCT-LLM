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
    static void id0 (int [] array, int l, int r, int val) { for(int i=l; i<r; i++) array[i] = val; }
    static void id9 (int [][] array, int val) { for(int i=0; i<array.length; i++) Arrays.fill(array[i], val); }
    static void id0 (String [] array, int l, int r, String val) { for(int i=l; i<r; i++) array[i] = val; }
    static void id9 (String [][] array, String val) { for(int i=0; i<array.length; i++) Arrays.fill(array[i], val); }
    static void id0 (double [] array, int l, int r, double val) { for(int i=l; i<r; i++) array[i] = val; }
    static void id9 (double [][] array, double val) { for(int i=0; i<array.length; i++) Arrays.fill(array[i], val); }
    static void id0 (long [] array, int l, int r, long val) { for(int i=l; i<r; i++) array[i] = val; }
    static void id9 (long [][] array, long val) { for(int i=0; i<array.length; i++) Arrays.fill(array[i], val); }
    static void sort (int array[], int l, int r) { Arrays.sort(array, l, r); }
    static void sort (double array[], int l, int r){ Arrays.sort(array, l, r); }
    static void sort (long array[], int l, int r) { Arrays.sort(array, l, r); }
    static void sort (String array[], int l, int r) { Arrays.sort(array, l, r); }
    static void id10 (int array[], int N)throws IOException{
        for(int i=0; i<N; i++)
            array[i] = in.readInt();
    }
    static void id8 (int array[], int N) throws IOException {
        for(int i=1; i<=N; i++)
            array[i] = in.readInt();
    }
    static void id5 (int array[][], int R, int C) throws IOException {
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                array[i][j] = in.readInt();
    }
    static void id6 (int array[][], int R, int C) throws IOException {
        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
                array[i][j] = in.readInt();
    }
    static void id10 (double array[], int N)throws IOException{
        for(int i=0; i<N; i++)
            array[i] = in.readDouble();
    }
    static void id8 (double array[], int N) throws IOException {
        for(int i=1; i<=N; i++)
            array[i] = in.readDouble();
    }
    static void id5 (double array[][], int R, int C) throws IOException {
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                array[i][j] = in.readDouble();
    }
    static void id6 (double array[][], int R, int C) throws IOException {
        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
                array[i][j] = in.readDouble();
    }
    static void id10 (long array[], int N)throws IOException{
        for(int i=0; i<N; i++)
            array[i] = in.readLong();
    }
    static void id8 (long array[], int N) throws IOException {
        for(int i=1; i<=N; i++)
            array[i] = in.readLong();
    }
    static void id5 (long array[][], int R, int C) throws IOException {
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                array[i][j] = in.readLong();
    }
    static void id6 (long array[][], int R, int C) throws IOException {
        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
                array[i][j] = in.readLong();
    }
    static void id10 (String array[], int N)throws IOException{
        for(int i=0; i<N; i++)
            array[i] = in.read();
    }
    static void id8 (String array[], int N) throws IOException {
        for(int i=1; i<=N; i++)
            array[i] = in.read();
    }
    static void id5 (char array[][], int R, int C) throws IOException {
        for(int i=0; i<R; i++) {
            String s = in.read();
            for (int j = 0; j < C; j++)
                array[i][j] = s.charAt(j);
        }
    }
    static void id6 (char array[][], int R, int C) throws IOException {
        for(int i=1; i<=R; i++) {
            String s = in.read();
            for (int j = 1; j <= C; j++)
                array[i][j] = s.charAt(j-1);
        }
    }
    static int id4(ArrayList<ArrayList<pii>> adj, int N, int st, int ed) {
        PriorityQueue<pii> pq = new PriorityQueue<pii>();
        int dis[] = new int[N+1];
        id0(dis, 0, dis.length, Integer.MAX_VALUE);
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
    static long id7(ArrayList<ArrayList<pli>> adj, int N, int st, int ed) {
        PriorityQueue<pli> pq = new PriorityQueue<pli>();
        long dis[] = new long[N+1];
        id0(dis, 0, dis.length, Integer.MAX_VALUE);
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
    private static final String id11 = ""; 

    private static final String id1 = ""; 

    private static final int id2 = 1; 

    private static boolean crash = true;
    private static boolean flush = false;
    private static final int MAXN = 100010; 

    private static final int INF = 0x3f3f3f3f;
    public static void main(String[]args) throws Exception{
        if(id11.equals("")) in = new Reader(System.in);
        else in = new Reader(id11);
        if(id1.equals("")) out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        else out = new PrintWriter(new BufferedWriter(new FileWriter(id1)));
        for(int i=1 ;i<=id2; i++) {
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
    private static void run(int id3) throws Exception {
        int T = readInt();
        while(T-- > 0) {
            int n = readInt();
            long a = readLong(), b = readLong();
            String pipe = next();
            long dp[] = new long[n+5];
            dp[0] = b;
            int curval=-1, prev=0;
            long slope=b;
            int pre[] = new int[n+1];
            Arrays.fill(pre, -1);
            for(int i=pipe.length()-1; i>=0; i--) {
                if (pipe.charAt(i) == '1') {
                    pre[i] = i;
                }
                else pre[i] = pre[i+1];
            }
            for(int i=1; i<=pipe.length(); i++) {
                if(i < pipe.length()) curval = Integer.parseInt(pipe.charAt(i)+"");
                if(prev == 1 && curval == 0) {
                    int nxt = pre[i];
                    

                    if(nxt == -1) {
                        dp[i+1] += a;
                        dp[i] += slope + dp[i-1];
                        slope -= b;
                    }
                    else {
                        int diff = nxt - i - 1;
                        long line1 = 2*b*diff;
                        long line2 = b*diff+2*a;
                       

                        if(line1 <= line2) {
                            

                            dp[i] += slope + dp[i-1];
                        }
                        else {
                            

                            dp[i+1] += a;
                            dp[i] += slope + dp[i-1];
                            slope -= b;
                        }
                    }
                }
                if(prev == curval) dp[i] += slope + dp[i-1];
                if(prev == 0 && curval == 1) {
                    

                    if(slope == 2*b)
                        dp[i] += dp[i-1] + slope;
                    else {
                        slope += b;
                        dp[i] += a + dp[i - 1] + slope;
                    }
                }
                dp[i] += a;
                prev = curval;
            }
            

             


            System.out.println(dp[n]);
        }
    }
    static int findnext(int start, String s) {
        for(int i=start+1; i<s.length(); i++)
            if(s.charAt(i) == '1') return i;
        return -1;
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