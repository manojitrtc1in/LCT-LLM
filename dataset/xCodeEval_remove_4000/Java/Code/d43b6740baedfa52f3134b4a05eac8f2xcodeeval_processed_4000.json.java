import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.util.NoSuchElementException;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.*;
import java.lang.reflect.*;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }
}

class Task {
    class Tree {
        int left, right, middle;
        long value, first, second;
        Tree leftChild, rightChild;

        Tree(int left, int right) {
            this.left=left;
            this.right=right;
            middle=(left+right)/2;
            first=second=0;
            if (left==right) {
                value=A[left];
                return;
            }
            leftChild=new Tree(left, middle);
            rightChild=new Tree(middle+1, right);
            value=leftChild.value+rightChild.value;
        }

        void push() {
            if (first!=0) {
                long A=(acum(right-left-1)+1)%MOD, B=acum(right-left);
                value=(value+A*first%MOD+B*second%MOD)%MOD;
                if (leftChild!=null) {
                    leftChild.first=(leftChild.first+first)%MOD;
                    leftChild.second=(leftChild.second+second)%MOD;
                }
                if (rightChild!=null) {
                    long d1=(fib[middle-left]*first%MOD+fib[middle+1-left]*second%MOD)%MOD, d2=(fib[middle-left+1]*first%MOD+fib[middle+2-left]*second%MOD)%MOD;
                    rightChild.first=(rightChild.first+d1)%MOD;
                    rightChild.second=(rightChild.second+d2)%MOD;
                }
                first=second=0;
            }
        }

        void update(int from, int to) {
            push();
            if (left>to || right<from) return;
            if (left>=from && right<=to) {
                first=(first+fib[left-from+1])%MOD;
                second=(second+fib[left-from+2])%MOD;
                push();
                return;
            }
            leftChild.update(from, to);
            rightChild.update(from, to);
            value=(leftChild.value+rightChild.value)%MOD;
        }

        long query(int from, int to) {
            push();
            if (left>to || right<from) return 0;
            if (left>=from && right<=to) return value;
            return (leftChild.query(from, to)+rightChild.query(from, to))%MOD;
        }

    }

    int[] A;
    long[] fib;
    final int MOD=1_000_000_009;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n=in.readInt(), m=in.readInt();
        fib=new long[n+3];
        fib[0]=0;
        fib[1]=1;
        for (int i=2; i<n+3; i++) fib[i]=(fib[i-1]+fib[i-2])%MOD;
        A=new int[n];
        for (int i=0; i<n; i++) A[i]=in.readInt();
        Tree tree=new Tree(0, n-1);
        while (m-->0) {
            int t=in.readInt(), l=in.readInt()-1, r=in.readInt()-1;
            if (t==1) tree.update(l, r);
            else {
                

                out.printLine(tree.query(l, r));
            }
        }
    }

    long acum(int x) {
        return x<0?0:(fib[x]+fib[x+1]-1+MOD)%MOD;
    }
}

class InputReader {
    private boolean finished = false;

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id35 filter;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int peek() {
        if (numChars == -1)
            return -1;
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                return -1;
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar];
    }

    public int readInt() {
        int c = read();
        while (id10(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!id10(c));
        return res * sgn;
    }

    public long readLong() {
        int c = read();
        while (id10(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!id10(c));
        return res * sgn;
    }

    public String readString() {
        int c = read();
        while (id10(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            if (Character.isValidCodePoint(c))
                res.appendCodePoint(c);
            c = read();
        } while (!id10(c));
        return res.toString();
    }

    public boolean id10(int c) {
        if (filter != null)
            return filter.id10(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private String id5() {
        StringBuilder buf = new StringBuilder();
        int c = read();
        while (c != '\n' && c != -1) {
            if (c != '\r')
                buf.appendCodePoint(c);
            c = read();
        }
        return buf.toString();
    }

    public String readLine() {
        String s = id5();
        while (s.trim().length() == 0)
            s = id5();
        return s;
    }

    String readLine(boolean id31) {
        if (id31)
            return readLine();
        else
            return id5();
    }

    public BigInteger id22() {
        try {
            return new BigInteger(readString());
        } catch (NumberFormatException e) {
            throw new InputMismatchException();
        }
    }

    public char readCharacter() {
        int c = read();
        while (id10(c))
            c = read();
        return (char) c;
    }

    public double readDouble() {
        int c = read();
        while (id10(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!id10(c) && c != '.') {
            if (c == 'e' || c == 'E')
                return res * Math.pow(10, readInt());
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!id10(c)) {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, readInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                m /= 10;
                res += (c - '0') * m;
                c = read();
            }
        }
        return res * sgn;
    }

    public boolean id9() {
        int value;
        while (id10(value = peek()) && value != -1)
            read();
        return value == -1;
    }

    public String next() {
        return readString();
    }

    public id35 getFilter() {
        return filter;
    }

    public void setFilter(id35 filter) {
        this.filter = filter;
    }

    public interface id35 {
        public boolean id10(int ch);
    }
}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
                outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(char[] array) {
        writer.print(array);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void print(int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(array[i]);
        }
    }

    public void print(long[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(array[i]);
        }
    }

    public void printLine(int[] array) {
        print(array);
        writer.println();
    }

    public void printLine(long[] array) {
        print(array);
        writer.println();
    }

    public void printLine() {
        writer.println();
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void print(char i) {
        writer.print(i);
    }

    public void printLine(char i) {
        writer.println(i);
    }

    public void printLine(char[] array) {
        writer.println(array);
    }

    public void printFormat(String format, Object... objects) {
        writer.printf(format, objects);
    }

    public void close() {
        writer.close();
    }

    public void flush() {
        writer.flush();
    }

    public void print(long i) {
        writer.print(i);
    }

    public void printLine(long i) {
        writer.println(i);
    }

    public void print(int i) {
        writer.print(i);
    }

    public void printLine(int i) {
        writer.println(i);
    }
}

class IOUtils {
    public static int[] id2(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
    }

    public static long[] id16(InputReader in, int size) {
        long[] array = new long[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readLong();
        return array;
    }

    public static double[] id4(InputReader in, int size) {
        double[] array = new double[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readDouble();
        return array;
    }

    public static String[] id32(InputReader in, int size) {
        String[] array = new String[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readString();
        return array;
    }

    public static char[] id8(InputReader in, int size) {
        char[] array = new char[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readCharacter();
        return array;
    }

    public static void id20(InputReader in, int[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readInt();
        }
    }

    public static void id23(InputReader in, long[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readLong();
        }
    }

    public static void id27(InputReader in, double[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readDouble();
        }
    }

    public static char[][] readTable(InputReader in, int rowCount,
            int columnCount) {
        char[][] table = new char[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id8(in, columnCount);
        return table;
    }

    public static int[][] id11(InputReader in, int rowCount,
            int columnCount) {
        int[][] table = new int[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id2(in, columnCount);
        return table;
    }

    public static double[][] id1(InputReader in, int rowCount,
            int columnCount) {
        double[][] table = new double[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id4(in, columnCount);
        return table;
    }

    public static long[][] id3(InputReader in, int rowCount,
            int columnCount) {
        long[][] table = new long[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id16(in, columnCount);
        return table;
    }

    public static String[][] id30(InputReader in, int rowCount,
            int columnCount) {
        String[][] table = new String[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id32(in, columnCount);
        return table;
    }

    public static String readText(InputReader in) {
        StringBuilder result = new StringBuilder();
        while (true) {
            int character = in.read();
            if (character == '\r')
                continue;
            if (character == -1)
                break;
            result.append((char) character);
        }
        return result.toString();
    }

    public static void id24(InputReader in, String[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readString();
        }
    }

    public static void printTable(OutputWriter out, char[][] table) {
        for (char[] row : table)
            out.printLine(new String(row));
    }
}

class MiscUtils {
    public static final int[] DX4 = { 1, 0, -1, 0 };
    public static final int[] DY4 = { 0, -1, 0, 1 };
    public static final int[] DX8 = { 1, 1, 1, 0, -1, -1, -1, 0 };
    public static final int[] DY8 = { -1, 0, 1, 1, 1, 0, -1, -1 };
    public static final int[] id29 = { 2, 1, -1, -2, -2, -1, 1, 2 };
    public static final int[] id14 = { 1, 2, 2, 1, -1, -2, -2, -1 };

    private static final String[] id13 = { "M", "CM", "D", "CD", "C",
            "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    private static final int[] id34 = { 1000, 900, 500, 400, 100, 90,
            50, 40, 10, 9, 5, 4, 1 };

    public static long id7(long n, int k) {
        if (n == 1)
            return 0;
        if (k == 1)
            return n - 1;
        if (k > n)
            return (id7(n - 1, k) + k) % n;
        long count = n / k;
        long result = id7(n - count, k);
        result -= n % k;
        if (result < 0)
            result += n;
        else
            result += result / (k - 1);
        return result;
    }

    public static boolean id36(int row, int column, int rowCount,
            int columnCount) {
        return row >= 0 && row < rowCount && column >= 0
                && column < columnCount;
    }

    public static long id33(long[][] array) {
        int n = array.length;
        int m = array[0].length;
        long[][] id12 = new long[n + 1][m + 1];
        for (int i = 0; i < n; i++) {
            long rowSum = 0;
            for (int j = 0; j < m; j++) {
                rowSum += array[i][j];
                id12[i + 1][j + 1] = id12[i][j + 1] + rowSum;
            }
        }
        long result = Long.MIN_VALUE;
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                long id21 = 0;
                for (int k = 1; k <= n; k++) {
                    long current = id12[k][j + 1] - id12[k][i];
                    result = Math.max(result, current - id21);
                    id21 = Math.min(id21, current);
                }
            }
        }
        return result;
    }

    public static int parseIP(String ip) {
        String[] components = ip.split("[.]");
        int result = 0;
        for (int i = 0; i < 4; i++)
            result += (1 << (24 - 8 * i)) * Integer.parseInt(components[i]);
        return result;
    }

    public static String buildIP(int mask) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < 4; i++) {
            if (i != 0)
                result.append('.');
            result.append(mask >> (24 - 8 * i) & 255);
        }
        return result.toString();
    }

    public static long binarySearch(long from, long to,
            Function<Long, Boolean> function) {
        while (from < to) {
            long argument = from + (to - from) / 2;
            if (function.value(argument))
                to = argument;
            else
                from = argument + 1;
        }
        return from;
    }

    public static <T> boolean equals(T first, T second) {
        return first == null && second == null || first != null
                && first.equals(second);
    }

    public static boolean id18(char ch) {
        ch = Character.toUpperCase(ch);
        return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
                || ch == 'Y';
    }

    public static boolean id6(char ch) {
        ch = Character.toUpperCase(ch);
        return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    public static String id26(int number) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < id13.length; i++) {
            while (number >= id34[i]) {
                number -= id34[i];
                result.append(id13[i]);
            }
        }
        return result.toString();
    }

    public static int id19(String number) {
        int result = 0;
        for (int i = 0; i < id13.length; i++) {
            while (number.startsWith(id13[i])) {
                number = number.substring(id13[i].length());
                result += id34[i];
            }
        }
        return result;
    }

    public static int distance(int x1, int y1, int x2, int y2) {
        int dx = x1 - x2;
        int dy = y1 - y2;
        return dx * dx + dy * dy;
    }

    public static <T extends Comparable<T>> T min(T first, T second) {
        if (first.compareTo(second) <= 0)
            return first;
        return second;
    }

    public static <T extends Comparable<T>> T max(T first, T second) {
        if (first.compareTo(second) <= 0)
            return second;
        return first;
    }

    public static void id15(int[]... arrays) {
        for (int[] array : arrays) {
            for (int i = 0; i < array.length; i++)
                array[i]--;
        }
    }

    public static int[] id25(String s) {
        String[] tokens = s.split(" ");
        int[] result = new int[tokens.length];
        for (int i = 0; i < result.length; i++)
            result[i] = Integer.parseInt(tokens[i]);
        return result;
    }
}

interface Function<A, V> {
    public abstract V value(A argument);
}

class ArrayUtils {
    private static int[] tempInt = new int[0];
    private static long[] tempLong = new long[0];

    public static Integer[] generateOrder(int size) {
        Integer[] order = new Integer[size];
        for (int i = 0; i < size; i++)
            order[i] = i;
        return order;
    }

    public static void fill(short[][] array, short value) {
        for (short[] row : array)
            Arrays.fill(row, value);
    }

    public static void fill(long[][] array, long value) {
        for (long[] row : array)
            Arrays.fill(row, value);
    }

    public static void fill(double[][] array, double value) {
        for (double[] row : array)
            Arrays.fill(row, value);
    }

    public static void fill(double[][][] array, double value) {
        for (double[][] row : array)
            fill(row, value);
    }

    public static void fill(double[][][][] array, double value) {
        for (double[][][] row : array)
            fill(row, value);
    }

    public static void fill(double[][][][][] array, double value) {
        for (double[][][][] row : array)
            fill(row, value);
    }

    public static void fill(long[][][] array, long value) {
        for (long[][] row : array)
            fill(row, value);
    }

    public static void fill(long[][][][] array, long value) {
        for (long[][][] row : array)
            fill(row, value);
    }

    public static void fill(long[][][][][] array, long value) {
        for (long[][][][] row : array)
            fill(row, value);
    }

    public static void fillColumn(long[][] array, int index, long value) {
        for (long[] row : array)
            row[index] = value;
    }

    public static void fillColumn(int[][] array, int index, int value) {
        for (int[] row : array)
            row[index] = value;
    }

    public static void fill(int[][] array, int value) {
        for (int[] row : array)
            Arrays.fill(row, value);
    }

    public static void fill(boolean[][] array, boolean value) {
        for (boolean[] row : array)
            Arrays.fill(row, value);
    }

    public static void fill(boolean[][][] array, boolean value) {
        for (boolean[][] row : array)
            fill(row, value);
    }

    public static long sumArray(int[] array) {
        long result = 0;
        for (int element : array)
            result += element;
        return result;
    }

    public static int[] range(int from, int to) {
        int[] result = new int[Math.max(from, to) - Math.min(from, to) + 1];
        int index = 0;
        if (to > from) {
            for (int i = from; i <= to; i++)
                result[index++] = i;
        } else {
            for (int i = from; i >= to; i--)
                result[index++] = i;
        }
        return result;
    }

    public static void fill(int[][][] array, int value) {
        for (int[][] subArray : array)
            fill(subArray, value);
    }

    public static void fill(short[][][] array, short value) {
        for (short[][] subArray : array)
            fill(subArray, value);
    }

    public static void fill(int[][][][] array, int value) {
        for (int[][][] subArray : array)
            fill(subArray, value);
    }

    public static void fill(short[][][][] array, short value) {
        for (short[][][] subArray : array)
            fill(subArray, value);
    }

    public static void fill(int[][][][][] array, int value) {
        for (int[][][][] subArray : array)
            fill(subArray, value);
    }

    public static void fill(short[][][][][] array, short value) {
        for (short[][][][] subArray : array)
            fill(subArray, value);
    }

    public static void fill(int[][][][][][] array, int value) {
        for (int[][][][][] subArray : array)
            fill(subArray, value);
    }

    public static void fill(short[][][][][][] array, short value) {
        for (short[][][][][] subArray : array)
            fill(subArray, value);
    }

    public static void fill(int[][][][][][][] array, int value) {
        for (int[][][][][][] subArray : array)
            fill(subArray, value);
    }

    public static void fill(short[][][][][][][] array, short value) {
        for (short[][][][][][] subArray : array)
            fill(subArray, value);
    }

    public static Integer[] order(int size, Comparator<Integer> comparator) {
        Integer[] order = generateOrder(size);
        Arrays.sort(order, comparator);
        return order;
    }

    public static <T> void fill(T[][] array, T value) {
        for (T[] row : array)
            Arrays.fill(row, value);
    }

    public static void fill(char[][] array, char value) {
        for (char[] row : array)
            Arrays.fill(row, value);
    }

    public static void fill(byte[][] array, byte value) {
        for (byte[] row : array)
            Arrays.fill(row, value);
    }

    public static void fill(byte[][][] array, byte value) {
        for (byte[][] row : array)
            fill(row, value);
    }

    public static void fill(byte[][][][] array, byte value) {
        for (byte[][][] row : array)
            fill(row, value);
    }

    public static long multiply(int[] first, int[] second) {
        long result = 0;
        for (int i = 0; i < first.length; i++)
            result += (long) first[i] * second[i];
        return result;
    }

    public static int[] createOrder(int size) {
        int[] order = new int[size];
        for (int i = 0; i < size; i++)
            order[i] = i;
        return order;
    }

    private static void id0(int size) {
        if (tempInt.length >= size)
            return;
        size = Math.max(size, tempInt.length << 1);
        tempInt = new int[size];
    }

    private static void id17(int size) {
        if (tempLong.length >= size)
            return;
        size = Math.max(size, tempLong.length << 1);
        tempLong = new long[size];
    }

    public static int[] unique(int[] array) {
        return unique(array, 0, array.length);
    }

    public static int[] unique(int[] array, int from, int to) {
        if (from == to)
            return new int[0];
        int count = 1;
        for (int i = from + 1; i < to; i++) {
            if (array[i] != array[i - 1])
                count++;
        }
        int[] result = new int[count];
        result[0] = array[from];
        int index = 1;
        for (int i = from + 1; i < to; i++) {
            if (array[i] != array[i - 1])
                result[index++] = array[i];
        }
        return result;
    }

    public static char[] unique(char[] array) {
        return unique(array, 0, array.length);
    }

    public static char[] unique(char[] array, int from, int to) {
        if (from == to)
            return new char[0];
        int count = 1;
        for (int i = from + 1; i < to; i++) {
            if (array[i] != array[i - 1])
                count++;
        }
        char[] result = new char[count];
        result[0] = array[from];
        int index = 1;
        for (int i = from + 1; i < to; i++) {
            if (array[i] != array[i - 1])
                result[index++] = array[i];
        }
        return result;
    }

    public static int maxElement(int[] array) {
        return maxElement(array, 0, array.length);
    }

    public static int maxElement(int[] array, int from, int to) {
        int result = Integer.MIN_VALUE;
        for (int i = from; i < to; i++)
            result = Math.max(result, array[i]);
        return result;
    }

    public static int[] reversePermutation(int[] permutation) {
        int[] result = new int[permutation.length];
        for (int i = 0; i < permutation.length; i++)
            result[permutation[i]] = i;
        return result;
    }

    public static void reverse(int[] array) {
        for (int i = 0, j = array.length - 1; i < j; i++, j--) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    public static void reverse(char[] array) {
        for (int i = 0, j = array.length - 1; i < j; i++, j--) {
            char temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    private static long maxElement(long[] array, int from, int to) {
        long result = Long.MIN_VALUE;
        for (int i = from; i < to; i++)
            result = Math.max(result, array[i]);
        return result;
    }

    public static int minPosition(int[] array) {
        return minPosition(array, 0, array.length);
    }

    public static int maxPosition(int[] array) {
        return maxPosition(array, 0, array.length);
    }

    public static int minPosition(int[] array, int from, int to) {
        if (from >= to)
            return -1;
        int min = array[from];
        int result = from;
        for (int i = from + 1; i < to; i++) {
            if (array[i] < min) {
                min = array[i];
                result = i;
            }
        }
        return result;
    }

    public static int maxPosition(int[] array, int from, int to) {
        if (from >= to)
            return -1;
        int max = array[from];
        int result = from;
        for (int i = from + 1; i < to; i++) {
            if (array[i] > max) {
                max = array[i];
                result = i;
            }
        }
        return result;
    }

    public static int[] id28(int[] first, int[] second) {
        int count = first.length;
        int[] result = new int[count];
        for (int i = 0; i < count; i++) {
            result[i] = first[second[i]];
        }
        return result;
    }

    public static int minElement(int[] array) {
        return array[minPosition(array)];
    }

    public static long[] id12(int[] array) {
        long[] result = new long[array.length + 1];
        for (int i = 0; i < array.length; i++)
            result[i + 1] = result[i] + array[i];
        return result;
    }

    public static void order(int[] order, int[] array) {
        id0(order.length);
        for (int i = 0; i < order.length; i++)
            tempInt[i] = array[order[i]];
        System.arraycopy(tempInt, 0, array, 0, array.length);
    }

    public static void order(int[] order, long[] array) {
        id17(order.length);
        for (int i = 0; i < order.length; i++)
            tempLong[i] = array[order[i]];
        System.arraycopy(tempLong, 0, array, 0, array.length);
    }

    public static long[] asLong(int[] array) {
        long[] result = new long[array.length];
        for (int i = 0; i < array.length; i++)
            result[i] = array[i];
        return result;
    }

    public static int count(int[] array, int value) {
        int result = 0;
        for (int i : array) {
            if (i == value)
                result++;
        }
        return result;
    }

    public static int count(long[] array, long value) {
        int result = 0;
        for (long i : array) {
            if (i == value) {
                result++;
            }
        }
        return result;
    }

    public static int count(char[] array, char value) {
        int result = 0;
        for (char i : array) {
            if (i == value)
                result++;
        }
        return result;
    }

    public static int count(boolean[] array, boolean value) {
        int result = 0;
        for (boolean i : array) {
            if (i == value)
                result++;
        }
        return result;
    }

    public static int[] merge(int[] first, int[] second) {
        int[] result = new int[first.length + second.length];
        int firstIndex = 0;
        int secondIndex = 0;
        int index = 0;
        while (firstIndex < first.length && secondIndex < second.length) {
            if (first[firstIndex] < second[secondIndex])
                result[index++] = first[firstIndex++];
            else
                result[index++] = second[secondIndex++];
        }
        System.arraycopy(first, firstIndex, result, index, first.length
                - firstIndex);
        System.arraycopy(second, secondIndex, result, index, second.length
                - secondIndex);
        return result;
    }

    public static <V> void reverse(V[] array) {
        for (int i = 0, j = array.length - 1; i < j; i++, j--) {
            V temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    public static long minElement(long[] array) {
        return array[minPosition(array)];
    }

    public static long maxElement(long[] array) {
        return array[maxPosition(array)];
    }

    public static int minPosition(long[] array) {
        return minPosition(array, 0, array.length);
    }

    public static int maxPosition(long[] array) {
        return maxPosition(array, 0, array.length);
    }

    public static int minPosition(long[] array, int from, int to) {
        if (from >= to)
            return -1;
        long min = array[from];
        int result = from;
        for (int i = from + 1; i < to; i++) {
            if (array[i] < min) {
                min = array[i];
                result = i;
            }
        }
        return result;
    }

    public static int maxPosition(long[] array, int from, int to) {
        if (from >= to)
            return -1;
        long max = array[from];
        int result = from;
        for (int i = from + 1; i < to; i++) {
            if (array[i] > max) {
                max = array[i];
                result = i;
            }
        }
        return result;
    }

    public static int[] createArray(int count, int value) {
        int[] array = new int[count];
        Arrays.fill(array, value);
        return array;
    }

    public static long[] createArray(int count, long value) {
        long[] array = new long[count];
        Arrays.fill(array, value);
        return array;
    }

    public static double[] createArray(int count, double value) {
        double[] array = new double[count];
        Arrays.fill(array, value);
        return array;
    }

    public static boolean[] createArray(int count, boolean value) {
        boolean[] array = new boolean[count];
        Arrays.fill(array, value);
        return array;
    }

    public static char[] createArray(int count, char value) {
        char[] array = new char[count];
        Arrays.fill(array, value);
        return array;
    }

    public static <T> T[] createArray(int count, T value) {
        @SuppressWarnings("unchecked")
        T[] array = (T[]) Array.newInstance(value.getClass(), count);
        Arrays.fill(array, value);
        return array;
    }

    public static long[][] id12(int[][] array) {
        int height = array.length;
        int width = array[0].length;
        long[][] result = new long[height + 1][width + 1];
        for (int i = 1; i <= height; i++) {
            for (int j = 1; j <= width; j++) {
                result[i][j] = result[i][j - 1] + result[i - 1][j]
                        - result[i - 1][j - 1] + array[i - 1][j - 1];
            }
        }
        return result;
    }

    public static long[][] id12(long[][] array) {
        int height = array.length;
        int width = array[0].length;
        long[][] result = new long[height + 1][width + 1];
        for (int i = 1; i <= height; i++) {
            for (int j = 1; j <= width; j++) {
                result[i][j] = result[i][j - 1] + result[i - 1][j]
                        - result[i - 1][j - 1] + array[i - 1][j - 1];
            }
        }
        return result;
    }

    public static int[][] transpose(int[][] array) {
        if (array.length == 0) {
            return new int[0][0];
        }
        int[][] result = new int[array[0].length][array.length];
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array[i].length; j++) {
                result[j][i] = array[i][j];
            }
        }
        return result;
    }

    public static int find(int[] array, int value) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == value) {
                return i;
            }
        }
        return -1;
    }
}