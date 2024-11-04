import java.io.*;
import java.util.*;
import java.util.Map.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        Task solver = new B();
        solver.solve(1, in, out);
        out.close();
    }
}

interface Task {
    public void solve(int testNumber, InputReader in, OutputWriter out);
}

class A implements Task {
    
    int[] arr;
    
    public void solve(int testNumber, InputReader in, OutputWriter out){
        int n=in.readInt(), k=in.readInt(), ret=0;
        arr=IOUtils.id2(in, n);
        Arrays.sort(arr);
        for (int i=2; i<n; i+=3) if (arr[i]+k<=5) ret++;
        out.printLine(ret);
    }
    
}

class B implements Task {
    
    int[] arr=new int[100010];
    Pair<Integer, Integer>[] lista;
    
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n=in.readInt();
        lista=IOUtils.id13(in, n);
        for (int i=0; i<n; i++) arr[lista[i].first]++;
        for (int i=0; i<n; i++) out.printLine(n-1+arr[lista[i].second], n-1-arr[lista[i].second]);
    }
    
}

class C implements Task {
    
    public void solve(int testNumber, InputReader in, OutputWriter out){
        
    }
    
}

class D implements Task {
    
    public void solve(int testNumber, InputReader in, OutputWriter out){
        
    }
    
}

class E implements Task {
    
    public void solve(int testNumber, InputReader in, OutputWriter out){
        
    }
    
}

class F implements Task {
    
    public void solve (int testNumber, InputReader in, OutputWriter out) {
        
    }
    
}

interface Filter<T> {
    public boolean accept(T value);
}

interface Function<A, V> {
    public abstract V value(A argument);
}

class CollectionUtils {
    public static int[] toArray(Collection<Integer> collection) {
        int[] array = new int[collection.size()];
        int index = 0;
        for (int element : collection)
            array[index++] = element;
        return array;
    }

    public static List<Integer> range(int from, int to) {
        List<Integer> result = new ArrayList<Integer>(Math.max(from, to) - Math.min(from, to) + 1);
        if (to > from) {
            for (int i = from; i <= to; i++)
                result.add(i);
        } else {
            for (int i = from; i >= to; i--)
                result.add(i);
        }
        return result;
    }

    public static void rotate(List<Integer> list) {
        list.add(list.remove(0));
    }

    public static<T extends Comparable<T>> T minElement(Iterable<T> collection) {
        T result = null;
        for (T element : collection) {
            if (result == null || result.compareTo(element) > 0)
                result = element;
        }
        return result;
    }

    public static<T extends Comparable<T>> T maxElement(Iterable<T> collection) {
        T result = null;
        for (T element : collection) {
            if (result == null || result.compareTo(element) < 0)
                result = element;
        }
        return result;
    }

    public static<T> T minElement(Iterable<T> collection, Comparator<T> comparator) {
        T result = null;
        for (T element : collection) {
            if (result == null || comparator.compare(result, element) > 0)
                result = element;
        }
        return result;
    }

    public static<T> T maxElement(Iterable<T> collection, Comparator<T> comparator) {
        T result = null;
        for (T element : collection) {
            if (result == null || comparator.compare(result, element) < 0)
                result = element;
        }
        return result;
    }

    public static<T> List<T> asList(Iterable<T> iterable) {
        List<T> list = new ArrayList<T>();
        for (T element : iterable)
            list.add(element);
        return list;
    }

    public static<T> int count(Iterable<T> array, T sample) {
        int result = 0;
        for (T element : array) {
            if (element.equals(sample))
                result++;
        }
        return result;
    }

    public static<T> int count(Iterable<T> array, Filter<T> filter) {
        int result = 0;
        for (T element : array) {
            if (filter.accept(element))
                result++;
        }
        return result;
    }

    public static<T> List<T> filter(Iterable<T> sequence, Filter<T> filter) {
        List<T> result = new ArrayList<T>();
        for (T element : sequence) {
            if (filter.accept(element))
                result.add(element);
        }
        return result;
    }

    public static<A, V> List<V> apply(Iterable<A> sequence, Function<A, V> function) {
        List<V> result = new ArrayList<V>();
        for (A element : sequence)
            result.add(function.value(element));
        return result;
    }
    
    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
    
}

class Pair<U, V> implements Comparable<Pair<U, V>> {
    public final U first;
    public final V second;

    public static<U, V> Pair<U, V> makePair(U first, V second) {
        return new Pair<U, V>(first, second);
    }

    private Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Pair pair = (Pair) o;

        return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

    }

    @Override
    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }

    public Pair<V, U> swap() {
        return makePair(second, first);
    }

    @Override
    public String toString() {
        return "(" + first + "," + second + ")";
    }

    @SuppressWarnings({"unchecked"})
    public int compareTo(Pair<U, V> o) {
        int value = ((Comparable<U>)first).compareTo(o.first);
        if (value != 0)
            return value;
        return ((Comparable<V>)second).compareTo(o.second);
    }
}

abstract class id12<T> implements Iterator<T>  {
    public final void remove() {
        throw new UnsupportedOperationException();
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id23 filter;

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
        while (id8(c))
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
        } while (!id8(c));
        return res * sgn;
    }

    public long readLong() {
        int c = read();
        while (id8(c))
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
        } while (!id8(c));
        return res * sgn;
    }

    public String readString() {
        int c = read();
        while (id8(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            if (Character.isValidCodePoint(c))
                res.appendCodePoint(c);
            c = read();
        } while (!id8(c));
        return res.toString();
    }

    public boolean id8(int c) {
        if (filter != null)
            return filter.id8(c);
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

    public String readLine(boolean id21) {
        if (id21)
            return readLine();
        else
            return id5();
    }

    public BigInteger id16() {
        try {
            return new BigInteger(readString());
        } catch (NumberFormatException e) {
            throw new InputMismatchException();
        }
    }

    public char readCharacter() {
        int c = read();
        while (id8(c))
            c = read();
        return (char) c;
    }

    public double readDouble() {
        int c = read();
        while (id8(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!id8(c) && c != '.') {
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
            while (!id8(c)) {
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

    public boolean id7() {
        int value;
        while (id8(value = peek()) && value != -1)
            read();
        return value == -1;
    }

    public String next() {
        return readString();
    }

    public id23 getFilter() {
        return filter;
    }

    public void setFilter(id23 filter) {
        this.filter = filter;
    }

    public interface id23 {
        public boolean id8(int ch);
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

    public void print(char[] array) {
        writer.print(array);
    }

    public void print(Object...objects) {
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

    public void printLine(Object...objects) {
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

    public void printFormat(String format, Object...objects) {
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
    public static Pair<Integer, Integer> id10(InputReader in) {
        int first = in.readInt();
        int second = in.readInt();
        return Pair.makePair(first, second);
    }

    public static Pair<Long, Long> id14(InputReader in) {
        long first = in.readLong();
        long second = in.readLong();
        return Pair.makePair(first, second);
    }

    public static int[] id2(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
    }

    public static long[] id11(InputReader in, int size) {
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

    public static String[] id22(InputReader in, int size) {
        String[] array = new String[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readString();
        return array;
    }

    public static char[] id6(InputReader in, int size) {
        char[] array = new char[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readCharacter();
        return array;
    }

    public static Pair<Integer, Integer>[] id13(InputReader in, int size) {
        @SuppressWarnings({"unchecked"})
        Pair<Integer, Integer>[] result = new Pair[size];
        for (int i = 0; i < size; i++)
            result[i] = id10(in);
        return result;
    }

    public static Pair<Long, Long>[] id0(InputReader in, int size) {
        @SuppressWarnings({"unchecked"})
        Pair<Long, Long>[] result = new Pair[size];
        for (int i = 0; i < size; i++)
            result[i] = id14(in);
        return result;
    }

    public static void id15(InputReader in, int[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readInt();
        }
    }

    public static void id17(InputReader in, long[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readLong();
        }
    }

    public static void id19(InputReader in, double[]...arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readDouble();
        }
    }

    public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
        char[][] table = new char[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id6(in, columnCount);
        return table;
    }

    public static int[][] id9(InputReader in, int rowCount, int columnCount) {
        int[][] table = new int[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id2(in, columnCount);
        return table;
    }

    public static double[][] id1(InputReader in, int rowCount, int columnCount) {
        double[][] table = new double[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id4(in, columnCount);
        return table;
    }

    public static long[][] id3(InputReader in, int rowCount, int columnCount) {
        long[][] table = new long[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id11(in, columnCount);
        return table;
    }

    public static String[][] id20(InputReader in, int rowCount, int columnCount) {
        String[][] table = new String[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id22(in, columnCount);
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

    public static void id18(InputReader in, String[]... arrays) {
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