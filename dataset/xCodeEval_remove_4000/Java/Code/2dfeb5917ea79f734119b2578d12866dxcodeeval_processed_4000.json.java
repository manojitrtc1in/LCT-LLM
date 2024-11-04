import java.io.*;
import java.util.*;


public class id15 implements Runnable {
    static EventType eventType = EventType.DEFAULT; 

    static int T = 1; 

    static String inputFilename = null; 


    static boolean id5 = false; 

    static int id10 = 1;

    


    public static class Solver extends  SolverAbstract{

        int N;
        long A;
        long B;
        long[] X;
        long[] VX;
        long[] VY;

        @Override
        public void readInput() throws IOException {
            N = scanner.nextInt(); 

            A = scanner.nextLong(); 

            B = scanner.nextLong(); 

            X = new long[N];
            VX = new long[N];
            VY = new long[N];
            for (int i = 0; i < N; i++) {
                X[i] = scanner.nextInt(); 

                VX[i] = scanner.nextInt(); 

                VY[i] = scanner.nextInt(); 

            }
        }

        @Override
        protected void solve() throws IOException {
            long[] y = new long[N];
            long ABx = 1;
            long ABy = A;

            Map<Long, Map<Long, Integer>> map = new HashMap<>();
            for (int i = 0; i < N; i++) {
                y[i] = X[i] * A + B;
                long ortog = formulae(ABx, ABy, VX[i], VY[i]);
                long projection = proj(VX[i], VY[i]);
                Map<Long, Integer> id0 = map.computeIfAbsent(ortog, k -> new HashMap<>());
                int cnt = id0.computeIfAbsent(projection, k-> 0);
                id0.put(projection, cnt+1);
            }
            long res = 0;
            for(Map<Long, Integer> id0 : map.values()){
                long cntAll = 0;
                for(Integer cnt : id0.values()){
                    cntAll += cnt;
                }
                

                for(Integer cnt : id0.values()){
                    long meetings = cnt * (cntAll-cnt); 

                    res += meetings;
                }
            }
            out.println(res);
        }

        private long norm2(long vx, long vy){
            return vx*vx + vy*vy;
        }

        private long id6(long vx1, long vy1, long vx2, long vy2){
            long p = dot_product(vx1, vy1, vx2, vy2);
            return p * p;
        }

        private long dot_product(long vx1, long vy1, long vx2, long vy2){
            return vx1 * vx2 + vy1 * vy2;
        }














        private long formulae(long vx1, long vy1, long vx2, long vy2){
            return vx1 * vy2 - vy1 * vx2;
        }

        private long proj(long vx1, long vy1){
            return dot_product(vx1, vy1, 1, A);
        }
    }

    


    private void solveAll() throws IOException {
        long timeStart = System.currentTimeMillis();
        if (T==0) {
            if (id5) {
                T = id10;
            } else {
                T = scanner.nextInt();
            }
        }
        final String[] results = new String[T+1];
        for (int test = 0; test < T; test++) {
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            PrintStream outLocal = new PrintStream(baos);
            Solver solver = new Solver(){
                @Override
                public void callback() {
                    results[testNo] = answer;
                }
            };
            solver.out = outLocal;
            solver.testNo = test+1;
            if (id5) {
                solver.readFakeInput();
            }else{
                solver.readInput();
            }
            solver.solveWrapped(baos);
        }

        long timeEnd = System.currentTimeMillis();
        if (isInputFromFile())
            System.out.println("All tasks are solved! Elapsed time "+(timeEnd-timeStart)/1000.0+" sec.");

        

        for (int i = 1; i <= T; i++) {
            if (eventType == EventType.GOOGLE_CODE_JAM){
                outGlobal.printf("Case 
            }else {
                outGlobal.print(results[i]);
            }
        }
    }

    enum EventType{
        DEFAULT,
        GOOGLE_CODE_JAM
    }

    static boolean isInputFromFile() {
        return inputFilename != null;
    }

    public static abstract class SolverAbstract {
        PrintStream out;
        int testNo;
        String answer = null;

        public void callback(){};

        public abstract void readInput() throws IOException;

        

        public void readFakeInput() throws  IOException{
            throw new RuntimeException("not implemented");
        }

        protected abstract void solve() throws IOException;

        protected void solveWrapped(ByteArrayOutputStream baos) throws IOException {
            if (isInputFromFile())
                System.out.println("SOLVER: solving task 
            solve();
            answer = baos.toString();
            if (isInputFromFile()) {
                System.out.println("\t"+answer);
            }
            callback();
        }
    }

    

    



    

    

    static class Graph{

        int[][] G;
        int N;

        int[][] A;
        int[][] F;

        int[] path;
        int pathLen;
        boolean[] visited;
        int target;
        boolean flowFound;

        public Graph(int[][] g) {
            G = g;
            N = G.length;
        }

        public int[][] maxflow(int iSource, int iSink) {
            path = new int[N];
            visited = new boolean[N];

            A = new int[N][];
            for (int i = 0; i < N; i++) {
                A[i] = G[i].clone();
            }
            F = new int[N][N];

            target = iSink;
            

            

            while(true){
                flowFound = false;
                visited[iSource] = true;
                pathLen = 0;
                path[pathLen++] = iSource;
                dfs(iSource);
                if (!flowFound)
                    break;
            }
            return F;
        }

        private void dfs(int u) {
            if (u==target){
                flowFound = true;
                for (int i = 0; i < pathLen-1; i++) {
                    int from = path[i];
                    int to  = path[i+1];
                    F[from][to]++;
                    F[to][from]--;
                }
            }else {
                for (int i = 0; i < N && !flowFound; i++) {
                    if (!visited[i] && A[u][i] > F[u][i]) {
                        visited[i] = true;
                        path[pathLen] = i;
                        pathLen++;
                        dfs(i);
                        visited[i] = false;
                        pathLen--;
                    }
                }
            }
        }
    }

    public static class Utilities{
        public static List<Integer> id9(int limit) {
            boolean[] primes = new boolean[limit+1];
            Arrays.fill(primes, true);

            primes[1] = false;
            for(int i=2; i<=limit; i++){
                if (primes[i]){
                    for(int j=i+i; j<=limit; j+=i){
                        primes[j] = false;
                    }
                }
            }
            List<Integer> id2 = new ArrayList<>();
            for(int i=2; i<=limit; i++){
                if (primes[i]){
                    id2.add(i);
                }
            }
            return id2;
        }
    }

    public static class Modulo{
        long mod = (long)1e9+7;

        public Modulo(long mod) {
            super();
            this.mod = mod;
        }

        public long inv(long a) {
            long res =  pow(a, mod-2);
            return res;
        }

        public long pow(long a, long x) {
            if (x==0)
                return 1;
            long part = 1;
            if ((x&1)!=0)
                part = a;
            return (part * pow((a*a)%mod, x>>1)) % mod;
        }

        public long c(long n, long m){
            long res = 1;
            for(int i=1; i<=m; i++){
                res = (res * (n-m+i)) % mod;
                res = (res * inv(i)) % mod;
            }
            return res;
        }
    }

    
    static class id1 implements Cloneable{
        int[] rank;
        int[] parent;

        protected id1 clone(){
            id1 cloned = new id1(parent.length);
            for(int i=0; i<parent.length; i++){
                cloned.parent[i] = parent[i];
                cloned.rank[i] = rank[i];
            }
            return cloned;
        }

        public id1(int n) {
            rank = new int[n];
            parent = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        @Override
        public String toString() {
            return "disj [parents=" + Arrays.toString(parent) + "]";
        }

        
        public void union(id1 set2){
            for(int i=0; i<parent.length; i++){
                parent[find(i)] = parent[find(set2.find(i))];
            }
        }

        
        public void union(int index1, int index2){
            int p1 = find(index1);
            int p2 = find(index2);
            if (rank[p1] > rank[p2]){
                parent[p2] = p1;
            }else if (rank[p2] > rank[p1]){
                parent[p1] = p2;
            }else{
                parent[p2] = p1;
                rank[p1]++;
            }
        }

        

        private int find(int index) {
            if (parent[index] != index)
                parent[index] =  find(parent[index]);
            return parent[index];
        }

        

        public int id11(){
            int[] used = new int[parent.length];
            for(int i=0; i<parent.length; i++){
                used[find(i)] = 1;
            }
            int res = 0;
            for(int i=0; i<parent.length; i++){
                res += used[i];
            }
            return res;
        }
    }

    private static Random rnd = new Random();
    public static class ArrayUtils{
        public static void shuffle(int[] a){
            for(int j=a.length-1; j>=1; j--){
                int i = rnd.nextInt(j+1);
                swap(a, i, j);
            }
        }

        public static void swap(int[] a, int i, int j){
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }

    static class GraphSupport{
        
    }


    

    

    

    final int BUF_SIZE = 1024 * 1024 * 8;

    final int id14 = 1024 * 1024 * 8;
    final int id7 = 1024;

    boolean id18 = true;
    String outSuffix = ".out";

    static PrintStream outGlobal;
    static ByteScanner scanner;

    public void run() {
        try{
            InputStream bis;
            OutputStream bos;
            if (inputFilename !=null){
                File inputFile;
                File outputFile;
                if (id18) {
                    File baseFile = new File(getClass().getResource("/").getFile());
                    inputFile = new File(baseFile, inputFilename);
                    outputFile = new File(baseFile, inputFilename +outSuffix);
                }else{
                    inputFile = new File(inputFilename);
                    outputFile = new File(inputFilename +outSuffix);
                }
                System.out.println("Input file canonical path: "+inputFile.getCanonicalPath());
                bis = new BufferedInputStream(
                        new FileInputStream(inputFile),
                        id14);
                bos = new BufferedOutputStream(new FileOutputStream(outputFile));
                outGlobal = new PrintStream(bos);
            }else{
                bis = new BufferedInputStream(System.in, id14);
                bos = new BufferedOutputStream(System.out);
                outGlobal = new PrintStream(bos);
            }
            scanner = new ByteScanner(bis, id7, BUF_SIZE);

            solveAll();
            outGlobal.flush();
        }catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static class id3 extends IOException{
    }

    public static class ByteScanner{
        InputStream is;

        public ByteScanner(InputStream is, int id4, int bufSize){
            this.is = is;
            this.id4 = id4;
            this.bufSize = bufSize;

            id16 = new byte[this.id4];
            byteBuf = new byte[this.bufSize];
        }

        public ByteScanner(byte[] data){
            id16 = data;
            id4 = data.length;
            bufSize = data.length;
            byteBuf = new byte[bufSize];
            byteRead = data.length;
            bytePos = 0;
        }

        private int id4;
        private int bufSize;

        byte[] id16;
        byte by=-1;
        int byteRead=-1;
        int bytePos=-1;

        byte[] byteBuf;
        int totalBytes;

        boolean id12 = false;

        private byte nextByte() throws IOException{
            if (bytePos<0 || bytePos>=byteRead){
                byteRead = is==null? -1: is.read(id16);
                bytePos=0;
                if (byteRead<0){
                    id16[bytePos]=-1;

                    if (id12)
                        throw new id3();
                    id12 = true;
                }
            }
            return id16[bytePos++];
        }

        public byte id8() throws IOException{
            while ((by=nextByte())<=0x20);
            return by;
        }

        public String nextLine() throws IOException {
            readToken((byte)0x20);
            return new String(byteBuf,0,totalBytes);
        }

        

        public String nextToken() throws IOException {
            readToken((byte)0x21);
            return new String(byteBuf,0,totalBytes);
        }

        

        private void readToken() throws IOException {
            readToken((byte)0x21);
        }

        private void readToken(byte acceptFrom) throws IOException {
            totalBytes = 0;
            while ((by=nextByte())<acceptFrom);
            byteBuf[totalBytes++] = by;
            while ((by=nextByte())>=acceptFrom){
                byteBuf[totalBytes++] = by;
            }
        }

        public int nextInt() throws IOException{
            readToken();
            int num=0, i=0;
            boolean sign=false;
            if (byteBuf[i]=='-'){
                sign = true;
                i++;
            }
            for (; i<totalBytes; i++){
                num*=10;
                num+=byteBuf[i]-'0';
            }
            return sign?-num:num;
        }

        public long nextLong() throws IOException{
            readToken();
            long num=0;
            int i=0;
            boolean sign=false;
            if (byteBuf[i]=='-'){
                sign = true;
                i++;
            }
            for (; i<totalBytes; i++){
                num*=10;
                num+=byteBuf[i]-'0';
            }
            return sign?-num:num;
        }

        public double nextDouble() throws IOException{
            readToken();
            char[] token = new char[totalBytes];
            for (int i = 0; i < totalBytes; i++) {
                token[i] = (char)byteBuf[i];
            }
            return Double.parseDouble(new String(token));
        }

        public int[] id17(int size) throws IOException{
            int[] a = new int[size];
            for (int i = 0; i < a.length; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public long[] id13(int size) throws IOException{
            long[] a = new long[size];
            for (int i = 0; i < a.length; i++) {
                a[i] = nextLong();
            }
            return a;
        }
    }

    public static void main(String[] args) {
        new id15().run();
    }
}