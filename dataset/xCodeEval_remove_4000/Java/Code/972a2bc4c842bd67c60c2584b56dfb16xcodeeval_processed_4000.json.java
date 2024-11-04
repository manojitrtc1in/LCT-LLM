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
    
    public void solve(int testNumber, InputReader in, OutputWriter out){
        int n=in.readInt();
        String str;
        while (n-->0) {
            str=in.next();
            if (str.length()>10) out.printLine(""+str.charAt(0)+(str.length()-2)+str.charAt(str.length()-1));
            else out.printLine(str);
        }
    }
    
}

class B implements Task {
    
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n=in.readInt(), k=in.readInt(), t=in.readInt();
        int s=n*k*t/100, a=0, x;
        

        for (int i=0; i<n; i++) {
            x=Math.min(s-a, k);
            out.print(x, ' ');
            a+=x;
        }
    }
    
    boolean isDigit(char c) {
        return c>='0' && c<='9';
    }
    
    int f1(StringBuilder str) {
        int ret=0;
        for (int i=0; i<str.length(); i++) ret=26*ret+str.charAt(i)-'A'+1;
        return ret;
    }
    
    String f2(int n) {
        StringBuilder ret=new StringBuilder();
        for (; n>0; n/=26) {
            n--;
            ret.insert(0, (char)('A'+n%26));
            

        }
        return ret.toString();
    }
    
}

class C implements Task {
    
    
    
    public void solve(int testNumber, InputReader in, OutputWriter out){
        
    }
    
    double cross(Vector v0, Vector v1) {
        return Math.abs(v0.x*v1.y-v0.y*v1.x);
    }
    
    double gcd(double a, double b) {
        if (Math.abs(b)<GeometryUtils.epsilon) return a;
        return gcd(b, a%b);
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

class Point {
    public static final Point ORIGIN = new Point(0, 0);
    public final double x;
    public final double y;

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
        return GeometryUtils.id7(x - other.x, y - other.y);
    }

    public double distance(Line line) {
        return Math.abs(line.a * x + line.b * y + line.c);
    }

    public double value() {
        return GeometryUtils.id7(x, y);
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

class GeometryUtils {
    public static double epsilon = 1e-8;

    public static double id7(double...x) {
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

    public static double id7(double x, double y) {
        return Math.sqrt(x * x + y * y);
    }

    public static double id7(double[] x, double[] y) {
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

    public static double id7(int[] x, int[] y) {
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

    public static double id0(double v, double angle, double g) {
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
        double h = GeometryUtils.id7(a, b);
        this.a = a / h;
        this.b = b / h;
        this.c = c / h;
    }

    public Point intersect(Line other) {
        if (parallel(other))
            return null;
        double id2 = b * other.a - a * other.b;
        double x = (c * other.b - b * other.c) / id2;
        double y = (a * other.c - c * other.a) / id2;
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

    public Point[] id6(Point point) {
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

class D implements Task {
    
    int[] arr;
    
    public void solve(int testNumber, InputReader in, OutputWriter out){
        int n=in.readInt(), ret=-1000000000, c;
        arr=new int[n];
        for (int i=0; i<n; i++) arr[i]=in.readInt();
        for (int i=1; i<=n/3; i++) if (n%i==0) for (int j=0; j<i; j++) {
            c=0;
            for (int k=j; k<n; k+=i) c+=arr[k];
            ret=Math.max(ret, c);
        }
        out.printLine(ret);
    }
        
}

class E implements Task {
    
    int[] ini, dur;
    int[][] pd;
    
    public void solve(int testNumber, InputReader in, OutputWriter out){
        int n=in.readInt(), k=in.readInt(), ret, a;
        ini=new int[n+1];
        dur=new int[n+1];
        pd=new int[n+1][k+1];
        ini[0]=dur[0]=0;
        for (int i=1; i<=n; i++) {
            ini[i]=in.readInt();
            dur[i]=in.readInt();
        }
        if (n==k) {
            out.printLine(86400);
            return;
        }
        for (int i=0; i<=n; i++) for (int j=0; j<=k; j++) 
            pd[i][j]=i==0?1:Math.min(j==0?1000000000:pd[i-1][j-1], Math.max(pd[i-1][j], ini[i])+dur[i]);
        ret=86400-pd[n][k]+1;
        for (int i=1; i<=n; i++) ret=Math.max(ret, ini[i]-pd[i-1][k]);
        out.printLine(ret);
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id9 filter;

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
        while (id4(c))
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
        } while (!id4(c));
        return res * sgn;
    }

    public long readLong() {
        int c = read();
        while (id4(c))
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
        } while (!id4(c));
        return res * sgn;
    }

    public String readString() {
        int c = read();
        while (id4(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            if (Character.isValidCodePoint(c))
                res.appendCodePoint(c);
            c = read();
        } while (!id4(c));
        return res.toString();
    }

    public boolean id4(int c) {
        if (filter != null)
            return filter.id4(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private String id1() {
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
        String s = id1();
        while (s.trim().length() == 0)
            s = id1();
        return s;
    }

    public String readLine(boolean id8) {
        if (id8)
            return readLine();
        else
            return id1();
    }

    public BigInteger id5() {
        try {
            return new BigInteger(readString());
        } catch (NumberFormatException e) {
            throw new InputMismatchException();
        }
    }

    public char readCharacter() {
        int c = read();
        while (id4(c))
            c = read();
        return (char) c;
    }

    public double readDouble() {
        int c = read();
        while (id4(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!id4(c) && c != '.') {
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
            while (!id4(c)) {
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

    public boolean id3() {
        int value;
        while (id4(value = peek()) && value != -1)
            read();
        return value == -1;
    }

    public String next() {
        return readString();
    }

    public id9 getFilter() {
        return filter;
    }

    public void setFilter(id9 filter) {
        this.filter = filter;
    }

    public interface id9 {
        public boolean id4(int ch);
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