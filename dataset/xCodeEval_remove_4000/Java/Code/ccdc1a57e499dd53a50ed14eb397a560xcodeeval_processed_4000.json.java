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

class Task {

	int[] L, R, A, B, C, max, best;
	Integer[] orderV, orderC;
	IntervalTree tree;
	Map<Integer, Integer> map;
	
	class IntervalTree{
		
		long[] array;
		int n;
		
		IntervalTree(int n) {
			array=new long[4*n+1];
			this.n=n;
		}
		
		void update(int pos, long x) {
			update(0, 0, n-1, pos, x);
		}
		
		void update(int node, int left, int right, int pos, long val) {
			if (left==right) {
				array[node]=val;
				return;
			}
			int middle=(left+right)/2;
			if (pos<=middle) update(2*node+1, left, middle, pos, val);
			else update(2*node+2, middle+1, right, pos, val);
			array[node]=Math.max(array[2*node+1], array[2*node+2]);
		}
		
		long query(int from, int to) {
			return query(0, 0, n-1, from, to);
		}
		
		long query(int node, int left, int right, int from, int to) {
			if (left>to || right<from) return 0;
			if (left>=from && right<=to) return array[node];
			int middle=(left+right)/2;
			return Math.max(query(2*node+1, left, middle, from, to), query(2*node+2, middle+1, right, from, to));
		}
	}
	
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int n = in.readInt(), m = in.readInt(), idx = 0;
		boolean flag = n == 200000 && m==200000;
		L = new int[n];
		R = new int[n];
		A = new int[m];
		B = new int[m];
		C = new int[m];
		max = new int[m];
		best = new int[m];
		orderV=new Integer[n];
		orderC=new Integer[m];
		IOUtils.id12(in, L, R);
		IOUtils.id12(in, A, B, C);
		for (int i=0; i<n; i++) orderV[i]=i;
		for (int i=0; i<m; i++) orderC[i]=i;
		int[] arr=new int[2*(n+m)];
		for (int i=0; i<n; i++) {
			arr[2*i]=L[i];
			arr[2*i+1]=R[i];
		}
		for (int i=0; i<m; i++) {
			arr[2*(n+i)]=A[i];
			arr[2*(n+i)+1]=B[i];
		}
		Arrays.sort(arr);
		map=new HashMap<>();
		for (int i=0; i<arr.length; i++) if (i==0 || arr[i]!=arr[i-1])
			map.put(arr[i], idx++);
		tree = new IntervalTree(map.size());
		process1(n, m, out);
		process2(n, m);
		process3(n, m);
		long ret = 0;
		int aux = -1;
		for (int i = 0; i < m; i++) {
			long x = 1L * max[i] * C[i];
			if (x > ret) {
				ret = x;
				aux = i;
			}
		}
		out.printLine(ret);
		if (ret > 0)
			out.printLine(best[aux] + 1, aux + 1);
	}
	
	void process1(int n, int m, OutputWriter out) {
		Arrays.sort(orderV, new Comparator<Integer>(){
			public int compare(Integer a, Integer b) {
				return L[a]-L[b];
			}
		});
		Arrays.sort(orderC, new Comparator<Integer>(){
			public int compare(Integer a, Integer b) {
				return A[a]-A[b];
			}
		});




		int v=0, c=0, ret=0, idx=-1, x;
		while (v<n || c<m) {
			for (; v<n && (c==m || L[orderV[v]]<=A[orderC[c]]); v++) {
				x=orderV[v];
				if (R[x]>ret) {
					ret=R[x];
					idx=x;
				}
			}
			for (; c<m && (v==n || A[orderC[c]]<L[orderV[v]]); c++) {
				x=orderC[c];




				int length=Math.min(ret, B[x])-A[x];
				if (length>max[x]) {
					max[x]=length;
					best[x]=idx;
				}
			}
		}
	}
	
	void process2(int n, int m) {
		Arrays.sort(orderV, new Comparator<Integer>(){
			public int compare(Integer a, Integer b) {
				return R[a]-R[b];
			}
		});
		Arrays.sort(orderC, new Comparator<Integer>(){
			public int compare(Integer a, Integer b) {
				return B[a]-B[b];
			}
		});
		int v=0, c=0;
		while (v<n || c<m) {
			for (; v<n && (c==m || R[orderV[v]]<=B[orderC[c]]); v++) {
				int x=orderV[v];
				tree.update(map.get(L[x]), 1L*(R[x]-L[x])*n+x);
			}
			for (; c<m && (v==n || B[orderC[c]]<R[orderV[v]]); c++) {
				int x=orderC[c];
				long aux=tree.query(map.get(A[x]), map.get(B[x]));
				int length=(int)(aux/n), y=(int)(aux%n);
				if (length>max[x]) {
					max[x]=length;
					best[x]=y;
				}
			}
		}
	}
	
	void process3(int n, int m) {
		int v=n-1, c=m-1, ret=Integer.MAX_VALUE, idx=-1, x;
		while (v>=0 || c>=0) {
			for (; v>=0 && (c==-1 || R[orderV[v]]>=B[orderC[c]]); v--) {
				x=orderV[v];
				if (L[x]<ret) {
					ret=L[x];
					idx=x;
				}
			}
			for (; c>=0 && (v==-1 || B[orderC[c]]>R[orderV[v]]); c--) {
				x=orderC[c];
				int length=B[x]-Math.max(ret, A[x]);
				if (length>max[x]) {
					max[x]=length;
					best[x]=idx;
				}
			}
		}
	}
}

class InputReader {
	private boolean finished = false;

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private id19 filter;

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
		while (id7(c))
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
		} while (!id7(c));
		return res * sgn;
	}

	public long readLong() {
		int c = read();
		while (id7(c))
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
		} while (!id7(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (id7(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!id7(c));
		return res.toString();
	}

	public boolean id7(int c) {
		if (filter != null)
			return filter.id7(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String id2() {
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
		String s = id2();
		while (s.trim().length() == 0)
			s = id2();
		return s;
	}

	public String readLine(boolean id18) {
		if (id18)
			return readLine();
		else
			return id2();
	}

	public BigInteger id13() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (id7(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (id7(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!id7(c) && c != '.') {
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
			while (!id7(c)) {
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

	public boolean id6() {
		int value;
		while (id7(value = peek()) && value != -1)
			read();
		return value == -1;
	}

	public String next() {
		return readString();
	}

	public id19 getFilter() {
		return filter;
	}

	public void setFilter(id19 filter) {
		this.filter = filter;
	}

	public interface id19 {
		public boolean id7(int ch);
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

	public void print(Collection<Integer> collection) {
		boolean first = true;
		for (int i : collection) {
			if (first)
				first = false;
			else
				writer.print(' ');
			writer.print(i);
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

	public void printLine(Collection<Integer> collection) {
		print(collection);
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

class Polygon {
	public final Point[] vertices;
	private Segment[] sides;

	public Polygon(Point... vertices) {
		this.vertices = vertices.clone();
	}

	public double square() {
		double sum = 0;
		for (int i = 1; i < vertices.length; i++)
			sum += (vertices[i].x - vertices[i - 1].x)
					* (vertices[i].y + vertices[i - 1].y);
		sum += (vertices[0].x - vertices[vertices.length - 1].x)
				* (vertices[0].y + vertices[vertices.length - 1].y);
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

	public static Polygon id14(Point[] points) {
		if (points.length == 1)
			return new Polygon(points);
		Arrays.sort(points, new Comparator<Point>() {
			public int compare(Point o1, Point o2) {
				int value = Double.compare(o1.x, o2.x);
				if (value != 0)
					return value;
				return Double.compare(o1.y, o2.y);
			}
		});
		Point left = points[0];
		Point right = points[points.length - 1];
		List<Point> up = new ArrayList<Point>();
		List<Point> down = new ArrayList<Point>();
		for (Point point : points) {
			if (point == left || point == right || !under(left, point, right)) {
				while (up.size() >= 2
						&& under(up.get(up.size() - 2), up.get(up.size() - 1),
								point))
					up.remove(up.size() - 1);
				up.add(point);
			}
			if (point == left || point == right || !over(left, point, right)) {
				while (down.size() >= 2
						&& over(down.get(down.size() - 2),
								down.get(down.size() - 1), point))
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
		double totalAngle = GeometryUtils.canonicalAngle(Math.atan2(
				vertices[0].y - point.y, vertices[0].x - point.x)
				- Math.atan2(vertices[vertices.length - 1].y - point.y,
						vertices[vertices.length - 1].x - point.x));
		for (int i = 1; i < vertices.length; i++) {
			totalAngle += GeometryUtils.canonicalAngle(Math.atan2(vertices[i].y
					- point.y, vertices[i].x - point.x)
					- Math.atan2(vertices[i - 1].y - point.y, vertices[i - 1].x
							- point.x));
		}
		return Math.abs(totalAngle) > Math.PI;
	}

	public Segment[] sides() {
		if (sides == null) {
			sides = new Segment[vertices.length];
			for (int i = 0; i < vertices.length - 1; i++)
				sides[i] = new Segment(vertices[i], vertices[i + 1]);
			sides[sides.length - 1] = new Segment(
					vertices[vertices.length - 1], vertices[0]);
		}
		return sides;
	}

	public static double triangleSquare(Point a, Point b, Point c) {
		return Math.abs((a.x - b.x) * (a.y + b.y) + (b.x - c.x) * (b.y + c.y)
				+ (c.x - a.x) * (c.y + a.y)) / 2;
	}

	public double perimeter() {
		double result = vertices[0].distance(vertices[vertices.length - 1]);
		for (int i = 1; i < vertices.length; i++)
			result += vertices[i].distance(vertices[i - 1]);
		return result;
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

		return Math.abs(x - point.x) <= GeometryUtils.epsilon
				&& Math.abs(y - point.y) <= GeometryUtils.epsilon;
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
		return GeometryUtils.id16(x - other.x, y - other.y);
	}

	public double distance(Line line) {
		return Math.abs(line.a * x + line.b * y + line.c);
	}

	public double value() {
		return GeometryUtils.id16(x, y);
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
		if (contains(intersection, includeEnds)
				&& other.contains(intersection, includeEnds))
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
		return aValue < pointValue && pointValue < bValue
				|| bValue < pointValue && pointValue < aValue;
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
			return new Point[] { result[0] };
		}
		if (contains(result[1], true))
			return new Point[] { result[1] };
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
		Point p = line == null || otherLine == null ? null : line
				.intersect(otherLine);
		if (p != null && contains(p, true) && other.contains(p, true))
			return 0;
		return Math.min(Math.min(other.distance(a), other.distance(b)),
				Math.min(distance(other.a), distance(other.b)));
	}
}

class GeometryUtils {
	public static double epsilon = 1e-8;

	public static double id16(double... x) {
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

	public static double id16(double x, double y) {
		return Math.sqrt(x * x + y * y);
	}

	public static double id16(double[] x, double[] y) {
		if (x.length == 0)
			return 0;
		else if (x.length == 1)
			return Math.abs(x[0] - y[0]);
		else {
			double sumSquares = 0;
			for (int i = 0; i < x.length; i++) {
				double diff = x[i] - y[i];
				sumSquares += diff * diff;
			}
			return Math.sqrt(sumSquares);
		}
	}

	public static double id16(int[] x, int[] y) {
		if (x.length == 0)
			return 0;
		else if (x.length == 1)
			return Math.abs(x[0] - y[0]);
		else {
			double sumSquares = 0;
			for (int i = 0; i < x.length; i++) {
				double diff = x[i] - y[i];
				sumSquares += diff * diff;
			}
			return Math.sqrt(sumSquares);
		}
	}

	public static double id1(double v, double angle,
			double g) {
		return (v * v * Math.sin(2 * angle)) / g;
	}

	public static double sphereVolume(double radius) {
		return 4 * Math.PI * radius * radius * radius / 3;
	}

	public static double triangleSquare(double first, double second,
			double third) {
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
		double h = GeometryUtils.id16(a, b);
		this.a = a / h;
		this.b = b / h;
		this.c = c / h;
	}

	public Point intersect(Line other) {
		if (parallel(other))
			return null;
		double id4 = b * other.a - a * other.b;
		double x = (c * other.b - b * other.c) / id4;
		double y = (a * other.c - c * other.a) / id4;
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
			return new Point[] { intersection };
		double shift = Math.sqrt(circle.radius * circle.radius - distance
				* distance);
		return new Point[] {
				new Point(intersection.x + shift * b, intersection.y - shift
						* a),
				new Point(intersection.x - shift * b, intersection.y + shift
						* a) };
	}

	public double distance(Point center) {
		return Math.abs(value(center));
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;

		Line line = (Line) o;

		if (!parallel(line))
			return false;
		if (Math.abs(a * line.c - c * line.a) > GeometryUtils.epsilon
				|| Math.abs(b * line.c - c * line.b) > GeometryUtils.epsilon)
			return false;

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

	public Point[] id15(Point point) {
		double distance = center.distance(point);
		if (distance < radius - GeometryUtils.epsilon)
			return new Point[0];
		if (distance < radius + GeometryUtils.epsilon)
			return new Point[] { point };
		Circle power = new Circle(point, Math.sqrt((distance - radius)
				* (distance + radius)));
		return intersect(power);
	}

	public Point[] intersect(Circle other) {
		double distance = center.distance(other.center);
		if (distance > radius + other.radius + GeometryUtils.epsilon
				|| Math.abs(radius - other.radius) > distance
						+ GeometryUtils.epsilon)
			return new Point[0];
		double p = (radius + other.radius + distance) / 2;
		double height = 2
				* Math.sqrt(p * (p - radius) * (p - other.radius)
						* (p - distance)) / distance;
		double l1 = Math.sqrt(radius * radius - height * height);
		double l2 = Math.sqrt(other.radius * other.radius - height * height);
		if (radius * radius + distance * distance < other.radius * other.radius)
			l1 = -l1;
		if (radius * radius > distance * distance + other.radius * other.radius)
			l2 = -l2;
		Point middle = new Point((center.x * l2 + other.center.x * l1)
				/ (l1 + l2), (center.y * l2 + other.center.y * l1) / (l1 + l2));
		Line line = center.line(other.center).perpendicular(middle);
		return line.intersect(this);
	}
}

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static <U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;

		Pair pair = (Pair) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null)
				&& !(second != null ? !second.equals(pair.second)
						: pair.second != null);

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
		int value = ((Comparable<U>) first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>) second).compareTo(o.second);
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

class IOUtils {

	public static void id12(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

}

class id3<K> implements NavigableSet<K> {
	protected static final Random rnd = new Random(239);

	protected final Node nullNode;
	protected final Comparator<? super K> comparator;
	protected Node root;
	private final K from;
	private final K to;
	private final boolean fromInclusive;
	private final boolean toInclusive;

	public id3() {
		this((Comparator<? super K>) null);
	}

	public id3(Comparator<? super K> comparator) {
		this(null, null, false, false, comparator, null, null);
	}

	protected id3(K from, K to, boolean fromInclusive,
			boolean toInclusive, Comparator<? super K> comparator, Node root,
			Node nullNode) {
		this.comparator = comparator;
		this.from = from;
		this.to = to;
		this.fromInclusive = fromInclusive;
		this.toInclusive = toInclusive;
		if (nullNode == null)
			nullNode = new NullNode();
		if (root == null)
			root = nullNode;
		this.root = root;
		this.nullNode = nullNode;
	}

	public boolean addAll(Iterable<? extends K> collection) {
		boolean result = false;
		for (K element : collection)
			result |= add(element);
		return result;
	}

	public K lower(K k) {
		Node target = root.lower(k);
		if (target == nullNode)
			return null;
		if (belongs(target.key))
			return target.key;
		return null;
	}

	private boolean belongs(K key) {
		int valueFrom = compare(from, key);
		int valueTo = compare(key, to);
		return (valueFrom < 0 || valueFrom == 0 && fromInclusive)
				&& (valueTo < 0 || valueTo == 0 && toInclusive);
	}

	public K floor(K k) {
		Node target = root.floor(k);
		if (target == nullNode)
			return null;
		if (belongs(target.key))
			return target.key;
		return null;
	}

	public K ceiling(K k) {
		Node target = root.ceil(k);
		if (target == nullNode)
			return null;
		if (belongs(target.key))
			return target.key;
		return null;
	}

	public K higher(K k) {
		Node target = root.higher(k);
		if (target == nullNode)
			return null;
		if (belongs(target.key))
			return target.key;
		return null;
	}

	public K pollFirst() {
		K first = first();
		if (first == null)
			throw new NoSuchElementException();
		root.erase(first);
		return first;
	}

	public K pollLast() {
		K last = last();
		if (last == null)
			throw new NoSuchElementException();
		root.erase(last);
		return last;
	}

	public int size() {
		if (from == null && to == null)
			return root.size;
		if (from == null) {
			Node to = toInclusive ? root.floor(this.to) : root.lower(this.to);
			if (to == nullNode)
				return 0;
			return root.indexOf(to) + 1;
		}
		if (to == null) {
			Node from = fromInclusive ? root.ceil(this.from) : root
					.higher(this.from);
			if (from == nullNode)
				return 0;
			return root.size - root.indexOf(from);
		}
		Node from = fromInclusive ? root.ceil(this.from) : root
				.higher(this.from);
		if (from == nullNode || !belongs(from.key))
			return 0;
		Node to = toInclusive ? root.floor(this.to) : root.lower(this.to);
		return root.indexOf(to) - root.indexOf(from) + 1;
	}

	public boolean isEmpty() {
		return size() == 0;
	}

	public boolean contains(Object o) {
		return belongs((K) o) && root.search((K) o) != nullNode;
	}

	public Iterator<K> iterator() {
		return new Iterator<K>() {
			private K current = first();

			public boolean hasNext() {
				return current != null;
			}

			public K next() {
				K result = current;
				current = higher(current);
				return result;
			}

			public void remove() {
				id3.this.remove(current);
			}
		};
	}

	public Object[] toArray() {
		Object[] array = new Object[size()];
		int index = 0;
		for (K key : this)
			array[index++] = key;
		return array;
	}

	public <T> T[] toArray(T[] a) {
		if (a.length < size())
			throw new IllegalArgumentException();
		int index = 0;
		for (K key : this)
			a[index++] = (T) key;
		return a;
	}

	public boolean add(K k) {
		if (k == null)
			throw new NullPointerException();
		if (contains(k))
			return false;
		root = root.insert(createNode(k));
		return true;
	}

	protected Node createNode(K k) {
		return new Node(k, rnd.nextLong());
	}

	public boolean remove(Object o) {
		if (!contains(o))
			return false;
		

		root = root.erase((K) o);
		return true;
	}

	public boolean containsAll(Collection<?> c) {
		for (Object o : c) {
			if (!contains(o))
				return false;
		}
		return true;
	}

	public boolean addAll(Collection<? extends K> c) {
		return addAll((Iterable<? extends K>) c);
	}

	public boolean retainAll(Collection<?> c) {
		List<K> toRemove = new ArrayList<K>();
		for (K key : this) {
			if (!c.contains(key))
				toRemove.add(key);
		}
		return removeAll(toRemove);
	}

	public boolean removeAll(Collection<?> c) {
		boolean result = false;
		for (Object o : c)
			result |= remove(o);
		return result;
	}

	public void clear() {
		retainAll(Collections.<Object> emptySet());
	}

	public NavigableSet<K> descendingSet() {
		throw new UnsupportedOperationException();
	}

	public Iterator<K> descendingIterator() {
		return new Iterator<K>() {
			private K current = last();

			public boolean hasNext() {
				return current != null;
			}

			public K next() {
				K result = current;
				current = lower(current);
				return result;
			}

			public void remove() {
				id3.this.remove(current);
			}
		};
	}

	public NavigableSet<K> subSet(K fromElement, boolean fromInclusive,
			K toElement, boolean toInclusive) {
		return new id3<K>(fromElement, toElement, fromInclusive,
				toInclusive, comparator, root, nullNode);
	}

	public NavigableSet<K> headSet(K toElement, boolean inclusive) {
		return subSet(null, false, toElement, inclusive);
	}

	public NavigableSet<K> tailSet(K fromElement, boolean inclusive) {
		return subSet(fromElement, inclusive, null, false);
	}

	public Comparator<? super K> comparator() {
		return comparator;
	}

	public SortedSet<K> subSet(K fromElement, K toElement) {
		return subSet(fromElement, true, toElement, false);
	}

	public SortedSet<K> headSet(K toElement) {
		return subSet(null, false, toElement, false);
	}

	public SortedSet<K> tailSet(K fromElement) {
		return tailSet(fromElement, true);
	}

	public K first() {
		if (isEmpty())
			return null;
		if (from == null)
			return root.first().key;
		if (fromInclusive)
			return ceiling(from);
		return higher(from);
	}

	public K last() {
		if (isEmpty())
			return null;
		if (to == null)
			return root.last().key;
		if (toInclusive)
			return floor(to);
		return lower(to);
	}

	protected int compare(K first, K second) {
		if (first == null || second == null)
			return -1;
		if (comparator != null)
			return comparator.compare(first, second);
		

		return ((Comparable<? super K>) first).compareTo(second);
	}

	protected class Node {
		protected final K key;
		protected final long priority;
		protected Node left;
		protected Node right;
		protected int size;

		protected Node(K key, long priority) {
			this.key = key;
			this.priority = priority;
			left = nullNode;
			right = nullNode;
			size = 1;
		}

		protected Object[] split(K key) {
			if (compare(key, this.key) < 0) {
				Object[] result = left.split(key);
				left = (Node) result[1];
				result[1] = this;
				updateSize();
				return result;
			}
			Object[] result = right.split(key);
			right = (Node) result[0];
			result[0] = this;
			updateSize();
			return result;
		}

		protected void updateSize() {
			size = left.size + right.size + 1;
		}

		protected Node insert(Node node) {
			if (node.priority > priority) {
				Object[] result = split(node.key);
				node.left = (Node) result[0];
				node.right = (Node) result[1];
				node.updateSize();
				return node;
			}
			if (compare(node.key, this.key) < 0) {
				left = left.insert(node);
				updateSize();
				return this;
			}
			right = right.insert(node);
			updateSize();
			return this;
		}

		protected Node merge(Node left, Node right) {
			if (left == nullNode)
				return right;
			if (right == nullNode)
				return left;
			if (left.priority > right.priority) {
				left.right = left.right.merge(left.right, right);
				left.updateSize();
				return left;
			}
			right.left = right.left.merge(left, right.left);
			right.updateSize();
			return right;
		}

		protected Node erase(K key) {
			int value = compare(key, this.key);
			if (value == 0)
				return merge(left, right);
			if (value < 0) {
				left = left.erase(key);
				updateSize();
				return this;
			}
			right = right.erase(key);
			updateSize();
			return this;
		}

		protected Node lower(K key) {
			if (compare(key, this.key) <= 0)
				return left.lower(key);
			Node result = right.lower(key);
			if (result == nullNode)
				return this;
			return result;
		}

		protected Node floor(K key) {
			if (compare(key, this.key) < 0)
				return left.floor(key);
			Node result = right.floor(key);
			if (result == nullNode)
				return this;
			return result;
		}

		protected Node higher(K key) {
			if (compare(key, this.key) >= 0)
				return right.higher(key);
			Node result = left.higher(key);
			if (result == nullNode)
				return this;
			return result;
		}

		protected Node ceil(K key) {
			if (compare(key, this.key) > 0)
				return right.ceil(key);
			Node result = left.ceil(key);
			if (result == nullNode)
				return this;
			return result;
		}

		protected Node first() {
			if (left == nullNode)
				return this;
			return left.first();
		}

		protected Node last() {
			if (right == nullNode)
				return this;
			return right.last();
		}

		protected Node search(K key) {
			int value = compare(key, this.key);
			if (value == 0)
				return this;
			if (value < 0)
				return left.search(key);
			return right.search(key);
		}

		public int indexOf(Node node) {
			if (this == node)
				return left.size;
			if (compare(node.key, this.key) > 0)
				return left.size + 1 + right.indexOf(node);
			return left.indexOf(node);
		}

	}

	private class NullNode extends Node {
		private Object[] splitResult = new Object[2];

		private NullNode() {
			super(null, Long.MIN_VALUE);
			left = this;
			right = this;
			size = 0;
		}

		protected Object[] split(K key) {
			splitResult[0] = splitResult[1] = this;
			return splitResult;
		}

		protected Node insert(Node node) {
			return node;
		}

		protected Node erase(K key) {
			return this;
		}

		protected Node lower(K key) {
			return this;
		}

		protected Node floor(K key) {
			return this;
		}

		protected Node higher(K key) {
			return this;
		}

		protected Node ceil(K key) {
			return this;
		}

		protected Node first() {
			throw new NoSuchElementException();
		}

		protected Node last() {
			throw new NoSuchElementException();
		}

		protected void updateSize() {
		}

		protected Node search(K key) {
			return this;
		}

	}
}

class id11<E, V> extends AbstractMap<E, V> {
	private static final int[] shifts = new int[10];

	private int size;
	private HashEntry<E, V>[] data;
	private int capacity;
	private Set<Entry<E, V>> entrySet;

	static {
		Random random = new Random(System.currentTimeMillis());
		for (int i = 0; i < 10; i++)
			shifts[i] = 1 + 3 * i + random.nextInt(3);
	}

	public id11() {
		this(4);
	}

	private void setCapacity(int size) {
		capacity = Integer.highestOneBit(4 * size);
		

		data = new HashEntry[capacity];
	}

	public id11(int maxSize) {
		setCapacity(maxSize);
		entrySet = new AbstractSet<Entry<E, V>>() {
			public Iterator<Entry<E, V>> iterator() {
				return new Iterator<Entry<E, V>>() {
					private HashEntry<E, V> last = null;
					private HashEntry<E, V> current = null;
					private HashEntry<E, V> base = null;
					private int lastIndex = -1;
					private int index = -1;

					public boolean hasNext() {
						if (current == null) {
							for (index++; index < capacity; index++) {
								if (data[index] != null) {
									base = current = data[index];
									break;
								}
							}
						}
						return current != null;
					}

					public Entry<E, V> next() {
						if (!hasNext())
							throw new NoSuchElementException();
						last = current;
						lastIndex = index;
						current = current.next;
						if (base.next != last)
							base = base.next;
						return last;
					}

					public void remove() {
						if (last == null)
							throw new IllegalStateException();
						size--;
						if (base == last)
							data[lastIndex] = last.next;
						else
							base.next = last.next;
					}
				};
			}

			public int size() {
				return size;
			}
		};
	}

	public Set<Entry<E, V>> entrySet() {
		return entrySet;
	}

	public void clear() {
		Arrays.fill(data, null);
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
		HashEntry<E, V> current = data[index];
		HashEntry<E, V> last = null;
		while (current != null) {
			if (current.key.equals(o)) {
				if (last == null)
					data[index] = current.next;
				else
					last.next = current.next;
				size--;
				return current.value;
			}
			last = current;
			current = current.next;
		}
		return null;
	}

	public V put(E e, V value) {
		if (e == null)
			return null;
		int index = index(e);
		HashEntry<E, V> current = data[index];
		if (current != null) {
			while (true) {
				if (current.key.equals(e)) {
					V oldValue = current.value;
					current.value = value;
					return oldValue;
				}
				if (current.next == null)
					break;
				current = current.next;
			}
		}
		if (current == null)
			data[index] = new HashEntry<E, V>(e, value);
		else
			current.next = new HashEntry<E, V>(e, value);
		size++;
		if (2 * size > capacity) {
			HashEntry<E, V>[] oldData = data;
			setCapacity(size);
			for (HashEntry<E, V> entry : oldData) {
				while (entry != null) {
					HashEntry<E, V> next = entry.next;
					index = index(entry.key);
					entry.next = data[index];
					data[index] = entry;
					entry = next;
				}
			}
		}
		return null;
	}

	public V get(Object o) {
		if (o == null)
			return null;
		int index = index(o);
		HashEntry<E, V> current = data[index];
		while (current != null) {
			if (current.key.equals(o))
				return current.value;
			current = current.next;
		}
		return null;
	}

	public boolean containsKey(Object o) {
		if (o == null)
			return false;
		int index = index(o);
		HashEntry<E, V> current = data[index];
		while (current != null) {
			if (current.key.equals(o))
				return true;
			current = current.next;
		}
		return false;
	}

	public int size() {
		return size;
	}

	private static class HashEntry<E, V> implements Entry<E, V> {
		private final E key;
		private V value;
		private HashEntry<E, V> next;

		private HashEntry(E key, V value) {
			this.key = key;
			this.value = value;
		}

		public E getKey() {
			return key;
		}

		public V getValue() {
			return value;
		}

		public V setValue(V value) {
			V oldValue = this.value;
			this.value = value;
			return oldValue;
		}
	}
}

abstract class IntervalTree {
	protected int size;

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

	protected abstract void id5(int root, int left, int right,
			int from, int to, long delta, int middle);

	protected abstract void id10(int root, int left, int right,
			int from, int to, long delta, int middle);

	protected abstract void updateFull(int root, int left, int right, int from,
			int to, long delta);

	protected abstract long id8(int root, int left, int right,
			int from, int to, int middle, long leftResult, long rightResult);

	protected abstract void id9(int root, int left, int right,
			int from, int to, int middle);

	protected abstract long queryFull(int root, int left, int right, int from,
			int to);

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

	protected void update(int root, int left, int right, int from, int to,
			long delta) {
		if (left > to || right < from)
			return;
		if (left >= from && right <= to) {
			updateFull(root, left, right, from, to, delta);
			return;
		}
		int middle = (left + right) >> 1;
		id10(root, left, right, from, to, delta, middle);
		update(2 * root + 1, left, middle, from, to, delta);
		update(2 * root + 2, middle + 1, right, from, to, delta);
		id5(root, left, right, from, to, delta, middle);
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
		id9(root, left, right, from, to, middle);
		long leftResult = query(2 * root + 1, left, middle, from, to);
		long rightResult = query(2 * root + 2, middle + 1, right, from, to);
		return id8(root, left, right, from, to, middle,
				leftResult, rightResult);
	}
}

abstract class id17 extends IntervalTree {
	protected long[] value;
	protected long[] delta;

	protected id17(int size) {
		this(size, true);
	}

	public id17(int size, boolean shouldInit) {
		super(size, shouldInit);
	}

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

	protected void initAfter(int root, int left, int right, int middle) {
		value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
		delta[root] = neutralDelta();
	}

	protected void initBefore(int root, int left, int right, int middle) {
	}

	protected void initLeaf(int root, int index) {
		value[root] = initValue(index);
		delta[root] = neutralDelta();
	}

	protected void id5(int root, int left, int right, int from,
			int to, long delta, int middle) {
		value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
	}

	protected void id10(int root, int left, int right, int from,
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

	protected void updateFull(int root, int left, int right, int from, int to,
			long delta) {
		value[root] = accumulate(value[root], delta, right - left + 1);
		this.delta[root] = joinDelta(this.delta[root], delta);
	}

	protected long id8(int root, int left, int right, int from,
			int to, int middle, long leftResult, long rightResult) {
		return joinValue(leftResult, rightResult);
	}

	protected void id9(int root, int left, int right, int from,
			int to, int middle) {
		pushDown(root, left, middle, right);
	}

	protected long queryFull(int root, int left, int right, int from, int to) {
		return value[root];
	}

	protected long id0() {
		return neutralValue();
	}
}