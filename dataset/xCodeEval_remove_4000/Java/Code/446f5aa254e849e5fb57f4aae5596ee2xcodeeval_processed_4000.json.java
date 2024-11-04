import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;


public class id24 implements Runnable {

    static EventType eventType = EventType.DEFAULT;



    

    

    static int T = 1;

    







    static String inputFilename = null;


    

    static boolean id8 = false;
    

    static int id14 = 1;


    



    public static class Solver extends  SolverAbstract{

        long tS, tF, t;
        int N;
        long[] A;

        @Override
        public void readInput() throws IOException {
            tS = scanner.nextLong();
            tF = scanner.nextLong(); 

            t = scanner.nextLong();
            N = scanner.nextInt(); 

            A = scanner.id19(N);
        }

        @Override
        protected String solve() throws IOException {
            if (N==0){
                return ""+tS;
            }
            if (A[0] > tS){
                return ""+tS;
            }

            boolean[] id3 = new boolean[N];
            long[] S = new long[N];
            S[0] = Math.max(tS, A[0]);
            id3[0] = A[0] > 0;
            for (int i = 1; i < N; i++) {
                S[i] = Math.max(S[i-1] + t, A[i]);
                id3[i] = A[i] != A[i-1];
            }

            long bestWait = Long.MAX_VALUE / 4;
            long id11 = -1;
            for(int i=0; i<N; i++){
                if (id3[i]){
                    long id6 = A[i]-1;
                    long id22 = i==0? tS: S[i-1] + t;
                    long myWait;
                    if (id22 + t <= tF){
                        if (id6 < id22){
                            myWait = id22 - id6;
                        }else{
                            myWait = 0;
                        }
                        if (myWait < bestWait){
                            bestWait = myWait;
                            id11 = Math.min(id6, id22);
                        }
                        

                    }
                }
            }
            {

                long id17 = S[N-1] + t;
                if (id17 + t <= tF){
                    return "" + id17; 

                }
            }
            return "" + id11;
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
            if (id8) {
                T = id14;
            } else {
                T = scanner.nextInt();
            }
        }
        final String[] results = new String[T+1];
        for (int test = 0; test < T; test++) {
            Solver solver = new Solver(){
                @Override
                public void callback() {
                    results[testNo] = answer;
                }
            };
            solver.testNo = test+1;
            if (id8) {
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
                out.println(results[i]);
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

        public abstract void readInput() throws IOException;

        

        public void readFakeInput() throws  IOException{
            throw new RuntimeException("not implemented");
        }

        protected abstract String solve() throws IOException;

        protected void solveWrapped() throws IOException {

            if (isInputFromFile())
                System.out.println("SOLVER: solving task 

            answer = solve();


            if (isInputFromFile()) {
                System.out.println("\t"+answer);
            }
            callback();
        }

    }

    


    





































    
    public static List<Integer> id12(int limit) {
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

        

        public int id16(){
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

    final int id20 = 1024 * 1024 * 8 ;
    final int id10 = 1024;

    final int id15 = 1024;

    boolean id26 = true;
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
                if (id26) {
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
                        id20);
                bos = new BufferedOutputStream(new FileOutputStream(outputFile));
                out = new PrintStream(bos);
            }else{
                bis = new BufferedInputStream(System.in, id20);
                bos = new BufferedOutputStream(System.out);
                out = new PrintStream(bos);
            }
            scanner = new ByteScanner(bis, id10, BUF_SIZE);
            writer = new ByteWriter(bos, id15);

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
            int id5 = byteBuf.length;
            if (num==0){
                byteBuf[--id5] = ZERO;
            }else{
                int numAbs = Math.abs(num);
                while (numAbs>0){
                    byteBuf[--id5] = (byte)((numAbs % 10) + ZERO);
                    numAbs /= 10;
                }
                if (num<0)
                    byteBuf[--id5] = MINUS;
            }
            os.write(byteBuf, id5, byteBuf.length - id5);
        }

        
        public void id21(byte[] ar) throws IOException{
            for (int i = 0; i < ar.length; i++) {
                byteBuf[i] = ar[i];
            }
            os.write(byteBuf,0,ar.length);
        }

        public void id4() throws IOException{
            byteBuf[0] = SPACEBAR;
            os.write(byteBuf,0,1);
        }

    }

    public static class ByteScanner implements Constants{

        InputStream is;

        public ByteScanner(InputStream is, int id7, int bufSize){
            this.is = is;
            this.id7 = id7;
            this.bufSize = bufSize;

            id23 = new byte[this.id7];
            byteBuf = new byte[this.bufSize];
        }

        public ByteScanner(byte[] data){
            id23 = data;
            id7 = data.length;
            bufSize = data.length;
            byteBuf = new byte[bufSize];
            byteRead = data.length;
            bytePos = 0;
        }

        private int id7;
        private int bufSize;

        byte[] id23;
        byte by=-1;
        int byteRead=-1;
        int bytePos=-1;

        byte[] byteBuf;
        int totalBytes;

        boolean id18 = false;

        private byte nextByte() throws IOException{

            if (bytePos<0 || bytePos>=byteRead){
                byteRead = is==null? -1: is.read(id23);
                bytePos=0;
                if (byteRead<0){
                    id23[bytePos]=-1;

                    if (id18)
                        throw new id2();
                    id18 = true;
                }
            }
            return id23[bytePos++];
        }

        
        public byte nextChar() throws IOException{
            while ((by=nextByte())<=0x20);
            return by;
        }

        
        public byte id13() throws IOException{
            while ((by=nextByte())<0x20);
            return by;
        }

        
        public String nextLine() throws IOException {
            readToken((byte)0x20);
            return new String(byteBuf,0,totalBytes);
        }

        public byte[] id9() throws IOException {
            readToken((byte)0x20);
            byte[] out = new byte[totalBytes];
            System.arraycopy(byteBuf, 0, out, 0, totalBytes);
            return out;
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

        public int[] id25(int size) throws IOException{
            int[] a = new int[size];
            for (int i = 0; i < a.length; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public long[] id19(int size) throws IOException{
            long[] a = new long[size];
            for (int i = 0; i < a.length; i++) {
                a[i] = nextLong();
            }
            return a;
        }
    }

    public static void main(String[] args) {
        new id24().run();
    }
}