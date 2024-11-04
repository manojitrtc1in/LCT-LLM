import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static final String NON_CHARACTER = "[^a-zA-Z]+";
    static final double EPS = 1e-9;
    static final int[] BOX_X = {0,-1,1,0}; 

    static final int[] BOX_Y = {-1,0,0,1}; 

    static InputReader reader;
    static OutputWriter writer;

    public static void main(String[] args)  {
        reader = new InputReader(System.in);
        writer = new OutputWriter(System.out);

        int n = reader.nextInt();
        int[] b = new int[n];
        for(int i=0;i<n;i++){
            b[i] = reader.nextInt();
        }
        long count = Math.abs(b[0]);
        for(int i=1;i<n;i++){
            if(b[i] != b[i-1]){
                count += Math.abs(b[i] - b[i-1]);
            }
        }
        writer.println(count);
        writer.flush();
    }
    static class Point implements Comparable<Point>{
        int x; int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            if(x == o.x){
                return y - o.y;
            }else{
                return x - o.x;
            }
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    return null;
                }
            }
            return tokenizer.nextToken();
        }
        public char nextChar(){
            try {
                char c = '\0';
                while(c == '\0' || c == '\n' || c == '\r')
                    c = (char) reader.read();
                return c;
            }catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public String nextLine(){
            if(tokenizer != null && tokenizer.hasMoreTokens()){
                StringBuilder sb = new StringBuilder(tokenizer.nextToken());
                while(tokenizer.hasMoreTokens()){
                    sb.append(" ").append(tokenizer.nextToken());
                }
                return sb.toString();
            }else{
                try {
                    return reader.readLine();
                }catch(Exception e){
                    return null;
                }
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    static class OutputWriter {
        public BufferedWriter writer;
        OutputWriter(OutputStream stream) {
            writer = new BufferedWriter(new OutputStreamWriter(stream));
        }
        public void print(String string){
            try {
                writer.write(string, 0, string.length());
            }catch(Exception e){e.printStackTrace();}
        }
        public void print(char c){
            try {
                writer.write(c);
            }catch(Exception e){e.printStackTrace();}
        }
        public void print(String format, Object... args) {
            try {
                String string = String.format(format, args);
                writer.write(string, 0, string.length());
            }catch(Exception e){e.printStackTrace();}
        }
        public void print(int x){
            try {
                String string = String.format("%d", x);
                writer.write(string, 0, string.length());
            }catch(Exception e){e.printStackTrace();}
        }
        public void print(double x){
            try {
                int x_int = (int) (x * 100 + 1e-6); 

                String string = String.format("%d.%02d", x_int/100, x_int%100);
                writer.write(string, 0, string.length());
            }catch(Exception e){e.printStackTrace();}
        }
        public void print(long x){
            try {
                String string = String.format("%d", x);
                writer.write(string, 0, string.length());
            }catch(Exception e){e.printStackTrace();}
        }
        public void println(String string){
            print(string);
            newline();
        }
        public void println(char c){
            print(c);
            newline();
        }
        public void println(String format, Object... args) {
            print(format, args);
            newline();
        }
        public void println(int x){
            print(x);
            newline();
        }
        public void println(long x){
            print(x);
            newline();
        }
        public void println(double x){
            print(x);
            newline();
        }
        public void println(){
            newline();
        }

        private void newline() {
            try {
                writer.newLine();
            }catch(Exception e){e.printStackTrace();}
        }
        private void flush(){
            try {
                writer.flush();
            }catch(Exception e){e.printStackTrace();}
        }
    }

    static class BitBoolean{
        final static int SIZE = 31;
        int[] bits;

        public BitBoolean(int size) {
            bits = new int[size/SIZE + 1];
        }

        public boolean equals(BitBoolean b){
            if (bits.length != b.bits.length)   return false;
            for (int i=0;i<bits.length;i++){
                if (bits[i] != b.bits[i])   return false;
            }
            return true;
        }

        public int set(int i, boolean b){
            return b ? setTrue(i) : setFalse(i);
        }
        public int setTrue(int i){
            return bits[i/SIZE] = BitBoolean.setBit(bits[i / SIZE], i % SIZE);
        }
        public int setFalse(int i){
            return bits[i/SIZE] = BitBoolean.clearBit(bits[i / SIZE], i % SIZE);
        }
        public boolean isTrue(int i){
            return BitBoolean.isOn(bits[i / SIZE], i%SIZE) > 0;
        }
        public int toggle(int i){
            return bits[i/SIZE] = BitBoolean.toggleBit(bits[i / SIZE], i % SIZE);
        }
        public void allTrue(){
            for (int i=0;i<bits.length;i++){
                bits[i] = BitBoolean.setAll(SIZE);
            }
        }
        public void allFalse(){
            for (int i=0;i<bits.length;i++){
                bits[i] = 0;
            }
        }

        static int setBit(int S, int j) { return S | (1 << j); }

        static int isOn(int S, int j) { return S & (1 << j); }

        static int clearBit(int S, int j) { return S & ~(1 << j); }

        static int toggleBit(int S, int j) { return S ^ (1 << j); }

        static int lowBit(int S) { return S & (-S); }

        static int setAll(int n) { return (1 << n) - 1; }

        static int modulo(int S, int N) { return ((S) & (N - 1)); } 


        static int isPowerOfTwo(int S) { return (S & (S - 1)) == 0 ? 1 : 0; }

        static int nearestPowerOfTwo(int S) { return ((int)Math.pow(2.0, (int)((Math.log((double)S) / Math.log(2.0)) + 0.5))); }

        static int turnOffLastBit(int S) { return ((S) & (S - 1)); }

        static int turnOnLastZero(int S) { return ((S) | (S + 1)); }

        static int turnOffLastConsecutiveBits(int S) { return ((S) & (S + 1)); }

        static int turnOnLastConsecutiveZeroes(int S) { return ((S) | (S - 1)); }

        static void printSet(int vS) {             

            System.out.printf("S = %2d = ", vS);
            Stack<Integer> st = new Stack<Integer>();
            while (vS > 0) {
                st.push(vS % 2);
                vS /= 2;
            }
            while (!st.empty()) {                          

                System.out.printf("%d", st.peek());
                st.pop();
            }
            System.out.printf("\n");
        }
    }

    

    

    private static void printPermutations( Comparable[] c ) {
        System.out.println( Arrays.toString( c ) );
        while ( ( c = nextPermutation( c ) ) != null ) {
            System.out.println( Arrays.toString( c ) );
        }
    }

    

    private static Comparable[] nextPermutation( final Comparable[] c ) {
        

        int first = getFirst( c );
        if ( first == -1 ) return null; 

        

        int toSwap = c.length - 1;
        while ( c[ first ].compareTo( c[ toSwap ] ) >= 0 )
            --toSwap;
        

        swap( c, first++, toSwap );
        

        toSwap = c.length - 1;
        while ( first < toSwap )
            swap( c, first++, toSwap-- );
        return c;
    }

    

    

    private static int getFirst( final Comparable[] c ) {
        for ( int i = c.length - 2; i >= 0; --i )
            if ( c[ i ].compareTo( c[ i + 1 ] ) < 0 )
                return i;
        return -1;
    }

    

    private static void swap( final Comparable[] c, final int i, final int j ) {
        final Comparable tmp = c[ i ];
        c[ i ] = c[ j ];
        c[ j ] = tmp;
    }

    private static int length(long num){
        int count = 0;
        while(num > 0){
            count ++;
            num /= 10;
        }
        return count;
    }
    private static int length(int num){
        int count = 0;
        while(num > 0){
            count ++;
            num /= 10;
        }
        return count;
    }

    static abstract class Combination<T>{
        T[] array, a;
        int size, n;

        @SuppressWarnings("unchecked")
        public Combination(Class<T> c, T[] array, int size, int n) {
            this.array = array;
            this.size = size;
            this.n = n;
            a = (T[]) Array.newInstance(c, n);
        }
        public void generate(){
            g(array, a, 0, 0, n);
        }
        private void g(T[] set, T[] a, int i, int j, int n){
            if (i == n){
                solve(a);
                return;
            } else if(set.length - j < n - i){
                return;
            } else {
                for (int p = j; p < set.length; p++) {
                    a[i] = set[p];
                    g(set, a, i + 1, p + 1, n);
                }
            }
        }
        public abstract void solve(T[] a);
    }
    

















































































































































    public static class SuffixArray {
        private Suffix[] suffixes;

        
        public SuffixArray(String text) {
            int N = text.length();
            this.suffixes = new Suffix[N];
            for (int i = 0; i < N; i++)
                suffixes[i] = new Suffix(text, i);
            Arrays.sort(suffixes);
        }

        private static class Suffix implements Comparable<Suffix> {
            private final String text;
            private final int index;

            private Suffix(String text, int index) {
                this.text = text;
                this.index = index;
            }
            private int length() {
                return text.length() - index;
            }
            private char charAt(int i) {
                return text.charAt(index + i);
            }

            public int compareTo(Suffix that) {
                if (this == that) return 0;  

                int N = Math.min(this.length(), that.length());
                for (int i = 0; i < N; i++) {
                    if (this.charAt(i) < that.charAt(i)) return -1;
                    if (this.charAt(i) > that.charAt(i)) return +1;
                }
                return this.length() - that.length();
            }

            public String toString() {
                return text.substring(index);
            }
        }

        
        public int length() {
            return suffixes.length;
        }


        
        public int index(int i) {
            if (i < 0 || i >= suffixes.length) throw new IndexOutOfBoundsException();
            return suffixes[i].index;
        }


        
        public int lcp(int i) {
            if (i < 1 || i >= suffixes.length) throw new IndexOutOfBoundsException();
            return lcp(suffixes[i], suffixes[i-1]);
        }

        

        private static int lcp(Suffix s, Suffix t) {
            int N = Math.min(s.length(), t.length());
            for (int i = 0; i < N; i++) {
                if (s.charAt(i) != t.charAt(i)) return i;
            }
            return N;
        }

        
        public String select(int i) {
            if (i < 0 || i >= suffixes.length) throw new IndexOutOfBoundsException();
            return suffixes[i].toString();
        }

        
        public int rank(String query) {
            int lo = 0, hi = suffixes.length - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                int cmp = compare(query, suffixes[mid]);
                if (cmp < 0) hi = mid - 1;
                else if (cmp > 0) lo = mid + 1;
                else return mid;
            }
            return lo;
        }

        

        private static int compare(String query, Suffix suffix) {
            int N = Math.min(query.length(), suffix.length());
            for (int i = 0; i < N; i++) {
                if (query.charAt(i) < suffix.charAt(i)) return -1;
                if (query.charAt(i) > suffix.charAt(i)) return +1;
            }
            return query.length() - suffix.length();
        }
    }
}
