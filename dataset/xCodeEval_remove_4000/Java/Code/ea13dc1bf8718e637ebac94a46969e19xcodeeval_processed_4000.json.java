import java.io.*;
import java.util.*;
import java.math.*;

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

class id54 {

    public static List<List<Integer>> scc(List<Integer>[] graph) {
        int n = graph.length;
        boolean[] used = new boolean[n];
        List<Integer> order = new ArrayList<>();
        for (int i = 0; i < n; i++)
            if (!used[i])
                dfs(graph, used, order, i);

        List<Integer>[] reverseGraph = new List[n];
        for (int i = 0; i < n; i++)
            reverseGraph[i] = new ArrayList<>();
        for (int i = 0; i < n; i++)
            for (int j : graph[i])
                reverseGraph[j].add(i);

        List<List<Integer>> components = new ArrayList<>();
        Arrays.fill(used, false);
        Collections.reverse(order);

        for (int u : order)
            if (!used[u]) {
                List<Integer> component = new ArrayList<>();
                dfs(reverseGraph, used, component, u);
                components.add(component);
            }

        return components;
    }

    static void dfs(List<Integer>[] graph, boolean[] used, List<Integer> res,
            int u) {
        used[u] = true;
        for (int v : graph[u])
            if (!used[v])
                dfs(graph, used, res, v);
        res.add(u);
    }

    

    public static void main(String[] args) {
        List<Integer>[] g = new List[3];
        for (int i = 0; i < g.length; i++)
            g[i] = new ArrayList<>();

        g[2].add(0);
        g[2].add(1);
        g[0].add(1);
        g[1].add(0);

        List<List<Integer>> components = scc(g);
        System.out.println(components);
    }
}

class Task {

    int[] arr, rev;
    boolean[] vis;
    List<Integer>[] adjl;
    Graph graph;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt(), m = in.readInt(), ret = n, M = m;
        adjl = new List[n];
        arr = new int[n];
        rev = new int[n];
        vis = new boolean[n];
        for (int i=0; i<n; i++) adjl[i]=new ArrayList<Integer>();
        while (m-->0) {
            int a=in.readInt()-1, b=in.readInt()-1;
            adjl[a].add(b);
        }
        List<List<Integer>> list=id54.scc(adjl);


        {
            for (int i=0; i<list.size(); i++) {


                for (int j: list.get(i)) arr[j]=i;
            }
            graph = new Graph(list.size());
            for (int i=0; i<n; i++) if (!vis[i]) makeGraph(i);
            n = graph.vertexCount();
            rev = new int[n];
            

            for (int i: arr) rev[i]++;
            

            Arrays.fill(vis, false);
            for (int i = 0; i < n; i++)
                if (!vis[i]) {
                    ret -= dfs(i);


                }
            out.printLine(ret);
        }
    }
    
    void makeGraph(int u) {
        vis[u]=true;
        for (int v: adjl[u]) {
            graph.id36(arr[u], arr[v]);
            if (!vis[v]) makeGraph(v);
        }
    }

    int dfs(int u) {
        

        int ret = rev[u] == 1 ? 1 : 0;
        vis[u] = true;
        for (int i = graph.firstOutbound(u); i != -1; i = graph.nextOutbound(i)) {
            int v = graph.destination(i);
            if (!vis[v])
                ret &= dfs(v);
        }
        for (int i = graph.firstInbound(u); i != -1; i = graph.nextInbound(i)) {
            int v = graph.source(i);
            if (!vis[v])
                ret &= dfs(v);
        }
        return ret;
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id56 filter;

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
        while (id15(c))
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
        } while (!id15(c));
        return res * sgn;
    }

    public long readLong() {
        int c = read();
        while (id15(c))
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
        } while (!id15(c));
        return res * sgn;
    }

    public String readString() {
        int c = read();
        while (id15(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            if (Character.isValidCodePoint(c))
                res.appendCodePoint(c);
            c = read();
        } while (!id15(c));
        return res.toString();
    }

    public boolean id15(int c) {
        if (filter != null)
            return filter.id15(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private String id8() {
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
        String s = id8();
        while (s.trim().length() == 0)
            s = id8();
        return s;
    }

    public String readLine(boolean id50) {
        if (id50)
            return readLine();
        else
            return id8();
    }

    public BigInteger id37() {
        try {
            return new BigInteger(readString());
        } catch (NumberFormatException e) {
            throw new InputMismatchException();
        }
    }

    public char readCharacter() {
        int c = read();
        while (id15(c))
            c = read();
        return (char) c;
    }

    public double readDouble() {
        int c = read();
        while (id15(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!id15(c) && c != '.') {
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
            while (!id15(c)) {
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

    public boolean id13() {
        int value;
        while (id15(value = peek()) && value != -1)
            read();
        return value == -1;
    }

    public String next() {
        return readString();
    }

    public id56 getFilter() {
        return filter;
    }

    public void setFilter(id56 filter) {
        this.filter = filter;
    }

    public interface id56 {
        public boolean id15(int ch);
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

    public static long[] id26(InputReader in, int size) {
        long[] array = new long[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readLong();
        return array;
    }

    public static double[] id7(InputReader in, int size) {
        double[] array = new double[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readDouble();
        return array;
    }

    public static String[] id51(InputReader in, int size) {
        String[] array = new String[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readString();
        return array;
    }

    public static char[] id12(InputReader in, int size) {
        char[] array = new char[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readCharacter();
        return array;
    }

    public static void id31(InputReader in, int[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readInt();
        }
    }

    public static void id38(InputReader in, long[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readLong();
        }
    }

    public static void id45(InputReader in, double[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readDouble();
        }
    }

    public static char[][] readTable(InputReader in, int rowCount,
            int columnCount) {
        char[][] table = new char[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id12(in, columnCount);
        return table;
    }

    public static int[][] id16(InputReader in, int rowCount,
            int columnCount) {
        int[][] table = new int[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id2(in, columnCount);
        return table;
    }

    public static double[][] id0(InputReader in, int rowCount,
            int columnCount) {
        double[][] table = new double[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id7(in, columnCount);
        return table;
    }

    public static long[][] id4(InputReader in, int rowCount,
            int columnCount) {
        long[][] table = new long[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id26(in, columnCount);
        return table;
    }

    public static String[][] id48(InputReader in, int rowCount,
            int columnCount) {
        String[][] table = new String[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id51(in, columnCount);
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

    public static void id39(InputReader in, String[]... arrays) {
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

class id29 extends id44 {
    public id29(int size) {
        super(size);
    }

    @Override
    protected long joinValue(long left, long right) {
        return left + right;
    }

    @Override
    protected long joinDelta(long was, long delta) {
        return was + delta;
    }

    @Override
    protected long accumulate(long value, long delta, int length) {
        return value + delta * length;
    }

    @Override
    protected long neutralValue() {
        return 0;
    }

    @Override
    protected long neutralDelta() {
        return 0;
    }
}

abstract class IntervalTree {
    protected int size;

    protected IntervalTree(int size) {
        this(size, true);
    }

    public IntervalTree(int size, boolean shouldInit) {
        this.size = size;
        int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
        initData(size, nodeCount);
        if (shouldInit)
            init();
    }

    protected abstract void initData(int size, int nodeCount);

    protected abstract void initAfter(int root, int left, int right, int middle);

    protected abstract void initBefore(int root, int left, int right, int middle);

    protected abstract void initLeaf(int root, int index);

    protected abstract void id11(int root, int left, int right,
            int from, int to, long delta, int middle);

    protected abstract void id27(int root, int left, int right,
            int from, int to, long delta, int middle);

    protected abstract void updateFull(int root, int left, int right, int from,
            int to, long delta);

    protected abstract long id18(int root, int left, int right,
            int from, int to, int middle, long leftResult, long rightResult);

    protected abstract void id22(int root, int left, int right,
            int from, int to, int middle);

    protected abstract long queryFull(int root, int left, int right, int from,
            int to);

    protected abstract long id1();

    public void init() {
        if (size == 0)
            return;
        init(0, 0, size - 1);
    }

    private void init(int root, int left, int right) {
        if (left == right) {
            initLeaf(root, left);
        } else {
            int middle = (left + right) >> 1;
            initBefore(root, left, right, middle);
            init(2 * root + 1, left, middle);
            init(2 * root + 2, middle + 1, right);
            initAfter(root, left, right, middle);
        }
    }

    public void update(int from, int to, long delta) {
        update(0, 0, size - 1, from, to, delta);
    }

    protected void update(int root, int left, int right, int from, int to,
            long delta) {
        if (left > to || right < from)
            return;
        if (left >= from && right <= to) {
            updateFull(root, left, right, from, to, delta);
            return;
        }
        int middle = (left + right) >> 1;
        id27(root, left, right, from, to, delta, middle);
        update(2 * root + 1, left, middle, from, to, delta);
        update(2 * root + 2, middle + 1, right, from, to, delta);
        id11(root, left, right, from, to, delta, middle);
    }

    public long query(int from, int to) {
        return query(0, 0, size - 1, from, to);
    }

    protected long query(int root, int left, int right, int from, int to) {
        if (left > to || right < from)
            return id1();
        if (left >= from && right <= to)
            return queryFull(root, left, right, from, to);
        int middle = (left + right) >> 1;
        id22(root, left, right, from, to, middle);
        long leftResult = query(2 * root + 1, left, middle, from, to);
        long rightResult = query(2 * root + 2, middle + 1, right, from, to);
        return id18(root, left, right, from, to, middle,
                leftResult, rightResult);
    }
}

abstract class id44 extends IntervalTree {
    protected long[] value;
    protected long[] delta;

    protected id44(int size) {
        this(size, true);
    }

    public id44(int size, boolean shouldInit) {
        super(size, shouldInit);
    }

    @Override
    protected void initData(int size, int nodeCount) {
        value = new long[nodeCount];
        delta = new long[nodeCount];
    }

    protected abstract long joinValue(long left, long right);

    protected abstract long joinDelta(long was, long delta);

    protected abstract long accumulate(long value, long delta, int length);

    protected abstract long neutralValue();

    protected abstract long neutralDelta();

    protected long initValue(int index) {
        return neutralValue();
    }

    @Override
    protected void initAfter(int root, int left, int right, int middle) {
        value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
        delta[root] = neutralDelta();
    }

    @Override
    protected void initBefore(int root, int left, int right, int middle) {
    }

    @Override
    protected void initLeaf(int root, int index) {
        value[root] = initValue(index);
        delta[root] = neutralDelta();
    }

    @Override
    protected void id11(int root, int left, int right, int from,
            int to, long delta, int middle) {
        value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
    }

    @Override
    protected void id27(int root, int left, int right, int from,
            int to, long delta, int middle) {
        pushDown(root, left, middle, right);
    }

    protected void pushDown(int root, int left, int middle, int right) {
        value[2 * root + 1] = accumulate(value[2 * root + 1], delta[root],
                middle - left + 1);
        value[2 * root + 2] = accumulate(value[2 * root + 2], delta[root],
                right - middle);
        delta[2 * root + 1] = joinDelta(delta[2 * root + 1], delta[root]);
        delta[2 * root + 2] = joinDelta(delta[2 * root + 2], delta[root]);
        delta[root] = neutralDelta();
    }

    @Override
    protected void updateFull(int root, int left, int right, int from, int to,
            long delta) {
        value[root] = accumulate(value[root], delta, right - left + 1);
        this.delta[root] = joinDelta(this.delta[root], delta);
    }

    @Override
    protected long id18(int root, int left, int right, int from,
            int to, int middle, long leftResult, long rightResult) {
        return joinValue(leftResult, rightResult);
    }

    @Override
    protected void id22(int root, int left, int right, int from,
            int to, int middle) {
        pushDown(root, left, middle, right);
    }

    @Override
    protected long queryFull(int root, int left, int right, int from, int to) {
        return value[root];
    }

    @Override
    protected long id1() {
        return neutralValue();
    }
}

class IntPair implements Comparable<IntPair> {
    public final int first, second;

    public IntPair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public String toString() {
        return "(" + first + "," + second + ")";
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;

        IntPair intPair = (IntPair) o;

        return first == intPair.first && second == intPair.second;

    }

    @Override
    public int hashCode() {
        int result = first;
        result = 31 * result + second;
        return result;
    }

    public int compareTo(IntPair o) {
        if (first < o.first)
            return -1;
        if (first > o.first)
            return 1;
        if (second < o.second)
            return -1;
        if (second > o.second)
            return 1;
        return 0;
    }
}

class Matrix {
    public static long mod = Long.MAX_VALUE;
    public final long[][] data;
    public final int rowCount;
    public final int columnCount;

    public Matrix(int rowCount, int columnCount) {
        this.rowCount = rowCount;
        this.columnCount = columnCount;
        this.data = new long[rowCount][columnCount];
    }

    public Matrix(long[][] data) {
        this.rowCount = data.length;
        this.columnCount = data[0].length;
        this.data = data;
    }

    public static Matrix add(Matrix first, Matrix second) {
        Matrix result = new Matrix(first.rowCount, first.columnCount);
        for (int i = 0; i < result.rowCount; i++) {
            for (int j = 0; j < result.columnCount; j++) {
                result.data[i][j] = first.data[i][j] + second.data[i][j];
                if (result.data[i][j] >= mod)
                    result.data[i][j] -= mod;
            }
        }
        return result;
    }

    public static Matrix multiply(Matrix first, Matrix second) {
        Matrix result = new Matrix(first.rowCount, second.columnCount);
        for (int i = 0; i < first.rowCount; i++) {
            for (int j = 0; j < second.rowCount; j++) {
                for (int k = 0; k < second.columnCount; k++)
                    result.data[i][k] = (result.data[i][k] + first.data[i][j]
                            * second.data[j][k])
                            % mod;
            }
        }
        return result;
    }

    public static Matrix fastMultiply(Matrix first, Matrix second) {
        Matrix result = new Matrix(first.rowCount, second.columnCount);
        for (int i = 0; i < first.rowCount; i++) {
            for (int j = 0; j < second.rowCount; j++) {
                for (int k = 0; k < second.columnCount; k++)
                    result.data[i][k] += first.data[i][j] * second.data[j][k];
            }
        }
        for (int i = 0; i < first.rowCount; i++) {
            for (int j = 0; j < second.columnCount; j++)
                result.data[i][j] %= mod;
        }
        return result;
    }

    public static Matrix identityMatrix(int size) {
        Matrix result = new Matrix(size, size);
        for (int i = 0; i < size; i++)
            result.data[i][i] = 1;
        return result;
    }

    public static long[] convert(long[][] matrix) {
        long[] result = new long[matrix.length * matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++)
                result[i * matrix.length + j] = matrix[i][j];
        }
        return result;
    }

    public static long[] id53(long[] matrix, long exponent, long mod,
            int side) {
        long[] result = new long[matrix.length];
        long[] power = new long[matrix.length];
        long[] temp = new long[matrix.length];
        long[] temp2 = new long[matrix.length];
        id53(matrix, result, power, temp, temp2, exponent + 1, mod, side);
        return result;
    }

    private static void id53(long[] matrix, long[] result, long[] power,
            long[] temp, long[] temp2, long exponent, long mod, int side) {
        if (exponent == 0) {
            for (int i = 0; i < matrix.length; i += side + 1)
                power[i] = 1 % mod;
            return;
        }
        if ((exponent & 1) == 0) {
            id53(matrix, result, temp, power, temp2, exponent >> 1, mod,
                    side);
            multiply(temp2, result, temp, mod, side);
            add(result, temp2, mod, side);
            multiply(power, temp, temp, mod, side);
        } else {
            id53(matrix, result, temp, power, temp2, exponent - 1, mod,
                    side);
            add(result, temp, mod, side);
            multiply(power, temp, matrix, mod, side);
        }
    }

    public static long[][] convert(long[] matrix, int side) {
        long[][] result = new long[side][side];
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++)
                result[i][j] = matrix[i * side + j];
        }
        return result;
    }

    public static long[] power(long[] matrix, long exponent, long mod, int side) {
        long[] result = new long[matrix.length];
        long[] temp = new long[result.length];
        power(matrix, result, temp, exponent, mod, side);
        return result;
    }

    private static void power(long[] matrix, long[] result, long[] temp,
            long exponent, long mod, int side) {
        if (exponent == 0) {
            for (int i = 0; i < matrix.length; i += side + 1)
                result[i] = 1 % mod;
            return;
        }
        if ((exponent & 1) == 0) {
            power(matrix, temp, result, exponent >> 1, mod, side);
            multiply(result, temp, temp, mod, side);
        } else {
            power(matrix, temp, result, exponent - 1, mod, side);
            multiply(result, temp, matrix, mod, side);
        }
    }

    public static void multiply(long[] c, long[] a, long[] b, long mod, int side) {
        Arrays.fill(c, 0);
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++) {
                for (int k = 0; k < side; k++) {
                    c[i * side + k] += a[i * side + j] * b[j * side + k];
                    if ((j & 3) == 3) {
                        c[i * side + k] %= mod;
                    }
                }
            }
        }
        for (int i = 0; i < c.length; i++)
            c[i] %= mod;
    }

    public static void add(long[] c, long[] a, long mod, int side) {
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++) {
                c[i * side + j] += a[i * side + j];
                if (c[i * side + j] >= mod)
                    c[i * side + j] -= mod;
            }
        }
    }

    public static long[] fastPower(long[] matrix, long exponent, long mod,
            int side) {
        long[] result = new long[matrix.length];
        long[] temp = new long[result.length];
        fastPower(matrix, result, temp, exponent, mod, side);
        return result;
    }

    private static void fastPower(long[] matrix, long[] result, long[] temp,
            long exponent, long mod, int side) {
        if (exponent == 0) {
            for (int i = 0; i < matrix.length; i += side + 1)
                result[i] = 1;
            return;
        }
        if ((exponent & 1) == 0) {
            fastPower(matrix, temp, result, exponent >> 1, mod, side);
            fastMultiply(result, temp, temp, mod, side);
        } else {
            power(matrix, temp, result, exponent - 1, mod, side);
            fastMultiply(result, temp, matrix, mod, side);
        }
    }

    public static void fastMultiply(long[] c, long[] a, long[] b, long mod,
            int side) {
        Arrays.fill(c, 0);
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++) {
                for (int k = 0; k < side; k++)
                    c[i * side + k] += a[i * side + j] * b[j * side + k];
            }
        }
        for (int i = 0; i < c.length; i++)
            c[i] %= mod;
    }

    public Matrix power(long exponent) {
        if (exponent == 0)
            return identityMatrix(rowCount);
        if (exponent == 1)
            return this;
        Matrix result = power(exponent >> 1);
        result = multiply(result, result);
        if ((exponent & 1) == 1)
            result = multiply(result, this);
        return result;
    }

    public Matrix fastPower(long exponent) {
        if (exponent == 0)
            return identityMatrix(rowCount);
        if (exponent == 1)
            return this;
        Matrix result = power(exponent >> 1);
        result = fastMultiply(result, result);
        if ((exponent & 1) == 1)
            result = fastMultiply(result, this);
        return result;
    }
}

class MiscUtils {
    public static final int[] DX4 = { 1, 0, -1, 0 };
    public static final int[] DY4 = { 0, -1, 0, 1 };
    public static final int[] DX8 = { 1, 1, 1, 0, -1, -1, -1, 0 };
    public static final int[] DY8 = { -1, 0, 1, 1, 1, 0, -1, -1 };
    public static final int[] id46 = { 2, 1, -1, -2, -2, -1, 1, 2 };
    public static final int[] id20 = { 1, 2, 2, 1, -1, -2, -2, -1 };

    private static final String[] id19 = { "M", "CM", "D", "CD", "C",
            "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    private static final int[] id55 = { 1000, 900, 500, 400, 100, 90,
            50, 40, 10, 9, 5, 4, 1 };

    public static long id10(long n, int k) {
        if (n == 1)
            return 0;
        if (k == 1)
            return n - 1;
        if (k > n)
            return (id10(n - 1, k) + k) % n;
        long count = n / k;
        long result = id10(n - count, k);
        result -= n % k;
        if (result < 0)
            result += n;
        else
            result += result / (k - 1);
        return result;
    }

    public static boolean id57(int row, int column, int rowCount,
            int columnCount) {
        return row >= 0 && row < rowCount && column >= 0
                && column < columnCount;
    }

    public static long id52(long[][] array) {
        int n = array.length;
        int m = array[0].length;
        long[][] id17 = new long[n + 1][m + 1];
        for (int i = 0; i < n; i++) {
            long rowSum = 0;
            for (int j = 0; j < m; j++) {
                rowSum += array[i][j];
                id17[i + 1][j + 1] = id17[i][j + 1] + rowSum;
            }
        }
        long result = Long.MIN_VALUE;
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                long id33 = 0;
                for (int k = 1; k <= n; k++) {
                    long current = id17[k][j + 1] - id17[k][i];
                    result = Math.max(result, current - id33);
                    id33 = Math.min(id33, current);
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

    public static <T> boolean equals(T first, T second) {
        return first == null && second == null || first != null
                && first.equals(second);
    }

    public static boolean id28(char ch) {
        ch = Character.toUpperCase(ch);
        return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
                || ch == 'Y';
    }

    public static boolean id9(char ch) {
        ch = Character.toUpperCase(ch);
        return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    public static String id42(int number) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < id19.length; i++) {
            while (number >= id55[i]) {
                number -= id55[i];
                result.append(id19[i]);
            }
        }
        return result.toString();
    }

    public static int id49(String number) {
        int result = 0;
        for (int i = 0; i < id19.length; i++) {
            while (number.startsWith(id19[i])) {
                number = number.substring(id19[i].length());
                result += id55[i];
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

    public static void id24(int[]... arrays) {
        for (int[] array : arrays) {
            for (int i = 0; i < array.length; i++)
                array[i]--;
        }
    }

    public static int[] id41(String s) {
        String[] tokens = s.split(" ");
        int[] result = new int[tokens.length];
        for (int i = 0; i < result.length; i++)
            result[i] = Integer.parseInt(tokens[i]);
        return result;
    }
}

class Graph {
    public static final int id58 = 0;

    protected int vertexCount;
    protected int edgeCount;

    private int[] firstOutbound;
    private int[] firstInbound;

    private Edge[] edges;
    private int[] nextInbound;
    private int[] nextOutbound;
    private int[] from;
    private int[] to;
    private long[] weight;
    public long[] capacity;
    private int[] reverseEdge;
    private int[] flags;

    public Graph(int vertexCount) {
        this(vertexCount, vertexCount);
    }

    public Graph(int vertexCount, int edgeCapacity) {
        this.vertexCount = vertexCount;
        firstOutbound = new int[vertexCount];
        Arrays.fill(firstOutbound, -1);

        from = new int[edgeCapacity];
        to = new int[edgeCapacity];
        nextOutbound = new int[edgeCapacity];
        flags = new int[edgeCapacity];
    }

    public static Graph createGraph(int vertexCount, int[] from, int[] to) {
        Graph graph = new Graph(vertexCount, from.length);
        for (int i = 0; i < from.length; i++)
            graph.id36(from[i], to[i]);
        return graph;
    }

    public static Graph id5(int vertexCount, int[] from,
            int[] to, long[] weight) {
        Graph graph = new Graph(vertexCount, from.length);
        for (int i = 0; i < from.length; i++)
            graph.id3(from[i], to[i], weight[i]);
        return graph;
    }

    public static Graph id40(int vertexCount, int[] from, int[] to,
            long[] capacity) {
        Graph graph = new Graph(vertexCount, from.length * 2);
        for (int i = 0; i < from.length; i++)
            graph.id21(from[i], to[i], capacity[i]);
        return graph;
    }

    public static Graph id23(int vertexCount, int[] from,
            int[] to, long[] weight, long[] capacity) {
        Graph graph = new Graph(vertexCount, from.length * 2);
        for (int i = 0; i < from.length; i++)
            graph.id25(from[i], to[i], weight[i], capacity[i]);
        return graph;
    }

    public static Graph createTree(int[] parent) {
        Graph graph = new Graph(parent.length + 1, parent.length);
        for (int i = 0; i < parent.length; i++)
            graph.id36(parent[i], i + 1);
        return graph;
    }

    public int addEdge(int fromID, int toID, long weight, long capacity,
            int reverseEdge) {
        id35(edgeCount + 1);
        if (firstOutbound[fromID] != -1)
            nextOutbound[edgeCount] = firstOutbound[fromID];
        else
            nextOutbound[edgeCount] = -1;
        firstOutbound[fromID] = edgeCount;
        if (firstInbound != null) {
            if (firstInbound[toID] != -1)
                nextInbound[edgeCount] = firstInbound[toID];
            else
                nextInbound[edgeCount] = -1;
            firstInbound[toID] = edgeCount;
        }
        this.from[edgeCount] = fromID;
        this.to[edgeCount] = toID;
        if (capacity != 0) {
            if (this.capacity == null)
                this.capacity = new long[from.length];
            this.capacity[edgeCount] = capacity;
        }
        if (weight != 0) {
            if (this.weight == null)
                this.weight = new long[from.length];
            this.weight[edgeCount] = weight;
        }
        if (reverseEdge != -1) {
            if (this.reverseEdge == null) {
                this.reverseEdge = new int[from.length];
                Arrays.fill(this.reverseEdge, 0, edgeCount, -1);
            }
            this.reverseEdge[edgeCount] = reverseEdge;
        }
        if (edges != null)
            edges[edgeCount] = createEdge(edgeCount);
        return edgeCount++;
    }

    protected final GraphEdge createEdge(int id) {
        return new GraphEdge(id);
    }

    public final int id25(int from, int to, long weight,
            long capacity) {
        if (capacity == 0) {
            return addEdge(from, to, weight, 0, -1);
        } else {
            int id32 = edgeCount;
            addEdge(to, from, -weight, 0, id32 + id34());
            return addEdge(from, to, weight, capacity, id32);
        }
    }

    protected int id34() {
        return 1;
    }

    public final int id21(int from, int to, long capacity) {
        return id25(from, to, 0, capacity);
    }

    public final int id3(int from, int to, long weight) {
        return id25(from, to, weight, 0);
    }

    public final int id36(int from, int to) {
        return id3(from, to, 0);
    }

    public final int vertexCount() {
        return vertexCount;
    }

    public final int edgeCount() {
        return edgeCount;
    }

    protected final int edgeCapacity() {
        return from.length;
    }

    public final Edge edge(int id) {
        initEdges();
        return edges[id];
    }

    public final int firstOutbound(int vertex) {
        int id = firstOutbound[vertex];
        while (id != -1 && isRemoved(id))
            id = nextOutbound[id];
        return id;
    }

    public final int nextOutbound(int id) {
        id = nextOutbound[id];
        while (id != -1 && isRemoved(id))
            id = nextOutbound[id];
        return id;
    }

    public final int firstInbound(int vertex) {
        initInbound();
        int id = firstInbound[vertex];
        while (id != -1 && isRemoved(id))
            id = nextInbound[id];
        return id;
    }

    public final int nextInbound(int id) {
        initInbound();
        id = nextInbound[id];
        while (id != -1 && isRemoved(id))
            id = nextInbound[id];
        return id;
    }

    public final int source(int id) {
        return from[id];
    }

    public final int destination(int id) {
        return to[id];
    }

    public final long weight(int id) {
        if (weight == null)
            return 0;
        return weight[id];
    }

    public final long capacity(int id) {
        if (capacity == null)
            return 0;
        return capacity[id];
    }

    public final long flow(int id) {
        if (reverseEdge == null)
            return 0;
        return capacity[reverseEdge[id]];
    }

    public final void pushFlow(int id, long flow) {
        if (flow == 0)
            return;
        if (flow > 0) {
            if (capacity(id) < flow)
                throw new IllegalArgumentException("Not enough capacity");
        } else {
            if (flow(id) < -flow)
                throw new IllegalArgumentException("Not enough capacity");
        }
        capacity[id] -= flow;
        capacity[reverseEdge[id]] += flow;
    }

    public int transposed(int id) {
        return -1;
    }

    public final int reverse(int id) {
        if (reverseEdge == null)
            return -1;
        return reverseEdge[id];
    }

    public final void addVertices(int count) {
        id30(vertexCount + count);
        Arrays.fill(firstOutbound, vertexCount, vertexCount + count, -1);
        if (firstInbound != null)
            Arrays.fill(firstInbound, vertexCount, vertexCount + count, -1);
        vertexCount += count;
    }

    protected final void initEdges() {
        if (edges == null) {
            edges = new Edge[from.length];
            for (int i = 0; i < edgeCount; i++)
                edges[i] = createEdge(i);
        }
    }

    public final void removeVertex(int vertex) {
        int id = firstOutbound[vertex];
        while (id != -1) {
            removeEdge(id);
            id = nextOutbound[id];
        }
        initInbound();
        id = firstInbound[vertex];
        while (id != -1) {
            removeEdge(id);
            id = nextInbound[id];
        }
    }

    private void initInbound() {
        if (firstInbound == null) {
            firstInbound = new int[firstOutbound.length];
            Arrays.fill(firstInbound, 0, vertexCount, -1);
            nextInbound = new int[from.length];
            for (int i = 0; i < edgeCount; i++) {
                nextInbound[i] = firstInbound[to[i]];
                firstInbound[to[i]] = i;
            }
        }
    }

    public final boolean flag(int id, int bit) {
        return (flags[id] >> bit & 1) != 0;
    }

    public final void setFlag(int id, int bit) {
        flags[id] |= 1 << bit;
    }

    public final void removeFlag(int id, int bit) {
        flags[id] &= -1 - (1 << bit);
    }

    public final void removeEdge(int id) {
        setFlag(id, id58);
    }

    public final void restoreEdge(int id) {
        removeFlag(id, id58);
    }

    public final boolean isRemoved(int id) {
        return flag(id, id58);
    }

    public final Iterable<Edge> outbound(final int id) {
        initEdges();
        return new Iterable<Edge>() {
            public Iterator<Edge> iterator() {
                return new EdgeIterator(id, firstOutbound, nextOutbound);
            }
        };
    }

    public final Iterable<Edge> inbound(final int id) {
        initEdges();
        initInbound();
        return new Iterable<Edge>() {
            public Iterator<Edge> iterator() {
                return new EdgeIterator(id, firstInbound, nextInbound);
            }
        };
    }

    protected void id35(int size) {
        if (from.length < size) {
            int newSize = Math.max(size, 2 * from.length);
            if (edges != null)
                edges = resize(edges, newSize);
            from = resize(from, newSize);
            to = resize(to, newSize);
            nextOutbound = resize(nextOutbound, newSize);
            if (nextInbound != null)
                nextInbound = resize(nextInbound, newSize);
            if (weight != null)
                weight = resize(weight, newSize);
            if (capacity != null)
                capacity = resize(capacity, newSize);
            if (reverseEdge != null)
                reverseEdge = resize(reverseEdge, newSize);
            flags = resize(flags, newSize);
        }
    }

    private void id30(int size) {
        if (firstOutbound.length < size) {
            int newSize = Math.max(size, 2 * from.length);
            firstOutbound = resize(firstOutbound, newSize);
            if (firstInbound != null)
                firstInbound = resize(firstInbound, newSize);
        }
    }

    protected final int[] resize(int[] array, int size) {
        int[] newArray = new int[size];
        System.arraycopy(array, 0, newArray, 0, array.length);
        return newArray;
    }

    private long[] resize(long[] array, int size) {
        long[] newArray = new long[size];
        System.arraycopy(array, 0, newArray, 0, array.length);
        return newArray;
    }

    private Edge[] resize(Edge[] array, int size) {
        Edge[] newArray = new Edge[size];
        System.arraycopy(array, 0, newArray, 0, array.length);
        return newArray;
    }

    public final boolean isSparse() {
        return vertexCount == 0 || edgeCount * 20 / vertexCount <= vertexCount;
    }

    protected class GraphEdge implements Edge {
        protected int id;

        protected GraphEdge(int id) {
            this.id = id;
        }

        public int getSource() {
            return source(id);
        }

        public int getDestination() {
            return destination(id);
        }

        public long getWeight() {
            return weight(id);
        }

        public long getCapacity() {
            return capacity(id);
        }

        public long getFlow() {
            return flow(id);
        }

        public void pushFlow(long flow) {
            Graph.this.pushFlow(id, flow);
        }

        public boolean getFlag(int bit) {
            return flag(id, bit);
        }

        public void setFlag(int bit) {
            Graph.this.setFlag(id, bit);
        }

        public void removeFlag(int bit) {
            Graph.this.removeFlag(id, bit);
        }

        public int id14() {
            return transposed(id);
        }

        public Edge id6() {
            int reverseID = id14();
            if (reverseID == -1)
                return null;
            initEdges();
            return edge(reverseID);
        }

        public int id43() {
            return reverse(id);
        }

        public Edge id47() {
            int reverseID = id43();
            if (reverseID == -1)
                return null;
            initEdges();
            return edge(reverseID);
        }

        public int getID() {
            return id;
        }

        public void remove() {
            removeEdge(id);
        }

        public void restore() {
            restoreEdge(id);
        }
    }

    public class EdgeIterator implements Iterator<Edge> {
        private int edgeID;
        private final int[] next;
        private int lastID = -1;

        public EdgeIterator(int id, int[] first, int[] next) {
            this.next = next;
            edgeID = nextEdge(first[id]);
        }

        private int nextEdge(int id) {
            while (id != -1 && isRemoved(id))
                id = next[id];
            return id;
        }

        public boolean hasNext() {
            return edgeID != -1;
        }

        public Edge next() {
            if (edgeID == -1)
                throw new NoSuchElementException();
            lastID = edgeID;
            edgeID = nextEdge(next[lastID]);
            return edges[lastID];
        }

        public void remove() {
            if (lastID == -1)
                throw new IllegalStateException();
            removeEdge(lastID);
            lastID = -1;
        }
    }

}



interface Edge {
    public int getSource();

    public int getDestination();

    public long getWeight();

    public long getCapacity();

    public long getFlow();

    public void pushFlow(long flow);

    public boolean getFlag(int bit);

    public void setFlag(int bit);

    public void removeFlag(int bit);

    public int id14();

    public Edge id6();

    public int id43();

    public Edge id47();

    public int getID();

    public void remove();

    public void restore();
}