import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Random;
import java.util.StringTokenizer;

public class C implements id41 {

	public void solve(InputStream is) {
		FastScanner in = new FastScanner(is);
		double w = in.nextDouble();
		double h = in.nextDouble();
		double a= in.nextDouble();
		
		DynamicArray<Point<Dbl>> ps = DynamicArray.create();
		ps.id16(Point.create(new Dbl(w/2), new Dbl(h/2)));
		ps.id16(Point.create(new Dbl(-w/2), new Dbl(h/2)));
		ps.id16(Point.create(new Dbl(-w/2), new Dbl(-h/2)));
		ps.id16(Point.create(new Dbl(w/2), new Dbl(-h/2)));
		
		DynamicArray<Point<Dbl>> intersects = DynamicArray.create();
		DynamicArray<Point<Dbl>> id53 = DynamicArray.create();
		for(int i=0;i<4;i++) { 
			Segment<Dbl> s1 = new Segment<Dbl>(ps.get(i), ps.get((i+1)%4));
			for(int j=0;j<4;j++) {
				Segment<Dbl> s2 = new Segment<Dbl>(rotate(ps.get(j), a), rotate(ps.get((j+1)%4), a));

				




				Point<Dbl> p = s1.p1;
				Point<Dbl> q = s2.p1;
				DirectionVector<Dbl> r = id44.get(p, s1.p2);
				DirectionVector<Dbl> s = id44.get(q, s2.p2);
				
				DirectionVector<Dbl> m = id44.get(p, q);
				double t = cross(m, s).divide(cross(r, s)).toPrimitive();
				double u = cross(m, r).divide(cross(r, s)).toPrimitive();
				


				if(0 <= t && t <= 1 && 0 <= u && u <= 1) {


					Point<Dbl> inter = Geometry.id4(s1.p1, s1.p2, t);
					intersects.id16(inter);
				}








			}
		}
		


		
		new QuickSort().sort(intersects, new id48<Dbl>(id29.ORIGIN));
		new QuickSort().sort(id53, new id48<Dbl>(id29.ORIGIN));




		if(intersects.size() == 0) {
			System.out.println("GG");
		} else {
			double r = id50.get(new SimplePolygon<Dbl>(intersects));
			System.out.println(r);
		}
	}

	private Dbl cross(DirectionVector<Dbl> d1, DirectionVector<Dbl> d2) {
		return d1.dx.times(d2.dy).minus(d1.dy.times(d2.dx));
	}

	private Point<Dbl> rotate(Point<Dbl> p, double a) {
		Point<Dbl> p2 = id20.calc(new Direction(id34.calc(p).a + Math.toRadians(a)), id0.calc(p));
		return p2;
	}

	public static void main(String[] args) throws Exception {
		id19.launch(new id13() {
			public id41 create() {
				return new C();
			}
		}, "C1.txt", "C2.txt", "C3.txt");
	}

}

interface id41 {
	void solve(InputStream is); 
}

interface id13 {
	id41 create();
}

class id19 {

	public static void launch(id13 factory, String... id61) throws FileNotFoundException, IOException {
		if(System.getProperty("ONLINE_JUDGE", "false").equals("true")) {
			factory.create().solve(System.in);
		} else { 
			for(String path : id61) {
				FileInputStream is = new FileInputStream(new File(path));
				factory.create().solve(is);
				is.close();
				System.out.println();
			}
		}
	}

}

class FastScanner {
	
	private StringTokenizer tokenizer;

	public FastScanner(InputStream is) {
		try {
			ByteArrayOutputStream bos = new ByteArrayOutputStream(1024*1024);
			byte[] buf = new byte[1024*1024];
			while(true) {
				int read = is.read(buf);
				if(read == -1)
					break;
				bos.write(buf, 0, read);
			}
			tokenizer = new StringTokenizer(new String(bos.toByteArray()));
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
	
	public int nextInt() {
		return Integer.parseInt(tokenizer.nextToken());
	}
	
	public long nextLong() {
		return Long.parseLong(tokenizer.nextToken());
	}
	
	public double nextDouble() {
		return Double.parseDouble(tokenizer.nextToken());
	}
	
	public String next() {
		return tokenizer.nextToken();
	}

}

class Geometry {
	
	

	
	static public double getArea(LengthTriangle<Dbl> lt) {
		double l1 = lt.l1.toPrimitive();
		double l2 = lt.l2.toPrimitive();
		double l3 = lt.l3.toPrimitive();
		double s = (l1+l2+l3) / 2;
		double f = s * (s-l1) * (s-l2) * (s-l3);
		if(f >= 0)
			return Math.sqrt(f);
		else
			return 0;
	}
	
	static public double id45(LengthTriangle<Dbl> lt) {
		return lt.l1.toPrimitive() * lt.l2.toPrimitive() * lt.l3.toPrimitive() / getArea(lt) / 4;
	}
	
	static public double getDistance(Segment<Dbl> s, Point<Dbl> p) {
		Angle a1 = RightAngle.calc(p, s.p1, s.p2);
		Angle a2 = RightAngle.calc(p, s.p2, s.p1);
		if((a1.a < Math.PI / 2 || a1.a > Math.PI * 3 / 2) && (a2.a < Math.PI / 2 || a2.a > Math.PI * 3 / 2)) 

			return id58.calc(id54.convert(id21.create(s)), p);
		else
			return Math.min(id26.calc(s.p1,p), id26.calc(s.p2,p));
	}
	
	static public double getDistance(Segment<Dbl> s1, Segment<Dbl> s2) {
		return Math.min(Math.min(Math.min(getDistance(s1, s2.p1), getDistance(s1, s2.p2)), getDistance(s2, s1.p1)), getDistance(s2, s1.p2));
	}
	
	static public double id42(LengthTriangle<Dbl> lt) {
		return getArea(lt) * 2 / (lt.l1.toPrimitive()+lt.l2.toPrimitive()+lt.l3.toPrimitive());
	}
	
	

	static public Point<Dbl> id4(Point<Dbl> p1, Point<Dbl> p2, double rate) 	{
		return new Point<Dbl>(new Dbl(p1.x.toPrimitive() + (p2.x.toPrimitive()-p1.x.toPrimitive())*rate), new Dbl(p1.y.toPrimitive() + (p2.y.toPrimitive() - p1.y.toPrimitive()) * rate));
	}

	static public Point<Dbl> getMoved(Point<Dbl> p, double dx, double dy) {
		return new Point<Dbl>(new Dbl(p.x.toPrimitive() + dx), new Dbl(p.y.toPrimitive() + dy));    	
	}
	
	static public Point<Dbl> id33(Point<Dbl> p, Angle a) {
		return id20.calc(TurnLeft.calc(id34.calc(p) , a), id0.calc(p));
	}
	
	static public Point<Dbl> id33(Point<Dbl> p, Point<Dbl> ref, Angle a) {
		return getMoved(id33(getMoved(p, -ref.x.toPrimitive(), -ref.y.toPrimitive()), a), ref.x.toPrimitive(), ref.y.toPrimitive());
	}
	
	public Point<Dbl> id28(Triangle<Dbl> t) { 
		Line<Dbl> line1 = id11.calc(id2.toLine(t.p1, t.p2), id4(t.p1, t.p2, 0.5));
		Line<Dbl> line2 = id11.calc(id2.toLine(t.p2, t.p3), id4(t.p2, t.p3, 0.5));
		return id1.calc(line1, line2);
	}

}

class id34 {

	public static Direction calc(Point<Dbl> p) {
		return id36.calc(p, id29.ORIGIN);
	}

}

class Dbl implements RealNumber<Dbl>, EqualityTester<Dbl> {

	

	
	private final double v;
	
	public Dbl(double v) {
		this.v = v;
	}

	public Dbl plus(Dbl t) {
		return new Dbl(v + t.v);
	}

	public Dbl minus(Dbl t) {
		return new Dbl(v - t.v);
	}
	
	public Dbl id59() {
		return new Dbl(-v);
	}
	
	public String toString() {
		if(v == Math.round(v))
			return Integer.toString((int)v);
		return Double.toString(v);
	}
	
	public double toPrimitive() {
		return v;
	}
	
	public int compareTo(Dbl o) {
		double v2 = o.v;
		if(v == v2)
			return 0;
		else if(v < v2)
			return -1;			
		else
			return 1;
	}
	
	public Dbl getZero() {
		return ZERO;
	}
	
	public Dbl divide(Dbl o) {
		return new Dbl(v / o.v);
	}
	
	public Dbl getOne() {
		return ONE;
	}
	
	public boolean isOne() {
		return v == 1;
	}
	
	public Dbl id7() {
		return new Dbl(1/v);
	}
	
	public Dbl times(Dbl a) {
		return new Dbl(v * a.v);
	}	
	
	public boolean equals(Object obj) {
		return id43.areEqual(this, obj, this);
	}
	
	public boolean areEqual(Dbl o1, Dbl o2) {
		return o1.compareTo(o2) == 0; 

	}
	
	public int hashCode() { 
		return 1; 

	}
	
	public int getSign() {
		if(Math.abs(v) < DoubleCompare.eps)
			return 0;
		else if(v < 0)
			return -1;			
		else
			return 1;
	}

	public final Dbl get(int v) { 

		return new Dbl(v);
	}

	public final boolean isPositive() {
		return getSign() > 0;
	}

	public final boolean isNegative() {
		return getSign() < 0;
	}

	public final boolean isZero() { 
		return getSign() == 0;
	}

	static public final Dbl ZERO = new Dbl(0);
	static public final Dbl ONE = new Dbl(1);

}

interface EqualityTester<T> {
	boolean areEqual(T o1, T o2);
}

class id43 {
	@SuppressWarnings("unchecked")
	public static <T> boolean areEqual(T me, Object you, EqualityTester<T> tester) {
		if(me == you)
			return true;
		if(you == null)
			return false;
		if(you.getClass() != me.getClass())
			return false;
		return tester.areEqual(me, (T)you);
	}
}

class DoubleCompare {
	
	static public double eps = 1e-12;  
	
	static public int compare(double v1, double v2) {
		if(Math.abs(v1-v2) < eps)
			return 0;
		else if(v1 < v2)
			return -1;			
		else
			return 1;
	}
	
	static public int getSign(double v) {
		if(Math.abs(v) < eps)
			return 0;
		else if(v < 0)
			return -1;			
		else
			return 1;
	}
	
	static public boolean isZero(double v) {
		return compare(v, 0)==0;
	}
	
	static public boolean isPositive(double v) {
		return compare(v, 0) > 0;
	}

	static public boolean isNegative(double v) {
		return compare(v, 0) < 0;
	}
	
	static public final Comparator<Double> comparator = new Comparator<Double>() {
		public int compare(Double o1, Double o2) {
			return DoubleCompare.compare(o1, o2);			
		}
	};

}

interface RealNumber<T extends RealNumber<T>> extends Divisable<T> {
}

interface Divisable<T extends Divisable<T>> extends id25<T> {
	T divide(T o);
	T id7();
}

interface id25<T extends id25<T>> extends Additive<T> { 

	T times(T a);
	T getOne();
	T get(int v);
	boolean isOne();
}

interface Additive<T extends Additive<T>> extends Number<T> { 

	T plus(T v);
	T minus(T v);
	T id59();
	T getZero();
	boolean isPositive();
	boolean isZero();
	boolean isNegative();
	int getSign();
}

interface Number<T> extends Comparable<T> {
}

class Direction {
	
	public final double a; 

	
	public Direction(double radian) {
		if(Double.isNaN(radian))
			throw new IllegalArgumentException("Direction cannot be NaN");
		while(radian < 0)
			radian += Math.PI + Math.PI;
		while(DoubleCompare.compare(radian,Math.PI + Math.PI) >= 0)
			radian -= Math.max(0, Math.PI + Math.PI);
		a = radian;
	}
	
	public final boolean equals(Object v) { 

		if(v==null)
			return false;
		if(v == this)
			return true;
		if(!(v instanceof Direction))
			return false;
		Direction d = (Direction)v;
		return id8.equals(a, d.a);
	}
	
	public final int hashCode() { 

		return 1;
	}
	
	public double cos() {
		return Math.cos(a);
	}
	
	public double sin() {
		return Math.sin(a);
	}
	
	public double tan() {
		return Math.tan(a);
	}
	
	public String toString() {
		return "Dir(" + String.format("%.2f", a) +"pi)";
	}
	
}

class id8 {

	static public boolean equals(double v1, double v2) {
		return DoubleCompare.compare(v1,v2)==0;
	}

}

class id29 {

	public static final Point<Dbl> ORIGIN = Point.create(Dbl.ZERO, Dbl.ZERO);

}

class Point<T> implements id38<T>, EqualityTester<Point<T>> {

	public static <T> Point<T> create(T x, T y) {
		return new Point<T>(x, y); 
	}
	
	public final T x;
	public final T y;
	
	public Point(T x, T y) {
		this.x = x;
		this.y = y;
	}

	public T x() {
		return x;
	}
	
	public T y() {
		return y;
	}

	public final boolean equals(Object o) {
		return id43.areEqual(this, o, this);
	}

	public boolean areEqual(Point<T> o1, Point<T> o2) {
		return o1.x.equals(o2.x) && o1.y.equals(o2.y);
	}

	public final int hashCode() {
		return x.hashCode() ^ y.hashCode();
	}
	
	public String toString() {
		return "(" + x + "," + y + ")";
	}
	
}

interface id38<T> {
	T x();
	T y();
}

class id36 {

	public static Direction calc(Point<Dbl> p, Point<Dbl> ref) {
		return new Direction(Math.atan2(p.y.toPrimitive() - ref.y.toPrimitive(), p.x.toPrimitive() - ref.x.toPrimitive()));
	}

}

class id58 {

	public static double calc(OldLine l, Point<Dbl> p) { 

		return Math.abs(l.a*p.x.toPrimitive() + l.b*p.y.toPrimitive() + l.c) / Math.sqrt(l.a*l.a+l.b*l.b);		
	}
	
	public static <T extends Divisable<T>> T calcSquare(Line<T> line, Point<T> p) { 

		return Square.calc(line.a.times(p.x).plus(line.b.times(p.y)).plus(line.c)).divide(Square.calc(line.a).plus(Square.calc(line.b)));		
	}

}

class Square {
	static public <T extends id25<T>>T calc(T v) {
		return v.times(v);
	}
}

class Line<T> implements EqualityTester<Line<T>> {
	
	


	public final T a,b,c; 


	public Line(T a,T b,T c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}
	
	public final boolean equals(Object obj) {
		return id43.areEqual(this, obj, this);
	}

	public boolean areEqual(Line<T> o1, Line<T> o2) {
		return o1.a.equals(o2.a) && o1.b.equals(o2.b) && o1.c.equals(o2.c);
	}
	
	public int hashCode() {
		return a.hashCode() ^ b.hashCode() ^ c.hashCode();
	}
	
	public String toString() {
		return String.format("(%s)x+(%s)y+(%s)=0", a,b,c);
	}
}

class OldLine {
	
	public final double a,b,c; 

	public OldLine(double a,double b,double c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}

	public final boolean equals(Object obj) {
		if(obj == null)
			return false;
		if(obj == this)
			return true;
		if(!(obj instanceof OldLine))
			return false;
		OldLine o = (OldLine)obj;
		return ParallelLines.isParallel(id49.convert(this), id49.convert(o)) && id8.equals(c,o.c);
	}
	
	public final int hashCode() {
		return 1;
	}
	
	public String toString() {
		String r = a + "x";
		if(b >= 0)
			r += "+";
		r += "y";
		if(c >= 0)
			r += "+";
		r += c + "=0";
		return r;
	}
}

class id49 { 

	
	public static Line<Dbl> convert(OldLine line) {
		return new Line<Dbl>(new Dbl(line.a), new Dbl(line.b), new Dbl(line.c));
	}

}

class ParallelLines {
	public static <T extends id25<T>> boolean isParallel(Line<T> line1, Line<T> line2) {
		return line2.a.times(line1.b).equals(line1.a.times(line2.b));
	}
}

class id0 {
	static public double calc(Point<Dbl> p) {
		return id26.calc(p, id29.ORIGIN);		
	}
		

}

class id26 {
	
	public static double calc(Point<Dbl> p1, Point<Dbl> p2) {
		return Math.sqrt(id46.calc(p1, p2).toPrimitive());		
	}
}

class id46 {

	public static <T extends id25<T>> T calc(Point<T> p1, Point<T> p2) {
		T sq1 = Square.calc(p1.x.minus(p2.x));
		T sq2 = Square.calc(p1.y.minus(p2.y));
		return sq1.plus(sq2);
	}

}

class id1 {
	
	@Deprecated
	public static <T extends Divisable<T>> Point<T> calc(Line<T> line1, Line<T> line2, Point<T> def) {
		if(ParallelLines.isParallel(line1, line2))
			return def;
		else 
			return calc(line1, line2);
	}

	public static <T extends Divisable<T>> Point<T> calc(Line<T> line1, Line<T> line2) {
		T divisor = line2.a.times(line1.b).minus(line1.a.times(line2.b));
		if(divisor.isZero())
			throw new IllegalArgumentException("Two lines (" + line1 + " and " + line2 + ") are parellel");
		T x = (line2.b.times(line1.c).minus(line1.b.times(line2.c))).divide(divisor);
		T y = (line2.a.times(line1.c).minus(line1.a.times(line2.c))).divide(divisor.id59());
		return Point.create(x, y);
	}

}

class id2 {

	public static <T extends Divisable<T>> Line<T> toLine(Point<T> p1, Point<T> p2) {
		T a, b, c;
		if(p1.x.equals(p2.x)) {
			if(p1.y.equals(p2.y))
				throw new IllegalArgumentException("Cannot create a line from same points");
			a = p1.x.getOne();
			b = p1.x.getZero();
			c  = p1.x.id59();
		} else {
			b = p1.x.getOne();
			a = (p1.y.minus(p2.y)).divide(p1.x.minus(p2.x)).id59();
			c = a.times(p1.x).id59().minus(b.times(p1.y));
		}
		return new Line<T>(a, b, c);
	}
}

class id21 {
	public static <T extends Divisable<T>> Line<T> create(Segment<T> s) {
		return id2.toLine(s.p1, s.p2);		
	}
}

class Segment<T> {
	
	public static <T> Segment<T> create(Point<T> p1, Point<T> p2) {
		return new Segment<T>(p1, p2);
	}
	
	public final Point<T> p1;
	public final Point<T> p2;

	public Segment(Point<T> p1, Point<T> p2) {
		if(p1.equals(p2))
			throw new RuntimeException("Segment : two points are same");
		this.p1 = p1;
		this.p2 = p2;
	}

	public String toString() {
		return "Segment(" + p1 + "-" + p2 + ")";
	}
	
	@SuppressWarnings("unchecked")
	public final boolean equals(Object obj) { 

		if(obj == null)
			return false;
		if(obj == this)
			return true;
		if(!(obj instanceof Segment))
			return false;
		Segment<T> s = (Segment<T>)obj;
		return (p1.equals(s.p1) && p2.equals(s.p2)) || (p1.equals(s.p2) && p2.equals(s.p1));
	}
	
	public final int hashCode() {
		return p1.hashCode() ^ p2.hashCode();
	}
	
}

class id54 { 

	
	public static OldLine convert(Line<Dbl> line) {
		return new OldLine(line.a.toPrimitive(), line.b.toPrimitive(), line.c.toPrimitive());
	}

}

class id11 {
	
	public static <T extends Divisable<T>> Line<T> calc(Line<T> line, Point<T> passingPoint) {
		if(line.a.isZero()) {
			return id2.toLine(passingPoint, Point.create(passingPoint.x, increase(passingPoint.y)));
		} else if(line.b.isZero()) {
			return id2.toLine(passingPoint, Point.create(increase(passingPoint.x), passingPoint.y));
		} else {
			T slope = id68.calc(line);
			return id32.toLine(passingPoint, slope.id7().id59());
		}
	}

	private static <T extends id25<T>> T increase(T v) {
		return v.plus(v.getOne());
	}
}

class id32 {
	
	public static <T extends Divisable<T>> Line<T> toLine(Point<T> p, T s) {
		T a = s.id59();
		T b = a.getOne();
		T c = a.times(p.x).plus(b.times(p.y)).id59();
		return new Line<T>(a, b, c);
	}

}

class id68 {
	
	public static <T extends Divisable<T>> T calc(Line<T> line) {
		if(line.b.isZero()) 
			throw new IllegalArgumentException("Line " + line + " don't have a slope");
		return line.a.divide(line.b).id59();
	}
}

class id20 {
	
	public static Point<Dbl> calc(Direction a, double d) {
		return Point.create(new Dbl(d * a.cos()), new Dbl(d * a.sin()));
	}

	public static Point<Dbl> calc(Point<Dbl> p, Direction dir, double dis) {
		return Geometry.getMoved(calc(dir, dis), p.x.toPrimitive(), p.y.toPrimitive());    	
	}
	
}

class RightAngle {

	public static Angle calc(Point<Dbl> s, Point<Dbl> m, Point<Dbl> e) { 

		double a = Math.atan2(e.y.toPrimitive() - m.y.toPrimitive(), e.x.toPrimitive() - m.x.toPrimitive()) - Math.atan2(s.y.toPrimitive() - m.y.toPrimitive(), s.x.toPrimitive() - m.x.toPrimitive());
		if(a < 0)
			a += 2*Math.PI;
		return new Angle(a);
	}

}

class Angle {
	
	public final double a; 

	
	public Angle(double a) {
		this.a = a;
	}
	
	public double cos() {
		return Math.cos(a);
	}	
	
	public double sin() {
		return Math.sin(a);
	}
	
	public double tan() {
		return Math.tan(a);
	}
	
	public String toString() {
		return "A"+a ;
	}
	
	public boolean equals(Object o) { 

		if(o == null)
			return false;
		if(o.getClass() != this.getClass())
			return false;
		return DoubleCompare.compare(a, ((Angle)o).a) == 0;			
	}
	
	public int hashCode() { 

		return 0;
	}
}

class TurnLeft {

	static public Direction calc(Direction d, Angle da) {
		return new Direction(d.a + da.a);
	}

}

class LengthTriangle<T extends Additive<T>> {
	
	public final T l1,l2,l3;
	
	

	public LengthTriangle(T l1,T l2, T l3) {
		this.l1 = l1;
		this.l2 = l2;
		this.l3 = l3;
	}
	
	public String toString() {
		return "LT : (" + l1 + ","+l2+","+l3+")";
	}
	
}

class Triangle<T> {
	public final Point<T> p1,p2,p3;
	
	public Triangle(Point<T> p1, Point<T> p2, Point<T> p3) {
		this.p1 = p1;
		this.p2 = p2;
		this.p3 = p3;
	}

	public String toString() {
		return "Triangle(" + p1 + p2 + p3+")";
	}
}

class DynamicArray<T> implements MutableArray<T> {
	
	public static <T> DynamicArray<T> create() {
		return new DynamicArray<T>();
	}
	
	private T[] a;
	private int asize;
	
	
	@SuppressWarnings("unchecked")
	private void init(int cap) {
		asize = 0;
		a = (T[])new Object[Math.max(1, cap)];		
	}
	
	public DynamicArray() {
		init(1);
	}
	
	public DynamicArray(int initialCapacity) {
		init(initialCapacity);
	}
	
	public T get(int index) {
		return a[index];
	}	
	
	public void set(int index, T value) {
		a[index] = value;		
	}
	
	public int size() {
		return asize;
	}
	
	public void clear() {
		asize = 0;
	}
	
	@SuppressWarnings("unchecked")
	public void reserve(int size) {
		if(a.length < size) {
			T[] ta = (T[])new Object[size];
			for(int i=0;i<a.length;i++)
				ta[i] = a[i];
			a = ta;
		}
	}
	
	@SuppressWarnings("unchecked")
	public void id16(T value) {
		if(a.length == asize) {
			T[] ta = (T[])new Object[asize*2];
			for(int i=0;i<asize;i++)
				ta[i] = a[i];
			a =ta;
		}
		a[asize++] = value;						
	}
	
	public void id64(Iterable<? extends T> values) {
		for(T v : values)
			id16(v);
	}
	
	public T removeLast() {
		T r = id31.getLast(this);
		a[--asize] = null;
		return r;
	}
	
	public boolean equals(Object obj) {
		return id43.areEqual(this, obj, new EqualityTester<DynamicArray<T>>() {
			public boolean areEqual(DynamicArray<T> o1, DynamicArray<T> o2) {
				if(o1.size() != o2.size())
					return false;
				for(int i=0;i<o1.size();i++)
					if(!o1.get(i).equals(o2.get(i)))
						return false;		
				return true;
			}
		});
	}

	public int hashCode() {
		int r = 0;
		for(int i=0;i<size();i++)
			r ^= id52.id12(get(i).hashCode());
		return r;
	}

	public final boolean isEmpty() {
		return size() == 0;
	}

	public final Iterator<T> iterator() {
		return ArrayIterator.create(this);
	}

	public final String toString() {
		return id9.toString(this);
	}
	
}

class id9 {
	public static <T> String toString(Iterable<T> iterable) {
		StringBuilder sb = new StringBuilder();
		sb.append('(');
		boolean first = true;
		for(T v : iterable) {
			if(first)
				first = false;
			else
				sb.append(',');
			sb.append(v);
		}
		sb.append(')');
		return sb.toString();
	}
}

class id52 {
	
	

	
	public static int id12(int key) {
		key = ~key + (key << 15); 

		key = key ^ (key >>> 12);
		key = key + (key << 2);
		key = key ^ (key >>> 4);
		key = key * 2057; 

		key = key ^ (key >>> 16);
		return key;
	}

	public static int id27(long key) { 
		key = (~key) + (key << 18); 

		key = key ^ (key >>> 31);
		key = key * 21; 

		key = key ^ (key >>> 11);
		key = key + (key << 6);
		key = key ^ (key >>> 22);
		return (int) key;
	}
}

class ArrayIterator {
	public static <T> Iterator<T> create(final Array<T> a) {
		return new id24<T>() {
			int p = 0;
			public boolean hasNext() {
				return p < a.size();
			}
			public T next() {
				return a.get(p++);
			}
		};
	}

	private ArrayIterator() {
	}
}

abstract class id24<T> implements Iterator<T> {
	public final void remove() {
		throw new UnsupportedOperationException();
	}
}

interface Array<T> extends Collection<T> {
	T get(int index);
}

interface Collection<T> extends Iterable<T> {
	int size();
	boolean isEmpty();
}

interface MutableArray<T> extends Array<T> {
	void set(int index, T value);	
}

class id31 {

	public static <T> T getLast(Array<T> a) {
		return a.get(a.size()-1);
	}

	public static <T> T getFirst(Array<T> a) {
		return a.get(0);
	}

}

class id50 {

	static public double get(SimplePolygon<Dbl> pg) {
		

		double total = 0;
		for(int i=0;i<pg.pointNumber();i++) {
			Point<Dbl> pre = pg.get(i);
			Point<Dbl> p = pg.get((i+1)%pg.pointNumber());
			total += pre.x.toPrimitive() * p.y.toPrimitive() - pre.y.toPrimitive() * p.x.toPrimitive();
		}
		return Math.abs(total)/2;
	}

}

class SimplePolygon<T extends id25<T>> {
	
	public final Array<Point<T>> points; 

	
	public SimplePolygon(Iterable<Point<T>> src) {
		
		DynamicArray<Point<T>> points = new DynamicArray<Point<T>>();
		
		

		

		DynamicArray<Point<T>> id18 = new DynamicArray<Point<T>>();
		id18.id64(src);
		Unique.unique(id18);		
		if(id18.size() >=  2 && id18.get(0).equals(id31.getLast(id18)))
			id18.removeLast();

		if(id18.size() <= 2) {
			points.id64(id18);
		} else {
			

			for(int i=0;i<id18.size();i++)
				if(!StraightLine.is(id18.get((i-1+id18.size()) % id18.size()), id18.get(i), id18.get((i+1)%id18.size())))
					points.id16(id18.get(i));	
	
			

			T total = id18.get(0).x.getZero();
			for(int i=0;i<points.size();i++) {
				Point<T> pre = points.get(i);
				Point<T> p = points.get((i+1) % points.size());
				total = total.plus(pre.x.times(p.y)).minus(pre.y.times(p.x));
			}
			if(total.isPositive())
				id51.reverse(points);
		}

		

		Comparator<Point<T>> xycomp = new id14<T>();
		id60.rotate(points, Min.minIndex(points, xycomp));		
		this.points = points;
	}
	
	@SuppressWarnings("unchecked")
	public boolean equals(Object obj) {
		return points.equals(((SimplePolygon<T>)obj).points);
	}
	
	public int pointNumber() {
		return points.size();
	}
	
	public Point<T> get(int index) {
		return points.get(index);
	}
	
	public int size() {
		return points.size();
	}
	
}

class Min {
	

	

	
	static public <T extends Comparable<T>> T min(T v1, T v2) {
		if(v1.compareTo(v2) < 0)
			return v1;
		else
			return v2;
	}

	static public <T> T min(Iterable<T> c, Comparator<T> comp) {
		T min = null;
		for(T a : c) 
			if(min == null || comp.compare(min, a) > 0)
				min = a;
		return min;
	}
	
	static public <T> int minIndex(Array<T> c, Comparator<T> comp) {
		int r = -1;
		for(int i=0;i<c.size();i++)
			if(r==-1 || comp.compare(c.get(r), c.get(i)) > 0)
				r = i;
		return r;
	}
	
	static public <T extends Comparable<T>> T min(Iterable<T> c) {
		return min(c, new DefaultComparator<T>()); 
	}
}

class DefaultComparator<T> implements Comparator<T> {
	

	@SuppressWarnings("unchecked")
	public int compare(T arg0, T arg1) {
		return ((Comparable<T>)arg0).compareTo(arg1);
	}

}

class id51 {
	
	static public <T> void reverse(MutableArray<T> a) {
		reverse(a, 0, a.size()-1);
	}
	
	static public <T> void reverse(MutableArray<T> a, int start, int end) {
		for(int i=0;i<(end-start+1)/2;i++)
			id67.swap(a, start+i, end-i); 
	}

}

class id67 {
	
	public static <T> void swap(MutableArray<T> a, int p1, int p2) {
		T t = a.get(p1);
		a.set(p1, a.get(p2));
		a.set(p2, t);
	}
	
	public static <T> void swap(T[] a, int p1, int p2) { 

		swap(id40.create(a), p1, p2);				
	}
}

class id40 {
	
	public static <T> MutableArray<T> create(final T[] a) {
		return new MutableArray<T>() {
			public T get(int p) {
				return a[p];
			}
		
			public void set(int p, T v) {
				a[p] = v;
			}
		
			public int size() {
				return a.length;
			}
		
			public boolean isEmpty() {
				return a.length == 0;
			}
		
			public Iterator<T> iterator() {
				return ArrayIterator.create(this);
			}
		
			public String toString() {
				return id9.toString(this);
			}
		};
	}

	private id40() {
	}

}

class id60 {
	
	static public <T> void rotate(MutableArray<T> a, int id15) {
		id51.reverse(a, 0, id15-1);		 
		id51.reverse(a, id15, a.size()-1);
		id51.reverse(a, 0, a.size()-1);
	}
}

class Unique {
	static public <T> void unique(DynamicArray<T> a) {
		if(a.isEmpty())
			return;
		int p = 0;
		for(int i=1;i<a.size();i++)
			if(!a.get(p).equals(a.get(i))) {
				p++;
				a.set(p, a.get(i));
			}
		while(a.size() > p+1)
			a.removeLast();
	}
}

class StraightLine { 


	public static <T extends id25<T>>boolean is(Point<T> p1,Point<T> p2,Point<T> p3) {
		if(!CCW.ccw(p1, p2, p3).isZero())
			return false;
		return id55.is(p2, p1, p3);
	}

}

class CCW {
	static public <T extends id25<T>> T ccw(Point<T> p1, Point<T> p2, Point<T> p3) {
		return p1.x.times(p2.y).plus(p2.x.times(p3.y)).plus(p3.x.times(p1.y)).minus(p1.x.times(p3.y)).minus(p2.x.times(p1.y)).minus(p3.x.times(p2.y)).id59();
	}
}

class id55 {

	public static <T extends id25<T>> boolean is(Point<T> p, Point<T> id3, Point<T> id65) {
		return id55.is(p, id3.x, id65.x, id3.y, id65.y);
	}

	public static <T extends Comparable<T>> boolean is(Point<T> p, T id39, T id23, T id6, T id35) {
		T maxx = Max.max(id39, id23);
		T minx = Min.min(id39, id23);
		T maxy = Max.max(id6, id35);
		T miny = Min.min(id6, id35);
		return InRange.is(p.x, minx, maxx) && InRange.is(p.y, miny, maxy);
	}

}

class InRange {
	
	static public <T extends Comparable<T>> boolean is(T v, T lower, T upper) {
		return lower.compareTo(v) <= 0 && v.compareTo(upper) <= 0;
	}

}

class Max {
	
	public static <T extends Comparable<T>> T max(T v1, T v2) {
		if(v1.compareTo(v2) > 0)
			return v1;
		else
			return v2;
	}
	
}

class id14<T extends Comparable<T>> implements Comparator<Point<T>> {
	
	@SuppressWarnings("unchecked")
	private Comparator<Point<T>> comp =  new SeriesComparator<Point<T>>(new id56<T>(), new id62<T>());
	
	public int compare(Point<T> p1, Point<T> p2) {
		return comp.compare(p1, p2);
	}		
}

class SeriesComparator<T> implements Comparator<T> {
	
	private Comparator<T>[] compList;
	
	public SeriesComparator(Comparator<T>... compList) {
		this.compList = compList;						
	}

	public int compare(T o1, T o2) {
		for(Comparator<T> comp : compList) {
			int c = comp.compare(o1, o2);
			if(c != 0)
				return c;
		}
		return 0;
	}

}

class id56<T extends Comparable<T>> implements Comparator<Point<T>> {
	public int compare(Point<T> p1, Point<T> p2) {
		return p1.x.compareTo(p2.x);
	}
}

class id62<T extends Comparable<T>> implements Comparator<Point<T>> {
	public int compare(Point<T> p1, Point<T> p2) {
		return p1.y.compareTo(p2.y);
	}		
}

class id44 {

	public static <T extends Additive<T>>DirectionVector<T> get(Point<T> from, Point<T> to) {
		return new DirectionVector<T>(to.x.minus(from.x), to.y.minus(from.y));
	}

}

class DirectionVector<T> {
	public final T dx;
	public final T dy;
	public DirectionVector(T dx, T dy) {
		this.dx = dx;
		this.dy = dy;
	}
}

interface id22 {
	boolean id10();
	boolean id37();
	boolean isIntersect();
	Point<Dbl> id57();
	Segment<Dbl> id47();
}

class id30 {
	
	

	
	@SuppressWarnings("unchecked")
	static public id22 getIntersection(Segment<Dbl> s1, Segment<Dbl> s2) {
		Point<Dbl> rp = null;
		Segment<Dbl> rs = null;
		if(id5.isParallel(s1, s2)) {
			int pn = 0;
			Point<Dbl>[] p = new Point[4];
			if(id17.is(s2.p1, s1))
				p[pn++] = s2.p1;
			if(id17.is(s2.p2, s1))
				p[pn++] = s2.p2;
			if(id17.is(s1.p1, s2))
				p[pn++] = s1.p1;
			if(id17.is(s1.p2, s2))
				p[pn++] = s1.p2;
			
			int opn = 0;
			Point<Dbl>[] op = new Point[2];
			for(int i=0;i<pn;i++) {
				boolean found = false;
				for(int j=0;j<opn;j++)
					if(op[j].equals(p[i]))
						found = true;
				if(!found)
					op[opn++] = p[i];
			}
			
			if(opn == 1)
				rp = op[0];
			else if(opn == 2)
				rs = new Segment<Dbl>(op[0], op[1]);
			
		} else {
			Line<Dbl> line1 = id21.create(s1);
			Line<Dbl> line2 = id21.create(s2);
			Point<Dbl> subr = id1.calc(line1, line2);
			if(id17.is(subr, s1) && id17.is(subr, s2))
				rp = subr;
		}					
		final Point<Dbl> frp = rp;
		final Segment<Dbl> frs = rs;
		return new id22() {
			public Point<Dbl> id57() {
				return frp;
			}
			public boolean isIntersect() {
				return frp != null || frs != null;
			}
			public Segment<Dbl> id47() {
				return frs;
			}
			public boolean id10() {
				return frp != null;
			}
			public boolean id37() {
				return frs != null;
			}
		};
	}
}

class id5 {
	static public boolean isParallel(Segment<Dbl> s1, Segment<Dbl> s2) {
		return ParallelLines.isParallel(id21.create(s1), id21.create(s2));
	}
}

class id17 {
	static public <T extends id25<T>>boolean is(Point<T> p, Segment<T> s) {
		return StraightLine.is(s.p1, p, s.p2);
	}
}

class QuickSort implements Sort {
	
	private static Random RANDOM = new Random();

	

	
	public <T> void sort(MutableArray<T> a, Comparator<T> comparator) {
		sort(a, 0, a.size()-1, comparator);		
	}

	public <T> void sort(MutableArray<T> list, int start, int end, Comparator<T> comparator) {
		if(start < end) {
			id67.swap(list, start, RANDOM.nextInt(end-start) + start + 1);
			int pos = start;
			for(int i=start+1;i<=end;i++) {
				int c = comparator.compare(list.get(i), list.get(start)); 
				if(c < 0 || c == 0 && i%2==0)
					id67.swap(list, i,++pos);
			}
			id67.swap(list, start, pos);
			sort(list, start,pos-1, comparator);
			sort(list, pos+1, end, comparator);
		}
	}
	
}

interface Sort {
	<T> void sort(MutableArray<T> a, Comparator<T> comparator);
}

class id48<T extends id25<T>> implements Comparator<Point<T>> {
	
	public Comparator<Point<T>> comp;
	
	@SuppressWarnings("unchecked")
	public id48(Point<T> ref) {
		T one = ref.x.getOne();
		comp = new SeriesComparator<Point<T>>(new DirectionComparator<T>(ref, new Point<T>(ref.x.plus(one), ref.y)), new id66<T>(ref));
	}
	
	public int compare(Point<T> p1, Point<T> p2) {
		return comp.compare(p1, p2);
	}		
	
}

class DirectionComparator<T extends id25<T>> implements Comparator<Point<T>> {
	
	private final Point<T> ref;
	private final Point<T> start;
	
	public DirectionComparator(Point<T> ref, Point<T> start) {
		this.ref = ref;
		this.start = start;
	}
	
	public int id63(Point<T> p) {
		if(StraightLine.is(start, ref, p))
			return 2;
		else if(RightTurn.is(start, ref, p))
			return 1;
		else if(LeftTurn.is(start, ref, p))
			return 3;
		else 
			return 0;
	}
	
	public int compare(Point<T> p1, Point<T> p2) {
		int code1 = id63(p1);
		int code2 = id63(p2);
		if(code1 != code2)
			return code1 - code2;
		
		if(code1 == 0 || code1 == 2) {
			return 0;
		} else {
			if(RightTurn.is(p1, ref, p2))
				return -1;
			else if(LeftTurn.is(p1, ref, p2))
				return 1;
			else
				return 0;
		}
	}		
}

class LeftTurn {

	static public <T extends id25<T>> boolean is(Point<T> p1,Point<T> p2,Point<T> p3) {
		return CCW.ccw(p1,p2,p3).isNegative();
	}

}

class RightTurn {

	static public <T extends id25<T>> boolean is(Point<T> p1,Point<T> p2,Point<T> p3) {
		return CCW.ccw(p1,p2,p3).isPositive();
	}

}

class id66<T extends id25<T>> implements Comparator<Point<T>> {
	private Point<T> ref;
	
	public id66(Point<T> ref) {
		this.ref = ref;
	}
	
	private T calc(Point<T> p) {
		return id46.calc(ref, p); 
	}
	
	public int compare(Point<T> p1, Point<T> p2) {
		return calc(p1).compareTo(calc(p2));
	}		
}

