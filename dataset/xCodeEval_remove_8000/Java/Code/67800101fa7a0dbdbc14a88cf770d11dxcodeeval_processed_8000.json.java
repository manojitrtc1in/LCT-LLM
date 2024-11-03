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

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int n = in.readInt();
		int[][] p=new int[n][n];
		for (int i=0; i<n; i++) for (int j=0; j<n; j++) p[i][j]=in.readInt();
		double[] retain = new double[n];
		Arrays.fill(retain, 1);
		double[] answer = new double[n];
		double[] id19 = new double[n];
		Arrays.fill(answer, Double.POSITIVE_INFINITY);
		answer[n - 1] = 0;
		boolean[] processed = new boolean[n];
		for (int i = 0; i < n; i++) {
			double best = Double.POSITIVE_INFINITY;
			int at = -1;
			for (int j = 0; j < n; j++) {
				if (!processed[j] && best > answer[j]) {
					best = answer[j];
					at = j;
				}
			}
			if (at == -1) {
				break;
			}
			processed[at] = true;
			for (int j = 0; j < n; j++) {
				if (processed[j] || p[j][at] == 0 || retain[j] == 0) {
					continue;
				}
				double id8 = id19[j] + retain[j] * p[j][at] / 100d * (answer[at]);
				double id1 = retain[j] * (1 - p[j][at] / 100d);
				double nAnswer = (1 + id8) / (1 - id1);
				if (nAnswer < answer[j]) {
					id19[j] = id8;
					retain[j] = id1;
					answer[j] = nAnswer;
				}
			}
		}
		out.printLine(answer[0]);
	}
}

class InputReader {
	private boolean finished = false;

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
		while (id2(c))
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
		} while (!id2(c));
		return res * sgn;
	}

	public long readLong() {
		int c = read();
		while (id2(c))
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
		} while (!id2(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (id2(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!id2(c));
		return res.toString();
	}

	public boolean id2(int c) {
		if (filter != null)
			return filter.id2(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String id15() {
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
		String s = id15();
		while (s.trim().length() == 0)
			s = id15();
		return s;
	}

	public String readLine(boolean id49) {
		if (id49)
			return readLine();
		else
			return id15();
	}

	public BigInteger id7() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (id2(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (id2(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!id2(c) && c != '.') {
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
			while (!id2(c)) {
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

	public boolean id16() {
		int value;
		while (id2(value = peek()) && value != -1)
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
		public boolean id2(int ch);
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
		for (Iterator<Integer> iterator = collection.iterator(); iterator
				.hasNext(); iterator.next()) {
			if (first)
				first = false;
			else
				writer.print(' ');
			writer.print(iterator);
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

	public Point[] id20(Point point) {
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

class GeometryUtils {
	public static double epsilon = 1e-4;

	public static double id47(double... x) {
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

	public static double id47(double x, double y) {
		return Math.sqrt(x * x + y * y);
	}

	public static double id47(double[] x, double[] y) {
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

	public static double id47(int[] x, int[] y) {
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

	public static double id14(double v, double angle,
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
		double h = GeometryUtils.id47(a, b);
		this.a = a / h;
		this.b = b / h;
		this.c = c / h;
	}

	public Point intersect(Line other) {
		if (parallel(other))
			return null;
		double id38 = b * other.a - a * other.b;
		double x = (c * other.b - b * other.c) / id38;
		double y = (a * other.c - c * other.a) / id38;
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
		return GeometryUtils.id47(x - other.x, y - other.y);
	}

	public double distance(Line line) {
		return Math.abs(line.a * x + line.b * y + line.c);
	}

	public double value() {
		return GeometryUtils.id47(x, y);
	}

	public double angle() {
		return Math.atan2(y, x);
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

	public static Polygon id29(Point[] points) {
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
		return line.contains(point)
				&& perpendicular.value(point) > -GeometryUtils.epsilon;
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
		return GeometryUtils
				.canonicalAngle(other.point.angle() - point.angle());
	}

	public double length() {
		return point.value();
	}

	public double angle() {
		return point.angle();
	}
}

class MaxFlow {
	private final Graph graph;
	private int source;
	private int destination;
	private int[] queue;
	private int[] distance;
	private int[] nextEdge;

	public MaxFlow(Graph graph, int source, int destination) {
		this.graph = graph;
		this.source = source;
		this.destination = destination;
		int vertexCount = graph.vertexCount();
		queue = new int[vertexCount];
		distance = new int[vertexCount];
		nextEdge = new int[vertexCount];
	}

	public static long dinic(Graph graph, int source, int destination) {
		return new MaxFlow(graph, source, destination).dinic();
	}

	public long dinic() {
		long totalFlow = 0;
		while (true) {
			edgeDistances();
			if (distance[destination] == -1)
				break;
			Arrays.fill(nextEdge, -2);
			totalFlow += id36(source, Long.MAX_VALUE);
		}
		return totalFlow;
	}

	private void edgeDistances() {
		Arrays.fill(distance, -1);
		distance[source] = 0;
		int size = 1;
		queue[0] = source;
		for (int i = 0; i < size; i++) {
			int current = queue[i];
			int id = graph.firstOutbound(current);
			while (id != -1) {
				if (graph.capacity(id) != 0) {
					int next = graph.destination(id);
					if (distance[next] == -1) {
						distance[next] = distance[current] + 1;
						queue[size++] = next;
					}
				}
				id = graph.nextOutbound(id);
			}
		}
	}

	private long id36(int source, long flow) {
		if (source == destination)
			return flow;
		if (flow == 0 || distance[source] == distance[destination])
			return 0;
		int id = nextEdge[source];
		if (id == -2)
			nextEdge[source] = id = graph.firstOutbound(source);
		long id10 = 0;
		while (id != -1) {
			int id40 = graph.destination(id);
			if (graph.capacity(id) != 0
					&& distance[id40] == distance[source] + 1) {
				long pushed = id36(id40,
						Math.min(flow, graph.capacity(id)));
				if (pushed != 0) {
					graph.pushFlow(id, pushed);
					flow -= pushed;
					id10 += pushed;
					if (flow == 0)
						return id10;
				}
			}
			nextEdge[source] = id = graph.nextOutbound(id);
		}
		return id10;
	}
}

class Graph {
	public static final int id50 = 0;

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
			graph.id6(from[i], to[i]);
		return graph;
	}

	public static Graph id12(int vertexCount, int[] from,
			int[] to, long[] weight) {
		Graph graph = new Graph(vertexCount, from.length);
		for (int i = 0; i < from.length; i++)
			graph.id0(from[i], to[i], weight[i]);
		return graph;
	}

	public static Graph id30(int vertexCount, int[] from, int[] to,
			long[] capacity) {
		Graph graph = new Graph(vertexCount, from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id18(from[i], to[i], capacity[i]);
		return graph;
	}

	public static Graph id24(int vertexCount, int[] from,
			int[] to, long[] weight, long[] capacity) {
		Graph graph = new Graph(vertexCount, from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id25(from[i], to[i], weight[i], capacity[i]);
		return graph;
	}

	public static Graph createTree(int[] parent) {
		Graph graph = new Graph(parent.length + 1, parent.length);
		for (int i = 0; i < parent.length; i++)
			graph.id6(parent[i], i + 1);
		return graph;
	}

	public int addEdge(int fromID, int toID, long weight, long capacity,
			int reverseEdge) {
		id28(edgeCount + 1);
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
			int id42 = edgeCount;
			addEdge(to, from, -weight, 0, id42 + id5());
			return addEdge(from, to, weight, capacity, id42);
		}
	}

	protected int id5() {
		return 1;
	}

	public final int id18(int from, int to, long capacity) {
		return id25(from, to, 0, capacity);
	}

	public final int id0(int from, int to, long weight) {
		return id25(from, to, weight, 0);
	}

	public final int id6(int from, int to) {
		return id0(from, to, 0);
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
		id27(vertexCount + count);
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
		setFlag(id, id50);
	}

	public final void restoreEdge(int id) {
		removeFlag(id, id50);
	}

	public final boolean isRemoved(int id) {
		return flag(id, id50);
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

	protected void id28(int size) {
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

	private void id27(int size) {
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

		public Edge id37() {
			int reverseID = id34();
			if (reverseID == -1)
				return null;
			initEdges();
			return edge(reverseID);
		}

		public int id9() {
			return reverse(id);
		}

		public Edge id31() {
			int reverseID = id9();
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

	public int id34();

	public Edge id37();

	public int id9();

	public Edge id31();

	public int getID();

	public void remove();

	public void restore();
}

class id17 extends Graph {
	public int[] id13;

	public id17(int vertexCount) {
		this(vertexCount, vertexCount);
	}

	public id17(int vertexCount, int edgeCapacity) {
		super(vertexCount, 2 * edgeCapacity);
		id13 = new int[2 * edgeCapacity];
	}

	public static id17 createGraph(int vertexCount, int[] from,
			int[] to) {
		id17 graph = new id17(vertexCount,
				from.length);
		for (int i = 0; i < from.length; i++)
			graph.id6(from[i], to[i]);
		return graph;
	}

	public static id17 id12(int vertexCount,
			int[] from, int[] to, long[] weight) {
		id17 graph = new id17(vertexCount,
				from.length);
		for (int i = 0; i < from.length; i++)
			graph.id0(from[i], to[i], weight[i]);
		return graph;
	}

	public static id17 id30(int vertexCount,
			int[] from, int[] to, long[] capacity) {
		id17 graph = new id17(vertexCount,
				from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id18(from[i], to[i], capacity[i]);
		return graph;
	}

	public static id17 id24(int vertexCount,
			int[] from, int[] to, long[] weight, long[] capacity) {
		id17 graph = new id17(vertexCount,
				from.length * 2);
		for (int i = 0; i < from.length; i++)
			graph.id25(from[i], to[i], weight[i], capacity[i]);
		return graph;
	}

	@Override
	public int addEdge(int fromID, int toID, long weight, long capacity,
			int reverseEdge) {
		int id42 = edgeCount;
		super.addEdge(fromID, toID, weight, capacity, reverseEdge);
		super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1
				: reverseEdge + 1);
		this.id13[id42] = id42 + 1;
		this.id13[id42 + 1] = id42;
		return id42;
	}

	@Override
	protected int id5() {
		return 2;
	}

	@Override
	public final int transposed(int id) {
		return id13[id];
	}

	@Override
	protected void id28(int size) {
		if (size > edgeCapacity()) {
			super.id28(size);
			id13 = resize(id13, edgeCapacity());
		}
	}
}

class DFSOrder {
	public final int[] position;
	public final int[] end;

	public DFSOrder(Graph graph) {
		this(graph, 0);
	}

	public DFSOrder(Graph graph, int root) {
		int count = graph.vertexCount();
		position = new int[count];
		end = new int[count];
		int[] edge = new int[count];
		int[] stack = new int[count];
		for (int i = 0; i < count; i++)
			edge[i] = graph.firstOutbound(i);
		stack[0] = root;
		int size = 1;
		position[root] = 0;
		int index = 0;
		while (size > 0) {
			int current = stack[size - 1];
			if (edge[current] == -1) {
				end[current] = index;
				size--;
			} else {
				int next = graph.destination(edge[current]);
				edge[current] = graph.nextOutbound(edge[current]);
				position[next] = ++index;
				stack[size++] = next;
			}
		}
	}

	public DFSOrder(id17 graph) {
		this(graph, 0);
	}

	public DFSOrder(id17 graph, int root) {
		int count = graph.vertexCount();
		position = new int[count];
		end = new int[count];
		int[] edge = new int[count];
		int[] stack = new int[count];
		int[] last = new int[count];
		for (int i = 0; i < count; i++)
			edge[i] = graph.firstOutbound(i);
		stack[0] = root;
		last[root] = -1;
		int size = 1;
		position[root] = 0;
		int index = 0;
		while (size > 0) {
			int current = stack[size - 1];
			if (edge[current] == -1) {
				end[current] = index;
				size--;
			} else {
				int next = graph.destination(edge[current]);
				if (next == last[current]) {
					edge[current] = graph.nextOutbound(edge[current]);
					continue;
				}
				edge[current] = graph.nextOutbound(edge[current]);
				position[next] = ++index;
				last[next] = current;
				stack[size++] = next;
			}
		}
	}
}

class GraphAlgorithms {
	public static int[] id26(Graph graph) {
		int count = graph.vertexCount();
		int[] queue = new int[count];
		int[] degree = new int[count];
		int size = 0;
		for (int i = 0; i < graph.edgeCount(); i++) {
			if (!graph.isRemoved(i))
				degree[graph.destination(i)]++;
		}
		for (int i = 0; i < count; i++) {
			if (degree[i] == 0)
				queue[size++] = i;
		}
		for (int i = 0; i < size; i++) {
			int current = queue[i];
			for (int j = graph.firstOutbound(current); j != -1; j = graph
					.nextOutbound(j)) {
				int next = graph.destination(j);
				if (--degree[next] == 0)
					queue[size++] = next;
			}
		}
		if (size != count)
			return null;
		return queue;
	}
}

class id43 {
	private final Graph graph;
	private final int source;
	private final int destination;
	private final long[] phi;
	private final long[] id35;
	private final int[] lastEdge;
	private final Heap heap;
	private final int vertexCount;
	private final int[] visited;
	private int visitIndex;

	public id43(Graph graph, int source, int destination,
			boolean id32) {
		this.graph = graph;
		this.source = source;
		this.destination = destination;
		vertexCount = graph.vertexCount();
		phi = new long[vertexCount];
		if (id32)
			id44();
		id35 = new long[vertexCount];
		lastEdge = new int[vertexCount];
		if (graph.isSparse()) {
			heap = new Heap(vertexCount, new IntComparator() {
				public int compare(int first, int second) {
					return IntegerUtils.longCompare(id35[first],
							id35[second]);
				}
			}, vertexCount);
			visited = null;
		} else {
			heap = null;
			visited = new int[vertexCount];
		}
	}

	private void id44() {
		Arrays.fill(phi, Long.MAX_VALUE);
		phi[source] = 0;
		boolean[] inQueue = new boolean[vertexCount];
		int[] queue = new int[vertexCount + 1];
		queue[0] = source;
		inQueue[source] = true;
		int stepCount = 0;
		int head = 0;
		int end = 1;
		int maxSteps = 2 * vertexCount * vertexCount;
		while (head != end) {
			int vertex = queue[head++];
			if (head == queue.length)
				head = 0;
			inQueue[vertex] = false;
			int edgeID = graph.firstOutbound(vertex);
			while (edgeID != -1) {
				long total = phi[vertex] + graph.weight(edgeID);
				int destination = graph.destination(edgeID);
				if (graph.capacity(edgeID) != 0 && phi[destination] > total) {
					phi[destination] = total;
					if (!inQueue[destination]) {
						queue[end++] = destination;
						inQueue[destination] = true;
						if (end == queue.length)
							end = 0;
					}
				}
				edgeID = graph.nextOutbound(edgeID);
			}
			if (++stepCount > maxSteps)
				throw new IllegalArgumentException(
						"Graph contains negative cycle");
		}
	}

	public static Pair<Long, Long> id4(Graph graph, int source,
			int destination, boolean id32) {
		return new id43(graph, source, destination, id32)
				.id4();
	}

	public static Pair<Long, Long> id4(Graph graph, int source,
			int destination, boolean id32, long maxFlow) {
		return new id43(graph, source, destination, id32)
				.id4(maxFlow);
	}

	public Pair<Long, Long> id4() {
		return id4(Long.MAX_VALUE);
	}

	public Pair<Long, Long> id4(long maxFlow) {
		long cost = 0;
		long flow = 0;
		while (maxFlow != 0) {
			if (graph.isSparse())
				id21();
			else
				id22();
			if (lastEdge[destination] == -1)
				return Pair.makePair(cost, flow);
			for (int i = 0; i < id35.length; i++) {
				if (id35[i] != Long.MAX_VALUE)
					phi[i] += id35[i];
			}
			int vertex = destination;
			long currentFlow = maxFlow;
			long currentCost = 0;
			while (vertex != source) {
				int edgeID = lastEdge[vertex];
				currentFlow = Math.min(currentFlow, graph.capacity(edgeID));
				currentCost += graph.weight(edgeID);
				vertex = graph.source(edgeID);
			}
			maxFlow -= currentFlow;
			cost += currentCost * currentFlow;
			flow += currentFlow;
			vertex = destination;
			while (vertex != source) {
				int edgeID = lastEdge[vertex];
				graph.pushFlow(edgeID, currentFlow);
				vertex = graph.source(edgeID);
			}
		}
		return Pair.makePair(cost, flow);
	}

	private void id21() {
		Arrays.fill(id35, Long.MAX_VALUE);
		Arrays.fill(lastEdge, -1);
		id35[source] = 0;
		heap.add(source);
		while (!heap.isEmpty()) {
			int current = heap.poll();
			int edgeID = graph.firstOutbound(current);
			while (edgeID != -1) {
				if (graph.capacity(edgeID) != 0) {
					int next = graph.destination(edgeID);
					long total = graph.weight(edgeID) - phi[next]
							+ phi[current] + id35[current];
					if (id35[next] > total) {
						id35[next] = total;
						if (heap.getIndex(next) == -1)
							heap.add(next);
						else
							heap.shiftUp(heap.getIndex(next));
						lastEdge[next] = edgeID;
					}
				}
				edgeID = graph.nextOutbound(edgeID);
			}
		}
	}

	private void id22() {
		visitIndex++;
		Arrays.fill(id35, Long.MAX_VALUE);
		lastEdge[destination] = -1;
		id35[source] = 0;
		for (int i = 0; i < vertexCount; i++) {
			int index = -1;
			long length = Long.MAX_VALUE;
			for (int j = 0; j < vertexCount; j++) {
				if (visited[j] != visitIndex && id35[j] < length) {
					length = id35[j];
					index = j;
				}
			}
			if (index == -1) {
				return;
			}
			visited[index] = visitIndex;
			int edgeID = graph.firstOutbound(index);
			while (edgeID != -1) {
				if (graph.capacity(edgeID) != 0) {
					int next = graph.destination(edgeID);
					if (visited[next] != visitIndex) {
						long total = graph.weight(edgeID) - phi[next]
								+ phi[index] + length;
						if (id35[next] > total) {
							id35[next] = total;
							lastEdge[next] = edgeID;
						}
					}
				}
				edgeID = graph.nextOutbound(edgeID);
			}
		}
	}
}

class id23 {
	public static Set<Integer> minimalTree(final id17 graph) {
		Set<Integer> result = new HashSet<>(graph.vertexCount - 1);
		int[] edgeOrder = new int[graph.edgeCount >> 1];
		for (int i = 0; i < edgeOrder.length; i++)
			edgeOrder[i] = i << 1;
		ArrayUtils.sort(edgeOrder, new IntComparator() {
			public int compare(int first, int second) {
				return IntegerUtils.longCompare(graph.weight(first),
						graph.weight(second));
			}
		});
		id41 setSystem = new id39(
				graph.vertexCount);
		for (int i : edgeOrder) {
			if (setSystem.join(graph.source(i), graph.destination(i)))
				result.add(i);
		}
		if (setSystem.id11() == 1)
			return result;
		else
			return null;
	}
}

class ShortestDistance {
	public static Pair<long[], int[]> id21(Graph graph, int source) {
		int vertexCount = graph.vertexCount();
		final long[] distance = new long[vertexCount];
		int[] last = new int[vertexCount];
		Arrays.fill(distance, Long.MAX_VALUE);
		Arrays.fill(last, -1);
		distance[source] = 0;
		if (graph.isSparse()) {
			Heap heap = new Heap(vertexCount, new IntComparator() {
				public int compare(int first, int second) {
					return IntegerUtils.longCompare(distance[first],
							distance[second]);
				}
			}, vertexCount);
			heap.add(source);
			while (!heap.isEmpty()) {
				int current = heap.poll();
				int id = graph.firstOutbound(current);
				while (id != -1) {
					int next = graph.destination(id);
					long total = graph.weight(id) + distance[current];
					if (distance[next] > total) {
						distance[next] = total;
						if (heap.getIndex(next) == -1)
							heap.add(next);
						else
							heap.shiftUp(heap.getIndex(next));
						last[next] = id;
					}
					id = graph.nextOutbound(id);
				}
			}
		} else {
			boolean[] visited = new boolean[vertexCount];
			for (int i = 0; i < vertexCount; i++) {
				int index = -1;
				long length = Long.MAX_VALUE;
				for (int j = 0; j < vertexCount; j++) {
					if (!visited[j] && distance[j] < length) {
						length = distance[j];
						index = j;
					}
				}
				if (index == -1)
					break;
				visited[index] = true;
				int id = graph.firstOutbound(index);
				while (id != -1) {
					int next = graph.destination(id);
					if (!visited[next]) {
						long total = graph.weight(id) + length;
						if (distance[next] > total) {
							distance[next] = total;
							last[next] = id;
						}
					}
					id = graph.nextOutbound(id);
				}
			}
		}
		return Pair.makePair(distance, last);
	}

	public static Pair<Long, List<Integer>> id21(Graph graph,
			int source, int destination) {
		if (source == destination)
			return Pair.makePair(0L, (List<Integer>) new ArrayList<Integer>());
		Pair<long[], int[]> result = id21(graph, source);
		if (result.second[destination] == -1)
			return null;
		List<Integer> path = new ArrayList<>();
		int id = destination;
		while (id != source) {
			path.add(result.second[id]);
			id = graph.source(result.second[id]);
		}
		Collections.reverse(path);
		return Pair.makePair(result.first[destination], path);
	}
}

class id45 {
	private final Graph graph;
	private int[] order;
	private boolean[] visited;
	private int index = 0;
	private int vertexCount;
	private int[] condensed;
	private Set<Integer> next;

	private boolean[] cutPoints, bridges;

	private id45(Graph graph) {
		this.graph = graph;
		vertexCount = graph.vertexCount();
		order = new int[vertexCount];
		visited = new boolean[vertexCount];
		condensed = new int[vertexCount];

		cutPoints = new boolean[vertexCount];
		bridges = new boolean[graph.edgeCount()];
	}

	public static Pair<int[], Graph> id48(Graph graph) {
		return new id45(graph).id48();
	}

	private Pair<int[], Graph> id48() {
		for (int i = 0; i < vertexCount; i++) {
			if (!visited[i])
				firstDFS(i);
		}
		Arrays.fill(visited, false);
		Graph result = new Graph(0);
		index = 0;
		for (int i = vertexCount - 1; i >= 0; i--) {
			if (!visited[order[i]]) {
				next = new HashSet<Integer>();
				secondDFS(order[i]);
				result.addVertices(1);
				for (int set : next)
					result.id6(set, index);
				index++;
			}
		}
		return Pair.makePair(condensed, result);
	}

	private void secondDFS(int vertexID) {
		if (visited[vertexID]) {
			if (condensed[vertexID] != index)
				next.add(condensed[vertexID]);
			return;
		}
		condensed[vertexID] = index;
		visited[vertexID] = true;
		int edgeID = graph.firstInbound(vertexID);
		while (edgeID != -1) {
			secondDFS(graph.source(edgeID));
			edgeID = graph.nextInbound(edgeID);
		}
	}

	private void firstDFS(int vertexID) {
		if (visited[vertexID])
			return;
		visited[vertexID] = true;
		int edgeID = graph.firstOutbound(vertexID);
		while (edgeID != -1) {
			firstDFS(graph.destination(edgeID));
			edgeID = graph.nextOutbound(edgeID);
		}
		order[index++] = vertexID;
	}

	public static Pair<boolean[], boolean[]> id3(Graph graph) {
		return new id45(graph).id3();
	}

	private Pair<boolean[], boolean[]> id3() {
		for (int i = 0; i < vertexCount; i++)
			if (!visited[i])
				dfs(i, -1);
		return Pair.makePair(cutPoints, bridges);
	}

	private void dfs(int u, int p) {
		visited[u] = true;
		condensed[u] = order[u] = index++;
		int children = 0;
		boolean cutPoint = false;
		for (int i = graph.firstOutbound(u); i != -1; i = graph.nextOutbound(i)) {
			int v = graph.destination(i);
			if (v == p)
				continue;
			if (visited[v])
				condensed[u] = Math.min(condensed[u], order[v]);
			else {
				dfs(v, u);
				condensed[u] = Math.min(condensed[u], condensed[v]);
				cutPoint |= condensed[v] >= order[u];
				if (condensed[v] > condensed[u]) {
					bridges[i] = true;
					int j = graph.transposed(i);
					if (j != -1)
						bridges[j] = true;
				}
				children++;
			}
		}
		if (p == -1)
			cutPoint = children >= 2;
		if (cutPoint)
			cutPoints[u] = true;
	}
}

class Heap {
	private IntComparator comparator;
	private int size = 0;
	private int[] elements;
	private int[] at;

	public Heap(int maxElement) {
		this(10, maxElement);
	}

	public Heap(IntComparator comparator, int maxElement) {
		this(10, comparator, maxElement);
	}

	public Heap(int capacity, int maxElement) {
		this(capacity, IntComparator.DEFAULT, maxElement);
	}

	public Heap(int capacity, IntComparator comparator, int maxElement) {
		this.comparator = comparator;
		elements = new int[capacity];
		at = new int[maxElement];
		Arrays.fill(at, -1);
	}

	public int getSize() {
		return size;
	}

	public void setComparator(IntComparator comparator) {
		this.comparator = comparator;
	}

	public boolean isEmpty() {
		return size == 0;
	}

	public int add(int element) {
		ensureCapacity(size + 1);
		elements[size] = element;
		at[element] = size;
		shiftUp(size++);
		return at[element];
	}

	public void shiftUp(int index) {
		

		

		int value = elements[index];
		while (index != 0) {
			int parent = (index - 1) >>> 1;
			int parentValue = elements[parent];
			if (comparator.compare(parentValue, value) <= 0) {
				elements[index] = value;
				at[value] = index;
				return;
			}
			elements[index] = parentValue;
			at[parentValue] = index;
			index = parent;
		}
		elements[0] = value;
		at[value] = 0;
	}

	public void shiftDown(int index) {
		if (index < 0 || index >= size)
			throw new IllegalArgumentException();
		while (true) {
			int child = (index << 1) + 1;
			if (child >= size)
				return;
			if (child + 1 < size
					&& comparator.compare(elements[child], elements[child + 1]) > 0)
				child++;
			if (comparator.compare(elements[index], elements[child]) <= 0)
				return;
			swap(index, child);
			index = child;
		}
	}

	public int getIndex(int element) {
		return at[element];
	}

	private void swap(int first, int second) {
		int temp = elements[first];
		elements[first] = elements[second];
		elements[second] = temp;
		at[elements[first]] = first;
		at[elements[second]] = second;
	}

	private void ensureCapacity(int size) {
		if (elements.length < size) {
			int[] oldElements = elements;
			elements = new int[Math.max(2 * elements.length, size)];
			System.arraycopy(oldElements, 0, elements, 0, this.size);
		}
	}

	public int peek() {
		if (isEmpty())
			throw new IndexOutOfBoundsException();
		return elements[0];
	}

	public int poll() {
		if (isEmpty())
			throw new IndexOutOfBoundsException();
		int result = elements[0];
		at[result] = -1;
		if (size == 1) {
			size = 0;
			return result;
		}
		elements[0] = elements[--size];
		at[elements[0]] = 0;
		shiftDown(0);
		return result;
	}

	public int remove(int element) {
		int index = getIndex(element);
		if (index == -1)
			throw new IndexOutOfBoundsException();
		int result = elements[index];
		at[result] = -1;
		if (index == size - 1) {
			size--;
			return result;
		}
		elements[index] = elements[--size];
		at[elements[index]] = index;
		shiftDown(index);
		shiftUp(index);
		return result;
	}

	public void clear() {
		size = 0;
		Arrays.fill(at, -1);
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

class IntegerUtils {
	public static int longCompare(long a, long b) {
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
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

	@Override
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

	@SuppressWarnings({ "unchecked" })
	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>) first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>) second).compareTo(o.second);
	}
}

class ArrayUtils {
	public static int[] sort(int[] array, IntComparator comparator) {
		return sort(array, 0, array.length, comparator);
	}

	public static int[] sort(int[] array, int from, int to,
			final IntComparator comparator) {
		Comparator<Integer> id46 = new Comparator<Integer>() {
			@Override
			public int compare(Integer x, Integer y) {
				return comparator.compare(x, y);
			}
		};
		Integer[] arr;
		if (from == 0 && to == array.length) {
			arr = new Integer[array.length];
			for (int i = 0; i < arr.length; i++)
				arr[i] = array[i];
			Arrays.sort(arr, id46);
			for (int i = 0; i < arr.length; i++)
				array[i] = arr[i];
		} else {
			arr = new Integer[to - from];
			for (int i = 0; i < arr.length; i++)
				arr[i] = array[from + i];
			Arrays.sort(arr, id46);
			for (int i = 0; i < arr.length; i++)
				array[from + i] = arr[i];
		}
		return array;
	}
}

interface id41 {
	public boolean join(int first, int second);

	public int get(int index);

	public int id11();

	public void setListener(Listener listener);

	public static interface Listener {
		public void joined(int joinedRoot, int root);
	}
}

class id39 implements id41 {
	private final int[] color;
	private final int[] rank;
	private int setCount;
	private Listener listener;

	public id39(int size) {
		color = new int[size];
		rank = new int[size];
		for (int i = 0; i < size; i++)
			color[i] = i;
		setCount = size;
	}

	public id39(id39 other) {
		color = other.color.clone();
		rank = other.rank.clone();
		setCount = other.setCount;
	}

	public boolean join(int first, int second) {
		first = get(first);
		second = get(second);
		if (first == second)
			return false;
		if (rank[first] < rank[second]) {
			int temp = first;
			first = second;
			second = temp;
		} else if (rank[first] == rank[second])
			rank[first]++;
		setCount--;
		color[second] = first;
		if (listener != null)
			listener.joined(second, first);
		return true;
	}

	public int get(int index) {
		if (color[index] == index)
			return index;
		return color[index] = get(color[index]);
	}

	public int id11() {
		return setCount;
	}

	public void setListener(Listener listener) {
		this.listener = listener;
	}
}