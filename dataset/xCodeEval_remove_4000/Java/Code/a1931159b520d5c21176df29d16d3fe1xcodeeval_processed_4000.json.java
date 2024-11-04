import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;


public class id3 implements Runnable {

    static EventType eventType = EventType.DEFAULT;



    

    

    static int T = 1;

    







    static String inputFilename = null;


    

    static boolean id7 = false;
    

    static int id12 = 1;


    














    public static class Solver extends  SolverAbstract{
        int N;
        int[] A;
        byte[] T;

        int sumComponent;

        List<Integer> listAnswer = new ArrayList<>();

        @Override
        public void readInput() throws IOException {
            N = scanner.nextInt(); 

            A = new int[N];
            T = new byte[N];
            for (int i = 0; i < N; i++) {
                A[i] = scanner.nextInt(); 

                T[i] = (byte)scanner.nextInt(); 

            }
        }

        List<Integer>[] children;
        int[] sumChildren;

        @Override
        protected String solve() throws IOException {
            sumChildren = new int[N];
            children = new List[N];
            for (int i = 0; i < N; i++) {
                children[i] = new ArrayList<>();
            }
            int root = -1;
            for (int i = 0; i < N; i++) {
                if (A[i]>0) {
                    children[A[i]-1].add(i);
                }else{
                    root = i;
                }
            }
            int totalT = 0;
            for(byte x : T){
                totalT += x;
            }
            if (totalT % 3 != 0){
                return "-1";
            }
            sumComponent = totalT / 3;


            

            int[] stack = new int[N*2];
            int iStack = 0;
            stack[iStack++] = root;
            stack[iStack++] = 0;
            while(true){
                int childIdx = stack[iStack-1];
                int node = stack[iStack-2];
                if (childIdx < children[node].size()){
                    stack[iStack++] = children[node].get(childIdx);
                    stack[iStack++] = 0;
                }else{
                    dfs_post(node);

                    iStack-=2;
                    if (iStack==0){
                        break;
                    }
                    stack[iStack-1]++;
                }
            }

            if (listAnswer.size() < 2){
                return "-1";
            }
            return (listAnswer.get(0)+1) + " " + (listAnswer.get(1)+1);
        }

        private void dfs(int node){
            for(int child : children[node]){
                dfs(child);
            }
            dfs_post(node);
        }

        private void dfs_post(int node){
            boolean cutPossible = false;
            if (A[node]>0 && sumChildren[node] + T[node] == sumComponent){
                cutPossible = true;
                if (listAnswer.size() < 4) {
                    listAnswer.add(node);
                }
            }
            if (A[node] > 0 && !cutPossible) {
                sumChildren[A[node]-1] += sumChildren[node] + T[node];
            }
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
            if (id7) {
                T = id12;
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
            if (id7) {
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

    


    





































    
    public static List<Integer> id10(int limit) {
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

        

        public int id14(){
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

    

    

    

    final int BUF_SIZE = 1024 * 1024 * 1;

    final int id17 = 1024 * 1024 * 1 ;
    final int id9 = 1024;

    final int id13 = 1024;

    boolean id21 = true;
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
                if (id21) {
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
                        id17);
                bos = new BufferedOutputStream(new FileOutputStream(outputFile));
                out = new PrintStream(bos);
            }else{
                bis = new BufferedInputStream(System.in, id17);
                bos = new BufferedOutputStream(System.out);
                out = new PrintStream(bos);
            }
            scanner = new ByteScanner(bis, id9, BUF_SIZE);
            writer = new ByteWriter(bos, id13);

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

        
        public void id18(byte[] ar) throws IOException{
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

        public ByteScanner(InputStream is, int id6, int bufSize){
            this.is = is;
            this.id6 = id6;
            this.bufSize = bufSize;

            id19 = new byte[this.id6];
            byteBuf = new byte[this.bufSize];
        }

        public ByteScanner(byte[] data){
            id19 = data;
            id6 = data.length;
            bufSize = data.length;
            byteBuf = new byte[bufSize];
            byteRead = data.length;
            bytePos = 0;
        }

        private int id6;
        private int bufSize;

        byte[] id19;
        byte by=-1;
        int byteRead=-1;
        int bytePos=-1;

        byte[] byteBuf;
        int totalBytes;

        boolean id15 = false;

        private byte nextByte() throws IOException{

            if (bytePos<0 || bytePos>=byteRead){
                byteRead = is==null? -1: is.read(id19);
                bytePos=0;
                if (byteRead<0){
                    id19[bytePos]=-1;

                    if (id15)
                        throw new id2();
                    id15 = true;
                }
            }
            return id19[bytePos++];
        }

        
        public byte nextChar() throws IOException{
            while ((by=nextByte())<=0x20);
            return by;
        }

        
        public byte id11() throws IOException{
            while ((by=nextByte())<0x20);
            return by;
        }

        
        public String nextLine() throws IOException {
            readToken((byte)0x20);
            return new String(byteBuf,0,totalBytes);
        }

        public byte[] id8() throws IOException {
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

        public int[] id20(int size) throws IOException{
            int[] a = new int[size];
            for (int i = 0; i < a.length; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        public long[] id16(int size) throws IOException{
            long[] a = new long[size];
            for (int i = 0; i < a.length; i++) {
                a[i] = nextLong();
            }
            return a;
        }
    }

    public static void main(String[] args) {
        new id3().run();
    }
}