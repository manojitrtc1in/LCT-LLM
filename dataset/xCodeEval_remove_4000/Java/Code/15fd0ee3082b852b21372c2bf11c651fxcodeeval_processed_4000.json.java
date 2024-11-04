import java.io.*;
import java.util.*;


public class id19 implements Runnable {

    static EventType eventType = EventType.DEFAULT;



    

    

    static int T = 1;

    







    static String inputFilename = null;


    

    static boolean id6 = false;
    

    static int id13 = 100;


    




    public static class Solver extends SolverAbstract {


        @Override 

        public void readInput() throws IOException {
            int MAX = 1_000_000;

            int n = scanner.nextInt(); 

            char[] A = scanner.nextToken().toCharArray();
            int[] a = new int[n];

            int cnt1 = 0;
            for (int i = 0; i < n; i++) {
                a[i] = A[i] == 'r' ? 0 : 1; 

                cnt1 += a[i];
            }



            

            int res = MAX;
            for (int start = 0; start < 2; start++) {
                int[] a1 = a.clone();
                int cur_res = 0;

                int id23 = 0;
                int[] a0 = new int[n];
                for (int i = start; i < n; i+=2) {
                    a0[i] = 1;
                    id23 += a0[i];
                }

                int id10 = 0;
                for (int i = start; i < n; i+=2) {
                    if (a0[i] == a1[i]){
                        id10++;
                    }
                }

                cur_res += Math.max( Math.abs(id23 - id10), Math.abs(cnt1 - id10));
                res = Math.min(res, cur_res);
            }




            
            

            outLocal.println(res);

        }

        @Override
        protected void solve() throws IOException {
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

    


    private void solveAll() throws IOException, InterruptedException {
        long timeStart = System.currentTimeMillis();

        if (T==0) {
            if (id6) {
                T = id13;
            } else {
                T = scanner.nextInt();
            }
        }
        String[] results = new String[T+1];
        for (int test = 0; test < T; test++) {
            Solver solver = new Solver(){
                @Override
                public void callback() {
                    results[testNo] = answer;
                }
            };
            solver.testNo = test+1;
            if (id6) {
                solver.readFakeInput();
            }else{
                solver.readInput();
            }
            solver.solveWrapped();
        }

        long timeEnd = System.currentTimeMillis();
        if (isInputFromFile())
            System.out.println("All tasks are solved! Elapsed time "+(timeEnd-timeStart)/1000.0+" sec.");

        

        for (int i = 1; i <= T; i++) {
            if (eventType == EventType.GOOGLE_CODE_JAM){
                out.printf("Case 
            }else {
                out.print(results[i]);
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
        int testNo;
        String answer = null;

        public void callback(){};

        private ByteArrayOutputStream baos = new ByteArrayOutputStream();
        protected PrintStream outLocal = new PrintStream(baos);

        public abstract void readInput() throws IOException;

        

        public void readFakeInput() throws  IOException{
            throw new RuntimeException("not implemented");
        }

        protected abstract void solve() throws IOException;

        protected void solveWrapped() throws IOException {

            if (isInputFromFile())
                System.out.println("SOLVER: solving task 

            solve();
            outLocal.close();
            answer = baos.toString();
            if (isInputFromFile()) {
                System.out.println("\t"+answer);
            }
            callback();
        }

    }

    


    





































    public static class MultiSet<T>{
        private Map<T, Integer> m = new HashMap<>();

        public void add(T x){
            Integer y = m.get(x);
            if (y == null)
                y = 0;
            m.put(x, y + 1);
        }

        public boolean remove(T x){
            Integer y = m.get(x);
            if (y != null){
                if (y > 1) {
                    m.put(x, y - 1);
                }else{
                    m.remove(x);
                }
                return true;
            }
            return false;
        }

        public boolean removeAll(T x){
            return m.remove(x)!=null;
        }

        public boolean contains(T x){
            return m.containsKey(x);
        }

        public int getCount(T x){
            Integer y = m.get(x);
            return y==null? 0 : y;
        }
    }

    
    public static List<Integer> id11(int limit) {
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
        List<Integer> id1 = new ArrayList<>();
        for(int i=2; i<=limit; i++){
            if (primes[i]){
                id1.add(i);
            }
        }
        return id1;
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

    
    static class id0 implements Cloneable{
        int[] rank;
        int[] parent;

        protected id0 clone(){
            id0 cloned = new id0(parent.length);
            for(int i=0; i<parent.length; i++){
                cloned.parent[i] = parent[i];
                cloned.rank[i] = rank[i];
            }
            return cloned;
        }

        public id0(int n) {
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

        
        public void union(id0 set2){
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

        

        public int id15(){
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

    

    

    

    final int BUF_SIZE = 1024 * 1024 * 8;

    final int id18 = 1024 * 1024 * 8 ; 

    final int id9 = 1024;

    final int id14 = 1024;

    boolean id25 = true;
    String outSuffix = ".out";

    static PrintStream out;
    static ByteScanner scanner;
    static ByteWriter writer;

    public void run() {
        try{
            InputStream bis = null;
            OutputStream bos = null;
            if (inputFilename !=null){
                File inputFile = null;
                File outputFile = null;
                if (id25) {
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
                        id18);
                bos = new BufferedOutputStream(new FileOutputStream(outputFile));
                out = new PrintStream(bos);
            }else{
                bis = new BufferedInputStream(System.in, id18);
                bos = new BufferedOutputStream(System.out);
                out = new PrintStream(bos);
            }
            scanner = new ByteScanner(bis, id9, BUF_SIZE);
            writer = new ByteWriter(bos, id14);

            solveAll();
            out.flush();
        }catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public interface Constants{
        byte ZERO = '0';

        byte NINE = '9';
        byte SPACEBAR = ' '; 

        byte MINUS = '-'; 


        char FLOAT_POINT = '.';
    }

    public static class id2 extends IOException{
    }

    public static class ByteWriter implements Constants {

        int bufSize = 1024;
        byte[] byteBuf = new byte[bufSize];
        OutputStream os;

        public ByteWriter(OutputStream os, int bufSize){
            this.os = os;
            this.bufSize = bufSize;
        }

        public void writeInt(int num) throws IOException{
            int id4 = byteBuf.length;
            if (num==0){
                byteBuf[--id4] = ZERO;
            }else{
                int numAbs = Math.abs(num);
                while (numAbs>0){
                    byteBuf[--id4] = (byte)((numAbs % 10) + ZERO);
                    numAbs /= 10;
                }
                if (num<0)
                    byteBuf[--id4] = MINUS;
            }
            os.write(byteBuf, id4, byteBuf.length - id4);
        }

        
        public void id20(byte[] ar) throws IOException{
            for (int i = 0; i < ar.length; i++) {
                byteBuf[i] = ar[i];
            }
            os.write(byteBuf,0,ar.length);
        }

        public void id3() throws IOException{
            byteBuf[0] = SPACEBAR;
            os.write(byteBuf,0,1);
        }
    }


    public static class id21{
        private byte[] buf;
        private int pos = 0;

        public id21() {
            buf = new byte[256];
        }

        public byte[] getBytes(){
            return buf;
        }

        public int size(){
            return pos;
        }

        public void write(byte[] array, int from, int to){
            int lenAdd = to - from;
            int bufLen = buf.length;
            while (pos + lenAdd > bufLen){
                bufLen *= 2;
            }
            if (bufLen > buf.length){
                buf = Arrays.copyOf(buf, bufLen);
            }
            System.arraycopy(array,from,buf,pos,lenAdd);
            pos += lenAdd;
        }
    }

    public static class ByteScanner implements Constants{

        private InputStream is;

        private int id5;
        private int bufSize;

        byte[] id22;
        byte by=-1;
        int byteRead=-1;
        int bytePos=-1;

        byte[] byteBuf;
        int totalBytes;

        boolean id16 = false;

        public ByteScanner(InputStream is, int id5, int bufSize){
            this.is = is;
            this.id5 = id5;
            this.bufSize = bufSize;

            id22 = new byte[this.id5];
            byteBuf = new byte[this.bufSize];
        }

        public ByteScanner(byte[] data){
            id22 = data;
            id5 = data.length;
            bufSize = data.length;
            byteBuf = new byte[bufSize];
            byteRead = data.length;
            bytePos = 0;
        }

        private byte nextByte() throws IOException{
            if (bytePos<0 || bytePos>=byteRead){
                byteRead = is==null? -1: is.read(id22);
                bytePos=0;
                if (byteRead<0){
                    id22[bytePos]=0;

                    if (id16)
                        throw new id2();
                    id16 = true;
                }
            }
            return id22[bytePos++];
        }

        private void readToken(byte acceptFrom) throws IOException {
            if (id26){
                id26 = false;
                return;
            }
            totalBytes = 0;
            if (id16)
                return;
            while ((by=nextByte())<acceptFrom);
            do{
                byteBuf[totalBytes++] = by;
            }while ((by=nextByte())>=acceptFrom);
        }

        boolean id26 = false;

        public boolean id7() throws IOException{
            if (!id26) {
                try{
                    readToken();
                    id26 = true;
                }catch (id2 e){
                    return false;
                }
            }
            return totalBytes>0;
        }

        
        public String nextLine() throws IOException {
            if (id26){
                throw new RuntimeException("error logic");
            }
            readToken((byte)0x20);
            return new String(byteBuf,0,totalBytes);
        }

        
        public String nextToken() throws IOException {
            readToken();
            return new String(byteBuf,0,totalBytes);
        }

        
        private void readToken() throws IOException {
            readToken((byte)0x21);
        }

        public int nextInt() throws IOException{
            readToken();
            int num=0, i=0;
            boolean sign=false;
            if (byteBuf[i]==MINUS){
                sign = true;
                i++;
            }
            for (; i<totalBytes; i++){
                num*=10;
                num+=byteBuf[i]-ZERO;
            }
            return sign?-num:num;
        }

        public long nextLong() throws IOException{
            readToken();
            long num=0;
            int i=0;
            boolean sign=false;
            if (byteBuf[i]==MINUS){
                sign = true;
                i++;
            }
            for (; i<totalBytes; i++){
                num*=10;
                num+=byteBuf[i]-ZERO;
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

        public int[] id24(int size) throws IOException{
            int[] a = new int[size];
            for (int i = 0; i < a.length; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public long[] id17(int size) throws IOException{
            long[] a = new long[size];
            for (int i = 0; i < a.length; i++) {
                a[i] = nextLong();
            }
            return a;
        }

        
        public byte nextChar() throws IOException{
            while ((by=nextByte())<=0x20);
            return by;
        }

        
        public byte id12() throws IOException{
            while ((by=nextByte())<0x20);
            return by;
        }

        public byte[] id8() throws IOException {
            readToken((byte)0x20);
            byte[] out = new byte[totalBytes];
            System.arraycopy(byteBuf, 0, out, 0, totalBytes);
            return out;
        }
    }

    public static void main(String[] args) {
        new id19().run();
    }
}