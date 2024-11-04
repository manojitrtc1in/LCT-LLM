

import java.util.*;
import java.lang.*;
import java.io.*;
import static java.lang.Math.*;


public class id15


{
    static InputReader in = new InputReader(System.in);
    static OutputWriter out = new OutputWriter(System.out);

    public static void main(String[] args) throws java.lang.Exception {

        int t = in.nextInt();

        while (t-- > 0) {
            int n = in.nextInt();
            int m = in.nextInt();

            int a[] = in.id11(n);
            int b[] = in.id11(m);

            int an = 0;
            int bn = 0;
            while (an < n && a[an] < 0)
                an++;
            while (bn < m && b[bn] < 0)
                bn++;

            int a1[] = new int[an];
            int b1[] = new int[bn];

            int ans1 = solve(a, an, b, bn);

            for (int i = 0, j = an - 1; j >= 0; j--, i++) {
                a1[i] = -a[j];
            }
            for (int i = 0, j = bn - 1; j >= 0; j--, i++) {
                b1[i] = -b[j];
            }
            out.printLine(ans1 + solve(a1, 0, b1, 0));
        }

        

        out.flush();
        out.close();
    }

    static int solve(int a[], int i, int[] b, int j) {
        if (a.length == i || b.length == j)
            return 0;
        int max = 0;

        int rs = a[i];
        int re = a[i];
        int boxes = 0;
        

        

        int goodi = j;
        int goodj = j;

        int initSpecial[] = new int[a.length + 1];

        for (int o = a.length - 1, s = b.length - 1; o >= i; o--) {
            while (s >= 0 && a[o] < b[s])
                s--;

            if (s >= 0 && a[o] == b[s]) {
                initSpecial[o] = 1;
                s--;
            }
            initSpecial[o] += o + 1 < a.length ? initSpecial[o + 1] : 0;
        }

        while (j < b.length) {
            if (i < a.length && a[i] < b[j]) {
                boxes++;
                re = a[i];
                rs = re - boxes + 1;
                i++;
            } else if (i >= a.length || a[i] > b[j]) {
                re = b[j];
                rs = re - boxes + 1;
                j++;
            } else {
                boxes++;
                re = a[i];
                rs = re - boxes + 1;
                i++;
                j++;
            }

            while (goodi < b.length && b[goodi] <= re)
                goodi++;
            while (goodj < b.length && b[goodj] < rs)
                goodj++;

            max = Math.max(max, goodi - goodj + initSpecial[i]);
        }

        return max;
    }

    private static class InputReader implements AutoCloseable {

        
        private static final int id18 = 1 << 16;

        
        private static final InputStream DEFAULT_STREAM = System.in;

        
        private static final int id23 = 21;

        

        private int c;

        

        private final byte[] buf;
        private final int bufferSize;
        private int bufIndex;
        private int id29;

        private final InputStream stream;

        

        private static final byte EOF = -1;

        

        private static final byte NEW_LINE = 10;

        

        private static final byte SPACE = 32;

        

        private static final byte DASH = 45;

        

        private static final byte DOT = 46;

        

        private char[] charBuffer;

        

        private static final byte[] bytes = new byte[58];
        private static final int[] ints = new int[58];
        private static final char[] chars = new char[128];

        static {
            char ch = ' ';
            int value = 0;
            byte _byte = 0;
            for (int i = 48; i < 58; i++)
                bytes[i] = _byte++;
            for (int i = 48; i < 58; i++)
                ints[i] = value++;
            for (int i = 32; i < 128; i++)
                chars[i] = ch++;
        }

        

        private static final double[][] doubles = {
                { 0.0d, 0.00d, 0.000d, 0.0000d, 0.00000d, 0.000000d, 0.0000000d, 0.00000000d, 0.000000000d,
                        0.0000000000d, 0.00000000000d, 0.000000000000d, 0.0000000000000d, 0.00000000000000d,
                        0.000000000000000d, 0.0000000000000000d, 0.00000000000000000d, 0.000000000000000000d,
                        0.0000000000000000000d, 0.00000000000000000000d, 0.000000000000000000000d },
                { 0.1d, 0.01d, 0.001d, 0.0001d, 0.00001d, 0.000001d, 0.0000001d, 0.00000001d, 0.000000001d,
                        0.0000000001d, 0.00000000001d, 0.000000000001d, 0.0000000000001d, 0.00000000000001d,
                        0.000000000000001d, 0.0000000000000001d, 0.00000000000000001d, 0.000000000000000001d,
                        0.0000000000000000001d, 0.00000000000000000001d, 0.000000000000000000001d },
                { 0.2d, 0.02d, 0.002d, 0.0002d, 0.00002d, 0.000002d, 0.0000002d, 0.00000002d, 0.000000002d,
                        0.0000000002d, 0.00000000002d, 0.000000000002d, 0.0000000000002d, 0.00000000000002d,
                        0.000000000000002d, 0.0000000000000002d, 0.00000000000000002d, 0.000000000000000002d,
                        0.0000000000000000002d, 0.00000000000000000002d, 0.000000000000000000002d },
                { 0.3d, 0.03d, 0.003d, 0.0003d, 0.00003d, 0.000003d, 0.0000003d, 0.00000003d, 0.000000003d,
                        0.0000000003d, 0.00000000003d, 0.000000000003d, 0.0000000000003d, 0.00000000000003d,
                        0.000000000000003d, 0.0000000000000003d, 0.00000000000000003d, 0.000000000000000003d,
                        0.0000000000000000003d, 0.00000000000000000003d, 0.000000000000000000003d },
                { 0.4d, 0.04d, 0.004d, 0.0004d, 0.00004d, 0.000004d, 0.0000004d, 0.00000004d, 0.000000004d,
                        0.0000000004d, 0.00000000004d, 0.000000000004d, 0.0000000000004d, 0.00000000000004d,
                        0.000000000000004d, 0.0000000000000004d, 0.00000000000000004d, 0.000000000000000004d,
                        0.0000000000000000004d, 0.00000000000000000004d, 0.000000000000000000004d },
                { 0.5d, 0.05d, 0.005d, 0.0005d, 0.00005d, 0.000005d, 0.0000005d, 0.00000005d, 0.000000005d,
                        0.0000000005d, 0.00000000005d, 0.000000000005d, 0.0000000000005d, 0.00000000000005d,
                        0.000000000000005d, 0.0000000000000005d, 0.00000000000000005d, 0.000000000000000005d,
                        0.0000000000000000005d, 0.00000000000000000005d, 0.000000000000000000005d },
                { 0.6d, 0.06d, 0.006d, 0.0006d, 0.00006d, 0.000006d, 0.0000006d, 0.00000006d, 0.000000006d,
                        0.0000000006d, 0.00000000006d, 0.000000000006d, 0.0000000000006d, 0.00000000000006d,
                        0.000000000000006d, 0.0000000000000006d, 0.00000000000000006d, 0.000000000000000006d,
                        0.0000000000000000006d, 0.00000000000000000006d, 0.000000000000000000006d },
                { 0.7d, 0.07d, 0.007d, 0.0007d, 0.00007d, 0.000007d, 0.0000007d, 0.00000007d, 0.000000007d,
                        0.0000000007d, 0.00000000007d, 0.000000000007d, 0.0000000000007d, 0.00000000000007d,
                        0.000000000000007d, 0.0000000000000007d, 0.00000000000000007d, 0.000000000000000007d,
                        0.0000000000000000007d, 0.00000000000000000007d, 0.000000000000000000007d },
                { 0.8d, 0.08d, 0.008d, 0.0008d, 0.00008d, 0.000008d, 0.0000008d, 0.00000008d, 0.000000008d,
                        0.0000000008d, 0.00000000008d, 0.000000000008d, 0.0000000000008d, 0.00000000000008d,
                        0.000000000000008d, 0.0000000000000008d, 0.00000000000000008d, 0.000000000000000008d,
                        0.0000000000000000008d, 0.00000000000000000008d, 0.000000000000000000008d },
                { 0.9d, 0.09d, 0.009d, 0.0009d, 0.00009d, 0.000009d, 0.0000009d, 0.00000009d, 0.000000009d,
                        0.0000000009d, 0.00000000009d, 0.000000000009d, 0.0000000000009d, 0.00000000000009d,
                        0.000000000000009d, 0.0000000000000009d, 0.00000000000000009d, 0.000000000000000009d,
                        0.0000000000000000009d, 0.00000000000000000009d, 0.000000000000000000009d } };

        
        public InputReader() {
            this(DEFAULT_STREAM, id18);
        }

        
        public InputReader(int bufferSize) {
            this(DEFAULT_STREAM, bufferSize);
        }

        
        public InputReader(InputStream stream) {
            this(stream, id18);
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

            if (id29 == EOF)
                throw new IOException();

            if (bufIndex >= id29) {
                bufIndex = 0;
                id29 = stream.read(buf);
                if (id29 == EOF)
                    return EOF;
            }

            return buf[bufIndex++];
        }

        
        private int id6(int token) throws IOException {

            if (id29 == EOF)
                return EOF;

            

            do {

                while (bufIndex < id29) {
                    if (buf[bufIndex] > token)
                        return 0;
                    bufIndex++;
                }

                

                id29 = stream.read(buf);
                if (id29 == EOF)
                    return EOF;
                bufIndex = 0;

            } while (true);

        }

        
        public byte nextByte() throws IOException {
            return (byte) nextInt();
        }

        
        public int nextInt() throws IOException {

            if (id6(DASH - 1) == EOF)
                throw new IOException();
            int sgn = 1, res = 0;

            c = buf[bufIndex];
            if (c == DASH) {
                sgn = -1;
                bufIndex++;
            }

            do {

                while (bufIndex < id29) {
                    if (buf[bufIndex] > SPACE) {
                        res = (res << 3) + (res << 1);
                        res += ints[buf[bufIndex++]];
                    } else {
                        bufIndex++;
                        return res * sgn;
                    }
                }

                

                id29 = stream.read(buf);
                if (id29 == EOF)
                    return res * sgn;
                bufIndex = 0;

            } while (true);

        }

        
        public long nextLong() throws IOException {

            if (id6(DASH - 1) == EOF)
                throw new IOException();
            int sgn = 1;
            long res = 0L;
            c = buf[bufIndex];
            if (c == DASH) {
                sgn = -1;
                bufIndex++;
            }

            do {

                while (bufIndex < id29) {
                    if (buf[bufIndex] > SPACE) {
                        res = (res << 3) + (res << 1);
                        res += ints[buf[bufIndex++]];
                    } else {
                        bufIndex++;
                        return res * sgn;
                    }
                }

                

                id29 = stream.read(buf);
                if (id29 == EOF)
                    return res * sgn;
                bufIndex = 0;

            } while (true);

        }

        
        private void id7() {
            char[] newBuffer = new char[charBuffer.length << 1];
            for (int i = 0; i < charBuffer.length; i++)
                newBuffer[i] = charBuffer[i];
            charBuffer = newBuffer;
        }

        
        public String nextLine() throws IOException {

            try {
                c = read();
            } catch (IOException e) {
                return null;
            }
            if (c == NEW_LINE)
                return ""; 

            if (c == EOF)
                return null; 


            int i = 0;
            charBuffer[i++] = (char) c;

            do {

                while (bufIndex < id29) {
                    if (buf[bufIndex] != NEW_LINE) {
                        if (i == charBuffer.length)
                            id7();
                        charBuffer[i++] = (char) buf[bufIndex++];
                    } else {
                        bufIndex++;
                        return new String(charBuffer, 0, i);
                    }
                }

                

                id29 = stream.read(buf);
                if (id29 == EOF)
                    return new String(charBuffer, 0, i);
                bufIndex = 0;

            } while (true);

        }

        

        

        

        public String nextString() throws IOException {
            if (id29 == EOF)
                return null;
            if (id6(SPACE) == EOF)
                return null;

            for (int i = 0;;) {
                while (bufIndex < id29) {
                    if (buf[bufIndex] > SPACE) {
                        if (i == charBuffer.length)
                            id7();
                        charBuffer[i++] = (char) buf[bufIndex++];
                    } else {
                        bufIndex++;
                        return new String(charBuffer, 0, i);
                    }
                }

                

                id29 = stream.read(buf);
                if (id29 == EOF)
                    return new String(charBuffer, 0, i);
                bufIndex = 0;
            }
        }

        

        public double nextDouble() throws IOException {
            String doubleVal = nextString();
            if (doubleVal == null)
                throw new IOException();
            return Double.valueOf(doubleVal);
        }

        

        

        

        

        

        

        

        

        public double id2() throws IOException {
            c = read();
            int sgn = 1;
            while (c <= SPACE)
                c = read(); 

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
                

                while (c > SPACE && i < id23) {
                    res += doubles[ints[c]][i++];
                    c = read();
                }
            }
            return res * sgn;
        }

        

        public byte[] id8(int n) throws IOException {
            byte[] ar = new byte[n];
            for (int i = 0; i < n; i++)
                ar[i] = nextByte();
            return ar;
        }

        

        public int[] id11(int n) throws IOException {
            int[] ar = new int[n];
            for (int i = 0; i < n; i++)
                ar[i] = nextInt();
            return ar;
        }

        

        public long[] id30(int n) throws IOException {
            long[] ar = new long[n];
            for (int i = 0; i < n; i++)
                ar[i] = nextLong();
            return ar;
        }

        

        public double[] id24(int n) throws IOException {
            double[] ar = new double[n];
            for (int i = 0; i < n; i++)
                ar[i] = nextDouble();
            return ar;
        }

        

        public double[] id13(int n) throws IOException {
            double[] ar = new double[n];
            for (int i = 0; i < n; i++)
                ar[i] = id2();
            return ar;
        }

        

        public String[] id25(int n) throws IOException {
            String[] ar = new String[n];
            for (int i = 0; i < n; i++) {
                String str = nextString();
                if (str == null)
                    throw new IOException();
                ar[i] = str;
            }
            return ar;
        }

        

        public byte[] id17(int n) throws IOException {
            byte[] ar = new byte[n + 1];
            for (int i = 1; i <= n; i++)
                ar[i] = nextByte();
            return ar;
        }

        

        public int[] id1(int n) throws IOException {
            int[] ar = new int[n + 1];
            for (int i = 1; i <= n; i++)
                ar[i] = nextInt();
            return ar;
        }

        

        public long[] id28(int n) throws IOException {
            long[] ar = new long[n + 1];
            for (int i = 1; i <= n; i++)
                ar[i] = nextLong();
            return ar;
        }

        

        public double[] id3(int n) throws IOException {
            double[] ar = new double[n + 1];
            for (int i = 1; i <= n; i++)
                ar[i] = nextDouble();
            return ar;
        }

        

        public double[] id26(int n) throws IOException {
            double[] ar = new double[n + 1];
            for (int i = 1; i <= n; i++)
                ar[i] = id2();
            return ar;
        }

        

        public String[] id16(int n) throws IOException {
            String[] ar = new String[n + 1];
            for (int i = 1; i <= n; i++)
                ar[i] = nextString();
            return ar;
        }

        

        public byte[][] id21(int rows, int cols) throws IOException {
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

        

        public long[][] id9(int rows, int cols) throws IOException {
            long[][] matrix = new long[rows][cols];
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    matrix[i][j] = nextLong();
            return matrix;
        }

        

        public double[][] id22(int rows, int cols) throws IOException {
            double[][] matrix = new double[rows][cols];
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    matrix[i][j] = nextDouble();
            return matrix;
        }

        

        public double[][] id4(int rows, int cols) throws IOException {
            double[][] matrix = new double[rows][cols];
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    matrix[i][j] = id2();
            return matrix;
        }

        

        public String[][] id19(int rows, int cols) throws IOException {
            String[][] matrix = new String[rows][cols];
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    matrix[i][j] = nextString();
            return matrix;
        }

        

        public byte[][] id14(int rows, int cols) throws IOException {
            byte[][] matrix = new byte[rows + 1][cols + 1];
            for (int i = 1; i <= rows; i++)
                for (int j = 1; j <= cols; j++)
                    matrix[i][j] = nextByte();
            return matrix;
        }

        

        public int[][] id10(int rows, int cols) throws IOException {
            int[][] matrix = new int[rows + 1][cols + 1];
            for (int i = 1; i <= rows; i++)
                for (int j = 1; j <= cols; j++)
                    matrix[i][j] = nextInt();
            return matrix;
        }

        

        public long[][] id20(int rows, int cols) throws IOException {
            long[][] matrix = new long[rows + 1][cols + 1];
            for (int i = 1; i <= rows; i++)
                for (int j = 1; j <= cols; j++)
                    matrix[i][j] = nextLong();
            return matrix;
        }

        

        public double[][] id5(int rows, int cols) throws IOException {
            double[][] matrix = new double[rows + 1][cols + 1];
            for (int i = 1; i <= rows; i++)
                for (int j = 1; j <= cols; j++)
                    matrix[i][j] = nextDouble();
            return matrix;
        }

        

        public double[][] id12(int rows, int cols) throws IOException {
            double[][] matrix = new double[rows + 1][cols + 1];
            for (int i = 1; i <= rows; i++)
                for (int j = 1; j <= cols; j++)
                    matrix[i][j] = id2();
            return matrix;
        }

        

        public String[][] id27(int rows, int cols) throws IOException {
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

    private static class OutputWriter implements AutoCloseable {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0)
                    writer.print(' ');
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void flush() {
            writer.flush();
        }

    }
}
