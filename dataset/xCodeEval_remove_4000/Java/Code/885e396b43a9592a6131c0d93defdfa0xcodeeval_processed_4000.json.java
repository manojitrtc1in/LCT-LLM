import java.io.*;
import java.util.*;
import java.util.Map.*;
import java.lang.reflect.*;
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
        lista=IOUtils.id15(in, n);
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

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id28 filter;

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

    private String id6() {
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
        String s = id6();
        while (s.trim().length() == 0)
            s = id6();
        return s;
    }

    public String readLine(boolean id26) {
        if (id26)
            return readLine();
        else
            return id6();
    }

    public BigInteger id18() {
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

    public id28 getFilter() {
        return filter;
    }

    public void setFilter(id28 filter) {
        this.filter = filter;
    }

    public interface id28 {
        public boolean id10(int ch);
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

abstract class id14<T> implements Iterator<T>  {
    public final void remove() {
        throw new UnsupportedOperationException();
    }
}

class IOUtils {
    public static Pair<Integer, Integer> id12(InputReader in) {
        int first = in.readInt();
        int second = in.readInt();
        return Pair.makePair(first, second);
    }

    public static Pair<Long, Long> id16(InputReader in) {
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

    public static long[] id13(InputReader in, int size) {
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

    public static String[] id27(InputReader in, int size) {
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

    public static Pair<Integer, Integer>[] id15(InputReader in, int size) {
        @SuppressWarnings({"unchecked"})
        Pair<Integer, Integer>[] result = new Pair[size];
        for (int i = 0; i < size; i++)
            result[i] = id12(in);
        return result;
    }

    public static Pair<Long, Long>[] id0(InputReader in, int size) {
        @SuppressWarnings({"unchecked"})
        Pair<Long, Long>[] result = new Pair[size];
        for (int i = 0; i < size; i++)
            result[i] = id16(in);
        return result;
    }

    public static void id17(InputReader in, int[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readInt();
        }
    }

    public static void id19(InputReader in, long[]... arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readLong();
        }
    }

    public static void id24(InputReader in, double[]...arrays) {
        for (int i = 0; i < arrays[0].length; i++) {
            for (int j = 0; j < arrays.length; j++)
                arrays[j][i] = in.readDouble();
        }
    }

    public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
        char[][] table = new char[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id8(in, columnCount);
        return table;
    }

    public static int[][] id11(InputReader in, int rowCount, int columnCount) {
        int[][] table = new int[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id2(in, columnCount);
        return table;
    }

    public static double[][] id1(InputReader in, int rowCount, int columnCount) {
        double[][] table = new double[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id5(in, columnCount);
        return table;
    }

    public static long[][] id3(InputReader in, int rowCount, int columnCount) {
        long[][] table = new long[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id13(in, columnCount);
        return table;
    }

    public static String[][] id25(InputReader in, int rowCount, int columnCount) {
        String[][] table = new String[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id27(in, columnCount);
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

    public static void id20(InputReader in, String[]... arrays) {
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

class ReverseComparator<T extends Comparable<T>> implements Comparator<T> {
    public int compare(T o1, T o2) {
        return o2.compareTo(o1);
    }
}

class Angle {
    public final Point o;
    public final Point a;
    public final Point b;

    public Angle(Point o, Point a, Point b) {
        this.o = o;
        this.a = a;
        this.b = b;
    }

    public double value() {
        double ab = a.distance(b);
        double ao = a.distance(o);
        double bo = b.distance(o);
        return Math.acos((ao * ao + bo * bo - ab * ab) / (2 * ao * bo));
    }

}

class Circle {
    public final Point center;
    public final double radius;

    public Circle(Point center, double radius) {
        this.center = center;
        this.radius = radius;
    }

    public boolean contains(Point point) {
        return center.distance(point) < radius + GeometryUtils.epsilon;
    }

    public boolean strictContains(Point point) {
        return center.distance(point) < radius - GeometryUtils.epsilon;
    }

    public Point[] id22(Point point) {
        double distance = center.distance(point);
        if (distance < radius - GeometryUtils.epsilon)
            return new Point[0];
        if (distance < radius + GeometryUtils.epsilon)
            return new Point[]{point};
        Circle power = new Circle(point, Math.sqrt((distance - radius) * (distance + radius)));
        return intersect(power);
    }

    public Point[] intersect(Circle other) {
        double distance = center.distance(other.center);
        if (distance > radius + other.radius + GeometryUtils.epsilon || Math.abs(radius - other.radius) > distance + GeometryUtils.epsilon)
            return new Point[0];
        double p = (radius + other.radius + distance) / 2;
        double height = 2 * Math.sqrt(p * (p - radius) * (p - other.radius) * (p - distance)) / distance;
        double l1 = Math.sqrt(radius * radius - height * height);
        double l2 = Math.sqrt(other.radius * other.radius - height * height);
        if (radius * radius + distance * distance < other.radius * other.radius)
            l1 = -l1;
        if (radius * radius > distance * distance + other.radius * other.radius)
            l2 = -l2;
        Point middle = new Point((center.x * l2 + other.center.x * l1) / (l1 + l2),
            (center.y * l2 + other.center.y * l1) / (l1 + l2));
        Line line = center.line(other.center).perpendicular(middle);
        return line.intersect(this);
    }
}

class GeometryUtils {
    public static double epsilon = 1e-8;

    public static double id23(double...x) {
        if (x.length == 0)
            return 0;
        else if (x.length == 1)
            return Math.abs(x[0]);
        else {
            double sumSquares = 0;
            for (double value : x)
                sumSquares += value * value;
            return Math.sqrt(sumSquares);
        }
    }

    public static double id23(double x, double y) {
        return Math.sqrt(x * x + y * y);
    }

    public static double id23(double[] x, double[] y) {
        if (x.length == 0)
            return 0;
        else if (x.length == 1)
            return Math.abs(x[0]- y[0]);
        else {
            double sumSquares = 0;
            for (int i = 0; i < x.length; i++) {
                double diff = x[i] - y[i];
                sumSquares += diff * diff;
            }
            return Math.sqrt(sumSquares);
        }
    }

    public static double id23(int[] x, int[] y) {
        if (x.length == 0)
            return 0;
        else if (x.length == 1)
            return Math.abs(x[0]- y[0]);
        else {
            double sumSquares = 0;
            for (int i = 0; i < x.length; i++) {
                double diff = x[i] - y[i];
                sumSquares += diff * diff;
            }
            return Math.sqrt(sumSquares);
        }
    }

    public static double id4(double v, double angle, double g) {
        return (v * v * Math.sin(2 * angle)) / g;
    }

    public static double sphereVolume(double radius) {
        return 4 * Math.PI * radius * radius * radius / 3;
    }

    public static double triangleSquare(double first, double second, double third) {
        double p = (first + second + third) / 2;
        return Math.sqrt(p * (p - first) * (p - second) * (p - third));
    }

    public static double canonicalAngle(double angle) {
        while (angle > Math.PI)
            angle -= 2 * Math.PI;
        while (angle < -Math.PI)
            angle += 2 * Math.PI;
        return angle;
    }

    public static double positiveAngle(double angle) {
        while (angle > 2 * Math.PI - GeometryUtils.epsilon)
            angle -= 2 * Math.PI;
        while (angle < -GeometryUtils.epsilon)
            angle += 2 * Math.PI;
        return angle;
    }
}

class Line {
    public final double a;
    public final double b;
    public final double c;

    public Line(Point p, double angle) {
        a = Math.sin(angle);
        b = -Math.cos(angle);
        c = -p.x * a - p.y * b;
    }

    public Line(double a, double b, double c) {
        double h = GeometryUtils.id23(a, b);
        this.a = a / h;
        this.b = b / h;
        this.c = c / h;
    }

    public Point intersect(Line other) {
        if (parallel(other))
            return null;
        double id7 = b * other.a - a * other.b;
        double x = (c * other.b - b * other.c) / id7;
        double y = (a * other.c - c * other.a) / id7;
        return new Point(x, y);
    }

    public boolean parallel(Line other) {
        return Math.abs(a * other.b - b * other.a) < GeometryUtils.epsilon;
    }

    public boolean contains(Point point) {
        return Math.abs(value(point)) < GeometryUtils.epsilon;
    }

    public Line perpendicular(Point point) {
        return new Line(-b, a, b * point.x - a * point.y);
    }

    public double value(Point point) {
        return a * point.x + b * point.y + c;
    }

    public Point[] intersect(Circle circle) {
        double distance = distance(circle.center);
        if (distance > circle.radius + GeometryUtils.epsilon)
            return new Point[0];
        Point intersection = intersect(perpendicular(circle.center));
        if (Math.abs(distance - circle.radius) < GeometryUtils.epsilon)
            return new Point[]{intersection};
        double shift = Math.sqrt(circle.radius * circle.radius - distance * distance);
        return new Point[]{new Point(intersection.x + shift * b, intersection.y - shift * a),
            new Point(intersection.x - shift * b, intersection.y + shift * a)};
    }

    public double distance(Point center) {
        return Math.abs(value(center));
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Line line = (Line) o;

        if (!parallel(line)) return false;
        if (Math.abs(a * line.c - c * line.a) > GeometryUtils.epsilon || Math.abs(b * line.c - c * line.b) > GeometryUtils.epsilon) return false;

        return true;
    }
}

class Point implements Comparable<Point> {
    public static final Point ORIGIN = new Point(0, 0);
    public final double x;
    public final double y;

    public int compareTo(Point other) {
        int value = Double.compare(this.x, other.x);
        if (value != 0)
            return value;
        return Double.compare(this.y, other.y);
    }
    
    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Line line(Point other) {
        if (equals(other))
            return null;
        double a = other.y - y;
        double b = x - other.x;
        double c = -a * x - b * y;
        return new Line(a, b, c);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;

        Point point = (Point) o;

        return Math.abs(x - point.x) <= GeometryUtils.epsilon && Math.abs(y - point.y) <= GeometryUtils.epsilon;
    }

    @Override
    public int hashCode() {
        int result;
        long temp;
        temp = x != +0.0d ? Double.doubleToLongBits(x) : 0L;
        result = (int) (temp ^ (temp >>> 32));
        temp = y != +0.0d ? Double.doubleToLongBits(y) : 0L;
        result = 31 * result + (int) (temp ^ (temp >>> 32));
        return result;
    }

    public double distance(Point other) {
        return GeometryUtils.id23(x - other.x, y - other.y);
    }

    public double distance(Line line) {
        return Math.abs(line.a * x + line.b * y + line.c);
    }

    public double value() {
        return GeometryUtils.id23(x, y);
    }

    public double angle() {
        return Math.atan2(y, x);
    }

    public static Point readPoint(InputReader in) {
        double x = in.readDouble();
        double y = in.readDouble();
        return new Point(x, y);
    }

    public Point rotate(double angle) {
        double nx = x * Math.cos(angle) - y * Math.sin(angle);
        double ny = y * Math.cos(angle) + x * Math.sin(angle);
        return new Point(nx, ny);
    }
}

class Polygon {
    public final Point[] vertices;
    private Segment[] sides;

    public Polygon(Point...vertices) {
        this.vertices = vertices.clone();
    }

    public double square() {
        double sum = 0;
        for (int i = 1; i < vertices.length; i++)
            sum += (vertices[i].x - vertices[i - 1].x) * (vertices[i].y + vertices[i - 1].y);
        sum += (vertices[0].x - vertices[vertices.length - 1].x) * (vertices[0].y + vertices[vertices.length - 1].y);
        return Math.abs(sum) / 2;
    }

    public Point center() {
        double sx = 0;
        double sy = 0;
        for (Point point : vertices) {
            sx += point.x;
            sy += point.y;
        }
        return new Point(sx / vertices.length, sy / vertices.length);
    }

    public static boolean over(Point a, Point b, Point c) {
        return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < -GeometryUtils.epsilon;
    }

    private static boolean under(Point a, Point b, Point c) {
        return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > GeometryUtils.epsilon;
    }

    public static Polygon id21(Point[] points) {
        if (points.length == 1)
            return new Polygon(points);
        Arrays.sort(points);
        Point left = points[0];
        Point right = points[points.length - 1];
        List<Point> up = new ArrayList<Point>();
        List<Point> down = new ArrayList<Point>();
        for (Point point : points) {
            if (point == left || point == right || !under(left, point, right)) {
                while (up.size() >= 2 && under(up.get(up.size() - 2), up.get(up.size() - 1), point))
                    up.remove(up.size() - 1);
                up.add(point);
            }
            if (point == left || point == right || !over(left, point, right)) {
                while (down.size() >= 2 && over(down.get(down.size() - 2), down.get(down.size() - 1), point))
                    down.remove(down.size() - 1);
                down.add(point);
            }
        }
        Point[] result = new Point[up.size() + down.size() - 2];
        int index = 0;
        for (Point point : up)
            result[index++] = point;
        for (int i = down.size() - 2; i > 0; i--)
            result[index++] = down.get(i);
        return new Polygon(result);
    }

    public boolean contains(Point point) {
        return contains(point, false);
    }

    public boolean contains(Point point, boolean strict) {
        for (Segment segment : sides()) {
            if (segment.contains(point, true))
                return !strict;
        }
        double totalAngle = GeometryUtils.canonicalAngle(Math.atan2(vertices[0].y - point.y, vertices[0].x - point.x) -
            Math.atan2(vertices[vertices.length - 1].y - point.y, vertices[vertices.length - 1].x - point.x));
        for (int i = 1; i < vertices.length; i++) {
            totalAngle += GeometryUtils.canonicalAngle(Math.atan2(vertices[i].y - point.y, vertices[i].x - point.x) -
                Math.atan2(vertices[i - 1].y - point.y, vertices[i - 1].x - point.x));
        }
        return Math.abs(totalAngle) > Math.PI;
    }

    public Segment[] sides() {
        if (sides == null) {
            sides = new Segment[vertices.length];
            for (int i = 0; i < vertices.length - 1; i++)
                sides[i] = new Segment(vertices[i], vertices[i + 1]);
            sides[sides.length - 1] = new Segment(vertices[vertices.length - 1], vertices[0]);
        }
        return sides;
    }

    public static double triangleSquare(Point a, Point b, Point c) {
        return Math.abs((a.x - b.x) * (a.y + b.y) + (b.x - c.x) * (b.y + c.y) + (c.x - a.x) * (c.y + a.y)) / 2;
    }

    public double perimeter() {
        double result = vertices[0].distance(vertices[vertices.length - 1]);
        for (int i = 1; i < vertices.length; i++)
            result += vertices[i].distance(vertices[i - 1]);
        return result;
    }
}

class Ray {
    public final Point base;
    public final Line line;
    private final Line perpendicular;

    public Ray(Point base, double direction) {
        this.base = base;
        line = new Line(base, direction);
        this.perpendicular = line.perpendicular(base);
    }

    public Ray(Point base, Point other) {
        this.base = base;
        line = base.line(other);
        this.perpendicular = line.perpendicular(base);
    }

    public boolean contains(Point point) {
        return line.contains(point) && perpendicular.value(point) > -GeometryUtils.epsilon;
    }

    public double distance(Point point) {
        if (perpendicular.value(point) > -GeometryUtils.epsilon)
            return line.distance(point);
        return base.distance(point);
    }
}

class Segment {
    public final Point a;
    public final Point b;
    private double distance = Double.NaN;
    private Line line = null;

    public Segment(Point a, Point b) {
        this.a = a;
        this.b = b;
    }

    public double length() {
        if (Double.isNaN(distance))
            distance = a.distance(b);
        return distance;
    }

    public double distance(Point point) {
        double length = length();
        double left = point.distance(a);
        if (length < GeometryUtils.epsilon)
            return left;
        double right = point.distance(b);
        if (left * left > right * right + length * length)
            return right;
        if (right * right > left * left + length * length)
            return left;
        return point.distance(line());
    }

    public Point intersect(Segment other, boolean includeEnds) {
        Line line = line();
        Line otherLine = other.a.line(other.b);
        if (line.parallel(otherLine))
            return null;
        Point intersection = line.intersect(otherLine);
        if (contains(intersection, includeEnds) && other.contains(intersection, includeEnds))
            return intersection;
        else
            return null;
    }

    public boolean contains(Point point, boolean includeEnds) {
        if (a.equals(point) || b.equals(point))
            return includeEnds;
        if (a.equals(b))
            return false;
        Line line = line();
        if (!line.contains(point))
            return false;
        Line perpendicular = line.perpendicular(a);
        double aValue = perpendicular.value(a);
        double bValue = perpendicular.value(b);
        double pointValue = perpendicular.value(point);
        return aValue < pointValue && pointValue < bValue || bValue < pointValue && pointValue < aValue;
    }

    public Line line() {
        if (line == null)
            line = a.line(b);
        return line;
    }

    public Point middle() {
        return new Point((a.x + b.x) / 2, (a.y + b.y) / 2);
    }

    public Point[] intersect(Circle circle) {
        Point[] result = line().intersect(circle);
        if (result.length == 0)
            return result;
        if (result.length == 1) {
            if (contains(result[0], true))
                return result;
            return new Point[0];
        }
        if (contains(result[0], true)) {
            if (contains(result[1], true))
                return result;
            return new Point[]{result[0]};
        }
        if (contains(result[1], true))
            return new Point[]{result[1]};
        return new Point[0];
    }

    public Point intersect(Line line) {
        Line selfLine = line();
        Point intersect = selfLine.intersect(line);
        if (intersect == null)
            return null;
        if (contains(intersect, true))
            return intersect;
        return null;
    }

    public double distance(Segment other) {
        Line line = line();
        Line otherLine = other.line();
        Point p = line == null || otherLine == null ? null : line.intersect(otherLine);
        if (p != null && contains(p, true) && other.contains(p, true))
            return 0;
        return Math.min(Math.min(other.distance(a), other.distance(b)), Math.min(distance(other.a), distance(other.b)));
    }
}

class Vector {
    public final double x;
    public final double y;
    public final Point point;

    public Vector(double x, double y) {
        this.x = x;
        this.y = y;
        point = new Point(x, y);
    }

    public Vector(Point point) {
        this.x = point.x;
        this.y = point.y;
        this.point = point;
    }

    public Vector(Point from, Point to) {
        this(to.x - from.x, to.y - from.y);
    }

    public double angleTo(Vector other) {
        return GeometryUtils.canonicalAngle(other.point.angle() - point.angle());
    }

    public double length() {
        return point.value();
    }

    public double angle() {
        return point.angle();
    }
}