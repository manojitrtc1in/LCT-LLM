import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.Random;
import java.util.AbstractList;
import java.io.Writer;
import java.util.Map;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.AbstractSet;
import java.util.Iterator;
import java.util.Set;
import java.util.AbstractMap;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.util.Collections;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        long x = in.readInt();

        long[] c = IOUtils.id16(in, n);
        long h = 0;

        ArrayUtils.safeSort(c);

        for (int i = 0; i < n; i++) {
            h += (x * c[i]);
            if (x > 1) {
                x--;
            }
        }

        out.printLine(h);
    }
}

class InputReader {
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
        while (id9(c))
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
        } while (!id9(c));
        return res * sgn;
    }

    public boolean id9(int c) {
        if (filter != null)
            return filter.id9(c);
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public boolean id8() {
        int value;
        while (id9(value = peek()) && value != -1)
            read();
        return value == -1;
    }

    public char readCharacter() {
        int c = read();
        while (id9(c))
            c = read();
        return (char) c;
    }

    public String readString() {
        int c = read();
        while (id9(c))
            c = read();
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!id9(c));
        return res.toString();
    }

    public long readLong() {
        int c = read();
        while (id9(c))
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
        } while (!id9(c));
        return res * sgn;
    }

    public interface id35 {
        public boolean id9(int ch);
    }

    private String id6() {
        StringBuffer buf = new StringBuffer();
        int c = read();
        while (c != '\n' && c != -1) {
            if (c != '\r')
                buf.appendCodePoint(c);
            c = read();
        }
        return buf.toString();
    }

    public String readLine() {
        String s = id6();
        while (s.trim().length() == 0)
            s = id6();
        return s;
    }

    public String readLine(boolean id33) {
        if (id33)
            return readLine();
        else
            return id6();
    }

    public BigInteger id23() {
        try {
            return new BigInteger(readString());
        } catch (NumberFormatException e) {
            throw new InputMismatchException();
        }
    }

    public double readDouble() {
        int c = read();
        while (id9(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!id9(c) && c != '.') {
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
            while (!id9(c)) {
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

    public String next() {
        return readString();
    }
}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(long[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(array[i]);
        }
    }

    public void printLine(long[] array) {
        print(array);
        writer.println();
    }

    public void print(int[] array) {
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

    public void print(IntCollection collection) {
        boolean first = true;
        for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance()) {
            if (first)
                first = false;
            else
                writer.print(' ');
            writer.print(iterator.value());
        }
    }

    public void printLine(IntCollection collection) {
        print(collection);
        writer.println();
    }

    public void printFormat(String format, Object...objects) {
        writer.printf(format, objects);
    }

    public void print(Object...objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void printLine(Object...objects) {
        print(objects);
        writer.println();
    }

    public void printLine(char[] array) {
        writer.println(array);
    }

    public void close() {
        writer.close();
    }

}

class IOUtils {
    public static void printArray(int[] array, OutputWriter out) {
        if (array.length == 0) {
            out.printLine();
            return;
        }
        out.print(array[0]);
        for (int i = 1; i < array.length; i++)
            out.print(" " + array[i]);
        out.printLine();
    }

    public static<T> void printCollection(Iterable<T> collection, OutputWriter out) {
        printCollection(collection, out, " ");
    }

    public static<T> void printCollection(Iterable<T> collection, OutputWriter out, String delimiter) {
        boolean isFirst = true;
        for (T element : collection) {
            if (isFirst)
                isFirst = false;
            else
                out.print(delimiter);
            out.print(element);
        }
        out.printLine();
    }

    public static<T> void printCollection(Iterable<T> collection, PrintWriter out, String delimiter) {
        boolean isFirst = true;
        for (T element : collection) {
            if (isFirst)
                isFirst = false;
            else
                out.print(delimiter);
            out.print(element);
        }
        out.println();
    }

    public static Pair<Integer, Integer> id13(InputReader in) {
        int first = in.readInt();
        int second = in.readInt();
        return Pair.makePair(first, second);
    }

    public static Pair<Long, Long> id19(InputReader in) {
        long first = in.readLong();
        long second = in.readLong();
        return Pair.makePair(first, second);
    }

    public static Pair<Integer, Integer>[] id17(InputReader in, int size) {
        @SuppressWarnings({"unchecked"})
        Pair<Integer, Integer>[] result = new Pair[size];
        for (int i = 0; i < size; i++)
            result[i] = id13(in);
        return result;
    }

    public static Pair<Long, Long>[] id1(InputReader in, int size) {
        @SuppressWarnings({"unchecked"})
        Pair<Long, Long>[] result = new Pair[size];
        for (int i = 0; i < size; i++)
            result[i] = id19(in);
        return result;
    }

    public static void id29(InputReader in, double[]...arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readDouble();
        }
    }

    public static int[][] id11(InputReader in, int rowCount, int columnCount) {
        int[][] table = new int[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id2(in, columnCount);
        return table;
    }

    public static long[][] id3(InputReader in, int rowCount, int columnCount) {
        long[][] table = new long[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id16(in, columnCount);
        return table;
    }

    public static String[][] id32(InputReader in, int rowCount, int columnCount) {
        String[][] table = new String[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id34(in, columnCount);
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

    public static int[] id2(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
    }

    public static void id20(InputReader in, int[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readInt();
        }
    }

    public static char[] id7(InputReader in, int size) {
        char[] array = new char[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readCharacter();
        return array;
    }

    public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
        char[][] table = new char[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id7(in, columnCount);
        return table;
    }

    public static void id24(InputReader in, long[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readLong();
        }
    }

    public static String[] id34(InputReader in, int size) {
        String[] array = new String[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readString();
        return array;
    }

    public static void id25(InputReader in, String[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readString();
        }
    }

    public static String[] id10(InputReader in, int size) {
        String[] array = new String[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readLine();
        return array;
    }

    public static long[] id16(InputReader in, int size) {
        long[] array = new long[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readLong();
        return array;
    }

    public static double[] id5(InputReader in, int size) {
        double[] array = new double[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readDouble();
        return array;
    }
}

class ArrayUtils {
    private static int[] tempInt = new int[0];

    public static int[] createOrder(int size) {
        int[] order = new int[size];
        for (int i = 0; i < size; i++)
            order[i] = i;
        return order;
    }

    public static int[] sort(int[] array, IntComparator comparator) {
        return sort(array, 0, array.length, comparator);
    }

    public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
        new IntArray(array).subList(from, to).id22(comparator);






        return array;
    }

    public static void reverse(int[] array) {
        reverse(array, 0, array.length);
    }

    public static void reverse(double[] array) {
        reverse(array, 0, array.length);
    }

    public static void reverse(int[] array, int from, int to) {
        for (int i = from, j = to - 1; i < j; i++, j--) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    public static void reverse(double[] array, int from, int to) {
        for (int i = from, j = to - 1; i < j; i++, j--) {
            double temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    private static void id0(int size) {
        if (tempInt.length >= size)
            return;
        size = Math.max(size, tempInt.length << 1);
        tempInt = new int[size];
    }

    private static void sortImpl(int[] array, int from, int to, int[] temp, int fromTemp, int toTemp, IntComparator comparator) {
        if (to - from <= 1)
            return;
        int middle = (to - from) >> 1;
        int tempMiddle = fromTemp + middle;
        sortImpl(temp, fromTemp, tempMiddle, array, from, from + middle, comparator);
        sortImpl(temp, tempMiddle, toTemp, array, from + middle, to, comparator);
        int index = from;
        int index1 = fromTemp;
        int index2 = tempMiddle;
        while (index1 < tempMiddle && index2 < toTemp) {
            if (comparator.compare(temp[index1], temp[index2]) <= 0)
                array[index++] = temp[index1++];
            else
                array[index++] = temp[index2++];
        }
        if (index1 != tempMiddle)
            System.arraycopy(temp, index1, array, index, tempMiddle - index1);
        if (index2 != toTemp)
            System.arraycopy(temp, index2, array, index, toTemp - index2);
    }

    public static Integer[] order(int size, Comparator<Integer> comparator) {
        Integer[] order = generateOrder(size);
        Arrays.sort(order, comparator);
        return order;
    }

    public static int[] order(final int[] array) {
        return sort(createOrder(array.length), new IntComparator() {
            public int compare(int first, int second) {
                if (array[first] < array[second])
                    return -1;
                if (array[first] > array[second])
                    return 1;
                return 0;
            }
        });
    }

    public static int[] order(final long[] array) {
        return sort(createOrder(array.length), new IntComparator() {
            public int compare(int first, int second) {
                if (array[first] < array[second])
                    return -1;
                if (array[first] > array[second])
                    return 1;
                return 0;
            }
        });
    }

    public static Integer[] generateOrder(int size) {
        Integer[] order = new Integer[size];
        for (int i = 0; i < size; i++)
            order[i] = i;
        return order;
    }

    public static long sumArray(int[] array) {
        long result = 0;
        for (int element : array)
            result += element;
        return result;
    }

    public static long sumArray(int[] array, int from, int to) {
        long result = 0;
        to = Math.min(to, array.length);
        for (int i = 0; i < to; i++)
            result += array[i];
        return result;
    }

    public static long sumArray(long[] array) {
        long result = 0;
        for (long element : array)
            result += element;
        return result;
    }

    public static long sumArray(long[] array, int from, int to) {
        long result = 0;
        to = Math.min(to, array.length);
        for (int i = 0; i < to; i++)
            result += array[i];
        return result;
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

    public static void fill(int[][] array, int value) {
        for (int[] row : array)
            Arrays.fill(row, value);
    }

    public static void fill(long[][] array, long value) {
        for (long[] row : array)
            Arrays.fill(row, value);
    }

    public static void fill(int[][][] array, int value) {
        for (int[][] subArray : array)
            fill(subArray, value);
    }

    public static void fill(int[][][][] array, int value) {
        for (int[][][] subArray : array)
            fill(subArray, value);
    }

    public static void fillColumn(long[][] array, int index, long value) {
        for (long[] row : array)
            row[index] = value;
    }

    public static void fillColumn(int[][] array, int index, int value) {
        for (int[] row : array)
            row[index] = value;
    }

    public static void fill(boolean[][] array, boolean value) {
        for (boolean[] row : array)
            Arrays.fill(row, value);
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

    


    public static int[] id36(int[] f)
    {
        int[] to = new int[f.length];
        {
            int[] b = new int[65537];
            for(int i = 0;i < f.length;i++)b[1+(f[i]&0xffff)]++;
            for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
            for(int i = 0;i < f.length;i++)to[b[f[i]&0xffff]++] = f[i];
            int[] d = f; f = to;to = d;
        }
        {
            int[] b = new int[65537];
            for(int i = 0;i < f.length;i++)b[1+(f[i]>>>16)]++;
            for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
            for(int i = 0;i < f.length;i++)to[b[f[i]>>>16]++] = f[i];
            int[] d = f; f = to;to = d;
        }
        return f;
    }

    public static void safeSort(int[] array) {
        Collections.shuffle(asList(array));
        Arrays.sort(array);
    }

    private static List<Integer> asList(int[] array) {
        return new IntList(array);
    }

    private static class IntList extends AbstractList<Integer> implements RandomAccess {

        int[] array;

        private IntList(int[] array) {
            this.array = array;
        }

        public Integer get(int index) {
            return array[index];
        }

        public Integer set(int index, Integer element) {
            int result = array[index];
            array[index] = element;
            return result;
        }

        public int size() {
            return array.length;
        }
    }

    public static void safeSort(long[] array) {
        Collections.shuffle(asList(array));
        Arrays.sort(array);
    }

    private static List<Long> asList(long[] array) {
        return new LongList(array);
    }

    private static class LongList extends AbstractList<Long> implements RandomAccess {

        long[] array;

        private LongList(long[] array) {
            this.array = array;
        }

        public Long get(int index) {
            return array[index];
        }

        public Long set(int index, Long element) {
            long result = array[index];
            array[index] = element;
            return result;
        }

        public int size() {
            return array.length;
        }
    }

    public static long[] id14(int[] array) {
        long[] result = new long[array.length + 1];
        for (int i = 0; i < array.length; i++)
            result[i + 1] = result[i] + array[i];
        return result;
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

    public static void orderBy(int[] base, int[]... arrays) {
        int[] order = ArrayUtils.order(base);
        order(order, base);
        for (int[] array : arrays)
            order(order, array);
    }

    public static void order(int[] order, int[] array) {
        id0(order.length);
        for (int i = 0; i < order.length; i++)
            tempInt[i] = array[order[i]];
        System.arraycopy(tempInt, 0, array, 0, array.length);
    }

    public static int[] reversePermutation(int[] permutation) {
        int[] result = new int[permutation.length];
        for (int i = 0; i < permutation.length; i++)
            result[permutation[i]] = i;
        return result;
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

    public static void compress(int[]...arrays) {
        int totalLength = 0;
        for (int[] array : arrays)
            totalLength += array.length;
        int[] all = new int[totalLength];
        int delta = 0;
        for (int[] array : arrays) {
            System.arraycopy(array, 0, all, delta, array.length);
            delta += array.length;
        }
        sort(all, IntComparator.DEFAULT);
        all = unique(all);
        Map<Integer, Integer> map = new id18<Integer, Integer>();
        for (int i = 0; i < all.length; i++)
            map.put(all[i], i);
        for (int[] array : arrays) {
            for (int i = 0; i < array.length; i++)
                array[i] = map.get(array[i]);
        }
    }

    public static boolean id26(int[] p) {
        for (int a = p.length - 2; a >= 0; --a)
            if (p[a] < p[a + 1])
                for (int b = p.length - 1;; --b)
                    if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
        return false;
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

    public static int minElement(int[] array) {
        return minElement(array, 0, array.length);
    }

    public static int minElement(int[] array, int from, int to) {
        int result = Integer.MAX_VALUE;
        for (int i = from; i < to; i++)
            result = Math.min(result, array[i]);
        return result;
    }

    public static long maxElement(long[] array) {
        return maxElement(array, 0, array.length);
    }

    public static long maxElement(long[] array, int from, int to) {
        long result = Long.MIN_VALUE;
        for (int i = from; i < to; i++)
            result = Math.max(result, array[i]);
        return result;
    }

    public static long minElement(long[] array) {
        return minElement(array, 0, array.length);
    }

    public static long minElement(long[] array, int from, int to) {
        long result = Long.MAX_VALUE;
        for (int i = from; i < to; i++)
            result = Math.min(result, array[i]);
        return result;
    }

    public static int[] id21(int count) {
        int[] answer = new int[count];
        for (int i = 0; i < count; i++)
            answer[i] = i;
        return answer;
    }

    public static int count(int[] array, int value) {
        int result = 0;
        for (int i : array) {
            if (i == value)
                result++;
        }
        return result;
    }

    public static int find(int[] array, int value) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == value)
                return i;
        }
        return -1;
    }

    public static int searchLower(int[] array, long value) {
        int count = array.length;

        int left = 0;
        int right = count - 1;

        while (right - left > 1) {
            int mid = (right + left) >> 1;
            if (value <= array[mid])
                right = mid;
            else
                left = mid;
        }

        if (array[right] < value)
            return right;
        else if (array[left] < value)
            return left;
        else
            return -1;
    }

    public static int searchLower(long[] array, long value) {
        int count = array.length;

        int left = 0;
        int right = count - 1;

        while (right - left > 1) {
            int mid = (right + left) >> 1;
            if (value <= array[mid])
                right = mid;
            else
                left = mid;
        }

        if (array[right] < value)
            return right;
        else if (array[left] < value)
            return left;
        else
            return -1;
    }

    public static int id27(int[] array, long value) {
        int count = array.length;

        int left = 0;
        int right = count - 1;

        while (right - left > 1) {
            int mid = (right + left) >> 1;
            if (value < array[mid])
                right = mid;
            else
                left = mid;
        }

        if (array[right] <= value)
            return right;
        else if (array[left] <= value)
            return left;
        else
            return -1;
    }

    public static int id27(long[] array, long value) {
        int count = array.length;

        int left = 0;
        int right = count - 1;

        while (right - left > 1) {
            int mid = (right + left) >> 1;
            if (value < array[mid])
                right = mid;
            else
                left = mid;
        }

        if (array[right] <= value)
            return right;
        else if (array[left] <= value)
            return left;
        else
            return -1;
    }

    public static int searchGreater(int[] array, long value) {
        int count = array.length;

        int left = 0;
        int right = count - 1;

        while (right - left > 1) {
            int mid = (right + left) >> 1;
            if (value < array[mid])
                right = mid;
            else
                left = mid;
        }

        if (array[left] > value)
            return left;
        else if (array[right] > value)
            return right;
        else
            return -1;
    }

    public static int searchGreater(long[] array, long value) {
        int count = array.length;

        int left = 0;
        int right = count - 1;

        while (right - left > 1) {
            int mid = (right + left) >> 1;
            if (value < array[mid])
                right = mid;
            else
                left = mid;
        }

        if (array[left] > value)
            return left;
        else if (array[right] > value)
            return right;
        else
            return -1;
    }

    public static int id28(int[] array, long value) {
        int count = array.length;

        int left = 0;
        int right = count - 1;

        while (right - left > 1) {
            int mid = (right + left) >> 1;
            if (value <= array[mid])
                right = mid;
            else
                left = mid;
        }

        if (array[left] >= value)
            return left;
        else if (array[right] >= value)
            return right;
        else
            return -1;
    }

    public static int id28(long[] array, long value) {
        int count = array.length;

        int left = 0;
        int right = count - 1;

        while (right - left > 1) {
            int mid = (right + left) >> 1;
            if (value <= array[mid])
                right = mid;
            else
                left = mid;
        }

        if (array[left] >= value)
            return left;
        else if (array[right] >= value)
            return right;
        else
            return -1;
    }
}

abstract class IntCollection {
    public abstract IntIterator iterator();
    public abstract int size();
    public abstract void add(int value);

    public int min() {
        if (size() == 0)
            throw new NoSuchElementException();
        int result = Integer.MAX_VALUE;
        for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
            result = Math.min(result, iterator.value());
        return result;
    }

    public int max() {
        if (size() == 0)
            throw new NoSuchElementException();
        int result = Integer.MIN_VALUE;
        for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
            result = Math.max(result, iterator.value());
        return result;
    }

    public int[] toArray() {
        int size = size();
        int[] array = new int[size];
        int i = 0;
        for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
            array[i++] = iterator.value();
        return array;
    }

    public void addAll(IntCollection values) {
        for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
            add(it.value());
        }
    }

    public boolean contains(int value) {
        for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance()) {
            if (iterator.value() == value)
                return true;
        }
        return false;
    }
}

interface IntIterator {
    public int value() throws NoSuchElementException;
    
    public void advance() throws NoSuchElementException;
    public boolean isValid();
}

class Pair<U, V> implements Comparable<Pair<U, V>> {
    public static class Comparator<U extends Comparable<U>, V extends Comparable<V>> implements java.util.Comparator<Pair<U, V>> {
        public int compare(Pair<U, V> o1, Pair<U, V> o2) {
            int result = o1.first.compareTo(o2.first);
            if (result != 0)
                return result;
            return o1.second.compareTo(o2.second);
        }
    }

    public final U first;
    public final V second;

    public static<U, V> Pair<U, V> makePair(U first, V second) {
        return new Pair<U, V>(first, second);
    }

    public Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Pair pair = (Pair) o;

        return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

    }

    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }

    public String toString() {
        return "(" + first + "," + second + ")";
    }

    public int compareTo(Pair<U, V> o) {
        int value = ((Comparable<U>)first).compareTo(o.first);
        if (value != 0)
            return value;
        return ((Comparable<V>)second).compareTo(o.second);
    }
}

interface IntComparator {
    public static final IntComparator DEFAULT = new IntComparator() {
        public int compare(int first, int second) {
            if (first < second)
                return -1;
            if (first > second)
                return 1;
            return 0;
        }
    };

    public static final IntComparator REVERSE = new IntComparator() {
        public int compare(int first, int second) {
            if (first < second)
                return 1;
            if (first > second)
                return -1;
            return 0;
        }
    };

    public int compare(int first, int second);
}

abstract class IntList extends IntCollection implements Comparable<IntList> {
    private static final int id30 = 8;

    public abstract int get(int index);
    public abstract void set(int index, int value);

    public IntIterator iterator() {
        return new IntIterator() {
            private int size = size();
            private int index = 0;

            public int value() throws NoSuchElementException {
                if (!isValid())
                    throw new NoSuchElementException();
                return get(index);
            }

            public void advance() throws NoSuchElementException {
                if (!isValid())
                    throw new NoSuchElementException();
                index++;
            }

            public boolean isValid() {
                return index < size;
            }
        };
    }

    public IntList subList(final int from, final int to) {
        return new SubList(from, to);
    }

    private void swap(int first, int second) {
        if (first == second)
            return;
        int temp = get(first);
        set(first, get(second));
        set(second, temp);
    }

    public id31 id22() {
        return id22(IntComparator.DEFAULT);
    }

    public id31 id22(IntComparator comparator) {
        quickSort(0, size() - 1, size(), comparator);
        return new id15(this, comparator);
    }

    private void quickSort(int from, int to, int remaining, IntComparator comparator) {
        if (to - from < id30) {
            id12(from, to, comparator);
            return;
        }
        if (remaining == 0) {
            heapSort(from, to, comparator);
            return;
        }
        remaining >>= 1;
        int pivotIndex = (from + to) >> 1;
        int pivot = get(pivotIndex);
        swap(pivotIndex, to);
        int storeIndex = from;
        int equalIndex = to;
        for (int i = from; i < equalIndex; i++) {
            int value = comparator.compare(get(i), pivot);
            if (value < 0)
                swap(storeIndex++, i);
            else if (value == 0)
                swap(--equalIndex, i--);
        }
        quickSort(from, storeIndex - 1, remaining, comparator);
        for (int i = equalIndex; i <= to; i++)
            swap(storeIndex++, i);
        quickSort(storeIndex, to, remaining, comparator);
    }

    private void heapSort(int from, int to, IntComparator comparator) {
        for (int i = (to + from - 1) >> 1; i >= from; i--)
            id4(i, to, comparator, from);
        for (int i = to; i > from; i--) {
            swap(from, i);
            id4(from, i - 1, comparator, from);
        }
    }

    private void id4(int start, int end, IntComparator comparator, int delta) {
        int value = get(start);
        while (true) {
            int child = ((start - delta) << 1) + 1 + delta;
            if (child > end)
                return;
            int childValue = get(child);
            if (child + 1 <= end) {
                int otherValue = get(child + 1);
                if (comparator.compare(otherValue, childValue) > 0) {
                    child++;
                    childValue = otherValue;
                }
            }
            if (comparator.compare(value, childValue) >= 0)
                return;
            swap(start, child);
            start = child;
        }
    }

    private void id12(int from, int to, IntComparator comparator) {
        for (int i = from + 1; i <= to; i++) {
            int value = get(i);
            for (int j = i - 1; j >= from; j--) {
                if (comparator.compare(get(j), value) <= 0)
                    break;
                swap(j, j + 1);
            }
        }
    }

    public int hashCode() {
        int hashCode = 1;
        for (IntIterator i = iterator(); i.isValid(); i.advance())
            hashCode = 31 * hashCode + i.value();
        return hashCode;
    }

    public boolean equals(Object obj) {
        if (!(obj instanceof IntList))
            return false;
        IntList list = (IntList)obj;
        if (list.size() != size())
            return false;
        IntIterator i = iterator();
        IntIterator j = list.iterator();
        while (i.isValid()) {
            if (i.value() != j.value())
                return false;
            i.advance();
            j.advance();
        }
        return true;
    }

    public int compareTo(IntList o) {
        IntIterator i = iterator();
        IntIterator j = o.iterator();
        while (true) {
            if (i.isValid()) {
                if (j.isValid()) {
                    if (i.value() != j.value()) {
                        if (i.value() < j.value())
                            return -1;
                        else
                            return 1;
                    }
                } else
                    return 1;
            } else {
                if (j.isValid())
                    return -1;
                else
                    return 0;
            }
            i.advance();
            j.advance();
        }
    }

    public id31 sort(IntComparator comparator) {
        return new IntArray(this).id22(comparator);
    }

    private class SubList extends IntList {
        private final int to;
        private final int from;
        private int size;

        public SubList(int from, int to) {
            this.to = to;
            this.from = from;
            size = to - from;
        }

        public int get(int index) {
            if (index < 0 || index >= size)
                throw new IndexOutOfBoundsException();
            return IntList.this.get(index + from);
        }

        public void set(int index, int value) {
            if (index < 0 || index >= size)
                throw new IndexOutOfBoundsException();
            IntList.this.set(index + from, value);
        }

        public int size() {
            return size;
        }

        @Override
        public void add(int value) {
            throw new UnsupportedOperationException();
            

        }

    }


    public int popBack() {
        throw new UnsupportedOperationException();
    }
}

abstract class id31 extends IntList {
    protected final IntComparator comparator;

    protected id31(IntComparator comparator) {
        this.comparator = comparator;
    }

    public void set(int index, int value) {
        throw new UnsupportedOperationException();
    }

    public void add(int value) {
        throw new UnsupportedOperationException();
    }

    public id31 id22(IntComparator comparator) {
        if (comparator == this.comparator)
            return this;
        throw new UnsupportedOperationException();
    }

    public id31 sort(IntComparator comparator) {
        if (comparator == this.comparator)
            return this;
        return super.sort(comparator);
    }

    protected void ensureSorted() {
        int size = size();
        if (size == 0)
            return;
        int last = get(0);
        for (int i = 1; i < size; i++) {
            int current = get(i);
            if (comparator.compare(last, current) > 0)
                throw new IllegalArgumentException();
            last = current;
        }
    }

    public id31 subList(final int from, final int to) {
        return new id31(comparator) {
            private int size = to - from;

            @Override
            public int get(int index) {
                if (index < 0 || index >= size)
                    throw new IndexOutOfBoundsException();
                return id31.this.get(index + from);
            }

            @Override
            public int size() {
                return size;
            }

            public void add(int value) {
                

            }
        };
    }
}

class IntArray extends IntList {
    private final int[] array;

    public IntArray(int[] array) {
        this.array = array;
    }

    public IntArray(IntCollection collection) {
        array = new int[collection.size()];
        int i = 0;
        for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance())
            array[i++] = iterator.value();
    }

    public int get(int index) {
        return array[index];
    }

    public void set(int index, int value) {
        array[index] = value;
    }

    public int size() {
        return array.length;
    }

    public void add(int value) {
        throw new UnsupportedOperationException();
    }

    public int[] toArray() {
        return array;
    }
}

class id18<E, V> extends AbstractMap<E, V> {
    private static final int[] shifts = new int[10];

    private int size;
    private Object[] keys;
    private Object[] values;
    private int capacity;
    private int shift;
    private int[] indices;
    private Set<Entry<E, V>> entrySet;

    static {
        Random random = new Random(System.currentTimeMillis());
        for (int i = 0; i < 10; i++)
            shifts[i] = 1 + 3 * i + random.nextInt(3);
    }

    public id18() {
        this(4);
    }

    private void setCapacity(int size) {
        capacity = Integer.highestOneBit(10 * size);
        keys = new Object[capacity];
        values = new Object[capacity];
        shift = capacity / 3 - 1;
        shift -= 1 - (shift & 1);
        indices = new int[capacity];
    }

    public id18(int maxSize) {
        setCapacity(maxSize);
        entrySet = new AbstractSet<Entry<E, V>>() {
            @Override
            public Iterator<Entry<E, V>> iterator() {
                return new Iterator<Entry<E, V>>() {
                    private HashEntry entry = new HashEntry();
                    int index = 0;

                    public boolean hasNext() {
                        while (index < size && keys[index] == null)
                            index++;
                        return index < size;
                    }

                    public Entry<E, V> next() {
                        if (!hasNext())
                            throw new NoSuchElementException();
                        entry.key = (E) keys[index];
                        entry.value = (V) values[index++];
                        return entry;
                    }

                    public void remove() {
                        if (entry.key == null)
                            throw new IllegalStateException();
                        id18.this.remove(entry.key);
                        entry.key = null;
                        entry.value = null;
                    }
                };
            }

            @Override
            public int size() {
                return size;
            }
        };
    }

    public id18(Map<E, V> map) {
        this(map.size());
        putAll(map);
    }

    public Set<Entry<E, V>> entrySet() {
        return entrySet;
    }

    public void clear() {
        Arrays.fill(keys, null);
        Arrays.fill(values, null);
        size = 0;
    }

    private int index(Object o) {
        return getHash(o.hashCode()) & (capacity - 1);
    }

    private int getHash(int h) {
        int result = h;
        for (int i : shifts)
            result ^= h >>> i;
        return result;
    }

    public V remove(Object o) {
        if (o == null)
            return null;
        int index = index(o);
        int indicesSize = 0;
        while (keys[index] != null && !keys[index].equals(o)) {
            indices[indicesSize++] = index;
            index = (index + shift) & (capacity - 1);
        }
        if (keys[index] == null)
            return null;
        size--;
        int lastIndex = indicesSize;
        indices[indicesSize++] = index;
        keys[index] = null;
        V result = (V) values[index];
        values[index] = null;
        index = (index + shift) & (capacity - 1);
        while (keys[index] != null) {
            int curKey = index(keys[index]);
            for (int i = 0; i <= lastIndex; i++) {
                if (indices[i] == curKey) {
                    keys[indices[lastIndex]] = keys[index];
                    values[indices[lastIndex]] = values[index];
                    keys[index] = null;
                    values[index] = null;
                    lastIndex = indicesSize;
                }
            }
            indices[indicesSize++] = index;
            index = (index + shift) & (capacity - 1);
        }
        return result;
    }

    public V put(E e, V value) {
        if (e == null)
            return null;
        int index = index(e);
        while (keys[index] != null && !keys[index].equals(e))
            index = (index + shift) & (capacity - 1);
        if (keys[index] == null)
            size++;
        keys[index] = e;
        values[index] = value;
        if (size * 2 > capacity) {
            Object[] oldKeys = keys;
            Object[] oldValues = values;
            setCapacity(size);
            size = 0;
            for (int i = 0; i < oldKeys.length; i++) {
                if (oldKeys[i] != null)
                    put((E) oldKeys[i], (V) oldValues[i]);
            }
        }
        return value;
    }

    public V get(Object o) {
        if (o == null)
            return null;
        int index = index(o);
        while (keys[index] != null && !keys[index].equals(o))
            index = (index + shift) & (capacity - 1);
        return (V) values[index];
    }

    public boolean containsKey(Object o) {
        if (o == null)
            return false;
        int index = index(o);
        while (keys[index] != null && !keys[index].equals(o))
            index = (index + shift) & (capacity - 1);
        return keys[index] != null;
    }

    public int size() {
        return size;
    }

    private class HashEntry implements Entry<E, V> {
        private E key;
        private V value;

        public E getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public V setValue(V value) {
            put(key, value);
            return this.value = value;
        }
    }
}

class id15 extends id31 {
    private final int[] array;

    public id15(int[] array) {
        this(array, IntComparator.DEFAULT);
    }

    public id15(IntCollection collection) {
        this(collection, IntComparator.DEFAULT);
    }

    public id15(int[] array, IntComparator comparator) {
        super(comparator);
        this.array = array;
        ensureSorted();
    }

    public id15(IntCollection collection, IntComparator comparator) {
        super(comparator);
        array = new int[collection.size()];
        int i = 0;
        for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance())
            array[i++] = iterator.value();
        ensureSorted();
    }

    public int get(int index) {
        return array[index];
    }

    public int size() {
        return array.length;
    }
}
