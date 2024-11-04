import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.List;

public class id15 {
    static class InputReader {

        
        private static final int id20 = 1 << 16; 


        
        private static final InputStream DEFAULT_STREAM = System.in;

        
        private static final int id25 = 21;

        

        private int c;

        

        private byte[] buf;
        private int bufferSize, bufIndex, id31;

        private InputStream stream;

        

        private static final byte EOF = -1;

        

        private static final byte NEW_LINE = 10;

        

        private static final byte id8 = 13;

        

        private static final byte SPACE = 32;

        

        private static final byte DASH = 45;

        

        private static final byte DOT = 46;

        

        private char[] charBuffer;

        

        private static byte[] bytes = new byte[58];
        private static int[] ints = new int[58];
        private static char[] chars = new char[128];

        static {
            char ch = ' ';
            int value = 0;
            byte _byte = 0;
            for (int i = 48; i < 58; i++) bytes[i] = _byte++;
            for (int i = 48; i < 58; i++) ints[i] = value++;
            for (int i = 32; i < 128; i++) chars[i] = ch++;
        }

        

        private static final double[][] doubles = {
                {0.0d, 0.00d, 0.000d, 0.0000d, 0.00000d, 0.000000d, 0.0000000d, 0.00000000d, 0.000000000d, 0.0000000000d, 0.00000000000d, 0.000000000000d, 0.0000000000000d, 0.00000000000000d, 0.000000000000000d, 0.0000000000000000d, 0.00000000000000000d, 0.000000000000000000d, 0.0000000000000000000d, 0.00000000000000000000d, 0.000000000000000000000d},
                {0.1d, 0.01d, 0.001d, 0.0001d, 0.00001d, 0.000001d, 0.0000001d, 0.00000001d, 0.000000001d, 0.0000000001d, 0.00000000001d, 0.000000000001d, 0.0000000000001d, 0.00000000000001d, 0.000000000000001d, 0.0000000000000001d, 0.00000000000000001d, 0.000000000000000001d, 0.0000000000000000001d, 0.00000000000000000001d, 0.000000000000000000001d},
                {0.2d, 0.02d, 0.002d, 0.0002d, 0.00002d, 0.000002d, 0.0000002d, 0.00000002d, 0.000000002d, 0.0000000002d, 0.00000000002d, 0.000000000002d, 0.0000000000002d, 0.00000000000002d, 0.000000000000002d, 0.0000000000000002d, 0.00000000000000002d, 0.000000000000000002d, 0.0000000000000000002d, 0.00000000000000000002d, 0.000000000000000000002d},
                {0.3d, 0.03d, 0.003d, 0.0003d, 0.00003d, 0.000003d, 0.0000003d, 0.00000003d, 0.000000003d, 0.0000000003d, 0.00000000003d, 0.000000000003d, 0.0000000000003d, 0.00000000000003d, 0.000000000000003d, 0.0000000000000003d, 0.00000000000000003d, 0.000000000000000003d, 0.0000000000000000003d, 0.00000000000000000003d, 0.000000000000000000003d},
                {0.4d, 0.04d, 0.004d, 0.0004d, 0.00004d, 0.000004d, 0.0000004d, 0.00000004d, 0.000000004d, 0.0000000004d, 0.00000000004d, 0.000000000004d, 0.0000000000004d, 0.00000000000004d, 0.000000000000004d, 0.0000000000000004d, 0.00000000000000004d, 0.000000000000000004d, 0.0000000000000000004d, 0.00000000000000000004d, 0.000000000000000000004d},
                {0.5d, 0.05d, 0.005d, 0.0005d, 0.00005d, 0.000005d, 0.0000005d, 0.00000005d, 0.000000005d, 0.0000000005d, 0.00000000005d, 0.000000000005d, 0.0000000000005d, 0.00000000000005d, 0.000000000000005d, 0.0000000000000005d, 0.00000000000000005d, 0.000000000000000005d, 0.0000000000000000005d, 0.00000000000000000005d, 0.000000000000000000005d},
                {0.6d, 0.06d, 0.006d, 0.0006d, 0.00006d, 0.000006d, 0.0000006d, 0.00000006d, 0.000000006d, 0.0000000006d, 0.00000000006d, 0.000000000006d, 0.0000000000006d, 0.00000000000006d, 0.000000000000006d, 0.0000000000000006d, 0.00000000000000006d, 0.000000000000000006d, 0.0000000000000000006d, 0.00000000000000000006d, 0.000000000000000000006d},
                {0.7d, 0.07d, 0.007d, 0.0007d, 0.00007d, 0.000007d, 0.0000007d, 0.00000007d, 0.000000007d, 0.0000000007d, 0.00000000007d, 0.000000000007d, 0.0000000000007d, 0.00000000000007d, 0.000000000000007d, 0.0000000000000007d, 0.00000000000000007d, 0.000000000000000007d, 0.0000000000000000007d, 0.00000000000000000007d, 0.000000000000000000007d},
                {0.8d, 0.08d, 0.008d, 0.0008d, 0.00008d, 0.000008d, 0.0000008d, 0.00000008d, 0.000000008d, 0.0000000008d, 0.00000000008d, 0.000000000008d, 0.0000000000008d, 0.00000000000008d, 0.000000000000008d, 0.0000000000000008d, 0.00000000000000008d, 0.000000000000000008d, 0.0000000000000000008d, 0.00000000000000000008d, 0.000000000000000000008d},
                {0.9d, 0.09d, 0.009d, 0.0009d, 0.00009d, 0.000009d, 0.0000009d, 0.00000009d, 0.000000009d, 0.0000000009d, 0.00000000009d, 0.000000000009d, 0.0000000000009d, 0.00000000000009d, 0.000000000000009d, 0.0000000000000009d, 0.00000000000000009d, 0.000000000000000009d, 0.0000000000000000009d, 0.00000000000000000009d, 0.000000000000000000009d}
        };

        
        public InputReader() {
            this(DEFAULT_STREAM, id20);
        }

        
        public InputReader(int bufferSize) {
            this(DEFAULT_STREAM, bufferSize);
        }

        
        public InputReader(InputStream stream) {
            this(stream, id20);
        }

        
        public InputReader(InputStream stream, int bufferSize) {
            if (stream == null || bufferSize <= 0)
                throw new IllegalArgumentException();
            buf = new byte[bufferSize];
            charBuffer = new char[128];
            this.bufferSize = bufferSize;
            this.stream = stream;
        }

        
        private byte read() throws IOException {

            if (id31 == EOF) throw new IOException();

            if (bufIndex >= id31) {
                bufIndex = 0;
                id31 = stream.read(buf);
                if (id31 == EOF)
                    return EOF;
            }

            return buf[bufIndex++];
        }

        
        private int id7(int token) throws IOException {

            if (id31 == EOF) return EOF;

            

            do {

                while (bufIndex < id31) {
                    if (buf[bufIndex] > token) return 0;
                    bufIndex++;
                }

                

                id31 = stream.read(buf);
                if (id31 == EOF) return EOF;
                bufIndex = 0;

            } while (true);

        }

        
        public byte nextByte() throws IOException {
            return (byte) nextInt();
        }

        
        public int nextInt() throws IOException {

            if (id7(DASH - 1) == EOF) throw new IOException();
            int sgn = 1, res = 0;

            c = buf[bufIndex];
            if (c == DASH) {
                sgn = -1;
                bufIndex++;
            }

            do {

                while (bufIndex < id31) {
                    if (buf[bufIndex] > SPACE) {
                        res = (res << 3) + (res << 1);
                        res += ints[buf[bufIndex++]];
                    } else {
                        bufIndex++;
                        return res * sgn;
                    }
                }

                

                id31 = stream.read(buf);
                if (id31 == EOF) return res * sgn;
                bufIndex = 0;

            } while (true);

        }

        
        public long nextLong() throws IOException {

            if (id7(DASH - 1) == EOF) throw new IOException();
            int sgn = 1;
            long res = 0L;
            c = buf[bufIndex];
            if (c == DASH) {
                sgn = -1;
                bufIndex++;
            }

            do {

                while (bufIndex < id31) {
                    if (buf[bufIndex] > SPACE) {
                        res = (res << 3) + (res << 1);
                        res += ints[buf[bufIndex++]];
                    } else {
                        bufIndex++;
                        return res * sgn;
                    }
                }

                

                id31 = stream.read(buf);
                if (id31 == EOF) return res * sgn;
                bufIndex = 0;

            } while (true);

        }

        
        private void id9() {
            char[] newBuffer = new char[charBuffer.length << 1];
            for (int i = 0; i < charBuffer.length; i++) newBuffer[i] = charBuffer[i];
            charBuffer = newBuffer;
        }

        
        public String nextLine() throws IOException {

            try {
                c = read();
            } catch (IOException e) {
                return null;
            }
            if (c == NEW_LINE) return ""; 

            if (c == EOF) return null; 


            int i = 0;
            charBuffer[i++] = (char) c;

            do {

                while (bufIndex < id31) {
                    if (buf[bufIndex] != NEW_LINE && buf[bufIndex] != id8) {
                        if (i == charBuffer.length) id9();
                        charBuffer[i++] = (char) buf[bufIndex++];
                    } else {
                        if(buf[bufIndex] == id8) bufIndex++;
                        bufIndex++;
                        return new String(charBuffer, 0, i);
                    }
                }

                

                id31 = stream.read(buf);
                if (id31 == EOF)
                    return new String(charBuffer, 0, i);
                bufIndex = 0;

            } while (true);

        }

        

        

        

        public String nextString() throws IOException {
            if (id31 == EOF) return null;
            if (id7(SPACE) == EOF) return null;

            for (int i = 0; ; ) {
                while (bufIndex < id31) {
                    if (buf[bufIndex] > SPACE) {
                        if (i == charBuffer.length) id9();
                        charBuffer[i++] = (char) buf[bufIndex++];
                    } else {
                        bufIndex++;
                        return new String(charBuffer, 0, i);
                    }
                }

                

                id31 = stream.read(buf);
                if (id31 == EOF) return new String(charBuffer, 0, i);
                bufIndex = 0;
            }
        }

        

        public double nextDouble() throws IOException {
            String doubleVal = nextString();
            if (doubleVal == null) throw new IOException();
            return Double.valueOf(doubleVal);
        }

        

        

        

        

        public double id3() throws IOException {
            c = read();
            int sgn = 1;
            while (c <= SPACE) c = read(); 

            if (c == DASH) {
                sgn = -1;
                c = read();
            }
            double res = 0.0;
            

            while (c > DOT) {
                res *= 10.0;
                res += ints[c];
                c = read();
            }
            if (c == DOT) {
                int i = 0;
                c = read();
                

                while (c > SPACE && i < id25) {
                    res += doubles[ints[c]][i++];
                    c = read();
                }
            }
            return res * sgn;
        }

        

        public byte[] id10(int n) throws IOException {
            byte[] ar = new byte[n];
            for (int i = 0; i < n; i++) ar[i] = nextByte();
            return ar;
        }

        

        public int[] id13(int n) throws IOException {
            int[] ar = new int[n];
            for (int i = 0; i < n; i++) ar[i] = nextInt();
            return ar;
        }

        

        public long[] id32(int n) throws IOException {
            long[] ar = new long[n];
            for (int i = 0; i < n; i++) ar[i] = nextLong();
            return ar;
        }

        

        public double[] id26(int n) throws IOException {
            double[] ar = new double[n];
            for (int i = 0; i < n; i++) ar[i] = nextDouble();
            return ar;
        }

        

        public double[] id16(int n) throws IOException {
            double[] ar = new double[n];
            for (int i = 0; i < n; i++) ar[i] = id3();
            return ar;
        }

        

        public String[] id27(int n) throws IOException {
            String[] ar = new String[n];
            for (int i = 0; i < n; i++) {
                String str = nextString();
                if (str == null) throw new IOException();
                ar[i] = str;
            }
            return ar;
        }

        

        public byte[] id19(int n) throws IOException {
            byte[] ar = new byte[n + 1];
            for (int i = 1; i <= n; i++) ar[i] = nextByte();
            return ar;
        }

        

        public int[] id1(int n) throws IOException {
            int[] ar = new int[n + 1];
            for (int i = 1; i <= n; i++) ar[i] = nextInt();
            return ar;
        }

        

        public long[] id30(int n) throws IOException {
            long[] ar = new long[n + 1];
            for (int i = 1; i <= n; i++) ar[i] = nextLong();
            return ar;
        }

        

        public double[] id4(int n) throws IOException {
            double[] ar = new double[n + 1];
            for (int i = 1; i <= n; i++) ar[i] = nextDouble();
            return ar;
        }

        

        public double[] id28(int n) throws IOException {
            double[] ar = new double[n + 1];
            for (int i = 1; i <= n; i++) ar[i] = id3();
            return ar;
        }

        

        public String[] id18(int n) throws IOException {
            String[] ar = new String[n + 1];
            for (int i = 1; i <= n; i++) ar[i] = nextString();
            return ar;
        }

        

        public byte[][] id23(int rows, int cols) throws IOException {
            byte[][] matrix = new byte[rows][cols];
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    matrix[i][j] = nextByte();
            return matrix;
        }

        

        public int[][] id0(int rows, int cols) throws IOException {
            int[][] matrix = new int[rows][cols];
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    matrix[i][j] = nextInt();
            return matrix;
        }

        

        public long[][] id11(int rows, int cols) throws IOException {
            long[][] matrix = new long[rows][cols];
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    matrix[i][j] = nextLong();
            return matrix;
        }

        

        public double[][] id24(int rows, int cols) throws IOException {
            double[][] matrix = new double[rows][cols];
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    matrix[i][j] = nextDouble();
            return matrix;
        }

        

        public double[][] id5(int rows, int cols) throws IOException {
            double[][] matrix = new double[rows][cols];
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    matrix[i][j] = id3();
            return matrix;
        }

        

        public String[][] id21(int rows, int cols) throws IOException {
            String[][] matrix = new String[rows][cols];
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    matrix[i][j] = nextString();
            return matrix;
        }

        

        public byte[][] id17(int rows, int cols) throws IOException {
            byte[][] matrix = new byte[rows + 1][cols + 1];
            for (int i = 1; i <= rows; i++)
                for (int j = 1; j <= cols; j++)
                    matrix[i][j] = nextByte();
            return matrix;
        }

        

        public int[][] id12(int rows, int cols) throws IOException {
            int[][] matrix = new int[rows + 1][cols + 1];
            for (int i = 1; i <= rows; i++)
                for (int j = 1; j <= cols; j++)
                    matrix[i][j] = nextInt();
            return matrix;
        }

        

        public long[][] id22(int rows, int cols) throws IOException {
            long[][] matrix = new long[rows + 1][cols + 1];
            for (int i = 1; i <= rows; i++)
                for (int j = 1; j <= cols; j++)
                    matrix[i][j] = nextLong();
            return matrix;
        }

        

        public double[][] id6(int rows, int cols) throws IOException {
            double[][] matrix = new double[rows + 1][cols + 1];
            for (int i = 1; i <= rows; i++)
                for (int j = 1; j <= cols; j++)
                    matrix[i][j] = nextDouble();
            return matrix;
        }

        

        public double[][] id14(int rows, int cols) throws IOException {
            double[][] matrix = new double[rows + 1][cols + 1];
            for (int i = 1; i <= rows; i++)
                for (int j = 1; j <= cols; j++)
                    matrix[i][j] = id3();
            return matrix;
        }

        

        public String[][] id29(int rows, int cols) throws IOException {
            String[][] matrix = new String[rows + 1][cols + 1];
            for (int i = 1; i <= rows; i++)
                for (int j = 1; j <= cols; j++)
                    matrix[i][j] = nextString();
            return matrix;
        }

        

        public void close() throws IOException {
            stream.close();
        }
    }

    

    static InputReader sc = new InputReader();
    static OutputStream outputStream = System.out;
    static PrintWriter w = new PrintWriter(outputStream);
    static int MOD = (int)1e9 + 7;
    static long timeStart;
    


    private static void id2()
            throws IOException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            try {
                w = new PrintWriter("output.txt");
                sc = new InputReader(new FileInputStream("input.txt"));
            } catch (Exception e) {
                throw new IOException();
            }
        }
    }

    public static void main(String[] args)
            throws IOException {

        id2();

        int t = sc.nextInt();
        while(t-->0) {
            solve();
        }

        w.close();

    }

    static void solve() throws IOException {
        int n = sc.nextInt();

        int[][] arr = sc.id0(2, n);

        List<Integer> l = new ArrayList<>();
        for(int i = 1; i <= n; i++) {
            l.add(i);
        }

        UnionFind<Integer> uf = new UnionFind<>(l);

        for(int i = 0; i < n; i++) {
            uf.unify(arr[0][i], arr[1][i]);
        }

        int comp = uf.components();

        w.println(BigInteger.valueOf(2).modPow(BigInteger.valueOf(comp), BigInteger.valueOf(MOD)));
    }

    


    static class UnionFind <T extends Comparable<T>> {

        

        private int size;

        

        private int[] sz;

        

        private int[] id;

        

        private int numComponents;

        

        private Hashtable<T, Integer> ht;

        

            

        public UnionFind(List<T> list) {
            ht = new Hashtable<>(list.size());

            for(int i = 0; i < list.size(); i++) {
                ht.put(list.get(i), i); 

                

            }

            this.size = numComponents = list.size();
            sz = new int[list.size()];
            id = new int[list.size()];

            for(int i = 0; i < list.size(); i++) {
                id[i] = i; 

                sz[i] = 1; 

            }
        }

        public int find (T elem) {

            

            int p = ht.get(elem);

            

            int root = p;
            while(id[root] != root) root = id[root];

            

            

            

            while(p != root) {
                int next = id[p];
                id[p] = root;
                p = next;
            }

            return root;
        }

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        public boolean connected(T p, T q) {
            return find(p) == find(q);
        }

        

        public int componentSize(T p) {
            return sz[find(p)];
        }

        

        public int size() {
            return size;
        }

        

        public int components() {
            return numComponents;
        }

        

        public void unify (T p, T q) {

            int root1 = find(p);
            int root2 = find(q);

            

            if(root1 == root2) return;

            

            if(sz[root1] < sz[root2]) {
                sz[root2] += sz[root1];
                id[root1] = root2;
            } else {
                sz[root1] += sz[root2];
                id[root2] = root1;
            }

            

            

            numComponents--;
        }
    }
    


}