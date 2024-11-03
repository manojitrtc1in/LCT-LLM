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
        Task solver = new E();
        solver.solve(1, in, out);
        out.close();
    }
}

interface Task {
    public void solve(int testNumber, InputReader in, OutputWriter out);
}

class A implements Task {
    
    public void solve(int testNumber, InputReader in, OutputWriter out){
        int n=in.readInt(), x, y, ret=0, cap=0;
        while (n-->0) {
            x=in.readInt();
            y=in.readInt();
            cap+=y-x;
            ret=Math.max(ret,  cap);
        }
        out.printLine(ret);
    }
    
}

class B implements Task {
    
    String[] arr;
    int[] dx={-1, 0, 0, 1}, dy={0, -1, 1, 0};
    
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n=in.readInt(), m=in.readInt(), ret=0;
        arr=new String[n];
        for (int i=0; i<n; i++) arr[i]=in.next();
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (arr[i].charAt(j)=='W') {
            boolean val=false;
            for (int k=0; k<4; k++) {
                int i2=i+dx[k], j2=j+dy[k];
                if (i2>=0 && i2<n && j2>=0 && j2<m && arr[i2].charAt(j2)=='P') val=true;
            }
            if (val) ret++;
        }
        out.printLine(ret);
    }
    
}

class C implements Task {
    
    int[] pai, arr;
    
    public void solve(int testNumber, InputReader in, OutputWriter out){
        int n=in.readInt(), ret=0;
        pai=new int[n+1];
        arr=new int[n+1];
        for (int i=1; i<=n; i++) pai[i]=in.readInt();
        for (int i=1; i<=n; i++) ret=Math.max(ret, f(i));
        out.printLine(ret);
    }
    
    int f(int x) {
        if (arr[x]!=0) return arr[x];
        if (pai[x]==-1) return arr[x]=1;
        return arr[x]=f(pai[x])+1;
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

    public static Polygon id23(Point[] points) {
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

class Point implements Comparable<Point>{
    public static final Point ORIGIN = new Point(0, 0);
    public final double x;
    public final double y;
    
    public int compareTo(Point o2) {
        int value = Double.compare(this.x, o2.x);
        if (value != 0)
            return value;
        return Double.compare(this.y, o2.y);
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
        return GeometryUtils.id28(x - other.x, y - other.y);
    }

    public double distance(Line line) {
        return Math.abs(line.a * x + line.b * y + line.c);
    }

    public double value() {
        return GeometryUtils.id28(x, y);
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

    public static double id28(double...x) {
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

    public static double id28(double x, double y) {
        return Math.sqrt(x * x + y * y);
    }

    public static double id28(double[] x, double[] y) {
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

    public static double id28(int[] x, int[] y) {
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
        double h = GeometryUtils.id28(a, b);
        this.a = a / h;
        this.b = b / h;
        this.c = c / h;
    }

    public Point intersect(Line other) {
        if (parallel(other))
            return null;
        double id6 = b * other.a - a * other.b;
        double x = (c * other.b - b * other.c) / id6;
        double y = (a * other.c - c * other.a) / id6;
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

    public Point[] id27(Point point) {
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
    
    int[] mini, maxi;
    
    public void solve(int testNumber, InputReader in, OutputWriter out){
        int n=in.readInt(), m=in.readInt(), ret=0, x=0, y=-1, i2, j2, f=-1;
        String str;
        mini=new int[n];
        maxi=new int[n];
        for (int i=0; i<n; i++) {
            str=in.next();
            mini[i]=1000;
            maxi[i]=-1000;
            for (int j=0; j<m; j++) if (str.charAt(j)=='W') {
                mini[i]=Math.min(mini[i], j);
                maxi[i]=Math.max(maxi[i], j);
                if (f==-1) f=i;
            }
        }
        if (f!=-1) ret+=f;
        for (int i=0; i<n; i++) {
            i2=1000;
            j2=-1000;
            if (i==f && i%2==1) ret+=x=maxi[i];
            for (int j=i+1; j<n; j++) if (mini[j]!=i2 && maxi[j]!=j2) {
                i2=mini[j];
                j2=maxi[j];
                y=j;
                break;
            }
            if (mini[i]!=1000 && maxi[i]!=-1000) {
                ret+=i%2==0?maxi[i]-x:x-mini[i];
                x=i%2==0?maxi[i]:mini[i];
                if (i2!=1000 && j2!=-1000) {
                    ret+=y-i+Math.abs(x-(y%2==0?i2:j2));
                    x=y%2==0?i2:j2;
                }
            }
        }
        out.printLine(ret);
    }
    
}

class E implements Task {
    
    String[] arr;
    int[] pot=new int[500010];
    
    public void solve(int testNumber, InputReader in, OutputWriter out){
        int n=in.readInt(), m=in.readInt(), ret=0, prev;
        char c1, c2;
        boolean val=true, val2;
        arr=new String[n];
        pot[0]=1;
        for (int i=1; i<500010; i++) pot[i]=pot[i-1]*2%1000003;
        for (int i=0; i<n; i++) arr[i]=in.next();
        for (int i=0; i<n; i++) {
            val2=true;
            prev=-1;
            for (int j=0; j<m; j++) if (arr[i].charAt(j)!='.') {
                if (prev!=-1 && ((j-prev)%2==1)==((arr[i].charAt(j)-'1')/2==(arr[i].charAt(prev)-'1')/2)) {
                    val=false;
                }
                val2=false;
                prev=j;
            }
            if (val2) ret++;
        }
        

        for (int j=0; j<m; j++) {
            val2=true;
            prev=-1;
            for (int i=0; i<n; i++) if (arr[i].charAt(j)!='.') {
                if (prev!=-1) {
                    c1=arr[i].charAt(j);
                    c2=arr[prev].charAt(j);
                    if (((i-prev)%2==1)==((c1=='1' || c1=='4')==(c2=='1' || c2=='4'))) val=false;
                }
                val2=false;
                prev=i;
            }
            if (val2) ret++;
        }
        out.printLine(val?pot[ret]:0);
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
    public int id34();
    public Edge id3();
    public int id26();
    public Edge id30();
    public int getID();
    public void remove();
    public void restore();
}

class Graph {
    public static final int id35 = 0;

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
    private long[] capacity;
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
            graph.id21(from[i], to[i]);
        return graph;
    }

    public static Graph id2(int vertexCount, int[] from, int[] to, long[] weight) {
        Graph graph = new Graph(vertexCount, from.length);
        for (int i = 0; i < from.length; i++)
            graph.id1(from[i], to[i], weight[i]);
        return graph;
    }

    public static Graph id24(int vertexCount, int[] from, int[] to, long[] capacity) {
        Graph graph = new Graph(vertexCount, from.length * 2);
        for (int i = 0; i < from.length; i++)
            graph.id11(from[i], to[i], capacity[i]);
        return graph;
    }

    public static Graph id13(int vertexCount, int[] from, int[] to, long[] weight, long[] capacity) {
        Graph graph = new Graph(vertexCount, from.length * 2);
        for (int i = 0; i < from.length; i++)
            graph.id14(from[i], to[i], weight[i], capacity[i]);
        return graph;
    }

    public static Graph createTree(int[] parent) {
        Graph graph = new Graph(parent.length + 1, parent.length);
        for (int i = 0; i < parent.length; i++)
            graph.id21(parent[i], i + 1);
        return graph;
    }

    public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
        id20(edgeCount + 1);
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

    public final int id14(int from, int to, long weight, long capacity) {
        if (capacity == 0) {
            return addEdge(from, to, weight, 0, -1);
        } else {
            int id18 = edgeCount;
            addEdge(to, from, -weight, 0, id18 + id19());
            return addEdge(from, to, weight, capacity, id18);
        }
    }

    protected int id19() {
        return 1;
    }

    public final int id11(int from, int to, long capacity) {
        return id14(from, to, 0, capacity);
    }

    public final int id1(int from, int to, long weight) {
        return id14(from, to, weight, 0);
    }

    public final int id21(int from, int to) {
        return id1(from, to, 0);
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
        id17(vertexCount + count);
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
        setFlag(id, id35);
    }

    public final void restoreEdge(int id) {
        removeFlag(id, id35);
    }

    public final boolean isRemoved(int id) {
        return flag(id, id35);
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

    protected void id20(int size) {
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

    private void id17(int size) {
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

        public int id34() {
            return transposed(id);
        }

        public Edge id3() {
            int reverseID = id34();
            if (reverseID == -1)
                return null;
            initEdges();
            return edge(reverseID);
        }

        public int id26() {
            return reverse(id);
        }

        public Edge id30() {
            int reverseID = id26();
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
    protected abstract void id7(int root, int left, int right, int from, int to, long delta, int middle);
    protected abstract void id15(int root, int left, int right, int from, int to, long delta, int middle);
    protected abstract void updateFull(int root, int left, int right, int from, int to, long delta);
    protected abstract long id10(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult);
    protected abstract void id12(int root, int left, int right, int from, int to, int middle);
    protected abstract long queryFull(int root, int left, int right, int from, int to);
    protected abstract long id0();

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

    protected void update(int root, int left, int right, int from, int to, long delta) {
        if (left > to || right < from)
            return;
        if (left >= from && right <= to) {
            updateFull(root, left, right, from, to, delta);
            return;
        }
        int middle = (left + right) >> 1;
        id15(root, left, right, from, to, delta, middle);
        update(2 * root + 1, left, middle, from, to, delta);
        update(2 * root + 2, middle + 1, right, from, to, delta);
        id7(root, left, right, from, to, delta, middle);
    }

    public long query(int from, int to) {
        return query(0, 0, size - 1, from, to);
    }

    protected long query(int root, int left, int right, int from, int to) {
        if (left > to || right < from)
            return id0();
        if (left >= from && right <= to)
            return queryFull(root, left, right, from, to);
        int middle = (left + right) >> 1;
        id12(root, left, right, from, to, middle);
        long leftResult = query(2 * root + 1, left, middle, from, to);
        long rightResult = query(2 * root + 2, middle + 1, right, from, to);
        return id10(root, left, right, from, to, middle, leftResult, rightResult);
    }
}

abstract class id16 extends IntervalTree {
    protected long[] value;
    protected long[] array;

    protected id16(long[] array) {
        super(array.length, false);
        this.array = array;
        init();
    }

    @Override
    protected void initData(int size, int nodeCount) {
        value = new long[nodeCount];
    }

    @Override
    protected void initAfter(int root, int left, int right, int middle) {
        value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
    }

    @Override
    protected void initBefore(int root, int left, int right, int middle) {
    }

    @Override
    protected void initLeaf(int root, int index) {
        value[root] = array[index];
    }

    @Override
    protected void id7(int root, int left, int right, int from, int to, long delta, int middle) {
        throw new UnsupportedOperationException();
    }

    @Override
    protected void id15(int root, int left, int right, int from, int to, long delta, int middle) {
        throw new UnsupportedOperationException();
    }

    @Override
    protected void updateFull(int root, int left, int right, int from, int to, long delta) {
        throw new UnsupportedOperationException();
    }

    @Override
    protected long id10(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult) {
        return joinValue(leftResult, rightResult);
    }

    @Override
    protected void id12(int root, int left, int right, int from, int to, int middle) {
    }

    @Override
    protected long queryFull(int root, int left, int right, int from, int to) {
        return value[root];
    }

    @Override
    protected long id0() {
        return neutralValue();
    }

    @Override
    public void update(int from, int to, long delta) {
        throw new UnsupportedOperationException();
    }

    @Override
    protected void update(int root, int left, int right, int from, int to, long delta) {
        throw new UnsupportedOperationException();
    }

    protected abstract long neutralValue();
    protected abstract long joinValue(long left, long right);
}

class LCA {
    private final long[] order;
    private final int[] position;
    private final Graph graph;
    private final IntervalTree id29;
    private final int[] level;

    public LCA(Graph graph) {
        this(graph, 0);
    }

    public LCA(Graph graph, int root) {
        this.graph = graph;
        order = new long[2 * graph.vertexCount() - 1];
        position = new int[graph.vertexCount()];
        level = new int[graph.vertexCount()];
        int[] index = new int[graph.vertexCount()];
        for (int i = 0; i < index.length; i++)
            index[i] = graph.firstOutbound(i);
        int[] last = new int[graph.vertexCount()];
        int[] stack = new int[graph.vertexCount()];
        stack[0] = root;
        int size = 1;
        int j = 0;
        last[root] = -1;
        Arrays.fill(position, -1);
        while (size > 0) {
            int vertex = stack[--size];
            if (position[vertex] == -1)
                position[vertex] = j;
            order[j++] = vertex;
            if (last[vertex] != -1)
                level[vertex] = level[last[vertex]] + 1;
            while (index[vertex] != -1 && last[vertex] == graph.destination(index[vertex]))
                index[vertex] = graph.nextOutbound(index[vertex]);
            if (index[vertex] != -1) {
                stack[size++] = vertex;
                stack[size++] = graph.destination(index[vertex]);
                last[graph.destination(index[vertex])] = vertex;
                index[vertex] = graph.nextOutbound(index[vertex]);
            }
        }
        id29 = new id16(order) {
            @Override
            protected long joinValue(long left, long right) {
                if (left == -1)
                    return right;
                if (right == -1)
                    return left;
                if (level[((int) left)] < level[((int) right)])
                    return left;
                return right;
            }

            @Override
            protected long neutralValue() {
                return -1;
            }
        };
        id29.init();
    }

    public int getPosition(int vertex) {
        return position[vertex];
    }

    public int id31(int first, int second) {
        return (int) id29.query(Math.min(position[first], position[second]), Math.max(position[first], position[second]));
    }

    public int getLevel(int vertex) {
        return level[vertex];
    }

    public int id25(int first, int second) {
        return level[first] + level[second] - 2 * level[id31(first, second)];
    }

    private int calculate(int vertex, int last, int currentPosition) {
        if (last != -1)
            level[vertex] = level[last] + 1;
        position[vertex] = currentPosition;
        order[currentPosition++] = vertex;
        for (int i = graph.firstOutbound(vertex); i != -1; i = graph.nextOutbound(i)) {
            int to = graph.destination(i);
            if (to != last) {
                currentPosition = calculate(to, vertex, currentPosition);
                order[currentPosition++] = vertex;
            }
        }
        return currentPosition;
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id33 filter;

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

    public String readString() {
        int c = read();
        while (id9(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            if (Character.isValidCodePoint(c))
                res.appendCodePoint(c);
            c = read();
        } while (!id9(c));
        return res.toString();
    }

    public boolean id9(int c) {
        if (filter != null)
            return filter.id9(c);
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

    public String readLine(boolean id32) {
        if (id32)
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
        while (id9(c))
            c = read();
        return (char) c;
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

    public boolean id8() {
        int value;
        while (id9(value = peek()) && value != -1)
            read();
        return value == -1;
    }

    public String next() {
        return readString();
    }

    public id33 getFilter() {
        return filter;
    }

    public void setFilter(id33 filter) {
        this.filter = filter;
    }

    public interface id33 {
        public boolean id9(int ch);
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