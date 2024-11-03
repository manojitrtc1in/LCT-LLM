import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		Task solver = new C();
		solver.solve(1, in, out);
		out.close();
	}
}

interface Task {
	public void solve(int testNumber, InputReader in, OutputWriter out);
}

class A implements Task {
	
	public void solve(int testNumber, InputReader in, OutputWriter out){
		int n=in.readInt(), m=in.readInt(), ret=1, r=m;
		for (int i=0; i<n; i++) {
			int x=in.readInt();
			if (x>r) {
				ret++;
				r=m-x;
			}
			else r-=x;


		}
		out.printLine(ret);
	}
}

class B implements Task {

	int[] arr;
	ArrayList<Integer> lista=new ArrayList<Integer>();
	
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		for (long a=in.readLong(); a>0; a/=10) lista.add((int)(a%10));
		int k=in.readInt();
		arr=CollectionUtils.toArray(lista);
		int n=arr.length;
		for (int i=0, j=n-1; i<j; i++, j--) {
			arr[i]^=arr[j];
			arr[j]^=arr[i];
			arr[i]^=arr[j];
		}
		for (int i=0; i<n; i++) {
			int max=arr[i], pos=i;
			for (int j=i+1; j<n; j++) if (arr[j]>max && j-i<=k) {
				max=arr[j];
				pos=j;
			}


			k-=pos-i;
			for (int j=pos; j>i; j--) arr[j]=arr[j-1];
			arr[i]=max;
		}
		long ret=0L;
		for (int i=0; i<n; i++) ret=10L*ret+arr[i];
		out.printLine(ret);
	}

}

class C implements Task {

	ArrayList<Pair<Integer, Integer>> lista=new ArrayList<Pair<Integer, Integer>>();
	ArrayList<StringBuilder> tab=new ArrayList<StringBuilder>();
	
	public void solve(int testNumber, InputReader in, OutputWriter out){
		int n=in.readInt(), xmin=1000, ymin=1000, xmax=0, ymax=-1000, x=0, y=0;
		lista.add(Pair.makePair(0, 0));
		for (int i=1; i<=n; i++) {
			int a=in.readInt();
			lista.add(Pair.makePair(lista.get(i-1).first+a, lista.get(i-1).second+(i%2==1?a:-a)));
		}


		for (Pair<Integer, Integer> par: lista) {
			xmin=Math.min(xmin, par.first);
			xmax=Math.max(xmax, par.first);
			ymin=Math.min(ymin, par.second);
			ymax=Math.max(ymax, par.second);
		}


		int k=ymax;
		char last=' ';
		for (int i=0; i<ymax-ymin; i++) tab.add(new StringBuilder());
		for (int i=1; i<=n; i++) {
			int x2=lista.get(i).first, y2=lista.get(i).second, newk;
			if (i==1) {
				if (y2>y) k--;
			}
			else if (y2>y && last=='\\') k--;
			else if (y2<y && last=='/') k++;
			for (int j=0; x!=x2; j++, x++) {
				for (int l=0; l<k; l++) tab.get(l).append(' ');
				if (y2>y) {
					y++;
					tab.get(k).append('/');
					last='/';
					newk=k-1;
				}
				else {
					y--;
					tab.get(k).append('\\');
					last='\\';
					newk=k+1;
				}
				for (int l=k+1; l<tab.size(); l++) tab.get(l).append(' ');
				k=newk;


			}
		}
		for (StringBuilder sb: tab) {


			out.printLine(sb);
		}
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

	public Point[] id21(Point point) {
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

	public static double id47(double...x) {
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

	public static double id47(int[] x, int[] y) {
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

	public static double id8(double v, double angle, double g) {
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
		double h = GeometryUtils.id47(a, b);
		this.a = a / h;
		this.b = b / h;
		this.c = c / h;
	}

	public Point intersect(Line other) {
		if (parallel(other))
			return null;
		double id39 = b * other.a - a * other.b;
		double x = (c * other.b - b * other.c) / id39;
		double y = (a * other.c - c * other.a) / id39;
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

	public static Polygon id30(Point[] points) {
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

class Date implements Comparable<Date> {
	private static final int[] id46 = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	public static final String[] id49 = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

	public final int year;
	public final int month;
	public final int day;
	private int weekday;

	public Date(int year, int month, int day) {
		this.year = year;
		this.month = month;
		this.day = day;
		weekday = -1;
	}

	public int id32() {
		if (weekday == -1) {
			weekday = asInt();
			weekday += 6;
			weekday %= 7;
		}
		return weekday;
	}

	public int asInt() {
		int day = (year - 1) * 365;
		day += (year - 1) / 4;
		day -= (year - 1) / 100;
		day += (year - 1) / 400;
		for (int i = 1; i < month; i++)
			day += id46[i];
		day += this.day;
		if (id6(year) && month > 2)
			day++;
		return day;
	}

	public boolean isValid() {
		return !(month > 12 || month < 1) && !(day > id46[month] &&
				(day != 29 || month != 2 || !id6(year))) && day >= 1;
	}

	public Date next() {
		int year = this.year;
		int month = this.month;
		int day = this.day;
		day++;
		Date next = new Date(year, month, day);
		if (!next.isValid())
			next = new Date(year, month + 1, 1);
		if (!next.isValid())
			next = new Date(year + 1, 1, 1);
		if (weekday != -1)
			next.weekday = (weekday + 1) % 7;
		return next;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Date date = (Date) o;

		return day == date.day && month == date.month && year == date.year;
	}

	@Override
	public int hashCode() {
		int result = year;
		result = 31 * result + month;
		result = 31 * result + day;
		return result;
	}

	public static Date parse(String date, String pattern) {
		int length = date.length();
		if (length != pattern.length())
			throw new IllegalArgumentException();
		int year = 0;
		int month = 0;
		int day = 0;
		for (int i = 0; i < length; i++) {
			if (Character.toUpperCase(pattern.charAt(i)) == 'Y') {
				year *= 10;
				year += date.charAt(i) - '0';
			} else if (Character.toUpperCase(pattern.charAt(i)) == 'M') {
				month *= 10;
				month += date.charAt(i) - '0';
			} else if (Character.toUpperCase(pattern.charAt(i)) == 'D') {
				day *= 10;
				day += date.charAt(i) - '0';
			}
		}
		return new Date(year, month, day);
	}

	public static boolean id6(int year) {
		return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	}

	public int compareTo(Date o) {
		return asInt() - o.asInt();
	}

	@Override
	public String toString() {
		return toString("DD.MM.YYYY");
	}

	public String toString(String pattern) {
		int copyYear = year;
		int copyMonth = month;
		int copyDay = day;
		StringBuilder result = new StringBuilder();
		for (int i = pattern.length() - 1; i >= 0; i--) {
			char character = pattern.charAt(i);
			switch (character) {
			case 'D': case 'd':
				result.append(copyDay % 10);
				copyDay /= 10;
				break;
			case 'M': case 'm':
				result.append(copyMonth % 10);
				copyMonth /= 10;
				break;
			case 'Y': case 'y':
				result.append(copyYear % 10);
				copyYear /= 10;
				break;
			default:
				result.append(character);
			}
		}
		return result.reverse().toString();
	}
}

class id29 {
	public static Time timePassed(Time from, Time to) {
		int hours = to.getHours() - from.getHours();
		int minutes = to.getMinutes() - from.getMinutes();
		int seconds = to.getSeconds() - from.getSeconds();
		if (seconds < 0) {
			seconds += 60;
			minutes--;
		}
		if (minutes < 0) {
			minutes += 60;
			hours--;
		}
		if (hours < 0)
			hours += 24;
		return new Time(hours, minutes, seconds);
	}
}

enum Month {
	NULL(null),
	JANUARY("January"),
	FEBRUARY("February"),
	MARCH("March"),
	APRIL("April"),
	MAY("May"),
	JUNE("June"),
	JULY("July"),
	AUGUST("August"),
	SEPTEMBER("September"),
	OCTOBER("October"),
	NOVEMBER("November"),
	DECEMBER("December");

	public final String longName;
	public final String shortName;

	private Month(String longName) {
		this.longName = longName;
		shortName = longName == null ? null : longName.substring(0, 3);
	}
}

class Time implements Comparable<Time> {
	private final int hours;
	private final int minutes;
	private final int seconds;

	public static Time parse(String time, String pattern) {
		int length = time.length();
		if (length != pattern.length())
			throw new IllegalArgumentException();
		int hours = 0;
		int minutes = 0;
		int seconds = 0;
		for (int i = 0; i < length; i++) {
			if (Character.toUpperCase(pattern.charAt(i)) == 'H') {
				hours *= 10;
				hours += time.charAt(i) - '0';
			} else if (Character.toUpperCase(pattern.charAt(i)) == 'M') {
				minutes *= 10;
				minutes += time.charAt(i) - '0';
			} else if (Character.toUpperCase(pattern.charAt(i)) == 'S') {
				seconds *= 10;
				seconds += time.charAt(i) - '0';
			}
		}
		return new Time(hours, minutes, seconds);
	}

	public Time(int hours, int minutes, int seconds) {
		this.hours = hours;
		this.minutes = minutes;
		this.seconds = seconds;
	}

	public int getHours() {
		return hours;
	}

	public int getMinutes() {
		return minutes;
	}

	public int getSeconds() {
		return seconds;
	}

	public boolean isValid() {
		return hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60;
	}

	@Override
	public String toString() {
		return toString("HH:MM:SS");
	}

	public String toString(String pattern) {
		int copyHours = hours;
		int copyMinutes = minutes;
		int copySeconds = seconds;
		StringBuilder result = new StringBuilder();
		for (int i = pattern.length() - 1; i >= 0; i--) {
			char character = pattern.charAt(i);
			switch (character) {
			case 'S': case 's':
				result.append(copySeconds % 10);
				copySeconds /= 10;
				break;
			case 'M': case 'm':
				result.append(copyMinutes % 10);
				copyMinutes /= 10;
				break;
			case 'H': case 'h':
				result.append(copyHours % 10);
				copyHours /= 10;
				break;
			default:
				result.append(character);
			}
		}
		return result.reverse().toString();
	}

	public int totalMinutes() {
		return hours * 60 + minutes;
	}

	public Time normalize() {
		if (isValid())
			return this;
		int copySeconds = seconds;
		int copyMinutes = minutes;
		int copyHours = hours;
		copyMinutes += IntegerUtils.trueDivide(copySeconds, 60);
		copySeconds = IntegerUtils.trueMod(copySeconds, 60);
		copyHours += IntegerUtils.trueDivide(copyMinutes, 60);
		copyMinutes = IntegerUtils.trueMod(copyMinutes, 60);
		copyHours = IntegerUtils.trueMod(copyHours, 24);
		return new Time(copyHours, copyMinutes, copySeconds);
	}

	public int totalSeconds() {
		return totalMinutes() * 60 + seconds;
	}

	public int compareTo(Time o) {
		return totalSeconds() - o.totalSeconds();
	}

	public Time advance(int seconds) {
		int total = totalSeconds() + seconds;
		return new Time(total / (60 * 60), total / 60 % 60, total % 60);
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Time time = (Time) o;

		if (hours != time.hours) return false;
		if (minutes != time.minutes) return false;
		if (seconds != time.seconds) return false;

		return true;
	}

	@Override
	public int hashCode() {
		int result = hours;
		result = 31 * result + minutes;
		result = 31 * result + seconds;
		return result;
	}
}

class BooleanMatrix {
	public final boolean[][] data;
	public final int rowCount;
	public final int columnCount;

	public BooleanMatrix(int rowCount, int columnCount) {
		this.rowCount = rowCount;
		this.columnCount = columnCount;
		this.data = new boolean[rowCount][columnCount];
	}

	public static BooleanMatrix add(BooleanMatrix first, BooleanMatrix second) {
		BooleanMatrix result = new BooleanMatrix(first.rowCount, first.columnCount);
		for (int i = 0; i < result.rowCount; i++) {
			for (int j = 0; j < result.columnCount; j++) {
				result.data[i][j] = first.data[i][j] || second.data[i][j];
			}
		}
		return result;
	}

	public static BooleanMatrix multiply(BooleanMatrix first, BooleanMatrix second) {
		BooleanMatrix result = new BooleanMatrix(first.rowCount, second.columnCount);
		for (int i = 0; i < first.rowCount; i++) {
			for (int j = 0; j < second.rowCount; j++) {
				for (int k = 0; k < second.columnCount; k++)
					result.data[i][k] |= first.data[i][j] && second.data[j][k];
			}
		}
		return result;
	}

	public static BooleanMatrix identityMatrix(int size) {
		BooleanMatrix result = new BooleanMatrix(size, size);
		for (int i = 0; i < size; i++)
			result.data[i][i] = true;
		return result;
	}

	public BooleanMatrix power(int exponent) {
		if (exponent == 0)
			return identityMatrix(rowCount);
		if (exponent == 1)
			return this;
		BooleanMatrix result = power(exponent >> 1);
		result = multiply(result, result);
		if ((exponent & 1) == 1)
			result = multiply(result, this);
		return result;
	}
}

class DoubleUtils {
	public static double id19(double p, double q) {
		return p / (1 - q);
	}
}

class id31 {
	public static void fft(double[] a, double[] b, boolean invert) {
		int count = a.length;
		for (int i = 1, j = 0; i < count; i++) {
			int bit = count >> 1;
		for (; j >= bit; bit >>= 1)
			j -= bit;
		j += bit;
		if (i < j) {
			double temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			temp = b[i];
			b[i] = b[j];
			b[j] = temp;
		}
		}
		for (int len = 2; len <= count; len <<= 1) {
			int halfLen = len >> 1;
		double angle = 2 * Math.PI / len;
		if (invert)
			angle = -angle;
		double id20 = Math.cos(angle);
		double id0 = Math.sin(angle);
		for (int i = 0; i < count; i += len) {
			double wA = 1;
			double wB = 0;
			for (int j = 0; j < halfLen; j++) {
				double uA = a[i + j];
				double uB = b[i + j];
				double vA = a[i + j + halfLen] * wA - b[i + j + halfLen] * wB;
				double vB = a[i + j + halfLen] * wB + b[i + j + halfLen] * wA;
				a[i + j] = uA + vA;
				b[i + j] = uB + vB;
				a[i + j + halfLen] = uA - vA;
				b[i + j + halfLen] = uB - vB;
				double nextWA = wA * id20 - wB * id0;
				wB = wA * id0 + wB * id20;
				wA = nextWA;
			}
		}
		}
		if (invert) {
			for (int i = 0; i < count; i++) {
				a[i] /= count;
				b[i] /= count;
			}
		}
	}

	public static long[] multiply(long[] a, long[] b) {
		int resultSize = Integer.highestOneBit(Math.max(a.length, b.length) - 1) << 2;
		resultSize = Math.max(resultSize, 1);
		double[] aReal = new double[resultSize];
		double[] id28 = new double[resultSize];
		double[] bReal = new double[resultSize];
		double[] id24 = new double[resultSize];
		for (int i = 0; i < a.length; i++)
			aReal[i] = a[i];
		for (int i = 0; i < b.length; i++)
			bReal[i] = b[i];
		fft(aReal, id28, false);
		if (a == b) {
			System.arraycopy(aReal, 0, bReal, 0, aReal.length);
			System.arraycopy(id28, 0, id24, 0, id28.length);
		} else
			fft(bReal, id24, false);
		for (int i = 0; i < resultSize; i++) {
			double real = aReal[i] * bReal[i] - id28[i] * id24[i];
			id28[i] = id28[i] * bReal[i] + id24[i] * aReal[i];
			aReal[i] = real;
		}
		fft(aReal, id28, true);
		long[] result = new long[resultSize];
		for (int i = 0; i < resultSize; i++)
			result[i] = Math.round(aReal[i]);
		return result;
	}
}

class IntegerUtils {
	public static long gcd(long a, long b) {
		a = Math.abs(a);
		b = Math.abs(b);
		while (b != 0) {
			long temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}

	public static int gcd(int a, int b) {
		a = Math.abs(a);
		b = Math.abs(b);
		while (b != 0) {
			int temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}

	public static int[] id34(int upTo) {
		int[] isPrime = id11(upTo);
		ArrayList<Integer> primes = new ArrayList<Integer>();
		for (int i = 0; i < upTo; i++) {
			if ((isPrime[i >> 5] >>> (i & 31) & 1) == 1)
				primes.add(i);
		}
		return CollectionUtils.toArray(primes);
	}

	public static boolean[] id12(int upTo) {
		boolean[] isPrime = new boolean[upTo];
		if (upTo < 2)
			return isPrime;
		Arrays.fill(isPrime, true);
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i * i < upTo; i++) {
			if (isPrime[i]) {
				for (int j = i * i; j < upTo; j += i)
					isPrime[j] = false;
			}
		}
		return isPrime;
	}

	public static int[] id11(int upTo) {
		int[] isPrime = new int[(upTo + 31) >> 5];
		if (upTo < 2)
			return isPrime;
		Arrays.fill(isPrime, -1);
		isPrime[0] &= -4;
		for (int i = 2; i * i < upTo; i++) {
			if ((isPrime[i >> 5] >>> (i & 31) & 1) == 1) {
				for (int j = i * i; j < upTo; j += i)
					isPrime[j >> 5] &= -1 - (1 << (j & 31));
			}
		}
		return isPrime;
	}

	public static int[] id10(int upTo) {
		int[] divisor = new int[upTo];
		for (int i = 1; i < upTo; i++)
			divisor[i] = i;
		for (int i = 2; i * i < upTo; i++) {
			if (divisor[i] == i) {
				for (int j = i * i; j < upTo; j += i)
					divisor[j] = i;
			}
		}
		return divisor;
	}

	public static long id44(long n, long p) {
		long result = 0;
		while (n != 0) {
			result += n /= p;
		}
		return result;
	}

	public static int sumDigits(CharSequence number) {
		int result = 0;
		for (int i = number.length() - 1; i >= 0; i--)
			result += digitValue(number.charAt(i));
		return result;
	}

	public static int digitValue(char digit) {
		if (Character.isDigit(digit))
			return digit - '0';
		if (Character.isUpperCase(digit))
			return digit + 10 - 'A';
		return digit + 10 - 'a';
	}

	public static int longCompare(long a, long b) {
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

	public static long[][] id33(int n) {
		long[][] result = new long[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			result[i][0] = 1;
			for (int j = 1; j <= i; j++)
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
		return result;
	}

	public static long[][] id33(int n, long module) {
		long[][] result = new long[n + 1][n + 1];
		if (module == 1)
			return result;
		for (int i = 0; i <= n; i++) {
			result[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
				if (result[i][j] >= module)
					result[i][j] -= module;
			}
		}
		return result;
	}

	public static long[] id43(int n, long module) {
		long[] result = generateReverse(n + 1, module);
		result[0] = 1;
		for (int i = 1; i <= n; i++)
			result[i] = result[i - 1] * (n - i + 1) % module * result[i] % module;
		return result;
	}

	public static int[] id36(long number, int base) {
		long basePower = base;
		int exponent = 1;
		while (number >= basePower) {
			basePower *= base;
			exponent++;
		}
		int[] representation = new int[exponent];
		for (int i = 0; i < exponent; i++) {
			basePower /= base;
			representation[i] = (int) (number / basePower);
			number %= basePower;
		}
		return representation;
	}

	public static int trueDivide(int a, int b) {
		return (a - trueMod(a, b)) / b;
	}

	public static long trueDivide(long a, long b) {
		return (a - trueMod(a, b)) / b;
	}

	public static int trueMod(int a, int b) {
		a %= b;
		a += b;
		a %= b;
		return a;
	}

	public static long trueMod(long a, long b) {
		a %= b;
		a += b;
		a %= b;
		return a;
	}

	public static long factorial(int n) {
		long result = 1;
		for (int i = 2; i <= n; i++)
			result *= i;
		return result;
	}

	public static long factorial(int n, long mod) {
		long result = 1;
		for (int i = 2; i <= n; i++)
			result = result * i % mod;
		return result % mod;
	}

	public static List<Pair<Long, Integer>> factorize(long number) {
		List<Pair<Long, Integer>> result = new ArrayList<Pair<Long, Integer>>();
		for (long i = 2; i * i <= number; i++) {
			if (number % i == 0) {
				int power = 0;
				do {
					power++;
					number /= i;
				} while (number % i == 0);
				result.add(Pair.makePair(i, power));
			}
		}
		if (number != 1)
			result.add(Pair.makePair(number, 1));
		return result;
	}

	public static List<Long> id7(long number) {
		List<Pair<Long, Integer>> id35 = factorize(number);
		return id26(id35, 0, 1, new ArrayList<Long>());
	}

	private static List<Long> id26(List<Pair<Long, Integer>> id35, int index, long current,
			List<Long> result)
			{
		if (index == id35.size()) {
			result.add(current);
			return result;
		}
		long p = id35.get(index).first;
		int power = id35.get(index).second;
		for (int i = 0; i <= power; i++) {
			id26(id35, index + 1, current, result);
			current *= p;
		}
		return result;
			}

	public static long power(long base, long exponent) {
		if (exponent == 0)
			return 1;
		long result = power(base, exponent >> 1);
		result = result * result;
		if ((exponent & 1) != 0)
			result = result * base;
		return result;
	}

	public static long power(long base, long exponent, long mod) {
		if (base >= mod)
			base %= mod;
		if (exponent == 0)
			return 1 % mod;
		long result = power(base, exponent >> 1, mod);
		result = result * result % mod;
		if ((exponent & 1) != 0)
			result = result * base % mod;
		return result;
	}

	public static long lcm(long a, long b) {
		return a / gcd(a, b) * b;
	}

	public static long[] id16(long upTo) {
		int count = 0;
		long last = 0;
		long current = 1;
		while (current <= upTo) {
			long next = last + current;
			last = current;
			current = next;
			count++;
		}
		return id16(count, -1);
	}

	public static long[] id16(int count, long module) {
		long[] result = new long[count];
		if (module == -1) {
			if (count != 0)
				result[0] = 1;
			if (count > 1)
				result[1] = 1;
			for (int i = 2; i < count; i++)
				result[i] = result[i - 1] + result[i - 2];
		} else {
			if (count != 0)
				result[0] = 1 % module;
			if (count > 1)
				result[1] = 1 % module;
			for (int i = 2; i < count; i++)
				result[i] = (result[i - 1] + result[i - 2]) % module;
		}
		return result;
	}

	public static long[] generateHappy(int digits) {
		long[] happy = new long[(1 << (digits + 1)) - 2];
		happy[0] = 4;
		happy[1] = 7;
		int first = 0;
		int last = 2;
		for (int i = 2; i <= digits; i++) {
			for (int j = 0; j < last - first; j++) {
				happy[last + 2 * j] = 10 * happy[first + j] + 4;
				happy[last + 2 * j + 1] = 10 * happy[first + j] + 7;
			}
			int next = last + 2 * (last - first);
			first = last;
			last = next;
		}
		return happy;
	}

	public static long[] id45(int count, long module) {
		long[] result = new long[count];
		if (module == -1) {
			if (count != 0)
				result[0] = 1;
			for (int i = 1; i < count; i++)
				result[i] = result[i - 1] * i;
		} else {
			if (count != 0)
				result[0] = 1 % module;
			for (int i = 1; i < count; i++)
				result[i] = (result[i - 1] * i) % module;
		}
		return result;
	}

	public static long reverse(long number, long module) {
		return power(number, module - 2, module);
	}

	public static boolean isPrime(long number) {
		if (number < 2)
			return false;
		for (long i = 2; i * i <= number; i++) {
			if (number % i == 0)
				return false;
		}
		return true;
	}

	public static long[] generateReverse(int upTo, long module) {
		long[] result = new long[upTo];
		if (upTo > 1)
			result[1] = 1;
		for (int i = 2; i < upTo; i++)
			result[i] = (module - module / i * result[((int) (module % i))] % module) % module;
		return result;
	}

	public static long[] id14(int upTo, long module) {
		long[] result = generateReverse(upTo, module);
		if (upTo > 0)
			result[0] = 1;
		for (int i = 1; i < upTo; i++)
			result[i] = result[i] * result[i - 1] % module;
		return result;
	}

	public static long[] id17(long base, int count, long mod) {
		long[] result = new long[count];
		if (count != 0)
			result[0] = 1 % mod;
		for (int i = 1; i < count; i++)
			result[i] = result[i - 1] * base % mod;
		return result;
	}

	public static long nextPrime(long from) {
		if (from <= 2)
			return 2;
		from += 1 - (from & 1);
		while (!isPrime(from))
			from += 2;
		return from;
	}

	public static long id22(int n, int m, long mod) {
		if (m < 0 || m > n)
			return 0;
		if (2 * m > n)
			m = n - m;
		long result = 1;
		for (int i = n - m + 1; i <= n; i++)
			result = result * i % mod;
		return result * BigInteger.valueOf(factorial(m, mod)).modInverse(BigInteger.valueOf(mod)).longValue() % mod;
	}

	public static boolean isSquare(long number) {
		long sqrt = Math.round(Math.sqrt(number));
		return sqrt * sqrt == number;
	}

	public static long findCommon(long id40, long aMod, long id5, long bMod) {
		long id4 = gcd(aMod, bMod);
		long id41 = id40 % id4;
		if (id41 != id5 % id4)
			return -1;
		aMod /= id4;
		id40 /= id4;
		bMod /= id4;
		id5 /= id4;
		long aReverse = BigInteger.valueOf(aMod).modInverse(BigInteger.valueOf(bMod)).longValue();
		long bReverse = BigInteger.valueOf(bMod).modInverse(BigInteger.valueOf(aMod)).longValue();
		long mod = aMod * bMod;
		return (bReverse * id40 % mod * bMod + aReverse * id5 % mod * aMod) % mod * id4 + id41;
	}

	public static long[] id17(long base, long maxValue) {
		if (maxValue <= 0)
			return new long[0];
		int size = 1;
		long current = 1;
		while (maxValue / base >= current) {
			current *= base;
			size++;
		}
		return id17(base, size, Long.MAX_VALUE);
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
					result.data[i][k] = (result.data[i][k] + first.data[i][j] * second.data[j][k]) % mod;
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

	public static long[] id23(long[] matrix, long exponent, long mod, int side) {
		long[] result = new long[matrix.length];
		long[] power = new long[matrix.length];
		long[] temp = new long[matrix.length];
		long[] temp2 = new long[matrix.length];
		id23(matrix, result, power, temp, temp2, exponent + 1, mod, side);
		return result;
	}

	private static void id23(long[] matrix, long[] result, long[] power, long[] temp, long[] temp2, long exponent, long mod, int side) {
		if (exponent == 0) {
			for (int i = 0; i < matrix.length; i += side + 1)
				power[i] = 1 % mod;
			return;
		}
		if ((exponent & 1) == 0) {
			id23(matrix, result, temp, power, temp2, exponent >> 1, mod, side);
			multiply(temp2, result, temp, mod, side);
			add(result, temp2, mod, side);
			multiply(power, temp, temp, mod, side);
		} else {
			id23(matrix, result, temp, power, temp2, exponent - 1, mod, side);
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

	private static void power(long[] matrix, long[] result, long[] temp, long exponent, long mod, int side) {
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
				for (int k = 0; k < side; k++)
					c[i * side + k] += a[i * side + j] * b[j * side + k] % mod;
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

	public static long[] fastPower(long[] matrix, long exponent, long mod, int side) {
		long[] result = new long[matrix.length];
		long[] temp = new long[result.length];
		fastPower(matrix, result, temp, exponent, mod, side);
		return result;
	}

	private static void fastPower(long[] matrix, long[] result, long[] temp, long exponent, long mod, int side) {
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

	public static void fastMultiply(long[] c, long[] a, long[] b, long mod, int side) {
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

abstract class id27 {
	public static final id27 id15 = new id27() {
		@Override
		protected long value(long p, int exponent, long power) {
			return exponent + 1;
		}
	};

	public static final id27 id2 = new id27() {
		@Override
		protected long value(long p, int exponent, long power) {
			return (power * p - 1) / (p - 1);
		}
	};

	public static final id27 PHI = new id27() {
		@Override
		protected long value(long p, int exponent, long power) {
			return power / p * (p - 1);
		}
	};

	public static final id27 id25 = new id27() {
		@Override
		protected long value(long p, int exponent, long power) {
			return exponent == 1 ? -1 : 0;
		}
	};

	protected abstract long value(long p, int exponent, long power);

	public long calculate(long argument) {
		long value = 1;
		for (long i = 2; i * i <= argument; i++) {
			if (argument % i == 0) {
				int exponent = 0;
				long power = 1;
				do {
					exponent++;
					power *= i;
					argument /= i;
				} while (argument % i == 0);
				value *= value(i, exponent, power);
			}
		}
		if (argument != 1)
			value *= value(argument, 1, argument);
		return value;
	}

	public long[] id38(int upTo) {
		int[] divisor = IntegerUtils.id10(upTo);
		long[] result = new long[upTo];
		if (upTo <= 1)
			return result;
		result[1] = 1;
		for (int i = 2; i < upTo; i++) {
			int id18 = i;
			int exponent = 0;
			do {
				id18 /= divisor[i];
				exponent++;
			} while (id18 % divisor[i] == 0);
			result[i] = result[id18] * value(divisor[i], exponent, i / id18);
		}
		return result;
	}
}

abstract class NumberIterator {
	protected final long base;
	protected final long[] power;

	protected NumberIterator() {
		this(10);
	}

	protected NumberIterator(int base) {
		this.base = base;
		power = IntegerUtils.id17(base, Long.MAX_VALUE);
	}

	protected abstract void process(long prefix, int remainingDigits);

	public void run(long from, long to) {
		if (from < 0 || from > to)
			throw new IllegalArgumentException();
		to++;
		for (int i = 0; ; i++) {
			if (i != power.length - 1 && from / power[i + 1] != to / power[i + 1]) {
				long prefix = from / power[i + 1] * base;
				for (int j = (int) (from / power[i] % base); j < base; j++)
					process(prefix + j, i);
				from /= power[i + 1];
				from++;
				from *= power[i + 1];
			} else {
				long upTo = to / power[i] % base;
				long prefix = from / power[i] / base * base;
				for (int j = (int) (from / power[i] % base); j < upTo; j++) {
					process(prefix + j, i);
				}
				for (int k = i - 1; k >= 0; k--) {
					upTo = to / power[k] % base;
					prefix = to / power[k + 1] * base;
					for (int j = 0; j < upTo; j++) {
						process(prefix + j, k);
					}
				}
				break;
			}
		}
	}
}

class Rational implements Comparable<Rational> {
	public static final Rational MAX_VALUE = new Rational(Integer.MAX_VALUE, 1);
	public static final Rational MIN_VALUE = new Rational(Integer.MIN_VALUE, 1);
	public static final Rational ONE = new Rational(1, 1);
	public static final Rational ZERO = new Rational(0, 1);

	public final long numerator;
	public final long denominator;

	public Rational(long numerator, long denominator) {
		if (denominator == 0)
			throw new IllegalArgumentException();
		long gcd = IntegerUtils.gcd(Math.abs(numerator), Math.abs(denominator));
		if (denominator > 0) {
			this.numerator = numerator / gcd;
			this.denominator = denominator / gcd;
		} else {
			this.numerator = -numerator / gcd;
			this.denominator = -denominator / gcd;
		}
	}

	@Override
	public String toString() {
		return numerator + "/" + denominator;
	}

	public int compareTo(Rational other) {
		return IntegerUtils.longCompare(numerator * other.denominator, denominator * other.numerator);
	}

	public Rational add(Rational other) {
		return new Rational(numerator * other.denominator + denominator * other.numerator,
				denominator * other.denominator);
	}

	public Rational reverse() {
		if (numerator == 0)
			throw new ArithmeticException();
		return new Rational(denominator, numerator);
	}

	public Rational multiply(long number) {
		return new Rational(numerator * number, denominator);
	}

	public Rational subtract(Rational other) {
		return new Rational(numerator * other.denominator - denominator * other.numerator,
				denominator * other.denominator);
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Rational rational = (Rational) o;

		if (denominator != rational.denominator) return false;
		if (numerator != rational.numerator) return false;

		return true;
	}

	@Override
	public int hashCode() {
		int result = (int) (numerator ^ (numerator >>> 32));
		result = 31 * result + (int) (denominator ^ (denominator >>> 32));
		return result;
	}

	public Rational divide(long number) {
		return new Rational(numerator, denominator * number);
	}

	public long floor() {
		if (numerator >= 0)
			return numerator / denominator;
		else
			return (numerator - denominator + 1) / denominator;
	}

	public long ceil() {
		if (numerator >= 0)
			return (numerator + denominator - 1) / denominator;
		else
			return numerator / denominator;
	}

	public Rational divide(Rational other) {
		return new Rational(numerator * other.denominator, other.numerator * denominator);
	}

	public Rational multiply(Rational other) {
		return new Rational(numerator * other.numerator, other.denominator * denominator);
	}
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

abstract class id42<T> implements Iterator<T>  {
	public final void remove() {
		throw new UnsupportedOperationException();
	}
}

interface Filter<T> {
	public boolean accept(T value);
}

interface Function<A, V> {
	public abstract V value(A argument);
}

class InputReader {
	private boolean finished = false;

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private id37 filter;

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
		while (id1(c))
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
		} while (!id1(c));
		return res * sgn;
	}

	public long readLong() {
		int c = read();
		while (id1(c))
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
		} while (!id1(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (id1(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!id1(c));
		return res.toString();
	}

	public boolean id1(int c) {
		if (filter != null)
			return filter.id1(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String id9() {
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
		String s = id9();
		while (s.trim().length() == 0)
			s = id9();
		return s;
	}

	public String readLine(boolean id48) {
		if (id48)
			return readLine();
		else
			return id9();
	}

	public BigInteger id3() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (id1(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (id1(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!id1(c) && c != '.') {
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
			while (!id1(c)) {
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
		while (id1(value = peek()) && value != -1)
			read();
		return value == -1;
	}

	public String next() {
		return readString();
	}

	public id37 getFilter() {
		return filter;
	}

	public void setFilter(id37 filter) {
		this.filter = filter;
	}

	public interface id37 {
		public boolean id1(int ch);
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